/*
** File: /adm/obj/death_ob.c
** Purpose: Individualized death stuff for each victim of an
**    "accident".
** Credits:
**    13 Jun 97   Cyanide@Nightfall's Keep wrote the first version.
**		  (Nightmask suggested the random death emotes).
**    11 Oct 97   Cyanide added the wizcall action, just in case.
**    06 Nov 97   Cyanide added a "kills" log addendum for purges.
**    20 Jun 99   Cyanide took steps to reduce the chance of
**                "multideathing". That sucks.
*/

#include <move.h>
#include <logs.h>
#include <mudlib.h>
#include <config.h>
#include <uid.h>
#include <daemons.h>

#define CAP_NAME ob->query("cap_name")
#define EMOTE_DIR "/adm/text/"
#define EMOTE_WILD ({ "die_*.t", "remove_*.t" })
// Cyanide borrowed this from the shutdown daemon. Kudos for original
// wild emote concept go to Blue@TMI-2

inherit OBJECT;

string *emotes;
int num_emote,  	//Total number of emotes...
delay;

// Prototypes...
string get_emote();
void do_death (object, int);
void delete_player (object);
int init_emotes(object);
int cmd_wizcall(string);

void create() {
    seteuid(ROOT_UID);
    set("id", ({ "__DEATH_OB__" }) );
}

void init() {
    add_action ("cmds_func", "");
    add_action("cmd_wizcall", "wizcall"); 
}

int cmds_func(string str) {
    if (!adminp(TP)) {
	tell_object(TP, "You cannot even do that!\n"+
	  "If you have a REAL problem, use the 'wizcall' command.\n");
	return 1;
    }

    return 0;
}

void remove() {
    object ob;

    ob = environment(this_object());
    if (ob) ob = environment(ob);
    if (ob && living(ob)) ob->delete("dying");
    ::remove();
}


int cmd_wizcall(string str) {

    object *usrs ;
    int i, flag ;
    string message ;

    if (!str) {
	write("Syntax: wizcall <message>\n");
	return 1;
    }

    message = (string)this_player()->query("cap_name")+" calls: "+str+"\n";
    write("You call: "+str+"\n");
    usrs = users() ;
    for (i=0;i<sizeof(usrs);i++) {
	if (!wizardp(usrs[i])) continue ;
	tell_object(usrs[i],message) ;
	flag = 1 ;
    }
    if (flag==0) {
	write ("There are no wizards logged on at the moment.\n") ;
    }
    return 1 ;
}

void begin_sequence (object ob) {
    int res;

    // This eliminated the hundreds of multiple deaths.
    res = ob->query("max_hp");
    if (res<1) ob->set("max_hp", 100);

    res = init_emotes(ob);
    call_out("scroll_sequence", 3, ob, res);
    return;
}

// This function chooses a random death sequence file and initializes the
// "emotes" array with the data found in it.

int init_emotes (object ob) {
    string *e_files;
    int i;   //temp
    int res;
    object *p;

    res = (PROPERTY_D->query_res_percentage(ob));

    if ( ((random(100) > res) &&
	(ob->query_level()>=5)) ||
      ob->query("branded_by_death") ) {
	res = 1; 	// Object (player) will be removed.  How sad.
	ob->set("branded_by_death", 1);
    } else {
	res = 0;  	// He/she/it will be reborn!  Praise be!
    }

    p = users();
    for (i=0; i<sizeof(users()); i++)
	if (adminp(p[i]) && p[i]->query("announce"))
	{
	    e_files = p[i]->query("announce");
	    if (e_files &&
	      ( e_files[0] == "ON" ||
		(member_array(ob->query("name"), e_files) != -1 )))
	    {
		if (!res)
		    tell_object(p[i], "Death tells you: "+
		      capitalize(subjective(ob->query("gender")))+
		      "'ll be back.\n");
		else
		    tell_object(p[i], "Death tells you: "+
		      "I'm keeping this one.\n");
	    }
	}

    e_files = get_dir(EMOTE_DIR+EMOTE_WILD[res]);
    //for (i=0;i<sizeof(e_files);i++)
    //  DEBUG(i+"  "+e_files[i]+"\n");

    if (!sizeof(e_files)) {
	emotes = ({ });
	num_emote = -1;
    } else {
	i = random(sizeof(e_files));
	emotes = explode(read_file(EMOTE_DIR +
	    e_files[i]), "###\n");
	//DEBUG("Random = "+i+"\n");
	/*
	      e_files[random(sizeof(e_files))]), "###\n");
	*/
	num_emote = sizeof(emotes)-1;
    }

    delay = (num_emote - 1);
    return res;
}

void scroll_sequence (object ob, int res) {
    string msg;

    if (!ob) return;

    // If there's a message, tell the poor dead guy.
    msg = get_emote();
    if (msg)
	tell_object(ob, msg);

    // If no more messages, do the death stuff  (Muhahahahahaha)
    if (delay < 1) {
	do_death(ob, res);
	return;
    }

    // Decrement "delay" by 1.
    delay--;
    call_out("scroll_sequence", 3, ob, res);
}   //end scroll_sequence()

string get_emote () {
    if (delay < num_emote)
	return emotes[(num_emote - delay)];

    return 0;  // Else, returns no message;
}

void do_death (object ob, int remove_ob) {

    if (remove_ob == 1) {
	delete_player (ob);
    } else {
	// reduce con + related bonus.  Sucks to be him, huh?
	//lets not do this to lvl 4 and lower and not to lvl 30
	/*
		if ( ob->query_level() >= 5 ) {
		    remove_ob = (int)PROPERTY_D->query_con_hp_bonus(ob);
		    ob->set("base_stat/constitution", 
		      (int)ob->query("base_stat/constitution") - 1);
		    ob->set("stat", ob->query("base_stat"));

		    remove_ob = remove_ob - (int)PROPERTY_D->query_con_hp_bonus(ob);
		    //write("lost "+remove_ob+" hit points.\n");
		    ob->add("max_hp", (-1 * remove_ob * (ob->query_level()-1) ) );
		    if (remove_ob > 0) remove_ob = (remove_ob * -1);
		}
	*/
	if (ob->query_level() > 29){
	    ob->set("experience", ((ob->query("experience")) - 100000));
	}
	ob->set("hit_points", 1);
	ob->delete("pk");
	ob->delete("dying");
	if (ob->move(PRAY_ROOM)!=MOVE_OK)
	    ob->move(START);
    }

    remove();
}

// This function deletes the poor player...
void delete_player (object ob) {
    string name, *ann;
    object *p;
    int i;

    name = (string)ob->query("name");

    p = users();
    for (i=0; i<sizeof(users()); i++)
	if (adminp(p[i])) {
	    ann = p[i]->query("announce");
	    if (ann &&
	      ( ann[0] == "ON" ||
		(member_array(name, ann) != -1 )) )
		tell_object(p[i], "[ "+capitalize(name)+" has "+
		  "been removed from play. ]\n");
	}

    GANG_D->remove_member( ob->query("gang") );
    ob->delete("gang");

    log_file(DIE_PURGE, iwrap(CAP_NAME + " was killed and PURGED ["+
	extract(ctime(time()), 4, 15) + "]\n"));  

    log_file(KILLS, iwrap(CAP_NAME + " was killed and PURGED ["+
	extract(ctime(time()), 4, 15) + "]\n"));

    if (ARCHIVE_DIR) {
	rename(user_data_file(ob) + __SAVE_EXTENSION__, ARCHIVE_DIR + 
	  "user/" + name + __SAVE_EXTENSION__);
	rename(PDATA_DIR + name[0..0] + "/" + name + __SAVE_EXTENSION__,
	  ARCHIVE_DIR + "connection/" + name + __SAVE_EXTENSION__);
    } else {
	rm( user_data_file(ob) + __SAVE_EXTENSION__);
	rm( PDATA_DIR + name[0..0] + "/" + name + __SAVE_EXTENSION__ );
    }

    destruct(ob->query_link());
    destruct (ob);
}

