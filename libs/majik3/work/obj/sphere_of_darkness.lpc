/* Darkness emitting object for darkness spell */
/* Coder : Harum */

inherit ITEM;

create_item () {
	set_light(-4);
	
	call_out("do_destruct", 10 *60);

}

do_destruct () {
	
	object o;
	if (ENV(THOB)) {
	o = ENV(THOB);

	if (living(o))
	emote ("The darkness surrounding $n dissipates.",o, 0, ENV(o));
	else message("spell", "The darkness surrounding "+o->query_maybe_cap_name()+ 
		" dissipates.\n",ENV(o));
	}
	destruct(THOB);

}
