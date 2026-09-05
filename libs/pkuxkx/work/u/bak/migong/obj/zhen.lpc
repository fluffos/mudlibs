#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_AUTOLOAD;
inherit F_SAVE;
void setup()
{}
void create()
{
           set_name(HIY"木鱼捶"NOR, ({"xiuhua zhen","chui"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                 set("long", HIW"一把好像准备磨成针的木鱼捶。\n"NOR);
                set("value", 800000);
                set("no_get", 1);
                set("no_drop", 1);
                set("no_steal", 1);
                set("unit", "柄");
                set("material", "steel");
                set("rigidity", 300);
                set("auto_load", 1);
                  set("wield_msg", HIG"木鱼捶杀气隐现...\n"NOR);
                 set("unwield_msg", HIR"$N将木鱼捶瘪在腰间。\n"NOR);
        }
          init_sword(10000);
        seteuid(getuid());
        setup();
}
void init()
{

       add_action("do_promote", "promote");
}
string query_autoload()
{
     return query("name");
}
void autoload()
{}
