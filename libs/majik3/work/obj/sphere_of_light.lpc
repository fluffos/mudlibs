/* Light emitting object for light spell */
/* Coder : Harum */

inherit ITEM;

create_item () {
	set_light(2);
	set_no_autoload(1);
//	set_no_drop(1);
	call_out("do_destruct", 10 * 60);

}

do_destruct () {
	object o;

	if (ENV(THOB)) {
	o = ENV(THOB);

	if (living(o))
	emote("The light emitting ball beside $n flashes brightly and "
		+"disappears.",o, 0, ENV(o));
	else message("spell", "The light emitting ball beside "
		+o->query_maybe_cap_name()+" flashes brightly and disappears.\n",ENV(o));
	}
	destruct(THOB);


}
