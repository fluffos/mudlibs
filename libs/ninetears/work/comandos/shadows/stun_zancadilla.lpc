object my_player;

void destruct_stun_shadow() {
    destruct(this_object());
    }

void setup_shadow(object ob) {
    shadow(ob,1);
    my_player = ob;
    my_player->add_extra_look(TO);
    }

int check_duration() {
    if ( !my_player || !(my_player->query_timed_property("stun_on")) ) {
	if ( my_player ) my_player->remove_extra_look(this_object());
	return 1;
	}
    else return 0;
    }

varargs int move( mixed dest, mixed messout, mixed messin ) {
    if ( check_duration() ) call_out("destruct_stun_shadow",0,0);
    return my_player->move(dest, messout, messin );
    }

int query_hold_spell() { return 1; }

object* query_weapons_wielded() {
    if ( check_duration() ) call_out("destruct_stun_shadow",0,0);
    return ({ this_object() });
    }

int weapon_attack( object him, object me ) {
    tell_object(me, "Aun intentas recuperarte de la caida.\n");
    tell_room(environment(me), me->query_cap_name()+" se revuelve en el suelo sin ningun efecto.\n", me);
    if ( check_duration() ) call_out("destruct_stun_shadow",0,0);
    return 0;
    }

int shield_attack(object him, object me) {
    if (check_duration()) call_out("destruct_stun_shadow",0,0);
    return 0;
    }

void attack_ob(object ob) {
    tell_object(my_player, "Aun intentas recuperarte de la caida!\n");
    if ( check_duration() ) call_out("destruct_stun_shadow",0,0);
    return 0;
    }

string extra_look() { return "Esta aturdido en el suelo.\n"; }

varargs mixed move_player(string dir, string dest, mixed message, object followee, mixed enter) {
    if ( this_player(1) && this_player(1)->query_creator() ) return my_player->move_player(dir, dest, message, followee, enter);
    notify_fail("No puedes arrastrarte en esa direccion.\n");
    if ( check_duration() ) call_out("destruct_stun_shadow",0,0);
    return 0;
    }
