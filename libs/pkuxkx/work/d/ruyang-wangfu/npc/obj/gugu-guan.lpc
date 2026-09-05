//gugu-guan.c -- 汝阳王府王妃帽子
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name( HIR"红绢姑姑冠"NOR, ({ "gugu guan", "guan" }) );
	set("long", HIR"这是一顶只有蒙古贵妇才可以戴的姑姑冠。\n"NOR);

	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
		set("material", "iron");
		set("armor_prop/armor", 1);
		set("value", 20000);
	}
	setup();
}
