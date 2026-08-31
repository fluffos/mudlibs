#include <std.h>
inherit WEAPON;

int remove_sword();

void create() {
   ::create();
   set_name("scimitar");
   set_id(({"scimitar","long scimitar","blade"}));
   set_short("A long, deadly scimitar");
   set_long("This scimitar is a long staff with a sharp curved "
            "deadly blade at the end. along the length of it are "
            "several old runes and this thing looks dangerous.");
   set_wc(5);
   set_curr_value("gold", 58);
   set_hands(2);
   set_mass(20);
   set_type("blade");
   set_wield("You feel power rush up and down your arms.");
   set_unwield((: remove_sword() :));
}
int query_auto_load() { return 1; }

int remove_sword() {
    if((string)query_wielded()->query_race() != "elf") return 1;
    write("A strange power binds the scimitar to you.");
    return 0;
}

int drop() {
    if(!this_object()->query_wielded()) return 0;
    if((string)this_player()->query_race() != "elf") return 0;
    message("info", "The power is too great to leave", this_player());
    message("info", (string)this_player()->query_cap_name()+" tries to drop "+
      this_player()->query_possessive()+" scimitar, but "
      +this_player()->query_objective()+" can't seem to do it!",
      environment(this_player()), ({ this_player() }) );
    return 1;
}

int weapon_hit() {
    int x, y;
    object ob;

    ob = this_player()->query_current_attacker();
    if (!ob) return 0;
    if ((string)ob->query("race") != "elf") return 0;
    y = random(10);
    x = (int)this_player()->query_alignment();
    if(x> 0) x = (x/100);
    else x = 0;
    y += x;
    write("Your elf slayer plunges deep into your oponents flesh!");
    say(this_player()->query_cap_name()+" plunges deep into the elf!\n", this_player());
    return y;
}

