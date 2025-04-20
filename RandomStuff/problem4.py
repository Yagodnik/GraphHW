def clamp(a, b):
    if a > b:
        return b

    return a


def step(jar3, jar5, seq, depth=0):
    if depth > 10:
        return
    seq.append((jar3, jar5))

    if jar3 == 1 or jar5 == 1:
        print(seq)
        return

    if (0, jar5) not in seq and jar5 != 0:
        step(0, jar5, seq.copy(), depth + 1)

    if (jar3, 0) not in seq and jar3 != 0:
        step(jar3, 0, seq.copy(), depth + 1)

    if (3, jar5) not in seq:
        step(3, jar5, seq.copy(), depth + 1)

    if (jar3, 5) not in seq:
        step(jar3, 5, seq.copy(), depth + 1)

    x = clamp(jar5 + jar3, 5)
    if (jar3 - (x - jar5), x) not in seq:
        step(jar3 - (x - jar5), x, seq.copy(), depth + 1)

    x = clamp(jar5 + jar3, 3)
    if (x, jar5 - (x - jar3)) not in seq:
        step(x, jar5 - (x - jar3), seq.copy(), depth + 1)


step(3, 0, [])
step(0, 5, [])
