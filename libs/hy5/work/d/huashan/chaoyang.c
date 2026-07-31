// chaoyang.c

inherit ROOM;

void create()
{
        set("short", "朝阳峰");
        set("long", @LONG
这里就是华山的东峰，也称朝阳峰，是华山看日出的绝佳处。於此俯
瞰，黄河隐显东迤如带，南望小孤峰背倚山河。小孤峰上有一小亭，覆以
铁瓦，亭中有铁棋盘一局，那就是华山著名的“博台”了。东壁悬崖上，
更有一个巨型掌印，相传为「河神巨灵」劈山时所留下的，李白诗中“巨
灵咆哮劈两山，洪波喷流射东海”就是指这个上古传说。
LONG );
        set("exits", ([ /* sizeof() == 1 */
           "westdown" : __DIR__"chaopath2",
        ]));
        set("objects", ([
            CLASS_D("huashan")+"/gao-laozhe": 1,
            CLASS_D("huashan")+"/ai-laozhe": 1,
        ]));

//        set("no_clean_up", 0);
        set_temp("wayao2",1);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
 
