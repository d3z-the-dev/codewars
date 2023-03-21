def stock_list(list_of_art, list_of_cat):
    if not list_of_art or not list_of_cat: return ''
    quantities = {category: 0 for category in list_of_cat}
    for book in list_of_art:
        code, i = book.split()
        if code[0] in quantities:
            quantities[code[0]] += int(i)
    return ' - '.join(f"({category} : {quantities[category]})" for category in list_of_cat)
