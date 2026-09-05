#ifndef BAD_FILE_H
#define BAD_FILE_H

varargs status bad_file(string file, string *bad_char) {
  string *illegal, tmp1, tmp2;
  int i;

  illegal = ({ " ", "!", "#", "$", "%", "^", "&", "(", ")",
               "=", "+", "<", ">", ":", ";", "\"", "'", ",",
               "{", "}", "[", "]", "|", "\\",
            });

  if (bad_char && pointerp(bad_char)) illegal += bad_char;

  for (i=0; i<sizeof(illegal); i++) {
    if (sscanf(file, "%s" + illegal[i] + "%s", tmp1, tmp2)) {
      return 1;
    }
  }
  return 0;
}

#endif /* BAD_FILE_H */

