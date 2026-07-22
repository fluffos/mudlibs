// Room: /d/city/guandimiao.c
// Date: Look 99/09/20

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR "关帝庙" NOR);
	set("long", @LONG
这是扬州城东面的一所关帝庙，据说夜里经常有人在此聚众饮酒，普通百
姓是不会来这是非之地的。但见庙正中供奉的关帝塑像栩栩如生，手持青龙偃
月刀，左右各是关公的结义兄弟刘备和张飞，一个个义气夺人，仿佛要杀尽天
下不义之人。
LONG
	);
        set("indoors", "扬州");

	set("exits", ([
		"southwest" : __DIR__"dongmen",
	]));
//	set("objects", ([__DIR__"npc/linghuchong" : 1]));

	set("incity",1);
	setup();
}

void init()
{
	object me = this_player();
  	object weapon = me->query_temp("weapon");
	if (weapon){
		tell_object(me, YEL"你看见关帝瞪着你的眼神，打了个冷战，不自禁的放下了手中的兵器。\n"NOR);
		weapon->unequip();
	}
//	add_action("do_jiebai","jiebai");
}

/*
int do_jiebai(string arg)
{
	string arg1, arg2, arg3;
       	object me, ob1, ob2, ob3;
       	int i;

       	me = this_player();

       	if (!arg) return notify_fail("格式：jiebai with <id> <id> <id>\n");
	i = sscanf(arg, "%s %s %s", arg1,arg2,arg3);
        if( i >= 0 && i <= 2 ){
        	if (!arg1) return notify_fail("你要和谁结拜？\n");
        	if (arg1){
			if (!(ob1 = present(arg1, environment(me))))
				return notify_fail("你要结拜的人不在这里。\n");
			if (ob1==me )
				return notify_fail("你不能和自己结拜。\n");
			if (!living(ob1)
                         || !ob1->is_character())
				return notify_fail("你要和谁结拜？\n");
		}
                if (arg2){
			if (!(ob2 = present(arg1, environment(me))))
				return notify_fail("你要结拜的人不在这里。\n");
			if (ob2==me )
				return notify_fail("你不能和自己结拜。\n");
			if (ob2==ob1)
				return notify_fail("你已经输入了"+arg2+"的名字，不需要输入两次。\n");
                	if (!living(ob2)
			 || !ob2->is_character())
				return notify_fail("你要和谁结拜？\n");
		}
                if (arg3){
			if (!(ob3 = present(arg1, environment(me))))
				return notify_fail("你要结拜的人不在这里。\n");
			if (ob3==me)
				return notify_fail("你不能和自己结拜。\n");
			if (ob3==ob1 || ob3==ob2)
				return notify_fail("你已经输入了"+arg3+"的名字，不需要输入两次。\n");
                	if (!living(ob3)
			 || !ob3->is_character())
				return notify_fail("你要和谁结拜？\n");
		}
        }
        else {
                return notify_fail("结拜的人数必须是二到四个。\n");
	}
	return notify_fail("目前有"+(string)i+"个结拜对象。"+arg1+arg2+arg3+"\n");
}
*/