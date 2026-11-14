import re

def check_regex_for_words(word_list_file, detail_file):
    # Read the list of words
    with open(word_list_file, 'r', encoding='utf-8') as file:
        word_list = [line.strip() for line in file]

    # Read the details file content
    with open(detail_file, 'r', encoding='utf-8') as file:
        details_text = file.read()

    # Initialize an empty list to store words without matching regex
    words_without_regex = []

    # Check each word against the regex
    for word in word_list:
        regex_pattern = r'\[detail:.*?' + re.escape(word) + r'.*?\]'
        if not re.search(regex_pattern, details_text):
            words_without_regex.append(word)

    return words_without_regex

# Example usage:
word_list_file = 'found'  # Replace with your word list file
detail_file = 'description'   # Replace with your detail file

result = check_regex_for_words(word_list_file, detail_file)

print("Words without matching regex:")
for word in result:
    print(word)
