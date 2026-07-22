//by mudgod@xssx
#include <ansi.h>
inherit BHNPC;
void create()
{
        set_name("皇皇教舵主", ({ "duo zhu", "duo" }) );
        set("long",
"一个皇皇教的舵主，看上去身经百战。\n");
        set("max_qi",1000);
        set("max_jing",500);
        set("attitude", "aggressive");
        set("vendetta/authority",1);
        set("per", random(10));
        set("combat_exp", 300000+random(500000));
        set("chat_chance", 10);
        set("chat_msg", ({
                "皇皇舵主喊道：杀啊，杀一个赚一个!\n",
        }) );
        set_skill("unarmed", 100+random(50));
        set_skill("blade", 100+random(50));
        set_skill("parry", 100+random(50));
        set_skill("dodge", 100+random(50));
        set_skill("wuhu-duanmendao", 100+random(50));
        map_skill("blade","wuhu-duanmendao");
        map_skill("parry","wuhu-duanmendao");

        setup();

        carry_object("/clone/weapon/gangdao")->wield();
}
void init()
{
        remove_call_out("hunting");
	if(!environment()->query("no_fight"))
        call_out("hunting",1);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
		if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}
void die()
{
	object killer;
	object *inv,*pro_team;
	int values;
	int i;
	message_vision(GRN"$N大叫一声倒在地上，挣扎了几下，"HIR"死了"NOR"！\n"NOR,this_object(),this_player());
	values=0;
	killer=query_temp("last_damage_from");
	if (killer)
	{
             killer->add_temp("marks/杀舵",1);
	}
	destruct(this_object());
}

