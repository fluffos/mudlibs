/*

  Arena for guildmaster challenges.



  Diewarzau 7/4/96

  DarkeLIB 1.0

*/



#include <rooms.h>

#include <security.h>

#define ARENA "/std/diewarzau/rooms/gm_arena"



inherit "/std/room";



int cip = 0;

object chal = 0;

object gm = 0;

int go = 0;

int spon = 0;



void create() {

  ::create();

  seteuid(getuid());

  set_short("The Guild Master Arena");

  set_long(

	   "This is the arena where the guild master rite of "

	   "challenge takes place.  A small field is bordered by "

	   "fences on all sides.");

  set_property("indoors", 1);

  set_property("light", 2);

  set_property("no scry", 1);

  set_property("no summon", 1);

  set_property("no teleport", 1);

  add_exit("/d/standard/square", "surrender");

  add_pre_exit_function("surrender", "do_surrender");

  return;

}



void init() {

  add_action("do_cast", "cast");

  add_action("check_use", "use");

  add_action("check_kill", "kill");

  return;

}



int do_cast(string str) {

  if(go) return 0;

  write("You may not do that until the challenge begins!");

  return 1;

}



int check_use(string str) {

  if(go) return 0;

  write("You may not do that until the challenge begins!");

  return 1;

}



int check_kill(string str) {

  if(go) return 0;

  write("You may not do that until the challenge begins!");

  return 1;

}



int do_surrender() {

  this_player()->set("death save", 0);

  if(!cip || !gm || !chal) return 1;

  if(!present(gm) || !present(chal)) {

    cip = 0;

    return 1;

  }

  remove_call_out("begin_challenge");

  if(this_player() == gm) {

    message("info", "By surrendering, you have lost your guildmaster position!\n\n", gm);

    call_other("/std/diewarzau/obj/misc/death_func", "gm_death", gm, chal);

    return 1;

  }

  else if(this_player() == chal) {

    message("info", "You have lost the guild master challenge.\n\n", chal);

    "/daemon/chat"->send_chat("darke","DemiUrge",

      (string)chal->query_cap_name() + " has surrendered to "+

      (string)gm->query_cap_name() +

      " in the challenge for the position of Guild Master of the "+

      pluralize(capitalize((string)gm->query_class()))+"!");

    message("info", "%^GREEN%^%^BOLD%^You are transported to the church.", gm);

    gm->move(ROOM_START);

    return 1;

  }

  return 1;

}



void set_cip(int x) {

  cip = x;

  if(!x) {

    go = x;

    spon = 0;

  }

}



int query_spon() { return spon; }



object query_chal() { return chal; }



object query_gm() { return gm; }



void set_gm(object ob) { gm = ob; }



void set_chal(object ob) { chal = ob; }



int query_cip() { return cip; }



void sponsor(object who) {

  if(!cip) return;

  if(spon) {

    message("info", "The challenge has already been sponsored.",

	    who);

    return;

  }

  if(!gm) {

    "/daemon/chat"->send_chat("darke","DemiUrge",

      "Could not find the guild master.  Challenge is nullified.");

    cip = 0;

    gm = 0;

    chal = 0;

    return;

  }

  if(!chal) {

    "/daemon/chat"->send_chat("darke","DemiUrge",

      "Could not find the challenger.  Challenge is nullified.");

    cip = 0;

    gm = 0;

    chal = 0;

    return;

  }

  go = 0;

  if(!interactive(gm) && interactive(chal)) {

    "/daemon/chat"->send_chat("darke","DemiUrge",

      "The Guild Master is net dead, so "+(string)chal->query_cap_name() +

      " becomes the guild master of the "+

      (string)chal->query_class()+" guild!");

    call_other("/std/diewarzau/obj/misc/death_func", "gm_death", gm, chal);

    cip = 0;

    gm = 0;

    chal = 0;

    return;

  }

  else if(!interactive(chal)) {

    "/daemon/chat"->send_chat("darke","DemiUrge",

      "The challenger is net dead, so the challenge is negated.");

    if(interactive(gm)) {

      message("info", "%^GREEN%^%^BOLD%^You are transported to the church.", gm);

      gm->move(ROOM_START);

    }

    return;

  }

  spon = 1;

  message("info", @TEXT

You have 2 minutes until the challenge begins.  At that time,

you will be transported to the arena, and combat begin.  You may

surrender at any time by typing 'surrender'.  If you are the guild's

master, you will forfeit your position.

TEXT

,({ gm, chal }));



  gm->set("death save",

    (: call_other, "/std/diewarzau/obj/misc/death_func","gm_death" :));

  chal->set("death save",

    (: call_other, "/std/diewarzau/obj/misc/death_func","other_guy" :));

  call_out("begin_challenge", 120);

}



void gm_quit() {

  if(!cip) return;

  remove_call_out("begin_challenge");

  remove_call_out("begin_combat");

  "/daemon/chat"->send_chat("darke","DemiUrge",

    "The Guild Master has conceded, making "+

    (string)chal->query_cap_name() +

    " the new guild master of the "+

    (string)chal->query_class()+" guild!");

  call_other("/cmds/mortal/_challenge", "remove_to_call");

  call_other("/std/diewarzau/obj/misc/death_func", "gm_death", gm, chal);

  cip = 0;

  return;

}



int can_exceed_max_hp() { return 1; }



void chal_quit() {

  object ob;



  remove_call_out("begin_combat");

  remove_call_out("begin_challenge");

  "/daemon/chat"->send_chat("darke","DemiUrge",

    "The challenger has quit, negating the challenge.");

  ({ chal, gm })->move(ROOM_START);

  if(gm && (ob=present("challenge soul", gm))) ob->remove();

  if(chal && (ob=present("challenge soul", chal))) ob->remove();

  cip = 0;

  gm = 0;

  set_chal(0);

  call_other("/cmds/mortal/_challenge", "remove_to_call");

  chal->add_hp(-1 * (int)chal->query_max_hp() - 10);

  return;

}



void begin_combat() {

  if(!interactive(gm) && interactive(chal)) {

    "/daemon/chat"->send_chat("darke", "DemiUrge",

      "The Guild Master is net dead, so "+

      (string)chal->query_cap_name()+

      " becomes the guild master of the "+

      (string)chal->query_class()+" guild!");

    call_other("/std/diewarzau/obj/misc/death_func", "gm_death",

               gm, chal);

    cip = 0;

    gm = 0;

    chal = 0;

    return;

  }

  else if(!interactive(chal)) {

    "/daemon/chat"->send_chat("darke","DemiUrge",

      "The challenger is net dead, so the challenge is negated.");

    if(interactive(gm)) {

      message("info", "%^GREEN%^%^BOLD%^You are transported to the church.", gm);

      gm->move(ROOM_START);

    }

    return;

  }

    "/daemon/chat"->send_chat("darke","DemiUrge",

      "Let the challenge begin!");

  go = 1;

  gm->kill_ob(chal, 1);

}



void begin_challenge() {

  if(!interactive(gm) && interactive(chal)) {

    "/daemon/chat"->send_chat("darke","DemiUrge",

      "The Guild Master is net dead, so "+

      (string)chal->query_cap_name() +

      " becomes the guild master of the "+

      (string)chal->query_class()+" guild!");

    call_other("/std/diewarzau/obj/misc/death_func", "gm_death",

	       gm, chal);

    cip = 0;

    gm = 0;

    chal = 0;

    return;

  }

  else if(!interactive(chal)) {

    "/daemon/chat"->send_chat("darke","DemiUrge",

      "The challenger is net dead, so the challenge is negated.");

    if(interactive(gm)) {

      message("info", "%^GREEN%^%^BOLD%^You are transported to the church.",

              gm);

      gm->move(ROOM_START);

    }

    return;

  }

  "/daemon/chat"->send_chat("darke","DemiUrge",

    "The combatants are transported to the arena!  Combat will begin in 30 sec.");

  ({ gm, chal })->move_player(ARENA, 0);

  call_out("begin_combat", 30);

  return;

}











