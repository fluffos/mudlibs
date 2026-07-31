//  jitan.c 祭坛

inherit ROOM;

void create()
{
        set("short","雪山祭坛");
        set("long",@LONG
这里是雪山寺雪山祭坛，中间一个高台，青石砌就。
周围摆满了木柴和酥油，旁边一个盛水的颅钵搁着摆着一
只法铃。一些痛苦和可怜的亡灵可以在这里获得超度。
LONG );
        set("outdoors","xueshan");
//        set("no_fight","1");
        set("exits",([
                "north" : __DIR__"chang",
        ]));
set("roomif","$botten#法事任务|上交尸体:ask gelunbu about 法事|give corpse to gelunbu$#");
        set("objects",([
                CLASS_D("xueshan")+"/gelunbu": 1,
                __DIR__"npc/sengbing": 2,
                __DIR__"npc/x_lama": 2,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

