/*
This is the waiting room between fights.  When the command 'begin'
is executed from staff.c, all of the players here are moved to arenas.
The healing loop is here so that vampires and dark mages aren't put at
a disadvantage if there is a delay between fights.

There is no fighting or spellcasting allowed here.  By this point,
players should've set their spar pk in the previous room.
*/
#include "defs.h"

inherit ROOM;

int peeps;

void start_hb(int arg);
void heartbeat();

void reset(int arg) {
  if(arg) return;
  set_light(1);
  set_no_magic(1);
  set_no_fight(1);
  short_desc=BOLD+"Grand Tournament of Nirvana"+NORM;
  long_desc=
    "This is the room where we wait until everybody's ready.\n";
  items=({
  });
  dest_dir=({
  });
}

void init() {
  ::init();
  if(TP->is_player()) peeps++;
  start_hb(1);
  add_action("cmd_list","list");
}

void exit() {
  ::exit();
  if(TP && TP->is_player()) peeps--;
  if(peeps <= 0) start_hb(0);
}

void start_hb(int arg) {
  while(remove_call_out("heartbeat")!=-1) ;
  if(arg==1)
    call_out("heartbeat",1);
}

void heartbeat() {
  object *kids;
  int i,size;
  kids=all_inventory(this_object());
  size=sizeof(kids);
  for(i=0; i < size; i++) {
    if((int)kids[i]->query_hp() < (int)kids[i]->query_mhp())
      tell_object(kids[i],"You are healed.\n");
    kids[i]->heal_self(200);
  }
  call_out("heartbeat",5);
}

int cmd_list(string str) {
  string *kids;
  int i;
  kids=(string *)(MASTER->query_players());
  write("Fights:\n------\n");
  for(i=0; i < sizeof(kids); i+=2) {
    if(i==sizeof(kids)-1) {
      write("Odd man: "+capitalize(kids[i])+"\n");
    } else
    write(capitalize(kids[i])+" vs. "+capitalize(kids[i+1])+"\n");
  }
  return 1;
}
