
#include <ansi.h>
inherit ITEM;

void create()
{
		string *colors=({HIC,HIR,HIW,HIY,HIM,MAG,YEL,WHT,RED,CYN});
        set_name(colors[random(sizeof(colors))]+"贡品"+NOR, ({ "gong pin", }) );
        set_weight(3000);
		set("value",10000+random(5000));
		set("is_gongpin",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "份");
                set("material", "paper");
        }
        setup();
}
