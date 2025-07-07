Q = [None, None, None, None, None]
frontQ = rearQ = -1
Qlenght = 5

#function for check that Q is full  or not full.
def isFull():
    if (rearQ+1)%Qlenght == frontQ:
        return True
    else:
        return False

def isEmpty():
    if frontQ == -1 and rearQ == -1:
        return True
    else:
        False

def enQ():
    global frontQ, rearQ
    enQItem  = int(input("Enter enqueue item: "))
    if not(frontQ==-1 and rearQ==-1):
        rearQ = (rearQ + 1) % Qlenght
        Q[rearQ] = enQItem
    else:
        frontQ = rearQ = 0
        Q[rearQ] = enQItem

def deQ():
    global frontQ, rearQ
    Q[frontQ] = None
    if frontQ != rearQ:
        frontQ = (frontQ + 1) % Qlenght
    else:
        frontQ = rearQ = -1

def showQ():
    print(f"Queue(Circular Queue)={Q} Front={frontQ} Rear={rearQ}")

while True:
    print("-----------------------------------------------------------------------")
    print("Menu: 1.Enqueue 2.Dequeue 3.Show queue 4.Exit")
    menu = input("Choose a menu: ")
    print("-----------------------------------------------------------------------")

    if menu == "1":
        if not(isFull()):
            #if Q is not full then this indent will work.
            enQ()
        else:
            print("Queue is full")
    elif menu == "2":
        if not(isEmpty()):
            #if Q is not empty then this indent will work.
            deQ()
        else:
            print("Queue is empty")
    elif menu == "3":
        showQ()
    elif menu == "4":
        break
    else:
        continue