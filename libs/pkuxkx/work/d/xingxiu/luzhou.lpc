inherit ROOM;

void create()
{
        set("short", "沙漠绿洲");
        set("long", @LONG
在沙漠的尽头出现了一个绿洲。灌木丛中有一眼水井。井台上有一个木杯专
供口渴的行人喝水。井边是一块瓜地。
LONG
        );
        set("resource/water", 1);

        set("exits", ([
                "northeast" : __DIR__"shanjiao",
                "southwest" : __DIR__"nanjiang3",
        ]));

        set("objects", ([
            __DIR__"npc/obj/donkey" : 1,
            __DIR__"npc/obj/hamigua" : 2,
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
            message("vision", me->name()+"趴在水井的井台上用木杯舀了一杯水喝。\n"
            , environment(me), ({me}) );
            write("你喝了一口井中捞上来的井水，冰凉沁人，十分舒畅。\n");
        }
        else write("逮着不要钱的水就这么喝，至于吗?\n");

        return 1;
}


