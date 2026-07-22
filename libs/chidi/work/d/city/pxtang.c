// by lonely
#include <ansi.h>
inherit ROOM;

void create()
{
set("short","辟邪山庄香堂");
set("long", @LONG
这里是辟邪山庄的香堂，所有准备加入辟邪山庄的人，必须先在这里参加入帮仪事,
饮血为盟，对天发誓，方可入帮．香堂的正中央放着会香(xiang)，供入会着使用的．
LONG);
    set("item_desc", ([
      "xiang" : "这是入会要点的会香，你可以pick xiang,dian baixiang,pushin baixiang来加入帮派！\n",
    ]) );
  set("objects", ([
"/d/player/xth/obj/xiangl" : 1,
]));
  set("exits", ([
"down" : __DIR__"wumiao",
]));
    set("no_fight", "1");
setup();
}
void init()
{
    add_action("do_pick", "pick");
}
int do_pick(string arg)
{
    object obn,me;
       me = this_player();
    if( !arg || arg!="xiang" )
      return notify_fail("你要拿什么？\n");
      obn = new ("/d/player/xth/obj/xiang");
       obn->move(me);
       message_vision("$N拿起一柱入会香。\n",me );
       return 1;
}
