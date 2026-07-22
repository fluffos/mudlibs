// Room: /d/huashan/celang3.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "侧廊");
        set("long", @LONG
这里是华山派总堂的侧廊, 庄严古朴, 两旁蜂舞蝶影，山花烂漫，好一派
山地风光。西面是华山弟子的饭厅，未及走近，你已经闻到阵阵饭香。南面是
华山弟子的休息室，供习武疲倦之时睡眠之用。
LONG
        );
        set("exits", ([
		"east" : __DIR__"houtang",
		"west" : __DIR__"fanting",
		"south" : __DIR__"xiuxi1",
	]));

	set("indoors", "华山" );
	setup();
}

int valid_leave(object me, string dir)
{
	if ( dir == "south" && me->query("gender") != "女性") {
		return notify_fail("那是女弟子休息室，你可不能去那个地方!\n");
	}
	return ::valid_leave(me, dir);
}
