#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
        set_name(HIG "玉竹杖" NOR, ({ "yuzhu zhang", "yuzhu", "zhang" }));
        set_weight(26000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", HIG "这是一根绿玉所制的杖，乃是丐帮历代相"
                            "传的帮主信物。\n" NOR);
                set("unit", "根");
                set("value", 8000);
                set("treasure", 1);
                set("material", "steel");
                set("wield_msg", HIG "$N" HIG "从背后抽出一根绿玉所制"
                                 "的手杖，凌空舞了个圈子。\n" NOR);
                set("unwield_msg", HIG "$N" HIG "微微一笑，将手中的玉"
                                 "竹杖插回背后。\n" NOR);
                set("stable", 100);
        }
        init_staff(600+random(320));
        setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        switch (random(6))
        {
        case 0:
                n = me->query_skill("staff");
                victim->receive_damage("qi", n);
                victim->receive_wound("qi", n);
                return HIG "$N" HIG "将手中玉竹杖一振，登时幻出层层杖影，向逼$n"
                       HIG "而去！\n" NOR;
        }
        return damage_bonus;
}
