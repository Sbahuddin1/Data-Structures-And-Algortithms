def can_make(target, words):
    arr = [0] * (len(target) + 1)
    arr[0] = 1

    for i in range(len(target) + 1):
            for word in words:
                if target[i : (i + len(word))] == word:
                    arr[i + len(word)] += arr[i]

    return arr[len(target)]


print(can_make("abcdef", ["ab", "abc", "cd", "def", "abcd"]))
print(can_make("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"]))
print(can_make("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"]))
