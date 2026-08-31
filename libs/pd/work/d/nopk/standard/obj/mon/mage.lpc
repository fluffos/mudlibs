#include <std.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("Mage");
   set_id( ({ "mage", "trainer" }) );
   set_short("The mage trainer");
   set("aggressive", 0);
  set_level(50);
    set_long("He trains the mages.\n");
    set_body_type("human");
   set_alignment(200);
   set("race", "human");
    set_hp(10000);
    set_mp(10000);
}

void check_illusion(string *what)
{
  object tp, ob;
 string who, that;

 who = what[0];
 that = what[1];
 tp = present(who, environment(this_object()));
 ob = present("scroll_of_illusionists");
 if (!ob || !tp) return;
 if (tp->query_class()!= "mage")
    {
     write("bleh cheater");
     return;
    }
 if (tp->query_subclass()=="illusionist")
   {
    message("info", "My son, you already are an Illusionist.", tp);
    return;
   }
 this_object()->force_me("emote reads over the scroll.");
 this_object()->force_me("say I see you met Soltan, the leader of the Illusionists.");
 this_object()->force_me("say There is one more step in becoming a Illusionist");
 this_object()->force_me("say but your in luck ill skip you");
 tp->set_subclass("illusionist");
 message("info", "You feel stronger as you become an Illusionist", tp);
 shout("%^BOLD%^%^BLUE%^All hail "+(string)tp->query_cap_name()+" the new Illusionist!");
}

void catch_tell(string str)
{
 object ob;
 string a, b, c;

 if(this_player() == (ob = this_object())) return;
 if(sscanf(str, "%s gives you %s", a, b) == 2)
   call_out("check_illusion", 2, ({ lower_case(a), lower_case(b) }) );
}



