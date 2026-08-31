mapping member, council, leader, main;
int cmd_induct(string str) {
mixed name, whoname;
name = this_player()->query_cap_name();
if(!this_player()->query_guild()) return 0;
if(!str) return notify_fail("Induct who?\n");
who = if(present(str, environment(this_player()))); else who = find_player(str);
if(!who) return notify_fail("No one online by that name.\n");
restore_object("/d/guilds/save/"+this_player()->query_guild());
if(!council[name] && !leader[name]) return notify_fail("You may not induct.\n"); 
if(who->query_guild()) return notify_fail("You may not add anyone with guild affiliation.\n");
if(!present("guilld_induct_ok_"+this_player()->query_guild(), who)) return notify_fail(""
"You do not have there permission to induct them.\n");
write("You induct "+who->query_cap_name()+" into "+this_player()->query_guild()+".");
tell_object(who, "You have been inducted into "+this_player()->query_guild()+".");

