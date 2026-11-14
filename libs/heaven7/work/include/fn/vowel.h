#ifndef VOWEL_H
#define VOWEL_H

status vowel(string str) {
  if(!str) return 0;
  return (str[0] == 'a' || str[0] == 'A' || str[0] == 'e' || str[0] == 'E'
       || str[0] == 'i' || str[0] == 'I' || str[0] == 'o' || str[0] == 'O'
       || str[0] == 'u' || str[0] == 'U');
}

#endif /* VOWEL_H */
