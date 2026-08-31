#include <std.h>
inherit MONSTER;
void create(){
   ::create();
   set_name("pumpkinhead");
   set_short("%^RESET%^%^ORANGE%^Pumpkinhead%^RESET%^");
   set_long("A dark scarecrow without a head. It seems to be shambling along looking for something.");
   set_moving(1);
   set_speed(3);
   set_level(100);
   set_race("scarecrow");
   set_body_type("human");
   set_class("clergy");
   set_subclass("monk");
   set_stats("strength",999);
   set_stats("dexterity",999);
   set_stats("constitution",999);
   set_stats("wisdom",999);
   set_stats("intelligence",999);
   set_stats("charisma",999);
   set_skill("defense",999);
   set_skill("magic defense",999);
   set_skill("stealing",999); 
   set_max_hp(999999);
   set_hp(query_max_hp());
   set_sp(query_max_sp());
   set_id(({"pumpkinhead"}));
   set_property("no steal", 1);
  set_emotes(3,({
   "The goblin searches around.\n",
   "The goblin looks around on the ground.\n",
}),0);
set_achats(3, ({ 
   "Pumpkinhead flails around wildly.\n",
   "Pumpkinhead shuffles slowly as if searching for something.\n",
   "Pumpkinhead stumbles around.\n",
}) );
 
}
void catch_tell(string str) {
    object ob;
    string a, b;
    if(this_player() == (ob = this_object())) return;
    if(sscanf(str, "%s gives you %s", a, b) == 2) {
        if(present("jack-o-lantern", ob)) {
          ob->force_me("emote puts his head on.");
          present("jack-o-lantern", ob)->remove();
          call_out("finish_quest", 3, this_player());
        }
    }
}
void finish_quest(object tp) {
    this_object()->force_me("emote sighs loudly and grins his Jack-O-Lantern smile.");
    this_object()->force_me("whisper "+tp->query_name()+" Thank you..  I can now return to my realm.");
    if(tp->set_manual_quest("Halloween Quest 2002")) {
      tp->set_stats("strength", tp->query_stats("strength") + 1);
      tp->set_stats("wisdom", tp->query_stats("wisdom") + 1);
      tp->set_stats("constitution", tp->query_stats("constitution") + 1);
      tp->set_stats("intelligence", tp->query_stats("intelligence") + 1);
      tp->set_stats("dexterity", tp->query_stats("dexterity") + 1);
      tp->set_stats("charisma", tp->query_stats("charisma") + 1);
      tp->add_exp(5000000);
      message("info", "You feel different somehow.", tp);
    }
    this_object()->force_me("emote waves it's hands in the air recalling all it's minions.");
    this_object()->force_me("emote vanishes in a flash of light!");
    this_object()->force_me("tell stormbringer hey "+tp->query_cap_name()+" returned me lantern!");    
    this_object()->remove();
}
