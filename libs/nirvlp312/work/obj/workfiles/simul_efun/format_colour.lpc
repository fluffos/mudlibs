#include "/obj/ansi.h"

string format_colour(string str, int num){
  mapping ansi_positions;
  string formatted_string, heh;
  int i, s, j;
  
  ansi_positions = (mapping)"/obj/simul_efun/m_efuns"->get_ansi_positions(str);
#ifndef __LDMUD__ /* Rumplemintz */
  formatted_string = format((string)"/obj/simul_efun/m_efuns"->delete_colour(str), num);
#else
  formatted_string = sprintf("%*-=s",70,(string)"/obj/simul_efun/m_efuns"->delete_colour(str), num);
#endif
  
  i = 0;
  s = strlen(formatted_string);
  heh = "";
  
  while(i < s){
    if(formatted_string[j] == '\n'){
      heh += "\n";
      j ++;
      i ++;
      continue;
    }
    heh += (ansi_positions[i]?ansi_positions[i]:"")+formatted_string[j..j];
    j++;
    i++;
  } 
  return heh + NORM;
}
