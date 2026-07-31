 // TIE@FY3
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIW "苍穹神剑"NOR, ({ "cang qiong" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "一柄没有剑头的长剑\n");
                set("value", 5000);
                set("rigidity",2000);   
                set("material", "steel");
                set("max_enchant",7);
                set("for_create_weapon",1);
            set("unique_amount", 2);  
    }
        ::init_sword(650);
      
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int badint=0;
        badint = 
        victim->query_skill("iron-cloth") + victim->query_temp("apply/iron-cloth") * 2  ;
        if(badint)
        message_vision( HIR "$N手中"+name()+ HIR "发出丝丝剑气，直取$n的气门！\n"NOR,me,victim);
        return badint * 2;
}        
