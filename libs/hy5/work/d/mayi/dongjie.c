// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "东大街");
	set("long", @LONG
马邑是西北的重镇，刚开始这里就是一个兵营，百姓害怕突厥侵犯，
就迁移到这儿来，就逐渐形成现在的规模，在街道的北面是军营，南面是
一个小校场。
LONG
	);
set("outdoors", "mayi");
set("exits", ([
                "east": __DIR__"dongmen", 
                "west": __DIR__"center",  
	]));
set("objects",([
  __DIR__"npc/shiren":1,
  ]));
       setup();
	replace_program(ROOM);
}	
