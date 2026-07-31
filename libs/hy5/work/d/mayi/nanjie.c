// rich 99/04/05
inherit ROOM;
void create()	
{
	set("short", "南大街");
	set("long", @LONG
马邑是西北的重镇，刚开始这里就是一个兵营，百姓害怕突厥侵犯，
就迁移到这儿来，就逐渐形成现在的规模，在街道的东面是一家杂货铺，
西面好象是一家官办的盐局。
LONG
	);
set("outdoors", "mayi");
set("exits", ([
                "north": __DIR__"center", 
                "south": __DIR__"nanmen",   
                "east": __DIR__"zahuopu", 
                "west": __DIR__"yanju",  
	]));
       setup();
	replace_program(ROOM);
}	
