#include <ansi.h>
inherit ITEM;

int is_container() { return 1; }

int is_comb_ob() { return 1; }

object *apteam = ({});
object *dpteam = ({});
object *fighter = ({});

void create()
{
	set_name("战斗物件", ({ "fight ob"}) );
	set_weight(5000000);
	set_max_encumbrance(800000);
	set("no_get", 1);
	set("unit", "个");
	set("long", "这是一个战斗场景。\n");
	set("no_get", 1);
	set_heart_beat(1);
}

varargs string short(int raw)
{
	return name(raw);
}

object *query_emy(string emy)
{
	if(!emy) return 0;
	if(emy=="ap")
		return apteam;
	else if(emy=="dp")
		return dpteam;
	else
		return 0;
}

void add_apteam(object ob)
{
	apteam += ({ ob });
	fighter += ({ ob });
	ob->set_temp("fight_team","dp");
}

void remove_apteam(object ob)
{
	apteam -= ({ ob });
	fighter -= ({ ob });
	ob->delete_temp("fight_team");
}

void add_dpteam(object ob)
{
	dpteam += ({ ob });
	fighter += ({ ob });
	ob->set_temp("fight_team","ap");
}

void remove_dpteam(object ob)
{
	dpteam -= ({ ob });
	fighter -= ({ ob });
	ob->delete_temp("fight_team");
}

void add_fighter(object ob)
{
	fighter += ({ ob });
}

void remove_fighter(object ob)
{
	fighter -= ({ ob });
}

void heart_beat()
{
	int i,w;
	object *inv,first,ob=this_object();
	if(!sizeof(apteam)||!sizeof(dpteam)||!sizeof(fighter))
	{
		tell_room(ob,HIG"战斗结束！"NOR"\n");
		inv = all_inventory(ob);
		inv->move(environment(ob));
		inv->delete_temp("fight_team");
		destruct(ob);
		return;
	}
	w = ob->query("waiting");
	first = fighter[0];
	ob->set("first",first);
	if((!w||w<5)&&first&&!first->query_temp("pfm_cmd")&&playerp(first)&&living(first))
	{
		tell_object(first,ZJTMPSAY"请发招。。。"+(3-w)+"\n");
		ob->add("waiting",1);
		return;
	}
	else
	{
		fighter -= ({ first });
		if(first&&living(first))
		{
			tell_room(ob,"一一一一一一一一一一一一一一一一一一一一一一\n");
			if(!first->query_temp("pfm_cmd"))
				first->attack();
			first->delete_temp("pfm_cmd");
			ob->delete("waiting");
			ob->delete("first");
		}
	}
	fighter += ({ first });
	for(i=0;i<sizeof(apteam);i++)
	{
		if(!apteam[i]||!environment(apteam[i])||environment(apteam[i])!=ob)
		{
			remove_apteam(apteam[i]);
		}
	}
	for(i=0;i<sizeof(dpteam);i++)
	{
		if(!dpteam[i]||!environment(dpteam[i])||environment(dpteam[i])!=ob)
		{
			remove_dpteam(dpteam[i]);
		}
	}
}
