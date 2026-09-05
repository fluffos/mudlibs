#define BLANKS "                                                                        "
#include "/players/feldegast/closed/ansi.h"

string color_pad(string str,int len) {
  int i,l;
  int flag;
  int ansi_length;  /* Length of current ansi code */
  int curr_length;  /* Length without ansi codes   */
  int total_length; /* Total length of the string so it doesn't cut off any codes */
  for(i=0,l=strlen(str); i < l && (total_length - ansi_length) < len; i++)
  {
    if(str[i..i] == ESC) flag = 1;
    if(flag) {
      ansi_length++;
      curr_length++;
      if(str[i..i] == "m") {
        flag = 0;
        total_length+=curr_length;
        curr_length=0;
      }
    }
    else
      total_length++;
  }
  str+=BLANKS;
  if(total_length - ansi_length < len)
    total_length += len - (total_length - ansi_length); /* Blah! */
  return str[0..total_length];
}

