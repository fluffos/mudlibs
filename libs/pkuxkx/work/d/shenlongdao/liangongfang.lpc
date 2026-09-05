// liangongfang.c 练功房
inherit ROOM;
void create()
{
        set("short", "练功房");
        set("long", @LONG
        这里是练功房，地下凌乱地放着几个蒲团，几位弟子正盘膝坐在上
面打坐，另外几名弟子在互相切磋功夫。
LONG
        );
        set("exits", ([
                "south" : __DIR__"xiaoting",
        ]));
        set("objects", ([
              __DIR__"npc/dizi" : 2,
              "/clone/weapon/bishou" : 1,
              "/clone/weapon/changbian" : 1,
]));
        set("lingwu_family", "神龙教");
        set("no_fight", 1);
        setup();
}

