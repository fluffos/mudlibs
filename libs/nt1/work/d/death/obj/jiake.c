#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(CYN "ĞşÎä¼×¿Ç" NOR, ({ "xuanwu jiake", "jiake"}));
	set_weight(25000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", CYN "Ò»¿éÉñÊŞĞşÎäµÄ¼×¿Ç£¬Ïàµ±µÄ¼áÈÍ¡£\n" NOR);
		set("unit", "¿é");
		set("value", 120000);
              set("item_origin", 1);
              set("material_attrib", "silk");
              set("material_name", CYN "ĞşÎä¼×¿Ç" NOR);
              set("can_make", ({ "¼×" }));
              set("power_point", 100);
	}
}

