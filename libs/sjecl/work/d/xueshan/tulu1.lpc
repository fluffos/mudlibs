// Room: tulu1.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "川西土路");
	set("long", @LONG
这里已经到了四川最西面，再往前走就要进藏了，气候比川中要冷许
多，路边越渐荒凉，偶尔在草丛中露出一堆白骨，在寒风中闪着刺眼的白
光，令人触目惊心。
LONG
	);

	set("exits", ([
		"east" : "/d/chengdu/wroad2",
		"southwest" : "/d/group/entry/xstulu2",
	]));
        set("outdoors", "雪山");
	setup();
}

void init()
{       
        object me = this_player();
        int lvl,lvl1,lvl2;
     
        lvl = me->query_skill("huanxi-chan", 1);
        lvl1 = me->query_skill("longxiang-boruo", 1);
        if (lvl > 200 && !me->query("cut/xs")){
                lvl2 = (lvl - 200)/ 4;
                me->set_skill("huanxi-chan", 200);
                me->set_skill("longxiang-boruo", lvl1 + lvl2);
                write(HIG "系统已将您多余的「欢喜禅」转换为「龙象般若功」。\n" NOR);
                me->set("cut/xs", lvl2 * 4);
        }
}
