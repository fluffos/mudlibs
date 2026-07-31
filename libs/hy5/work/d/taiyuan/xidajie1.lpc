// /d/taiyuan/xidajie1.c
// Room in 太原
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "西大街");
	set("long", @LONG
太原位于西部，街道上你可以看见各域各国的商团，街道的北面是
一家商行，南面是一家驿站，一匹匹快马飞驰而过。
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"shanghang", 
                "south" : __DIR__"yizhan", 
                "west" : __DIR__"ximen", 
                "east" : __DIR__"xidajie2",       
	]));
        set("objects", ([
              "/clone/misc/dache" : 1,
        ]) );		
       setup();
	replace_program(ROOM);
}	
