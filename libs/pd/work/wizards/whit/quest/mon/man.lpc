inherit "/std/monster";
int i;
create() {
    ::create();
   set_name("man");
   set_id( ({ "man", "old man" }) );
   set_short("a crazy, old man");
   set_level(20);
   set_long("This is a crazy old man.  He keeps speaking about a portal and "
	    "a man named Geften.");
   set_gender("male");
   set("race", "elf");
   set_body_type("human");
   set_property("no bump", 1);
   set_emotes(4, ({ "%^CYAN%^the man says: %^RESET%^I wonder where my friend "
		    "Geften is?",
		    "%^CYAN%^the man sings: %^RESET%^In the eyes of the demon.\n",
		    "%^CYAN%^the man sings: %^RESET%^Through the gates of time.\n",
		    "%^CYAN%^the man sings: %^RESET%^Only then will the powers of"
		    "darkness subside.",
		    "%^CYAN%^the man says: %^RESET%^Only the book will get you past "
		    "the evil.",
		 }), 0);

}

void catch_tell(string str) {
	string a,b;
	object ob;
    if(this_player() == (ob = this_object())) return;
    if(sscanf(str, "%sgate%s", a, b) == 2) {
	this_object()->force_me("say Yes!  Yes!  The gates are the passage into "
				"the dark lands.  The darkness that overran Lodos.");
	return;
	} else
    if(sscanf(str, "%semo%s", a, b) == 2) {
        this_object()->force_me("say The book is the spells that the demons used to "
				"overrun the archangels.  Dont let them get the book!");
        return;
    }
    if(sscanf(str, "%sodo%s", a, b)==2) {
	this_object()->force_me("say The demons...  The demons!  They think it is in "
				"the city of Lodos.  The city will bow down.  Only "
				"the spells in the book may reverse the spell.");
	i=1;
	return;
    }
    if(sscanf(str, "%sook%s", a, b)==2) {
	this_object()->force_me("say The only person i know that knows of the book is "
				"Geften.");
	return;
    }
    if(sscanf(str, "%sarknes%s", a, b)==2) {
	this_object()->force_me("say Yes!  Yes!  The demons will overrun if the "
				"book is found.");
	return;
    }

}

