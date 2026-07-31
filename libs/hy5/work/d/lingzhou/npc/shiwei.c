//Cracked by Kafei

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("侍卫", ({ "shi wei", "wei", "guard" }) );
	set("gender", "男性");
	set("age", 35);
	set("long",
		"这是西夏黄帝的贴身侍卫，他太阳穴高高鼓起，武功不低。\n");
	set("combat_exp", 500000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("str", 26);
	set("con", 22);
	set("int", 20);
	set("dex", 24);

	set("max_qi", 12000);
	set("eff_qi", 12000);
	set("qi", 12000);
	set("max_jing", 8000);
	set("jing", 8000);
	set("neili", 20000);
	set("max_neili", 20000);
	set("jiali", 60);

	set_temp("apply/attack",  100);
	set_temp("apply/defense", 100);

 set("combat_exp", 1400000+random(2000000));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.leitingpili" :),
                (: perform_action, "sword.kuang" :),
                (: random_move :),
        }) );
        set("chat_chance", 60);
        set("chat_msg", ({
                (: random_move :),
        }) );

        set_skill("unarmed", 180+random(180));
        set_skill("sword", 180+random(180));
        set_skill("parry", 180+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-jian", 280+random(380));
        
        map_skill("sword", "kuang-jian");
        map_skill("parry", "kuang-jian");
        set_temp("apply/attack", 120);
        set_temp("apply/defense",150);
        set_temp("apply/armor", 350);
        set_temp("apply/damage", 320);
	
	set("no_get", "侍卫对你而言太重了");

	setup();

        carry_object("/d/city/obj/gangjian")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}


void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        call_out("hunting",1);
        }
	if(!environment()->query("no_fight") && random(100) < 1)
        call_out("hunting",1);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if( userp(ob[i]) && ob[i]->query("combat_exp") < 80000) continue;
        if(ob[i]->query("vendetta/authority")) continue;
        if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}