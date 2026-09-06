/*
**
** orc.c
**
** (c) Tron.
**
*/

#include <npc.h>
#include <conditions.h>
#include <areas.h>

#define CODER this_player()->query_coder_level()
#define ATTACK  0
#define FBACK   1

status dattack;
object old_attack;

void
l_chat() {

    string nam;

    nam = query_name();

    load_chat (10, ({
	nam+" sticks his finger in his nose.",
	nam+" scratches his ass.",
	nam+" says: And what are you looking at?",
	nam+" clears his voice: Grrrrhhhmmm...",
	nam+" says: You better move out!",
	nam+" moves around nervously.",
	nam+" glares at you.",
	nam+" spits on the ground.",
	nam+" grinds his teeth.",
	nam+" laughs: What a wimp!",
	nam+" says: The black dragon is my master.",
	nam+" says: Go away!",
	nam+" shows you his middle finger!",
	nam+" farts loudly."
      }));

    load_a_chat(20, ({
	nam+" yells: Hey everybody! There is one wimp here again!",
	nam+" growls: There you go, and there! Ha! Soon you'll die!",
	nam+" glares at you and mumbles something.",
	nam+" says: Others don't bother, this hunk is mine!",
	nam+" spits on you.",
	nam+" says: Even my mom is more beautiful than you are.",
	nam+" whines in pain: AUUUUUUUUUHhhhh!",
	nam+" kicks you painfully.",
	nam+" bites you.",
	nam+" screams: Kill! Kill! Kill!",
	nam+" growls: I want the ears!",
	nam+" yells: OUCH! My toe!",
	nam+" screams: I want the eyes!",
	nam+" shouts: Mom, put the cauldron on fire!",
	nam+" says: Let me show you my triple swing!!!",
	nam+" giggles: Oh my, this one has dirty underwear!",
	nam+" aims his strike at you with his tongue sticking out.",
      })); 

}


void
create_monster()
{
    string *tmp;
    object ob;
    string str;
    int i;


    tmp = ({
      "short", "fat", "huge", "smirking",
      "limpy", "grinning", "smelling",
      "ugly", "angry", "skinny", "tired",
      "bug-eyed", "big-nosed", "hairy",
      "sweating", "tiny", "one-handed",
      "giant", "noseless", 
    });

    str = tmp[random(sizeof(tmp))];
    set_name(str+" orc");
    set_race("orc");
    str = capitalize(str);
    set_short(str+" orc");
    set_long("A hostile looking and pale green orc.\n");
    set_race("orc");
    set_level(i=random(14)+1);
    set_hp(i*8+60);
    set(random(2) ? NPC_AGGRESSIVE : NPC_NOT_AGGRESSIVE);
    set_wimpy(10);
    set_wander(10);
    // Let's not make hb-status permanent; negative values are amount of hbs
    // to let it have hb after player leaves. -+ Doomdark +-
    set_keep_hb(random(2) * -300);


    set_random_pick (30);
    set_alignment(-random(300));

    tmp = ({ "knife", "steel_bar", "ord_sword" });
    if (!random(3)) {
	ob=clone_object(AREA_TRISTEZA "duel/obj/"+tmp[random(sizeof(tmp))]);
	move_object(ob, this_object());
	command("wield");
    }
    set_ac(random(12)+4);
    set_wc(random(10)+i);
}

string
rnd_msg(int choice) {

    string str; 
    string *tmp;

    if(!choice) {

	tmp = ({
	  "yells: Kill!!!\n",
	  "shouts: Chop the head off!!!\n",
	  "giggles: Come to me baby!\n",
	  "says: I am sorry but I have to kill you.\n",
	  "screams: Alarm!\n",
	  "shouts: We have a stranger here!\n",
	  "groans: One for no one, everybody for themselves!!!\n",
	});
    }
    else if(choice == FBACK) {

	tmp = ({
	  "says: That bastard!\n",
	  "shouts: Everyone, come and help.\n",
	  "exclaims: We have a fight here!\n",
	  "says: Let me show how to kill this shit head!\n",
	  "sighs happily: At last we have something to do!\n",
	  "explains: Since I am the best...er, WAIT FOR ME!!!\n",
	  "sings: We - are - going to - slaughter youuuuuu.\n",
	});
    }

    return query_name()+" "+tmp[random(sizeof(tmp))];
}

status executing;
string mv;

void
catch_tell(string str) {

    string tmp;
    string dir;
    object ob; 

    if(!str || executing) return;
    if(!this_player()) return;
    if(this_player() == this_object()) return;

    if(sscanf(str, "%s leaves %s." ,tmp, dir)==2) {
	if(this_player() != query_attack())        
	    if(query_attack() || random(3)) dir=0;
	if(dir && !mv && random(4)) mv = dir;
    }
    else if(sscanf(str,"%s walks %s.", tmp, dir)==2) 
    {
	if(query_attack()) return;
	executing = 1;
	if(random(100) < 80 && !mv) 
	    command(dir, this_object()); // Let's follow the leader orc.
	executing = 0;
    }

    if(sscanf(str, "%s groans: %s attacked me!", dir, tmp)==2)
    {
	if(!query_attack()) {
	    ob = present(lower_case(tmp));
	    if(!ob) 
		tell_room(environment(), query_name()+
		  " tries to find the mysterious attacker.\n");
	    else {
		tell_room(environment(), rnd_msg(FBACK));
		attacker_ob = ob;
	    }
	}
    }       
}


void
heart_beat() {

    object ob;
    int dx;

    if(mv) {
	executing = 1;

	command(mv, this_object());
	executing = 0;
	mv = 0;
    }
    /* Attack them both. */ 
    if(attacker_ob && alt_attacker_ob) {
	if(present(attacker_ob) && present(alt_attacker_ob)) {
	    ob=attacker_ob;
	    attacker_ob=alt_attacker_ob;
	    alt_attacker_ob=ob;
	}
    }

    if(dattack) { 
	tell_room(environment(), rnd_msg(ATTACK));
	dattack = 0;
    }

    if(!(ob=query_attack())) old_attack = 0;
    else if(!random(15) && present(ob)) {
	tell_object(ob, query_name()+" runs against you ");
	dx = (int)ob->query_stat(ST_DEX);
	dx = 2 + (dx - query_stat(ST_DEX))/2;
	if(dx<0) dx = 0;
	if(!random(dx)) {
	    tell_object(ob, "and KNOCKS YOU DOWN!!!\n");
	    tell_room(environment(), query_name()+
	      " knocks "+(string)ob->query_name()+ " down!!!\n", ({ob}));
	    ob->set_condition(C_UNCONSCIOUS, random(5)+3);
	}
	else tell_object(ob, "but you block the attempt.\n"); 
    }

    ::heart_beat();

}

varargs void
my_attack(object ob) {

    if(!query_attack()) dattack=1; 
    else return;

    if(ob) attacker_ob = ob;
    else attacker_ob = this_player();
}


void
init () {

    object ob;
    object ob2;
    string *dir;
    int i;

    ::init();


    if(!interactive(this_player())) return;
    /* Let's change attack randomly */

    if (query(NPC_AGGRESSIVE)) {
	if(!query_attack() && 
	  (string)this_player()->query_race() != "orc")
	    my_attack(this_player());
    }
    else { 
	ob = first_inventory(environment());
	while(ob) {
	    if((string)ob->query_race()!="orc")
		if(ob2 = (object)ob->query_attack())
		    if((string)ob2->query_race()=="orc") {
			my_attack(ob);
			break;
		    }
	    ob = next_inventory(ob);
	}
    } 

    if (attacker_ob && this_player()!=attacker_ob)  
	if((string)this_player()->query_race() != "orc")
	    if((int)this_player()->query_level() > 5 && !random(3))
		attacker_ob=this_player();

}


int
hit_player(int i, int j, int k, object obj) {

    object ob;

    if(old_attack != attacker_ob) { 
	if(this_player())
	    tell_room(environment(), query_name()+" groans: "+ 
	      (string)this_player()->query_name()+
	      " attacked me!\n");
	old_attack = attacker_ob;
    }

    return ::hit_player(i, j, k, obj);
}

