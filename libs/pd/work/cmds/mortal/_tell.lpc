#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

#define INTERMUD_TELLS 0

void help() {
  message("help",
    "Syntax: <tell [player] [message]>\n"+
    (INTERMUD_TELLS ?
      "       <tell [player]@[mud] [message]>\n" :
      "")+
    "\n"
    "Sends a private message to another player. "+
    (INTERMUD_TELLS ?
      "You can also send messages to players on other muds that are connected to Primal Darkness. " :
      "")+
    "\n\n"
    "See also: say, emote, yell, shout, reply, emoteto",
    this_player() );
}
int cmd_tell(string str) {
  object tp = this_player();
  object ob;
  string who, mud, from, msg, name;

  if (!str || str == "")
    FAIL("Tell who what?");

  if (sscanf(str, "%s %s", who, msg) != 2)
    FAIL("Tell who what?");

  if (INTERMUD_TELLS && sscanf(who, "%s@%s", name, mud) == 2)
  {
      if (!NETWORK_D->mud_exists(mud))
      {
          FAIL(mud_name()+" is not aware of that mud.");
      }
      else
      {
          SERVICES_D->send_gtell(mud, name, msg);
          return 1;
      }
  }

  else if (who == "salox" && "/adm/daemon/shutdown_d"->query_time_remaining())
  {
    message("tell", "You tell Salox: "+msg, tp);
    if (tp->query_race() == "unborn")
    {
      message("tell", "Salox tells you: You must be born, first!", tp);
      return 1;
    }
    write("You are magically teleported to the shop.");
    say(tp->query_cap_name()+" is whisked away to the shop.");
    tp->move("/d/nopk/tirun/supply");
    say(tp->query_cap_name()+" appears from nowhere.");
    tp->describe_current_room(1);
  }      

  else if(ob = find_living(who))
  {
    if ((wizardp(ob) && !wizardp(tp)) || archp(ob))
      from = capitalize(tp->query_name());
    else
      from = tp->query_cap_name();

    if (ob->query_ignoring(tp->query_name()))
      FAIL(capitalize(ob->query_subjective())+" is ignoring you.");

    if((int)ob->query_invis(tp) || hiddenp(ob))
    {
        ob->set("reply", tp->query_name());
        message("info", "Tell who what?", tp);
        message("tell", from + " tells you: "+msg, ob);
        //message("tell", "You tell "+ob->query_cap_name()+": "+msg, tp);
        return 1;
    }

    else if(userp(ob) && !interactive(ob))
      message("info", ob->query_cap_name()+" is net-dead.", tp);

    else if(userp(ob) && (query_idle(ob) > 60))
      message("info", ob->query_cap_name()+" is idle and "
        "may not have been paying attention.", tp);

    else if((int)ob->query_blocked("tell"))
    {
      message("info", (ob)->query_cap_name()+" is blocking all tells.", tp);
      return 1;
    }

    else if(in_edit(ob) || in_input(ob))
      message("my_action", ob->query_cap_name()+" is in input "
        "and may not be able to respond.", tp);

    else if(file_size("/wizards/"+ob->query_name()+"/.tellblock") >= 0)
      message("my_action",
        "\n"+read_file("/wizards/"+ob->query_name()+"/.tellblock"), tp);

    message("tell", "You tell "+ob->query_cap_name()+": "+msg, tp);
    message("tell", from + " tells you: "+msg, ob);

    ob->set("reply", (string)tp->query_name());

    LAST_D->add_tell((string)ob->query_name(),
      ""+ from + " tells you: "+msg);

    LAST_D->add_tell((string)tp->query_name(),
      "You tell "+ob->query_cap_name()+": "+ msg);

    "/cmds/system/_intercept"->global("tell",
      capitalize(tp->query_name())+" tells "+
      capitalize(ob->query_name())+": "+msg);
  }
  else
    FAIL("Tell who what?");

  return 1;
}


