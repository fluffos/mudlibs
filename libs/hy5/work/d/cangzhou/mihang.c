// Room: /d/cangzhou/mihang.c

inherit ROOM;
void create()
{
        set("short", "米行");
        set("long", @LONG
这里米行，大担小斗堆满了一地，都是各种米。掌柜懒洋洋地躺在一只躺
椅上，伙计忙着招呼着客人。
LONG );
        set("exits", ([
        	"east" : __DIR__"beijie1",
		"south" : __DIR__"changku",
	]));
	
	set("objects", ([
                __DIR__"npc/gongtou.c" : 1,
        ]));
	setup();
}
