from typing import List

def bubble_sort(list_: List[int]) -> List[int]:
    """Order a list of numbers in ascending order using bubble sort"""
    my_list = list_[:]
    n = len(my_list)
    for j in range(n - 1):
        for i in range(n - 1):
            if my_list[i] > my_list[i + 1]:
                my_list[i], my_list[i + 1] = my_list[i + 1], my_list[i]
    return my_list
