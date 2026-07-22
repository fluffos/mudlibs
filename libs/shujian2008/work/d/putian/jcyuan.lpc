// Room: /d/putian/jcyuan.c 戒持院
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIB"戒持院"NOR);
        set("long", @LONG
这里是戒持院，相当于嵩山少林本院的戒律院。整个大殿门户紧闭，密不
透风。即便是在白昼，也犹如黑夜一般，墙上点着几枝蜡烛。殿上供奉着降魔
韦陀，下方摆着一排水牛皮鞭、穿孔竹板及狼牙棒等执法刑杖。四周站满了怀
抱戒刀的执法僧兵。他们正用威严的眼神打量着你，令你不禁心生惧意。
LONG
        );

        set("exits", ([
                "north" : __DIR__"xm-dian",
                "south" : __DIR__"jingshi",
                "east" : __DIR__"changlang3",
                "west" : __DIR__"changlang2"
        ]));

        set("objects",([
                __DIR__"npc/shami" : 1,
                CLASS_D("putian") + "/da-dian" : 1,
        ]));

        setup();
}
int valid_leave(object me, string dir)
{
	if (objectp(present("dadian dashi", environment(me))) && dir == "south")
		return notify_fail("大颠大师皱了皱眉道：没事请不要乱闯。\n");

	return ::valid_leave(me, dir);
}