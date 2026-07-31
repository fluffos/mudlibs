// /d/taiyuan/dongdajie2.c
// Room in 太原
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "东大街");
	set("long", @LONG
大街有两辆马车并行那么宽，向东望去已经可以看见东场城门子，
西面是太原的中心广场，北面是一家小酒馆，南面传来一阵唱叫声，原
来那里是一家赌场。
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"jiuguan", 
                "south" : __DIR__"duchang", 
                "east" : __DIR__"dongdajie1", 
                "west" : __DIR__"center",       
	]));
       setup();
	replace_program(ROOM);
}
