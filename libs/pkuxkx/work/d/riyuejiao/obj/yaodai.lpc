// yaodai 腰带
// by bing

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
        set_name(YEL "腰带" NOR , ({ "yao dai","dai" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "只");
		set("long", YEL "这是日月教众所佩带的黄色腰带，是尊贵身份的象征。\n" NOR);
                set("material", "cloth");
                set("armor_prop/armor", 1);
		set("wear_msg",YEL "$N将一只黄色腰带围在腰间，不禁得意洋洋。\n" NOR);
		set("mingjiao",1);
        }
        setup();
}

