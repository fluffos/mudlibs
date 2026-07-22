// Write By Yanyang@SJ 2001.9.27
// Room: /d/changan/huadian.c

inherit ROOM;

void create()
{
        set("short", "花店");
        set("long", @LONG
这里是长安城唯一的花店。走进这里，宛如步入了花的世界，从房顶到地
面都是五颜六色的鲜花，清新的花香沁人心裨。店中各种名花玲琅满目，不乏
珍奇异种。来客不分高低贵贱，这里的主人总是笑脸相迎。
LONG
        );
        set("exits", ([
                "north"   : __DIR__"eastjie3",
        ]));
        set("objects", ([
                NPC_D("flowergirl") : 1,
        ]));
        set("incity",1);
	setup();
}
