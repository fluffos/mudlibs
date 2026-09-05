inherit ROOM;




void create()
{
 set("short", "棺材");
 set("long", @LONG
这是一口不大不小的棺材，好象没什么特别，
棺材底部好象是空的,下面有些蹊跷。
LONG
 );
//   set("objects",([
//  __DIR__"obj/marrycloth" : 1,
//]));
 set("exits", ([
 "out" : __DIR__"gumu",
 ]));

setup();
}
void init()
{ add_action("do_down", "down");
  }
 
 int do_down(string arg)
{
   object me;
   me=this_player();
 //   if (arg=="guancai")
	if(me->query("jiguan")!=1) return 0;
   else
 {
     message("vision", me->name() + "突地不见了\n", 
     environment(me), ({me}) );
                me->move(__DIR__"mishi");
                message("vision",
     me->name() + "走了过来 \n",
                environment(me),({me}) );
     return 1;
}
  }
