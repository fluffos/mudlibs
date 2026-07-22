//ROOM lianjianshi.c
inherit ROOM;
void create()
{
        set("short", "铸剑车间");
        set("no_fight",1);
        set("long",
        "这里是冶炼厂的铸剑车间。四周荒凉没有人烟，地上隐约还能看见斑斑\n"
        "的血迹，偶尔能看见的几棵树似乎也成了剑的表征，一个个剑拔弩张的。露\n"
        "天放着一个巨大的炉子，冒着蓬蓬的蓝炎，激烈的罡气震得你一阵晕眩，原\n"
        "来这里正在以内家真气炼剑。\n"  
        );
        set("exits", ([
                "south" :  __DIR__"zhudao_room",
                "out":__DIR__"bangongshi",
        ]));
    set("objects",([__DIR__"npc/zhujian" :1,]));
        setup();
    replace_program(ROOM);
}
