inherit ROOM;

void create()
{
        set("short", "泉井亭");
        set("long", @LONG

    这是一个石室当中的小亭,四周是四面屏风,画满了鸟虫花草。亭子中有一眼坎儿井。
井台上有一个木杯似乎是专供口渴的人喝水之用。
LONG
        );
        set("resource/water", 1);

        set("exits", ([
                "south" : __DIR__"study_room",
                "west" : __DIR__"guoyuan",
		"east" :__DIR__"yueertai",
        ]));

        set("objects", ([
        ]));

        setup();
//        replace_program(ROOM);
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
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"趴在坎儿井的井台上用木杯舀了一杯水喝。\n"
            , environment(me), ({me}) );
            write("你喝了一口井中从从亭底上流淌进来的泉水，甘甜无比。\n");
        }
        else write("逮着不要钱的水就这么喝，至于吗?\n");

        return 1;
}


