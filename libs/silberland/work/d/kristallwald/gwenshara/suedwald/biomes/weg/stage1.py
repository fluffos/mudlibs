import re

def find_non_sentence_capitalized_words(text):
    sentences = re.split(r'(?<!\w\.\w.)(?<![A-Z][a-z]\.)(?<=\.|\?)\s', text)
    non_sentence_capitalized_words = set()

    for sentence in sentences:
        words = re.findall(r'\b[A-ZÄÖÜ][A-ZÄÖÜa-zäöüß]*\b', sentence)
        non_sentence_capitalized_words.update(words[1:])  # Exclude the first word in each sentence

    return set(map(str.lower, non_sentence_capitalized_words))

def find_all_non_sentence_capitalized_words(filename):
    with open(filename, 'r', encoding='utf-8') as file:
        content = file.read()

    return find_non_sentence_capitalized_words(content)


def find_words_with_detail_entries(text):
    detail_pattern = r'\[detail:([^|\]]+)(?:\|[^|\]]+)*\]'
    detail_matches = re.findall(detail_pattern, text)

    return set(detail_matches)

def find_words_with_detail_alternatives(filename):
    with open(filename, 'r', encoding='utf-8') as file:
        content = file.read()

    return find_words_with_detail_entries(content)

def find_words_without_detail_entries(all_words_set, words_with_detail_set):
    return all_words_set - words_with_detail_set

if __name__ == "__main__":
    filename = 'description'
    all_words_set = find_all_non_sentence_capitalized_words(filename)
    words_with_detail_set = find_words_with_detail_alternatives(filename)
    words_without_detail_set = find_words_without_detail_entries(all_words_set, words_with_detail_set)

    print("Words without corresponding [detail] entry:")
    for word in words_without_detail_set:
        print(word)
