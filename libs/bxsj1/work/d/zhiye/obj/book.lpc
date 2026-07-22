#include <ansi.h>
inherit ITEM;

void initlvl();

void create()
{
        set_name(HIC"倚天匠技残篇"NOR,({"yitian canpian","canpian","book"}));
        set_weight(1000);     
        set("unit", "本");
        set("long","一本凌乱的手册，粗看真如神画鬼符。
可你细细翻阅，对照自己所学的工匠之术，竟发现是一本记录了上乘工匠之术的秘籍。不由得手舞足蹈起来。
\n");
        set("value", 500000);
        set("material", "paper");        
        set("for_forg",1);        
        setup();
        initlvl();
}

void initlvl() {
	call_out("delete_owner",90+random(30));	
}

int set_level(int i)
{
	switch (i) {
		case 1:
		set_name(HIC"倚天匠技残篇"NOR,({"yitian canpian","canpian","book"}));
		set("long","一本凌乱的手册，粗看真如神画鬼符。
可你细细翻阅，对照自己所学的工匠之术，竟发现是一本记录了上乘工匠之术的秘籍。不由得手舞足蹈起来。
\n");
		break;
		case 2:
		set_name(HIM"屠龙匠技残篇"NOR,({"tulong canpian","canpian","book"}));
		set("long","一本凌乱的手册，粗看真如神画鬼符。
可你细细翻阅，对照自己所学的工匠之术，竟发现是一本记录了上乘工匠之术的秘籍。不由得手舞足蹈起来。
\n");		
		break;
		default:call_out("destroying", 1, this_object());
                 	return 0;
	}
	return 1;
}

void destroying(object obj)
{
	if (!obj) return;
	if (userp(obj))
		command("drop "+obj->parse_command_id_list()[0]);
	else
		destruct(obj);
}

