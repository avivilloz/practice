def find_doubled_value(l):
    s = set()
    for i in l:
        if i not in s:
            s.add(i)
        else:
            return i

def find_doubled_value2(l):
    for i in range(0, len(l)):
        for j in range(i + 1, len(l)):
            if l[i] == l[j]:
                return l[i]

l = [4,2,5,7,3,2,6,8]
print(find_doubled_value(l))
print(find_doubled_value2(l))