#include <std.h>
#include <tirun.h>
inherit MONSTER;

void create() {
  ::create();

  set_name("");
  set_short("");
  set_long("You do not notice that here.");
  set_level(1);
  set_id(({"deed"}));
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
    if((sscanf(str, "%sgo%s", a, b) == 2) || (sscanf(str,
"%sGo%s", a, b) == 2)) {
        write("%^BOLD%^%^BLUE%^The dragon says:%^RESET%^ It's safe for me to go to Roston?");
        write("%^BOLD%^%^BLUE%^The dragon says:%^RESET%^ We won't fit through the portal alone, let me go first!!");
        write("\n%^BOLD%^%^BLUE%^The dragon bumps you off his back and goes through the portal.%^RESET%^");
        present("dragon", environment(this_player()))->remove();
        if(!this_player()->set_mini_quest("zoleniadragon", 250000, "You helped rescue the trapped dragon in Zolenia.\n"))
        write("\n%^BOLD%^%^BLUE%^You may wish to enter the portal.%^RESET%^");
        return;
    }
}

int is_invincible() { return 1; }
