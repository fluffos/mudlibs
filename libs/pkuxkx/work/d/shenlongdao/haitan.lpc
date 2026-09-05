// Room: /shenlongjiao/haitan.c
// kiden 06/08/25

inherit ROOM;

void create()
{
        set("short", "海滩");
        set("long", @LONG
        长长的海滩望不到尽头，尽是雪白细沙。不远处有片树林，传来阵阵花香，让人觉得到了仙境。
传说这岛上生有仙果，吃了长生不老。只不过有福之人才吃得着。
LONG
        );
        set("outdoors", "city");

        set("exits", ([
                "east" : __DIR__"shulin1",
                "northwest" : __DIR__"haibianxiaowu",
                "south" : __DIR__"matou",
        ]));

   set("objects", ([
         __DIR__"npc/xunshandizi":1,
        "/kungfu/class/shenlong/shou":1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
//        replace_program(ROOM);
}

/*
int valid_leave(object me, string dir)
{        

        mapping myfam;
        myfam = (mapping)me->query("family");
        if ((myfam["family_name"] == "神龙教") && dir == "east"
            && ((int)me->query("shenlong/antisnake")==0)
            && objectp(present("shou toutuo", environment(me)))
            &&  living(present("shou toutuo", environment(me))))
           return notify_fail("瘦头陀拦住你说：岛上神龙众多，你还是先问沐姑娘要一杯雄黄酒吧。\n");

        return ::valid_leave(me, dir);
}
*/
