inherit MONSTER;

void create() {
string colour;
int rand;
::create();
	set_name("snake");
	set_id( ({"monster", "snake"}) );
	set_heart_beat(1);

	rand = random(5);
	if(rand == 0) colour = "%^BOLD%^GREEN%^Green%^BOLD%^RED%^";
	if(rand == 1) colour = "%^BOLD%^BLUE%^Blue%^RED%^";
	if(rand == 2) colour = "%^BOLD%^BLACK%^Black%^RED%^";
	if(rand == 3) colour = "%^BOLD%^RED%^Red";
	if(rand == 4) colour = "%^YELLOW%^Yellow%^RED%^";
	set_short("a "+colour+" snake");
	set_long("The snakes in this forest are evil creatures that steal the unborn eggs of other creatures and slowly devour them. They slither under the scrub and strike from the shadows.");
        set_race("snake");
	if (random(10) > 5)
	   set_gender("female");
	else
	   set_gender("male");
	set_body_type("snake");
	set_level(35+random(6));
set_emotes(5, ({"The snake flicks it's tongue out at you, searching for flesh." }),0);
	set_alignment(-1000);
}
