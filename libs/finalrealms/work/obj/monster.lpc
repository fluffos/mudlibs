/* Baldrick 
   Wonderflug
   Taniwha 1996, moved "brains" to handler object. Not for effiency, just 
   to allow more flexibility	


*/
// If wandering NPC's eat too much CPU
//#define NO_WANDER

#define MIN_PLAYER_LEVEL 5
#define MIN_MONSTER_LEVEL 10
#define MONSTER_HAND "/obj/handlers/monster_hand"
#define MOVE_DEFAULT ({ 300, 300 })
#define SOUL_OBJECT "/obj/handlers/soul"

inherit "/std/living/handle";
inherit "/std/living/mon_actions";
inherit "/std/living/living";
inherit "/global/communicate";
inherit "/global/drunk";
inherit "/global/guild-race";
inherit "/global/spells";

int hb_counter;

mixed *chat_string,    /* ({ ({ int chances }), ({ chat strings }) }) */
*achat_string,         /* ({ ({ int chances }), ({ chat strings }) }) */
*attack_spells;        /* ({ chance, identifier, data, ... }) */

// Taniwha 1995
int p_memory;          /* if !0 will record player names, else won't */
int minplayer; 	       /* minimum player level an NPC will attack, extra param to set_aggressive(), default 0 */
string *p_attack_list; /* names we don't like */

mixed move_after,      /* ({ minimum time, Add'l random time }) */
*throw_out;            /* ({ their hp, % chance, theirmess, elsemess}) */

mixed talk_string;           /* strings we shall watch for when people talk */

int chat_chance,             /* Chance of chatting any given round */
achat_chance,            /* Chance of doing an attack chat any round */
aggressive,              /* level of aggressiveness, >do_aggressive_check*/
follow_speed,            /* how long before we follow someone */
join_fights,             /* Do we join into fights in the room ? */
fight_npcs,		/* fight other NPC's as well as players */
protecting,              /* Am I protecting someone currently ? */
level,                   /* level of the monster */
body_ac,                 /* natural ac */
move_when,               /* how many hbs we shall move */
sneaky,               /* makes me sneak around */
heartheal,
combat_counter,          /* Counts what we should do next in combat */
in_talk;                 /* So stuff I say doesn't get catch_talk'd */



string race,                 /* what race i am */
mclass,               /* what guild i am */
*move_zones,          /* zones that i may wander into */
*protect,             /* People that I am protecting */
*enter_commands,      /* Commands to be done upon entering a room */
join_fight_mess;      /* I shall say this when I join a fight */

mapping loved;	/* How do I love thee, let me count the ways */
mapping hated;  /* ditto hated */	
protected string *story;        /* The current story (set of strings) */
nosave int which_story;      /* which bit of the story to come next */
nosave int hbcheck;	     /* A little patch to avoid slaughtering cowards */

/*** End of local variables ***/

nomask int query_player() { return 0; }

int query_concentrate_valid() { return 1; }
mixed query_consent(string str) { return "on"; }

int query_npc() { return 1; }
int query_monster() { return 1; }
nomask int query_creator() { return 0; }

// Taniwha 1996. Simply for the convenience of it
void add_clone(string what,int num)
{
    object ob;
    int i;
    if(!num) num = 1;
    for(i = 0; i < num; i++)
    {
	ob = clone_object(what);
	if(ob)
	{
	    if(ob->move(this_object()))
	    {
		if(ob && environment(this_object()) )
		{
		    tell_room(environment(this_object()),query_cap_name()+" struggles to hold "+ob->query_cap_name()+
		      " and finally drops it.\n");
		    ob->move(environment(this_object()));
		}
		else ob->dest_me();
	    }
	}
    }
}

void attack_by(object ob)
{
    // For NPC's remember the man who shot my paw ;) Taniwha 1995
    if( p_memory && interactive(ob) && (ob->query_level() > MIN_PLAYER_LEVEL) &&
      member_array(ob->query_name(), p_attack_list) == -1 )
	p_attack_list += ({ (string)ob->query_name() });
    if(p_attack_list)
	do_equip(0);

    ::attack_by(ob);
}

void stop_fight(object ob)
{
    if( ob && interactive(ob) ) 
	p_attack_list -= ({ (string)ob->query_name() });
    ::stop_fight(ob);
}

int player_memory(int i)
{
    p_memory = i;
    return p_memory;
}
int query_player_memory() { return p_memory; }

string *query_p_attacker_list()
{
    return p_attack_list;
}
void remove_p_attack_list() { p_attack_list = ({ }); }


/* This is a utility function. */
int check_props(string prop)
{
    int v;

    v = this_object()->query_property(prop);
    if ( !v ) 
	v = environment(this_object())->query_property(prop);
    return v;
}

int check_anyone_here();
void set_random_stats(int low, int high);
void do_move_after(int bing);
mixed query_attack_spells();

void create()
{
    reset_get();
    join_fights = 0;
    protecting = 0;
    body_ac = 0;
    set_gender(random(3));  
    race_ob = "/std/races/unknown";
    languages = ({ "common" });
    cur_lang = "common";
    follow_speed = 3;
    add_property("determinate", "");
    add_property("npc",1);
    p_attack_list = ({ });
    talk_string = ({ });
    which_story = 0;
    story = ({ });
    chat_string = ({ 0, ({ }) });
    achat_string = ({ 0, ({ }) });
    move_zones = ({ });
    protect = ({ });
    attack_spells = ({ });
    enter_commands = ({ });
    gr_commands = ([ ]);
    loved = ([ ]);
    hated = ([ ]);
    known_commands = ({ });
    enable_commands();
    living_commands();
    handle_commands();
    spell_commands();
    communicate_commands();
    add_property("npc",1);
    /* this is used to get the this_player set right */
    add_action("init_race", "init_race");
    //add_action("do_teach", "teach");
    //why this here?...
    set_random_stats(8,17);
    set_max_hp(2);
    set_thac0(200);
    set_weight(1700);
    combat_counter=0;
    mon_actions::create();
    living::create();
    spells::create();
} /* create() */

int query_cols() { return 200; }

/* This can be masked to get more limbs.. */
int query_limbs() { return 2; }

int soul_commqz(string str)
{
    string verb, bit;

    if (sscanf(str, "%s %s", verb, bit) == 2)
	return (int)SOUL_OBJECT->soul_command(verb, bit, this_object());

    return (int)SOUL_OBJECT->soul_command(str, "", this_object());
} /* soul_commqz() */

int soul_com_force(string str) 
{

    if (file_name(previous_object()) != SOUL_OBJECT)
	return 0;

    command(str);
    return 1;
} /* soul_com_force() */

void set_name(string n)
{
    if (name && name != "object")
	return;
    name = n;
    add_plural(pluralize(name));
    set_short(capitalize(name));
    set_long("You see nothing special.\n");
    set_living_name(n);
} /* set_name() */

string long(string str, int dark)
{
    string s;

    s = query_long();
    s += capitalize(query_pronoun())+" "+health_string()+".\n";
    s += calc_extra_look();
    s += query_living_contents(0);
    return s;
} /* long() */

int set_race(string str)
{
    object ob;
    race = str;
    add_alias(str);
    add_language(str);
    set_language(str);
    ob = load_object("/std/races/"+str);
    if(ob)
    {
	race_ob = "/std/races/"+str;
	race_ob->set_racial_bonuses();
	race_ob->start_player(TO);
    }
    return 1;
} /* set_race() */

string query_race() { return race; }
string query_mclass() { return mclass; }
string query_guild() { return mclass; }

int set_mclass(string str) { mclass = str; } 
int set_guild(string str) { mclass = str; } 

void init_command(string str) { call_out("do_command", 0, str); }
void init_equip() { call_out("do_equip", 0,0); }
void init_race() { race_guild_commands(); } 

int do_command(string str) 
{
    if (stringp(str))
	return command(str);
    else 
	printf("Invalid paramater to do_command %O in monster %O, env %O.\n", str,
	  this_object(), environment());
} /* do_command() */

void do_aggressive_check(object ob)
{
    if(MONSTER_HAND->do_aggressive_check(ob,aggressive,this_object(),minplayer,hated,loved))
    {
	if(stringp(join_fight_mess) && !query_timed_property("no_spam"))
	    tell_room(ETO,(string)MONSTER_HAND->expand_string(TO,join_fight_mess, TO, ob));
	{
	    add_timed_property("no_spam",1,10);
	    attack_ob(ob);
	}
    }
}   /* do_aggressive_check */

void init()
{
    if (!query_heart_beat(this_object()))
    {
	if (check_anyone_here() || sizeof(query_attacker_list()))
	    set_heart_beat(1);
    }
    else
	heartheal++;
    //log_file("baldylog", "Init! " + this_object()->query_short() + "\n");

    ::init();
} /* init() */

void event_enter(object ob, string mess, object from)
{
  if(!ob) return;
    // Taniwha 1995, I remember you you bastard, you attacked me then logged off
    if(interactive(ob) && member_array(ob->query_name(),p_attack_list) != -1)
    {
	attack_by(ob);
	// This should avoid problems with players entering, attacking and repeat
	// yeah, I removed it, taniwha
	{ 
	    attack(); // Taniwha 1995.
	    hbcheck++;
	}	
	return;
    }
    do_aggressive_check(ob);
} /* void event_enter */

int check_anyone_here()
{
    object *arr;
    int i;

    if (!environment())
	return 0;
    arr = all_inventory(environment());
    for (i=0;i<sizeof(arr);i++)
	if (arr[i] && interactive(arr[i]))
	    return 1;
    return 0;
}

void set_move_after(int after, int rand)
{
    move_after = ({ after, rand });
    move_when = (move_after[0] + random(move_after[1]));
}

void set_throw_out(int hps, int chance, string their_mess,string everyone_mess) 
{
    throw_out = ({ hps, chance, their_mess, everyone_mess });
} /* set_throw_out() */

mixed* query_throw_out() { return throw_out; }

varargs void run_away(int bing) 
{
    do_move_after(bing+1);
} /* run_away() */

void expand_mon_string(string str) 
{
    if (!stringp(str)) 
	return;

    switch (str[0]) 
    {
    case ':' :
	tell_room(ETO,this_object()->query_cap_name()+" "+
	  (string)MONSTER_HAND->expand_string(TO,str[1..1000],0,0)+"\n");
	break;
    case '\'' :
    case '"' :
    case '@' :
	command((string)MONSTER_HAND->expand_string(TO,str,0,0));
	break;
    case '#':
	call_other(TO,str[1..1000]);
	break;
    default :
	tell_room(ETO,(string)MONSTER_HAND->expand_string(TO,str,0,0)+"\n");
    }
}

int query_hb_counter() { return hb_counter; }
int query_hb_diff(int oldv)
{
    if(hb_counter > oldv) 
	return (hb_counter - oldv);
    else 
	return (oldv - hb_counter);
}

/* More heart_beat stuff, removing pieces from void heart_beat to make the
 * function less complex.
 * First go is the start and stop of heartbeats.
 * Baldrick, march '95
 */

int check_heart_beat()
{
    if ( hp == max_hp && gp == max_gp &&
      !sizeof(query_attacker_list()) &&
      !check_anyone_here() && !sizeof(query_effects()) )
    {
	set_heart_beat(0);
	protecting = 0;
    }
} /* int check heart_beat */

/* does the basic chat handling */
void chatter(int chance, mixed chat)
{
    int i,j;

    if( !sizeof(chat) ) 
	return;
    if (sizeof(story) )
    {
	if(which_story < sizeof(story))
	    expand_mon_string(story[which_story++]);
	else
	{
	    story = 0;
	    which_story = 0;
	}
    }
    else if( random(1000) < chance )
    {
	i = random(chat[0]+1);
	j=0;
	while ( (i -= chat[1][j]) >0)
	    j += 2;
	if (pointerp(chat[1][j+1]))
	    story = chat[1][j+1];
	else 
	    expand_mon_string(chat[1][j+1]);
    }
}
void combat_heart_beat()
{ 

    int i;
    if ( (max_hp*wimpy/100) > hp && hp > 0) 
    {
	run_away();
// taniwha, don't return here, they may NOT be able to run
    }
    switch(combat_counter++)
    {
    case 0:
	do_spell_effects(this_object());
	if(!sizeof(attack_spells) || !sizeof(attacker_list) ) break;
	MONSTER_HAND->spell_heart_beat(this_object(),attacker_list,attack_spells);
	break;
    case 1:
	chatter(achat_chance, achat_string);
	combat_counter=0;

	if (drunk_heart_beat(query_volume(0)))
	    attack();
	if (!throw_out)
	    break;
	for (i=0;i<sizeof(attacker_list);i++)
	    if (attacker_list[i] && 
	      attacker_list[i]->query_hp() < throw_out[0] &&
	      environment(attacker_list[i]) == ETO &&
	      random(100) < throw_out[1] )
	    {
		if (throw_out[2])
		    tell_object(attacker_list[i], 
		      (string)MONSTER_HAND->expand_string(TO,throw_out[2], 0, attacker_list[i]));
		if (throw_out[3])
		    tell_room(ETO,(string)MONSTER_HAND->expand_string(TO,throw_out[3], 0, attacker_list[i]),
		      attacker_list[i]);
		attacker_list[i]->run_away(1);
	    } /* if (attacker_list */
	break;
    }

}

/* Does the move after thingie called in heart_beat
 * Wonderflug, cut this down to nothing :)
 */
void move_after_heart_beat()
{
    // Taniwha 07 02 97, can't handle the crap uptimes.
#ifdef NO_WANDER
    return;
#endif
    if ( !move_when-- )
    {
	do_move_after(0); //probably change that number.. random ?
	move_when = (move_after[0] + random(move_after[1]) );
    }
    return;
} /* void move_after */

/* This code is *ugly* and it has to be possible to make it cleaner and faster!
 * Hrmf..
 * Well, actually done that now, moved a lot of the stuff in it to their
 * own funtions (right above), they are as ugly as before, but it looks a bit
 * cleaner.
 * Baldrick. march '95
 */
void heart_beat()
{

    hbcheck = 0; // Taniwha, so they don't attack TOO often	
    // Radix was here spet. 1995
    //Don't heal if -neg hps .. if in combat will catch with correct killer obj
    if (query_hp() > -1) 
	adjust_hp(heartheal,this_object());
    adjust_gp(2);
    heartheal = 0;
    hb_counter++;
    if(race_ob && !(hb_counter & 31))  race_ob->race_heartbeat(TO);

    /* This is the attack part.
     * it runs when the monsie is in fight.
     */
    if ( sizeof(attacker_list) || sizeof(call_outed) || sizeof(query_effects()) )
	combat_heart_beat();
    else
	chatter(chat_chance,chat_string);


    if (move_after && !sizeof(attacker_list))
	move_after_heart_beat();

    /* No race objects have this.
     * catch(race_ob->monster_heart_beat(race, mclass, race_ob, guild_ob));
     */

    /* This will start and stop the heartbeats dependant on a lot of
     * variables. this is to lessen the cpu.
     */
    check_heart_beat();

} /* void heart_beat */

/* Utility function */
int rand_num(int low, int max)
{
    return random(max-low)+low+1;
}

void set_random_stats(int low, int max) {
    set_str(rand_num(low, max));
    set_dex(rand_num(low, max));
    set_int(rand_num(low, max));
    set_con(rand_num(low, max));
    set_wis(rand_num(low, max));
    set_cha(rand_num(1,6));  /* CHA now has to do with luck. */
}

/* How many levels do we have? this is a mess.
 * Gonna get rid of these...
 * June '94; not many left, this one is needed.
 * Baldrick..
 */
void set_level(int i)
{
    object guildobject;
   int step;

    if(i > MIN_MONSTER_LEVEL) 
	p_memory = 1;
    if (i < 1) 
	i = 1;
    level = i;
    recalc_stats(i);
    set_hp(query_max_hp(),  this_object());
    reset_all(); //Taniwha 1996
    guildobject = (object)query_guild_ob();
    if (guildobject)
	step = guildobject->query_thac0_step();
    else
	step = 3;
    this_object()->set_thac0( 200 - (i * step) );

    /* why this now? not sure.. */
    init_command("init_race");
}

int give_money(int base, int rand, string type) 
{
    if (!type)
	type = "copper";
    return adjust_money(base+random(rand), type);
}

void load_chat(int chance, string *c_s)
{
    int i;
    for (i=0;i<sizeof(c_s);i+=2)
    {
	chat_string[1] += ({ c_s[i], c_s[i+1] });
	chat_string[0] += c_s[i];
    } /* for.. */
    chat_chance = chance;
}

void set_chat_chance(int i) { chat_chance = i; }
int query_chat_chance() { return chat_chance; }
void set_chat_string(string *chat) { chat_string = chat; }
string *query_chat_string() { return chat_string; }

void add_chat_string(mixed weight, mixed chat)
{
    int i;

    if (pointerp(weight))
	for (i=0;i<sizeof(weight);i+=2)
	    add_chat_string(weight[i], weight[i+1]);
    else
    if (member_array(chat, chat_string[1]) == -1) 
    {
	chat_string[1] += ({ weight, chat });
	chat_string[0] += weight;
    }
}

void remove_chat_string(mixed chat)
{
    int i;

    if (pointerp(chat))
	for (i=0;i<sizeof(chat);i++)
	    remove_chat_string(chat[i]);
    else
    if ((i = member_array(chat, chat_string[1])) != -1) 
    {
	chat_string[0] -= chat_string[1][i-1];
	chat_string[1] = delete(chat_string[1], i-1, 2);
    }
}

void load_a_chat(int chance, string *c_s) 
{
    int i;
    for (i=0;i<sizeof(c_s);i+=2) 
    {
	achat_string[1] += ({ c_s[i], c_s[i+1] });
	achat_string[0] += c_s[i];
    }
    achat_chance = chance;
}

void set_achat_chance(int i) { achat_chance = i; }
int query_achat_chance() { return achat_chance; }
void set_achat_string(string *chat) { achat_string = chat; }
string *query_achat_string() { return achat_string; }

void add_achat_string(mixed weight, mixed chat)
{
    int i;

    if (pointerp(weight))
	for (i=0;i<sizeof(weight);i+=2)
	    add_achat_string(weight[i], weight[i+1]);
    else
    if (member_array(chat, achat_string[1]) == -1) 
    {
	achat_string[1] += ({ chat });
	achat_string[0] += weight;
    }
}


void remove_achat_string(mixed chat) 
{
    int i;

    if (pointerp(chat))
	for (i=0;i<sizeof(chat);i++)
	    remove_achat_string(chat[i]);
    else
    if ((i = member_array(chat, achat_string[1])) != -1) 
    {
	achat_string[0] -= achat_string[1][i-1];
	achat_string[1] = delete(achat_string[1], i-1, 1);
    }
}

void add_move_zone(mixed zone) 
{
    int i;

    if (pointerp(zone))
	for (i=0;i<sizeof(zone);i++)
	    add_move_zone(zone[i]);
    else if (member_array(zone, move_zones) != -1)
	return;
    else
	move_zones += ({ zone });
    if (!move_after)
	set_move_after(MOVE_DEFAULT[0], MOVE_DEFAULT[1]);
}

void set_move_zones(string *zones) 
{
    int i;

    for (i=0;i<sizeof(zones);i++)
	add_move_zone(zones[i]);
}

void remove_move_zone(mixed zone) 
{
    int i;

    if (pointerp(zone))
	for (i=0;i<sizeof(zone);i++)
	    remove_move_zone(zone[i]);
    else 
    {
	if ((i=member_array(zone, move_zones)) == -1)
	    return ;
	move_zones = delete(move_zones, i, 1);
    }
    if ( !sizeof(move_zones) )
	move_after = 0;
}

string *query_move_zones() { return move_zones; } 

void add_protect(mixed shield) 
{
    int i;

    if (pointerp(shield))
	for (i=0;i<sizeof(shield);i++)
	    add_protect(shield[i]);
    else if (member_array(shield, protect) != -1)
	return;
    else
	protect += ({ shield });
}

void set_protect(string *shields) 
{
    int i;

    for (i=0;i<sizeof(shields);i++)
	add_protect(shields[i]);
}

void remove_protect(mixed shield) 
{
    int i;

    if(pointerp(shield))
	for(i=0;i<sizeof(shield);i++)
	    remove_protect(shield[i]);
    else 
    {
	if((i=member_array(shield, protect)) == -1)
	    return;
	protect = delete(protect, i, 1);
    }
}

string *query_protect() { return protect; }

mixed query_move_after() { return move_after; }

int add_enter_commands(mixed str) 
{
    if (stringp(str))
	enter_commands += ({ str });
    else if (pointerp(str))
	enter_commands += str;
    return 1;
}

string *query_enter_commands() { return enter_commands; }

int reset_enter_commands() 
{
    enter_commands = ({ });
}

int move_player(string dir, string dest, mixed message, object followee,
  mixed enter) {
    int i, j;

    i = ::move_player(dir, dest, message, followee, enter);
    protecting = 0;
    if (i) 
    {
	for (j=0;j<sizeof(enter_commands);j++)
	    init_command(enter_commands[j]);
	return i;
    }
    return 0;
}

void set_sneaky(){ sneaky = 1; }
int query_sneak(){ return(sneaky); }

void do_move_after(int bing) 
{
    mixed *direcs,
    *direcstemp;
    int i,dd, bong;
    string zone;

    if(!ETO)
    {
	call_out("dest_me",0);
	return;
    }

    direcstemp = (string *)environment()->query_dest_dir();
    direcs = ({});
    for(dd=0;dd<sizeof(direcstemp);dd+=2){
	if(find_object(direcstemp[dd+1])){
	    direcs += direcstemp[dd..dd+1];
	}
    }
    while (!bong && sizeof(direcs)) 
    {
	i = random(sizeof(direcs)/2)*2;

	bong = 0;
	if (bing > 1)
	    catch(bong = (int)direcs[i+1]->query_property("no throw out"));
	catch(zone = (string)direcs[i+1]->query_zone());
	if (sizeof(move_zones) || bong)
	    if (bong || member_array(zone, move_zones) == -1) 
	    {
		direcs = delete(direcs, i, 2);
		continue;
	    } /* if (bong */

	if(sneaky)
	{
	    "/std/commands/sneak"->sneak(direcs[i],this_object());
	    break;
	}
	else 
	    bong = command(direcs[i]);
	if (!bong)
	    direcs = delete(direcs, i, 2);
    } /* while */
} /* do_move_after() */


void set_talk_string(mixed arr) { talk_string = arr; }
mixed query_talk_string() { return talk_string; }

void add_talk_string(string cat, mixed do_this) 
{
    talk_string += ({ cat, do_this });
}

void remove_talk_string(string cat) 
{
    int i;

    if ((i=member_array(cat, talk_string)) == -1)
	return ;
    talk_string = delete(talk_string, i, 2);
}

void catch_talk(string str) 
{
    string s1, s2;
    int i;

    if (in_talk)
	return ;

    in_talk = 1;
    for (i=0;i<sizeof(talk_string);i+=2)
	if (sscanf(str, "%s"+talk_string[i]+"%s", s1, s2))
	    if (stringp(talk_string[i+1]))
		call_other(this_object(), talk_string[i+1], str, s1, s2);
	    else if (pointerp(talk_string[i+1]))
		call_other(talk_string[i+1][0], talk_string[i+1][1], str, s1, s2);
    in_talk = 0;
}
void pile_in(object ob,object ob1)
{
    if(ob != TO && (interactive(ob) || fight_npcs) )
    {
	if( !attacker_list || member_array(ob, attacker_list) == -1)
	{
	    if(!attacker_list)
	    {
		if(stringp(join_fight_mess))
		    tell_room(ETO,(string)MONSTER_HAND->expand_string(TO,join_fight_mess, TO, ob));
		else tell_room(ETO,query_cap_name()+" piles into the fight !.\n");
	    }
	    attack_ob(ob);
	}
    }
    if(ob != TO && ob1 != TO &&  sizeof(protect) && !protecting )
    {
	if(!interactive(ob) && member_array(ob->query_name(), protect) != -1)
	{
	    tell_room(ETO,capitalize(query_short())+" jumps into the fray to protect "+
	      ob->query_short()+".\n");
	    attack_ob(ob1);
	    protecting = 1;
	}	
    }

}	

void event_fight_in_progress(object one, object two) 
{
    if(join_fights)
    {
	attacker_list -= ({ 0 });
	pile_in(one,two);
	pile_in(two,one);
    }	
}

// Added by Wonderflug.  To fix add_protect.
void event_death(object ob, object* obs)
{
    if ( ob == this_object() )
	return ;
    else
	protecting = 0;
}

void set_join_fight_mess(string str) { join_fight_mess = str; }
varargs void set_join_fights(int npcs)
{
    join_fights = 1;
    fight_npcs = npcs;
}

string query_join_fight_mess() { return join_fight_mess; }
int query_join_fights() { return join_fights; }

void set_al(int i) { alignment = i; }
int query_al() { return alignment; }
int query_align() { return alignment; }
void set_align(int i) { alignment = i; }
void set_alignment(int i) { alignment = i; }
int query_alignment() { return alignment; }

void event_exit(object me, string mess, mixed ob) 
{
    mixed *bing;
    int i;
    string zone;

    if (!move_after) /* we dont move :( */
	return ;
    /* follow the suckers. */
    if (member_array(me, attacker_list) != -1) 
    {
	bing = (mixed *)environment()->query_dest_dir();
	if ((i = member_array(ob, bing)) == -1) 
	{
	    if (!objectp(ob))
		ob = find_object(ob); /* arhghh must have teleported... scums. */
	    else
		ob = file_name(ob);
	    if ((i = member_array(ob, bing)) == -1)
		return ; /* lost cause */
	}
	zone = (string)ob->query_move_zone();
	if (move_zones && sizeof(move_zones))
	    if (member_array(zone, move_zones) == -1) 
	    {
		return ; /* If we are suppose to wander in move_zones.. dont go
			  * where we are not supposed to... get stuck */
	    }
	remove_call_out("do_follow_move");
	call_out("do_follow_move", 2+random(follow_speed), bing[i-1]);
    }
}

void do_follow_move(string dir) { command(dir); }

int add_attack_spell(int chance, string name, mixed obj) 
{
    int i;

    if ((i=member_array(name, attack_spells)) == -1)
	attack_spells += ({ chance, name, obj  });
    else 
    {
	attack_spells[i-1] = chance;
	attack_spells[i+1] = obj;
    }
    return 1;
}

int remove_attack_spell(string name) 
{
    int i;

    if ((i=member_array(name, attack_spells)) == -1)
	return 0;
    attack_spells = delete(attack_spells, i-1, 3);
    return 1;
}

mixed query_attack_spells() { return attack_spells; }

mixed query_race_ob() { return race_ob; }
void set_race_ob(mixed r) { race_ob = r; }

mixed query_guild_ob() { return guild_ob; }
void set_guild_ob(mixed g) { guild_ob = g; }
int query_follow_speed() { return follow_speed; }
void set_follow_speed(int f) { follow_speed = f; }

int query_aggressive() { return aggressive; }
varargs void set_aggressive(int a , int level)
{
    aggressive = a;
    minplayer = level;
}

int query_level() { return level; }


mixed *stats() 
{
    mixed *zone,
    *shield;
    int i;

    zone = ({ });
    shield = ({ });
    for (i=0;i<sizeof(move_zones);i++)
	zone += ({ ({ "Move zone "+i, move_zones[i] }) });
    for (i=0;i<sizeof(protect);i++)
	shield += ({ ({ "Protect "+i, protect[i] }) });
    if (!query_move_after())
	return ::stats() + ({
	  ({ "guild", query_guild() }),
	  ({ "guild ob", query_guild_ob() }),
	  ({ "race", query_race() }),
	  ({ "race ob", query_race_ob() }),
	  ({ "join_fights", query_join_fight_mess() }),
	  ({ "follow speed", query_follow_speed() }),
	  ({ "level", level }),
	  ({ "chat chance", query_chat_chance() }),
	  ({ "achat chance", query_achat_chance() }),
	  ({ "alignment", query_al() }),
	  ({ "aggressive", query_aggressive() }),
	}) + zone + shield;
    return ::stats() + ({
      ({ "race", query_race() }),
      ({ "race ob", query_race_ob() }),
      ({ "guild", query_guild() }),
      ({ "guild ob", query_guild_ob() }),
      ({ "ac", body_ac }),
      ({ "follow_speed", query_follow_speed() }),
      ({ "level", level }),
      ({ "chat chance", query_chat_chance() }),
      ({ "achat chance", query_achat_chance() }),
      ({ "alignment", query_al() }),
      ({ "aggressive", query_aggressive() }),
      ({ "move after-fix", query_move_after()[0] }),
      ({ "move after-rand", query_move_after()[1] }),
    }) + zone + shield;
}

string expand_nickname(string str) { return str; }

// Added by Asmodean to make em go away like good monies
// Its 2:30am, give me a break.
int clean_up(int used)
{
    return ::clean_up(used);
}

mapping add_hated(string type,mixed targets)
{
    hated[type] = targets;
    return hated;
}
mapping	add_loved(string type,mixed targets)
{
    loved[type] = targets;
    return loved;
}

