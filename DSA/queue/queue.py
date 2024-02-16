class Queue:
    def __init__(self, val):
        self.arr = [0] * val
        self.rear = self.front = 0
        self.added_elemint = 0
        self.size = val

    def next(self, pos):
        pos += 1
        if pos == self.size:
            pos = 0
        return pos

    def is_empty(self):
        return self.added_elemint == 0

    def is_full(self):
        return self.added_elemint == self.size

    def enqueue(self, val):
        if self.is_full():
            print("Queue is full")
            return
        self.arr[self.rear] = val
        self.rear += 1
        self.added_elemint += 1

    def dequeue(self):
        if self.is_empty():
            print("The queue is empty")
            return
        val = self.arr[self.front]
        self.front = self.next(self.front)
        self.added_elemint -= 1
        return val


def main():
    # Example usage
    q = Queue(5)
    q.enqueue(1)
    q.enqueue(2)
    q.enqueue(3)

    print(q.dequeue())  # Output: 1
    print(q.dequeue())  # Output: 2

    q.enqueue(4)
    q.enqueue(5)

    print(q.dequeue())  # Output: 3
    print(q.dequeue())  # Output: 4

    q.enqueue(6)
    print(q.dequeue())  # Output: 5
    print(q.dequeue())  # Output: 6

    # Attempting to dequeue from an empty queue
    print(q.dequeue())  # Output: The queue is empty


if __name__ == "__main__":
    main()

