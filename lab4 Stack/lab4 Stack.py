top = -1
stack = [None, None, None, None, None, None, None, None]

def pushStack():
    global top
    newItem = int(input("Enter item for push: "))
    top += 1
    stack[top] = newItem
def popStack():
    global top
    print(stack[top], "is pop out from stack.")
    stack[top] = None
    top -= 1
def showStack():
    if top != -1:
        print("stack = {} | Top of stack is stack[{}] = {}".format(stack, top, stack[top]))
    else:
        print("stack = {} | Stack is empty.".format(stack))

while True:
    print("--------------------------------------------------------")
    print("Menu: 1.Push 2.Pop 3.Show 4.Exit")
    choise = input("Choose menu: ")
    print("--------------------------------------------------------")

    if choise == "1":
        if top != 7:
            pushStack()
        else:
            print("Stack is fulled.")
    elif choise == "2":
        if top != -1:
            popStack()
        else:
            print("Stack is empty.")
    elif choise == "3":
        showStack()
    elif choise == "4":
        print("Exited program.")
        break
    else:
        print("Your choise's incorrect, please choose again.")
        continue