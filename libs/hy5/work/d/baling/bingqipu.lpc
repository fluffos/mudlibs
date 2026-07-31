// baling/nandajie3
// Room in 龟兹 
// laowuwu 99/04/11
inherit ROOM;

void create()
{
	set("short", "兵器铺");
	set("long", @LONG
据说这家兵器铺是箭大师所开，所以不论是什么样的兵器特别是弓
箭的质量是一流的，在这买东西是没错的。
LONG
	);

	set("exits", ([
		"south":__DIR__"nandajie3",
	]));
set("objects", ([
		__DIR__"npc/tiejiang" : 1
	]));
	setup();
	replace_program(ROOM);
}
