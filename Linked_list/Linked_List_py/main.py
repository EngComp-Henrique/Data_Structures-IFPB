from LinkedList import Node, LinkedList

if __name__ == '__main__':

    import random

    LinkedList = LinkedList()
    array = []
    k = random.randint(8,24)
    for i in range(k):
        p = random.randint(0, 10)
        array.append(p)
        LinkedList.append(p)
    print(array)

    LinkedList.display_list()