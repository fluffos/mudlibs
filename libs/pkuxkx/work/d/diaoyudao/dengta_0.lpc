// Room: /d/diaoyudao/dengta_0.c
// cgbii 96.10.4
// modify by hongdou 98.9.15

inherit ROOM;



void create()
{
        set("short", "钓鱼岛");
        set("long", @LONG
这是一个座落在大海中央的孤岛，这里位处偏僻，根本没有
人会到这里来，而来自东瀛的倭寇就是看上这点，在这里建立了
一座灯塔，将这里变成了他们的大本营。只见许多倭寇在这里四
处走动。
LONG
        );

        set("exits", ([
                 "westdown" : __DIR__"duhaitan",
                   "enter" : __DIR__"dengta_1",
        ]));

        set("objects",([
                __DIR__"npc/langren" : 2,
        ]));

        set("outdoors", "quanzhou");
        setup();
}


int valid_leave(object me,string dir)
{
if (dir=="enter"){
if (objectp(present("lang ren",environment(me))))
return notify_fail("东瀛浪人拦住你道：你是哪里来的？这是我们东瀛的领土！快滚！八格.....\n");
                             }
    return::valid_leave(me,dir);
}
