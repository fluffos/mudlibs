// tulong-dao.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{

        set_name(HIM"ÖØÌú´óµ¶"NOR, ({ "da dao","dadao","dao", "blade" }));
        set_weight(35000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "±ú");
                set("rigidity", 9);
                set("sharpness", 9);

                set("value", 1000);
                set("unique", 1);



        }
         init_blade(300);
        setup();
}
