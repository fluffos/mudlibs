// /wizards/excelsior/rooms/level3/road6
// Excelsior 7-1-96

#define MSGES ({"The tigerwolf girl offers you a wilting daisy.", \
	"The flower girl looks blankly at the passerbys.", \
	"A man walks right past the begging and starving girl.", \
	"The girl trys to sell you an ugly bouque of flowers.", \
	"Sigh."})

inherit "/std/room";

void create() {
	::create();
	set_property("light",3);
	set_property("indoors",0);
	set_property("no mine",1);
	set_property("no castle",1);
	set("short","The market continues");
	set("long","Just when you thought it was over, the market "+
		"keeps going! It is boggling how many people have set "+
		"up shop along this street. Most of them probably didn't "+
		"register with the New Ferie Dust Commercial District and "+
		"are thus illegal, but the government only has the resourses "+
		"to crack down on them only once in a while. The illegals "+
		"usually hear of an impending crack down and clear out in "+
		"time. To the south you can see off the edge of the street "+
		"down into the depths of the city. There is a building to "+
		"your north. %^BLUE%^There is a flower vendor here%^RESET%^. The road continues "+
		"to the east and west.");
	set_listen("default","You here the sound of an open air market.");
	set_smell("default","You smell flowers.");
	set_smell("flowers","They actually don't smell very good.");
	set_items(([({"vendor","flower vendor","tigerwolf","girl","tigerwolf girl"}):"This really is a sad sight. "+
		"An obviously poor and meager tigerwolf set up the stand,for the "+
		"merchandise is nothing more then flowers picked from someone's yard. "+
		"Many are wilting and dying. She is asking next to nothing for "+
		"them, but people walk by without paying her any attention. "+
		"You try to ignore her before she breaks your heart.",
		"people":"Many have set up a shop on this street.",
		({"edge","street","edge of street","city","depths of city",
			"depths of the city"}):"Down below you can make out the entrance "+
			"to the city jail and below that a busy intersection."]));
	set_exits((["east":"/wizards/excelsior/rooms/level3/road7",
		"west":"/wizards/excelsior/rooms/level3/road5"]));
}

void init() {
	::init();
	call_out("offer_flowers",random(4)+1);
}

int check_player(object ob) {
	if(!ob) return 0;
	return (int)ob->is_player();
}

void offer_flowers() {
	object *ob;
	int i;
	ob = all_inventory(this_object());
	ob = filter_array(ob,"check_player");
	if(!sizeof(ob)) return;
	i = sizeof(MSGES);
	message("info",MSGES[random(i)],this_object());
	call_out("offer_flowers",random(10)+20);
}
