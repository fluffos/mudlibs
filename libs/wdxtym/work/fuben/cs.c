//by 游侠 ranger's ednpc tools.
// shanzei1.c

#include <ansi.h>
inherit NPC;

string *random_ob = ({
    "/fuben/wuguan/obj/putao",
    "/fuben/wuguan/obj/dan_chongmai1",
    "/fuben/wuguan/obj/tianling",    
});

void create()
{
object ob = this_player();
int lvl = 1;
int sklv = 1;

	set_name(HIY"武馆弟子"NOR,({"wuguan dizi"}));
	set("gender", "男性");
	set("per",20);
	set("age", 30);
	set("combat_exp", 1000000+random(3000000));
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_neili", lvl);
	set("neili", lvl);
	set("eff_qi", lvl);
	set("max_qi", lvl);
	set("qi", lvl);
	set("max_jing", lvl);
	set("jing", lvl);
	set("max_jingli", lvl);
    set("eff_jingli", lvl);
 	set("jingli", lvl);
		
	set_skill("force", sklv);
	set_skill("dodge", sklv);
	set_skill("unarmed", sklv);
	set_skill("parry", sklv);
    set_skill("shaolin-xinfa", sklv);	
    set_skill("shaolin-shenfa", sklv);
    set_skill("changquan", sklv);	    	    	
	
	map_skill("force", "shaolin-xinfa");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "chanquan");
	map_skill("parry", "chanquan");		
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
		killer->add("combat_exp",5000);
		killer->add("potential",5000);
	    killer->add("yuanbao_2",num);		
		tell_object(killer,"你杀死"+name()+"，获得5000点修为，5000点潜能"+num+"灵石票。\n");
	}
	::die();
}
void unconcious()
{
	die();
}

