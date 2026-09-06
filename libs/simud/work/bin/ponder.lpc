#include <magic.h>

int main( string arg ) {
	object spell;
	int dc;
	string worst, skill;
	float total_chance = 1.0, worst_chance = 1.0, chance;
	mapping skills = ([]);
	string *arr = ({});

	if( !arg )
		return notify_fail("What spell do you want to ponder?\n");
	if( !this_player()->query_known_spells()[arg] )
		return notify_fail("You do not know any such spell '"+arg+"'.\n");
	spell = find_object(MAGIC_DAEMON->query_spell(arg));
	if( !spell )
		return notify_fail("Somehow... that spell doesn't exist?\n");

	msg("~CACTYou ponder the spell '~CBRT"+arg+"~CACT'.~CDEF");

	debug( this_player()->query_name()+" / "+arg );
	for( int step = 0; step < spell->query_num_steps(); step++ ) {
		skill = spell->query_step_skill( (["step":step]) );
		dc = min( 120, max( 10, spell->query_level() * 25 + step * 5 ) );
		// I _think_ this is the right math :P
		chance = 1.0 - (dc + 11.0 - this_player()->query_modified_skill(skill)) / 50.0;
		//if( this_player()->query_level() > WIZLEVEL )
			debug( " >> ~CTIT"+skill+"~CDEF = "+chance+" << "+this_player()->query_modified_skill(skill)+"/"+this_player()->query_skill(skill)+"/"+dc );
		chance = min( 1.0, max( 0.0, chance ) );
		skills[skill] = chance;
		total_chance *= chance;
		if( chance < worst_chance ) {
			worst_chance = chance;
			worst = skill;
		}
	}
	total_chance = floor(100.0 * min( 1.0, max( 0.0, total_chance )));
	debug( total_chance );

	foreach( skill : m_indices(skills) ) {
		arr += ({ "~CCOM"+explode(skill,".")[<1]+"~CDEF" });
	}
	arr = sort_array(arr, #'>);

	msg( "~CBRT"+capitalize(arg)+"~CDEF uses the skill"+(sizeof(arr)>1?"s":"")+" "+comma_list(arr)+"." );
	if( total_chance == 100 )
		msg( "You are ~CEMOguaranteed~CDEF to succeed in casting this spell." );
	else if( total_chance == 0 )
		msg( "You are currently ~CWRNincapable~CDEF of casting this spell." );
	else {
		msg( "You are ~CBRT"+(int)total_chance+"%~CDEF likely to successfully cast this spell.");
		msg( "Practicing your ~CBRT"+worst+"~CDEF would improve this chance." );
	}
	
	return 1;
}
