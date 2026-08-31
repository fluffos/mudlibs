# 1 "obj/living.c" 
# 1 "/usr/mud/new/mudlib.2.4.5/room/log.h" 1

























































# 2 "obj/living.c" 2
































int time_to_heal;	
int money;		
string name;		
string msgin, msgout;	
int is_npc, brief;	
int level;		
static int armour_class;	
int hit_point;		
int max_hp, max_sp;
int experience;		
string mmsgout;		
string mmsgin;		
static object attacker_ob;	
static object alt_attacker_ob;	
static int weapon_class;	
static object name_of_weapon;	
static object head_armour;	
int ghost;		
static int local_weight;	
static object hunted, hunter;	
static int hunting_time;	
static string cap_name;	
int spell_points;	
static string spell_name;
static int spell_cost, spell_dam;
int age;		
int is_invis;		
int frog;		
int whimpy;		
string auto_load;	
int dead;		
string flags;		






int alignment;
int gender;	




int Str, Int, Con, Dex;









































move_player(dir_dest, optional_dest_ob)
{
    string dir, dest;
    object ob;
    int is_light, i;

    if (!optional_dest_ob) {
	if (sscanf(dir_dest, "%s#%s", dir, dest) != 2) {
	    tell_object(this_object(), "Move to bad dir/dest\n");
	    return;
	}
    } else {
	dir = dir_dest;
	dest = optional_dest_ob;
    }
    hunting_time -= 1;
    if (hunting_time == 0) {
	if (hunter)
	    call_other(hunter, "stop_hunter");
	hunter = 0;
	hunted = 0;
    }
    if (attacker_ob && present(attacker_ob)) {
	hunting_time = 10;
	if (!hunter)
	    tell_object(this_object(), "You are now hunted by " +
			call_other(attacker_ob, "query_name", 0) + ".\n");
        hunter = attacker_ob;
    }
    is_light = set_light(0);
    if(is_light < 0)
	is_light = 0;
    if(is_light) {
	if (!msgout)
	    msgout = "leaves";
	if (ghost)
	    say("some mist" + " " + msgout + " " + dir + ".\n");
	else if (dir == "X" && !is_invis)
	    say(cap_name + " " + mmsgout + ".\n");
	else if (!is_invis)
	    say(cap_name + " " + msgout + " " + dir + ".\n");
    }
    move_object(this_object(), dest);
    is_light = set_light(0);
    if(is_light < 0)
	is_light = 0;
    if (level >= 20) {
	if (!optional_dest_ob)
	    tell_object(this_object(), "/" + dest + "\n");
    }
    if(is_light) {
	if (!msgin)
	    msgin = "arrives";
	if (ghost)
	    say("some mist" + " " + msgin + ".\n");
	else if (dir == "X" && !is_invis)
	    say(cap_name + " " + mmsgin + ".\n");
	else if (!is_invis)
	    say(cap_name + " " + msgin + ".\n");
    }
    if (hunted && present(hunted))
        attack_object(hunted);
    if (hunter && present(hunter))
        call_other(hunter, "attack_object", this_object());
    if (is_npc)
	return;
    if (!is_light) {
	write("A dark room.\n");
	return;
    }
    ob = environment(this_object());
    if (brief)
	write(call_other(ob, "short", 0) + ".\n");
    else
	call_other(ob, "long", 0);
    for (i=0, ob=first_inventory(ob); ob; ob = next_inventory(ob)) {
	if (ob != this_object()) {
	    string short_str;
	    short_str = call_other(ob, "short");
	    if (short_str)
		write(short_str + ".\n");
	}
	if (i++ > 40) {
	    write("*** TRUNCATED\n");
	    break;
	}
    }
}








hit_player(dam) {
    if (!attacker_ob)
	set_heart_beat(1);
    if (!attacker_ob && this_player() != this_object())
	attacker_ob = this_player();
    else if (!alt_attacker_ob && attacker_ob != this_player() &&
	     this_player() != this_object())
	alt_attacker_ob = this_player();
    
    if (level >= 20 && !is_npc && dam >= hit_point) {
	tell_object(this_object(),
		    "Your wizardhood protects you from death.\n");
	return 0;
    }
    if(dead)
	return 0;	
    dam -= random(armour_class + 1);
    if (dam <= 0)
	return 0;
    if (dam > hit_point+1)
	dam = hit_point+1;
    hit_point = hit_point - dam;
    if (hit_point<0) {
	object corpse;
	
	
	if (!is_npc && !query_ip_number(this_object())) {
	    
	    write(cap_name + " is not here. You cannot kill a player who is not logged in.\n");
	    hit_point = 20;
	    stop_fight();
	    if (this_player())
	        this_player()->stop_fight();
            return 0;
	}

	dead = 1;
	if (hunter)
	    call_other(hunter, "stop_hunter");
	hunter = 0;
	hunted = 0;
	say(cap_name + " died.\n");
	experience = 2 * experience / 3;	
	hit_point = 10;
	
	
	if(attacker_ob) {
	    call_other(attacker_ob, "add_alignment",
		   ((-alignment - 10)/4));
	    call_other(attacker_ob, "add_exp", experience / 35);
	}
	corpse = clone_object("obj/corpse");
	call_other(corpse, "set_name", name);
	transfer_all_to(corpse);
	move_object(corpse, environment(this_object()));
	if (!call_other(this_object(), "second_life", 0))
	    destruct(this_object());
	if (!is_npc)
	    save_object("players/" + name);
    }
    return dam;
}

transfer_all_to(dest)
{
    object ob;
    object next_ob;

    ob = first_inventory(this_object());
    while(ob) {
	next_ob = next_inventory(ob);
	
	if (!call_other(ob, "drop", 1) && ob)
	    move_object(ob, dest);
	ob = next_ob;
    }
    local_weight = 0;
    if (money == 0)
	return;
    ob = clone_object("obj/money");
    call_other(ob, "set_money", money);
    move_object(ob, dest);
    money = 0;
}

query_name() {
    if (ghost)
	return "some mist";
    return cap_name;
}

query_alignment() {
    return alignment;
}

query_npc() {
    return is_npc;
}




attacked_by(ob) {
    if (!attacker_ob) {
	attacker_ob = ob;
	set_heart_beat(1);
	return;
    }
    if (!alt_attacker_ob) {
	alt_attacker_ob = ob;
	return;
    }
}

show_stats() {
    int i;
    write(short() + "\nlevel:\t" + level +
	  "\ncoins:\t" + money +
	  "\nhp:\t" + hit_point +
	  "\nmax:\t" + max_hp +
	  "\nspell\t" + spell_points +
	  "\nmax:\t" + max_sp);
    write("\nep:\t"); write(experience);
    write("\nac:\t"); write(armour_class);
    if (head_armour)
	write("\narmour: " + call_other(head_armour, "rec_short", 0));
    write("\nwc:\t"); write(weapon_class);
    if (name_of_weapon)
	write("\nweapon: " + call_other(name_of_weapon, "query_name", 0));
    write("\ncarry:\t" + local_weight);
    if (attacker_ob)
	write("\nattack: " + call_other(attacker_ob, "query_name"));
    if (alt_attacker_ob)
	write("\nalt attack: " + call_other(alt_attacker_ob, "query_name"));
    write("\nalign:\t" + alignment + "\n");
    write("gender:\t" + query_gender_string() + "\n");
    if (i = call_other(this_object(), "query_quests", 0))
	write("Quests:\t" + i + "\n");
    write(query_stats());
    show_age();
}

stop_wielding() {
    if (!name_of_weapon) {
	
	log_file("wield_bug", "Weapon not wielded !\n");
	write("Bug ! The weapon was marked as wielded ! (fixed)\n");
	return;
    }
    call_other(name_of_weapon, "un_wield", dead);
    name_of_weapon = 0;
    weapon_class = 0;
}

stop_wearing(name) {
    if(!head_armour) {
	
	log_file("wearing_bug", "armour not worn!\n");
	write("This is a bug, no head_armour\n");
	return;
    }
    head_armour = call_other(head_armour, "remove_link", name);
    if(head_armour && objectp(head_armour))
	armour_class = call_other(head_armour, "tot_ac");
    else {
	armour_class = 0;
	head_armour = 0;
    }
    if (!is_npc)
	if(!dead)
	    say(cap_name + " removes " + name + ".\n");
    write("Ok.\n");
}

query_level() {
    return level;
}


query_value() { return 0; }


get() { return 0; }




attack()
{
    int tmp;
    int whit;
    string name_of_attacker;

    if (!attacker_ob) {
	spell_cost = 0;
	return 0;
    }
    name_of_attacker = call_other(attacker_ob, "query_name", 0);
    if (!name_of_attacker || name_of_attacker == "some mist" ||
	environment(attacker_ob) != environment(this_object())) {
	if (!hunter && name_of_attacker &&
	    !call_other(attacker_ob, "query_ghost", 0))
	{
	    tell_object(this_object(), "You are now hunting " +
			call_other(attacker_ob, "query_name", 0) + ".\n");
	    hunted = attacker_ob;
	    hunting_time = 10;
	}
	attacker_ob = 0;
	if (!alt_attacker_ob)
	    return 0;
	attacker_ob = alt_attacker_ob;
	alt_attacker_ob = 0;
	if (attack()) {
	    if (attacker_ob)
		tell_object(this_object(),
			    "You turn to attack " +
			    attacker_ob->query_name() + ".\n");
	    return 1;
	}
	return 0;
    }
    if (spell_cost) {
	spell_points -= spell_cost;
	tell_object(attacker_ob, "You are hit by a " + spell_name + ".\n");
	write("You cast a " + spell_name + ".\n");
    }
    if(name_of_weapon) {
	whit = call_other(name_of_weapon,"hit",attacker_ob);
	if (!attacker_ob) {
	    tell_object(this_object(), "CRACK!\nYour weapon broke!\n");
	    log_file("BAD_SWORD", name_of_weapon->short() + ", " +
		     creator(name_of_weapon) + " XX !\n");
	    spell_cost = 0;
	    spell_dam = 0;
	    destruct(name_of_weapon);
	    weapon_class = 0;
	    return 1;
	}
    }
    if(whit != "miss") {
	tmp = ((weapon_class + whit) * 2 + Dex) / 3;
	if (tmp == 0)
	    tmp = 1;
	tmp = call_other(attacker_ob, "hit_player", 
		    random(tmp) + spell_dam);
    } else
	tmp = 0;
    tmp -= spell_dam;
    if (!is_npc && name_of_weapon && tmp > 20 &&
      random(100) < weapon_class - level * 2 / 3 - 14) {
	tell_object(this_object(), "CRACK!\nYour weapon broke!\n");
	tell_object(this_object(),
		    "You are too inexperienced for such a weapon.\n");
	log_file("BAD_SWORD", name_of_weapon->short() + ", " +
		 creator(name_of_weapon) + "\n");
	spell_cost = 0;
	spell_dam = 0;
	destruct(name_of_weapon);
	weapon_class = 0;
	return 1;
    }
    tmp += spell_dam;
    if (tmp == 0) {
	tell_object(this_object(), "You missed.\n");
	say(cap_name + " missed " + name_of_attacker + ".\n");
	spell_cost = 0;
	spell_dam = 0;
	return 1;
    }
    experience += tmp;
    tmp -= spell_dam;
    spell_cost = 0;
    spell_dam = 0;
    
    if (attacker_ob &&
      call_other(attacker_ob, "query_name", 0) != "some mist") {
	string how, what;
	how = " to small fragments";
	what = "massacre";
	if (tmp < 30) {
	    how = " with a bone crushing sound";
	    what = "smash";
	}
	if (tmp < 20) {
	    how = " very hard";
	    what = "hit";
	}
	if (tmp < 10) {
	    how = " hard";
	    what = "hit";
	}
	if (tmp < 5) {
	    how = "";
	    what = "hit";
	}
	if (tmp < 3) {
	    how = "";
	    what = "grazed";
	}
	if (tmp == 1) {
	    how = " in the stomach";
	    what = "tickled";
	}
	tell_object(this_object(), "You " + what + " " + name_of_attacker +
		    how + ".\n");
	tell_object(attacker_ob, cap_name + " " + what + " you" + how +
		    ".\n");
	say(cap_name + " " + what + " " + name_of_attacker + how +
		    ".\n", attacker_ob);
	return 1;
    }
    tell_object(this_object(), "You killed " + name_of_attacker + ".\n");
    attacker_ob = alt_attacker_ob;
    alt_attacker_ob = 0;
    if (attacker_ob)
	return 1;
}

query_attack() {
    
    return attacker_ob;
    




}

drop_all_money(verbose) {
    object mon;
    if (money == 0)
	return;
    mon = clone_object("obj/money");
    call_other(mon, "set_money", money);
    move_object(mon, environment());
    if (verbose) {
	say(cap_name + " drops " + money + " gold coins.\n");
	tell_object(this_object(), "You drop " + money + " gold coins.\n");
    }
    money = 0;
}


wield(w) {
    if (name_of_weapon)
	stop_wielding();
    name_of_weapon = w;
    weapon_class = call_other(w, "weapon_class", 0);
    say(cap_name + " wields " + call_other(w, "query_name", 0) + ".\n");
    write("Ok.\n");
}


wear(a) {
    object old;

    if(head_armour) {
	old = call_other(head_armour, "test_type", call_other(a, "query_type"));
	if(old)
	    return old;
	old = head_armour;
	call_other(a, "link", old);
    }
    head_armour = a;
    
    armour_class = call_other(head_armour, "tot_ac");
    say(cap_name + " wears " + call_other(a, "query_name", 0) + ".\n");
    write("Ok.\n");
    return 0;
}

add_weight(w) {
    if (w + local_weight > Str + 10 && level < 20)
	return 0;
    local_weight += w;
    return 1;
}

heal_self(h) {
    if (h <= 0)
	return;
    hit_point += h;
    if (hit_point > max_hp)
	hit_point = max_hp;
    spell_points += h;
    if (spell_points > max_sp)
	spell_points = max_sp;
}

restore_spell_points(h) {
    spell_points += h;
    if (spell_points > max_sp)
	spell_points = max_sp;
}

can_put_and_get(str)
{
    return str != 0;
}

attack_object(ob)
{
   if (call_other(ob, "query_ghost", 0))
       return;
   set_heart_beat(1);	
   if (attacker_ob == ob) {
       attack();
       return;
   }
   if (alt_attacker_ob == ob) {
       alt_attacker_ob = attacker_ob;
       attacker_ob = ob;
       attack();
       return;
   }
   if (!alt_attacker_ob)
       alt_attacker_ob = attacker_ob;
   attacker_ob = ob;
   call_other(attacker_ob, "attacked_by", this_object());
   attack();
}

























query_ghost() { return ghost; }

zap_object(ob)
{
    call_other(ob, "attacked_by", this_object());
    say(cap_name + " summons a flash from the sky.\n");
    write("You summon a flash from the sky.\n");
    experience += call_other(ob, "hit_player", 100000);
    write("There is a big clap of thunder.\n\n");
}

missile_object(ob)
{
    if (spell_points < 10) {
	write("Too low on power.\n");
	return;
    }
    spell_name = "magic missile";
    spell_dam = random(20);
    spell_cost = 10;
    attacker_ob = ob;
}

shock_object(ob)
{
    if (spell_points < 15) {
	write("Too low on power.\n");
	return;
    }
    spell_name = "shock";
    spell_dam = random(30);
    spell_cost = 15;
    attacker_ob = ob;
}

fire_ball_object(ob)
{
    if (spell_points < 20) {
	write("Too low on power.\n");
	return;
    }
    spell_name = "fire ball";
    spell_dam = random(40);
    spell_cost = 20;
    attacker_ob = ob;
}





test_if_any_here()
{
    object ob;
    ob = environment();
    if (!ob)
	return;
    ob = first_inventory(environment());
    while(ob) {
	if (ob != this_object() && living(ob) && !call_other(ob, "query_npc"))
	    return 1;
	ob = next_inventory(ob);
    }
    return 0;
}

show_age() {
    int i;

    write("age:\t");
    i = age;
    if (i/43200) {
	write(i/43200 + " days ");
	i = i - (i/43200)*43200;
    }
    if (i/1800) {
	write(i/1800 + " hours ");
	i = i  - (i/1800)*1800;
    }
    if (i/30) {
	write(i/30 + " minutes ");
	i = i - (i/30)*30;
    }
    write(i*2 + " seconds.\n");
}

stop_hunter()
{
    hunter = 0;
    tell_object(this_object(), "You are no longer hunted.\n");
}





force_us(cmd) {
    if (!this_player() || this_player()->query_level() <= level ||
	query_ip_number(this_player()) == 0) {
	tell_object(this_object(), this_player()->query_name() +
	    " failed to force you to " + cmd + "\n");
	return;
    }
    command(cmd);
}


add_money(m) {

    if (this_player() && this_player() != this_object() &&
      query_ip_number(this_player()) && query_ip_number(this_object()) &&
      level < 20 && m >= 10000)
	log_file("EXPERIENCE", ctime(time()) + " " +name + "(" + level + 
		") " + m + " money by " + this_player()->query_real_name() +
		"(" + this_player()->query_level() + ")\n");

    money = money + m;
    if (level <= 19 && !is_npc)
	add_worth(m);
}

query_money() {
    return money;
}

query_exp() {
    return experience;
}

query_frog() {
    return frog;
}

frog_curse(arg) {
    if (arg) {
	if (frog)
	    return 1;
	tell_object(this_object(), "You turn into a frog !\n");
	frog = 1;
	return 1;
    }
    tell_object(this_object(), "You turn HUMAN again.\n");
    frog = 0;
    return 0;
}

run_away() {
    object here;
    int i, j;

    here = environment();
    i = 0;
    j = random(6);
    while(i<6 && here == environment()) {
	i += 1;
	j += 1;
	if (j > 6)
	    j = 1;
	if (j == 1) command("east");
	if (j == 2) command("west");
	if (j == 3) command("north");
	if (j == 4) command("south");
	if (j == 5) command("up");
	if (j == 6) command("down");
    }
    if (here == environment()) {
	say(cap_name + " tried, but failed to run away.\n", this_object());
	tell_object(this_object(),
	    "Your legs tried to run away, but failed.\n");
    } else {
	tell_object(this_object(), "Your legs run away with you!\n");
    }
}

query_hp() {
    return hit_point;
}

query_wimpy() {
    return whimpy;
}

query_current_room() {
    return file_name(environment(this_object()));
}

query_spell_points() {
    return spell_points;
}

stop_fight() {
    attacker_ob = alt_attacker_ob;
    alt_attacker_ob = 0;
}

query_wc() {
    return weapon_class;
}

query_ac() {
    return armour_class;
}

reduce_hit_point(dam) {
    object o;
    if(this_player()!=this_object()) {
	log_file("REDUCE_HP",query_name()+" by ");
	if(!this_player()) log_file("REDUCE_HP","?\n");
	else {
	    log_file("REDUCE_HP",this_player()->query_name());
	    o=previous_object();
	    if (o)
		log_file("REDUCE_HP", " " + file_name(o) + ", " +
			 o->short() + " (" + creator(o) + ")\n");
	    else
		log_file("REDUCE_HP", " ??\n");
	}
    }
    
    hit_point -= dam;
    if (hit_point <= 0)
	hit_point = 1;
    return hit_point;
}

query_age() {
    return age;
}



query_gender() { return gender; }
query_neuter() { return !gender; }
query_male() { return gender == 1; }
query_female() { return gender == 2; }

set_gender(g) {
    if (g == 0 || g == 1 || g == 2)
        gender = g;
}
set_neuter() { gender = 0; }
set_male() { gender = 1; }
set_female() { gender = 2; }

query_gender_string() {
    if (!gender)
	return "neuter";
    else if (gender == 1)
	return "male";
    else
	return "female";
}

query_pronoun() {
    if (!gender)
	return "it";
    else if (gender == 1)
	return "he";
    else
	return "she";
}

query_possessive() {
    if (!gender)
	return "its";
    else if (gender == 1)
	return "his";
    else
	return "her";
}

query_objective() {
    if (!gender)
	return "it";
    else if (gender == 1)
	return "him";
    else
	return "her";
}







set_flag(n) {
    if (flags == 0)
	flags = "";

    log_file("FLAGS", name + " bit " + n + " set\n");
    if (previous_object()) {
	if (this_player() && this_player() != this_object() &&
	  query_ip_number(this_player()))
	    log_file("FLAGS", "Done by " +
		     this_player()->query_real_name() + " using " +
		     file_name(previous_object()) + ".\n");
    }

    flags = set_bit(flags, n);
}

test_flag(n) {
    if (flags == 0)
	flags = "";
    return test_bit(flags, n);
}

clear_flag(n) {
    if (flags == 0)
	flags = "";

    log_file("FLAGS", name + " bit " + n + " cleared\n");
    if (previous_object()) {
	if (this_player() && this_player() != this_object() &&
	  query_ip_number(this_player()))
	    log_file("FLAGS", "Done by " +
		     this_player()->query_real_name() + " using " +
		     file_name(previous_object()) + ".\n");
    }


    flags = clear_bit(flags, n);
    return 1;
}

query_stats() {
    return "str:\t" + Str +
	  "\nint:\t" + Int +
	  "\ncon:\t" + Con +
	  "\ndex:\t" + Dex + "\n";
}

query_str() { return Str; }
query_int() { return Int; }
query_con() { return Con; }
query_dex() { return Dex; }


set_str(i) {
    if (i<1 || i > 20)
	return;
    Str = i;
}

set_int(i) {
    if (i<1 || i > 20)
	return;
    Int = i;
    max_sp = 42 + Int * 8;
}

set_con(i) {
    if (i<1 || i > 20)
	return;
    Con = i;
    max_hp = 42 + Con * 8;
}

set_dex(i) {
    if (i<1 || i > 20)
	return;
    Dex = i;
}
