// 古玩 zine th newbiejob

#include <guwan.h>

void create()
{
	set_name("字画", ({"zi hua"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一幅字画，不知是什么年代的作品。\n");
		set("unit", "幅");
		set("value", 100);
	}
    set("is_guwanzihua",1);
    set("zihua",1);
	set("no_pawn",1);
//    set("no_buy_from_hockshop",1);
	setup();
    get_level(this_object());
}