// File: /std/user/team.c
// written by Zeus for TMI-2 or compatible mudlibs
// originally used arrays to hold member objects
// modified to use mapping to hold member objects
// hopefully this should increase efficiency of move_team
// as it doesn't have to query for cap_names when calling
// move_player. Added player's invitation, an idea from
// Nightmare's party daemon.

#define TIMEOUT 60
#define NAME (string)this_object()->query("name")
#define CAPNAME (string)this_object()->query("cap_name")
#define LEADER (string)this_object()->query("leader")
#define MAX 3

private nosave mapping members;
private nosave object *invited;
private nosave object startenv;

void disband_team();
void disband_member(object ob, int flag);

void init_team() {
     members = ([]);
     invited = ({});
     this_object()->set("leader", NAME);
}

// This function should be called from quit(), die(), net_dead()
// in user.c to clean up team status when a player quits, dies
// or goes netdead

void check_team() {
     object ob;

write ("I'm a frog!\n") ;
     if((LEADER) && ((NAME) == (LEADER))) {
write ("Damn, I'm a BLUE frog!\n") ;
          disband_team();
          return;
     }
     if((LEADER) && ((NAME) != (LEADER))) {
          ob = find_living(LEADER);
          if(!ob) return;
          ob->disband_member(this_object(), 0);
          return;
     }
}

void invite_player(object ob) {
     if(!ob || ob->query("leader") || sizeof(members) > MAX ||
     members[(string)ob->query("cap_name")]) {
          write("You can't invite "+ob->query("cap_name")+" to join your party.\n");
          return;
     }
     if(member_array(ob, invited) != -1) {
          write("You have already invited "+ob->query("cap_name")+".\n");
          return;
     }
     invited += ({ ob });
     write("You invited "+ob->query("cap_name")+" to join your party.\n");
     tell_object(ob, CAPNAME+" invited you to join "+
     possessive((string)this_object()->query("gender"))+" party.\n");
     call_out("remove_invitation", TIMEOUT, ({ ob, 1 }) );
     return;
}

void remove_invitation(mixed arg) {
     if(!arg[0] || !pointerp(invited) || sizeof(invited) == 0 ||
     member_array(arg[0], invited) == -1) return;
     if(!living(arg[0]) || arg[0]->query("ghost")) {
          invited -= ({ arg[0] });
          return;
     }
     if(arg[1]) tell_object(arg[0], "Your invitation to join "+CAPNAME+
                "'s party has expired.\n");
     invited -= ({ arg[0] });
}

void add_member(object ob) {
     if(member_array(ob, invited) == -1) {
          tell_object(ob, "You are have not been invited by "+CAPNAME+".\n");
          return;
     }
     if(sizeof(members) > MAX || members[(string)ob->query("cap_name")]) {
          tell_object(ob, CAPNAME+" can't add you to "+
          possessive((string)this_object()->query("gender"))+" party.\n");
          return;
     }
     remove_invitation( ({ ob, 0 }) );
     ob->set("leader", NAME);
     members += ([ (string)ob->query("cap_name") : ob ]);
     tell_object(ob, "You join "+CAPNAME+"'s party.\n");
     tell_object(this_object(), ob->query("cap_name")+" joins your party.\n");
     say(ob->query("cap_name")+" joins "+CAPNAME+"'s party.\n",
     ({ ob, this_object() }) );
     return;
}

// This function is called from /cmds/std/_go.c by the leader object
// to move party members.

void move_team(object env) {
     if(!mapp(members) || sizeof(members) == 0) return;
     if(!startenv) startenv = env;
     call_out("handle_move", 0, environment(this_object()) );
     return;
}

void handle_move(object env) {
     string *names;
     int i, flag;

     if(!mapp(members) || sizeof(members) == 0 || !startenv) return;
     if(environment(this_object()) != env) return;
     names = keys(members);
     for(i = 0; i < sizeof(names); i++) {
          if(!members[names[i]]) continue;
          if(environment(members[names[i]]) != startenv) {
               tell_object(members[names[i]], "Your party moved without you.\n");
               continue;
          }
          members[names[i]]->move_player(environment(this_object()),
               names[i]+" follows "+CAPNAME);
          flag = 1;
     }
     if(flag) write("Your party followed you.\n");
     startenv = 0;
}

void disband_team() {
     string *names;
     int i;

write ("Damn, I'm an UGLY blue frog!\n") ;

     if(!mapp(members)) return;

write ("None uglier!\n") ;
     names = keys(members);
     for(i = 0; i < sizeof(names); i++) {
          if(!members[names[i]]) continue;
          members[names[i]]->set("leader", 0);
          tell_object(members[names[i]], CAPNAME+" disbanded the party.\n");
     }
     members = 0;
     invited = 0;
     this_object()->set("leader", 0);
     tell_object(this_object(), "Your party is now disbanded.\n");
}

void disband_member(object ob, int flag) {
     if(!mapp(members) || sizeof(members) == 0 ||
     !members[(string)ob->query("cap_name")]) return;
     if(flag) tell_object(members[(string)ob->query("cap_name")], CAPNAME+
              " removed you from "+possessive((string)this_object()->query("gender"))+
              " party.\n");
     else tell_object(members[(string)ob->query("cap_name")],
          "You leave "+CAPNAME+"'s party.\n");
     ob->set("leader", 0);
     map_delete(members, (string)ob->query("cap_name"));
     if(flag) tell_object(this_object(), "You remove "+(string)ob->query("cap_name")+
              " from your party.\n");
     else tell_object(this_object(), (string)ob->query("cap_name")+
          " has left your party.\n");
     return;
}

object *query_members() {
     return values(members);
}
