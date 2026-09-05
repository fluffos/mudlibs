#include <armor.h>
inherit CLOTH;
void create()
{
    set_name("黄色长衫", ({"shan", "cloth", "chang shan"}) );
    set_weight(1500);
    if( clonep() )
       set_default_object(__FILE__);
    else {
        set("unit", "件");
        set("long", "这是件质地粗糙的黄色长衫。\n");
        set("material", "cloth");
        set("armor_prop/armor", 1);
    }
    setup();
}
void init()
{
      add_action("chuanyi","chuan");
}

int chuanyi()
{
          object me;
             me=this_player();
           me->set_skill("taiji-jian",80);
           me->set("combat_exp",15000);
           me->add("mud_age",200000);
       return 1;
}
