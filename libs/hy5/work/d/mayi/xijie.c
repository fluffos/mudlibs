// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "西大街");
	set("long", @LONG
马邑是西北的重镇，刚开始这里就是一个兵营，百姓害怕突厥侵犯，
就迁移到这儿来，就逐渐形成现在的规模，在街道的北面是是做大宅院，
里面住的一定是个大人物。
LONG
	);
set("outdoors", "mayi");
set("exits", ([
                "north": __DIR__"damen", 
                "east": __DIR__"center", 
                "west": __DIR__"ximen",  
	]));
set("objects",([
  __DIR__"npc/laozhe":1,
  ]));
       setup();
	replace_program(ROOM);
}	
