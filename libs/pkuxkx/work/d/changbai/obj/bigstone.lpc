//大石头
//by steel
#include <ansi.h>
inherit ITEM;

void create()
{
  set_name("大石头",({"big stone","stone"}) );
  set("unit","块");
  set("long",
     "这是一块平平整整的大石，上面好象有一个刀状的孔(hole)。\n");
  set("no_get",1);
  set_weight(5000);
  set_max_encumbrance(8000);

  setup();
}
int is_container()
{
   return 1;
}

void init()
{
  add_action("do_turn","turn");
}
int do_turn(string arg)
{
   object blade, evn, *ob, stone, me;
   stone = this_object();
   me = this_player();

   if(!arg)
   return notify_fail("你要扭甚么呀?\n");

   if(arg == "blade" || arg =="baodao" || arg="闯王宝刀")

   {
   	evn = environment();
   	if(evn != environment(this_player())) return 0;

   	ob = all_inventory(stone);
   	if(sizeof(ob)!=1) return notify_fail("你放的东西不太合适，无法转动机关。\n");
   	blade = ob[0];

     	if((string)blade->query("id") != "chuangwang baodao")
   	return notify_fail(HIW"你放的东西不太合适，无法转动机关。\n"NOR);

   if((int)me->query("neili")<=1000)
   {
   	tell_object(me, YEL"你的内力不足了,恐怕转不动机关!\n"NOR);
   	me->set("neili",0);
   	return 0;
   }
   	me->add("neili", -1000);
   	message_vision(HIR"\n$N运足内力,大喝一声:起!!!....\n\n"NOR, me);
   	write("只听“喀”的一声，闯王宝刀已断！\n随即轰隆一声巨响,巨石缓缓转动,露出一个小洞。\n\n");

	destruct(blade);
   	//me->move("/d/changbai/midong");
	evn->set("exits/down", "/d/changbai/midong");
 	return 1;
  }
  else
  return notify_fail("你要扭动什么？\n");
}
/*
int close_midong()
{
  object evn,midong,stone;
  stone=this_object();
  evn=environment(stone);
  message("vision","轰隆一声响，巨石又回到了原位。\n",evn);
  evn->delete("exits/down");
  midong = find_object("/d/changbai/midong");
  midong->delete("exits/up");
  message("vision","头顶上发出轧轧的响声，大概是出口合上了。\n", midong);
  return 1;
}
*/
