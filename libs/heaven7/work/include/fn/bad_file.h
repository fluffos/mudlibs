#ifndef BAD_FILE_H
#define BAD_FILE_H

#include <mudlib.h>

varargs status bad_file(string file, string *bad_char) {
  string *illegal, tmp1;
#ifndef MUDOS_DR
  string tmp2;
#endif
  int i;

  illegal = ({ " ", "!", "#", "$", "%", "^", "&",  "(", ")",
               "=", "+", "<", ">", ":", ";", "\"", "'", ",",
               "{", "}", "[", "]", "|", "\\",
            });
               
  if(bad_char && pointerp(bad_char)) illegal += bad_char;

  for(i = 0; i < sizeof(illegal); i++) {
#ifdef MUDOS_DR
    tmp1 = replace_string(file,illegal[i],"#");
    if(strcmp(file,tmp1)) {
#else
    if(sscanf(file,"%s"+illegal[i]+"%s", tmp1, tmp2)) {
#endif /* MUDOS_DR */
      return 1;
    }
  }
  return 0;
}

#endif /* BAD_FILE_H */