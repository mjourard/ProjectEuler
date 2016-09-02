#!/usr/local/bin/python3.1

#for quick exit
import sys

cubed = 1
base = 1

#To figure out if a cube is a permutation, we will check to see if they have the same number of 0s, then 1s, then 2s...etc
#If all the same, then it's a permutation, add the cube to the list
#Once the list gets to 5, then the program stops, and prints out the list, as well as the first base to create a perm

#EDIT: I tried the approach above by having a very complicated 10-level nested dictionary structure, where each level was the number of times a digit was represented in the number
#I took the idea of sorting the numbers into the highest permutation from Kristian at http://www.mathblog.dk/project-euler-62-cube-five-permutations/ as I was getting frusterated
#His idea worked so kudos to him

def checkIfPerm(x, y):
    xDigs = {}
    while (x > 0):
        digit = x % 10
        x = x // 10
        
        if digit in xDigs:
            xDigs[digit] = xDigs[digit] + 1
        else:
            xDigs[digit] = 1

    yDigs = {}
    while (y > 0):
        digit = y % 10
        y = y // 10
        
        if digit in yDigs:
            yDigs[digit] = yDigs[digit] + 1
        else:
            yDigs[digit] = 1

    #check to make sure they have the same number of each digit
    if len(xDigs.keys()) != len(yDigs.keys()):
        return False

    for key, value in xDigs.items():
        if yDigs[key] != value:
            return False

    return True
    
    

cubesDict = {}

while (1):

    #get the number of occurances of each digit
    cubeCopy = cubed
    digs = [0,0,0,0,0,0,0,0,0,0]
    while (cubeCopy > 0):
        digit = cubeCopy % 10
        digs[digit] += 1
        cubeCopy = cubeCopy // 10


    #create the proper key
    digStr = ""
    for i in range(10):
        if digs[9-i] > 0:
            digStr = digStr + str(str(9-i) * digs[9-i])
    

    #insert into the mapped list
    if digStr in cubesDict:
        cubesList = cubesDict[digStr][1]
        cubesList.append(cubed)

        if len(cubesList) == 5:
            print(str(cubesDict[digStr]))
            for i in range(4):
                if not checkIfPerm(cubesList[i], cubesList[i+1]):
                    print("This value doens't work for {}".format(cubesList[i+1]))
            sys.exit()

            

    #the mapped string isn't in the dictionary, so insert a new list
    else:
        cubesList = [cubed]
        cubesDict[digStr] = (base, cubesList)

    
    #increment for the next go around   
    base += 1
    cubed = base**3
    
