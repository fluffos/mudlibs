#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(BNK"经验"NOR, ({ "exp" }));
     set_weight(100000);
                set("food_remaining", 2);
             set("food_supply", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "万");
                set("value", 1);
                set("material", "paper");
                set("long",
                        HIY"这就是mud人人都想要的"+BNK"经验!\n"NOR);
            }
}
void init()
{
//   add_action("do_use","use");
}
int do_use()
{
object me;
int exp_plus;
me=this_player();
exp_plus=me->query("combat_exp")/100;
if(exp_plus<1) exp_plus=1;
if(random(2)==1)
me->add("combat_exp",exp_plus);
else
me->add("combat_exp",0-exp_plus);
message_vision(HIW"$N感到自己的经验有所变化!\n"NOR,me);
return 1;
}
