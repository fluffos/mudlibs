//Room: /d/huashan/shop.c

inherit ROOM;

void create()
{
	set("short", "小吃店");
	set("long", @LONG
这里是石梁边的一间小吃店，卖些简单的饮食，专门赚那些游客
的钱。
LONG );
     	set("exits", ([
            "west" : __DIR__"shiliang",
       	]));

        set("objects", ([
            "/d/city/npc/xiaoer2" : 1,
       	]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

