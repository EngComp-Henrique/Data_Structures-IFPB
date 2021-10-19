from OOP_queue import Queue_OOP

from collections import deque

def main():
    # Using the python "queue"
    queue = deque()
    queue.append(10)
    queue.append(20)
    queue.append(30)

    print("Elements in the python queue")
    for i in queue:
        print(i)

    print()
    # Using oop queue
    my_queue = Queue_OOP()
    my_queue.push(10)
    my_queue.push(20)
    my_queue.push(30)
    
    print("Elements in my oop queue")
    my_queue.show_queue()

    print("First element: ", my_queue.peek())

if __name__ == '__main__':
    main()
