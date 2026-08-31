#include <std.h>
#include <tirun.h>

inherit MONSTER;

void create() {
  ::create();

  set_name("");
  set_short("");
  set_long("You do not notice that here.");
  set_level(1);
  set_id(({"thingamajiggy"}));
  set_mass(11);
  set_value(0);
  set_exp(0);
}

int query_invis() {return 1;}

int query_ghost() {return 1;}

void catch_tell(string str) {
    object ob;
    string a, b;

    if(this_player() == (ob = this_object())) return;
    if((sscanf(str, "%shosseldorf%s", a, b) == 2) || (sscanf(str, "%sHosseldorf%s", a, b) == 2)) {
        write("%^CYAN%^A Cleric says:%^RESET%^ The Hosseldof child has gotten worse??");
        write("%^CYAN%^A Cleric says:%^RESET%^ We will go there immediately!");
        write("\nYou feel all warm and fuzzy inside from doing such a good deed.");
        if(!this_player()->set_mini_quest("sick child", 200, "You told the hospital about the sick boy.\n"))
        return;
    }
}

int is_invincible() { return 1; }
