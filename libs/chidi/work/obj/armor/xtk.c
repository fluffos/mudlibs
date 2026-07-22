// huyao.c
#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name("–˛Ã˙ø¯",({"xuantie kui","kui"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "∂•");
		set("material", "head");
		set("armor_prop/armor", 5);
		set("oldsix/protect",1000);
		set("value",500000);
		set("zhengzhao",4);
		set("oldsix/by",1);
		set("oldsix/max_damage",50);
	}
	setup();
}

int move(mixed dest)
{
        if(! userp(dest))       return ::move(dest);
        if( ::move(dest)==0)    return 0;
        message("channel:rumor",YEL"°æ“•—‘°ø"+ "ƒ≥»À£∫–˛Ã˙ø¯±ª"+
        dest->query("name")+"«¿µΩ ÷¡À£°\n"NOR,users());
        return 1;
}
