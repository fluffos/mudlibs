#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_ITEMMAKE;


void create()
{
        set_name(HIR "九天玄女剑" NOR, ({ "xuannvjian" }));
        set_weight(5000);
        set("special", 1);
        set("unit", "把");        
        set("long", "LONG_DESCRIPTION");   
        set("owner_id","ID");  
        set("no_sell", 1 ); 
        set("value",1000000);      
        set("no_steal", 1);      
        set("material", "tian jing");
        set("wield_msg", HIR "九天玄女剑划破天际，宛如一道彩虹，耀眼万分，瞬间落入$N手中。\n" NOR);
        set("unwield_msg", HIG"$N手中玄女剑嗡嗡做响，刹那间霞光尽散，宝剑便没了踪影。\n" NOR);
        if (! check_clone()) return;
        restore();
        init_sword(250);
        setup();             
       
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("sword") != "xuannv-jian" ||
            me->query_skill("xuannv-jian", 1) < 150)
                return damage_bonus / 2;

        switch (random(8))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 10 + 2);
                return HIR "突然间$N手中的九天玄女剑似乎幻化出无数道彩虹，" 
                           HIR "$n" HIR "顿吃一惊，呆在原地动弹不得！\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_wound("jing", n / 3, me);
                victim->receive_wound("qi", n / 3, me);
                return MAG "$N" MAG "手中九天玄女剑激荡出阵阵紫霞之气，$n" HIW
                       "顿时只觉气血上涌，难受之极！\n" NOR;
        }
        return damage_bonus;
}



void owner_is_killed()
{
        destruct(this_object());
} 
int query_autoload() { return 1; }

