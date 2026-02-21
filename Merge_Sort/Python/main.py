
def merge(left,right,compare):
    result = []
    while left and right:
       
        if compare(left[0],right[0]):
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))

    return result+left+right

def merge_sort(array,compare):
    if len(array) <= 1:
        return array
    return merge(left=merge_sort(array[:int(len(array)/2)],compare=compare),right=merge_sort(array[int(len(array)/2):],compare=compare),compare=compare)


if __name__ == '__main__':
    print("Hello")
    array = []
    for i in range(20,0,-1):
        array.append(i)

    print(array)

    array = merge_sort(array=array,compare=lambda a, b: a < b)
    print(array)





  