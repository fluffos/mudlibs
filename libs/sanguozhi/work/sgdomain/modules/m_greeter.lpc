// m_greeter.c
// every object inherited by this is a greeter
nosave private string *defgreet=({ "bow","hi","handshake",
	"jump","greet"});
nosave private string *defleave=({"wave","seeu","kick"});
int is_greeter() {
	return 1;
}
// the final object should override this method
void do_greet(object o) {
	string str;
	string p_id=o->query_primary_id();
	if(!sizeof(defgreet)) return;
	str=defgreet[random(sizeof(defgreet))];

	DELAY_D->delay_emote(this_object(), str,random(2)+1,p_id);

	return;
}

// the final object should override this method
void do_send(object o) {
	string str;
	string p_id=o->query_primary_id();
	if(!sizeof(defleave)) return;
	str=defleave[random(sizeof(defleave))];
	DELAY_D->delay_emote(this_object(), str,random(2)+1,p_id);
	return;
}
void init_meetplace() {
	object env=environment(this_object());
	if(!objectp(env)) return;
	env->set_can_meet(1);
}
void init_greet() {
	call_out("init_meetplace",1);
}
