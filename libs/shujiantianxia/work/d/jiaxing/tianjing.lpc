// /d/jiaxing/tianjing.c 天井
// by shang 97/6

inherit ROOM;

void create()
{
        set("short", "天井");
	set("long", @LONG
这是陆家庄庄内的天井，正面有一个青石屏风，上面画着一幅画。对着门
口有一个仆人正在低头扫地。
LONG
	);

	set("exits", ([
                "west" : __DIR__"dating",
                "east" : __DIR__"luzhuang",
	]));

        set("objects", ([
                __DIR__"npc/puren" : 1,
        ]));
        set("outdoors", "嘉兴");
	setup();
}
