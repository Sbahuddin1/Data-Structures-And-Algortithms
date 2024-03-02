## Problem Description

Your friend is making a text editor for programmers. They are currently working on a feature that will find errors in the usage of different types of brackets in code.

Code can contain any brackets from the set `[]{}()`, where the opening brackets are `[`, `{`, and `(`, and the corresponding closing brackets are `]`, `}`, and `)`.

For convenience, the text editor should not only inform the user that there is an error in the usage of brackets but also point to the exact place in the code with the problematic bracket. 

The first priority is to find the first unmatched closing bracket which either doesn’t have an opening bracket before it, like `]` in `]()`, or closes the wrong opening bracket, like `}` in `()[}`. 

If there are no such mistakes, then it should find the first unmatched opening bracket without the corresponding closing bracket after it, like `(` in `{}([]`. 

If there are no mistakes, the text editor should inform the user that the usage of brackets is correct.

Apart from the brackets, code can contain big and small Latin letters, digits, and punctuation marks.

More formally, all brackets in the code should be divided into pairs of matching brackets. In each pair, the opening bracket goes before the closing bracket. For any two pairs of brackets, either one of them is nested inside another one (like `(foo[bar])`) or they are separate (like `f(a,b)-g[c]`). 

The bracket `[` corresponds to the bracket `]`, `{` corresponds to `}`, and `(` corresponds to `)`.

### Input Format

Input contains one string 𝑆 which consists of big and small Latin letters, digits, punctuation marks, and brackets from the set `[]{}()`.

### Constraints

- The length of 𝑆 is at least 1 and at most 10^5.

### Output Format

If the code in 𝑆 uses brackets correctly, output `Success`. Otherwise, output the 1-based index of the first unmatched closing bracket. If there are no unmatched closing brackets, output the 1-based index of the first unmatched opening bracket.

### Examples

#### Input

```
[]
```

#### Output

```
Success
```

#### Explanation

The brackets are used correctly: there is just one pair of brackets `[` and `]`, they correspond to each other, the left bracket `[` goes before the right bracket `]`, and no two pairs of brackets intersect, because there is just one pair of brackets.

---

#### Input

```
{}[]
```

#### Output

```
Success
```

#### Explanation

The brackets are used correctly: there are two pairs of brackets — the first pair of `{` and `}`, and the second pair of `[` and `]` — and these pairs do not intersect.

---

#### Input

```
[()]
```

#### Output

```
Success
```

#### Explanation

The brackets are used correctly: there are two pairs of brackets — the first pair of `[` and `]`, and the second pair of `(` and `)` — and the second pair is nested inside the first pair.

---

#### Input

```
(())
```

#### Output

```
Success
```

#### Explanation

Pairs with the same types of brackets can also be nested.