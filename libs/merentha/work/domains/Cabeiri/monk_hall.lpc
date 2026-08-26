// Petrarch
// Merentha Lib 1.0

#include <daemons.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Inside the Cabeiri Monk Hall");
    set_long("Dozens of monks sit in deep meditation around the walls of \
the hall in a near perfect circle.  Still dozens more are freely moving \
about in conversation with their peers.  A few are deep in study of the \
faith while others practice hand to hand combat.");
    set_items(([
"monk":"There are many monks here all doing their own thing.",
      ]));
    set_exits(([
        "north":"/domains/Cabeiri/west_square",
      ]));
}

void reset() {
    object ob;
    ::reset();
    if(!present("table")) {
        ob=new(OBJECT);
        ob->set_name("table");
        ob->set_short("a large oak table");
        ob->set_long("On the table are several piles of paper.  Upon closer \
inspection one of the piles is actually a list of newly signed up \
monks.  The top of the list reads \n%^BOLD%^Want to be a Monk?\nSign \
up Here%^RESET%^.\nYou may <sign up> if you wish to become a monk.");
        ob->set_id(({"table", "oak table"}));
        ob->set_prevent_get("The table is much to large to pick up.");
        ob->move(this_object());
    }
}

void init() {
    ::init();
    add_action("cmd_sign", "sign");
}

int cmd_sign(string str) {
    if(!str || member_array(str, ({"up", "paper"}))==-1) return notify_fail("Sign what?\n");
      if(this_player()->query_class()) return notify_fail("You already belong to a class and can not sign up to become a monk.\n");
  this_player()->set_class("monk");
  SKILL_D->init_skills(this_object());
  message("action", "You sign up to become a monk.  One of the vetern monks comes over to you and shakes your hand.", this_player());
  message("monk", this_player()->query_cap_name()+" joins the faithful of the monks.", users());
  return 1;
}

string receive_object(object ob) {
string _class;
  if(_class=::receive_object()) return _class;
  if(!ob) return 0;
  _class=ob->query_class();
  if(_class && _class!="monk") return "You can not join the monks young "+_class+", this is not your hall.";
  return 0;
}


