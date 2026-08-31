inherit MONSTER;

void create() {
string colour;
int rand;
::create();
	set_name("tiger");
	set_id( ({"monster", "tiger"}) );
	set_heart_beat(1);

	rand = random(2);
	if(rand == 0) colour = "%^BOLD%^RED%^Red%^BOLD%^RED%^";
	if(rand == 1) colour = "%^BOLD%^WHITE%^White%^RED%^";
	set_short("a "+colour+" tiger");
	set_long("The tiger is a fearsome animal, capable of killing most other creatures, it's claws and teeth can rip flesh from bone. A fearsome creature.");
	set_race("tiger");
	if (random(10) > 5)
	   set_gender("female");
	else
	   set_gender("male");
	set_body_type("feline");
	set_level(39+random(3));
	set_alignment(0);
}
