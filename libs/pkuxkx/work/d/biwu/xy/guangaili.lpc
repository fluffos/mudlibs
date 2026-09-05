// Room: guangaili.c
// edit: by zine Aug 21 2010
inherit "/biwu/biwuroom2";

void create()
{
	set("short", "冠盖里");
	set("long", @LONG
这里是襄阳城的当年市场，蒙古人南下后作为军资堆放的场所。东南面是一
座巨大的烽火台。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"north" : __DIR__"southstreet",
		"south" : __DIR__"southgate",
	]));
	set("no_clean_up", 0);
	set("objects", ([
       ("/biwu/xy/npc/yexingren") : random(2),
    ]));
	setup();
}

