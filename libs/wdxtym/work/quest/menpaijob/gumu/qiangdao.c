//snowman 28/02/98
#include <ansi.h>
inherit ITEM;
int j=3;
void create()
{
        set_name("蒙古军队", ({ "mengurenma"}));
        set("unit", "只");
        set_weight(90000000);
        set("long", "
一只远道而来的蒙古军队，看来有不少高手。中间插
着一面大旗，似乎写着“蒙古护教法王”二个大字。。。\n");
        set("no_get", 1);
        set("no_drop", 1);
	 set("no_put",1);
}

void init()
{ remove_call_out("aaa");
  call_out("aaa", 120, this_object());  
  add_action("do_rob", "qianru");
}

int do_rob()
{
   object me, ob;   
   string arg;
   int stage, i;
   me = this_player();
   ob = this_object();
   stage = 0;
   arg = query("arg");

   if(!living(me)) return 0;
   if(!me->query("kill_gumu")) 
       return notify_fail("你胆子不小，竟敢在蒙古大军做对？\n");

   message_vision(HIY"$N一纵身,潜入了$n !!"+me->name()+"开始潜入蒙古大军内！\n"NOR, me, ob);
   me->set_temp("xx_rob", 1);
   remove_call_out("make_bs");
   call_out("make_bs", 6, me, ob); 
   return 1;     
}
void make_bs(object me, object ob)
{
    object *obn,room,obt;
    int i;
    me = this_player () ;
    ob = this_object() ;

    if(!( room = find_object("/quest/menpaijob/gumu/mengu")) )
          room = load_object("/quest/menpaijob/gumu/mengu");

if (!present("yuanshuai", room))
{
	obt = new("/quest/menpaijob/gumu/guan");
	obt->move(room);
	obt->set("startroom", base_name(room));
}

       me ->move(room) ;
        obn = all_inventory(environment(me));
      for(i=0; i<sizeof(obn); i++)
      if( obn[i]->is_character() && obn[i]!=me
      && obn[i]->query("id")=="yuanshuai" )
{
    message_vision(HIW"你终于发现了这队蒙军的意图了。\n"NOR, me);
    destruct(ob);
}

message_vision(HIG"你找了半天，好像没找到什么!只好逃了出来!!\n"NOR, me);
me->delete("kill_gumu");
me->delete("kill_gumu");
me->apply_condition("gumu_busy",0);
me->move("/d/xiangyang/southgate2");

    destruct(ob);
}

void aaa(object me)
{
       message_vision("$N转过几个小山丘就不见了。\n",me);       
       destruct(me);
       return;
}

