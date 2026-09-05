//disassemble zine@pkxuxk 2014/7/21 拆解武器
#include <ansi.h>
inherit F_DBASE;
int disassemble(object me,object ob,int suc)
{
	object new_ob;
	int rigid_loss=1+random(2)+me->query_skill("components")/10,sk_pts;
	if (!me||!living(me)) 
	return 1;
	if (!ob||environment(ob)!=me)
	{
		tell_object(me,"你要拆解东西不知去向，你也不知道该怎么办了。\n");
		return 1;
	}
	if (!suc)
	{
		message_vision(MAG+"$N"+MAG+"将$n"+MAG+"完全拆解开来了。\n"+NOR,me,ob);
		new_ob=new("/obj/smith/products/parts");//need an object
		new_ob->set("long","这是一堆"+ob->query("name")+"拆解开了的散落部件。\n");
		new_ob->set_weight(ob->query_weight());
		new_ob->move(me);
		destruct(ob);
		return 1;
	}
	else
	{
		sk_pts=ob->query("level");
		if (ob->query("rigidity")<rigid_loss)
		{
			message_vision(MAG+"$N"+MAG+"将$n"+MAG+"完全拆解开来了。\n"+NOR,me,ob);
			new_ob=new("/obj/smith/products/parts");//need an object
			new_ob->set("long","这是一堆"+ob->query("name")+"拆解开了的散落部件。\n");
			new_ob->set_weight(ob->query_weight());
			new_ob->move(me);
			destruct(ob);
		}
		else
		{
			if (!ob->is_parts())
			{
				new_ob=new("/obj/smith/products/fake_weapon");
				new_ob->set_name(ob->query("name"),ob->parse_command_id_list());
				new_ob->set("rigidity",ob->query("rigidity"));
				new_ob->set("long","这是一"+ob->query("unit")+ob->query("name")+"，它已经被拆解下了部分零件。\n");
				new_ob->set_weight(ob->query_weight());
				new_ob->set("unit",ob->query("unit"));
				new_ob->set("level",ob->query("level"));
				destruct(ob);
				ob=new_ob;
				ob->move(me);
			}
			ob->add("rigidity",-rigid_loss);
			message_vision(MAG+"$N"+MAG+"将$n"+MAG+"的一部分部件拆解开来。\n"+NOR,me,ob);
		}
		me->add_temp("weapon_cast/disassemble",1);
		if (me->query_temp("weapon_cast/disassemble")%6==0&&me->query_temp("weapon_cast/disassemble")!=0)
		{
			if (me->query_skill("components",1)>me->query_skill("smithing",1)*13/10)
			{
				tell_object(me,"受限于你的锻造术，你的装备结构知识无法再提升了。\n");
				return 1;
			}
			me->improve_skill("components",1+random(sk_pts)+sk_pts/2);
		}
		return 1;
	}
}
int main(object me, string arg)
{
	object ob;
	int lv,rigidity,sk_lv=1+me->query_skill("components",1)/10,suc=1;
	if (!me->query("weapon_cast/disassemble"))//need a book
	return notify_fail("你完全没有装备结构方面的知识，去找本书学习一下吧。\n");
	if (me->is_busy())
	return notify_fail("你正忙着呢。\n");
	if (!arg)
	return notify_fail("你要拆解什么装备？\n");
	if (!ob=present(arg,me))
	return notify_fail("你身上没有"+arg+"这样装备。\n");
	if ((!ob->is_gems()||ob->is_gem())&&!ob->is_parts())
	return notify_fail(ob->name()+"既不是随机装备，也不是玩家打造的装备，不能拆解用于提升装备结构方面的知识。\n");
	if (ob->query("gem_ob_autoloaded"))
	return notify_fail(ob->name()+"是自动加载武器，拆了可就没了。\n");
	lv=ob->query("level");
	rigidity=ob->query("rigidity");
	if (rigidity<1)
	return notify_fail(ob->name()+"已经损坏了！\n");
	if (lv-2>sk_lv)
	{
		message_vision("$N对着$n完全无从下手。\n",me,ob);
		return notify_fail(ob->name()+"的复杂程度超出了你的能力。\n");
	}
	message_vision(HIM"$N"+HIM+"开始动手拆解$n"+HIM+"。\n"NOR,me,ob);
	if (lv<sk_lv)
	{
		suc=0;
		write("你已经从这个级别的装备拆解上学不到任何东西了。\n");
	}
	me->add_busy(3);
	call_out("disassemble",3,me,ob,suc);
	return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : disassemble <装备>
让你拆开随机或玩家打造装备，获得装备构造知识的提升。
HELP
);
        return 1;
}

