inherit ROOM;

void create()
{
 set("short", "小溪");
 set("long", @LONG
    这是一终南山山洞中的一条小溪(river),\n
小溪不是很宽,但是你确不能看到底
LONG
 );

setup();
}
void init()
{
  add_action("do_swim","swim");
  add_action("do_edit", "orcworks");
  }
  
 int do_edit(string file)
 {
        ed(file);
        return 1;
 }
 
 int do_swim(string arg)
{
   object me;
   me=this_player();
    if (!arg||arg=="") return 0;
    if (arg=="river")
    {
     message("vision", me->name() + "扑通一声跳进小溪不见了\n", 
     environment(me), ({me}) );
                me->move(__DIR__"cliff");
                message("vision",
     me->name() + "从小溪里冒了出来 \n",
                environment(me),({me}) );
     return 1;
}
  }

