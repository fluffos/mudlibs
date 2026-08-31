#include <std.h>
inherit MONSTER;

int quest_done;

void create() {
    ::create();
   set_name("Soltan");
   set_id( ({ "soltan", "magician" }) );
   set_short("Soltan the master illusionist");
   set("aggressive", 0);
    set_long("This small human seems to be up here for many years in "
             "solitary. He is trying to scribe something and is "
             "frusterated for some wierd reason.");

   set_body_type("human");
   set_alignment(200);
   set_race("human");
   set_spell_chance(10);
   set_skill("conjuring", 100);
   set_skill("magic attack", 100);
   set_subclass("illusionist");
   set_level(50);
   set_spells( ({ "spook" }) );
   quest_done=0;
}

void check_quest(string *what)
{
 object tp, ob;
 string who, that;

 if (quest_done) return;
 who = what[0];
 that = what[1];
 tp = present(who, environment(this_object()));
 ob = present("book");

 if (!tp) return;
 if (!ob)
   {
    this_object()->force_me("say That isnt what i am looking for!");
    this_object()->force_me("give "+that+" to "+who);
    return;
   }
 if ( (string)tp->query_class()!="mage" )
   {
    this_object()->force_me("say Thank you for finding my book.");
    this_object()->force_me("say but you dont qualify for my gift");
    quest_done=1;
    return;
   }
 this_object()->force_me("say Thank you!!!!!! where did you find it? ive been looking all over for it!");
 this_object()->force_me("say I've been working on a scroll for a secret mage society, for only people that are worthy. You my son, are.");
 this_object()->force_me("say If you wish to become an Illusionist, take this to your mage leader in Sindarii.");
 new("/d/standard/rain_forest/obj/scroll")->move(this_object());
 this_object()->force_me("give scroll to "+who);
 tp->set_manual_quest("Soltan", 20);
 quest_done=1;
}
void catch_tell(string str)
{
 object ob;
 string a, b, c;

 if(this_player() == (ob = this_object())) return;
 if(sscanf(str, "%s gives you %s", a, b) == 2)
   call_out("check_quest", 2, ({ lower_case(a), lower_case(b) }) ); 
}
void heart_beat()
{
 if (random(500) > 450 && (!quest_done)) 
   {
    switch (random(4)) {
     case 1: 
      this_object()->force_me("say I cant figure out the last part.");
      break;
     case 2: 
      this_object()->force_me("say Where did i put that darn book?");
      break;
     case 3: 
      this_object()->force_me("say Its all i need!");
      break;
     case 4: 
      this_object()->force_me("emote recites the scroll, and nothing happens.");
      break;
     case 0: 
       this_object()->force_me("frown");
       break;
    }
  }
 ::heart_beat();
}
