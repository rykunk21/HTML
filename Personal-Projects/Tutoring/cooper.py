import copy


def findpar(tree, root, vertex):
    # if search for root
    if vertex == root:
        return []

    
    if vertex in tree[root]:
        return True
    else:
        return False

    
    for node in tree.keys():
        if findpar(tree, node, vertex):
            return node


def main():
    print(findpar(
        {'A':['B','C'], 'B':[], 'C':[], 'D':[], 'E':[], 'F':[]},
        'A', 'F'
    ))




if __name__ == '__main__':
    main() 