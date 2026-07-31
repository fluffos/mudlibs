// Room: /city/ymdongting.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "衙门正厅");
	set("long", @LONG
堂上东西有两根楹住，挂着一幅对联，但是你无心细看。正墙上悬挂一个横
匾，上书“正大光明”四个金光闪闪的大字。知府正坐在文案后批阅文书，听要
这里为玩家举行婚礼.你可以在这里和你的心上人结婚（jiehun）,离婚（lihun）。
LONG );
	set("exits", ([
		"west" : __DIR__"yamen",
	]));
	set("objects", ([
		__DIR__"marry/chen" : 1,
		__DIR__"marry/hongniang" : 1,
	]));
        set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

