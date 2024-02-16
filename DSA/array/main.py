from array import Vector

def main():
    vector1 = Vector(5)

    # Test the push_back function
    vector1.push_back(1)
    vector1.push_back(2)
    vector1.push_back(3)
    vector1.push_back(4)
    vector1.push_back(5)
    vector1.print()

    # Test the right and left functions
    vector1.right_rotate()
    vector1.print()
    vector1.left_rotate()
    vector1.print()
    vector1.right_rotate_steps(3)
    vector1.print()

    # Test the pop function
    print(vector1.pop(2))
    print(vector1.pop(3))
    vector1.print()

if __name__ == "__main__":
    main()

