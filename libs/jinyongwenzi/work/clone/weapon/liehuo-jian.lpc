#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(RED"烈火剑"NOR, ({ "liehuo jian", "jian", "liehuo", "sword" }) );        
        set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
           set("value", 10000000);
           set("rigidity", 2);
           set("sharpness", 2);
           set("unique", 1);
           set("treasure",1);
           set("wield_neili", 100);
           set("wield_maxneili", 1000);
           set("wield_str", 20);
           set("unit", "把");
           set("long", RED"此剑剑刃如熊熊烈火，剑鞘上镶著“烈火”两个古篆，乃是明教的镇教宝物，平时都供奉在光明宝塔之内。\n"NOR);
           }
        init_sword(60);
        setup();
}