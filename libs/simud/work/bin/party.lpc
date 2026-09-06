/*This is the party command.*/
/*It uses the party daemon, which keeps track of them all.*/
/*As it's written by Snarky, expect debug.... loads of debug*/

#ifndef PARTY_DAEMON
	#define PARTY_DAEMON ("/daemon/party")
#endif

string percent_color(int per) {
  if (per > 100)        // hicyan
    return "~[140";
  else if (per == 100)        // white
    return "~[150";
  else if (per > 90)        // higreen
    return "~[100";
  else if (per > 75)        // green
    return "~[020";
  else if (per > 50)        // yellow
    return "~[110";
  else if (per > 25)        // red
    return "~[010";
  else if (per > 0)        // hired
    return "~[090";
  else
    return "~[080";        // gray
}

string hp_string(object target) {
  int hp, maxhp, mana, maxmana, end, maxend, per;
  string buf = "~[060HP: ";

  hp = target->query_hp();
  maxhp = target->query_max_hp();
  mana = target->query_mana();
  maxmana = target->query_max_mana();
  end = target->query_endurance();
  maxend = target->query_max_endurance();

  if (hp != 0)
    per = 100*hp/maxhp;
  else
    per = 0;
  buf += percent_color(per);
  buf += (string)hp+"~[060/"+(string)maxhp+" ("+(string)per+"%)~CDEF ";

  if (maxmana > 0) {
    buf += "~[060Mana: ";
    if (mana != 0)
      per = 100*mana/maxmana;
    else
      per = 0;
    buf += percent_color(per);
    buf += (string)mana+"~[060/"+(string)maxmana+"~CDEF ";
  }

  if (maxend > 0) {
    buf += "~[060End: ";
    if (end != 0)
      per = 100*end/maxend;
    else
      per = 0;
    buf += percent_color(per);
    buf += (string)end+"~[060/"+(string)maxend+"~CDEF";
  }

  if (target->query_in_combat()) {
    object enemy = target->query_target();
    if( enemy->query_hp() > 0)
       per = 100 * enemy->query_hp() / enemy->query_max_hp();
    else
       per = 0;
    buf += " ~[060Enemy: ";
    buf += percent_color(per);
    buf += "/daemon/desc_vars"->hp(enemy);
    buf += "~CDEF";
  }

  return buf;
}

int main(string param) {
    string command = "";
    string target = "";
	string temp;
	string myName = this_player()->query_name();
	// DO THIS UP HERE, ARGH
	//Note to future wizzes of America, do NOT offend Al's style
	// FEH, it's not a matter of style, it's a matter of FUNCTIONAL CODE
	string party = this_player()->query_env_var("party");
	if(!param) {
      msg("You might try ~CREFhelp party~CDEF for help");
      return 1;
    }
	if(sscanf(param, "%s %s", command, target) != 2) {
        command = param;
    }
	switch(command) {

/*--------------------------*/
/*Commands without arguments*/
/*--------------------------*/

		case "members" : /*This command lists the party members*/
			if( party ) {
	            string *members = sort_array(PARTY_DAEMON->query_party_members(party), #'>);
				string toShow = "";
				int mentors = 0;
        	    toShow += "~CTITMembers of party ~CWRN"+capitalize(party)+"~CTIT:\n";
				// generate list of members
    	        foreach(temp : members ) {
   	    	        object tempPlayer = find_player(temp);
    	            if(temp == PARTY_DAEMON->query_party_leader(party)) {
   	    	            toShow += "  ~CBRT* ";
       	    	    }
           	    	else if(temp == myName) {
                	    toShow += "    ~CREF";
   	 	           } else {
       		            toShow += "    ~CWRN";
           		   }
	            	   toShow += pad(capitalize(temp),16,0) + " ~[060" + hp_string(tempPlayer) + "\n";
				}
				// display mentoring information
				foreach( temp : members ) {
					object ob = PARTY_DAEMON->find_member(temp);
					string pupil;
					if( !ob )
						continue;
					if( pupil = ob->query_env_var("mentoring") ) {
						if( !mentors ) {
							toShow += "~CTITMentors:\n";
							mentors = 1;
						}
						toShow += "    ~CDEF"+capitalize(temp)+" -> "+capitalize(pupil)+"\n";
					}
				}
				// display bonuses
				toShow += "~CTITBonuses earned:\n    ~CDEF"+
							PARTY_DAEMON->query_bonus(party);
				
	  	      	msg("\n"+toShow);
			} else {
				msg("You must be in a party to view the members.");
			}
			break;

		case "list" : /*This command lists all the parties*/
			string *parties = PARTY_DAEMON->query_party_names();
	        if(sizeof(parties) == 0) {
   		       msg("~CTITNo current parties.~CDEF");
       		} else {
           		msg("~CTITCurrent Parties:~CDEF");
               	foreach(temp : parties) {
                   	if(temp == party) {
                       	msg("~CREF" + capitalize(temp) + "~CDEF");
                    } else {
   	                    msg("~CWRN" + capitalize(temp) + "~CDEF");
       	            }
           	    }
           	}
			break;

		case "quit" : /*This command Quits a party*/
			if( party ) {
	            PARTY_DAEMON->msg_party(party, capitalize(myName) + " has quit the party!");
				PARTY_DAEMON->kick_member(party, myName, 1);
			} else {
				msg("You must be part of a party to quit it!");
			}
			break;

		case "disband" : /*This command Disbands the party if you're leader*/
			if( party ) {
				if(PARTY_DAEMON->query_party_leader(party) == myName) {
	               PARTY_DAEMON->msg_party(party, capitalize(myName) + " has disbanded the party!");
   		           PARTY_DAEMON->disband_party(party, 1);
        	    } else {
   	        	   msg("You must be party leader to disband the party.");
           		}
			} else {
				msg("You must be in a party, and leader to disband it.");
			}
			break;

		case "help":
			string myHelp = "~CTITParty Commands:~CDEF\n";
			myHelp += "~CCOMparty boot <message>\n";
			myHelp += "~CCOMparty create <name>\n";
			myHelp += "~CCOMparty disband \n";
			myHelp += "~CCOMparty list \n";
			myHelp += "~CCOMparty members \n";
			myHelp += "~CCOMparty mentor <name/stop>\n";
			myHelp += "~CCOMparty promote <message>\n";
			myHelp += "~CCOMparty quit \n";
			myHelp += "~CCOMparty recruit <name>\n";
			myHelp += "~CCOMparty tell <message>\n";
			myHelp += "~CDEFSee ~CREFhelp party~CDEF for more detail.";
			msg(myHelp);
			break;

		default :  /*Invalid command*/
			 msg("You might try ~CREFhelp party~CDEF for the commands.");	
			break;
/*------------------------------*/
/*Commands that need an argument*/
/*------------------------------*/

		case "create": /*This creates a party*/
			if( party ) {
				msg("Sorry, you must quit your present party to start a new one.");
			}
			else if(target == "") {
				msg("Please specify a name.");
			} else {
				if(sizeof(target) > 75) {
	                msg("Surely you can come up with a more concise name?");
   		        } else {
           		    PARTY_DAEMON->create_party(target, myName, 1);
               		PARTY_DAEMON->msg_party(target, capitalize(target) + " created, welcome!");
	            }
			}
			break;

		case "recruit": /*Bring someone into the party*/
			if( party ) {
				if(target == "") {
					msg("Please specify a player.");
				} else {
					object tempPlayer = find_player(target);
					if(tempPlayer != 0) {
						if(tempPlayer->query_env_var("party") != 0) {
				            msg("Sorry, that player is already in a party.");
       					} else {
		        			object accept = clone_object("/obj/accept");
							msg_object(tempPlayer, this_player()->query_cap_name() + " invites you to join the party, \"" + party + "\".");
							mixed sentParam = ({this_player(), tempPlayer, party});
							accept->set_verb(this_object());
							accept->set_yes("on_accept", sentParam);
							accept->set_no("on_reject", sentParam);
							accept->start(tempPlayer);
						}
					} else {
						msg("Sorry, that player isn't known.");
					}
				}
			} else {
				msg("You must be in a party to recruit a player.");
			}
			break;

		case "mentor": /* Start/stop mentoring somebody */
			if( party ) {
				if( target == "stop" ) {
					string pupil = this_player()->query_env_var("mentoring");
					if( !pupil )
						msg("You aren't mentoring anyone.");
					else {
						this_player()->remove_env_var("mentoring");
						msg("You stop mentoring "+capitalize(pupil));
						PARTY_DAEMON->msg_party(party, capitalize(myName)+" is no longer mentoring "+capitalize(pupil)+".");
					}
				} else if( target ) {
					object who = PARTY_DAEMON->find_member(target);
					string tmp;
					if( !who )
						msg("There is nobody by the name of '"+target+"' in your party.");
					else if( tmp = PARTY_DAEMON->query_mentor(myName) )
						msg("You're already being mentored by "+capitalize(tmp)+".");
					else if( tmp = who->query_env_var("mentoring") )
						msg(capitalize(target)+" is already mentoring "+capitalize(tmp)+".");
					else if( tmp = PARTY_DAEMON->query_mentor(target) )
						msg(capitalize(tmp)+" is already mentoring "+capitalize(target)+".");
					else {
						this_player()->set_env_var("mentoring",target);
						msg("You begin to mentor "+capitalize(target));
						PARTY_DAEMON->msg_party(party, capitalize(myName)+" is now mentoring "+capitalize(target)+".");
					}
				} else {
					msg("Please specify a party member to mentor.");
				}
			} else {
				msg("You must be in a party to mentor somebody.");
			}
			break;

		case "boot": /*Kicks someone out of a party*/
			if( party ) {
				if(target == "") {
					msg("Please specify a player.");
				} else {
					if(PARTY_DAEMON->query_party_leader(party) == myName) {
			            PARTY_DAEMON->msg_party(party, capitalize(myName) + " boots " + capitalize(target) + " from the party!");
       				    PARTY_DAEMON->kick_member(party, target, 1);
       				} else {
 			    	    msg("You must be the party leader to use boot.");
	         		}
				}
			} else {
				msg("You must be in a party and leader to boot someone.");
			}
			break;

		case "promote": /*Promotes someone to party leader*/
			if( party ) {
				if(target == "") {
					msg("Please specify a player.");
				} else {
		        	if(PARTY_DAEMON->query_party_leader(party) == myName) {
			            PARTY_DAEMON->msg_party(party, capitalize(target) + " is your new glorious leader!");
       				    PARTY_DAEMON->set_leader(party, target, 1);
	    		    } else {
	        		    msg("You must be the party leader to promote someone.");
       				}
				}
			} else {
				msg("You must be in a party and leader to promote.");
			}
			break;

		case "tell": /*Sends a tell to everyone in the party*/
			if( party ) {
				if(target == "") {
					msg("You don't want to waste the party's time with talk of nothing, do you?");
				} else {
			  		if(myName == PARTY_DAEMON->query_party_leader(party)) {
						PARTY_DAEMON->msg_party(party, "~[120" + capitalize(myName) + "~CDEF: " + target);
        	           } else {
						PARTY_DAEMON->msg_party(party, "~CREF" + capitalize(myName) + "~CDEF: " + target);
					}
				}
			} else {
				msg("You must be in a party to send a party tell.");
			}
			break;
	}
   return 1;
}

void on_accept(mixed param) {
    object recruiter = param[0];
    object recruitee = param[1];
    string party = param[2];

    "/daemon/party"->add_member(party, recruitee->query_name());
}

void on_reject(mixed param) {
    object recruiter = param[0];
    object recruitee = param[1];
    string party = param[2];
   msg_object(param[0], capitalize(param[1]->query_name()) + " rejects the recruit offer.");
}
