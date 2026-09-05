//shenshe.c
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("引路神蛇", ({ "shenshe"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "一条有识路能力的神蛇，可以把主人带到白驼山。(指令：gohome)\n");
		set("unit", "条");
		set("value", 0);
                set("usetime", 3);
	}
}
void init()
{
 add_action("do_home","gohome");
}
int do_home()
{
    object me = this_player();
   if(!wizardp(me)&&me->query("family/family_name") != "白驼山")
	  return notify_fail("你不是白驼山派弟子，「引路神蛇」不听你使唤。\n");
   message_vision(HIG"$N从怀中掏出「引路神蛇」，口里不知念了些什么，\n
   就见「引路神蛇」吐吐芯子，摇头摆尾地把$N往白驼山带去~~~\n"NOR,me);
   me->move("/d/baituo/damen");
   this_object()->add("usetime",-1);
    if(this_object()->query("usetime")<1)
    {
           message_vision(HIG"「引路神蛇」吐吐芯子，钻入草丛不见了。\n"NOR,me);
           destruct(this_object());
    }
   return 1;
}
