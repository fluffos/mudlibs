//Room: dgtsheshenya.c 睹光台舍身崖
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","睹光台舍身崖");
      set("long",@LONG
从卧云庵出来，这里是看日出、云海、佛光、神灯之地。台下深崖万丈，
陡彻无底，云遮雾掩。极目四望，数百里外的大小雪山皆历历在目。因为这里
至高至洁，至险至奇，又至美至幻，常有人在这里投身云海，舍此肉身尘世。
　　金顶云海，迷迷茫茫，笼罩四野，远接天际。云海轻荡时，你在金顶，脚
踏白云，大有飘飘欲仙之感；当云涛迅猛涌来时，整个金顶都似在向前浮动，
令人有乘舟欲风之意。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "enter"    : __DIR__"woyunan",
          "east"     : __DIR__"duguangtai", 
      ]));
      set("no_clean_up", 0);
      setup();
}
void init()
{
   object me;
   if( interactive( me = this_player())) remove_call_out("clone_ji");
       call_out("clone_ji", 2,me);
   add_action("do_sheshen","sheshen");
}
void clone_ji(object me)
{
   object *ob,obj;
   int i,j;

   if (!me)  return notify_fail("你已经断线了！\n");

   j=0;
   ob = all_inventory(environment(me));
   for(i=0; i<sizeof(ob); i++)
   {
      if ( (!userp(ob[i])) && ((string)ob[i]->query("id")=="ji xiaofu"))
      j=1;
   }
   if (!me)  return notify_fail("你已经断线了！\n");
   if (!this_object())  return notify_fail("你已经断线了！\n");
   if ((j==0) && (me->query("marks/ji")))
   {
      if( environment(me) == this_object()) obj=new("/kungfu/class/emei/ji.c");
if (!obj)   return notify_fail("你已经断线了！\n");
if (environment(me))
{
      obj->move(environment(me));
}
   }
}
int do_sheshen(object me)
{
	object *inv,kicker;
	int sizeinv,n,tt;

    me = this_player();
   if (!me)  return notify_fail("你已经断线了！\n");
   if (me->query("combat_exp") < 500000)  return notify_fail("你这点武功，跳下去肯定死！\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character()  )  
     				return notify_fail("你想下去拐卖人口？\n");
       		
		}

    message_vision("$N觉得活着太没意思了，决定舍身成仁。\n", me);
    message_vision("$N毅然跳出舍身崖，长声尖叫，凄厉的声音响彻山谷，随着$N的的下落也急剧向下拉长。\n", me);
    if (random(4)<1)
    {
        me->move(__DIR__"st0");
        me->unconcious();
    }
    else
    {
        command("chat 有人跳下舍身崖自杀了。\n\n");
//        me->move(__DIR__"st0");
        me->die();
    }
    return 1;
}

