// equip.c

inherit ITEM;
inherit F_EQUIP;

void setup()
{
	if ( query("weapon_prop") && !query("rigidity"))
		set("rigidity", 150);
	if (!query("max_rigidity")) set("max_rigidity", query("rigidity"));

	if( !query("armor_prop/dodge") && !query("weapon_prop") && (weight() >= 3000) )
		set("armor_prop/dodge", - weight() / 3000 );
	if( !query("weapon_prop/dodge") && !query("armor_prop") && (weight() >= 3000) )
		set("weapon_prop/dodge", - weight() / 3000 );
}
