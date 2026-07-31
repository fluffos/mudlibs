//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
#include <ansi.h>
inherit ITEM;
void init();
void create()
{
        set_name(HIM"令牌"NOR, ({"lpa"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一块奇怪的令牌(lpa)，打破(dapo)它可以进入封魔塔。\n");
                set("value", 1);
                set("material", "paper");
        }
        setup();
}

void init()
{
    set("no_get",1);
    set("no_give",1);
    set("no_drop",1);
    set("no_sell",1);
  add_action("do_dapo", "dapo");
}

int do_dapo(string arg)
{
  object me = this_player();
  object ob;

  if (arg!="lpa")   return 0;
     ob = new("/data/hell/fengmota/npc/guiwang");
        ob->move(environment(me));
        message_vision(CYN"$N打破令牌，你面前忽然出现一道模糊不清的身影。\n",me);  
        write("塔灵道：“欢迎来到封魔塔，挑战者。”\n");
		write("塔灵道：“我是封魔塔的塔灵，想要进入封魔塔必须妖经过我的考验。”\n");
        write("塔灵道：“你准备好了码？让我们开始吧！！！”\n"NOR);
        destruct(this_object());
        return 1;
}

