
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
void create()
{
        set_name(HIY"星月菩提"NOR, ({ "xingyue puti", "puti" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 1);
                set("unique", 1);
                set("rigidity", 4);
                set("material", "steel");
                set("weapon_prop/parry", 5);
                set("weapon_prop/dodge", 3);
                set("treasure",1);
                set("wield_neili", 500);
                set("wield_maxneili", 900);  
                set("wield_str", 22);
                set("long", "这是一副用星月菩提制成的念珠，共有一百零八颗，隐隐散发出红光，是历代高僧传下之宝物。\n");
                set("wield_msg","$N右手一抖，“刷”的一声，犹如一条神龙，盘旋飞舞，一串$n挂在了$N的手腕上。\n");
                set("unwield_msg","$N默念一声“阿弥陀佛”，伸出双手把念珠挂在胸口。\n");
       }
       init_whip(120);
       setup();
}

