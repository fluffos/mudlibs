//tianyuebing  中秋月饼(加50内力)
//Made By jason@mudnow.com
//2000-5.-6
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("先天再造丸",({"zaizaowan","wan"}));
        set("long","这是度每老先生亲自制作的先天再造丸(eat)\n");
        set("unit","个");
        set("no_drop",1);
        set("no_get",1);
        set("value",0);
        set("no_store",1);
       setup();
}

void init()
{
    add_action("do_eat","eat");
}

int do_eat(string arg)
{
    object me;
    me = this_player();
    if ( (int)me->query("wuyi/zaizaowan" ) > 0 ) return notify_fail("你已经拿过礼物了，为人不能贪得无厌，是不是？\n");
/*    if ( (int)me->query("marks/newyear2001" ) > 0 ) 
		return notify_fail("你已经吃过先天再造丸了，再吃会适得其反的!)\n");*/
	switch(random(4)) {  
	case 0 :             
message_vision(HIG"$N吃下一个先天再造丸,浑身觉得舒适异常,"+HIR"$N的先天属性增加了!\n"NOR,me);
        me->add("str",1);
							   break;
							case 1 :
message_vision(HIG"$N吃下一个先天再造丸,浑身觉得舒适异常,"+HIR"$N的先天属性增加了!\n"NOR,me);
        me->add("int",1);
							   break;
							case 2 :
message_vision(HIG"$N吃下一个先天再造丸,浑身觉得舒适异常,"+HIR"$N的先天属性增加了!\n"NOR,me);
        me->add("con",1);
							   break;
							case 3 :
message_vision(HIG"$N吃下一个先天再造丸,浑身觉得舒适异常,"+HIR"$N的先天属性增加了!\n"NOR,me);
        me->add("dex",1);
							   break;
							   
									 }    
 //       me->set("marks/newyear2001",1);
        me->set("wuyi/zaizaowan",1);
       destruct(this_object());
     return 1;
}
