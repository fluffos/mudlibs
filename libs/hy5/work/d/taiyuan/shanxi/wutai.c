// Room: /huanghe/huanghe2.c
// Java. Sep 21 1998
inherit ROOM;
void create()
{
	set("short", "叶门峰");
	set("long", @long
可看云海日出，可见花之海洋，可赏明月娇色，可览群山层叠，可
寻巨石如星，如天造奇观，南北穿流的黄河，哺育着沿崖万物生灵，奇
花异卉万枝，真是美丽到了极致。
long );
	set("exits", ([
  
  "eastdown" : __DIR__"huanghe3",
  "westdown" : __DIR__"huanghe2",
  "north" : __DIR__"daoguan",
  
	]));
	set("objects", ([
		//__DIR__"npc/hou" : 1,
	]));
//	set("no_clean_up", 0);
	        set("outdoors", "shanxi");
        set("coor/x",-350);
        set("coor/y",-430);
        set("coor/z",30);
	setup();
	//replace_program(ROOM);
}
