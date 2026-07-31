// Room: /chengdu/ruin1.c
// oooc: 1998/06/26

inherit ROOM;
void create()
{
	set("short", "破旧大宅");
	set("long", @LONG
这里是一间破旧大宅的前院，大厅已经崩塌了一半，焦黑的梁
柱挡住了你的去路，庭院里杂草丛生，看来已经很久没有人住了，
据说这里晚上有鬼魂出现，但是倒也从没听说过有人被害，因此附
近的居民仍然照常生活。
LONG
	);
        set("outdoors", "chengdu");
	set("exits", ([ /* sizeof() == 1 */
                "out" : __DIR__"cai",
                "east" : __DIR__"ruin2",
        ]));
        set("objects", ([
           __DIR__"npc/qigai" : 3,
        ]));

	setup();
}

