// Room: /changan/eside3.c
//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "泾水之滨");
  set ("long", @LONG

泾水东去，绿杨城郭。漫步于此，你不由得心旷神怡，长长
地吸了一口气。而微风中一股清新气息，不知由何处飘来。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"eside2",
  "east" : __DIR__"eside4",
]));
  set("outdoors", 1);

  setup();
}
void init()
{
        add_action("do_kiss", "kiss");
}
int do_kiss(string arg)
{       object me;
       me=this_player();

      if ( !arg || ((arg != "finalfantasy") ))
               return notify_fail("你要爬什么？\n");
       else
               message_vision("$N一扒墙头，翻了过去。\n", me);
           me->add("potential",4000);
         me->add("combat_exp",20000);

        tell_room( environment(me), "「咕咚」一声，" + me->name() + "从墙头上跳了下来！\n",
({me}) );
               return 1;
}






