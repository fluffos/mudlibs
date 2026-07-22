// Room: /d/huashan/zhenyue.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "镇岳宫");
        set("long", @LONG
这里地势略为平坦，上、下山的游客多在此稍作休息再继续前行。附近有
几间简陋的旅社，欲登东峰观日出者，大都于头晚歇息于此。
LONG
        );
	set("exits", ([
		"northup" : __DIR__"canglong",
		"eastup" : __DIR__"chaoyang",
		"southup" : __DIR__"yunu",
	]));
        set("objects",([
                NPC_D("tiao-fu") : 1,
                NPC_D("youke") : 2,
        ]));
	set("outdoors", "华山" );
	setup();
}
