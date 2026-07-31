//      dilao.c 地牢
//      Designed by secret (秘密)
//      97/04/09

inherit ROOM;

void create()
{
        set("short","地牢");
        set("long",@LONG
这是一个阴暗、潮湿的牢房。你感到奇怪的是怎麽会不
时听到一点怪声却怎么也找不到人呢? 
LONG );
        set("exits",([
                "westup" : __DIR__"houyuan",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

