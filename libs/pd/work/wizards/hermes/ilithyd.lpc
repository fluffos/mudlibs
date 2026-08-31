#include <std.h>
#include <hermes.h>
inherit MONSTER;
object all;
int i;
int wielded_sword = 0;
void create() 
{
        ::create();
        set_name("ilithyd");
        set("short", "Ilithyd: The Demon Hunter");
        set("long", "The eyes of the Demon Hunter move across you.  He raises his blades and growls a challenge.");
        set("id", 
                ({"monster","demon hunter","archangel","angel","ilithyd"})
        );
        set("race", "archangel");
        set_body_type("archangel");
        set_gender("male");
		set_class("wanderer");
        set_subclass("swashbuckler");
        set_spell_chance(40);
        set_spells( ({"bladedance", "trip", "disarm"}) );
        new(WEAP"warblade")->move(this_object());
        new(WEAP"warblade")->move(this_object());
        add_money("gold", 500);     
        add_money("platinum", 5);
        set_skill("defense", 250);
        set_skill("double wielding", 250);
        set_skill("euphony", 200);
        
        set_skill("blade", 450);
        set_languages( ({"nibelungen"}) );
        set_speech(5, "annarian", 
                ({"Have you seen him?",
                "Are there demons nearby?",
                "At last, I shall have...revenge."}),
                0);
        this_object()->force_me("wield warblade");
        this_object()->force_me("wield warblade 2");
        set_level(75);
		set_exp(750000);
}                                            

void init()   
{
        
    ::init();
 	all = all_inventory(environment(this_object()));
   	i = sizeof(all);
   	while (i--)
    {
     if (!all[i]->is_player()) continue;
     if (all[i]->is_player() && all[i]->query_race()=="demon")
     {
         demonkill(all[i]);
     }
        }       
}
void demonkill(object ob)
{
this_object()->force_me("kill "+ob->query_name());
}
