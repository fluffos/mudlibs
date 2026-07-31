//cave1.c 洞口
inherit ROOM;
void create()
{
          set("short","洞口");
          set("long",@LONG
越过鳄鱼潭，见到一个洞口（dong），里面漆黑一片，鼻中只隐约闻到一
股刺鼻的气味。洞口极窄，看样子只得屈膝爬行了。
LONG
);
           set("item_desc",([
             "dong":"这洞里黑漆漆的一片，什么都看不到。\n",
           ]));        
          
           setup();
}

void init()
{
          add_action("do_enter","zuan");
          add_action("do_enter","enter");
}
          
int do_enter(string arg)
{
       object me = this_player();
       if(! arg || arg !="dong") return 0;
       if (me->is_busy() || me->is_fighting())
            return notify_fail("你正忙着哪！\n");
       if (arg == "dong") {
               message("vision", me->name() + "一个溜身，钻进了山洞。\n", environment(me), ({me}));
               write("你急急忙忙的钻进了洞里，头撞上了山石，直痛你得哇哇大叫。\n");
               me->move(__DIR__"cave2");
               message("vision", me->name() + "钻了进来，头部撞到了山石上。\n", environment(me), ({me}));
               return 1;
       }
       return notify_fail("你往哪里钻啊？\n");       
}
