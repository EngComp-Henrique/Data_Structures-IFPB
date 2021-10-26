from typing import List

def insertion_sort(list_: List[int]) -> List[int]:
    """Order a list of numbers in ascending order using insertion sort"""
    my_list = list_[:]
    n = len(my_list)
    for i in range(1, n):
        key = my_list[i]
        j = i - 1
        while j >= 0 and my_list[j] > key:
            my_list[j + 1] = my_list[j]
            j -= 1
        my_list[j + 1] = key
    return my_list
