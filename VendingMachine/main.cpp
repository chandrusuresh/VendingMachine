//
//  main.cpp
//  VendingMachine
//
//  Created by Chandrasekar Sureshkumar on 1/23/17.
//  Copyright © 2017 Chandrasekar Sureshkumar. All rights reserved.
//

#include <iostream>
#include "VendingMachine.hpp"
#include "Testing.hpp"

int main(int argc, const char * argv[]) {

    VendingMachine VM4Sodas(0.95);
    srand (time(NULL));
    
    
    //CodeChecks();
    bool validChoice = false;
    int sodaChoice;
    
    std::cout << "Welcome!!! What soda would you like?" << endl;
    
    while(!validChoice){
        std::cout << "1. Pepsi" << endl;
        std::cout << "2. Sunny D" << endl;
        std::cout << "3. Coke" << endl;
        std::cout << "4. DrPepper" << endl;
        std::cout << "Enter your choice here from one of the above: ";
        std::cin >> sodaChoice;
        std::cout << endl;
        
        int order[SodaTypeCount];
        
        sodaChoice--;
        if (sodaChoice < SodaTypeCount && sodaChoice >= 0)
        {
            switch(sodaChoice)
            {
                case 0: std::cout << "Pepsi "; break;
                case 1 : std::cout << "SunnyD "; break;
                case 2 : std::cout << "Coke "; break;
                case 3 : std::cout << "Dr.Pepper "; break;
            }
            order[sodaChoice] = 1;
            std::cout << "is a great choice!!!" <<endl;
            std::cout << "Please pay $" << VM4Sodas.getSodaCost() << " for your drink."  <<endl;
            std::cout << endl;
            validChoice = true;
        }
        else
        {
            std::cout << "Invalid Choice! Please try again with choices between 1 and " << SodaTypeCount << "." << endl;
            continue;
        }
        double amtPaid;
        bool amtPaid_divisibleby5 = false;
        while (!amtPaid_divisibleby5)
        {
            std::cout << "Enter amount paid: $";
            std::cin  >> amtPaid;
            std::cout << endl;
            
            if ((int)(amtPaid*100) % 5 == 0)
            {
                if (amtPaid >= VM4Sodas.getSodaCost())
                {
                    double change = VM4Sodas.dispenseChange(amtPaid,order);
                    if (change >= 0)
                    {
                        std::cout<< "Please collect your change of $" << change << endl;
                        amtPaid_divisibleby5 = true;
                    }
                    else
                    {
                        std::cout<< "Sorry. The vending machine is running low on change!" << endl;
                        std::cout<< "Please try again with the exact change!" << endl;
                        return 0;
                    }
                }
                else
                {
                    std::cout<< "Please pay a valid amount in multiples of 5 cents" << endl;
                    std::cout << endl;
                }
            }
            else
            {
                std::cout << (amtPaid*100/5)*0.05 - amtPaid << endl;
                std::cout<< "Please pay a valid amount in multiples of 5 cents" << endl;
                std::cout << endl;
            }
        }
    };
    
    

    return 0;
}

