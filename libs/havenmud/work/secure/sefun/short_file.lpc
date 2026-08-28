/*  short_file.c
  *  written because I wanted to be able to use
  * the code I wrote for the "people" command
  * in more places.  So I made it a sefun and
  * removed that old code from the people command.
  * Man, I am too cool.
  *  Duuk 11 July 2004
  */
#include <dirs.h>

string short_file(string file) {

  if (!file) return "";

  file = replace_string(file, REALMS_DIRS "/", "~", 1);
  file = replace_string(file, DOMAINS_DIRS "/", "^", 1);
  file = replace_string(file, "southern_coast", "SC", 1);
  file = replace_string(file, "gurov", "GV", 1);
  file = replace_string(file, "frostmarches", "FM", 1);
  file = replace_string(file, "tairi", "TR", 1);
  file = replace_string(file, "valley", "VL", 1);
  file = replace_string(file, "baria", "BR", 1);
  file = replace_string(file, "peninsula", "PN", 1);
  file = replace_string(file, "averath", "AV", 1);
  file = replace_string(file, "havenwood", "HW", 1);
  file = replace_string(file, "westwood", "WW", 1);
  file = replace_string(file, "estergrym", "EG", 1);
  file = replace_string(file, "estates", "EE", 1);
  file = replace_string(file, "namatar", "NM", 1);
  file = replace_string(file, "yozrath", "YZ", 1);
  file = replace_string(file, "xandria", "X", 1);
  file = replace_string(file, "planes", "OP", 1);
  file = replace_string(file, "crystal_reaches", "CR", 1);
  file = replace_string(file, "innersea", "IN", 1);
  file = replace_string(file, "islands", "IS", 1);
  file = replace_string(file, "virtual", "~v", 1);
  file = replace_string(file, "areas", "~a", 1);
  file = replace_string(file, "towns", "~t", 1);
  return file;
}
