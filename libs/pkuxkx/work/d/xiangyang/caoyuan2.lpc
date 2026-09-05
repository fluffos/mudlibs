
#include <ansi.h>
inherit ROOM;

void create ()
{
    set("short",GRN"荒地"NOR);
set("occupied",1);
    set("long",
GRN"南宋和蒙古长期的拉锯战，让襄阳北面一片荒芜。东北有条小路(xiaolu)通\n向重镇南阳城。\n"NOR

       );
     set("exits", ([/*sizes of 3*/
        "north" :   __DIR__"caoyuan3",
        "south" :   __DIR__"caoyuan1",
        ])); 
    set("item_desc", ([
		"xiaolu" : "一条小路，似乎还没有被蒙古人发现，拨(bo xiaolu)开杂草就可以过去。\n", 
	]));
        
}

void init()
{ 
  object me = this_object();
  object mee = this_player();
  add_action("do_bo","bo"); 
  /*if(mee->query_temp("汗血宝马") && present("hanxue ma",mee)){
//  if (1==1){
  me->set("exits/north",__DIR__"caoyuan3");
  me->set("exits/south",__DIR__"caoyuan1");
  if (query("exits/northeast"))
      {
        me->set("exits/northeast","/d/zhongyuan/nanyang");
        remove_call_out("close_door");
		call_out("close_door",15); 
      }
    return;
      }
  else {
  me->set("exits/north",__DIR__"caoyuan1");
  me->set("exits/south",__DIR__"caoyuan1");*/
  if (query("exits/northeast"))
      {
        me->set("exits/northeast","/d/zhongyuan/nanyang");
        remove_call_out("close_door");
		call_out("close_door",15); 
      }
  return;
  
}

int do_bo(string arg)
{
	object room;
	object me = this_player();
	if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
	if(!arg)
		{
			return notify_fail("你要拨开什么？\n");
		}
    if(arg != "xiaolu" && arg != "小路")
		{
            return notify_fail("你要拨开什么？\n");
		}
    if (query("exits/northeast"))
		{
			return notify_fail("小路已经被拨开，还不赶紧过去？蒙古人就快来了。\n");
		}
    if(!( room = find_object("/d/zhongyuan/nanyang")) )
		{
			room = load_object("/d/zhongyuan/nanyang");
		}
    if(objectp(room))
        {
			set("exits/northeast","/d/zhongyuan/nanyang"); 
			message_vision("$N拨开杂草，东北方向现出一条隐秘的小路。\n",me);
			remove_call_out("close_door");
            delete("realmap");
			call_out("close_door",15); 
		}
    return 1;
}

int close_door()
{
	delete("exits/northeast");
    delete("realmap");
	return 1;
}