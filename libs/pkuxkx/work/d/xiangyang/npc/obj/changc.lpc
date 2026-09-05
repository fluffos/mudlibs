#include <ansi.h>
inherit ITEM;
void init()
{
  add_action("do_eat","eat");
}

void create()
{
  set_name(HIR"长春散"NOR,({"changchun san","san"}));
  set_weight(80);
 if (clonep())
		set_default_object(__FILE__);
     else {
                    set("long","这是一丸鲜红的丹药，据说可以让人长生不老.  \n");
             set("unit","粒"); 
		set("value", 80);
	}
       setup();
}
int do_eat()
{
 object me=this_player();
   me->add("max_neili",5);
   me->add("max_jingli",5);
   me->add("jingli",25);
   me->add("neili",25);
 message_vision(HIR"$N见了丹药，立即一口就吞了下去，连什么味道都没尝出来!\n"NOR,this_player());
destruct(this_object());
return 1;
}
