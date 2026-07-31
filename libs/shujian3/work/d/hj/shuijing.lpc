// shuijing.c
inherit ROOM;

void create()
{
        set("short", "坎儿井");
        set("long", @LONG
山丘下灌木丛中有一眼坎儿井，是牧民们的水源。井台上有一个木杯专供
口渴的行人喝水。井边有一个由人踏动的水车，水渠从这里一直连到了东边的
马厩。
LONG);
        set("resource/water", 1);
        set("exits", ([
                "eastup" : __DIR__"caochang",
                "southwest" : __DIR__"room-su",
                "northeast" : __DIR__"pmchang",                
        ]));
        set("objects", ([
               FOOD_D("hamigua") : 2
        ]));
        set("coor/x",-330);
  set("coor/y",90);
   set("coor/z",0);
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
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"趴在坎儿井的井台上用木杯舀了一杯水喝。\n"
            , environment(me), ({me}) );
            write("你喝了一口井中从天山上流淌下来的雪水，简直比蜜还甜。\n");
        }
        else write("你再也喝不下了。\n");
        return 1;
}
