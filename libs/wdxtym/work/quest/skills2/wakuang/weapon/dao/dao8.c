// tulong-dao.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{

        set_name(HIC"无名刀"NOR, ({ "noming dao","noming","dao", "blade" }));
        set_weight(35000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("rigidity", 9);
                set("sharpness", 9);
                set("long", "这是一把浑身发黑的无名刀。\n");
                set("value", 3000);
                set("unique", 1);
                set("wield_msg", HIM"只见黑光一闪，$N手中已提着一把黑沉沉的大刀！\n"NOR);            
                set("unwield_msg", HIM"黑光忽灭，$n跃入$N怀中。\n"NOR);
                set("treasure",1);
        }
         init_blade(300);
        setup();
}
