#include <armor.h>
#include <ansi.h>
#include <combat.h>

inherit WRISTS;
inherit F_UNIQUE;

void create()
{
        set_name("柔丝索", ({ "rousi suo", "suo", "rousi" }));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "silk");
                set("unit", "根");
                set("color", WHT);
                set("no_sell", 1);
                set("long", "这根柔丝索尽数以雪蚕丝绞成，微细透明，几非肉眼所能察见。\n");
                set("value", 30000);
                set("no_put", 1);
                set("armor_prop/armor", 1);
                set("wear_msg", CYN "$N哈哈大笑引人分散目光，暗地悄悄拢手于袖，缠上柔丝索。\n" NOR);
                set("remove_msg", CYN "$N嘿嘿奸笑两声，偷偷将缠在手腕上的柔丝索摘下。\n" NOR);
//                set("replace_file", OBJ_ARMORS("accouter/huwan"));
        }
        setup();
}

int is_special() { return 1; }

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object weapon;
        int skill;
        if( objectp(weapon = me->query_temp("weapon")) || objectp(weapon = me->query_temp("secondary_weapon")) )
                return 0;
        skill = me->query_skill("force",1);
        if( !victim->is_busy() && (random(3) > 1) && (random(skill) >= 100) )
        {       
                victim->start_busy(1 + random(2));
                return CYN "$N在$n全不知觉之下，出招的同时挥出了柔丝索。\n" 
                        CYN "待得$n惊觉得柔丝缠到身上，已被$N牵扯过去。\n" NOR;
        }
}
