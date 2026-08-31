#include <discastle.h>
inherit ROOM;
void create()
{
        ::create();
        set_properties
        (
                (["light" : 2, "night light" : 1, "inside" : 1])
        );
        set_short("Mad Cow Tavern.");
        set_day_long
        (
        	"A simple bedroom.  Sunlight shines in through the windows "
        	"and the curtains.  A single bed is here, neatly made and ready "
        	"for the next occupant.  A dresser sits next to the bed completing "
        	"the drab but not unpleasant decor."
        );
        set_night_long
        (
			"The pale moonlight casts a glow through the curtains on the window "
			"the rythmic snoring of the merchant in bed is the only sound to be heard. "
			"He must have only recently gone to bed, a thin wisp of smoke marks a smoldering "
			"candle and a great ledger beside it probably filled with figures."
		);
        if (query_night())            
        {
	        set_listen("default", "Light snoring can be heard");
        }
        else
        {
        	set_listen("default", "Birds chirping can be faintly heard");
        }
        set_items
        (
                ([
                        "bed" : "Looks comfortable",
                        "windows" : "It's a window alright",
                        "window" : "Yup, still a window",
                        "curtains" : "Heavy curtains to block sunlight",
                        "candle" : "It's used to help people see better",
                        "dresser" : "It contains clothes and other worthless items",
                        "ledge" : "You're not a merchant, it means nothing to you",
                        "door" : "Good quailty oak"
                ])
        );
        set_exits
        (([
                "out" : ROOMS"innsecflroome2",
        ]));

}




void reset() 
{
	::reset();
		if(!present("monster") && query_night())
	{
		int moo = random(3);
		switch (moo)
		{
			case 0:
			new(MOB"merbracers")->move(this_object());
			break;
			case 1:
			new(MOB"merforfl")->move(this_object());
			break;
			case 2:
			new(MOB"merforflw2")->move(this_object());
			break;
			case 3:
			new(MOB"merforflw")->move(this_object());
			break;
			default:
			new(MOB"merbracers")->move(this_object());
			break;
		}
	}	
}
