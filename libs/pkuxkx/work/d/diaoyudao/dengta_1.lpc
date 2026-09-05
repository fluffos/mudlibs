// Room: /d/quanzhou/dengta_1
// cgbii 96.10.4

inherit ROOM;




void create()
{
        set("short", "灯塔一层");
        set("long", @LONG
这里是灯塔的底层，海风从墙上的隙里吹进来，往上
看，长长的石级盘绕而上，似乎永无尽头。墙角，梯级都
相当洁净，看来经常有在走动。
LONG
        );

        set("exits", ([
                "up" : __DIR__"dengta_2",
                "out" : __DIR__"dengta_0",
        ]));

        set("objects",([
                __DIR__"npc/langren" : 3,
        ]));
        setup();
}

int valid_leave(object me,string dir)
{
if (dir=="up"){
if (objectp(present("lang ren",environment(me))))
return notify_fail("东瀛浪人拦住你道：哪里来的中原人？这是我们东瀛国的领土！快滚！八格呀路的...\n");                             }
    return::valid_leave(me,dir);
}
