// yuexia-qiulu 月下秋露

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name(HIC"月下秋露"NOR,({ "yuexia qiulu", "jian", "sword", "yuexiaqiulu" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "把");
                set("value", 1);
                set("rigidity", 5);
                set("sharpness", 5);
                set("unique", 1);
                set("material", "steel");
                set("weapon_prop/parry", 8);
                set("treasure",1);
                set("wield_neili", 500);
                set("wield_maxneili", 800);
                set("wield_str", 25);
                set("wield_msg", HIY"$N“唰”的一声抽出倚天剑挽了个剑花，但见寒芒吞吐，电闪星飞。\n$N不由得从心底升起一股凌云豪气。\n"NOR);
                set("long", "这是一柄四尺来长的古剑，剑鞘上金丝镶着‘倚天’两个篆文。\n整个剑身隐隐发出一层青气，剑未出鞘，已可见其不凡。\n");
                set("unwield_msg", HIY "倚天剑幻作一道白光，「唰」地飞入剑鞘。\n" NOR);
        }
        init_sword(180);
        setup();
}
