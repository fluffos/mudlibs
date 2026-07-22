// Room: /d/xingxiu/luzhou.c
// Jay 3.25/96
inherit ROOM;
void create()
{
        set("short", "绿洲");
        set("long", @LONG
在沙漠的尽头出现了一个绿洲。这儿是南疆难得一见的草原。草原上的夜
晚，天很高、很蓝，星星很亮，青草和小花散播著芳香。隐隐约约随风声飘来
天铃鸟的歌声。这里居住着哈萨克人, 以放牧羊群为生。灌木丛中有一眼坎儿
井。井台上有一个木杯专供口渴的行人喝水。井边是一块瓜地。
LONG
        );
        set("resource/water", 1);
        set("exits", ([
                "westup" : __DIR__"huijiang2",
                "southwest" : __DIR__"huijiang3",
                "northeast" : __DIR__"huijiang6",
                "north" : __DIR__"huijiang7",
        ]));
        set("objects", ([
            __DIR__"npc/yang" : 3,
            __DIR__"npc/su" : 1,
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
            message("vision", me->name()+"趴在坎儿井的井台上用木杯舀了一杯水喝。\n"
            , environment(me), ({me}) );
            write("你喝了一口井中从天山上流淌下来的雪水，简直比蜜还甜。\n");
        }
        else write("逮着不要钱的水就这么喝，至于吗?\n");
        return 1;
}
