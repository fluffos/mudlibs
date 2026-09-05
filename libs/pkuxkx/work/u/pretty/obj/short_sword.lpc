// short_sword.c
//
// created by pretty

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name( HIC "短剑" NOR, ({ "short sword", "sword" }) );
	set_weight( 1000 );
	if ( clonep() )
		set_default_object( __FILE__ );
	else
	{
		set( "long", "这是一柄精光四射的短剑，剑未出鞘已可感其锋芒。\n" );
		set( "value", 20000 );
		set( "unit", "柄" );
		set( "material", "steel" );
		set( "wield_msg", "$N一按绷簧，一柄$n『唰』的一声弹入$N的手中。\n" );
		set( "unwield_msg", "$N将手中的$n随手一抛，不偏不倚恰好落入鞘中。\n" );
	}

	init_sword( 50 );
	setup();
}
