#include <ansi.h>
#include <weapon.h>
inherit STAFF;
inherit F_UNIQUE;
void create()
{
        set_name(HIY "金刚降魔杵" NOR, ({ "xiangmo chu", "xiangmo", "chu","staff" }));
        set_weight(32000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", HIY + "这是一柄又粗又长的金杵，长达四尺，杵头碗口粗细，杵身金光闪闪，似是用纯金所铸。\n"NOR);
                set("value", 100000);
                set("unique", 1);
                set("rigidity", 8);
                set("material", "gold");
                set("weapon_prop/parry", 4);
                set("weapon_prop/dodge", -11);
                set("treasure",1);
                set("wield_neili", 1000);
                set("wield_maxneili", 2000);
                set("wield_str", 30);
                set("wield_msg", HIY"$N将金杵往上一抛，待杵落地之及，顺手一牵杵柄，牢牢将杵立在面前，威风凛凛！\n"NOR);
                set("unwield_msg", HIY"$N将金杵舞出一道金光，顺势插在身后。\n"NOR);
        }
        init_staff(120);
        setup();
}
