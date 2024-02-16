class Vector:
    def __init__(self, si=0):
        self.capacity = 100
        if si > self.capacity:
            self.capacity = si
        self.size = 0
        self.arr = [0] * self.capacity

    def __del__(self):
        del self.arr  # Free the memory allocated for the array

    def push_back(self, value):
        if self.size == self.capacity:
            self.double_capacity()

        self.arr[self.size] = value
        self.size += 1

    def double_capacity(self):
        self.capacity *= 2
        new_arr = [0] * self.capacity
        for i in range(self.size):
            new_arr[i] = self.arr[i]
        self.arr, new_arr = new_arr, self.arr  # Swap arrays
        del new_arr  # Free the memory of the old array

    def right_rotate(self):
        if self.size > 0:
            temp = self.arr[self.size - 1]
            for i in range(self.size - 1, 0, -1):
                self.arr[i] = self.arr[i - 1]
            self.arr[0] = temp

    def left_rotate(self):
        if self.size > 0:
            temp = self.arr[0]
            for i in range(self.size - 1):
                self.arr[i] = self.arr[i + 1]
            self.arr[self.size - 1] = temp

    def right_rotate_steps(self, steps):
        while steps > 0:
            self.right_rotate()
            steps -= 1

    def pop(self, idx):
        if 0 <= idx < self.size:
            item = self.arr[idx]
            for i in range(idx, self.size - 1):
                self.arr[i] = self.arr[i + 1]
            self.size -= 1
            return item
        return -1

    def improved_search(self, value):
        for i in range(self.size - 1):
            if self.arr[i] == value:
                temp = self.arr[i]
                self.arr[i] = self.arr[i - 1]
                self.arr[i - 1] = temp
                return i
        return -1

    def print(self):
        for i in range(self.size):
            print(self.arr[i], end=" ")
        print()

