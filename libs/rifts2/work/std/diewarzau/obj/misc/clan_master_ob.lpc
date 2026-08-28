/*
 * Object for the clan master.
 *
 * Diewarzau 10/14/96
 * DarkeLIB 1.0
 */

#include <daemons.h>
#include <clan.h>
#define PRIVS ([ "bad standing" : BAD_STANDING, "no teach" : NO_TEACH ])

inherit "/std/Object";

string clan_name;
string leader;

void init_arg(mixed *arg) {
  this_object()->set_clan_name(arg[0]);
  leader = arg[1];
  return;
}

void set_clan_name(string cname) {
  clan_name = cname;
  set_name("clan master object");
  set_id( ({ "symbol", "clan symbol" }) );
  set_short("The Symbol of Clan "+capitalize(cname));
  set_long("This emblem denotes the master of the clan of "+capitalize(cname)+".");
}

void set_leader(string str) {
  leader = str;
}

void create() {
 ::create();
  set_short("A generic clan leader symbol, BUGGED");
  set_id( ({"symbol", "clan symbol" }) );
  set_long("This symbol is bugged, talk to an arch.");
 
  set_property("no steal", 1);
  return;
}

mixed *query_auto_load() { 
  string file_name;

  file_name = base_name(this_object());
  return ({ file_name, ({ clan_name, leader }) });
}

int drop() { 
	 return 1;
	 }

void init() {

 if(!query("move flag"))
  if(this_player()->is_player() && environment() &&
     environment() == this_player() &&
     (string)this_player()->query_name() !=
     leader ) {
    write("The symbol disappears.");
 if(!archp(this_player()) ) remove();
    return;
  }
  else if(member_array(clan_name, (string *)CLAN_D->all_clans()) == -1 && !archp(this_player())) {
    write("%^CYAN%^%^BOLD%^-*> Your clan has been dissolved, due to lack of upkeep payment. <*-");
    remove();
    return;
  }
  else if(wizardp(this_player()) && leader ==
    (string)this_player()->query_name() && !archp(this_player())) {
    write("%^RED%^You are a wizard, and your clan is destroyed.");
    CLAN_D->remove_clan(clan_name);
    remove();
    return;
  }
  if(leader && leader == (string)this_player()->query_name()) {
    add_action("allow_player", "admit");
    add_action("kick_player", "dismiss");
    add_action("list_membership", "list");
    add_action("help", "help");
    add_action("set_privs", "setpriv");
  }
}

int set_privs(string str) {
  string player, priv;

  if(sscanf(str, "%s for %s", priv, player) != 2)
    return notify_fail("Usage: setpriv <privilege> for <player>\n");
  player = lower_case(player);
  if(!CLAN_D->clan_member(player, clan_name)) {
    write(capitalize(player) + " is not a member of your clan.");
    return 1;
  }
  if(member_array(priv, keys(PRIVS)) == -1) {
    write("That is not a valid privilege.  List of privileges:\n"+
        format_page(keys(PRIVS), 2));
    return 1;
  }
  if(CLAN_D->test_member_priv(clan_name, player, PRIVS[priv])) {
    write("Removed privilege '"+priv+"' from "+capitalize(player)+".");
    CLAN_D->remove_member_priv(clan_name, player, PRIVS[priv]);
    return 1;
  }
  write("Adding privilege '"+priv+"'.");
  CLAN_D->add_member_priv(clan_name, player, PRIVS[priv]);
  return 1;
}

void rid_gm_ob() {
  if(!environment()) remove();
  if((string)environment()->query_name() != leader) remove();
  return;
}

int list_membership(string str) {
  string *mem, list;
  int i;

  if(!str || str != "members") return 0;
  mem = map_array((string *)CLAN_D->all_members(clan_name), (: capitalize :));
  list = "Membership list:\n"+repeat_string("-=", 35)+"\n"+
	format_page(mem, 3);
	this_player()->more(explode(list, "\n"));
  return 1;
}

int kick_player(string str) {
  object plyr;
  
  if(!str) return 0;
  str = lower_case(str);
  if(!(plyr=find_player(str))) {
    write("A player must be logged on to be kicked out of his or her clan.");
    return 1;
  }
  if(!CLAN_D->clan_member(str, clan_name)) {
    write(capitalize(str) + " is not a member of your clan.");
    return 1;
  }
  CLAN_D->remove_member(str, clan_name);
  plyr->set_guild(0);
  write(capitalize(str) + " has been kicked out of the clan.");
  return 1;
}

int help(string str) {
  string help_str;
  
  if(str != "clan leader") return 0;
  help_str =
	  "admit <player>\n"+
	  "\tAdmits <player> into your clan.\n"+
	  "\ndismiss <player>\n"+
	  "\tKicks <player> out of your clan.  The player has to be on to do this.\n"+
	  "NOTE: Once a player is kicked out of your clan, he/she may NEVER rejoin.\n"+
	  "\nlist members\n"+
	  "\tGet a complete list of clan membership.\n"+
	  "\nhelp clan leader\n"+
	  "\tThis help.\n" +
	  "\nsetpriv <privilege> for <player>\n"+
	  "\tAdds or removes <privilege> from <player>.\n"+
	  "Current privileges:\n"+
	  "'no teach'  - Bars players from learning skills/spells in the teaching room.\n"
	  "'bad standing' - The guards will not lower the draw bridge for this player.\n";
	  this_player()->more(explode(help_str, "\n"));
  return 1;
}

int allow_player(string str) {
  object who;
  string guild;

  if(!str) return 0;
  who = present(lower_case(str), environment(this_player()));
  if(!who) {
    write(capitalize(str)+" isn't here.");
    return 1;
  }
  if(who->query_guild() && (string)who->query_class() != "none") {
    write(capitalize(str)+" is already the member of a clan.");
    return 1;
  }
  if(((int)this_player()->query_level() - (int)who->query_level()) < 7) {
    write("That player is fewer than 7 levels below you, and therefore may not "+
      "be admitted to your clan.");
    return 1;
  }
  if(find_object("/d/damned/guilds/join_rooms/"+who->query_class()+"_join")->query_master() == lower_case(str))
	{
	write("That player is a guildmaster, he/she cannot join your clan\n until they give up their leadership.");
	return 1;
	}
  switch((int)CLAN_D->add_member((string)who->query_name(), clan_name)) {
  case 0:
    write("That player has been a member of your clan before and is forbidden to "
      "join again.");
    return 1;
  case -2:
    write("That player is already a member of your clan.");
    return 1;
  case -1:
    write("Clan Daemon error, your clan does not exist...report to an arch.");
    return 1;
  case 1:
  default:
    write(capitalize(str) + " is now a member of your clan.");
    message("info", "You are now a member of Clan "+capitalize(clan_name)+".", who);
    who->set_guild(clan_name);
    return 1;
  }
}
