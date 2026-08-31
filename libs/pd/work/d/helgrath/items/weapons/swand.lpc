#include <std.h>
inherit WEAPON;
create(){
    ::create();
    set_name("wand");
    set_id(({"wand","learners wand","learner's wand"}));
    set_short("Learner's Wand");
    set_long(
      "This wand seems to have an aura of energy embued into it that you could use."
    );
    set_curr_value("gold",5+random(10));
    set_weight(5);
    set_wc(3);
    set_type("blunt");
    set_property("magic item", ({"use"}) );
}
void init() {
    ::init();
    add_action("use", "use");
}

int use(string str) {
    if(!str)
      return 0;
    if(str != "wand")
      return 0;
    if(this_player() != this_object()->query_wielded())
      return 0;

    if(this_player()->query_casting())
      return notify_fail("You are already involved in a spell!\n");
    if(!this_player()->query_current_attacker())
      return notify_fail("You cannot use the wand like that!\n");
    write("%^BOLD%^You point the wand at your enemy and electricity arcs off of it!");
    say("%^BOLD%^"+this_player()->query_cap_name()+" points "+possessive(this_player())+" wand at "+
        this_player()->query_current_attacker()->query_cap_name()+" and electricity arcs towards "+
        objective(this_player()->query_current_attacker())+"!", this_player()->query_current_attacker());
    message("info", this_player()->query_cap_name()+" points "+possessive(this_player())+" wand at "+
        "you and electricity arcs towards you!", this_player()->query_current_attacker());
    this_player()->set_casting(random(this_player()->query_level())*3);
    return 1;
}
int query_auto_load() { 
  if(this_player()->query_level() > 10) return 1;
  return 0; }
