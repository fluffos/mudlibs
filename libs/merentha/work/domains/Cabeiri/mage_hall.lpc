// Petrarch
// Merentha Lib 1.0

#include <daemons.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Inside the Cabeiri Mage Hall");
    set_long("Several magi stand by the door conjuring up simple items \
and generally having a good time doing so.  Several other magi are deep \
in study learning more complicated magic.");
    set_items(([
"mage":"Most of the magi here are practicing their magic skills.",
"magi":"Most of the magi here are practicing their magic skills.",
      ]));
    set_exits(([
        "south":"/domains/Cabeiri/east_square",
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
magi.  The top of the list reads \n%^BOLD%^Want to be a Mage?\nSign \
up Here%^RESET%^.\nYou may <sign up> if you wish to become a mage.");
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
      if(this_player()->query_class()) return notify_fail("You already belong to a class and can not sign up to become a mage.\n");
  this_player()->set_class("mage");
  SKILL_D->init_skills(this_object());
  message("action", "You sign up to become a mage.  One of the vetern magi comes over to you and shakes your hand.", this_player());
  message("mage", this_player()->query_cap_name()+" joins the magic of the magi.", users());
  return 1;
}

string receive_object(object ob) {
string _class;
  if(_class=::receive_object()) return _class;
  if(!ob) return 0;
  _class=ob->query_class();
  if(_class && _class!="mage") return "You can not join the magi young "+_class+", this is not your hall.";
  return 0;
}


