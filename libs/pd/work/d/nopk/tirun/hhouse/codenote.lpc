#include <std.h>
#include <tirun.h>
inherit OBJECT;

string do_read(string x);
void do_remove(object tp);

void create() {
  ::create();

  set_name("note");
  set_short("a crumpled up note");
  set_long("This seems to be a small reminder of some sort.");
  set_id(({"crumpled note", "note", "crumpled up note"}));
  set_mass(1);
  set_value(0);
  set("no store", 1);
  set_read("default", (: do_read :) );
}

string do_read(string x) {
  call_out("do_remove", 0, this_player());
  return "You are only able to discern a few hastily scrawled numbers:\n"+
         ((string)load_object(ROOMS+"hhouse/outside")->query_code())+"";
}

void do_remove(object tp) {
  if (tp) {
    message("emote", "The note crumbles in your hands.", tp);
    message("emote", "The note crumbles in "+tp->query_cap_name()+"'s hands.",
      environment(tp), tp);
  }
  this_object()->remove();
}
