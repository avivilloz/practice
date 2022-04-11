def remove_spaces(str):
    str = list(str)
    str.append('\0')
    word_index = find_next_word(str, 0)
    spaces_index = 0
    while str[word_index] != '\0':
        if str[spaces_index] == ' ':
            while str[word_index] != ' ':
                str[spaces_index], str[word_index] = str[word_index], str[spaces_index]
                spaces_index += 1
                word_index += 1
        word_index = find_next_word(str, word_index)
        spaces_index += 1
    str[spaces_index - 1] = '\0'
    return "".join(str)

def find_next_word(str, i):
    while str[i] == ' ':
        i += 1
    return i

str = "    hey    my name    is  aviv           "
print(str)
str = remove_spaces(str)
print(str)
