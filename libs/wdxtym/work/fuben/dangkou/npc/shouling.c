//by 游侠 ranger's ednpc tools.
// shanzei1.c

#include <ansi.h>
inherit NPC;

string *random_ob = ({
     "/fuben/wuguan/obj/putao",
    "/fuben/wuguan/obj/dan_chongmai1",
    "/fuben/wuguan/obj/book_wuliang",    
});

void create()
{
object ob = this_player();
int lvl = ob->query("qi");
int sklv;
sklv = to_int(pow(to_float(ob->query("combat_exp")*10),0.333333333)+random(15));
if (ob->query("combat_exp")<100000){
sklv = 100;
}
if (lvl > 7000){
lvl = 7000;
}
	set_name(HIR"日本鬼子皇"NOR,({"tianhuang"}));
	set("gender", "男性");
	set("per",20);
	set("age", 30);
	set("combat_exp", 9999999+random(3000000));
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_neili", lvl*3);
	set("neili", lvl*3);
	set("eff_qi", lvl*3);
	set("max_qi", lvl*3);
	set("qi", lvl*3);
	set("max_jing", lvl*3);
	set("jing", lvl*3);
	set("max_jingli", lvl*3);
    set("eff_jingli", lvl*3);
 	set("jingli", lvl*3);
 	set("jiali", 50); 	
		
	set_skill("force", sklv/2);
	set_skill("dodge", sklv/2);
	set_skill("hand", sklv/2);
	set_skill("cuff", sklv/2);	
	set_skill("parry", sklv/2);
    set_skill("longxiang", sklv/2);	
    set_skill("shenkong-xing", sklv/2);
    set_skill("dashou-yin", sklv/2);	
    set_skill("yujiamu-quan", sklv/2);	        	    	
	
	map_skill("force", "longxiang");
	map_skill("dodge", "shenkong-xing");
	map_skill("hand", "dashou-yin");
	map_skill("cuff", "yujiamu-quan");	
	map_skill("parry", "dashou-yin");			

	prepare_skill("hand", "dashou-yin");
	prepare_skill("cuff", "yujiamu-quan");

	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: perform_action, "hand.jingang" :),
		(: perform_action, "cuff.chen" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}));
	setup();
}

void die()
{
	object killer,ob;
	int exp;
	int num;
	if (objectp(killer = query_last_damage_from()))
	{
	    num=10+random(killer->query("kar"));	
		killer->add("combat_exp",20000);
		killer->add("potential",20000);
	    killer->add("jifeng",50);		
		tell_object(killer,"你杀死"+name()+"，获得20000点修为，20000点潜能，点券50张。\n");
		if(killer->query("zhanling/s6") < 10)
		{
		killer->add("zhanling/a6",5);
		killer->add("zhanling/s6",5);
		tell_object(killer,"你杀死"+name()+"，获得5战令修为。\n");
		}
	}
	::die();
}
void unconcious()
{
	die();
}