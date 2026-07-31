// sl_cloth.c

#include <ansi.h>

inherit ITEM;

string setcolor();

void create()
{
        set_name(HIW"圣"HIG"舍"HIB"利"HIR"子"NOR, ({"sheli zi", "sheli"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
		set("text" , "这是一颗前代高僧留下的圣舍利子，有"ZJURL("cmds:xu neili")+ZJSIZE(20)+"注入"NOR"(xu neili)和"ZJURL("cmds:xi neili")+ZJSIZE(20)+"汲取"NOR"(xi neili)的功效。"NOR"\n");
		set("long",HIW+query("text") );
                set("value", 8000);
                set("no_put", 1);
                set("no_get", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_sell", 1);
                set("no_steal", 1);
                set("material", "stone");
		set("neili",130000);
        }
        setup();
}

void init()
{
	add_action("do_zhuru","xu");
	add_action("do_xiqu","xi");
}

int do_zhuru(string arg)
{
	int cost,max_neili;
	object me = this_player();
        max_neili=130000;

	if (arg!="neili")
		return notify_fail("你要蓄入什么?\n");

	if( query("neili") >= max_neili )
		return notify_fail(""HIW"圣"HIG"舍"HIB"利"HIR"子"NOR"中已经内力充盈，你无法蓄入更多内力！\n");

	if( me->query_skill("force") < 200 )
		return notify_fail("你的内功等级不够，无法往"HIW"圣"HIG"舍"HIB"利"HIR"子"NOR"中蓄入内力！\n");

	cost = 11000;

	if( cost > me->query("neili") )
		return notify_fail("你的内力不足，无法往"HIW"圣"HIG"舍"HIB"利"HIR"子"NOR"中蓄入足够的内力！\n");

	add("neili",10000);
	if (query("neili") > max_neili) set("neili",max_neili);
	me->add("neili" , -cost);

	//message_vision(HIC"$N"HIC"潜运内功，双手虚按"HIW"圣"HIG"舍"HIB"利"HIR"子"HIC"，将内力蓄入其中。"NOR"\n",me);
      tell_object(me,HIC"你潜运内功，双手虚按"HIW"圣"HIG"舍"HIB"利"HIR"子"HIC"，将内力蓄入其中。"NOR"\n");	
	setcolor();

	return 1;
}

int do_xiqu(string arg)
{

	object me = this_player();

	if (arg!="neili")
		return notify_fail("你要吸取什么?\n");

        if(me->query_temp("dgjj/zongjue"))
		return notify_fail("你目前身中独孤九剑的「总诀式」，无法从"HIW"圣"HIG"舍"HIB"利"HIR"子"NOR"中吸取内力！\n");

	if( query("neili") <10000 )
		return notify_fail(""HIW"圣"HIG"舍"HIB"利"HIR"子"NOR"中储存的内力已经消耗光了！\n");

	if( me->query_skill("force") < 100 )
		return notify_fail("你的内功等级不够，无法从"HIW"圣"HIG"舍"HIB"利"HIR"子"NOR"中吸取内力！\n");

	if (me->query("neili") > me->query("max_neili"))
		return notify_fail("你目前内力充沛，无需从"HIW"圣"HIG"舍"HIB"利"HIR"子"NOR"中吸取内力！\n");

	if (sizeof(filter_array(me->query_enemy(),(: userp :))))
		return notify_fail("正在和玩家对手战斗，不能使用"HIW"圣"HIG"舍"HIB"利"HIR"子"NOR"。\n");

        if(me->query_condition("medicine") > 0 )
                  return notify_fail("你刚刚从"HIW"圣"HIG"舍"HIB"利"HIR"子"NOR"中吸取了内力，需等经脉适应了之后才能再次吸取。\n");

	add("neili",-100);

        me->set("neili",me->query("max_neili")*2);
        if (me->query_condition("fire_poison")) me->clear_condition("fire_poison");
        if (me->query_condition("huagu")) me->clear_condition("huagu");
	  me->set_temp("nopoison", 1);
        me->apply_condition("medicine", 4);

        tell_object(me,HIC"你双手虚按"HIW"圣"HIG"舍"HIB"利"HIR"子"HIC"，从中吸取内力补益自身。"NOR"\n");	

        if( me->is_fighting() )
                me->start_busy(2);

	setcolor();

	return 1;
}


string setcolor()
{
	int lvl;
	string color , s;

	if ( query("neili") != 0 )
		lvl = query("neili") / 10000;
	else
		lvl = 0;
	switch (lvl)  {
		case  0:
		case  1:
		case  2: color = HIW;break;
		case  3:
		case  4: color = HIC;break;
		case  5:
		case  6: color = CYN;break;
		case  7:
		case  8: color = HIB;break;
		case  9:
		case 10: color = BLU;break;
		case 11:
		case 12: color = HIM;break;
		case 13: color = MAG;break;
		default: color = HIW;
	}
	set("name" , HIW"圣"HIG"舍"HIB"利"HIR"子"NOR );
	
	if( lvl > 0 )
		s = HIW"圣"HIG"舍"HIB"利"HIR"子"+color+"之内已经蓄有"+CHINESE_D->chinese_number(lvl)+"道内力！"NOR"\n";
	else
		s = "";
	set("long" , color+query("text")+s);

	return color;
}

int query_autoload() { return 1; }