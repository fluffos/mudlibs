// Room: /d/xingxiu/ryd1.c
inherit ROOM;
void create()
{
        set("short", "日月洞口");
        set("long", @LONG
这里是星宿海的尽头。因方圆几百里都是一望无际的湖泊和沼泽，当地牧
羊人称之为“海”。北边是一座小石山，星宿派总舵日月洞便设在这里，洞口
立着一个铜制牌子(paizi)。
LONG);
        set("exits", ([
             "north" : __DIR__"ryd",
             "southdown" : __DIR__"xx1",
             "west" : __DIR__"xxh4",
             "east" : __DIR__"xxh3",
	]));
	set("item_desc", ([
                "paizi" : "
             星宿海福地
             日月洞洞天。\n",
	]));
	set("objects", ([
                __DIR__"npc/anran" : 1,
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
        ]) );
        set("outdoors", "星宿");
	setup();
	"/clone/board/xingxiu_b"->foo();
}
