#include "/players/feldegast/std/sort.h"
#define LINE "----------------------------------------------\n"
do_fog_who(str) {
  object *world;
  string area_name,wiz_name;
  int i,max;
  max=sizeof(users());
  world=users();
  world=sort_array(world,"query_level");
  write("\n");
  write(LINE);
  write(
" Name           Level   Guild    Area\n");
  write(LINE);
  for(i=0;i<max;i++) {
  if(world[i]->query_invis() < TP->query_level()) {
  if(world[i]->query_pl_k())
    write(RED+"*"+NORM);
  else
    write(" ");
   write(pad((string)world[i]->query_name(),15));
    write(pad((string)world[i]->query_level()+"+"+world[i]->query_extra_level(),7));
    write(" ");
    write(pad((string)world[i]->query_guild_name(),4));
    write(" ");
    if(environment(world[i])) {
    if((string)environment(world[i])->realm()=="NT")
      write(HIB+"X"+NORM);
    else
      write(" ");
    if(world[i]->query_fight_area())
      write(RED+"*"+NORM);
    else
      write(" ");
    if((string)environment(world[i])->realm() == "NM")
      write(MAG+"#"+NORM);
    else
      write(" ");
    write(" ");
    area_name=(string)file_name(environment(world[i]));
    sscanf(area_name,"players/%s/",wiz_name);
    if(wiz_name)
      write(pad(capitalize(wiz_name),40));
    else
      write(pad("Nirvana",40));
    }
    wiz_name=0;
    write(NORM+NORM+"\n");
  }
  }
  write(LINE);
  return 1;
}
