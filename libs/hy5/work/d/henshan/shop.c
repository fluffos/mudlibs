//Room: /d/henshan/shop.c
// Modified By Java Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "小店");
	set("long", @LONG
这里是衡阳县城的一间小店，卖些简单的饮食，专门赚那些游客
的钱。
LONG );
	set("exits", ([
		"north" : __DIR__"hengyang1",
		"up"    : __DIR__"huiyan",
	]));
	set("objects", ([
	      "/d/jinyong/book8/henshan/npc/xiaoer2" : 1,
	]));
//        set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
