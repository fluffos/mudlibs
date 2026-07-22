//ROOM lianjianshi.c
inherit ROOM;
void create()
{
        set("short", "铸杖车间");
        set("long",
        "这里是冶炼称的铸杖车间。四周道也不是十分荒凉，相反还可说有\n"
        "几分景致。露天放着一个巨大的炉子，冒着蓬蓬的蓝炎，似乎什么都能被它\n"
        "融化似的。\n"  
        );
        set("exits", ([
                "south" : __DIR__"zhubian_room",
                "north":__DIR__"zhudao_room",
        ]));
    set("objects",([__DIR__"npc/zhuzhang" :1,]));
set("no_fight",1);
        setup();
    replace_program(ROOM);
}
