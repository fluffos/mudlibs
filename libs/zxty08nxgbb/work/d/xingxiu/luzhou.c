// Room: /d/xingxiu/luzhou.c
// Jay 3.25/96
inherit ROOM;
void create()
{
        set("short", "沙漠绿洲");
        set("long", @LONG
在沙漠的尽头出现了一个绿洲。灌木丛中有一眼坎儿井。井台上有一
个木杯(cup)专供口渴的行人喝水。井边是一块瓜地。
LONG
        );
        set("resource/water", 1);
        set("exits", ([
                "northeast" :"/d/gaochang/huijiang2",
                "southwest" : __DIR__"nanjiang3",
        "south"     : "/d/npc/m_weapon/lianbianshi",
        ]));
        set("item_desc", ([
                "cup" :   "犹豫什么？用木杯舀井水喝(drink)呀！\n",
        ]));        set("objects", ([
            __DIR__"npc/obj/donkey" : 1,
            __DIR__"npc/obj/hamigua" : 2,
        ]));
        setup();
}
void init()
{
        add_action("do_drink", "drink");
}
int do_drink(string arg)
{
        int current_water;
    int max_water;
        object me;
        me = this_player();
        current_water = me->query("water");
        max_water = me->max_water_capacity();
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"趴在坎儿井的井台上用木杯舀了一杯水喝。\n"
            , environment(me), ({me}) );
            write("你喝了一口井中从天山上流淌下来的雪水，简直比蜜还甜。\n");
        }
        else write("逮着不要钱的水就这么喝？\n");
        return 1;
}
