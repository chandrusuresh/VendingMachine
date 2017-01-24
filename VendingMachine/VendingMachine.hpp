//
//  VendingMachine.hpp
//  VendingMachine
//
//  Created by Chandrasekar Sureshkumar on 1/23/17.
//  Copyright © 2017 Chandrasekar Sureshkumar. All rights reserved.
//

#ifndef VendingMachine_hpp
#define VendingMachine_hpp

#include <stdio.h>
#include <iostream>
#include "stdlib.h"
#include "time.h"
#include "math.h"

using namespace std;

enum SodaTypes { Pepsi=0, SunnyD, Coke, DrPepper, SodaTypeCount };
enum CoinType { Nickel = 0, Dime, Quarter, CoinTypeCount };

class VendingMachine {
protected:
    int* Coins = new int[CoinTypeCount];
    int* Sodas = new int[SodaTypeCount];
    string SodaNames[SodaTypeCount] = {"Pepsi","SunnyD","Coke","DrPepper"};

private:
    double sodaCost = 0.85;
    void resetChangeinVM(void)
    {
        for( int i=0; i < CoinTypeCount; i++)
        {
            Coins[i] = rand()%100+1;
        }
    }
    
    void resetSodaInventoryinVM(void)
    {
        for( int i=0; i < SodaTypeCount; i++)
        {
            Sodas[i] = rand()%25;
        }
    }
    
    void setChangeinVM(int x[CoinTypeCount])
    {
        std::cout << "Coins: ";
        for( int i=0; i < CoinTypeCount; i++)
        {
            std::cout << "(" << Coins[i] << ",";
            Coins[i] -= x[i];
            std::cout << Coins[i] << "), ";
        }
        std::cout << endl;
    }
    
    void setSodaInventoryinVM(int x[SodaTypeCount])
    {
       std::cout << "Inventory: ";
        for( int i=0; i < SodaTypeCount; i++)
        {
            std::cout << "(" << Sodas[i] << ",";
            Sodas[i] -= x[i];
            std::cout << Sodas[i] << "), ";
        }
        std::cout << endl;
    }
    
public:
    VendingMachine(double sodaPrice) {
        sodaCost = sodaPrice;
        // Generate change in machine
        resetChangeinVM();
        // Generate inventory in machine
        resetSodaInventoryinVM();
        cout << "Vending machine class is constructed" << endl;
    }
    
    ~VendingMachine(void) {
        cout << "Vending machine class is destructed" << endl;
    }
    
    int* getCoinCount(void)
    {
        return Coins;
    }
    
    int* getInventory(void)
    {
        return Sodas;
    }
    
    double getSodaCost(void)
    {
        return sodaCost;
    }
    
    double dispenseChange(double amtPaid, int order[SodaTypeCount])
    {
        if (amtPaid == sodaCost)
        {
            return 0.0;
        }
        int* coinsCount = getCoinCount();
        
        double change = 0.0;
        double rem_change = 0.0;
        change = amtPaid - sodaCost;
        
        int quarters = ceil(change*100)/25;
        
        if (quarters >= *coinsCount)
        {
            quarters = *coinsCount;
        }
        rem_change = change - (double)quarters*0.25;
        
        int dimes = ceil(rem_change*100)/10;
        if (dimes >= *(coinsCount+1))
        {
            dimes = *coinsCount;
        }
        rem_change = rem_change - (double)dimes*0.10;

        
        int nickels = ceil(rem_change*100)/5;
        if (nickels >= *(coinsCount+2))
        {
            nickels = *coinsCount;
        }
        rem_change = rem_change - (double)nickels*0.05;

        
        cout << "change*100: " << (change*100) << endl;
        cout << "Quarters: " << quarters << endl;
        cout << "Dimes: " << dimes << endl;
        cout << "Nickels: " << nickels << endl;
        
        cout << "rem_change: " << rem_change << endl;
        
        if (rem_change >= 0.05)
        {
            return -1; // Insufficient $$$ in vending machine
        }
        
        int x[CoinTypeCount] = {quarters, dimes, nickels};
        setChangeinVM(x);
        setSodaInventoryinVM(order);
        
        
        return change;
        
    }
    
};

#endif /* VendingMachine_hpp */
