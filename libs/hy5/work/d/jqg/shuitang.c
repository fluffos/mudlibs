// shuitang.c 水塘
// By River 99.5.25
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
           set("short",HIC"水塘"NOR);
	   set("long",@LONG
穿过竹林，突然一阵清香涌至，眼前无边无际的全是水仙花，原来地下是
浅浅的一片水塘，深不逾尺，种满了水仙，这花是原是南方之物，不知何以竟
会在关洛之间的山顶出现。
LONG
);
           set("outdoors","绝情谷");

           set("resource/water", 1);

	   set("exits",([
              "eastup": __DIR__"shanding",
              "westdown": __DIR__"qsroad",
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
        max_water = me->query("str")*10 + 100;
        if (current_water < max_water){
            me->set("water", current_water+30);
            message("vision", me->name()+"趴在溪边用手捧了一些水喝。\n",environment(me),({me}));
            write("你喝了一口从山上流淌下来的溪水，觉得舒服多了。\n");
        }
        else write("喝那么多的凉水，你不怕生病吗?\n");
        return 1;
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int valid_leave(object me, string dir,object *obj)
{
       object *inv = deep_inventory(me);
       if (dir == "eastup") {
           write("东面是一大片竹林，北方很少见长得这般茂密的竹林，数量之大，确实罕见。\n");
        obj = filter_array(inv,(:get_object:));        
        if ( random(me->query("kar")) > 12 && ! sizeof(obj))
           write(HIW"\n你缓缓在绿竹篁中穿过，闻到一阵阵淡淡花香，登觉烦俗尽消。\n\n"NOR);
            else {
             call_out("kicking", 0, me);
             tell_room(environment(me), me->name()+"往东边的"GRN"竹林"NOR"快步离开。\n"NOR, ({ me }));
             tell_room(environment(me), me->name()+"从水塘快步走了过来。\n"NOR, ({ me }));
             me->look();
             return notify_fail("");
             }
        }
        return ::valid_leave(me, dir);
}
void kicking(object me)
{
me->move(__DIR__"zhulin" + (random(6) + 1));
}
