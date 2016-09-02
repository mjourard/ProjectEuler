#!/usr/local/bin/python3.1

def isPermutations(x, y):
    digList = [0,0,0,0,0,0,0,0,0,0]

    xCopy = x
    yCopy = y

    while (xCopy > 0):
        digList[xCopy % 10] += 1
        xCopy //= 10

    while (yCopy > 0):
        digList[yCopy % 10] -= 1
        yCopy //= 10
    
    for i in range(10):
        if digList[i] != 0:
            return False

    return True    
    


if __name__ == "__main__":
    ########################################
    #testing if isPermutation works well   #
    #These print statements are for testing#
    ########################################
    
    #print(isPermutations(12345, 54321))
    #print(isPermutations(10101, 11100))
    #print(isPermutations(5, 6))
    #x = 1234
    #print(isPermutations(1234, 1234))
    #print('After calling isPermutations, x = ' + str(x))

    #isPermutation works fine

    minimum = 2
    winningN = 2


    
    ##############################################################
    #get a list of primes below one million between 1500 and 5500#  
    ##############################################################

    prmFile = open('primesBelowMillion.txt', 'r')
    #print(prmFile)

    primeList = []
    n = prmFile.readline()
    while ( n ):
        number = int(n, base=10)
        if number > 1500:
            primeList.append(number)

        if number > 5500:
            break
        n = prmFile.readline()

    totalPrimes = len(primeList)
    


    ########################################
    #use the list to find solve the problem#
    ########################################
    for i in primeList:
        for j in primeList:
            if i == j:
                continue            
            n = i * j
            if n > 10000000:
                break
            totient = (i - 1) * (j - 1)
        
            #now we have the totient, check if n and totient are permutations
            #checking n/totient will reveal if they can permutations. 
            #Anything greater than 10 means there aren't the same number of digits!
            if (n/totient < 10):
                
                if isPermutations(n, totient):
                    ratio = n/totient
                    if ratio < minimum:
                        minimum = ratio
                        winningN = n
                        #print("totient for " + str(n) + " = " + str(totient))

    print("The smallest ratio of n/phi(n) is " + str(minimum) + " that is caused by " + str(winningN))
                
                                

