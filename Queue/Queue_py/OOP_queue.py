class Node:
    def __init__(self, data: int) -> None:
        self.data = data
        self.next = None

    def __repr__(self) -> str:
        return f"{self.data}"

    def __bool__(self) -> bool:
        return bool(self.data != None)

class Queue_OOP:
    def __init__(self) -> None:
        self.first = Node(None)
        self.last = Node(None)
        self._count = 0

    def push(self, value):
        new_node = Node(value)
        if not self.first:
            self.first = new_node
        if not self.last:
            self.last = new_node
        else:
            self.last.next = new_node
            self.last = new_node
        self._count += 1

    def pop(self) -> int:
        if not self.first:
            return 0
        first = self.first

        if self.first.next:
            self.first = self.first.next
        else:
            self.first = None

        self._count -= 1
        return first.data

    def peek(self) -> int:
        return self.first.data

    def len(self) -> int:
        return self._count

    def empty(self) -> bool:
        if self.first:
            return True
        return False

    def show_queue(self):
        ptr = self.first
        r = ""
        while ptr:
            r += str(ptr.data) + " "
            ptr = ptr.next
        r += "\n"
        print(r)

