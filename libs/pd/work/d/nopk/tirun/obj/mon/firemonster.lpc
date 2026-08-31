#include <std.h>
#include <daemons.h>
inherit MONSTER;
int test_heart;
void create()
{
 ::create();
 set_name("rejik the peddler");
 set_level(20);
 set_short("Rejik the peddler");
 set_long("A stout middle aged man selling gifts. Say list items to have Rejik
"
          "tell you what he has and how much it costs.");
 set_race("human");
 set_body_type("human");
 set_gender("male");
 set_id( ({ "rejik", "peddler", "peddlar" }) );
 set_heart_beat(1);
 set_patrol(12, ({ "west", "south", "south", "east", "east", "north", "north",
"west", }) );
 set_emotes(3,({
   "%^RESET%^%^CYAN%^Rejik exclaims:%^RESET%^ Newly made fireworks for sale!",
}),0);
 add_money("copper", random(1000));
}
void init()
{
 ::init();
 add_action("fBuy", "buy");
}
int fBuy(string str)
{
 if (!str)
   {  
    this_object()->force_me("say Buy what?");
    return 1;
   }
 if (str!="fireworks" && str!="firework") 
   {
    this_object()->force_me("say I dont have that for sale.");
    return 1;
   }
 switch(str)
 {
  case "firework": 
  if (this_player()->query_money("gold") < 52)
   { this_object()->force_me("say You do not have enough gold for this.");
     return 1;
   }
  this_player()->add_money("gold", -52);
  write("Rendor hands you a firecracker.");
  say("Rendor hands "+this_player()->query_cap_name()+" a firecracker");
  new("/wizards/wraith/firework")->move(this_player());
  return 1;
  break;
  case "fireworks": 
  if (this_player()->query_money("gold") < 52)
   { this_object()->force_me("say You do not have enough gold for this.");
     return 1;
   }
  this_player()->add_money("gold", -52);
  write("Rendor hands you a firecracker");
  say("Rendor hands "+this_player()->query_cap_name()+" a firecracker");
  new("/wizards/wraith/firework")->move(this_player());
  return 1;
  break;
 }
}
int test_heart() { 
    if(!heart_beat_on) set_heart_beat(heart_beat_on = 1);
 return 1; 
}
void catch_tell(string str) {
    string a, b;
    if(sscanf(str, "%slist items%s", a, b) == 2) {
        this_object()->force_me("say Well, lets see. I have some fireworks for sale.");
        return;
    }
}

