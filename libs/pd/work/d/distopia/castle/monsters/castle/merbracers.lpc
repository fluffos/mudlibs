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
        set("long", "The merchant is blissfully sleeping, not a care in the world.");
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
        new(ARM"goldbracerl")->move(this_object());
        new(ARM"goldbracerr")->move(this_object());
        new(ARM"goldnecklace")->move(this_object());
        add_money("gold", 80);     
        set_skill("attack", 300);
       	this_object()->force_me("wear all");
        set_level(20);
}         
void scream(object ob) 
{
 	if (moo == 0) 
 	{
		write("Ut oh... the merchant heard you and woke up!\n"); 	
		if (random(10) == 3)
		{
			this_object()->force_me("yell "+ob->query_cap_name() + " is in my room! GUARDS!");
		}
		else
		{
			this_object()->force_me("say "+ob->query_cap_name() + " is in my room! GUARDS!");
		}
		new(MOB"mercguardforflw")->move(environment(this_object()));
		new(MOB"mercguardforflw")->move(environment(this_object()));
		new(MOB"mercguardforflw")->move(environment(this_object()));
		set_short("An angry merchant");
		set_long("The merchant is awake now. And looks upset!");
		this_object()->force_me("kill " + ob->query_name());
		moo = 1;
	}
}

void init() {
   object *all;
   int i;
   ::init();
   all = all_inventory(environment(this_object()));
   i = sizeof(all);
   while (i--) {
     if (!all[i]->is_player()) continue;
     if (all[i]->is_player())
        call_out("scream", 3, all[i]);
   return;
   }
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
    }
    return 0;
}
