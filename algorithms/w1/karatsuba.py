
def multiply(x, y):
    if len(x) <= 2:
        return str(long(x) * long(y))
    n = len(x)
    a = x[: n/2]
    b = x[n/2:]
    c = y[: n/2]
    d = y[n/2:]
    ac = multiply(a, c)
    bd = multiply(b, d)
    ad = multiply(a, d)
    bc = multiply(b, c)
    print(ac)
    
    o1 = pad_zeros(ac, n)
    o2 = pad_zeros(add(ad, bc), n/2)
    o3 = bd

    return add(add(o1, o2), o3)

def pad_zeros(x, n):
    r = list(x)
    r += ['0'] * n
    return ''.join(r)


def add(x, y):
    print('add')
    print(x)
    print(y)
    import itertools
    carry = 0
    result = list()

    for i, j in itertools.izip_longest(reversed(list(x)), reversed(list(y))):
        i = i or '0'
        j = j or '0'
        k = int(i) + int(j) + carry
        carry = 0
        if k >= 10:
            carry = 1
        result.append(list(str(k))[-1])
    if carry > 0:
        result.append('1')
    r = ''.join(reversed(result))
    print(r)
    assert long(r) == long(x) + long(y)
    return r

if __name__ == '__main__':
    import sys
    a = '3141592653589793238462643383279502884197169399375105820974944592'
    b = '2718281828459045235360287471352662497757247093699959574966967627'
    # a = '99999999'
    # b = '99999999'
    c = multiply(a, b)
    print(c)
    print(long(a) * long(b))
