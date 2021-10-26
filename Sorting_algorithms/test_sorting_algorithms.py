import unittest
import random
from selection_sort import selection_sort
from bubble_sort import bubble_sort
from insertion_sort import insertion_sort

class TestSortingAlgo(unittest.TestCase):
    """Test of sorting algorithms"""

    def setUp(self) -> None:
        """Initial lists"""
        random.seed(42)
        self.random_numbers = random.sample(range(1, 10000), 42)
        self.already_sorted = [1, 2, 3, 4, 5, 6, 7, 8, 9 , 20, 22, 23, 28,
                                32, 34, 39, 40, 42, 76, 87, 99, 112]
        self.inverserd = [int(i) for i in range(50, 0, -1)]
        self.repeated = [7, 7, 7, 7, 7, 1, 1, 9, 9, 0, 4, 4, 4, 5, 4, 5, 7, 1]

        self.random_numbers_sorted = sorted(self.random_numbers)
        self.inverserd_sorted = sorted(self.inverserd)
        self.repeated_sorted = sorted(self.repeated)

    def test_selection_sort(self) -> None:
        self.assertEqual(selection_sort(self.random_numbers), self.random_numbers_sorted)
        self.assertEqual(selection_sort(self.already_sorted), self.already_sorted)
        self.assertEqual(selection_sort(self.inverserd), self.inverserd_sorted)
        self.assertEqual(selection_sort(self.repeated), self.repeated_sorted)

    def test_bubble_sort(self) -> None:
        self.assertEqual(bubble_sort(self.random_numbers), self.random_numbers_sorted)
        self.assertEqual(bubble_sort(self.already_sorted), self.already_sorted)
        self.assertEqual(bubble_sort(self.inverserd), self.inverserd_sorted)
        self.assertEqual(bubble_sort(self.repeated), self.repeated_sorted)

    def test_insertion_sort(self) -> None:
        self.assertEqual(insertion_sort(self.random_numbers), self.random_numbers_sorted)
        self.assertEqual(insertion_sort(self.already_sorted), self.already_sorted)
        self.assertEqual(insertion_sort(self.inverserd), self.inverserd_sorted)
        self.assertEqual(insertion_sort(self.repeated), self.repeated_sorted)
