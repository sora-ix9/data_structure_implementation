queue = [None, None, None, None, None]
queueLength = 5
frontQueue = 0
rearQueue = 0

def enqueue():
    global rearQueue
    enqueueItem = int(input("Enter enqueue item: "))
    if ((frontQueue==0 and rearQueue==0) and (queue[0]!=None)) or (frontQueue!=rearQueue):
        rearQueue += 1
        queue[rearQueue] = enqueueItem
    elif (frontQueue==0 and rearQueue==0) and (queue[0]==None):
        queue[0] = enqueueItem

def dequeue():
    global frontQueue, rearQueue
    queue[frontQueue] = None
    if frontQueue != rearQueue:
        frontQueue += 1
    else:
        frontQueue = 0
        rearQueue = 0

def show():
    print(f"Queue={queue} Front={frontQueue} Rear={rearQueue}")

while True:
    print("--------------------------------------------------------")
    print("Menu : 1.Enqueue 2.Dequeue 3.Show queue 4.Exit")
    choice = input("Enter your choice: ")
    print("--------------------------------------------------------")

    if choice == '1':
        if rearQueue != (queueLength - 1):
            enqueue()
        else:
            print("Queue is full")
    elif choice == '2':
        if (frontQueue==0 and rearQueue==0) and (queue[0]==None):
            print("Queue is empty")
        elif frontQueue >= 0 and rearQueue <= (queueLength - 1):
            dequeue()
    elif choice == '3':
        show()
    elif choice == '4':
        break
    else:
        continue