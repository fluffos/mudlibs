#include <discastle.h>
inherit MONSTER;
object all;
int i;
void create() 
{
        ::create();
        set_name("guard");
        set("short", "merchant guard");
        set("long", "This giant was hired to protect the merchant");
        set("id", 
                ({"monster","guard"})
        );
        set("race", "giant");
        set_body_type("human");
        set_gender("male");
        set_class("fighter");
        set_subclass("warrior");
        set_spell_chance(40);
        set_spells( ({"slash"}) );
        new(WEAP"giantsword")->move(this_object());
        set("aggressive", 500);
        add_money("gold", 50);     
        set_skill("blade", 300);
        this_object()->force_me("wield sword");
        set_level(25);
}                                            

