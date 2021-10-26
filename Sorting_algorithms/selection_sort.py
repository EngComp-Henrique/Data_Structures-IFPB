from typing import List

def selection_sort(list_: List[int]) -> List[int]:
    """Order a list of numbers in ascending order using selection sort"""
    my_list = list_[:]
    n = len(my_list)
    for idx in range(n):
        min_idx = idx
        for i in range(idx, n):
            if my_list[i] < my_list[min_idx]:
                min_idx = i
        if my_list[idx] > my_list[min_idx]:
            my_list[idx], my_list[min_idx] = my_list[min_idx], my_list[idx]
    return my_list
