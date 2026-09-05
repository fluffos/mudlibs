// meigui-hualu.c 玫瑰花露

#include <ansi.h>

inherit ITEM;


void init()
{
	add_action("do_eat", "eat");
}

void create()
{

     set_name("玫瑰花露",({"meigui hualu","meigui","hualu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
     set("unit","粒");
     set("long","这是阿朱姑娘精心配置的一粒极具灵效的玫瑰花露，能补助体力。\n");
		set("value", 2000);
		set("no_drop", "这样东西不能离开你。\n");
	}

       set("taohuadao",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	int i,j,l;
	i = me->query("max_qi");
	j = me->query("max_jing");
	l = me->query("max_neili");
	if(me->query("family/family_name")!="姑苏慕容")
	{
		write("想偷吃我们姑苏慕容家的东东，不害臊吗？\n");
		return 1;
	}
	if (!id(arg)) return notify_fail("你要吃什么？\n");

	if ((me->query("qi") == me->query("max_qi"))
		&&(me->query("jing") == me->query("max_jing"))
		&&(me->query("neili") == me->query("max_neili")))
     return notify_fail("你现在不需要玫瑰花露.\n");
      else
	{
	me->set("eff_qi",i);
	me->set("eff_jing",j);
	me->set("eff_neili",l);
	me->set("qi",i);
	me->set("jing",j);
	me->set("neili",l);
    message_vision(RED "$N吃下一粒玫瑰花露，顿觉精神百倍.\n",this_player());
	destruct(this_object());
      return 1;
	}


}

