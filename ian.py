#!/usr/bin/python3

"""The 1st algo I thought of. Create array, populate array with values in the given array.
Iterate through the given array checking if elements of array exist in your created array.
If exists, remove the element in your created array.
At the end, you will have not existing element
"""

def notExist(array):
    checkArray = array
    i = 0

    for num in array:
        if num in array:
            checkArray.remove(num)

        i+=i

    print(checkArray)


def newsltn(array):
    """ Sort the array
    get the smallest number
    iterarte through the list, incrementing the smallest value checking if a consecutive number exists in the list
    if it doesn't append it to a new list

    """
    array.sort()
    print(array)
    
    i = array[0]
    print(i)
    newarray = []

    for num in array:
        if num == i:
            pass;
        else:
            newarray.append(i)
        i+=1
    print(newarray)
    
find_missing_numbers = [3,0,1,4,6,2]
newsltn(find_missing_numbers)
