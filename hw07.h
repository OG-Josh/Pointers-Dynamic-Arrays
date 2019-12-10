/* ======================================================================================= */
/* ======================================================================================= */
// Class: CS-1C
// Creator: Joshua Yang
// Contact: joshuayang0324@gmail.com
// Professor: Kath
// Date: 2/28/19
/* ======================================================================================= */
// Rules/Algorithm: Write a program that uses a random number generator to generate
// a three digit integer that allows the user to perform the following operation.
// 1. Sum the digits
// 2. Triple the number
// 3. Reverse the digitis
// b. Use an enum, typedef, and string variable
// c. Store 10 random numbers in an array
// d. Sort the array
// e. Write the array to an external file
// f. Call a function to read the external file
// g. Print the array in a function
// Use the command script to capture your interaction compiling and running 
// the program, including all operations, as shown below:
/* ======================================================================================= */
// Work: 
// CS1C Spring 2019 TTH HW-1 50pts Due: Th 1/24/2019
// cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ script hw01.scr
// Script started, file is hw01.scr
// cs1c@cs1c-VirtualBox ~/cs1c/hw01 $ date
// ... 
// Cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ Is -1
// ... 
// Cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ make all
// ...
// Cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ Is -1
// ...
// Cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ ./hw01
// ...//print out parts a, d & g above
// cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ exit
// Script done, file is hw01.scr
// Cs1c@cs1c-VirtualBox ~/cs1c/hw/01 $ make tar
// ...
// Submit the tar package file hw01.tar by Thursday January 24, 2019.
/* ======================================================================================= */
/* ======================================================================================= */
// Code:

#ifndef HW07_H_
#define HW07_H_

#include <iostream>
#include <string>

namespace hw07
{
    struct Item
    {
            std::string name;
            int quantity;
            float cost;
    };
    const int MAX_SIZE = 50;
    class ManageInventory
    {
        public:
            ManageInventory() :
                    count { 0 }, countHistory { 0 }, p_pInventoryItems { new Item*[size] }, p_pHistoryTransaction { new std::string[size] }
            {
            }
            // Copy contructor
            ManageInventory(const ManageInventory& other);
            ManageInventory(int size) :
                    size { size }, count { 0 }, countHistory { 0 }, p_pInventoryItems { new Item*[size] }, p_pHistoryTransaction { new std::string[size] }
            {
            }
            ~ManageInventory();
            void addItem(std::string name, int quantity, float cost);
            void print();
            float calculateTotalBeforeTax();
            float calculateTotalAfterTax();

        private:
            int size { MAX_SIZE };
            int count;
            int countHistory;
            Item ** p_pInventoryItems;
            std::string *p_pHistoryTransaction;
    };

} // end namespace hw07

#endif /* HW07_H_ */
