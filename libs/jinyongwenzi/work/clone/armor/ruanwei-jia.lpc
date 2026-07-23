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
		set("value", 1000000);
		set("material", "softsteel");                 
        set("armor_prop/armor", 100);
	}
	setup();
}
#include "/kungfu/skill/eff_msg.h";
int ob_hit(object ob, object me, int damage)
{
        object weapon = ob->query_temp("weapon");
        int p;
        string msg;
if(!weapon && random(10)>4
 && random(ob->query("combat_exp"))<me->query("combat_exp")*3/4) {
            msg = "只听“啊哟”一声惊呼，$N五指全插在软猬甲的刺上，顿时刺得鲜血淋漓！\n";
ob->receive_damage("qi", damage/5>200?200:damage/5);
ob->receive_wound("qi", damage/5>100?100:damage/5);
            p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
            msg += "( $N"+eff_status_msg(p)+" )\n";
            message_vision(msg, ob);
            return -damage/2;
         }        
}
