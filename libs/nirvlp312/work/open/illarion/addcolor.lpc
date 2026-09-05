#include "/players/illarion/ansi.h"

mapping colors;

void reset(int arg) {
  colors=(["red":RED,"green":GRN,"yellow":YEL,"blue":BLU,"purple":MAG,
           "cyan":CYN,"black":BLK,"white":WHT,"bold":BOLD,
           "RED":HIR,"GREEN":HIG,"YELLOW":HIY,"BLUE":HIB,"PURPLE":HIM,
           "CYAN":HIC,"BLACK":HIK,"WHITE":HIW,"off":NORM]);
}
string ansi(string str) {
  return colors[str]?colors[str]:"";
}
string addcolor(string str) {
  string before,mid,after;
  while(sscanf(str,"%s`%s`%s",before,mid,after)>=2)
    str=(before?before:"")+ansi(mid)+(after?after:"");
  return str;
}
void showcolors() {
  string *colarr;
  int k;
  colarr = ({ "red","green","yellow","blue","purple","cyan","black","white",
              "RED","GREEN","YELLOW","BLUE","PURPLE","CYAN","BLACK","WHITE"});
  write("Available colors are:\n");
  for(k=0;k<16;k++) {
    write(colors[colarr[k]]+colarr[k]+colors["off"]+" ");
    if(!((k+1)%4)) write("\n");
  }
  write("Also available:\n");
  write("bold off\n");
  return;
}
