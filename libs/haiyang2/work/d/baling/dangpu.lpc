// baling/pomiao
// Room in 龟兹 
// laowuwu 99/04/11

inherit ROOM;

void create()
{
	set("short", "当铺");
	set("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，
柜台上摆着一个牌子「paizi」，柜台后坐着老板，一双精明的眼睛上上
下下打量着你。
LONG
	);
    set("no_beg",1);

	set("item_desc", ([
		"paizi" : "公平交易\n",
	]));
	
	set("exits", ([
		"west" : __DIR__"nandajie1",
	]));
	set("objects",([
	   __DIR__"npc/meng":1,
	   ]));

	setup();
	replace_program(ROOM);
}

