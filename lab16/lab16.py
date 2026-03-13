text = "Hi, absolute number wasn`t found, user got banned"
length = len(text)
for i in range(length):
    if i + 1 < length:
        pair = text[i] + text[i+1]
        if pair == "ab" or pair == "ba":
            print(f"Found a pair '{pair}' at: {i + 1}")

    if i + 2 < length:
        triple = text[i] + text[i+1] + text[i+2]
        if triple == "a b" or triple == "b a":
            print(f"Found a pair separated by a whitespace '{triple}' at: {i + 1}")
