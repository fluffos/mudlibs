// SN:XmI0_jS_@??I^J2a
// ITEM Made by player(慕容新月:xinyue) /data/item/x/xinyue-club.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jul 25 00:18:02 2004
#include <ansi.h>
#include <weapon.h>

inherit CLUB;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m如此星辰非昨夜[2;37;0m", ({ "club" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一根棍。
[1;34m听着它的名字，看着它的式样，你实在猜不透它为什么是一根棍子，可是除了棍之外你又找不到合适的词来代替它。[2;37;0m
棍柄上刻着一行小字：慕容新月(xinyue)
");
	set("value", 2100000);
	set("point", 786);
	set("material", "magic stone");
	set("wield_msg", "[1;34m$N对着天空喃喃自语：“木自哪里来，教人费疑猜。借我春风手，扫尽红尘埃。”\n天边飞来一根$n[1;34m落入$N的手上，$N随手舞了个棍花，只见蓝色的棍花上星辰点点，一闪一烁，宛如夜空。[2;37;0m\n");
	set("unwield_msg", "[1;34m$N对着茫茫碧落念道：“君自天外来，再归天外路。待到风起时，还来震世俗。”\n$N随手一抖，$N呼啸一声就不见了，四周围的点点繁星也如同昨夜的星辰，隐入了苍茫长空，踪影全无。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_club(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
