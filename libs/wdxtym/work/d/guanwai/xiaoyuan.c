// /guanwai/xiaoyuan.c

inherit ROOM;

void create()
{
    set("short", "小院子");
    set("long", @LONG
这是山间民居前的一座小院子，北面有一个小屋，院中有一个老人正在
打扫。
LONG );
    set("exits", ([
	"south" : __DIR__"baihe",
	"north" : __DIR__"xiaowu",
    ]));
    set("objects", ([
	CLASS_D("hu") + "/pingsi" : 1,
    ]));
    set("outdoor", "guanwai");
	set("valid_startroom", 1);
    setup();
}

int valid_leave(object me, string dir)
{
    object guarder;

    if (objectp(guarder = present("ping si", this_object())) &&
	dir == "north")
    {
	return guarder->permit_pass(me, dir);
    }

    return 1;
}
