// Bozo the archmage, who lives in Footown.

#include <mudlib.h>

inherit MONSTER ;

void create () {
	::create() ;
	set("short", "Blind shephard");
	set("long", 
"A shephard stands tall, wearing a dull colored tunic with red, white and \n"+
"black stripes.  He wears gray leggings and worn out sandals.  The shephard \n"+
"bows his head, resting it against his thick wooden crook.  Around his head \n"+
"is wrapped a ragged gray cloth to cover his eyes, the ragged tassels hang \n"+
"down over one shoulder.  He seems almost sentiant, as if he has some sort \n"+
"of god-power over everything around him.  The shephard's gaunt face and \n"+
"hands make him so deadly serious that combined with his calm tentativeness,\n"+
"he becomes enthralling.\n"
);
	set ("id", ({ "shephard", "gidean" }));
	set_name("gidean") ;
	set_living_name("gidean");
	enable_commands() ;
	set ("no_attack", 1) ;
	set("gender", "male") ;
	set ("race" , "human") ;
	set ("stat/intelligence", 24) ;
	set_skill ("Magic of nasty sorts", 85, "intelligence") ;
	set ("inquiry", ([
"ducks" : "Ducks are a homogeneous brand of miscreants who secretly dominate\n"+
"our society.  Once they have gained organization within their race,\n"+
"they will be unstoppable.  We must act now!  Go out into the world\n"+
"and gather wild rice!  It shall be our only defense!\n",

"frogs" :  "If there are frogs in the world, let them be princes for the day!\n"+
"If there be princes, let them be frogs for a day.  And if we forget to\n"+
"turn them back, all the better, that's what I say--not that any of you\n"+
"punks asked...  I just don't get any respect these days.\n",
	]) ) ;
}
