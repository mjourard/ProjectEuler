#!/usr/local/bin/python3.1

import math

if __name__ == "__main__":
    #generate the value we are looking for less than
    target = 3/7
    tarTup = (target, 3, 7)
    sequence = [tarTup]
    listLen = 1

    #So, sequence will hold the sequence in a list. We will insert
    #elements in sorted order using insertion sort, and it will be sorted based
    #on the first element in the tuple

    for i in range(2, 1000001):
        numer = math.floor(i* 0.4286)
        ration = numer/i
        while (ration > target):
            numer -= 1
            ration = numer/i

        for index in range(listLen):
            if ration < sequence[index][0]:
                newElement = (ration, numer, i)
                sequence.insert(index, newElement)
                listLen += 1
                break

    length = len(sequence)
    print("The element directly to the left of 3/7 in the list is " + sequence[length-2])
    f = open('fareyList.txt', 'w')
    f.write(str(sequence))
    f.close
    
            
                                
