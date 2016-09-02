#!/usr/local/bin/python3.1

def countSummations(n):
    f = open('listFile.txt', 'w')
    summation = [n-1, 1]
    length = 2
    summationCount = 1
    while (summation[0] > 1):
        index = length - 1
        while(index > 0 and summation[index] == 1):
            index -= 1
        summation[index] -= 1
        if summation[index] == 1:
            summation.append(1)
            length += 1
        else:
            summation[index+1] += 1
        print(summation, file=f)
        
        summationCount += 1
    return summationCount

if __name__ == "__main__":
    endCount = countSummations(100)
    print("There are " + str(endCount) + " ways 100 can be written as a sum of at least 2 positive integers")
