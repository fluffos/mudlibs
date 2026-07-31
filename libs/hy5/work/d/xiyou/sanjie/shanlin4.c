// sanjie shanlin4.c

inherit ROOM;
void create()
{
        set("short", "瘴气林");
        set("long", @LONG
        
这是一片茂密的树林，长的大数有几层楼高，而且叶子茂密，
阳光都给遮蔽了，林子里面暗无天日。林子连瘴气重重，毒
蛇怪物满地爬走，好像一点都不怕人。
LONG );
        set("exits", ([
                "east" : __FILE__,
                "west" : __DIR__"shanlin5",
                "south" : __FILE__,
                "north" : __FILE__,
                "southeast" : __FILE__,
                "northwest" : __DIR__"shanlin3",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
