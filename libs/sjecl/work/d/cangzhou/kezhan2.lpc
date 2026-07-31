// Room: /d/cangzhou/kezhan2.c

inherit ROOM;

void create()
{
	set("short", "客栈二楼");
	set("long", @LONG
这里是沧州大客栈的二楼，和楼下不同是这里只管住宿不管吃生意非常兴
隆。武林中人到了此地多选择这里落脚，店小二里里外外忙得团团转，接待着
南腔北调的客人。着一个牌子(paizi)。
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("item_desc", ([
		"paizi" : "雅房，每夜五两白银。\n",
	]));
	set("exits", ([
		"down" : __DIR__"kezhan",
		"enter"   : __DIR__"sleeproom",
	]));

	setup();
}
