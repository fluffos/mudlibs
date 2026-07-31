// 千紫豆夹
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","你手里一松，千紫豆荚从指间滑落！\n");
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIG "千紫豆荚" NOR , ({"qianzi doujia", "doujia","dou","jia"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "千紫藤上结出的豆荚,青青的。\n");
    set("value", 0);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="doujia" && arg!="qianzi doujia")   return 0;
  
 
  me->add("potential", 20000);
  message_vision(HIG "$N轻轻掰开一颗千紫豆荚送入嘴中，一时间满脸泛青。
只见$N行为怪异,但片刻之后$N看起来精神多了！\n" NOR, me);
  destruct(this_object());
  return 1;
}

