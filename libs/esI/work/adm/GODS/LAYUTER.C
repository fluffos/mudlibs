#include <races.h>

inherit RACE_GOD;

void create()
{
	::create();
	seteuid(getuid());
	set_level(19);
	set_name( "layuter", "LAYUTER" );
	add ("id", ({ "god" }) );
	set_short( "Layuter of god", "LAYUTER大神" );

	set( "gender", "male" );

	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "con", 30 );
	set_perm_stat( "pie", 30 );
	set_perm_stat( "kar", 30 );

	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );

	set( "max_hp", 30000 );
	set( "hit_points", 30000 );
	set( "force_points", 100000 );
	set( "max_fp", 100000 );
	set( "wealth/platinum", 1 );
	set( "exp_reward", 1 );

	set_natural_weapon( 200, 50, 100 );
	set_natural_armor( 500, 500 );
	set( "special_defense", ([ "all": 100, "none": 100 ]) );
	wield_weapon( "/d/noden/nodania/obj/god_sabre" );
}
