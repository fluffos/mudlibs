// "suiye"/shuaifu
// Room in 碎叶
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "帅府");
	set("long", @LONG
这是碎叶的帅府，是中国在西域的最高权利中心，几个将领正在讨
论着西域的战局。每天从这里发出向西域作战的指令，并发出快本奏给
皇上。南面是后花园，从西面的客厅不时走出几个丫鬟，向东面元帅休
息的书房走去。
LONG
	);
set("exits", ([
		"west" : __DIR__"keting",
		"north" :  __DIR__"dongdajie1",
                "east"  : __DIR__"shufang",
                "south"  :__DIR__"houhuayuan",
	]));
 set("objects",([ __DIR__"npc/bing":2,]));
       setup();
	replace_program(ROOM);
}	
