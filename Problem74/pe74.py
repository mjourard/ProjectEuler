#!/usr/local/bin/python3.1

global digitFactorialDict

def factorial(n):
    if n < 0:
        n *= -1
    ret = 1
    while n > 0:
        ret *= n
        n -= 1
    return ret

def digFactorialSum(n):
    global digitFactorialDict

    factSum = 0
    while (n > 0):
        digit = n % 10
        factSum += digitFactorialDict[digit]
        n //= 10

    return factSum


if __name__ == "__main__":
    global digitFactorialDict
    digitFactorialDict = {}
    for i in range(10):
        val = factorial(i)
        digitFactorialDict[i] = val

    exactSixty = 0
    for i in range(1000001):
        chainLength = 0
        number = i
        chain = {}
        while chainLength < 61:
            if number in chain:
                break
            else:
                newNum = digFactorialSum(number)
                chain[number] = newNum
                chainLength += 1
                number = newNum

        if chainLength == 60:
            print(str(i) + " has 60 tems.")
            exactSixty += 1

    print("There are " + str(exactSixty) + " numbers with exactly 60 non repeating terms in their chain")
                
        
        
    
