//#pragma save_binary

#include <mudlib.h>
#include <magic.h>

inherit DAEMON;

int spell_exists(string spell);

int cmd_cast(string str)
{
	string type, targname, spell, code;
	mixed spell_level;

    if ( ! str ) return 0;
    if( this_player()->query_temp("slience") ||
        this_player()->query("slience") ) return 0;
    
    spell = str;
    if( sscanf( str, "%s %s at %s",type, spell, targname)!=3 &&
        sscanf( str, "%s %s on %s",type, spell, targname)!=3 &&
		sscanf( str, "%s at %s", spell, targname)!=2 &&
		sscanf( str, "%s on %s", spell, targname)!=2 && !str ) return 0;
	
	spell_level = (int)this_player()->query("spells/"+spell);
	code = MAGIC_D->find_spell( spell );
	if( !code ) return 0;
	if( !type || type == "" )
		spell_level -= (int)this_player()->query("spell_power");
    else
      switch( type ) {
        case "max"     : break;
        case "regular" : spell_level -= 1; break;
        case "normal"  : spell_level -= 2; break;
        case "minor"   : spell_level -= 3; break;
        case "mini"    : spell_level -= 4; break;
        default : spell_level -= (int)this_player()->query("spell_power");
      }
    if( spell_level < 0 ) spell_level = 0;
	code->cast(spell_level, targname);
	return 1;
}
