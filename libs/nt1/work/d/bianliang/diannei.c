inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short",HIY"承德殿内"NOR);
        set("long",
"这里是承德殿内，也是大宋皇帝和文武百官议事的地方，殿内金碧辉\n"
"煌，煞是雄伟壮观，大殿的正中央的龙椅上端坐的是宋徽宗，两面分立着\n"
"众宫女太监，文武百官依品次排列左右。\n"
);

        set("indoors", "bianliang");
        set("no_fly",1);
        set("no_fight",1);
        set("have_quest",1);

        set("exits", ([
                "out"    : __DIR__"cddian",
        ]));

        set("objects", ([
           "/quest/quest_jun/song/liu" : 1,
           __DIR__"npc/taijian"     : 2, 
        ]));
        setup();
        replace_program(ROOM);
}

