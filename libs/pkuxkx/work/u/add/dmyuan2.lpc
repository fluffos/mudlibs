// Room: /d/shaolin/dmyuan2.c
// Date: YZC 96/01/19

inherit ROOM;
#include <ansi.h>

void init();
int do_lin(string arg);
void create()
{
	set("short", "达摩院二楼");
	set("long", @LONG
这是一座古朴的殿堂。西首的墙上挂满了各类武功图谱，不
少白须白眉的老僧们正端坐在图谱画轴之前，似乎在苦苦思索。
南北山墙是高及屋顶的大书架，走近细看，它们是各门各派的武
功秘笈，屋正中摆着几张矮几诃和几个团，几位老僧正在入定中。
LONG
	);

	set("exits", ([
                 "north" : __DIR__"chanyuan",
		"down" : __DIR__"dmyuan",
	]));

	set("objects",([
		CLASS_D("shaolin") + "/xuan-bei" : 1,
		__DIR__"npc/xiao-bei" : 1,
	]));
	setup();
}



void init()
{
	object me=this_player();
	if(!me->query("luohan_winner") && userp(me))
	{
		me->move("/d/shaolin/dmyuan");
               message_vision("$N被赶了下去，没有破阵也来凑什么热闹呀。\n",me);
	}
        add_action("do_lin", "lingwu");
}


int do_lin(string arg)
{
   	object me= this_player();
        object where = environment(me);
        string skillname,arg2;
        int skill, skill_basic;
        int cost;
	int lingwu_times;
        seteuid(getuid());

        if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");
        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if( me->is_fighting() )
                return notify_fail("你已经在战斗中了，学一点实战经验吧。\n");

        if( !arg ) return notify_fail("领悟什么？\n");
        arg2=arg;
        if(sscanf(arg2,"%s %d",arg,lingwu_times)!=2) {
        arg=arg2;
        lingwu_times=1;
        }
		if (lingwu_times < 1) return notify_fail("你至少要领悟一次！\n");
		if (lingwu_times>100) return notify_fail("你至多领悟一百次！\n");
        skill_basic = me->query_skill(arg, 1);
        if( skill_basic < 1 )
        	return notify_fail("你还没学过这项技能吧？最好先去请教别人。\n");
        if( !stringp(skillname = me->query_skill_mapped(arg)) )
             return notify_fail("你只能领悟 enable 了高级技能的基本技能。\n");
        skill = me->query_skill(skillname, 1);
        cost=20;

              if( skill_basic > skill)
         return notify_fail("你的基本功夫比你的高级功夫还高！\n");
		if (me->query("jing") < cost)
			return notify_fail("你现在过于疲倦,无法静下心来领悟功夫！\n");
		if ( (me->query("jing")/cost)<lingwu_times)
				lingwu_times = me->query("jing")/cost;
		me->improve_skill(arg,(random((int)me->query_int()/4)+1)*lingwu_times);
		me->receive_damage("jing", cost*lingwu_times );
		write("你领悟了" + chinese_number(lingwu_times) + "次" + to_chinese(arg) + "。\n");
        return 1;
}

