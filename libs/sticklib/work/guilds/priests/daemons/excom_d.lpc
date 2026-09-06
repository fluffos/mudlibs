#include "../priest.h"
#include <macros.h>

#define RESTORE restore_object(PRIEST_SAVE_DIR "EXCOM")
#define SAVE_OBJ save_object(PRIEST_SAVE_DIR  "EXCOM")

string *names;
string *banned;


void
create() {
    RESTORE;
    if(!banned) banned=({});
    if(!names) names=({});
}


string
excoms() {
    int i;
    string *strs;

    if(sizeof(names)>0) {
	i = sizeof(names);
	strs = allocate(i);
	while(--i>=0) strs[i] = capitalize(names[i]);

	return "Those Excommunicated:" +
	sprintf("\n%-78#s",implode(strs,"\n"));
    }
    return "No one is excommunicated.";
}


status
excomed(string myname) {
    return member(names, myname)>=0;
}


void
excom_me(object me) {
    me->tell_me("You have been excommunicated!");
    if(me->query_guild() == GN_PRIEST)
	SERVER->resign(me);
    me->set_title("the Accursed of Boccob");
}


status
excom(string myname) {
    object who;

    myname = lower_case(myname); 

    if(!excomed(myname)) {
	names += ({ myname });
	if((who=find_player(myname)))
	    excom_me(who);
	INFORMER->inform(capitalize(myname)+" has \
been excommunicated; have no further traffic with this heathen.");
    } else {
	names-=({ myname });
	INFORMER->inform(capitalize(myname)+" is \
no longer excommunicated; may the mercy of " GOD_NAME " uphold us all.");
    }

    names = sort_array(names, #'>);
    SAVE_OBJ;
    return excomed(myname);
}


status
am_i_excom(string myname) {
    object who;

    if(!excomed(myname)) return 0;
    who = find_player(myname);
    if(who) call_out("excom_me",5,who);
    return 1;
}


status
am_i_banned(string myname) {
    return member(banned,myname)>=0; 
}


status
ban_me(string myname, int frock_him) {
    object go;
    status flag;

    if(member(banned, myname)>=0) {
	if(!frock_him) return 0;
	TP->tell_me("You pray quickly to " GOD_NAME " asking him "
	  "to lift the prohabition against "+capitalize(myname)+".");
	INFORMER->inform(capitalize(myname)+" has been frocked.");
	if(find_player(myname)) {
	    go=(object)find_player(myname)->query_guild_object();
	    go->set_banned(0);
	}

	banned-=({ myname });
    }
    else{
	if(frock_him) return 0;
	banned+=({ myname });
	INFORMER->inform(capitalize(myname)+" has been unfrocked. \
By Tradition of the Order, this prohabition against using prayers and \
spells is in effect until lifted by the Vicegerant.");
	go = (object)find_player(myname)->query_guild_object();
	go->set_banned(1);
    }

    banned = sort_array(banned, #'>);
    SAVE_OBJ;
    return 1;
}

debug() {
    printf("Excomed: %O\nBanned: %O\n", names, banned);
}
