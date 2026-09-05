/* Originally coded by Boltar, modified by mythos */

#include "/players/mythos/closed/ansi.h"
string colorstr,backstr;
string style, name;
object targ;

init(){
    add_action("color","color");
   add_action("cdescribe","cdescribe");
    add_action("setstyle","setstyle");
   add_action("colormmout","colormmout");
   add_action("colormmin","colormmin");
   add_action("colormin","colormin");
   add_action("colormout","colormout");
   add_action("colormhome","colormhome");
   add_action("setback","setback");
    add_action("coloral","coloral");
     add_action("setcolor","setcolor");
    add_action("colorpre","colorpre");
    add_action("target","target");
   }
   
   long() { write("Commands for colorob:\n"+
                  "     color  cdescribe  setstyle  setback setcolor\n"+
                  "     coloral  calorpre  colormmout  colormmin\n"+
                  "     colormin  colormout  colormhome  target\n"+
                  "     norm+setstyle+setcolor+st+norm\n"); }
id(str){
  return str == "colorob";
}
color(str) {
    str=NORM+style+colorstr+str+NORM;
     call_other(targ, "set_title", str);
     return 1;
}
coloral(str) {
    str=NORM+style+colorstr+str+NORM;
     call_other(targ, "set_al_title", str);
     return 1;
}
colorpre(str) {
    str=NORM+style+colorstr+str+NORM;
     call_other(targ, "set_pretitle", str);
     return 1;
}
colormmout(str) {
    str=NORM+style+colorstr+str+NORM;
     command("setmmout "+str,targ);
     return 1;
}
cdescribe(str) {
     str=NORM+style+colorstr+str+NORM;
     targ->describe(str);
     return 1;
  }
setcolor(str){
    if (!backstr)
     backstr = BBLK;
     if (str == "mag")
           colorstr= MAG+backstr;
     if (str == "red")
         colorstr = RED+backstr;
     if (str == "gre")
         colorstr = GRN+backstr;
     if (str == "yel")
         colorstr = YEL+backstr;
     if (str == "blu")
         colorstr = BLU+backstr;
     if (str == "cya")
         colorstr = CYN+backstr;
     if (str == "whi")
         colorstr = WHT+backstr;
return 1;
}
setstyle(str){
      if (str == "norm")
         style = NORM;
     if (str == "bold")
           style = BOLD;
     if (str == "bb")
            style = BOLD+BLINK;
     if (str == "blink")
           style = BLINK;
     if (str == "under")
           style = U;
return 1;
}
short(){ return "A colorfull colorob";}
colormmin(str) {
    str=NORM+style+colorstr+str+NORM;
     command("setmmin "+str,targ);
     return 1;
}
colormin(str) {
    str=NORM+style+colorstr+str+NORM;
     command("setmin "+str,targ);
     return 1;
}
colormout(str) {
    str=NORM+style+colorstr+str+NORM;
     command("setmout "+str,targ);
     return 1;
}
colormhome(str) {
    str=NORM+style+colorstr+str+NORM;
     command("setmhome "+str,targ);
     return 1;
}
setback(str){
     if (str == "mag")
           backstr = BMAG;
     if (str == "red")
             backstr = BRED;
     if (str == "gre")
          backstr = BGRN;
     if (str == "yel")
          backstr = BYEL;
     if (str == "blu")
            backstr = BBLU;
     if (str == "cya")
          backstr = BCYN;
     if (str == "whi")
       backstr = BWHT;
  if (!str)
      backstr = BBLK;
return 1;
}
get(){
   return 1;
  }
target(str) {
if(!str) return 0;
  targ = find_player(str);
  if(!targ) { write("Not here...\n"); targ = this_player(); return 1;}
  write("Targeting "+str+"\n");
  return 1;
}

reset(arg) { if(arg) return;  targ = this_player(); }
