// Room: fanting.c
inherit ROOM;
string* names = ({
"/d/murong/obj/tianbing","/d/murong/obj/gao","/d/murong/obj/oufen",
});
void create()
{
        set("short", "饭厅");
        set("long", @LONG
这里是神龙教弟子就餐的地方。饭厅不大，放了几张桌椅。
几个弟子正在布菜，看样子马上就要开饭了。也许你可以坐(zuo)下来吃(eat)喝(drink)点什么。
LONG
        );
        set("resource/water", 1);
        set("exits", ([
                "north" : __DIR__"xiaoting",
        ]));
        set("objects",([
                "/d/shenlongdao/obj/shegeng" : 2,
                names[random(sizeof(names))]: 1,
                names[random(sizeof(names))]: 1,
                names[random(sizeof(names))]: 1,
        ]));
        setup();
//        replace_program(ROOM);
}


void init()
{
    add_action("do_full","eat");
    add_action("do_full","drink");
    add_action("do_full","zuo");
        
}

 int do_full()
{
   
   object me=this_player();
   if((int)me->query("water")>=(int)me->max_water_capacity() || (int)me->query("food")>=(int)me->max_food_capacity())
                return notify_fail("你真是猪啊，吃那么多，你不怕撑死吗？\n");
   message_vision("$N觉得似乎有些饿，就坐在桌子旁边，狼吞虎咽的吃了起来。\n",me);
   me->set("food",me->max_food_capacity());
   me->set("water",me->max_water_capacity());
   message_vision("$N吃饱喝足，站了起来，感觉都肚子吃撑了。\n",me);
   me->start_busy(5);
  return 1;
}

