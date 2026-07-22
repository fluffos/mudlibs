// cangjingge.c 藏经阁
// by ahunter and shang  97/6
inherit ROOM;

string* books = ({
        __DIR__"obj/laozi1",
        __DIR__"obj/ddj1",
        __DIR__"obj/laozi2",
        __DIR__"obj/ddj1",
        __DIR__"obj/laozi8",
        __DIR__"obj/laozi13",
        __DIR__"obj/laozi1",
        __DIR__"obj/laozi16",
        __DIR__"obj/laozi18"
});

void create()
{
        set("short", "藏经阁");
        set("long", @LONG
这里是藏经阁，靠墙是一排书架，摆满了道教的典籍。中央有一个长方形
的大桌子，上面也堆满了书。一个道童正在整理书籍。
LONG
        );

        set("exits", ([
                "east" : __DIR__"donglang1",
        ]));

        set("objects", ([
                __DIR__"npc/daotong" : 1,
                books[random(sizeof(books))] : 1,
                books[random(sizeof(books))] : 1
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        object *ob = deep_inventory(me);
        int i = sizeof(ob);
        if((dir == "east")){
        while (i--)
        if(ob[i]->id("daode jing"))
           return notify_fail("道德经不得携带外出 !\n");               
        }
        return ::valid_leave(me, dir);
}
