# 1 "obj/monster.c" 


























# 1 "obj/living.h" 1








inherit "obj/living";
# 28 "obj/monster.c" 2





string short_desc, long_desc, alias, alt_name, race;
int move_at_reset, aggressive;
object kill_ob;
status healing;		

string chat_head;	
int chat_chance;

string a_chat_head;	
int a_chat_chance;

object talk_ob;
string talk_func;	
string talk_match;	
string talk_type;	
string the_text;
int have_text;


object dead_ob;
object init_ob;

int random_pick;

int spell_chance, spell_dam;
string spell_mess1, spell_mess2;
object me;
object create_room;

reset(arg)
{
    if (arg) {
	if (move_at_reset)
	    random_move();
	return;
    }
    is_npc = 1;
    enable_commands();
    me = this_object();
    create_room = environment(me);
}

random_move()
{
    int n;
    n = random(4);
    if (n == 0)
	command("west");
    else if (n == 1)
	command("east");
    else if (n == 2)
	command("south");
    else if (n == 3)
	command("north");
}

short() {
    return short_desc;
}

long() {
    write (long_desc);
}

id(str) { return str == name || str == alias || str == race || str == alt_name; }

heart_beat()
{
    int c;

    age += 1;
    if(!test_if_any_here()) {
	if(have_text && talk_ob) {
	    have_text = 0;
	    test_match(the_text);
	} else {
	    set_heart_beat(0);
	    if (!healing)
		heal_slowly();
	    return;
	}
    }
    if (kill_ob && present(kill_ob, environment(this_object()))) {
	if (random(2) == 1)
	    return;		
	attack_object(kill_ob);
	kill_ob = 0;
	return;
    }
    if (attacker_ob && present(attacker_ob, environment(this_object())) &&
      spell_chance > random(100)) {
	say(spell_mess1 + "\n", attacker_ob);
	tell_object(attacker_ob, spell_mess2 + "\n");
	call_other(attacker_ob, "hit_player", random(spell_dam));
    }
    attack();
    if (attacker_ob && whimpy && hit_point < max_hp/5)
	run_away();
    if(chat_chance || a_chat_chance){
	c = random(100);
	if(attacker_ob && a_chat_head) {
	    if(c < a_chat_chance){
		c = random(sizeof(a_chat_head));
		tell_room(environment(), a_chat_head[c]);
	    }
	} else {
	    if(c < chat_chance && chat_chance){
		c = random(sizeof(chat_head));
		tell_room(environment(), chat_head[c]);
	    }
	}
    }
    if(random_pick) {
	c = random(100);
	if(c < random_pick)
	    pick_any_obj();
    }
    if(have_text && talk_ob) {
	have_text = 0;
	test_match(the_text);
    }
}

can_put_and_get(str)
{
    if (!str)
	return 0;
    return 1;
}

int busy_catch_tell;

catch_tell(str) {
    if (busy_catch_tell)
	return;
    busy_catch_tell = 1;
    if(talk_ob) {
	if(have_text) {
	    test_match(the_text);
	    the_text = str;
	} else {
	    the_text = str;
	    have_text = 1;
	}
    }
    busy_catch_tell = 0;
}






set_name(n) {
    name = n;
    set_living_name(n);
    alignment = 0;		
    cap_name = capitalize(n);
    short_desc = cap_name;
    long_desc = "You see nothing special.\n";
}

set_level(l) {
    level = l;
    Str = l; Int = l; Con = l; Dex = l;
    weapon_class = level/2 + 3;
    armour_class = level/4;
    hit_point = 50 + (level - 1) * 8;	
    max_hp = hit_point;
    spell_points = max_hp;
    experience = call_other("room/adv_guild", "query_cost", l-1);
    
    if (experience == 0)
	experience = random(500);
}


set_alias(a) { alias = a; }

set_alt_name(a) { alt_name = a; }

set_race(r) { race = r; }

set_hp(hp) { max_hp = hp; hit_point = hp; }

set_ep(ep) { if (ep < experience) experience = ep; }

set_al(al) { alignment = al; }

set_short(sh) { short_desc = sh; long_desc = short_desc + "\n";}

set_long(lo) { long_desc = lo; }

set_wc(wc) { if (wc > weapon_class) weapon_class = wc; }

set_ac(ac) { if (ac > armour_class) armour_class = ac; }

set_move_at_reset() { move_at_reset = 1; }




set_aggressive(a) {
    aggressive = a;
}






set_chance(c) {
    spell_chance = c;
}

set_spell_mess1(m) {
    spell_mess1 = m;
}
set_spell_mess2(m) {
    spell_mess2 = m;
}
set_spell_dam(d) {
    spell_dam = d;
}


set_frog() {
    frog = 1;
}


set_whimpy() {
    whimpy = 1;
}






init_command(cmd) {
    command(cmd);
}

load_chat(chance, strs) {
    sizeof(strs);		
    chat_head = strs;
    chat_chance = chance;
}



load_a_chat(chance, strs) {
    sizeof(strs);		
    a_chat_head = strs;
    a_chat_chance = chance;
}



set_match(ob, func, type, match) {
    object old;

    if (sizeof(func) != sizeof(type) || sizeof(match) != sizeof(type))
	return;
    talk_ob = ob;
    talk_func = func;
    talk_type = type;
    talk_match = match;
    say("talk match length " + sizeof(func) + "\n");
}

set_dead_ob(ob)
{
    dead_ob = ob;
}

second_life()
{
    if(dead_ob)
	return call_other(dead_ob,"monster_died",this_object());
}

set_random_pick(r)
{
    random_pick = r;
}

pick_any_obj() {
    object ob;
    int weight;

    ob = first_inventory(environment(this_object()));
    while(ob) {
	if (call_other(ob, "get", 0) && call_other(ob, "short")) {
	    weight = call_other(ob, "query_weight", 0);
	    if (!add_weight(weight)) {
		say(cap_name + " tries to take " + call_other(ob, "short", 0) +
		    " but fails.\n");
		return;
	    }
	    move_object(ob, this_object());
	    say(cap_name + " takes " + call_other(ob, "short", 0) + ".\n");
	    if (call_other(ob, "weapon_class", 0))
		call_other(ob, "wield", call_other(ob,"query_name"));
	    else if (call_other(ob, "armour_class", 0))
		call_other(ob, "wear", call_other(ob,"query_name"));
	    return;
	}
	ob = next_inventory(ob);
    }
}

set_init_ob(ob)
{
    init_ob = ob;
}

init() {

    create_room = environment(me);
    if(this_player() == me)
	return;
    if(init_ob)
	if(call_other(init_ob,"monster_init",this_object()))
	    return;
    if (attacker_ob) {
	set_heart_beat(1); 
    }
    if(this_player() && !call_other(this_player(),"query_npc")) {
	set_heart_beat(1);
	if (aggressive == 1)
	    kill_ob = this_player();
    }
}

query_create_room() { return create_room; }

query_race() { return race; }

test_match(str) {
    string who, str1, type, match, func;
    int i;

    while(i < sizeof(talk_match)) {
	if (talk_type[i])
	    type = talk_type[i];
	match = talk_match[i];
	if (match == 0)
	    match = "";
	if (talk_func[i])
	    func = talk_func[i];
	if (sscanf(str,"%s " + type + match + " %s\n",who,str1) == 2 ||
	   sscanf(str,"%s " + type + match + "\n",who) == 1 ||
	   sscanf(str,"%s " + type + match + "%s\n",who,str1) == 2 ||
	   sscanf(str,"%s " + type + " " + match + "\n",who) == 1 ||
	   sscanf(str,"%s " + type + " " + match + " %s\n",who,str1) == 2)
	{
	    return call_other(talk_ob, func, str);
	}
	i += 1;
    }
}




heal_slowly() {
    hit_point += 120 / (10 * 2);
    if (hit_point > max_hp)
	hit_point = max_hp;
    spell_points += 120 / (10 * 2);
    if (spell_points > max_hp)
	spell_points = max_hp;
    healing = 1;
    if (hit_point < max_hp || spell_points < max_hp)
	call_out("heal_slowly", 120);
    else
	healing = 0;
}
