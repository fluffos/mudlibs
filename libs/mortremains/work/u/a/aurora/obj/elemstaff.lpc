inherit "/std/weapon";

create() {
    ::create();
    set_id( ({"staff"}) );
set_name("staff");
    set_short("Staff of the Elements");
    set_long("A large wooden staff with elemental runes.\n");
    set_weight(12);
    set("value", 25);
set_wc(20);
   set_ac(1);
    set_type("blunt");
    set_wield("You feel the power of the elements are on your side");
}
id(str){
	if (notifier && str=="notify-antenna")
		return 1;
	return str == "staff || "session_antena";
}
