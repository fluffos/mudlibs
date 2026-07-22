// /d/jiaxing/lumu.c 坟墓
// by shang 97/6

inherit ROOM;

void create()
{
        set("short", "坟墓");
	set("long", @LONG
这儿有两株高耸的大槐树，槐树下赫然并列著两座坟墓，一座墓碑上写著
「陆公展元之墓」六字，另一碑下则是「陆门何夫人之墓」七字。墓畔青草齐
膝，显是安葬已久。一青袍长须的老者呆呆望著墓碑，自言自语。
LONG
	);

	set("exits", ([
                 "west" : __DIR__"shulin1",
	]));

        set("objects", ([
                 __DIR__"npc/wu-santong" : 1,
        ]));

        set("outdoors", "嘉兴");
	setup();
}
