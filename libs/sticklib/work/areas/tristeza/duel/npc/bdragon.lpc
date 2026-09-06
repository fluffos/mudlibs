/**************************

    Black seven headed
	  Dragon.

   Design & code by Tron.

 **************************/

#include <npc.h>
#include <attack.h>
#include <areas.h>

#define HP 2500
#define HEAD_DIES HP/7
#define HEAD_DEATH_HP (heads-1)*HEAD_DIES
#define NAME capitalize(name)

int heads;           /* The amount of heads alive */
string *num;
string *chat;
string *chat_2;
string *head_desc;
int answer;
status nolook;

status
id(string str) {

    if(!::id(str)) {
	switch (str) {

	case "juhani": write("The oldest head.\n");
	    break;
	case "aapo":   write("The wisest head.\n");
	    break;
	case "simeoni":write("The head with beard.\n");
	    break;
	case "timo":   write("Just a head.\n");
	    break;
	case "lauri":  write("The meditating head.\n");
	    break;
	case "eero":   write("The sneaky head.\n");
	    break;
	case "tuomas": write("The holy head.\n");
	    break;

	default: return 0;
	}
	nolook=1;
    }
    return 1;
}


string
query_long() {

    if(nolook) {
	nolook=0;
	return "";
    }

    return ::query_long();
}


void
create_monster()
{
    set_name("black dragon");
    set_race("dragon");

    set_short("Seven-headed black dragon");
    set_long("Its wings seem too weak to carry the over-sized body. "+
      "It's Big, fat, and angry. Even the breath smells bad.");

    set_level(30);
    set_hp(HP);
    set_ep(3000000);
    set_alignment(AL_VERY_EVIL);
    set_random_pick(20);
    armour_class = 40; //set_ac(20);
    weapon_class = 55; //set_wc(30);
    set_keep_hb(1);

    set_spell_chance(10);
    set_spell_mess1("Black dragon blows a BRIGHT FLAME burning surrounings.");
    set_spell_mess2("Black dragon blows a dangerous and BURNING FLAME at you.");
    set_spell_dam(150);

    load_chat(2,
      ({
	"Dragon moves its tail lazily.",
	"Dragon spreads its wings wide open and pulls them back again.",
	"One of the heads puffs a small smoke cloud in the air.",
	"Dragon inspects its claws and cuts one of them a bit shorter.",
      }));

    num=({ "one", "two", "three", "four", "five", "six"});
    head_desc= ({"Juhani", "Tuomas", "Aapo", "Simeoni", "Timo",
      "Lauri", "Eero"});

    chat=({
      "says: What's for dinner?",
      "says: I had a weird dream last night, any of you saw it?",
      "clears its throat: AAARRRGGGHHHHHMMMM!",
      "yells: Damn, who of you took my tooth picks?",
      "coughs violently.",
      "burps looooong and loudly.",
      "glances at you and says: Get me the heart of the white dragon!",
      "yells at you: Go, kill the white dragon for a change!",
      "grins with its yellow teeth 'shining'.",
      "groans at you: Get me something to eat, slave!",
      "starts snoring...",
    });

    chat_2=({
      "comments: The same thing as usual...roasted human.\n",
      "says: Hmmm...was it about naked dragon lady on the beach?\n",
      "says: I have told you not to smoke! When do you learn?\n",
      "swallows something and says: Those were yours?\n",
      "says: Too much carbon monoxide?\n",
      "screams: Oh, God! Someone cut me loose!\n",
      "says: I almost had forgotten that bitch. Yeah, bring the heart.\n",
      "giggles: You have to be kidding. That poor shrimp? Kill us?!?!\n",
      "sighs: Ok, I believe you. You didn't use my toothbrush.\n",
      "adds: For me too or you will be my afternoon snack.\n",
      "yells: Wake up you lazy sod!!!\n",
    });

    set_dead_ob(this_object());

    heads=7;
    answer=-1;
}

void
head_dies() {

    string *tmp;

    tmp=({
      "\n"+NAME+"'s head just explodes with a shower of blood and smoke.\n\n",
      "\nOne of the heads drops down dead and bleading.\n\n",
      "\n"+NAME+" coughs blood and a puf of smoke rises up from the cut throat.\n\n",
      "\n"+NAME+" roars in pain and one head partly cuts off blood spilling around.\n\n",
      "\n'CHOP' - The Dragon's brain is all over your face.\n\n",
      "\n"+NAME+"'s head cuts off neatly leaving the throat foaming and bleeding.\n\n",
    });

    say(tmp[random(sizeof(tmp))]);
    if (heads) {
	say(NAME+" has still "+num[heads-1]+" heads left.\n");
	set_short(capitalize(num[heads-1])+"-headed black dragon");
    }
    else say(NAME+" has lost all the heads.\n");
    move_object(clone_object(AREA_TRISTEZA "duel/obj/dhead"), environment());
    if(heads < 3) set_chance(30);
}

int
hit_player(int amount, int dtype, int hc, object enemy)
{
    int i;

    if ((amount > (i=random(80)+10)) && (amount < 250 )) {
	say(NAME+"'s scales reduce the impact.\n");
	amount=i;
    }
    if (hit_point-amount < HEAD_DEATH_HP) {
	heads--;
	head_dies();
	set(NPC_AGGRESSIVE);
	set_wander((7-heads)*2, ({ "north", "south", "west", "east" })); 
    }
    return ::hit_player(amount, dtype, hc, enemy);
}

// Added a kludge as "reduce_hp" exists no more. -+ Doomdark +-
void
add_hp(int hp)
{
    int i;

    if(hp > -1) {
	::add_hp(hp);
	return;
    }

    hp = -hp;
    if(hp > (i = random(80)+10) && hp < 250) {
	say(NAME+"'s scales reduce the impact.\n");
    }
    else i=hp;
    i = -i;
    ::add_hp(i);
}

void
query_plr_dying() {

    object ob;
    object ob2;

    ob=first_inventory(environment());

    while(ob) {

	if(ob!=attacker_ob && ob!=alt_attacker_ob)
	{
	    ob=next_inventory(ob);
	    continue;
	}
	ob2=next_inventory(ob);
	if(living(ob))
	    if(ob->query_hp() < 0) {
		say ("One of the head reaches down for "+ob->query_name()+"'s"+
		  "body and\nand tears it in neat one pound pieces.\n",({ob}));
		ob -> tell_me("The black dragon reaches down to you... *CRUNCH*");
		ob -> hit_player(100, DT_BITE, 0, this_object());
		// Should die in this. Note we need to use all damage types. -+ Doomdark +-
	    }
	ob=ob2;
    }  
}     

int last_head;

string
active_head() {

    int i;

    i=random(heads);
    if(heads < 2 || i==last_head) return 0;

    last_head=i;
    return head_desc[i];
}

void
init_monster()
{


    if((int)this_player()->query_coder_level() < 10) {
	if(this_player()->query_invis()) {
	    this_player()->tell_me(
	      sprintf("%s groans: You puny low life scum, I can see you!\n\
%s draws breath consuming all the air. You feel dizzy.", NAME, NAME));
	    this_player()->vis();
	    this_player()->run_away();
	}
    }
}

void
heart_beat() {

    int attacks;
    int i;
    string tmp;

    /* This beast has many attacks */

    if (answer!=-1) {
	tmp=active_head();
	if(tmp) say(tmp+" "+chat_2[answer]);
	answer=-1;
    } 
    if (attacker_ob && present(attacker_ob)) {
	attacks=random(heads)+1;
	while(i++ < attacks-1) {
	    if(alt_attacker_ob) {
		attacker_ob=alt_attacker_ob;
		alt_attacker_ob=0;
	    }
	    ::heart_beat();
	}
    }
    else if (!random(20) && answer==-1 && heads > 1) {

	i=random(sizeof(chat));
	tmp=active_head();
	if(tmp) {
	    say(tmp+" "+chat[i]);
	    answer=i;
	}
    }
    else answer=-1;

    if(!random(10)) {
	add_hp(random(40)); // We add hit_points.
	if (heads < 7)
	    if ((HEAD_DEATH_HP + HEAD_DIES) < hit_point) {
		heads++;
		set_chance(0);
		if(heads==7) {
		    tmp="Seven";
		    set(NPC_NOT_AGGRESSIVE);
		}
		else tmp=capitalize(num[heads-1]);
		set_short(tmp+"-headed black dragon");
		environment()->tell_here(sprintf("%s grows a new head with amazing speed!",
		    NAME), this_object());
	    }
    }
    query_plr_dying();

    ::heart_beat();
}

void
monster_died() {

    object ob;
    object tmp;
    object ob2;

    ob=present("corpse", environment());
    ob2 = clone_object(AREA_TRISTEZA "duel/obj/dragon_corpse");

    while(tmp=first_inventory(ob)) move_object(tmp, ob2);

    if (ob) destruct(ob);

    ob2->set_name("dragon");
    ob2->set_orig_name(capitalize(name));
    ob2->set_orig_level(level);

    move_object(ob2, environment());
}

void
blow_fire(string where) {

    object room, ob, ob2;
    string tmp;
    string *rooms;
    int i;

    rooms = (string *)environment()->query_dest_dir();
    if(!rooms) return;

    i=member(rooms, where);

    if(i==-1) return;
    i--;

    room=find_object(rooms[i]);
    if(!room) return;

    ob=first_inventory(room);

    say(NAME+" blows a burning flame to the "+where+".\n");

    while(ob) {
	ob2=next_inventory(ob);
	if (living(ob))
	    ob -> hit_player(10 + random(141), DT_FIRE, 0, this_object());
	ob=ob2;
    }
    tell_room(room, 
      "AAAAARRRRGGHHhh...you are blinded by a bright burning flame!!!\n");
}

void
catch_tell(string s) {
    string who, where;

    if(!s) return;

    if(this_player() == this_object()) return;

    if(sscanf(s, "%s leaves %s.", who, where) == 2) {
	if (query(NPC_AGGRESSIVE))
	    call_out("blow_fire", 3, where);
    }
}

void
set_condition(int a, int b, object x)
{
    // Note new argument! -+ Doomdark +-

    if(b > 1) b = 1;
    ::set_condition(a, b, x);
}
