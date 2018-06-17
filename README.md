# Code for "Planning A Company Party" problem

# Problem:
"Professor Stewart is consulting for the president of a corporation that is planning a company party. The company has a hierarchical structure. The personnel office has ranked each employee with a conviviality rating, which is a real number. In order to make the party fun for all attendees, the president does not want both an employee and his or her immediate supervisor to attend."

# Running the program
You can run it on DEV CPP IDE (recommended), use any IDE that compiles C++ files, or use this link to compile it online:
https://onlinegdb.com/SJ_ZOxVb7

# Inputs
The inputs to this program are nodes of the tree (employees) and their individual conviviality rating

# Output 
The output of this program is the max possible aggregated conviviality rating of invited nodes/employees, keeping in consideration the  employee - direct supervisor restriction

# Editing the program to see results
You can add nodes to the 2 predefined trees or make a new tree and pass the root of that tree to the Find_Max_Conv() function. Note that the aggregate ratings are calculated as follows:
1) Sum of all siblings at each level of the tree
2) Sum of Grandparent and all its children
3) Sum of Uncle/Aunt and its Nephews/Niece

# Group Members
1)15B-036-SE - Syed Salman Manzoor
2)15B-008-SE - Muhammad Rabie Saeed
3)15B-059-SE - Phool Raja
