from stack import Stack

def main():
    s1 = Stack(10)

    # Example operations
    s1.push(10)
    s1.push(20)
    s1.push(30)
    s1.push(40)
    s1.push(50)
    s1.push(60)
    s1.push(70)
    s1.print_stack()

    s1.reverse()
    s1.print_stack()

    # Additional operations
    s = "()()()(()()){}{}(((()))}([])()[]{}{[]}"
    print(s1.valid_parentheses(s))

    s = "aabbaaccddsssabdehh"
    res = s1.remove_all_adjacent_duplicates_in_string(s)
    print(res)

    arr = [-1, 3, 2, -5, 4]
    s1.asteroid_collision(arr, 5)
    s1.print_front()

    s1.push(1)
    s1.push(2)
    s1.push(3)
    s1.push(4)
    s1.push(5)
    top = s1.get_top()
    s1.insert_at_bottom(6, top)
    s1.print_front()

    s = "()((())())"
    print(s1.score_of_parentheses(s))

if __name__ == "__main__":
    main()

