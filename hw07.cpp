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

#include <sstream>
#include <iomanip>
#include "hw07.h"

int main(int argc, char* argv[])
{
    /**
     *  If Mark purchases two pairs of Nike basketball shoes,
     * three Under Armour T-shirts, four Nike shorts, and one
     * pair of Brooks running shoes; print a receipt for the
     * purchase including the total cost before and after tax.
     * Assume the tax rate is 8.25%
     */
    hw07::ManageInventory *MarkInventory = new hw07::ManageInventory();
    std::cout << "Mark Inventory before Mark's purchase: " << std::endl;
    MarkInventory->print();

    MarkInventory->addItem("Nike basketball shoes", 2, 145.99);
    MarkInventory->addItem("Under Armour T-shirt", 3, 29.99);
    MarkInventory->addItem("Brooks running shoes", 1, 111.44);
    MarkInventory->addItem("Nike shorts", 4, 45.77);

    std::cout << std::endl << "Mark Inventory after Mark's purchase: " << std::endl;
    MarkInventory->print();

    hw07::ManageInventory *copyInventory = new hw07::ManageInventory(*MarkInventory);
    std::cout << std::endl << "The copy Inventory: " << std::endl;
    copyInventory->print();
}

void hw07::ManageInventory::addItem(std::string name, int quatity, float cost)
{
    if (count < size)
    {
        Item *x = new Item;
        x->name = name;
        x->quantity = quatity;
        x->cost = cost;
        p_pInventoryItems[count++] = x;

        std::stringstream transaction;
        transaction << quatity << " of " << name << " added to inventory with cost " << cost << " per item.";
        p_pHistoryTransaction[countHistory++] = transaction.str();
    }
    else
        std::cout << "Inventory items are full" << std::endl;
}

hw07::ManageInventory::~ManageInventory()
{
    for (int i = 0; i < count; i++)
    {
        delete p_pInventoryItems[i];
    }
    delete[] p_pInventoryItems;
    delete[] p_pHistoryTransaction;
}

void hw07::ManageInventory::print()
{
    std::cout << "|" << std::left << std::setw(25) << "Name" << "|" << std::setw(10) << "Cost" << "|" << std::setw(10) << "Quantity" << "|" << std::endl;
    std::cout << "-------------------------------------------------" << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << "|" << std::left << std::setw(25) << p_pInventoryItems[i]->name << "|" << std::setw(10) << p_pInventoryItems[i]->cost << "|"
                << std::setw(10) << p_pInventoryItems[i]->quantity << "|" << std::endl;
    }
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "|" << std::left << std::setw(25) << "Cost before TAX:" << "|" << calculateTotalBeforeTax() << std::endl;
    std::cout << "|" << std::left << std::setw(25) << "Cost after TAX:" << "|" << calculateTotalAfterTax() << std::endl;
    std::cout << "++++++++++++++History+++++++++++++++++++++++++++++" << std::endl;
    for (int i = 0; i < countHistory; i++)
    {
        std::cout << i + 1 << " : " << p_pHistoryTransaction[i] << std::endl;
    }
}

hw07::ManageInventory::ManageInventory(const ManageInventory& other)
{
    size = other.size;
    count = other.count;
    countHistory = other.countHistory;
    p_pInventoryItems = new Item*[size];
    p_pHistoryTransaction = new std::string[size];
    // Copy inventory
    for (int i = 0; i < count; i++)
    {
        p_pInventoryItems[i] = new Item;
        p_pInventoryItems[i]->name = other.p_pInventoryItems[i]->name;
        p_pInventoryItems[i]->cost = other.p_pInventoryItems[i]->cost;
        p_pInventoryItems[i]->quantity = other.p_pInventoryItems[i]->quantity;
    }
    // Copy history
    for (int i = 0; i < countHistory; i++)
    {
        p_pHistoryTransaction[i] = other.p_pHistoryTransaction[i];
    }
}

float hw07::ManageInventory::calculateTotalBeforeTax()
{
    float total = 0.0;
    for (int i = 0; i < count; i++)
    {
        total += (p_pInventoryItems[i]->cost * p_pInventoryItems[i]->quantity);
    }
    return total;
}

float hw07::ManageInventory::calculateTotalAfterTax()
{
    float total = 0.0;
    for (int i = 0; i < count; i++)
    {
        total += (p_pInventoryItems[i]->cost * p_pInventoryItems[i]->quantity);
    }
    total += total * 8.25 / 100;
    return total;
}
