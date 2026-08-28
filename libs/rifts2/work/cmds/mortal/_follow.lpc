//	/bin/user/_follow.c
//	from the Nightmare mudlib
//	allows players to follow one another
//	created by Descartes of Borg 15 february 1993

#include <std.h>
#include <party.h>

inherit DAEMON;

int cmd_follow(string str) {
    object ob, ob2, *inv;
    string who, party;
    int i;

    if(!str) {
	notify_fail("Correct syntax: <follow allow [who]> or <follow [who]> or \n<follow stop>\n");
	return 0;
    }
    if(str == "stop") {
      if(!this_player()->query_following()) {
        write("You are not following anyone.");
        return 1;
      }
      ob = (object)this_player()->query_following();
      if(!ob->query_followers()) {
        write((string)ob->query_cap_name()+ " has lost you.");
        this_player()->set_following(0);
        return 1;
      }
      while(member_array(this_player(), (object *)ob->query_followers()) >= 0)
        ob->remove_follower(this_player());
      message("info", (string)this_player()->query_cap_name()+
	      " has stopped following you.", ob);
      this_player()->set_following(0);
      write("You stop following "+(string)ob->query_cap_name());
      return 1;
    }
    if(sscanf(str, "allow %s", who) == 1) {
      if(who == "party") {
        party = (string)this_player()->query_party();
        if(!party) {
          write("You are not in a party.");
          return 1;
        }
        inv = (object *)PARTY_OB->query_party_members(party);
        if(!inv || !sizeof(inv)) {
          write("You are not in a party.");
          return 1;
        }
        for(i=0;i<sizeof(inv);i++) {
          if(!inv[i]) continue;
          write("You invite "+(string)inv[i]->query_cap_name() + " to follow you.");
          this_player()->follow_allow((string)inv[i]->query_name());
          message("info", (string)this_player()->query_cap_name() +
                " has invited you to follow "+objective(this_player()) + ".",
                inv[i]);
        }
        return 1;
      }
	if(!find_player(who)) {
	    notify_fail("No "+capitalize(who)+" in our reality.\n");
	    return 0;
   	}
	write("You invite "+capitalize(who)+" to follow you.\n");
	this_player()->follow_allow(lower_case(who));
	tell_object(find_player(who), "You have been invited to follow "+
	    this_player()->query_cap_name()+".\n");
	return 1;
    }
    ob = present(lower_case(str), environment(this_player()));
    if(!ob) {
	notify_fail("No one by that name around here.\n");
	return 0;
    }
    if(ob == this_player()) {
	notify_fail("You cannot follow yourself!\n");
	return 0;
    }
    if(!ob->can_follow((string)this_player()->query_name())) {
	notify_fail("You cannot follow "+capitalize(str)+"!\n");
	return 0;
    }
    if(ob2 = this_player()->query_following()) {
      while(member_array(this_player(), (object *)ob2->query_followers()) >= 0)
        ob2->remove_follower(this_player());
      this_player()->set_following(0);
      if(ob2 != ob) {
        write("You are no longer following "+(string)ob2->query_cap_name()+".");
        message("info", (string)this_player()->query_cap_name() + " stops following you.", ob2);
      }
    }
    if(!ob->add_follower(this_player())) {
	notify_fail("You cannot follow someone who is following you!\n");
	return 0;
    }
    write("You are now following "+capitalize(str)+".\n");
    tell_object(ob, this_player()->query_cap_name()+" is now following you.\n");
    return 1;
}

void help() {
    write("Syntax: <follow [name]>\n\
        <follow allow [name]>\n\
<follow allow> allows the player named to follow you.\n\
<follow allow party> allows all players in your party to follow you.\n\
<follow> allows you to follow a player who has allowed you.\n\
You may stop following by typing 'follow stop'.\n\
See also: party, kill\n"
);
}



