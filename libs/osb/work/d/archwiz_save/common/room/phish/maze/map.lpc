#include "path.h"
#include <moving.h>
inherit "/std/thing";

int a,b,c,d,e,f,g,h;

create(){
  ::create();
  maze_reset();
  AddId("map");
  AddId("mmap");
  SetShort("A map of a difficult maze");
  SetHelpMsg(
"Just read the map to get to know more about the construction "
"of this maze. The map will help you by showing you, where you went.\n");
 }

init(){
  ::init();
  add_action("read","QueryLong");
 }

QueryA(){return a;}
QueryB(){return b;}
QueryC(){return c;}
QueryD(){return d;}
QueryE(){return e;}
QueryF(){return f;}
QueryG(){return g;}
QueryH(){return h;}

SetA(){return a=1;}
SetB(){return b=1;}
SetC(){return c=1;}
SetD(){return d=1;}
SetE(){return e=1;}
SetF(){return f=1;}
SetG(){return g=1;}
SetH(){return h=1;}

maze_reset(){
 a=0;b=0;c=0;d=0;e=0;f=0;g=0;h=0;
 return 1;
 }

QueryLong(){
  string str;
str ="\
 FINAL GOAL               CURRENT STATUS\n\
============             ================\n\
\n\
    A                      "+LineOne()+"\n\
   / \\                     "+LineTwo()+"\n\
  B---C                    "+LineThree()+"\n\
  |\\ /|                    "+LineFour()+"\n\
  | X |                    "+LineFive()+"\n\
  |/ \\|                    "+LineSix()+"\n\
  D---E                    "+LineSeven()+"\n\
\n\
Form the figure above without using the same\n\
path twice.  There are only five rooms... how\n\
hard can it be?\n\
";
  return str;
}

CheckVictory(){
 if((a+b+c+d+e+f+g+h) == 8){call_out("Victory",1);return 1;}
 else {return 0;}
}

Victory(){
  if (!this_player()) return 0;
  write("You have solved the maze!  Congratulations!!!\n");
  this_player()->move(PHISH("victory"),M_GO,"out");
  maze_reset();
  return 1;
 }

Stuck(){ call_out("Stuck2",1); return 1;}

Stuck2(){
  if (!this_player()) return 0;
  write("Oh no!  You trapped yourself... gotta start over now!\n");
  this_player()->move(PHISH("maze_entrance"),M_GO,"out");
  maze_reset();
  return 1;
 }

string DoCross(string str){
  if(QueryE() && QueryF()){str = str + "X";return str;}
  if(QueryE()){str = str + "\\";return str;}
  if(QueryF()){str = str + "/";return str;}
  else{return str = str+" ";}
 }

string LineOne(){
  string str;
  str = "  A  ";
  return str;
 }

string LineTwo(){
  string str;
  str = " ";
if(QueryA()){str = str + "/";}
else{str = str + " ";}
str = str+" ";
if(QueryB()){str = str + "\\";}
else{str = str + " ";}
  return str;
 }

string LineThree(){
  string str;
  str="B";
if(QueryC()){str = str + "---";}
else{str = str + "   ";}
str = str + "C";
  return str;
}

string LineFour(){
  string str;
if(QueryD()){str = "|";}
else{str = " ";}
if(QueryE()){str = str + "\\";}
else{str = str + " ";}
str = str+" ";
if(QueryF()){str = str + "/";}
else{str = str + " ";}
if(QueryG()){str= str+"|";}
else{str = str+" ";}
  return str;
 }

string LineFive(){
  string str;
if(QueryD()){str = "|";}
else{str = " ";}
str = str +" ";
str = DoCross(str);
str = str +" ";
if(QueryG()){str= str+"|";}
else{str = str+" ";}
  return str;
 }

string LineSix(){
  string str;
if(QueryD()){str = "|";}
else{str = " ";}
if(QueryF()){str = str + "/";}
else{str = str + " ";}
str = str+" ";
if(QueryE()){str = str + "\\";}
else{str = str + " ";}
if(QueryG()){str= str+"|";}
else{str = str+" ";}
  return str;
 }

string LineSeven(){
  string str;
  str="D";
if(QueryH()){str = str + "---";}
else{str = str + "   ";}
str = str + "E";
  return str;
 }
