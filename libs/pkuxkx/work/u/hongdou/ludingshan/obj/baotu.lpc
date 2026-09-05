// baotu.c  鹿鼎山藏宝图
// hongdou 98.10.27

#include <ansi.h>

inherit ITEM;
inherit F_SAVE;
inherit F_AUTOLOAD;

void create()
{
   	set_name(WHT"鹿鼎山藏宝图"NOR,({"bao tu","tu"}));
	set_weight(50);
	if(clonep() )
     		set_default_object(__FILE__);
   	else{
   	set("long","这是一副记录鹿鼎山宝藏位置的地图，有了它就可以挖掘宝藏。\n");
	set("unit","副");
       }
}

string query_autoload()
{
        return query("name");
}