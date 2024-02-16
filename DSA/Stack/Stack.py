class Stack:
    def __init__(self, sz):
        self.arr = [0] * sz
        self.top = -1
        self.size = sz

    def is_full(self):
        return self.size == self.top + 1

    def is_empty(self):
        return self.top == -1

    def push(self, val):
        if self.is_full():
            self.resize()
        self.top += 1
        self.arr[self.top] = val

    def get_top(self):
        return self.top

    def resize(self):
        new_arr = [0] * (self.size * 2)
        for i in range(self.size):
            new_arr[i] = self.arr[i]
        self.size = self.size * 2
        self.arr = new_arr

    def pop(self):
        if self.is_empty():
            print("the stack is empty...!")
            return
        self.top -= 1

    def pick(self):
        if self.is_empty():
            print("the stack is empty...!")
            return 0
        return self.arr[self.top]

    def print_stack(self):
        if self.is_empty():
            print("there are no elements to print..!")
            return
        for i in range(self.top, -1, -1):
            print(self.arr[i], end=" ")
        print()

    def delete_stack(self):
        self.top = -1

    def reverse(self):
        j = 0
        i = self.top
        while i >= j:
            temp = self.arr[j]
            self.arr[j] = self.arr[i]
            self.arr[i] = temp
            j += 1
            i -= 1

    def valid_parentheses(self, s):
        sz = len(s)
        t = 0
        for i in range(1, sz):
            if s[i] == '(' or s[i] == '{' or s[i] == '[':
                self.push(s[i])
                t += 1
            elif s[i] == ')' and s[t] == '(':
                self.pop()
            elif s[i] == '{' and s[t] == '}':
                self.pop()
            elif s[i] == ']' and s[t] == '[':
                self.pop()
        return self.is_empty()

    def remove_all_adjacent_duplicates_in_string(self, s):
        sz = len(s)
        for i in range(sz):
            if self.is_empty():
                self.push(s[i])
                continue
            if s[i] == self.arr[self.top]:
                self.pop()
            else:
                self.push(s[i])
        new_string = ''.join(self.arr[:self.top + 1])
        return new_string

    def asteroid_collision(self, array):
        for i in array:
            if i < 0:
                if self.is_empty():
                    self.push(i)
                else:
                    tregar = True
                    while self.top >= 0:
                        if self.arr[self.top] > 0:
                            if abs(i) > self.arr[self.top]:
                                self.pop()
                            elif abs(i) == self.arr[self.top]:
                                self.pop()
                                tregar = False
                                break
                            elif abs(i) < self.arr[self.top]:
                                tregar = False
                                break
                        else:
                            self.push(i)
                            tregar = False
                            break
                    if tregar:
                        self.push(i)
            elif i > 0:
                self.push(i)

    def print_front(self):
        for i in range(self.top + 1):
            print(self.arr[i], end=" ")
        print()

    def insert_at_bottom(self, val, pos):
        if pos == -1:
            self.arr[0] = val
            self.top += 1
            return
        self.arr[pos + 1] = self.arr[pos]
        self.insert_at_bottom(val, pos - 1)

    def score_of_parentheses(self, s):
        counter = 0
        counter2 = 0
        sz = len(s)
        for i in range(sz):
            if s[i] == '(' and s[i + 1] == ')':
                counter += 1
                i += 1
            if s[i] == '(' and s[i + 1] == '(':
                while s[i] != ')' and s[i + 1] != ')':
                    counter2 += 1
                    i += 2
                break
        res = (counter2 * 2) + counter
        return res
