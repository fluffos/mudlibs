inherit "/obj/monster";

void setup() {
	set_name("aquila");
      	set_short("%^BOLD%^YELLOW%^Aguila%^RESET%^");
     	set_long(query_short()+"\nUna gran aguila de alas y plumas doradas y pico de color negro.\n\n");
	set_main_plural("%^BOLD%^YELLOW%^Aguilas%^RESET%^");
	add_alias("aguila");
	add_plural("aguilas");
	set_gender(0);
	set_level(50+random(5));
	set_random_stats(18, 20);
	set_wimpy(0);
      	set_max_hp(query_level() * 50);
      	set_hp(query_max_hp());
      	set_max_gp(query_level() * 60);
      	set_gp(query_max_gp());
	set_max_ep(query_level() * 20);
      	set_gp(query_max_ep());
}
void init() {
	::init();
	add_action("seguir","sigueme");
	add_action("irse","vete");
} 
int seguir(string str) {
	if(str=="paca") {
		if(TP->query_name()!="maele") {
			TP->attack_by(TO);
			return 1;
		}
		TO->do_command("seguir maele");
		TO->do_command("proteger maele");
		return 1;
	}
	return 0;
}
int irse(string str) {
	if(str=="paca") {
		if(TP->query_name()!="maele") {
			TP->attack_by(TO);
			return 1;
		}
		TO->do_command("noseguir maele");
		TO->do_command("desproteger maele");
		tell_object(TP,"A un gesto tuyo tu aguila se marcha volando.\n");
		tell_room(ENV(TP),TP->query_cap_name()+" hace un gesto y el aguila se marcha entre un fuerte batir de alas.\n");
		TO->dest_me();
		return 1;
	}
	return 0;
}