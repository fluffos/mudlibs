// "suiye"/zhongxinguanchang
// Room in 碎叶
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "碎叶广场");
	set("long", @LONG
这里便是碎叶城的中心，四条大街交汇于此。外周虽不甚漂亮，但
城中心还是很有气势一条美丽的人鱼石雕竖在城中心，好象这是他们的
崇拜物。
LONG);
set("outdoors", "suiye");
set("exits", ([
		"south" : __DIR__"nandajie1",
		"north" :  __DIR__"beidajie2",
                "east"  : __DIR__"dongdajie1",
                "west"  :__DIR__"xidajie1",
	]));
 set("objects",([
  __DIR__"npc/xiaofan2":1,
"/clone/npc/man":2,
  	]));

       setup();
	replace_program(ROOM);
}	
