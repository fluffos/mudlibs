//Room: /d/city/shuyuan2.c

string look_shelf();

#define STOY_TOC "/doc/legend/toc"
#define STOY_DIR "/doc/legend/"
inherit ROOM;

void create()
{
        set("short", "书院书库");
        set("long", @LONG
这里是书院的图书馆，窗明几净，一尘不染。壁上的书架(shelf)堆
满侠客行的先贤们的文选，记录了侠客行的风风雨雨和无数凄婉的、遥
远磨灭不去的传说。你可以阅读(read)到这些古老的故事。
LONG);
        set("item_desc", ([
            "shelf" : (: look_shelf :),
        ]));
        set("exits", ([
            "down" : __DIR__"shuyuan",
        ]));
	set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_read", "read");
}

string look_shelf()
{
        this_player()->start_more(read_file(STOY_TOC));
        return "\n";
}

int do_read(string arg)
{
        object me=this_player();
        if (arg == "" || file_size(STOY_DIR + arg) <= 0)
                return notify_fail("我们没有这本书。\n");

        log_file("LIBRARY", sprintf("%s read %s.\n", me->query("name"), arg));
        me->start_more(read_file(STOY_DIR + arg));
        return 1;
}

