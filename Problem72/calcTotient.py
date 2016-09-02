#!/usr/local/bin/python3.1


#taken from stack overflow, the sieve of sundaram
#works by starting with a sequence starting at 4, and then increasing by 3 indefinitely
#then increases the initial value by 3, and increases the stepping by 2
#continues this indefinitely
#looks like
#4   7 10 13 16 19
#7  12 17 22 27 32
#10 17 24 31 38 45

#etc. etc.

#for any number in the array, if you double it and add 1, it will not be prime
#therefore you sieve out the composite numbers and are left with primes
def sundaram3(max_n):
    numbers = list(range(3, max_n+1, 2))
    half = (max_n)//2
    initial = 4

    for step in range(3, max_n+1, 2):
        for i in range(initial, half, step):
            numbers[i-1] = 0
        initial += 2*(step+1)

        if initial > half:
            return [2] + list(filter(None, numbers))

def calcEulerTotient(n):
    if n == 1 or n == 2 or n == 0:
        return 1
    elif n  < 0:
        n *= -1
    primeList = sundaram3(n)
    length = len(primeList)
    totient = n
    contains = False
    while (n > 1):
        #divide out the prime factor from n
        while(length > 0 and n % primeList[0] == 0):
            n /= primeList[0]
            contains = True

        #be rid of the prime from the list and decrement
        if length > 0:
            pFact = primeList.pop(0)
            length -= 1

        #update the totient
        if contains:
            totient *= (1 - 1/pFact)
        contains = False
        #print(str(n) + " length = " + str(length))

    #check if n was prime, if so, return n-1
    if n == totient:
        return n-1
    else:
        return totient


global fareyCardDict
fareyCardDict = {}
    
def fareyCardinality(n):
    Fn = 1/2  * (n+3) * n
    
    

if __name__ == "__main__":
    for i in range(10):
        print("phi(" + str(i) + ") = " + str(calcEulerTotient(i)))
    Fn = 0
    target = 8
    tot = calcEulerTotient(target)
    fareyCard = tot * (tot+1)
    fareyCard /= 2
    fareyCard -= 1
    print(fareyCard)

    print("Attempting mobius function solution")
    fareyCardDict = {}
