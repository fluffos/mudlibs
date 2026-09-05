/* Just something thrown together for a mob Linus was doing */

#include "/open/ansi.h"

string get_color() {
  int i;

  i = random(13);

  switch(i) {
    case 0  : return HIY;
    case 1  : return WHT;
    case 2  : return BLU;
    case 3  : return GRN;
    case 4  : return YEL;
    case 5  : return RED;
    case 6  : return CYN;
    case 7  : return MAG;
    case 8  : return HIM;
    case 9  : return HIC;
    case 10 : return HIK;
    case 11 : return HIG;
    case 12 : return HIR;
    case 13 : return HIB;
  }
}

string color_name(string arg) {
  string temp;
  int i, len;

  len = strlen(arg);
  temp = "";

  for (i = 0; i < len; i++) 
    temp += get_color()+arg[i..i];

  temp += NORM;
  return temp;
}
