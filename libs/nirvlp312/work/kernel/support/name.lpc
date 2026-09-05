/*
 * /kernel/support/name.c
 */

#include <ctype.h>

mixed to_real_name(mixed name) {
  if (pointerp(name))
    return map(name,#'to_real_name);
  name = to_string(map(to_array(name)[0..strlen(name)-1],(: isotoascii($1) :)));
  return
    lower_case(to_string(to_array(name)[0..strlen(name)-1] - ({ '-','\'' })));
}

int valid_name(string name) {
  name = to_string(map(to_array(name)[0..strlen(name)-1],(: isotoascii($1) :)));
  if (strlen(name)==0 || strlen(name)>11)
    return 0;
  if (sizeof(regexp( ({ name }), "[^A-Za-z'-]")))
    return 0;
  if (name[0]=='\'' || name[0]=='-' || name[<1]=='\'' || name[<1]=='-')
    return 0;
  if (strlen(name)-sizeof(to_array(name)-({ '\'','-',0 }))>1)
    return 0;
  return 1;
}

int valid_capitalization(string name) {
  int *temp;
  int i,caps;

  temp = to_array(name)[0..strlen(name)-1];
  for (i=0; i < sizeof(temp) && temp[i]; i++) {
    if (i==0 || temp[i-1]=='-')
      if (!isupper(isotoascii(temp[i])))
        return 0;
    if (isupper(isotoascii(temp[i])))
      caps++;
  }
  if (caps>3)
    return 0;
  return 1;
}

string standard_capitalization(string name) {
  int *temp;
  int i;

  temp = to_array(lower_case(name))[0..strlen(name)-1];
  for (i=0; i < sizeof(temp) && temp[i]; i++)
    if ((i==0 || temp[i-1]=='-') && islower(temp[i]))
      temp[i]=toupper(temp[i]);
  return to_string(temp);
}

