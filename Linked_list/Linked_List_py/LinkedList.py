class Node:

    def __init__(self, data):
        """
        Função responsável por criar um elemento nó
        """
        self.data = data # elemento criado
        self.next = None # posição do próximo elemento

class LinkedList:

    def __init__(self):
        """
        Função responsável por iniciar nossa lista
        """
        self.head = None # criando lista vazia
        self.tail = None
        self.size = 0

    def append(self, data):
        """Função responsável por adicionar um elemento no final da lista"""
        # caso a lista esteja vazia
        if self.head is None:
            # inserindo primeiro elemento
            self.head = Node(data) 
            self.tail = Node(data)
        elif self.size == 1:
            self.tail = Node(data)
            self.head.next = self.tail
        else:
            pointer = self.tail
            self.tail = Node(data)
            pointer.next = self.tail
        
        # tamanho da lista é modificado
        self.size += 1
        return 1

    def insert(self, index, data):
        node = Node(data)
        if index == 0:
            node.next = self.head
            self.head = node
            return 1
        else:
            pointer = self.head
            for i in range(index - 1):
                if pointer:
                    pointer = pointer.next
                else:
                    return 0
            node.next = pointer.next
            pointer.next = node
        self.size += 1
            

    def get_data(self, index):
        """
        Função responsável por retornar o dado a partir de um índice
        """
        pointer = self.head

        for i in range(index):
            if pointer:
                pointer = pointer.next
            else:
                return 0
        if pointer:
            return pointer.data
        return 1

    def get_index(self, data):
        """Função responsável por retornar o índice de um elemento"""
        pointer = self.head
        index = 0
        while pointer:
            if pointer.data == data:
                return index
            index += 1
            pointer = pointer.next
        return 0

    def set_data(self, index, new_elem):
        """Função responsável por trocar um elemento em uma determinada posição por outro elemento"""
        pointer = self.head

        for i in range(index):
            if pointer:
                pointer = pointer.next
            else:
                return 0
        if pointer:
            pointer.data = new_elem
            return 1
        return 0

    def remove(self, data):
        """Função responsável por remover um elemento da lista"""
        if self.head is None:
            return 0
        elif self.head.data == data:
            self.head = self.head.next
        else:
            previous = self.head
            pointer = self.head.next
            while pointer:
                if pointer.data == data:
                    previous.next = pointer.next
                    pointer.next = None
                    return 1
                pointer = pointer.next
                previous = previous.next
        self.size -= 1
        return 0

    def display_list(self):
        """Função responsável por exibir a lista"""
        pointer = self.head

        if pointer is None:
            return 0
        print("[", end="")
        while pointer:
            if pointer.next:
                print(pointer.data, end=", ")
            else:
                print(str(pointer.data) + "]")
            pointer = pointer.next
