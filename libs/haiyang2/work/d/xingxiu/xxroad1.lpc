// Room: /d/xingxiu/xxroad1.c

inherit ROOM;

void create()
{
        set("short", "大道");
        set("long", @LONG
你走在一条青石大道上，尘土飞扬。东面是一座大城池，看城
墙上旗帜飘扬，好象就是兰州了。西面望去一片黄土和荒野。
LONG );
        set("exits", ([
            //"east"  : "/d/city4/westgate",
            "east"  : "/d/lanzhou/ximen",
            "west"  : __DIR__"xxroad2",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
        replace_program(ROOM);
}

