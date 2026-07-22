#include <armor.h>
#include <ansi.h>
#include <mudlib.h>
inherit FINGER;
void create()
{
         set_name(HIW"逍遥指"NOR, ({ "xiaoyao ring", "ring" }));
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                  set("long", "这是一枚增加防御力的戒指，防御力增加800，下线不掉。\n"NOR); 
              set("unit", "个");
              set("jym_money",3);
	      set("no_put",1);
              set("no_sell",1);
              set("no_get", 1);
              set("no_give", 1);
              set("no_drop",1); 
              set("material", "gold");
              set("armor_prop/armor", 800);
        set("armor_prop/intelligence", 20);

        }
        setup();
}       