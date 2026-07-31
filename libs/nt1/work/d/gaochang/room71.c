// Room: /d/gaochang/room71.c// This is a room made by roommaker. write by Fan. :)
inherit ROOM;
void create()
{
        set("short", "小径");
        set("long", @LONG
道路不知已有多少年无人行走，有些地方长草比人还高，有些地方又
全被沙堆阻塞，四下如死一般的寂静，只有风吹过草梢的沙沙之声。偶尔
一两声狼嚎随着腥风飘至耳际。
LONG );
        set("exits", ([ 
  "northwest" : __DIR__"room71",
  "south" : __DIR__"room71",
  "southwest" : __DIR__"room71",
  "north" : __DIR__"room71",
  "northeast" : __DIR__"room71",
  "east" : __DIR__"room71",
  "southeast" : __DIR__"room72",
  "west" : __DIR__"room71",
]));

        setup();
}
void init()
{
    if ( userp( this_player() ) )
    call_out("kill_user",1,this_player());
}
int kill_user(object me)
{
   object ob;
   if (!me || environment(me)!=this_object()) return 1;
    if (!present("wolf",this_object())){
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    ob=new( __DIR__"npc/wolf");
    ob->move(this_object());
    message("vision","几条黑影突然向你扑来。\n",this_object());
    }
}
int valid_leave(object me, string dir)
{
    object ob;
    ob=present("wolf", environment(me));
    if ( ob && living(ob))
       return notify_fail("狼群挡住了你的去路。\n");
    else
        return 1;
}
