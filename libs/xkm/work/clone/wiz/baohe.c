// baohe.c 月光宝盒
// by April 01/08/14
// update April 01/08/16

#include "ansi.h"

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_copy", "copy");
        add_action("do_exp", "exp");
}

void create()
{
        set_name(HIW "月光宝盒" NOR, ({ "moon box", "he", "box"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "凭此宝盒复制(copy)武功，设定经验(exp)。\n");
                set("material", "steel");
        }
}

int do_copy(string arg)
{
	mapping skill_status;
	string *sname;
	int i, count,point;
	object me = this_player();
	object where = environment(me);
	object target;

	if(!arg || !objectp(target = present(arg, environment(me))))
		return notify_fail("你要复制谁的武功？\n");

	me->set("max_jing", (int)target->query("max_jing"));
	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	
	me->set("eff_jingli", (int)target->query("max_jingli"));
	me->set("max_jingli", (int)me->query("eff_jingli"));
	me->set("jingli", (int)me->query("max_jingli"));
	
	me->set("max_qi", (int)target->query("max_qi"));
	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("qi", (int)me->query("max_qi"));

	me->set("max_neili", (int)target->query("max_neili"));
	me->set("neili", (int)me->query("max_neili"));

	me->set("combat_exp",target->query("combat_exp"));

	if ( mapp(skill_status = target->query_skills()) ) {
		skill_status = target->query_skills();
		sname = keys(skill_status);
		count = sizeof(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			point = target->query_skill(sname[i],1);
			me->set_skill(sname[i],point);
		}
	}

	message_vision("\n$N对著$n大喊，月亮显威力......，说着说着$N发现月亮没啥反映，就抱着$n的小脑袋大嚼起来!\n" 
		+"不一会，$N的身体参照$n的小脑袋有了些变化。\n",me,target);
	
	return 1;
}

int do_exp(string arg)
{
	object me = this_player();
	int myexp, mylvl ;
	mapping skill_status;
	string *sname;
	int i, count,point;

	if(!arg) return notify_fail("你要多少经验？\n");

	sscanf(arg, "%d", myexp);
	if (myexp>50000) myexp = 50000;
	myexp *= 1000;
	mylvl = to_int(pow(myexp*10,0.33333)+1);

	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname = keys(skill_status);
		count = sizeof(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			me->set_skill(sname[i],mylvl);
		}
	}

	me->set("combat_exp",myexp);

	message_vision("\n$N大喊，月亮显威力......，说着说着$N发现月亮没啥反映，就抱着自己的大脚丫啃了起来!\n" 
		+"不一会，$N的脚趾头都一般长短了。\n",me);

	return 1;
}