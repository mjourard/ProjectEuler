#!/usr/local/bin/python3.1

def recursePrint(index):
    if index < 0:
        return

    indent = (9-index)*4
    indentStr = " " * indent

    indexStr = ""
    for i in range(index + 1):
        indexStr += "[digs[{}]]".format(i)


    print(indentStr + "if digs[{}] in zerosDict".format(9-index) + indexStr + ":")

    recursePrint(index - 1)

    print(indentStr + "else:\n")
    indentStr += indentStr + "    "

    
    


    
    if digs[0] in zerosDict:
        if digs[1] in zerosDict[digs[0]]:
            if digs[2] in zerosDict[digs[0]][digs[1]]:
                if digs[3] in zerosDict[digs[0]][digs[1]][digs[2]]:
                    if digs[4] in zerosDict[digs[0]][digs[1]][digs[2]][digs[3]]:
                        if digs[5] in zerosDict[digs[0]][digs[1]][digs[2]][digs[3]][digs[4]]:
                            if digs[6] in zerosDict[digs[0]][digs[1]][digs[2]][digs[3]][digs[4]][digs[5]]:
                                if digs[7] in zerosDict[digs[0]][digs[1]][digs[2]][digs[3]][digs[4]][digs[5]][digs[6]]:
                                    if digs[8] in zerosDict[digs[0]][digs[1]][digs[2]][digs[3]][digs[4]][digs[5]][digs[6]][digs[7]]:
                                        if digs[9] in zerosDict[digs[0]][digs[1]][digs[2]][digs[3]][digs[4]][digs[5]][digs[6]][digs[7]][digs[8]]:
                                            cubeTuple = zerosDict[digs[0]][digs[1]][digs[2]][digs[3]][digs[4]][digs[5]][digs[6]][digs[7]][digs[8]][digs[9]]
                                            permList = cubeTuple[1]
                                            permList.append(cubed)
                                            if len(permList) == 5:
                                                for i in range(4):
                                                    if not checkIfPerm(permList[i], permList[i+1]):
                                                        print("This value doesn't work for {}".format(permList[i+1]))
                                                                
                                                print("The winning value is: " + str(cubeTuple))
                                                sys.exit()
                                        else:
                                            zerosDict[digs[0]][digs[1]][digs[2]][digs[3]][digs[4]][digs[5]][digs[6]][digs[7]][digs[8]] = {digs[9]: (base, [cubed])}
                                    else:
                                        zerosDict[digs[0]][digs[1]][digs[2]][digs[3]][digs[4]][digs[5]][digs[6]][digs[7]] = {digs[8]: {digs[9]: (base, [cubed])}}
                                else:
                                    zerosDict[digs[0]][digs[1]][digs[2]][digs[3]][digs[4]][digs[5]][digs[6]] = {digs[7]: {digs[8]: {digs[9]: (base, [cubed])}}}
                            else:
                                zerosDict[digs[0]][digs[1]][digs[2]][digs[3]][digs[4]][digs[5]] = {digs[6]: {digs[7]: {digs[8]: {digs[9]: (base, [cubed])}}}}
                        else:
                            zerosDict[digs[0]][digs[1]][digs[2]][digs[3]][digs[4]] = {digs[5]: {digs[6]: {digs[7]: {digs[8]: {digs[9]: (base, [cubed])}}}}}
                    else:
                        zerosDict[digs[0]][digs[1]][digs[2]][digs[3]] = {digs[4]: {digs[5]: {digs[6]: {digs[7]: {digs[8]: {digs[9]: (base, [cubed])}}}}}}
                else:
                    zerosDict[digs[0]][digs[1]][digs[2]] = {digs[3]: {digs[4]: {digs[5]: {digs[6]: {digs[7]: {digs[8]: {digs[9]: (base, [cubed])}}}}}}}
            else:
                zerosDict[digs[0]][digs[1]] = {digs[2]: {digs[3]: {digs[4]: {digs[5]: {digs[6]: {digs[7]: {digs[8]: {digs[9]: (base, [cubed])}}}}}}}}
        else:
            zerosDict[digs[0]] = {digs[1]: {digs[2]: {digs[3]: {digs[4]: {digs[5]: {digs[6]: {digs[7]: {digs[8]: {digs[9]: (base, [cubed])}}}}}}}}}

    else:
        zerosDict[digs[0]] = {digs[1]: {digs[2]: {digs[3]: {digs[4]: {digs[5]: {digs[6]: {digs[7]: {digs[8]: {digs[9]: (base, [cubed])} } } } } } } } } 
