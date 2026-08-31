/*HERP: no ; after #include, please */

#include "/players/skeeve/area.h"

#define DEST "/players/skeeve/workroom"

/*
 * The predefined string DEST is where a player should come when he
 * leaves the castle.
 *
 * This file is loaded automatically from "init_file". We have to move
 * ourself to where we are supposed to be.
 */

object quest;

make_quest() {
      quest=clone_object("obj/quest_obj");
      quest->set_name("fishsoup");
      quest->set_weight(17);
      quest->set_killing(4);
      quest->set_short_hint("Make the dinner for druid Lakmir");
      quest->set_hint("Druid Lakmir's cook is died, as he make the dinner.\n"+
                      "Go to the manager and ask for the job.\n");
// Sauron: Removed by Sauron (220497). This quest is now in Emerald's castle.
//      quest->add_quest();
}
                
id(str) { return str=="castle"; }

reset(arg) {
  if (!arg) {
    move_object(this_object(),DEST);
    call_other(ROAD+"northgate", "???"); 
  }
}

short() { return "The castle of Lord Skeeve"; }

object *mon_names = ({});
string *mon_p = ({});
int *borns=({});
  
long() {
  int i;
  string str;
  str = "This is the castle of Lord Skeeve.\n"
      + " The living monsters:\n";
  for (i=0;i<sizeof(mon_p);i++) {
      str += "  "+capitalize(mon_names[i])+"("+borns[i]+")   : ";
      if (mon_p[i])
        str += (environment(mon_p[i]))?file_name(environment(mon_p[i])) :"unknown";
      else str+="not alive";
      str +="\n";
    } 
  write (str);
}

add_monster(new, where) {
  int i;
  
  i = member_array(new,mon_names);
  if (i<0) {
    i=sizeof(mon_p);
    mon_names+=({new});
    borns+=({0});
    mon_p+=({0});
  } 
  if (!mon_p[i]){
    borns[i]++;
    mon_p[i]=clone_object(MONSTERS+new);
  }    
  move_object(mon_p[i],where);
  return mon_p[i];
}

query_monster(string mon) {   
  int i;
  i = member_array(mon,mon_names);
  return (i<0)? 0:mon_p[i]; 
}

create_monster(string mon){
  if (mon == "danseuse" && !find_living("danseuse"))
     add_monster("/room/vill_green");
}

monster_died(string mon) { 
  if (mon=="danseuse")
    call_out ("create_monster",30+random(60),"danseuse");
}

add_interior(what,where,con) {
  object ob;
  if (stringp(con)) {
    if (!ob=present(con,where))
      move_object(ob=clone_object(INTERIOR+what)->config(con,where),where);    
  } else {
    if (!ob=present(what,where)) {
      ob = clone_object(INTERIOR+what);
      if (con) ob->config(con,where);
      move_object(ob,where); 
    } 
  }
  return ob;
}

add_sphinx_obj(what,where){
  if (!present(what,where))
    move_object(clone_object(OBJECTS+"sphinx_obj")->config(what,where),where);
}
