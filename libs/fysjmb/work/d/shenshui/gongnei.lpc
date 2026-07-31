 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "水池");
        set("long", @LONG
这里的水更清更冷，突然间你觉得眼前一亮，你头冒出水面，发现自己
身在一个大水池里，原来这里的水跟外面是连着的，池水跟湖面相平，只见
水池的四周镶满了珍珠翡翠，显得十分富丽堂皇。
LONG
        );
   set("exits", ([ 
      "up" : __DIR__"rongdong",
   ]));
        set("coor/x",210);
        set("coor/y",12300);
        set("coor/z",0);
        setup();
} 
void init()
{
   add_action("do_dive", "dive");
} 
int do_dive()
{
   object me, room;
   me = this_player(); 
  message_vision("$N深吸一口气，一个猛子向下扎去。\n\n", me);
  room = find_object(__DIR__"gongmen");
  if(!objectp(room))  room = load_object(__DIR__"gongmen");
  me->move(room);
  message("vision", me->name()+"从洞中游了出来。\n", environment(me), me);
  return 1;
}      
