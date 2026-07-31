//Cracked by Roath
#include <armor.h>
#include <ansi.h>
inherit HEAD;

string* titles = ({
        "Éºº÷¶úÊÎ",
        "Éºº÷¶úÊÎ",
        "Éºº÷¶úÊÎ",
        "Éºº÷¶úÊÎ",
        "Éºº÷¶úÊÎ",
        "Éºº÷¶úÊÎ",
        "Éºº÷¶úÊÎ",
        "Éºº÷¶úÊÎ",
        "Éºº÷¶úÊÎ",
        "Éºº÷¶úÊÎ",
});

void create()
{
        int i;
        i = random(sizeof(titles));
        if (i<2)
        set_name(HIW+titles[i]+NOR, ({ "coral earring", "earring"}));
        else if (i<4)
        set_name(HIM+titles[i]+NOR, ({ "coral earring", "earring" }));
        else if (i<6)
        set_name(HIR+titles[i]+NOR, ({ "coral earring", "earring" }));
        else if (i<8)
        set_name(HIB+titles[i]+NOR, ({ "coral earring", "earring" }));
        else
        set_name(HIY+titles[i]+NOR, ({ "coral earring", "earring" }));

        set("weight", 50);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "¶Ô");
                set("value", 24000);
                set("long", "Ò»¶ÔÉºº÷¶úÊÎ£¬ÆäÉÏÉÁË¸ÖøÃÀÀö¶¯ÈËµÄ¹â²Ê¡£\n");
                set("material", "diamond");
                set("armor_prop/armor", 6);
				set("female_only", 1);
        }
        setup();
}