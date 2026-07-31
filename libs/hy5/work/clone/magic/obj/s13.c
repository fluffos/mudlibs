#include <ansi.h>
#include <armor.h>

inherit FINGER;

void create()
{
	set_name(HIY"龙神徽章"NOR, ({ "ice ring", "icering" }));
	set("long", HIY"这是一个龙神徽章，上面刻着一些奇怪的咒语。\n"NOR);
	set("weight", 400);
	set("unit", "枚");
	set("value", 32000);
	set("material", "gem");
	set("armor_prop/armor", 60);
	set("armor_prop/damage", 60);
	set("armor_type", TYPE_FINGER);
	setup();
}	
