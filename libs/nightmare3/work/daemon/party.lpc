//	/std/party.c
//	party daemon for the Nightmare mudlib
//	created by Descartes of Borg 10 Nov 1992

#include <party.h>

mapping party;
mapping invited;

string party_member(object ob);
void manage_party(string group);
void remove_party(string group);
void remove_invitation(mixed *bing);
int invited_now(object ob, string str);

void create() {
    party = ([]);
    invited = ([]);
    call_out("manage_all_parties", 300);
}

int add_member(object ob, string group) {
    if(!party) party = ([]);
    if(party_member(ob)) return ALREADY_MEMBER;
    if(!party[group]) {
        tell_object(ob, "You are the leader of party "+group+".\n");
        party[group] = ({});
    }
    party[group] += ({ ob });
    if(invited) if(invited[group]) if(member_array(ob, invited[group]) != -1) {
	remove_invitation( ({ ob, group, 1 }) );
    }
    ob->set_party(group);
    manage_party(group);
    return OK;
}

int remove_member(object ob) {
    string group;

    if(!party) return NOT_MEMBER;
    group = party_member(ob);
    if(!group) return NOT_MEMBER;
    party[group] -= ({ ob });
    tell_object(ob, "You are no longer in the party "+group+".\n");
    ob->set_party(0);
    manage_party(group);
    return OK;
}

string party_member(object ob) {
    string *groups;
    int i;

    if(!party) return 0;
    groups = keys(party);
    for(i=0; i<sizeof(groups); i++) {
        if(member_array(ob, party[groups[i]]) != -1) return groups[i];
    }
    return 0;
}

int change_leader(object ob) {
    string group;
    object *this_party;
    int x;

    if(!party) return NOT_MEMBER;
    group = party_member(ob);
    if(!group) return NOT_MEMBER;
    manage_party(group);
    this_party = party[group];
    x = member_array(ob, this_party);
    if(!x) return ALREADY_LEADER;
    this_party[x] = this_party[0];
    this_party[0] = ob;
    tell_object(ob, "You are now the leader of party "+group+".\n");
    party[group] = this_party;
    manage_party(group);
    return OK;
}

void manage_party(string group) {
    object *tmp;
    object *who;
    object ob;
    int i, j;

    tmp = ({});
    if(!party) return;
    if(!party[group]) return;
    if(!sizeof(party[group])) {
        remove_party(group);
        return;
    }
    ob = party[group][0];
    who = party[group];
    for(i=0; i<sizeof(who); i++) {
        if(!who[i]) continue;
        if(!living(who[i]) || !interactive(who[i])) {
            who[i]->set_party(0);
            continue;
        }
        tmp += ({ who[i] });
    }
    if(!sizeof(tmp)) {
        remove_party(group);
        return;
    }
    if(tmp[0] != ob) tell_object(tmp[0], "You are now the leader of the party "+group+".\n");
    party[group] = tmp;
    return;
    tmp = ({});
    for(i=0; i<sizeof(party[group]); i++) {
        if((who = party[group][i]->query_attackers())) {
            for(j=0; j<sizeof(who); j++) {
                if(member_array(who[j], tmp) == -1) tmp += ({ who[j] });
            }
        }
    }
    for(i=0; i < sizeof(party[group]); i++) party[group][i]->set_attackers(tmp);
}

void remove_party(string group) {
    if(!party) return;
    if(undefinedp(party[group])) return;
    map_delete(party, group);
}

void calculate_exp(string group, int exp, object tmp) {
    int tot, x, i;

    if(!party) {
        previous_object()->fix_exp(exp, tmp);
        return;
    }
    if(!party[group]) {
        previous_object()->fix_exp(exp, tmp);
        return;
    }
    if(sizeof(party[group]) == 1) {
	previous_object()->fix_exp(exp, tmp);
	return 0;
    }
    manage_party(group);
    for(i=0, tot=0; i<sizeof(party[group]); i++) {
	x = (int)party[group][i]->query_level();
        tot += x;
    }
    for(i=0; i<sizeof(party[group]); i++) {
        x = (int)party[group][i]->query_level();
        party[group][i]->fix_exp((x*exp)/tot+1, tmp);
    }
}

string *query_parties() {
    if(!party) return 0;
    return keys(party);
}

object *query_party_members(string group) {
    if(!party) return 0;
    if(!party[group]) return 0;
    manage_party(group);
    return party[group];
}

object query_leader(string str) {
    if(!party) return 0;
    if(!party[str]) return 0;
    manage_party(str);
    return party[str][0];
}

void notify_party(string str, string what) {
    int i, sz;

    if(!party) return;
    if(!party[str]) return;
    manage_party(str);
    sz = sizeof(party[str]);
    for(i=0; i<sz; i++) {
           tell_object(party[str][i], "<"+str+" info> "+what+"\n");
    }
}

void add_invited(object ob, string str) {
    if(!invited) return;
    if(!invited[str]) invited[str] = ({});
    invited[str] += ({ ob });
    call_out("remove_invitation", 60, ({ ob, str, 0 }));
}

object *query_invited(string str) {
    if(!invited) return 0;
    if(!invited[str]) return 0;
    return invited[str];
}

int invited_now(object ob, string str) {
    if(!invited) return 0;
    if(!invited[str]) return 0;
    if(member_array(ob, invited[str]) == -1) return 0;
    return 1;
}

void remove_invitation(mixed *bing) {
    if(!invited) return;
    if(!invited[bing[1]]) return;
    if(member_array(bing[0], invited[bing[1]]) == -1) return;
    invited[bing[1]] -= ({ bing[0] });
    if(!bing[2]) tell_object(bing[0], "You are no longer invited to be a member of the party.\n");
}

void manage_all_parties() {
    string *grps;
    int i;

    if(i = sizeof(grps = keys(party)))
      while(i--) manage_party(grps[i]);
    call_out("manage_all_parties", 300);
}
