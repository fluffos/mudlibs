// /d/emei/niuxinting.c 峨嵋派 牛心亭

inherit ROOM;

void create()
{
	set("short", "牛心亭");
	set("long", @LONG
这里是一座六脚亭，一条盘山小道连接上下，从亭中望向两边，只见
山式越见陡峭险峻，绝壁多生怪柏，悬泉瀑布，飞漱其间。清荣峻茂，良
多趣味。每至晴出霜旦，常有高猿长啸，空谷传响，哀转久绝。这里也是
路途劳顿，稍是休息的一个好地方。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([ /* sizeof() == 3 */
                "westdown":__DIR__"qingyinge",
                "southup":__DIR__"yixiantian",
		]));

	set("objects", ([ 
             "/d/emei/npc/youke" : 1,
	]));

	setup();
}
