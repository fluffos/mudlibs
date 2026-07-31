// yuyou.c 鱼油

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("鱼油", ({"yu you", "yuyou","you"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块新鲜的鱼油，黄色而半透明，取自于在寒冷水域中生活的鱼身上。\n");
		set("unit", "块");
		set("value", 200);
		set("food_remaining", 1);
		set("food_supply", 60);
	}
}
void init()
  {
        add_action("do_eat", "eat");
        add_action("do_chi", "chi");
  }

int do_eat(string arg)
  {
        object me = this_player();
        object ob = this_object();
        if( !arg || arg != "yu you" || arg == "")
             return notify_fail("你要吃什么？\n");
        if( arg == "yuyou" || "yu you" || "you") 
    {
        message_vision(
        "$N只觉的鱼油滑溜无比，哧溜一下就咽了下去，\n$N咂了咂嘴，只觉得一丝暖意从腹中升了起来。\n",this_player());
        me->add("neili", 100);
        destruct(ob);
        return 1;
      }
  }
int do_chi(string arg)
  {
        object me = this_player();
        object ob = this_object();
        if( !arg || arg != "yu you" ||  arg == "")
             return notify_fail("你要吃什么？\n");
        if( arg == "yuyou" || "yu you" || "you") 
    {
        message_vision(
        "$N只觉的鱼油滑溜无比，哧溜一下就咽了下去，\n$N咂了咂嘴，只觉得一丝暖意从腹中升了起来。\n",this_player());
        me->add("neili", 100);
        destruct(ob);
        return 1;
      }
  }