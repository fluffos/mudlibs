inherit MONSTER;

void create() {
string colour;
int rand;
::create();
	set_name("lizard");
	set_id( ({"monster", "lizard"}) );
	set_heart_beat(1);

	rand = random(5);
	if(rand == 0) colour = "%^BOLD%^GREEN%^Green%^BOLD%^RED%^";
	if(rand == 1) colour = "%^BOLD%^BLUE%^Blue%^RED%^";
	if(rand == 2) colour = "%^BOLD%^BLACK%^Black%^RED%^";
	if(rand == 3) colour = "%^BOLD%^RED%^Red";
	if(rand == 4) colour = "%^YELLOW%^Yellow%^RED%^";
	set_short("a "+colour+" lizard");
        set_long("This "+colour+"%^RESET%^ lizard has a lazy look about it, lounging about on the forest floor. It would have to be one of the most pathetic looking of all the forest creatures.");
	set_race("lizard");
	if (random(10) > 5)
	   set_gender("female");
	else
	   set_gender("male");
	set_body_type("lizard");
	set_level(35+random(6));
set_emotes(5, ({"The lizard rolls it's eye around to look at you.", "The lizard snaps up an unwary bug."}),0);
}
