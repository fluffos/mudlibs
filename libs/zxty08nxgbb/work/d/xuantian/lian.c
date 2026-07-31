// Room: /d/huashan/sgyhole.c

inherit ROOM;

void create()
{
        set("short", "面壁间");
        set("long", @LONG
这里就是玄天派的面壁间了，你只见到四面的墙壁上都
雕刻着不同形状的人，演示着不同的轻功身法和拳脚招式。
LONG );
        set("exits", ([ 
            "west"     : "d/xuantian/xiaolu",
        ]));
        set("no_clean_up", 0);

        setup();
}
void init()
{
  if (userp(this_player()))
{
  if((string)this_player()->query("family/family_name")!="玄天派")
{
this_player()->move("d/xuantian/xiaolu");
message_vision("$N不是玄天派弟子，想面壁还是回家面吧。\n",this_player());
return;
}
}
        add_action("do_mianbi", "mianbi");
        add_action("do_out", "out");
}

int do_mianbi()
{
   object ob;
   int c_exp,c_skill;
   ob = this_player();

   c_skill=(int)ob->query_skill("literate", 1);
   if (c_skill <1500)
   {
      message_vision("$N的领悟力不够强，完全不能领悟到墙上的武功。\n",ob);
      return 1; 
   }

   if (ob->query("jing")<2000)
   {
      message_vision("$N太累了，在面壁下去只怕要晕倒。\n",ob);
      return 1; 
   }
     if (ob->query_skill("dodge", 1)>4100)
   {
      message_vision("$N觉得面壁已经不能对自己的武功进行提升了。\n",ob);
      return 1; 
   }

   message_vision(RED"$N盘膝坐下,面对着墙领悟武功，$N提升了自己的轻功。\n"NOR,ob);
   ob->improve_skill("dodge", (int)ob->query_skill("dodge", 1));
  ob->add("jing",-500);
   ob->start_busy(1);
   ob->move("d/xuantian/xiaolu");
   return 1;
}

int do_out(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="无名" )
        {
                message("vision",
                        me->name() + "一弯腰往洞里走了进去。\n",
                        environment(me), ({me}) );
                me->move("d/xuantian/lyj");
                message("vision",
                        me->name() + "从洞里走了进来。\n",
                        environment(me), ({me}) );
                return 1;
        }
}  

