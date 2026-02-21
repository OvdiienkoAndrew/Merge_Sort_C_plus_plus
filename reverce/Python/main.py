import random, time


def reverce(array):
    demo = []
    while array:
        demo.append(array.pop())
    return demo

if __name__ == '__main__':
    array = []
    N = 10**3
    for i in range(N):
        array.append(random.randint(0, 9))
    # print(array)
    s = time.time()
    array = reverce(array)
    print(time.time()-s)
    #print(array)
   
    
