#include <std.h>
#include <hermes.h>
inherit ROOM;
void create()
{
	::create();
	set_properties
	(
	        (["light" : 2, "night light" : 1, "forest" : 1])
	);
	set_short("Road out of Lodos.");
	set_day_long
	(
	        "The forest is unusually quiet.  Unnervingly so. "
	        "The only sound heard is the steady crunch of worn "
	        "boots as they settle down the path. "
	        "Every so often an animal will sound, only to quickly be "
	        "cut off with a strange growling."
	);
	set_smell("default", "The frest aroma of pine trees fills the air.");
    set_listen("default", "A faint howling seems to draw closer");
	set_night_long
	(
	      "The sound of an owl catches the attention. "
	      "The forest is dark, spooky.  Perhaps it wasn't "
	      "such a good idea to come here after all? "
	      "A howl cuts through the night, an ice dagger "
	      "to the heart."
	);
	set_items
	(
	        ([
	                "forest" : "The forest streches out endlessly.",
	                "boots " : "Perhaps it's time to replace these old things?",
	                "animal" : "You hear it... But where is it coming from?",
	                "owl" : "The owl looks at you with blazing yellow eyes."
	        ])
	);
	set_exits
	(([
		"east" : ROOMS"path2",
		"west" : ROOMS"startlod"
	]));
}
void reset() 
{
	::reset();
	if(!present("owl")) 
	new(MOB "dowl")->move(this_object());
	if(!present("wolf"))
	{
		new(MOB"dwolf")->move(this_object());
		new(MOB"dwolf")->move(this_object());
		new(MOB"dwolf")->move(this_object());
	}
}
