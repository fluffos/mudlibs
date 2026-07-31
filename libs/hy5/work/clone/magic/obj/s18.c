#include <ansi.h>
#include <armor.h>

inherit SHIELD;

void create()
{
	set_name(YEL"众神之盾"NOR, ({ "light shield", "lightshield" }));
	set("long", YEL"这是一件众神之盾，上面刻着一些奇怪的咒语。\n"NOR);
	set("weight", 400);
	set("unit", "面");
	set("armor_prop/karay",10);
	set("value", 132000);
	set("material", "gem");
	set("armor_prop/armor", 500);
	set("armor_prop/damage", 100);
	set("armor_type", TYPE_SHIELD);
	setup();
}	
