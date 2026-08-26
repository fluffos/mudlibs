// Petrarch
// Merentha Lib 1.0

#include <daemons.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Inside the Cabeiri Healer Hall");
    set_long("Several healers are busy at work healing sick and injured \
commrads.  Some of the less experienced healers are hard at work \
studying the healing arts.  Medicines and bandages fill the shelves which \
line the walls of the hall.");
    set_items(([
"healer":"Many healers here are busy helping wounded friends.",
"medicine":"They cure sickness.",
"bandage":"The bandages are used to stop bleeding.",
"shelves":"The shelves are full of bandages and medicines.",
"shelf":"The shelves are full of bandages and medicines.",
      ]));
    set_exits(([
        "north":"/domains/Cabeiri/east_square",
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
healers.  The top of the list reads \n%^BOLD%^Want to be a Healer?\nSign \
up Here%^RESET%^.\nYou may <sign up> if you wish to become a healer.");
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
      if(this_player()->query_class()) return notify_fail("You already belong to a class and can not sign up to become a healer.\n");
  this_player()->set_class("healer");
  SKILL_D->init_skills(this_object());
  message("action", "You sign up to become a healer.  One of the vetern healers comes over to you and shakes your hand.", this_player());
  message("healer", this_player()->query_cap_name()+" joins the goodwill of the healers.", users());
  return 1;
}

string receive_object(object ob) {
string _class;
  if(_class=::receive_object()) return _class;
  if(!ob) return 0;
  _class=ob->query_class();
  if(_class && _class!="healer") return "You can not join the healers young "+_class+", this is not your hall.";
  return 0;
}


