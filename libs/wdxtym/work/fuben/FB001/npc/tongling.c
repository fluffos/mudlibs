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
	set_name(HIM"元兵统领"NOR,({"tongling"}));
	set("gender", "男性");
	set("per",20);
	set("age", 30);
	set("combat_exp", 1000000+random(3000000));
	set("str", 50);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_neili", lvl*4);
	set("neili", lvl*4);
	set("eff_qi", lvl*3);
	set("max_qi", lvl);
	set("qi", lvl*3);
	set("max_jing", lvl*3);
	set("jing", lvl*3);
	set("max_jingli", lvl*3);
    set("eff_jingli", lvl*3);
 	set("jingli", lvl*3);
 	set("jiali", 200); 	
 	set_temp("apply/attack", 300);
	set_temp("apply/armor", 350);
	set_temp("apply/damage", 150); 	
		
	set_skill("unarmed", sklv);
	set_skill("force", sklv);
	set_skill("club", sklv);
	set_skill("zhongping-qiang", sklv);
	set_skill("dodge", sklv);
	set_skill("parry", sklv);
	map_skill("club", "zhongping-qiang");
	
	setup();
	carry_object("/d/city/npc/obj/tiejia")->wear();
	carry_object("/clone/weapon/changqiang")->wield();
}

void die()
{
	object killer,ob;
	int exp;
	int num;
	if (objectp(killer = query_last_damage_from()))
	{
	    num=10+random(killer->query("kar"));	
		killer->add("combat_exp",15000);
		killer->add("potential",15000);
	    killer->add("jifeng",25);		
		tell_object(killer,"你杀死"+name()+"，获得15000点修为，15000点潜能，25张点券。\n");
		if(killer->query("zhanling/s3") < 10)
		{
		killer->add("zhanling/a3",25);
		killer->add("zhanling/s3",25);
		tell_object(killer,"你杀死"+name()+"，获得25战令修为。\n");
		}
	}
	::die();
}
void unconcious()
{
	die();
}