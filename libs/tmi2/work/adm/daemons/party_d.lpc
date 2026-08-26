// File: /adm/daemons/party_d.c
// written by Descartes of Borg 921110
// ported to TMI-2 by Zeus, about 932204
// It should be used with /cmds/std/_party.c

#define NAME(x) (string)x->query("name")
#define LEADER(x) (string)x->query("leader")
#define CAPNAME(x) (string)x->query("cap_name")
#define POSS(x) possessive((string)x->query("gender"))
#define TIMEOUT 60
#define MAX 4

private mapping members, invited;

void create() {
     members = ([]);
     invited = ([]);
}

void form_party(object le) {
     if(pointerp(members[NAME(le)])) return;
     members += ([ NAME(le) : ({}) ]);
     invited += ([ NAME(le) : ({}) ]);
     le->set("leader", NAME(le));
     write("You form a new party.\n");
     say(CAPNAME(le)+" forms a new party.\n");
}

void invite_member(object le, object me) {
     if(!pointerp(invited[NAME(le)])) return;
     if(sizeof(members[NAME(le)]) == MAX) {
          write("You can't add anymore members.\n");
          return;
     }
     if(member_array(me, members[NAME(le)]) != -1) {
          write("You have already invited "+CAPNAME(me)+".\n");
          return;
     }
     invited[NAME(le)] += ({ me });
     write("You invited "+CAPNAME(me)+" to join your party.\n");
     tell_object(me, CAPNAME(le)+" invited you to join "+
          POSS(le)+" party.\n");
     say(CAPNAME(le)+" invited "+CAPNAME(me)+" to join "+
          POSS(le)+" party.\n", ({ me }) );
     call_out("remove_invitation", TIMEOUT, ({ le, me, 1 }) );
}

void remove_invitation(mixed arg) {
     if(!pointerp(invited[NAME(arg[0])]) ||
     member_array(arg[1], invited[NAME(arg[0])]) == -1) return;
     if(arg[2]) {
          tell_object(arg[1], "Your invitation to join "+
               CAPNAME(arg[0])+"'s party has expired.\n");
          tell_object(arg[0], CAPNAME(arg[1])+
               "'s invitation to join your party has expired.\n");
     }
     invited[NAME(arg[0])] -= ({ arg[1] });
}

void add_member(object le, object me) {
     if(!pointerp(members[NAME(le)])) return;
     if(sizeof(members[NAME(le)]) == MAX) {
          write(CAPNAME(le)+" can't add you to "+POSS(le)+" party.\n");
          return;
     }
     if(member_array(me, members[NAME(le)]) != -1) {
          write("You are already a member of "+CAPNAME(le)+"'s party.\n");
          return;
     }
     if(member_array(me, invited[NAME(le)]) == -1) {
          write("You have not been invited by "+CAPNAME(le)+".\n");
          return;
     }
     remove_invitation( ({ le, me, 0 }) );
     members[NAME(le)] += ({ me });
     me->set("leader", NAME(le));
     write("You join "+CAPNAME(le)+"'s party.\n");
     tell_object(le, CAPNAME(me)+" joins your party.\n");
     say(CAPNAME(me)+" joins "+CAPNAME(le)+"'s party.\n", ({ le }) );
}

void disband_party(object le) {
     int i, sz;

     if(!pointerp(members[NAME(le)])) return;
     sz = sizeof(members[NAME(le)]);
     for(i = 0; i < sz; i++) {
          if(!members[NAME(le)][i]) continue;
          members[NAME(le)][i]->set("leader", 0);
          tell_object(members[NAME(le)][i], "Your party has been disbanded.\n");
     }
     members[NAME(le)] = 0;
     invited[NAME(le)] = 0;
     map_delete(members, NAME(le));
     map_delete(invited, NAME(le));
     le->set("leader", 0);
     tell_object(le, "Your party has been disbanded.\n");
}

void disband_member(object le, object me, int flag) {
     if(!pointerp(members[NAME(le)]) ||
     member_array(me, members[NAME(le)]) == -1) return;
     members[NAME(le)] -= ({ me });
     me->set("leader", 0);
     if(flag) {
          tell_object(me, CAPNAME(le)+" removed you from "+POSS(le)+" party.\n");
          tell_object(le, "You removed "+CAPNAME(me)+" from your party.\n");
     } else {
          tell_object(me, "You leave "+CAPNAME(le)+"'s party.\n");
          tell_object(le, CAPNAME(me)+" left your party.\n");
     }
}

void check_party(object le) {
     object ob;

     if(!(LEADER(le))) return;
     if((LEADER(le)) == (NAME(le))) {
          disband_party(le);
          return;
     }
     ob = find_living(LEADER(le));
     if(!ob) return;
     disband_member(ob, le, 0);
}

object *query_members(object le) {
     return members[NAME(le)];
}
void change_leader(object le, object me) {
     int i, sz;

     if(!pointerp(members[NAME(le)]) ||
     member_array(me, members[NAME(le)]) == -1) return;
     members[NAME(le)] -= ({ me });
     members[NAME(le)] += ({ le });
     sz = sizeof(members[NAME(le)]);
     for(i = 0; i < sz; i++) {
          if(!members[NAME(le)][i]) continue;
          members[NAME(le)][i]->set("leader", NAME(me));
          tell_object(members[NAME(le)][i], CAPNAME(me)+
               " becomes the new leader of your party.\n");
     }
     members += ([ NAME(me) : members[NAME(le)] ]);
     invited += ([ NAME(me) : invited[NAME(le)] ]);
     members[NAME(le)] = 0;
     invited[NAME(le)] = 0;
     map_delete(members, NAME(le));
     map_delete(invited, NAME(le));
     me->set("leader", NAME(me));
     tell_object(me, "You become the new leader of your party.\n");
}

void party_list(object le) {
     int i, sz;

     if(!pointerp(members[NAME(le)])) return;
     sz = sizeof(members[NAME(le)]);
     write("Your party has "+(sz+1)+" "+((sz+1) > 1 ? "members" : "member")+
          ".\n");
     write("  "+CAPNAME(le)+" [Party Leader]\n");
     for(i = 0; i < sz; i++) {
          if(!members[NAME(le)][i]) continue;
          write("  "+CAPNAME(members[NAME(le)][i])+"\n");
     }
}
