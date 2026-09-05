//荣昌交易行
//auction room
//Made by Jason@pkuxkx
//2001-10-15
#ifndef BID_D
#define BID_D   "/adm/daemons/bidd"
#endif 

inherit ROOM;

void create()
{
	set("short","荣昌交易行");
	set("long","这是一家不大的交易行，一个年迈的男人站在柜台后面颤巍巍的\n"
	"主持着交易，看来有得等了。\n"
	);
	set("exits",([
		"south":__DIR__"dongdajie3",
	]));
	set("objects", ([
		__DIR__"player/quqing" : 1,
	]));
	set("auction_room",1);
	setup();
}

void init()
{
	add_action("do_get","qu");
}

int do_get()
{
	return  BID_D->get_good(this_player());
}