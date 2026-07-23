// /d/taiyuan/nandajie1.c
// Room in 太原
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "南大街");
	set("long", @LONG
你走在青石铺成的街道上，街道有两辆马车并行那么宽，但你仍感
到人流的拥挤，北面就是中心广场了，东西两边店铺林立，人流不断，
好一片生意兴隆的景像。
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "north" : __DIR__"nandajie2", 
                "south" : __DIR__"nanmen", 
                "east" : __DIR__"wanjinzhai", 
                "west" : __DIR__"shuyuan",       
	]));
       setup();
	replace_program(ROOM);
}	
