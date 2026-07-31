// snowman.
// yuj.

#include <ansi.h>
inherit F_CLEAN_UP;

void do_recover(object ob, int j)
{
	int i;
	mapping skills, learned;
	string *sk;

	if (j < 1 || j > 5) return;
	while(j--) {
		skills = ob->query_skills();
		if (mapp(skills)) {
			sk = keys(skills);
			ob->improve_skill(sk[0], 1, 1);
			learned = ob->query_learned();
			learned[sk[0]]--;
			foreach (string skill in sk) {
				if(SKILL_D(skill)->type2()=="worker") continue;
				i = (skills[skill]+1)*(skills[skill]+1);
				if ((learned[skill]+=i/2) > i) {
					skills[skill]++;
					learned[skill] -= i;
				}
			}
		}
/*
		i = ob->query("death_lost_exp");
		ob->add("combat_exp", i);
		ob->add("shen", ob->query("shen")/9);
		i = ob->query("potential");
		i += i/3;
		i = ob->query("death_count") - 1;
		if (i < 0) i = 0;
		ob->set("death_count", i);
		if (i < ob->query("death_times")) ob->set("death_times", i);
*/
	}
	//ob->reincarnate();
}

int main(object me, string arg)
{
	int i, j = 1;
	string obj;
	object ob;
	mapping note;
	
	if (! SECURITY_D->valid_grant(me, "(admin)"))
		return 0;

	if( !arg )
		return notify_fail("recover <某人> [次数]。\n");

	if( sscanf(arg, "%s %d", obj, i)==2 ) j = i;
	else obj = arg;

	ob = find_player(obj);
	if( !ob )  ob = find_living(obj);
	if( !ob )  ob = present(obj, environment(me));
	if( !ob ) return notify_fail("找不到这个生物。\n");

	if( !userp(ob) )
		return notify_fail("对方只是个NPC，不用这么小题大作吧？\n");

	if( (wiz_level(me) < wiz_level("(wizard)")) && me!=ob )
		return notify_fail("你没有恢复" + ob->name() + "死亡损失的权利。\n");

	message_vision(HIR "\n$N祭起"+chinese_number(j)+"道"BLU"鬼火"HIR"，将$n笼罩在其中，把$p又送入轮回！！\n"NOR"\n",me,ob);

	tell_object(ob, HIW"你感到神情恍忽，宛若又遍历六道之界，恢复了不少损失！"NOR"\n");
	
		
	log_file("static/RECOVER",
			sprintf("%s(%s) recovered %s(%s) %d times\n", me->name(1),
				me->query("id"), ob->name(1), ob->query("id"), j), me, ({ ob->query("id") })
		);
	do_recover(ob, j);
	ob->set("combat/last_die", "已由巫师恢复");
	//ob->delete("last_killer_id");
	//ob->delete("last_death_time");
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : recover <某人> [次数]

此命令将可恢复死亡损失，谨用！

HELP
    );
    return 1;
}
