// FILE:    /adm/obj/summon_ob.c
// PURPOSE: The object that allows and regulates commands given
//      to monsters which have been summoned or charmed. Note
//      that this item is quite powerful.
// CREDITS:
//   09 Nov 98   Cyanide created the file.
//   07 Feb 00   Cyanide implemented follower filters
//   12 Mar 00   Cyanide added support for referring to 'follow @2'

#include <mudlib.h>
#include <uid.h>

#define LINE "=----------------------------------------------="
#define ALLOWED_COMMANDS ({ "get", "drop", "kill", "wield", \
    "wear", "equip", "follow", "protect", "stay", "flee", "run", \
    "be", "cast", "invoke", "psi" })

// Prototypes
object find_referance(string, int);

// Global variables
object *followers = ({});
object owner;

inherit OBJECT;

/**************************************************************/

void create() {
    seteuid(ROOT_UID);
    set("id", ({ "#SUMMON_OB#" }) );
    set("prevent_drop", 1);
    set("prevent_give", 1);
    set("prevent_sell", 1);
}

/**************************************************************/

int begin() {
    object env = environment(TO);

    if (!env) {
	remove();
	return 0;
    }

    owner = env;
    if (env->query("followers"))
	followers = (object *)env->query("followers");
    else
	followers = ({});

    return 1;
}

/**************************************************************/

void init() {
    add_action("command", "command");
    add_action("rename", "rename");
    add_action("dismiss", "dismiss");
}

/**************************************************************/

void add_follower(object ob) { 
    followers += ({ ob });

#ifdef DEBUG
    DEBUG("Adding "+file_name(ob)+"; size now "+
      sizeof(followers)+".\n");
#endif 
}

/**************************************************************/

int command(string cmd) {
    string name, tmp;
    object ob;
    int num;

#ifdef DEBUG
    DEBUG("Command received: "+cmd+"\n");
#endif

    if (!cmd) {    
	write("Command who to what?\n");
	return 1;
    }

    tmp = cmd;

    if (sscanf(tmp, "%s %d %s", name, num, cmd)!=3) {
	num = 1;
	sscanf(tmp, "%s %s", name, cmd);
    }

    ob = find_referance(name, num);

    if (!ob) {
	if (num > 1) name += " "+num;
	write("You have no follower called \""+name+"\".\n");
	return 1;
    }

    cmd = replace_string(cmd, "to ", "");

#ifdef DEBUG
    DEBUG("Commanding: "+cmd+"\n");
    DEBUG("Result: "+ob->force_me(cmd)+"\n");
#else
    ob->force_me(cmd);
#endif

    write("You command "+ob->query("cap_name")+" to \""+
      cmd+"\".\n");

    return 1;
}

/**************************************************************/

object find_referance(string name, int num) {
    int i, sz, count = 0;
    object ob;

    if (!num) num = 1;
    if (!owner) return 0;

    // For consistency
    begin();

    followers = filter_array(followers, "filter_followers", TO);
    sz = sizeof(followers);

#ifdef DEBUG
    DEBUG("Of "+sz+" followers, finding \""+name+"\", got ");
#endif

    for (i=0; i<sz; i++) {   
	if (followers[i]->id(name))
	{
	    count++;

	    if (count == num) {
		ob = followers[i];
		break;
	    }
	}
    }

#ifdef DEBUG
    if (ob) DEBUG(""+file_name(ob)+".\n");
    else DEBUG("nuthin'\n");
#endif

    return ob;
}

/**************************************************************/

int dismiss(string name) {
    string tmp;
    object ob;
    int num;

#ifdef DEBUG
    DEBUG("Command received: "+name+"\n");
#endif

    if (!name) {    
	write("Dismiss which follower?\n");
	return 1;
    }

    tmp = name;

    if (sscanf(name, "%s %d", name, num) != 2) {
	num = 1;
    }


    ob = find_referance(name, num);
    if (!ob) {
	write("Couldn't find follower \""+name+"\".\n");
	return 1;
    }

    write("You dismiss "+ob->query("cap_name")+".\n");
    say(TPN+" dismisses "+ob->query("cap_name")+".\n");

    ob->delete("summoner");
    return 1;
}


/**************************************************************/

int filter_followers( object ob ) {
    int flag = 1;
    if (!ob || userp(ob)) flag = 0;

    return flag;
}

/**[ End of File ]*********************************************/
