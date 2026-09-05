inherit ROOM;
void create()
{
        set("short", "平西王秘藏宝库");
        set("long", @LONG
这就是吴三桂藏宝秘室，这里藏着他的全部宝物与秘密．
地上放着一个精美的檀木柜子(cabinet)，柜门上系着一根细线．
LONG
        );
        set("exits", ([ 
 "up" : __DIR__"secret2",
  ]));
     set("objects", ([
                        ]) );

        set("count",1);
		set("no_newbie_task",1);
             setup();
}
void init()
{
     add_action("do_open","open");
    
} 
int do_open(string arg)
{ object me,cock;int i,mount;
   me=this_player();mount=random(3)+2;
  me->save();
 i=me->query("openbox");
if (!arg||arg != "cabinet") 
{write("你要打开什么?\n");return 1;}
if (( (int)me->query("marks/open_cabbit" )+20000 > (int)me->query("mud_age") )|| (this_object()->query("count") == 0) )
{write("你前不久才来拿过东西，现在又来拿太贪心了吧，至少要过几天.\n");return 1;}
if ( me->query("combat_exp") < 300000 )
{
    message_vision("$N用力一搬，结果因为经验不够，怎么也开不开柜子。\n",me);
    tell_object(me,"又想走私？hehe......\n");
    return 1;
}
if(!(i))
 {message_vision("$N想打开柜子，但是细线连着的警铃响了起来，冲进来几个拳师．\n" ,me);
 me->set("openbox",1);  
 for(i=1;i<=mount;++i)
 {cock=new(__DIR__"npc/huyuan");
   cock->move(this_object());
   cock->kill_ob(me);}
cock=new(__DIR__"npc/huyuantou");
 cock->move(this_object());
cock->command("guard up");
 cock->kill_ob(me);
return 1;
  }
else
{
/* if ( me->query("combat_exp") < 300000 )
{
    message_vision("$N用力一搬，结果因为经验不够，怎么也开不开柜子。\n",me);
    tell_object(me,"又想走私？hehe......\n");
    return 1;
}
*/
i=random(5);me->set("openbox",0);me->set("permit",0);
me->set("marks/open_cabbit",me->query("mud_age"));
  switch(i)
{
  case 0:  cock=new(__DIR__"obj/yangqiang");break;
 case 1: cock=new(__DIR__"obj/dagger");break;
case 2: cock=new(__DIR__"obj/baojia");break;
 case 3: cock=new(__DIR__"obj/herobook");break;
case 4: cock=new("/d/beijing/npc/obj/book42_4"); break;
 }
 message_vision("$N用力一搬,打开了柜子，一样东西落了出来．\n",me);
cock->move(this_object());
set("count",0);
return 1;
 }
}


int valid_leave(object me, string dir)
{
if ((dir == "up") && (present("hu yuantou",environment(this_player()))))
{
    return notify_fail("护院总武师正看守着这个方向，你上不去！\n");
}
if ((dir == "up")&&((!present("baihe hua",this_player()))||(me->query("neili")<2000)))
{
if((me->query("neili")>4500))
{
     write("你暴喝一声,内力自丹田源源涌出,终于冲了出去!\n");
me->add("neili",-500);
return ::valid_leave(me, dir);
}
else {return notify_fail("一股阴冽的寒气向你逼来,尽管你运起全身功力与之对抗,还是被挡了回来!\n");
}
}
else {write("你暴喝一声,内力自丹田源源涌出,终于冲了出去!!!\n");
        return ::valid_leave(me, dir);
}
return notify_fail("一股阴冽的寒气向你逼来,尽管你运起全身功力与之对抗,还是被挡了回来!\n");
        return ::valid_leave(me, dir);
}
