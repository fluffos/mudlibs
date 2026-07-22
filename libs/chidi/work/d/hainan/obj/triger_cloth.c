// bear_cloth.c 黑熊皮 by ksusan 10/06/97
#include <ansi.h>

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(YEL"虎皮短裙"NOR, ({ "skirt","cloth"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "用老虎皮作成的短裙,上面有黑黄交织的虎纹！\n");
		set("unit", "件");
		set("value", 1200);
		set("material", "leather");
		set("armor_prop/armor", 40);
		set("armor_prop/armor_vs_force", 40);
		set("armor_prop/attack", -6);
		set("armor_prop/dodge", -4);
	}
	setup();
}

int query_autoload() { return 1; }
