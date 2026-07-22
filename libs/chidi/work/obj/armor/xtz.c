// cloth.c
#include <ansi.h>
#include <armor.h>

inherit HANDS;

void create()
{
	set_name("–˛Ã˙’∆",({"xuantie zhang","zhang"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","À´");
		set("material","iron");
		set("armor_prop/armor",5);
		set("oldsix/by",1);
		set("zhengzhao",1);
		set("value",500000);
		set("oldsix/protect",1000);
		set("oldsix/max_damage",50);
	}
	setup();
}

int move(mixed dest)
{
        if(! userp(dest))       return ::move(dest);
        if( ::move(dest)==0)    return 0;
        message("channel:rumor",YEL"°æ“•—‘°ø"+ "ƒ≥»À£∫–˛Ã˙’∆±ª"+
        dest->query("name")+"«¿µΩ ÷¡À£°\n"NOR,users());
        return 1;
}

