//
//  Testing.cpp
//  VendingMachine
//
//  Created by Chandrasekar Sureshkumar on 1/23/17.
//  Copyright © 2017 Chandrasekar Sureshkumar. All rights reserved.
//

#include "Testing.hpp"
#include "VendingMachine.hpp"
#include <iostream>

void CodeChecks(void)
{
    VendingMachine VM4Sodas(0.95);
    
    SodaTypes soda = Pepsi;
    switch(soda)
    {
        case Pepsi  : std::cout << "Pepsi\n"; std::cout << "Count is " << SodaTypeCount << "\n";   break;
        case SunnyD : std::cout << "SunnyD\n";  break;
        case Coke: std::cout << "Coke\n"; break;
        case DrPepper : std::cout << "DrPepper\n";  break;
        default: std::cout << "Invalid Choice!!!\n"; break;
    }
    
    int* coinsCount = VM4Sodas.getCoinCount();
    for( int i=0; i < CoinTypeCount; i++)
    {
        switch(i)
        {
            case 0: std::cout << "Number of Nickels in Vending Machine: " << *(coinsCount+i) << "\n"; break;
            case 1 : std::cout << "Number of Dimes in Vending Machine: " << *(coinsCount+i) << "\n"; break;
            case 2 : std::cout << "Number of Quarters in Vending Machine: " << *(coinsCount+i) << "\n"; break;
        }
        
    }
    std::cout << "\n";
    
    int* sodasCount = VM4Sodas.getInventory();
    for( int i=0; i < SodaTypeCount; i++)
    {
        switch(i)
        {
            case 0: std::cout << "Number of Pepsi in Vending Machine: " << *(sodasCount+i) << "\n"; break;
            case 1 : std::cout << "Number of SunnyD in Vending Machine: " << *(sodasCount+i) << "\n"; break;
            case 2 : std::cout << "Number of Coke in Vending Machine: " << *(sodasCount+i) << "\n"; break;
            case 3 : std::cout << "Number of DrPepper in Vending Machine: " << *(sodasCount+i) << "\n"; break;
        }
        
    }
    
    return;
}
