#include <discastle.h>
inherit MONSTER;
object all;
int i;
int moo;
void create() 
{
        ::create();
        moo = 0;
        set_name("merchant");
        set("short", "A sleeping merchant");
        set("long", "The merchant is blissfully sleeping, not a care in the world... he looks rich");
        set("id", 
                ({"monster","merchant","Merchant"})
        );
        set("race", "human");
        set_body_type("human");
        set_gender("male");
        set_class("fighter");
        set_subclass("warrior");
        set_spell_chance(40);
        set_spells( ({"rush"}) );
        new(ARM"goldhelm")->move(this_object());
        new(ARM"goldnecklace")->move(this_object());
        new(ARM"goldring")->move(this_object());
        new(WEAP"golddag")->move(this_object());
        add_money("gold", 100);
        set_skill("attack", 300);
       	this_object()->force_me("wear all");
       	this_object()->force_me("wield dagger");
        set_level(30);
}         


int is_invincible() 
{
    set_sp(query_max_sp());
   	set_short("An angry merchant");
	set_long("The merchant is awake now. And looks upset!");
    if (random(10) == 3)
    {
        this_object()->force_me("yell Help guards! I am being attacked by "+ previous_object()->query_cap_name());
    }
    else
    {
    	this_object()->force_me("say Help guards! I am being attacked by "+ previous_object()->query_cap_name());
    }
    if(!present("guard", environment(this_object()))) {
   		new(MOB"mercguardforflw")->move(environment(this_object()));
		new(MOB"mercguardforflw")->move(environment(this_object()));
		new(MOB"mercguardforflw")->move(environment(this_object()));	
		new(MOB"mercguardforflw")->move(environment(this_object()));
		new(MOB"mercguardforflw")->move(environment(this_object()));
		new(MOB"mercguardforflw")->move(environment(this_object()));
    }
 	   return 0;
}
