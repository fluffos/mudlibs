// Write By Yanyang@SJ 2001.9.29
// Room: /d/changan/chm.c

inherit ROOM;

void create()
{
        set("short", "城隍庙");
        set("long", @LONG
城隍庙里香火极盛。大多是来保佑家里平安，生意兴隆之类。正中前方一
座白白胖胖，满脸福相的城隍，左边有一位手持帐簿和毛笔的判官。一位庙祝
走前走后，和大家打着招呼。
LONG
        );

        set("exits", ([
                "north"  : __DIR__"westjie4",
        ]));

        set("objects", ([
                __DIR__"npc/miaozhu" : 1,
        ]));

        set("incity",1);
	setup();
}

void init()
{
        add_action("action", ({
                "dazuo",
                "du",
                "exercise",
                "lian",
                "practice",
                "respirate",
                "study",
                "tuna"
        }));
}

int action()
{
        write("你无法静下心来修炼。\n");
        return 1;
}
