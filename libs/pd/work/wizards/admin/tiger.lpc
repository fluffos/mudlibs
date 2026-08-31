#include <std.h>
inherit MONSTER;

private object owner;

void create() {
   ::create();
   set_name( "tiger" );
   set_id( ({ "tiger" }) );
   set_short("A huge white tiger");
   set("aggressive", 0);
   set_level(50);
   set_long("This tiger is a rare white tiger. I wouldnt mess "
              "with it if i were you");
   set_body_type("human");
   set_alignment(100);
   set("race", "human");
   set_mp(1200);
   set_class("mage");
   set_spell_chance(90);
   set_stats("wisdom", 80);
   set_skill("magic attack", 300);
   set_skill("attack", 300);
   set_skill("melee", 300); 
   set_spells( ({ "missile", "shock", "fireball" }) );
   set_heart_beat(1);
}
void init()
{
 ::init();
 
 add_action("cmdPet", "pet");
 add_action("cmdKill", "kill");
}
int cmdKill(string str)
{
 if (!str || str=="") return 0;
 if (owner!=this_player()) return 0;
 
// this_object()->force_me("kill "+str);
 return 0;
}

int cmdPet(string str)
{
 if (!str || str=="") return 0;
 if (str!="tiger") return 0;
 if (owner) 
 if (owner!=this_player())
   {
    message("info", "The tiger bares his teeth at you. You think its wise not to touch him.", this_player());
    message("info", "The tiger bares his teeth at "+(string)this_player()->query_cap_name() + ".\n", environment(this_player()), this_player());
    return 1;
   } 
 if (owner==this_player()) {
   message("info", "You pet your tiger.\n", this_player());
   message("info", (string)this_player()->query_cap_name() + " pets his tiger.\n", environment(this_player()), this_player());
   return 1;
  }
 message("info", "You pet the white tiger and become good friends.", this_player());
 message("info", (string)this_player()->query_cap_name() + " pets the tiger.\n", environment(this_player()), this_player());
 owner = this_player();
 return 1;
}

void heart_beat()
{
 ::heart_beat();
 if (!owner) return;
   
 if ( environment( this_object() ) != environment( owner ) )
   {
    message("info", "%^GREEN%^%^BOLD%^The tiger leaves to follow its master\n", environment(this_object()));
this_object()->move(environment(owner));
    message("info", "%^GREEN%^%^BOLD%^A tiger enters.\n",environment(owner));
   }

}

