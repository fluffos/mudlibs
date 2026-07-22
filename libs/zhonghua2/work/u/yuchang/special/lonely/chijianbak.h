#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_ITEMMAKE;


void create()
{
        set_name(HIR "赤剑" NOR, ({ "chijian" }));
        set("special", 1);
	 set_weight(15000);
	 set("item_make", 1);
	 set("unit", "柄");         
        set("long", "LONG_DESCRIPTION");   
        set("owner_id","ID");  
        set("no_sell", 1 ); 
        set("no_steal", 1);      
        set("value",1);   
        set("point", 500);       
        set("material", "tian jing");
        set("wield_msg", HIR "赤剑当空一击，宛如赤龙升天，瞬间落入$N手中。\n" NOR);
        set("unwield_msg", HIG"$N手中赤剑嗡嗡做响，刹那间红光尽散，赤剑便没了踪影。\n" NOR);
        if (! check_clone()) return;
        restore();
        init_sword(apply_damage());
        setup();             
       
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n;
        int my_exp, ob_exp;

        if (me->query_skill_mapped("sword") != "china-aojue" ||
            me->query_skill("china-aojue", 1) < 150)
                return damage_bonus / 2;

        switch (random(8))
        {
        case 0:
                if (! victim->is_busy())
                victim->start_busy(me->query_skill("sword") / 10 + 2);
                return HIR "突然间$N手中的赤剑放射出无数道红光，" 
                           HIR "$n" HIR "顿吃一惊，呆在原地动弹不得！\n" NOR;

        case 1:
                n = me->query_skill("sword");
                victim->receive_wound("jing", n / 3, me);
                victim->receive_wound("qi", n / 3, me);
                return MAG "$N" MAG "手中赤剑激荡出阵阵天煞之气，$n" HIW
                       "顿时只觉气血上涌，难受之极！\n" NOR;
        }
        return damage_bonus;
}

string long() { return query("long") + item_long(); }

void owner_is_killed()
{
        destruct(this_object());
} 
int query_autoload() { return 1; }


