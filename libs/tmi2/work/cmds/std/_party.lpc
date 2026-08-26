// File: /cmds/std/_party.c
// written by Zeus @1993
// to be used in conjunction with
// my party daemon

#include <mudlib.h>
#include <daemons.h>

#define NAME(x) (string)x->query("name")
#define CAPNAME(x) (string)x->query("cap_name")
#define LEADER(x) (string)x->query("leader")
#define POSS(x) possessive((string)x->query("gender"))

inherit DAEMON;

string help();

int handle_form() {
     if((LEADER(this_player()))) {
          notify_fail("You are already in a party.\n");
          return 0;
     }
     PARTY_D->form_party(this_player());
     return 1;
}

int handle_invite(string str) {
     object ob;

     if(!(LEADER(this_player()))) {
          notify_fail("You are not in a party.\n");
          return 0;
     }
     if((LEADER(this_player())) != (NAME(this_player()))) {
          notify_fail("You are not permitted to do that.\n");
          return 0;
     }
     ob = present(lower_case(str), environment(this_player()));
     if(!ob) {
          notify_fail("There is no one by that name here.\n");
          return 0;
   }
    if(ob==this_player()) {
       notify_fail("Don't be narcistic please, find someone else to party with.\n");
      return 0;
     }
     PARTY_D->invite_member(this_player(), ob);
     return 1;
}

int handle_join(string str) {
     object ob;

     if((LEADER(this_player()))) {
          notify_fail("You are already in a party.\n");
          return 0;
     }
     ob = present(lower_case(str), environment(this_player()));
     if(!ob) {
          notify_fail("There is no one by that name here.\n");
          return 0;
     }
     if(!(LEADER(ob))) {
          notify_fail(CAPNAME(ob)+" is not in a party.\n");
          return 0;
     }
     if((LEADER(ob)) != (NAME(ob))) {
          notify_fail(CAPNAME(ob)+" is not leader of "+
               POSS(ob)+" party.\n");
          return 0;
     }
     PARTY_D->add_member(ob, this_player());
     return 1;
}

int handle_leave() {
     object ob;

     if(!(LEADER(this_player()))) {
          notify_fail("You are not in a party.\n");
          return 0;
     }
     if((LEADER(this_player())) == (NAME(this_player()))) {
          notify_fail("You are not permitted to do that.\n");
          return 0;
     }
     ob = find_living(lower_case(LEADER(this_player())));
     if(!ob) {     
          notify_fail("Your leader is gone...PLEASE NOTIFY A WIZ.\n");
          return 0;
     }
     PARTY_D->disband_member(ob, this_player(), 0);
     return 1;
}

int handle_remove(string str) {
     object ob;

     if(!(LEADER(this_player()))) {
          notify_fail("You are not in a party.\n");
          return 0;
     }
     if((LEADER(this_player())) != (NAME(this_player()))) {
          notify_fail("You are not permitted to do that.\n");
          return 0;
     }
     ob = find_living(lower_case(str));
     if(!ob) {
          notify_fail("That person is not logged on.\n");
          return 0;
     }
     if((LEADER(this_player())) != (LEADER(ob))) {
          notify_fail(CAPNAME(ob)+" is not a member of your party.\n");
          return 0;
     }
     PARTY_D->disband_member(this_player(), ob, 1);
     return 1;
}

int handle_disband() {
     if(!(LEADER(this_player()))) {
          notify_fail("You are not in a party.\n");
          return 0;
     }
     if((LEADER(this_player())) != (NAME(this_player()))) {
          notify_fail("You are not permitted to do that.\n");
          return 0;
     }
     PARTY_D->disband_party(this_player());
     return 1;
}

int handle_members() {
     object ob;

     if(!(LEADER(this_player()))) {
          notify_fail("You are not in a party.\n");
          return 0;
     }
     if((LEADER(this_player())) == (NAME(this_player()))) ob = this_player();
     else ob = find_living(lower_case(LEADER(this_player())));
     if(!ob) {     
          notify_fail("Your leader is gone...PLEASE NOTIFY A WIZ.\n");
          return 0;
     }
     PARTY_D->party_list(ob);
     return 1;
}

int handle_leader(string str) {
     object ob;

     if(!(LEADER(this_player()))) {
          notify_fail("You are not in a party.\n");
          return 0;
     }
     if((LEADER(this_player())) != (NAME(this_player()))) {
          notify_fail("You are not permitted to do that.\n");
          return 0;
     }
     ob = find_living(lower_case(str));
     if(!ob) {
          notify_fail("That person is not logged on.\n");
          return 0;
     }
     if((LEADER(this_player())) != (LEADER(ob))) {
          notify_fail(CAPNAME(ob)+" is not a member of your party.\n");
          return 0;
     }
     PARTY_D->change_leader(this_player(), ob);
     return 1;
}

int cmd_party(string str) {
     string foo, fii;

     if(!str) {
          if((LEADER(this_player())))
               write("You are a member of "+
                    capitalize(LEADER(this_player()))+"'s party.\n");
          else write("Usage: party <action> [<player>]\n");
          return 1;
     }
     if(sscanf(str, "%s %s", foo, fii) == 2) {
          switch(foo) {
               case "invite" : return handle_invite(fii); break;
               case "join" : return handle_join(fii); break;
               case "remove" : return handle_remove(fii); break;
               case "leader" : return handle_leader(fii); break;
               default : return notify_fail(help());
          }
     } else if(sscanf(str, "%s", foo) == 1) {
          switch(foo) {
               case "form" : return handle_form(); break;
               case "leave" : return handle_leave(); break;
               case "disband" : return handle_disband(); break;
               case "members" : return handle_members(); break;
               default : return notify_fail(help());
          }
     }
     return notify_fail(help());
}

string help() {
     write("Syntax: party form             non-members ONLY.\n"+
           "       party join <player>    non-members ONLY.\n"+
           "       party leave            members ONLY\n"+
           "       party members          all members\n"+
           "       party invite <player>  leader ONLY\n"+
           "       party remove <player>  leader ONLY\n"+
           "       party leader <player>  leader ONLY\n"+
           "       praty disband          leader ONLY\n"+
     "\nThis command allows players to form and manage small\n"+
           "parties. To join an existing party, you must be invited\n"+
           "by its leader. Once invited, you have 60 seconds to join\n"+
           "before your invitation expires. If you quit, die or go\n"+
           "netdead whilst in a party, your membership to that party\n"+
           "is automatically removed. If you are the leader of that\n"+
           "party, then the party will be disbanded.\n");
}
