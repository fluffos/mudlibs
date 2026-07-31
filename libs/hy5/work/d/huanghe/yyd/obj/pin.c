#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
          set_name(HIY"金钗"NOR, ({"jin chai","jin","chai"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long",
                "\n这是一支精致漂亮的金钗，钗上一颗明珠又大又圆，宝光莹然。\n");
		set("unit", "个");
		set("value", 3000);
		set("armor_prop/armor", 0);
		set("armor_prop/personality", 3);
		set("wear_msg", "$N轻轻地把一朵$n戴在头上。\n");
		set("unwield_msg", "$N轻轻地把$n从头上除了下来。\n");

		set("female_only", 1);

	}
	setup();
}

