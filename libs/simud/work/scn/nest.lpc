inherit "/obj/scenery";
#include <container.h>

int product_aspect;
int query_product_aspect() { return product_aspect; }
void set_product_aspect(int x) { product_aspect = x; }

/**
 * At present, nests do _not_ hatch eggs placed into them
 *
void on_insert(object egg) {
	if( egg->query_has_aspect( product_aspect ) &&
		egg->query_has_aspect( C_EGG ) &&
		egg->query_has_aspect( C_FERTILE ) ) {
			debug("got suitable egg","ai");
			if( find_call_out("do_hatch") == -1 )
				call_out("do_hatch",300);
			else
				debug("already got eggs","ai");
	} else {
		debug("invalid item inserted into nest, not hatching","ai");
	}
}

void do_hatch() {
	object duck, egg, *eggs;
	string duck_fname;
	
	while( find_call_out("do_hatch") != -1 )
		remove_call_out("do_hatch");
	
	// find fertile eggs
	eggs = filter( all_inventory(),
					(: $1->query_has_aspect(C_EGG) &&
					   $1->query_has_aspect(product_aspect) &&
					   $1->query_has_aspect(C_FERTILE) :)
				 );
	if( !sizeof(eggs) ) {
		debug("no eggs in nest","ai");
		return;
	}
	
	// select first fertile egg
	egg = eggs[0];
	if( environment(egg) != this_object() ) {
		debug("egg has wandered off, not hatching","ai");
		return;
	}
	switch( product_aspect ) {
		case C_DUCK:
			duck_fname = "/monsters/duck";
			break;
		default:
			debug("attempt to hatch unhatchable egg");
			return;
	}
	
	// emergency rabbit control - maximum of 100 ducks per nest
	if( sizeof(clones(object_name())) * 100 < sizeof(clones(duck_fname)) ) {
		debug("too many ducks, not hatching");
		return;
	}
	
	// and if we passed all previous tests, hatch
	debug("hatching "+as_lpc(egg),"ai");
	duck = clone_object( duck_fname );
	duck->set_birth( time() );
	duck->set_fertile( 0 );

	// remove egglaying ai from male ducks to save system resources
	if( duck->query_gender() == 1 )	{
		object ai = present_clone("/ai/egglaying",duck);
		debug("eliminating egglaying ai from male duck","ai");
		destruct(ai);
	}
	
	// crack the egg
	if( egg->query_quantity() ) {
		egg->add_quantity( -1 );
		call_out("do_hatch",120);
	} else
		destruct(egg);
	
	// message about the egg hatching
	tell_room( environment(), "The egg hatches.\n" );
	duck->move( environment() );
	duck->set_coord( this_object()->query_coord() );
	command("walk random",duck);
}
*/

NAME( "nest" )
SPECIFIC( "the nest" )
DISTANT( "a nest" )
LOOK( "The nest is made of assorted plant material mushed together in such a way that only the manufacturing critter could love it.?(HASINV: In the nest $(ISINV) $(INV).)" )

void create() {
   ::create();
/* OBJEDIT { */
   set_phrase( "There is a small nest ~plac." );
   set_position( "here" );
   set_preposition( "in" );
/* } OBJEDIT */
}

void on_map_paint( object painter ) {
   painter->paint( query_x(), query_y(), '%', 3, LAYER_ITEMS );
}
