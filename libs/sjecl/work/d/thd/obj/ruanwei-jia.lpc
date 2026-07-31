#include <ansi.h>
#include <armor.h>
inherit CLOTH; 
void create()
{
        set_name(YEL"软猬甲"NOR, ({ "ruanwei jia","ruanwei", "jia" }) );
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "桃花岛至宝软猬甲，质地坚韧，刀枪不入。\n");
                set("unit", "件");
                set("unique", 1);
                set("treasure",1);
                set("value", 1);
                set("material", "softsteel");                 
        set("armor_prop/armor", 100);
        }
        setup();
}

int ob_hit(object ob, object me, int damage)
{
        object weapon = ob->query_temp("weapon");
        int p;
        string msg;
        if(!weapon) {
            msg = "只听“啊哟”一声惊呼，$N五指全插在软猬甲的刺上，顿时刺得鲜血淋漓！\n";
            ob->receive_damage("qi", damage/10);
            ob->receive_wound("qi", damage/10);
            p = (int)ob->query("eff_qi")*100/(int)ob->query("max_qi");
            msg += "( $N"+COMBAT_D->eff_status_msg(p)+" )\n";
            message_vision(msg, ob);
            return -damage/3;
         }        
}

