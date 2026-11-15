// boots.c

#include <armor.h>

inherit EQUIP;

void setup()
{
	if (! clonep(this_object()))
		set("armor_type", TYPE_BOOTS);
set("armor_buwei", "脚部");
 if( !query("armor_apply/dodge") &&	 weight() > 3000 )
		set("armor_prop/dodge", - weight() / 3000 );

	::setup();
}

int washed(int n)
{
	switch (query("material"))
	{
	case "cloth":
		n += n * 3 / 10;
		break;
	case "leather":
		break;
	case "silk":
		n -= n * 3 / 10;
		break;
	case "bamboo":
		n -= n * 5 / 10;
		break;
	case "steel":
		n -= n * 7 / 10;
		break;
	}
	set_temp("no_wear", "现在" + name() + "还是湿乎乎的，你没法穿。\n");
	delete_temp("daub");
	remove_call_out("dry_cloth");
	if (n) call_out("dry_cloth", n);
	return n;
}

void dry_cloth()
{
	if (! objectp(this_object()))
		return;
	delete_temp("no_wear");
	message("vision", name() + "已经干了。\n", environment());
}
