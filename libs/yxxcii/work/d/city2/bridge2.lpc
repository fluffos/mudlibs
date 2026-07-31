//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "桥底西侧");
	set("long", @LONG
这里是小桥西侧，一股寒风吹过，冷得你瑟瑟发抖，只想离开。
LONG
);

	set("resource/water", 1);
	set("exits", ([
		"east" : __DIR__"bridge",
	]));

	set("no_clean_up", 0);
	setup();

	replace_program(ROOM);
}

