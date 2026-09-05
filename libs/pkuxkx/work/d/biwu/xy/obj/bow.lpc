// shenbeigong 神臂弓
// created by zine

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
	set_name(HIR"神臂弓"NOR, ({ "shenbi gong","bow","gong"}));
    set_weight(14000);
	if( clonep() )
		 set_default_object(__FILE__);
    else 
		{
			set("unit", "柄");
			set("long", "这就是大宋的守城利器神臂弓，你可以用它来射(she)敌人。\n");
			set("value", 1);
			set("material", "steel");
			init_staff(random(15));
		}
	setup();
}

void init()
{
	add_action("do_shoot", ({ "she", "shoot"}));
}

int do_shoot(string arg)
{	object ob;
	object me=this_player();
	object sbg;
	if(!present("shenbi gong", me))
		{
			tell_object(me,"你身上有神臂弓吗？\n");
			return 1;
		}
    sbg=present("shenbi gong",me);
    if(sbg->query("equipped"))
		{if(me->is_busy() )
			{return notify_fail("你正忙着哪！\n");}
		else{if (!arg) 
				{return notify_fail("你要指定一个目标才能射。\n");}
			ob=present(arg,environment(me));
			if (query("used")) 
				{return notify_fail(HIY"你刚刚拉开过神臂弓，现在手臂酸软，无法再拉开弓弦。\n"NOR);}
			if(ob==me) 
				{if (me->query("qi")<=5000)
					{me->unconcious();
					message_vision(HIR"$N把神臂弓倒转，一箭射向自己脸颊。\n"NOR,me);
					sbg->set("used",1);}
				else{me->add("qi",-5000);
					me->add_busy(random(6));
					message_vision(HIR"$N把神臂弓拿反了，一箭射在自己肩头，血流不止。\n"NOR,me);
					sbg->set("used",1);}
				call_out("cooldown", 10, sbg);
				return 1;}
			if (!objectp(ob))
				{return notify_fail("这里没有你的目标。\n");}
			if (!living(ob))
				{message_vision(RED"$N残忍的射向了$n。\n"NOR,me,ob);
				ob->die();
				sbg->set("used",1);
				me->add_busy(random(6));
				call_out("cooldown", 10, sbg);
				return 1;}
			else{if (ob->query("qi")<=8000)
					{ob->unconcious();
					ob->kill_ob(me);
					ob->add_busy(random(2));
					me->add_busy(random(6));
					message_vision(HIW"$N对着$n举起了手中的"+this_object()->name()+"...\n"NOR,me,ob);
					message_vision(RED"$N一声惨叫，晕了过去。\n"NOR,ob);
					sbg->set("used",1);}
				else{ob->add("qi",-random(8000));
					ob->kill_ob(me);
					ob->add_busy(random(2));
					me->add_busy(random(6));
					message_vision(HIW"$N对着$n举起了手中的神臂弓...\n"NOR,me,ob);
					message_vision(RED"$N一声惨叫，一只巨箭插在了$N身上。\n"NOR,ob);
					sbg->set("used",1);}
				call_out("cooldown", 6+random(3), sbg);
				return 1;}}}
else
{return notify_fail(HIG"你根本就没有装备神臂弓，怎么射击？\n"NOR);}}
int cooldown(object sbg)
{
	this_object()->delete("used");
}

