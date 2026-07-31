//fota1.c

inherit ROOM;

void create()
{
        set("short","佛塔");
        set("long", @LONG
这是一座八面玲珑却又巍峨庄严的佛塔，是当年佛教沿丝绸之路传入
中原时所修，塔分八面，共十二层。每层都塑有许多镏金佛像，各个眉目
慈祥，每层塔檐的八个角上都缀有风铃，微风拂过，叮当叮当的清音如仙
乐直入云霄。
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "north"         :       __DIR__ "lroad2",               
                "up"            :       __DIR__ "fota2",
                ])
        );
//      replace_program(ROOM);
        setup();
}

