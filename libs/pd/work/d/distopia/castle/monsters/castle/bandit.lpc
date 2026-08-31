#include <std.h>
#include <discastle.h>
inherit MONSTER;
object all;
int i;
int wielded_sword = 0;
void create() 
{
        ::create();
        set_name("bandit");
        set("short", "A Bandit");
        set("long", "The Bandit looks at you and grins, his knife sliding out of his sheath");
        set("id", 
                ({"monster","bandit","Bandit","a bandit","A bandit", "A Bandit"})
        );
        set("race", "human");
        set_body_type("human");
        set_gender("male");
        set_class("rogue");
        set_subclass("thief");
        set_spell_chance(40);
        set_spells( ({"stab"}) );
        new(WEAP"poisondagger")->move(this_object());
        new(WEAP"poisondagger")->move(this_object());
        set("aggressive", 500);
        new(ARM"leatherbelt")->move(this_object());
        new(ARM"studdedgloves")->move(this_object());
        new(ARM"studdedarmor")->move(this_object());
       	new(ARM"tinhelmet")->move(this_object());
        add_money("gold", 50);     

        set_skill("knife", 300);
       
        this_object()->force_me("wield dagger");
        this_object()->force_me("wield dagger 2");
        this_object()->force_me("wear all");
        set_level(20);
}                                            

