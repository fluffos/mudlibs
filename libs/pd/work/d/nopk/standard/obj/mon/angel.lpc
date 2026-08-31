#include <std.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("archangel");
   set_id(({ "angel", "powerful archangel", "archangel", "powerful angel" }));
   set_short("a Powerful Archangel");
   set_long("This arch angel is cool.");
   set_alignment(2000);
   set_class("cleric");
   set_stats("charisma", 99);
   set_skill("faith", 9999);
   set_skill("healing", 9999);
   
   set_level(200);
   set_gender("female");
   set_race("archangel");
   set_body_type("human");
}
int i;
void init()
{
 ::init();
 set_heart_beat(1);
 if (!i)
 {
 this_object()->force_me("peace");
 this_object()->force_me("kill death");
 i = 1;
 }
}

void heart_beat()
{
 ::heart_beat();
 if (!query_current_attacker())
   {
    this_object()->force_me("say I have saved you once, now your on your own.");
    this_object()->force_me("emote bows and departs.");
    this_object()->force_me("emote flys away.");
    this_object()->remove();
   }
} 
