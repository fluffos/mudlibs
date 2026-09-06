#include <item.h>
#include <desc.h>
#include <object.h>

ICON( 'g', 7, LAYER_ITEMS )
PLURAL( "bodies" )
NAME( "body" )
WEIGHT( 2000000000 )	// several thousand pounds
BULK( 2000000000 )
GETTABLE( 1 )		// in theory
DROPPABLE( 1 )
TASTE( "Strangely enough, it tastes like clay" )

string golem_type;

void set_golem_type(string str) {
	golem_type = str;
	if (str == "iron")
		set_distant( "an iron golem body" );
	else
		set_distant( "a "+str+" golem body" );
	set_look( "It is a large humanoid body constructed from "+str+". It "+
		  "does not appear to be alive right now." );
	set_alt_name( ({str+" golem body", "golem body"}) );
	set_alt_plural( ({str+" golem bodies", "golem bodies"}) );
	set_specific( "the "+str+" golem body" );
}
