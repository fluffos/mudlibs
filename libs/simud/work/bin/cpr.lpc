int main(string str) {
	object ob;
	if (str) {
		ob = find_player(str);
		if (!ob) {
			msg("Sorry, I was unable to find any player by that name to perform CPR on.");
			return 1;
		}
	} else
		ob = this_player();
	ob->cpr();
	msg("~CBRTYou perform CPR on "+ob->query_cap_name()+".~CDEF");
	if (this_player() != ob)
		msg_object(ob,"~CBRT"+this_player()->query_cap_name()+" has restored your heartbeat.~CDEF");
	return 1;
}
