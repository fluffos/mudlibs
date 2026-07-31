// dujing.c 毒经

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("毒经",({"wangnangu dujing","dujing","jing"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else{
        	set("unit", "本");
        	set("long","这是一部手写的抄本，题签上写着“王难姑毒经”五字。翻将开来,书页上满是蝇头小楷，密密麻麻的写着
诸般毒物的毒性、使用和化解之法。这下碰上驱毒(qudu)、下毒(xiadu)的事，不着急了吧?\n");
        	set("value", 10000);
        	set("material", "paper");
       //	set("unique", 1);
        	//set("treasure",1);
             set("dzd",1);

	}
	setup();
}

void init()
{
	add_action("do_qudu","qudu");
	add_action("do_xiadu","xiadu");
}

int do_qudu(string arg)
{
	object ob;
	object me = this_player();
	if(!arg) ob = this_player();
	else 
		{
			if(!objectp(ob = present(arg, environment(me))))
				return notify_fail("你要给谁驱毒？\n");
			if (!ob->is_character() || ob->is_corpse())
				return notify_fail("看清楚一点，那并不是活物。\n");
		}
	if( ob->is_fighting() )
		return notify_fail("你无法在战斗中运功疗毒。\n");
		
	if( !mapp(ob->query_conditions_by_type("poison"))  )
	  return notify_fail(ob->query("name")+"并没有中毒。\n");
	if(me==ob) 
		message_vision(HIW"$N端坐在地，依照经书中的方法，慢慢的将体内的毒驱出体外。\n"NOR,me);
	else
		message_vision(HIW"$N端坐在地，依照经书中的方法，慢慢的将$n体内的毒驱出体外。\n"NOR,me,ob);
		//nomask mapping query_conditions_by_type(string required_type)
		//nomask void clear_conditions_by_type(string required_type)
		ob->clear_conditions_by_type("poison");		
		me->start_busy(1);
		ob->start_busy(2);
		return 1;			
}

int do_xiadu(string arg)
{
	object ob;
	object me = this_player();
	
	if( me->is_busy()) return notify_fail("你现在正忙着呢。\n");	
	if(me->query_temp("dzd_quest/used_dujing"))	
		return notify_fail("你已经下毒了。\n");	
	if(!arg)
		return notify_fail("你要给谁下毒？\n");
	if(!objectp(ob = present(arg, environment(me))))
		return notify_fail("你要给谁下毒？\n");	
	if (!ob->is_character() || ob->is_corpse())
		return notify_fail("看清楚一点，那并不是活物。\n");
				
	me->set_temp("dzd_quest/used_dujing",1);
	remove_call_out("out_xiadu");
	call_out("out_xiadu",10,me);
	message_vision(HIB"$N嘿嘿一笑，将按毒经所说炼制出来的毒粉偷偷向$n撒去。\n"NOR,me,ob);
	if(random(4)) {
		message_vision(HIY"$N一时不察，已经身中剧毒！\n"NOR,ob);
		ob->add_condition("snake_poison",20);		
	}
	else 
		message_vision(HIY"谁知$N早有准备，侧身躲过了暗算！\n"NOR,ob);
	me->start_busy(1);
	return 1;
}

void out_xiadu(object me)
{
	if(!me) return;
	me->delete_temp("dzd_quest/used_dujing");
}