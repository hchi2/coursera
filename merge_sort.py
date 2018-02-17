


def merge_sort(l):
    if len(l) <= 1:
        return l
    x = merge_sort(l[0: len(l)/2])
    y = merge_sort(l[len(l)/2:])

    z = merge(x, y)
    return z

def merge(x, y):

    l = len(x) + len(y)
    j, k = 0, 0
    r = list()
    for i in range(l):
        if j == len(x):
            r += y[k:]
            return r
        if k == len(y):
            r += x[j:]
            return r

        if x[j] <= y[k]:
            r.append(x[j])
            j += 1
        else:
            r.append(y[k])
            k += 1
        
    return r


if __name__ == '__main__':
    print merge_sort(list(reversed(range(100000000))))
