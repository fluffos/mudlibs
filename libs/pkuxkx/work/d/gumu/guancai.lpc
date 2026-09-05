inherit ROOM;




void create()
{
 set("short", "棺材");
 set("long", @LONG
这是一口不大不小的棺材，好象没什么特别。
LONG
 );
   set("objects",([
  __DIR__"obj/marrycth" : 1,
]));
 set("exits", ([
 "out" : __DIR__"gumu",
 ]));
	set("hsz_no_task",1);
	set("no_task",1);
	set("no_dbr_stage",1);	
setup();
}
void init()
{  add_action("do_out","out");
  }
 
 int do_out(string arg)
{
   object me;
   me=this_player();
    if (!arg||arg=="") return 0;
    if (arg=="guancai")
    {
     message("vision", me->name() + "突地不见了\n", 
     environment(me), ({me}) );
                me->move(__DIR__"midao/rukou");
                message("vision",
     me->name() + "走了过来 \n",
                environment(me),({me}) );
     return 1;
  }
}
