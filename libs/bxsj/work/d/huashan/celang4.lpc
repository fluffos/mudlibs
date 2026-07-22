// Room: /d/huashan/celang4.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "侧廊");
        set("long", @LONG
这里是华山派总堂的侧廊, 庄严古朴, 两旁蜂舞蝶影，山花烂漫，好一派
山地风光。东面是一座古色古香的建筑，仔细一看，是华山派的书院所在，南
面是华山弟子的休息室，供习武疲倦之时睡眠之用。
LONG
        );
        set("exits", ([
		"west" : __DIR__"houtang",
		"east" : __DIR__"shuyuan",
		"south" : __DIR__"xiuxi2",
	]));

	set("no_clean_up", 0);
	set("indoors", "华山" );

	setup();
}

int valid_leave(object me, string dir)
{
        if ((dir == "south" && me->query("gender") != "男性")
        || (dir == "south" && !userp(me))) {
		return notify_fail("那是男弟子休息室，你可不能去那个地方!\n");
	}
	return ::valid_leave(me, dir);
}
