'''
This program gives you the actually set of arrays showing the words that join in many
ways to make the word.
'''

def can_make(target, words):
    arr = [[] for _ in range(len(target) + 1)]
    arr[0] = [[]]

    for i in range(len(target) + 1):
        for word in words:
            if i + len(word) <= len(target) and target[i : (i + len(word))] == word:
                new_combinations = [combination + [word] for combination in arr[i]]
                arr[i + len(word)].extend(new_combinations)

    return arr[len(target)]

print(can_make("abcdef", ["ab", "abc", "cd", "def", "abcd","ef","c"]))
print(can_make("skateboard", ["bo", "rd", "ate", "t", "ska", "sk", "boar"]))
print(can_make("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"]))