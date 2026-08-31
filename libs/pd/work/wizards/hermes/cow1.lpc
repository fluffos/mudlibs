#include <std.h>
inherit MONSTER;
void create() {
 ::create();
   set_name("cow");
   set_id(({ "cow" }));
   set_short("A mad cow");
   set_level(400);
set_long("A large white, cute cow with black spots.  On close inspection, a
name tag in the shape of a red heart with the words "
"\"I love Pyro\" written on it.");
   set_body_type("feline");
   set("race", "cow");
   set_gender("male");
}
void heart_beat() {
  if(find_player("pyro")) {
    if(environment(this_object()) != environment(find_player("pyro"))) {
      say(this_object()->query_cap_name()+" mooes towards Pyro.");
      this_object()->move(environment(find_player("pyro")));
      say(this_object()->query_cap_name()+" walks in, lazily, mooing and
nuzzling Pyro.");
}
    if(random(100) < 3)
this_object()->force_me("moo");
if(random(100) == 2)
this_object()->force_me("nuzzle pyro");
if (random(100) == 40)
this_object()->force_me("lick pyro");
  }
  ::heart_beat();
}
int die() { return 1; }
int is_invincible() { return 1; }
int dest() { 
 this_object()->force_me("lick pyro");
this_object()->force_me("shake"); 
return 1;
}
