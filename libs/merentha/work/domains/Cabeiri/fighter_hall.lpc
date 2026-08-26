// Petrarch
// Merentha Lib 1.0

#include <daemons.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Inside the Cabeiri Fighter Hall");
    set_long("The hall bustles with activity.  There are warriors of all \
ages and origins here.  Some of the older members are teaching the younger \
ones skills in the arts of fighting.  Many weapons and armours line the \
walls definatly signifing this is the Hall of Fighters.");
    set_items(([
        "warrior":"There are several warriors practicing skills, a couple more are telling stories of conquest and battle.",
        "weapon":"There are swords, knifes, axes, staves, bows and spears on the walls.",
        "armour":"There is armor on the walls ranging from boots and gloves to dragon scaled platemail.",
      ]));
    set_exits(([
        "south":"/domains/Cabeiri/west_square",
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
fighters.  The top of the list reads \n%^BOLD%^Want to be a Fighter?\nSign \
up Here%^RESET%^.\nYou may <sign up> if you wish to become a fighter.");
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
      if(this_player()->query_class()) return notify_fail("You already belong to a class and can not sign up to become a fighter.\n");
  this_player()->set_class("fighter");
  SKILL_D->init_skills(this_object());
  message("action", "You sign up to become a fighter.  One of the vetern fighters comes over to you and shakes your hand.", this_player());
  message("fighter", this_player()->query_cap_name()+" joins the ranks of the fighters.", users());
  return 1;
}

string receive_object(object ob) {
string _class;
  if(_class=::receive_object()) return _class;
  if(!ob) return 0;
  _class=ob->query_class();
  if(_class && _class!="fighter") return "You can not join the fighters young "+_class+", this is not your hall.";
  return 0;
}


