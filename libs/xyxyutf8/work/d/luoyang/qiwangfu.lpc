//changan city
// Cracked by 凌惊雪 1-3-2003

inherit ROOM;

void create ()
{
        set ("short", "少帅府");
        set ("long", @LONG
此处便是少帅府，寇仲为了与李唐抗衡在洛阳招兵买马的地方，
这里大门上方跳出四角飞檐，两侧立有四根大理石柱，柱身纹有图
腾底案。门上正中悬挂一块金匾，刻有:
*******************************************************
                       少 帅 府
*******************************************************
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"chengyun",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));
        set("outdoors", "luoyang");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


