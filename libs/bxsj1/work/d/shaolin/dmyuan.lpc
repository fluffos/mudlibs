// Room: /d/shaolin/dmyuan.c
// Date: YZC 96/01/19

inherit ROOM;

#include <ansi.h>

int nokill()
{
	object ob = previous_object(1);

	if (ob == find_object("/cmds/skill/exercise")
	|| ob == find_object("/cmds/skill/respirate"))
		return 0;
	return 1;
}

int check(string arg)
{
	if (arg) {
		object me = this_player();
		int i;

		sscanf(arg, "%d", i);
		switch (query_verb()) {
			case "exercise":
				if (me->query("neili") + i >= me->query("max_neili")*2) {
					write("这里可不是让你提高内力的地方。\n");
					return 1;
				}
				break;
			case "respirate":
				if (me->query("jingli") + i >= me->query("eff_jingli")*2) {
					write("这里可不是让你提高精力的地方。\n");
					return 1;
				}
				break;
		}
	}
	return 0;
}

void init()
{
	add_action("check", ({ "exercise", "respirate" }));
}

void create()
{
        set("short", HIY"达摩院"NOR);
        set("long", @LONG
这是一座古朴的殿堂。西首的墙上挂满了各类武功图谱，不少白须白眉
的老僧们正端坐在图谱画轴之前，似乎在苦苦思索。南北山墙是高及屋顶的
大书架，走近细看，它们是各门各派的武功秘笈，屋正中摆着几张矮几诃和
几个蒲团，几位老僧正在入定中。北面有个小门通向后殿。
LONG
        );
	set("no_fight", (: nokill :));
        set("exits", ([
                "south" : __DIR__"huilang4",
                "north" : __DIR__"dmyuan2",
        ]));
        set("objects",([
                CLASS_D("shaolin") + "/xuan-bei" : 1,
                __DIR__"npc/xiao-bei" : 1,
        ]));

        set("coor/x",20);
	set("coor/y",430);
	set("coor/z",130);
	setup();
}

int valid_leave(object me, string dir)
{
	if( dir == "north" && !me->query("luohan_winner") && !wizardp(me))
	if(objectp(present("xuanbei dashi", environment(me))))
		return notify_fail("玄悲大师喝道：达摩院乃本寺重地，你不能入内。\n");
	else 
		return notify_fail("一位武僧忽然从边上钻了出来，拦住了你说道：达摩院是少林重地，你不可擅入。\n"+
			"看你停步不动了，那位武僧一拱手，又退回了隐身处。\n");
	return ::valid_leave(me, dir);
}
