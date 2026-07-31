#include <ansi.h>
#include <armor.h>
inherit CLOTH; 
inherit F_UNIQUE;
void create()
{
	set_name(YEL"Èíâ¬¼×"NOR, ({ "ruanwei jia","ruanwei", "jia" }) );
	set_weight(2500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "ÌÒ»¨µºÖÁ±¦Èíâ¬¼×£¬ÖÊµØ¼áÈÍ£¬µ¶Ç¹²»Èë¡£\n");
		set("unit", "¼þ");
                set("treasure",1);
		set("value", 1000000);
		set("material", "softsteel");                 
		set("armor_prop/armor", 500);
	}
	setup();
}
#include "/kungfu/skill/eff_msg.h";
int ob_hit(object ob, object me, int damage)
{
        object weapon = ob->query_temp("weapon");
        int p;
        string msg;
        if(!weapon) {
            msg = "Ö»Ìý¡°°¡Ó´¡±Ò»Éù¾ªºô£¬$NÎåÖ¸È«²åÔÚÈíâ¬¼×µÄ´ÌÉÏ£¬¶ÙÊ±´ÌµÃÏÊÑªÁÜÀì£¡\n";
            ob->receive_damage("qi", damage/5);
            ob->receive_wound("qi", damage/5);
            p = (int)ob->query("qi")*100/(int)ob->query("max_qi");
            msg += "( $N"+eff_status_msg(p)+" )\n";
            message_vision(msg, ob);
            return -damage/2;
         }        
}
