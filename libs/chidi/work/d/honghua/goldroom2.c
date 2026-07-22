//ROOM goldroom.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "储藏室");
        set("long",@LONG
这是一间小屋子，地上干干净净，纤尘不染，靠墙角的地方放着
几个箱子，屋子两壁厢点满了粗如儿臂的红烛，照得四下如同白昼一
般。
LONG
	);
        
	        
	set("exits", ([
		"east" : __DIR__"zongduo",
        ]));
	
	set("objects", ([
                "/d/honghua/npc/xutianhong" : 1,
                "/d/honghua/box" : 1,
	]));	

	set("coor/x",-160);
	set("coor/y",110);
	set("coor/z",30);
	set("coor/x",-160);
	set("coor/y",110);
	set("coor/z",30);
	set("coor/x",-160);
	set("coor/y",110);
	set("coor/z",30);
	setup();
}
