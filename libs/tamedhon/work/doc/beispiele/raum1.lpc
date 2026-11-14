/* /doc/beispiele/raum1.c von Rumata */

inherit "std/room";

#include <properties.h>
#include <language.h>

create()
{
	::create();

	SetProp( P_INT_SHORT, "Ein kleines Schreibzimmer" );
	SetProp( P_INT_LONG,
		"Du stehst in einem kleinen Schreibzimmer.\n"
	+	"Es gehoerte wohl irgendwann einmal einem Magier, aber nun\n"
	+	"ist dieser Raum verwaist und rottet vor sich hin.\n"
	+	"Ein grosser Schreibtisch in der Mitte des Raumes scheint\n"
	+	"noch einigermassen gut erhalten zu sein. Durch die Tuer\n"
	+	"im Norden faellt etwas Licht hinein.\n"
	);
	SetProp( P_LIGHT, 1 );
	SetProp( P_INDOORS, 1 );

	AddDetail( ({ "schreibtisch", "tisch" }),
		"Auf dem Tisch liegt eine dicke Staubschicht.\n"
	+	"Eine Schublade findest Du ebenfalls.\n"
	);
	AddDetail( ({ "staub", "staubschicht", "schicht" }),
		"Du malst gelangweilt einige Kreise in den Staub.\n"
	);
	AddDetail( "schublade",
		"So sehr Du Dich anstrengst; Du kannst sie nicht bewegen.\n"
	);
	AddDetail( "tuer" ,
		"Sie steht seit Jahren offen und ist in dieser Lage\n"
	+	"hoffnungslos festgerostet.\n"
	);

	AddCmd( ({ "schliesse", "oeffne", "bewege",
		"schliess", "beweg" }), "beweg_etwas" );
	AddExit( "norden", "players/rumata/workroom" );
}

beweg_etwas( str )
{
	notify_fail( "Was willst Du denn bewegen ?" );
	if( str == "tuer" )
	{
		write( "Die Tuer ist hoffnungslos festgerostet.\n" );
		return 1;
	}
	if ( str == "lade" || str == "schublade" )
	{
		write( "Die Schublade klemmt einfach nur.\n" );
		return 1;
	}
	if ( query_verb() == "bewege" &&
		( str == "tisch" || str == "schreibtisch" ) )
	{
		write(
			"Der Tisch scheint am Boden festgeschraubt zu sein.\n"
		);
		say(
			this_player()->name(WER,2)+" zerrt am Schreibtisch.\n"
		);
		return 1;
	}
	return 0;
}
