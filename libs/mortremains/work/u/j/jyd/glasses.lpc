#include <mudlib.h>
#include <config.h>

inherit ARMOR;

void create() {
  set_armor_type("amulet");
  set("short", "a pair of cool sunglasses");
  set("long", @End
A pair of expensive looking sunglasses. You can't tell if he is looking at you or not.
End
    );
   set("id", ({ "glasses", "#REFLEXIVE_SPELL#"}) );
   set("value", 0);
}

int fbark() {
  object ob = environment(this_object());
  write("You bark happily.");
  say ("Jyd barks hapilly.\n");
  return 1;
}


int init () {
  add_action("fbark","bark",1);
}


