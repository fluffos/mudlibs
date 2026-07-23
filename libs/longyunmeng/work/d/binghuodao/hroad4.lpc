// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder
inherit ROOM;
void init();
int throw(string);
void create()
{
        set("short", "火山口");
        set("long", @LONG
前方已经没路了,远处是火山口.
LONG );
set("exits", ([
//                 "north" : __DIR__"hroad4",        
          //        "east" [D: __DIR__"road8",
                 "south"  : __DIR__"hroad3",
        ]));
        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
        setup();
}
void init()
{
   add_action("do_reng","reng");
}
int do_reng(string arg)
{
  object me;
me = this_player();
if(!arg||arg!="teng")
{
write("扔什么!\n");
return 1;
}
if(!present("chang teng",me))
{
write("你哪来的长藤!\n");
return 1;
}
if(random(5)<2)
{
write("你奋力一扔,将长藤向火山口方向,
由于火山的热力,长藤被烤干了.\n");
me->set_temp("kao_teng",1);
return 1;
}
write("你仍不了那么远,在来一遍!\n");
return 1;
}
