#include <std.h>
#include <daemons.h>

inherit DAEMON;

#define INTERMUD_TELLS 1

int cmd_tell2(string str)
{
    string *words;
    object ob;
    int i, max;
    string who, mud, frm, msg, tmp;

    if (!(str && strlen(str)))
    {
	return notify_fail("Syntax: <tell [who] [message]>\n");
    }

    if (sscanf(str, "%s %s", who, msg) != 2)
    {
	return notify_fail("Tell whom what?\n");
    }

    if (INTERMUD_TELLS && sscanf(who, "%s@%s", who, mud) == 2)
    {
	if (!NETWORK_D->mud_exists(mud))
	{
	    return notify_fail(mud_name()+" is not aware of that mud.\n");
	}
	else
	{
	    SERVICES_D->send_gtell(mud, who, msg);
	    return 1;
	}
    }
    else
    {   
	if(ob = find_living(who))
	{
	    if(archp(ob))
	    {
		frm = this_player()->query_cap_name();
	    }
	    else
	    {
		frm = capitalize(this_player()->query_name());
	    }

	    if(ob->query_ignoring(this_player()->query_name())) {
		return notify_fail("They are ignoring you.\n");
	    }

	    if((int)ob->query_invis(this_player()) || hiddenp(ob))
	    {
		ob->set("reply", this_player()->query_name());
		message("error", "Tell whom what?", this_player());
		message("tell", frm + " tells you: "+msg, ob);
	    }

	    else if(userp(ob) && !interactive(ob))
	    {
		message("my_action", ob->query_cap_name()+
		  " is net-dead.", this_player());
	    }

	    else if(userp(ob) && (query_idle(ob) > 60))
	    {
		message("my_action", ob->query_cap_name()+
		  " is idle and may not have been paying attention.", this_player());
	    }

	    else if((int)ob->query_blocked("tell"))
	    {
		message("my_action", (ob)->query_cap_name()+" is blocking "+
		  "all tells.", this_player());
		return 1;
	    }

	    else if(in_edit(ob) || in_input(ob))
	    {
		message("my_action", ob->query_cap_name()+" is in input "+
		  "and may not be able to respond.", this_player());
	    }

	    else if(file_size("/wizards/"+ob->query_name()+"/.tellblock") >= 0)
	    {
		message("my_action", "\n"+read_file("/wizards/"
		    +ob->query_name()+"/.tellblock"),
		  this_player());
	    }

	    message("tell", "You tell "+ob->query_cap_name()+
	      ":"+msg, this_player());
	    message("tell", frm + " tells you: "+msg, ob);

	    LAST_D->add_tell((string)ob->query_name(),
	      ""+(string)capitalize(this_player()->query_name() + " tells you:"+msg));
	    ob->set("reply", (string)this_player()->query_name());
	    LAST_D->add_tell((string)this_player()->query_name(),
	      "You tell "+ob->query_cap_name()+":"+ msg);
	    "/cmds/system/_intercept"->global("tell",
	      this_player()->query_cap_name()+" tells "+ob->query_cap_name()+":"+  msg);
	}         
    }
    return 1;
}


/*  if("/adm/daemon/shutdown_d"->query_time_remaining()) {
if(this_player()->query_race() == "unborn") return notify_fail("%^CYAN%^Salox says: %^RESET%^You must be born, first!\n");
write("You are magically teleported to the shop.");
say(this_player()->query_cap_name()+" is whisked away to the shop.");
this_player()->move("/d/nopk/tirun/supply");
say(this_player()->query_cap_name()+" appears from nowhere.");
this_player()->describe_current_room(1);
return 1;
}
*/
