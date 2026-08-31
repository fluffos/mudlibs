#include <std.h>
#include <discastle.h>
inherit ROOM;

void create()
{
	::create();
	
	set_properties
	(
	        (["light" : 2, "night light" : 1, "road" : 1])
	);
	set_short("Road to Distopia.");
	set_day_long
	(
		"Blood stains the road a rusty brown, swords lay on the side of the road chipped and broken"
		" a fight has taken place here, recently, a large one from the looks of it.  But all the bodies "
		"are gone. To the east, the faint and cheerful glow of the inn seems to stand in utter contrast "
		"to this seen of violence and gore."
	);
	set_night_long
	(
		"Stumbling over something in the moonlight that turns out to be a blood stained, rusted, sword is "
		"not very easy on the nerves. However, the strong light coming from the east seems to calm the nerves "
		"a bit. The ground is rough, as if it was kicked up by a lot of people. The sword on the ground tripped "
		"over draws a mental picture and gives a desire to leave as soon as possible. Maybe for the refuge of said inn?"
    );
	set_items
	(
	        ([
	                "sword" : "It was once a beautiful blade. Now it is rusted and broken",
	                "inn" : "You are getting closer",
	                "bodies" : "Where did they go?",
	        ])
	);

	set_exits
	(([
		"east" : ROOMS"npath5",
		"west" : ROOMS"npath3"
	]));
}
void reset() 
{
	::reset();
	if(!present("monster"))
	{
		new(ITEMS"wagon")->move(this_object());
		new(MOB"guard")->move(this_object());
		new(MOB"merchant")->move(this_object());
		new(MOB"brigand")->move(this_object());
		new(MOB"bandit")->move(this_object());
	
	}
}
