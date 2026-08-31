#include <std.h>
#include <arlon.h>

inherit OBJECT;

int i;
void create()
{
 set_name("rock");
 set_short("A large rock");
 set_long("The large rock looks rather heavy. The ground seems to slope "
          "under the rock. There is loud squeeking noises coming from "
          "under the rock");
 set_id( ({ "large rock", "rock" }) );
 set_mass(1);
 set_value(0);
}
void init()
{
 ::init();
 add_action("get", "roll");
 add_action("get", "move");
 add_action("get", "push");
 add_action("get", "get");
}
int get(string str) { 
 if (!str) return 0;
 if (str!="rock") return 0;
 if (!i)
  {
   write("You manage to pick up the rock and throw it to the side.");
   say(this_player()->query_cap_name()+" picks up the rock and throws it to the side.");
   message("info","Many small rodents pop up out of the hole and fill the room.", environment(this_player()));
   new(MOB "rat")->move(environment(this_player()));
   new(MOB "rat")->move(environment(this_player()));
   new(MOB "rat")->move(environment(this_player()));
   new(MOB "rat")->move(environment(this_player()));
   new(MOB "rat")->move(environment(this_player()));
   this_object()->remove();
   i = 1;
   return 1;
  }
  return 0;
 }
