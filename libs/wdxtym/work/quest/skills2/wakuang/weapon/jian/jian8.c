// xuantie jian ÐþÌúÖØ½£

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name( HIB"ÖØ½£"NOR,({ "zhong jian", "zhongjian", "jian", "sword"}) );
        set_weight(70000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "±ú");
                set("value", 3000);
                set("unique", 1);

         
        }
        init_sword(300);
        setup();
}
