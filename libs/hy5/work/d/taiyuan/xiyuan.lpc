// /d/taiyuan/xiyuan.c
// Room in 太原
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "戏园");
	set("long", @LONG
戏园里的台上正在唱戏，大红的幔布被拉在两端，台下几张桌子旁，
做着不少观众有的手舞足蹈，有的在品茶，叫好。
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "out" : __DIR__"chaguan", 
	]));
set("objects",([
  __DIR__"npc/xiyou":1,
  ]));
       setup();
	replace_program(ROOM);
}	
