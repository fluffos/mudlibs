// /d/taiyuan/chaguan.c
// Room in 太原
// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "茶馆");
	set("long", @LONG
这是一个茶馆不过是一张凉席遮住了阳光，几张桌子散放在地上，
门里传来一阵阵叫好声，里面是一家戏园子。
LONG
	);
set("exits", ([
                "enter" : __DIR__"xiyuan", 
                "south" : __DIR__"xidajie2",    
	]));
	set("objects",([
	__DIR__"npc/xiaoer":1,
	]));
	set("resource/water",1);
       setup();
	replace_program(ROOM);
}	
