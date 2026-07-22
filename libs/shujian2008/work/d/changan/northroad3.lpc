// Write By Yanyang@SJ 2001.10.13
// Room: /d/changan/northroad3.c

inherit ROOM;

void create()
{
        set("short", "大道");
        set("long", @LONG
这是一条尘土飞扬的大道，道路很宽，足可容得下十马并驰。四周人来人
往，熙熙攘攘，非常热闹。南边远远望过去可以看得到巍峨的长安城墙。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
       "northeast"  : __DIR__"northroad4",
           "south"  : __DIR__"northroad2",
                        ]));
                        
        setup();
}

int valid_leave(object me, string dir)
{
	if (me->query("id") == "yangcan popo" && dir != "south") return 0;
	return ::valid_leave(me, dir);
}
