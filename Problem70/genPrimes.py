#!/usr/local/bin/python3.1

def isPrime(n):
    if (n < 2):
        return False
    if (n % 2 == 0):
        return n==2
    elif (n % 3 == 0):
        return n == 3
    elif (n % 5 == 0):
        return n == 5
    elif (n % 7 == 0):
        return n == 7
    
    a = 11
    b = 13
    while (a < n and b < n):
        if (n % a == 0):
            return n == a
        if (n % b == 0):
            return n == b
        a += 6
        b += 6
    return True


if __name__ == "__main__":
    count = 0
    primeDict = {}
    #load the prime dictionary
    
    for i in range(100):
        if isPrime(i):
            primeDict[i] = 0
    print(primeDict)
                
