
FUNCTION
	int set_level( int lvl );

DESCRIPTION
	This function is defined in /std/living/stats.c. set_level will set
	a living's level. If the living is a monster, it will also set stats
	and skills to default value.
	If the living is a player, only wizards and objects that has Root ID
	can set level with this function.

