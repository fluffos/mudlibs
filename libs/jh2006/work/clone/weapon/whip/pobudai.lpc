// pobudai.c 破布袋

#include <weapon.h>
inherit WHIP;
inherit F_UNIQUE;

void create()
{
        set_name("破布袋", ({ "po budai", "budai","bian" }));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个脏兮兮的破麻布袋，里面蠕蠕而动。\n");
                set("value", 10);
                set("unique", 1);
                set("material", "cloth");
                set("rigidity", 4);
                set("weapon_prop/parry", 2);
                set("treasure",1);
                set("wield_neili", 500);
                set("wield_maxneili", 900);  
                set("wield_str", 22);
                set("wield_msg", "$N从怀里掏出一团破布，抓在手中当兵器。\n");
                set("unwield_msg", "$N将手中的$n折一折，放进怀里。\n");
        }
        init_whip(50);
        setup();
}
