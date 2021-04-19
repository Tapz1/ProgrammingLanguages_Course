"""
Python code for main.cpp
pulls data from file: grocery_items.txt

developer: Chris Tapia
last updated: 04/18/2021

"""

import re
import string
from collections import Counter


def ViewItems():
    """ displays all items from a file and how many times it was purchased """
    
    # list for the grocery items
    grocery_list = []
    item_count = Counter(grocery_list)
    
    with open("grocery_items.txt", 'r') as fileIn:
        lines = fileIn.read().splitlines()
        grocery_list.extend(lines)
   
    print("Item\t# Sold")
    for item in Counter(grocery_list):
        count = (Counter(grocery_list)[item])
        print("%s: %d" % (item, count))


def SpecificItemCount(item_name):
    """ return a specific item and how many times it was purchased """
   
    # list for the grocery items
    grocery_list = []
        
    with open("grocery_items.txt", 'r') as fileIn:
        lines = fileIn.read().splitlines()
        grocery_list.extend(lines)
    
    for item in Counter(grocery_list):
        # print(item)
        if(item_name.capitalize() in item):
            print("\nItem: ")
            print(item_name.capitalize())
            print("\nAmount Sold: ")
            return Counter(grocery_list)[item]
    else:
        print("This item didn't sell")
        return 0


def GenerateFileAndGraph():
     # list for the grocery items
    grocery_list = []
        
    with open("grocery_items.txt", 'r') as fileIn:
        lines = fileIn.read().splitlines()
        grocery_list.extend(lines)

    with open("frequency.dat", 'w') as fileOut:
        for item in Counter(grocery_list):
            count = (Counter(grocery_list)[item])
            fileOut.write("%s %d \n" % (item, count))
