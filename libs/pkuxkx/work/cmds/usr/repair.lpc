//repair zine@pkxuxk 2014/7/21 维修武器
#include <ansi.h>
inherit F_DBASE;
int repair(object me,object ob,object *inv,int cost)
{
	for (int i=0;i<sizeof(inv);i++)
	{
		if (cost>0)
		{
			if (cost>inv[i]->query_temp("repair_ability"))
			{
				cost-=inv[i]->query_temp("repair_ability");
				destruct(inv[i]);
			}
			else
			{
				cost=0;
				if (cost>inv[i]->query_temp("repair_ability")/2)
				destruct(inv[i]);
				else
				inv[i]->init_material(inv[i]->query("level")-2,member_array(query("type"),({"short","medium","long","entire"})));
			}
		}
	}
	tell_object(me,"完成这项工作，你也消耗了大量材料。\n");
	return 1;
}
int fixing(object me,object ob,object *inv)
{
	int repair_ability,cost=0;		        	        	
	for (int i=0;i<sizeof(inv);i++)
	{
		if (inv[i]->query("level")==ob->query("level"))
		{
			inv[i]->set_temp("repair_ability",2);
			repair_ability+=2;
		}
		else
		{
			inv[i]->set_temp("repair_ability",4*(inv[i]->query("level")-ob->query("level")));
			repair_ability+=4*(inv[i]->query("level")-ob->query("level"));//高级材料效果上升
		}
	}
	if (wizardp(me)) write("repairAbility:"+repair_ability+"\n");
	if(ob->query("max_rigidity") < ob->query("rigidity"))
	ob->set("max_rigidity", ob->query("rigidity"));	
	else if(ob->query("rigidity") == ob->query("max_rigidity"))
    {
		if (ob->query("max_rigidity")>340+query("level")*20)
		{
			tell_object(me,ob->name()+"的耐久度已经达到最高，无法再提升了。\n");
			return 1;
		}
		else if (repair_ability<50)
		{
			tell_object(me,"你身上的材料不足以提升"+ob->name()+"的永久耐久度。\n");
			return 1;
		}
		else
		{
			ob->add("max_rigidity",5);
			message_vision(MAG+"片刻之后$N"+MAG+"的状态更胜往昔，$n"+MAG+"拿在手中，把玩不止。\n"+NOR,ob,me);
			return repair(me,ob,inv,50);
		}
	}
	else
	{
		if(ob->query("forge/material1_level"))
		{
			cost += 1 * ob->query("forge/material1_level");
		}
		if(ob->query("forge/material2_level"))
		{
			cost += 1 * ob->query("forge/material2_level");
		}
		if(ob->query("forge/material3_level"))
		{
			cost += 1 * ob->query("forge/material3_level");
		}	
		if(ob->query("forge/material4_level"))
		{
			cost += 1 * ob->query("forge/material4_level");
		}				
		
		if(cost < 1) cost = 1;
		if (repair_ability<cost)
		{
			tell_object(me,"你身上的材料不足以修复"+ob->name()+"。\n");
			return 1;
		}
		ob->set("rigidity",ob->query("max_rigidity"));
		message_vision(MAG+"片刻之后$N"+MAG+"恢复了过去的状态，$n"+MAG+"暗叹自己手段的高超。\n"+NOR,ob,me);
		if (wizardp(me)) write("cost:"+cost+"\n");
		return repair(me,ob,inv,cost);
    }
}
int main(object me, string arg)
{
	object ob,tool,*inv,*materials=({});
	int lv,rigidity,sk_lv=1+me->query_skill("components",1)/10,allow=0;
	if (!me->query_skill("components",1))//need a book
	return notify_fail("你完全没有装备结构方面的知识，还是找别人来修吧。\n");
	if (me->is_busy())
	return notify_fail("你正忙着呢。\n");
	if (!arg)
	return notify_fail("你要维修什么装备？\n");
	if (!ob=present(arg,me))
	return notify_fail("你身上没有"+arg+"这样装备。\n");
	if ((!ob->is_gems()||!ob->query("weapon_prop")))
	return notify_fail(ob->name()+"不是随机武器或玩家打造武器，不能维修。\n");
	if(ob->query("gem_ob_autoloaded"))
	return notify_fail(ob->name()+"已经被自动加载，只有取消自动加载才能维修。\n");
	if (ob->query("equipped"))
	return notify_fail(ob->name()+"只有被放下了以后，你才可以维修。\n");
	if(ob->query("rigidity") == ob->query("max_rigidity")&&me->query_skill("components",1)<120)
    return notify_fail(ob->name()+"没有任何损坏，要提升耐久度上限，你需要至少一百二十级的装备构造知识。\n");
	lv=ob->query("level");
	rigidity=ob->query("max_rigidity");
	if (rigidity<1)
	return notify_fail(ob->name()+"已经彻底损坏，无法维修了！\n");
	if (me->query_temp("weapon")&&objectp(tool=me->query_temp("weapon"))&&tool->is_SmithHammer()) allow=1;
	else if (me->query_temp("secondary_weapon")&&objectp(tool=me->query_temp("secondary_weapon"))&&tool->is_SmithHammer()) allow=1;
	if (!allow)
	return notify_fail(RED"你要修复武器，总要找个铁锤来吧？\n"NOR);
	if (lv+2>sk_lv)
	{
		message_vision("$N对着$n完全无从下手。\n",me,ob);
		return notify_fail(ob->name()+"的复杂程度超出了你的能力。\n");
	}
	inv=all_inventory(me);
	for (int i=0;i<sizeof(inv);i++)
	{
		if (inv[i]->query("is_castmaterial")&&inv[i]->query("level")>=ob->query("level"))
		materials+=({inv[i]});
	}
	if (sizeof(materials)<1)
	return notify_fail("你身上没有和"+ob->name()+"同级或更高级的材料，无法修复。\n");
	message_vision(HIM"$N"+HIM+"开始尝试动手修复$n"+HIM+"。\n"NOR,me,ob);
	me->add_busy(3);
	fixing(me,ob,materials);
	return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : repair <装备>
修复某随机装备或玩家打造装备。
装备结构120级以上可增加耐久度上限。
此项工作需消耗同级别或更高级别的材料。
HELP
);
        return 1;
}

