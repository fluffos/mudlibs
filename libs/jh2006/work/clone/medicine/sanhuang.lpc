#include <ansi.h>
inherit COMBINED_ITEM;

void create()
{
   set_name("三黄宝腊丸", ({"baola wan", "sanhuang","baola", "wan"}));
   if (clonep())
      set_default_object(__FILE__);
   else {
      set("value", 15000);
      set("unit", "些");
      set("heal_up", 1);
      set("long","这是一粒武当派所制的伤药，内含麻黄、雄黄、藤黄三黄。\n");
      set("base_value", 15000);
      set("base_unit", "粒");
      set("base_weight", 20);
   }
   set_amount(1);
}

int init()
{
   add_action("do_eat", "fu");
}

int do_eat(string arg)
{

   if(!id(arg))
       return notify_fail("你要吃什么？\n");

   if ((int)this_player()->query("eff_qi") == 
       (int)this_player()->query("max_qi"))
           return notify_fail("你现在不需要用三黄宝腊丸。\n");
   else {
        this_player()->receive_curing("qi", 200+random(200));
        message_vision("$N服下一粒三黄宝腊丸，脸色开始由青转红。\n", this_player());
        add_amount(-1);
        return 1;
        }
}
