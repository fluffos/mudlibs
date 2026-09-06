#ifndef TMARK_C

#include <living_defs.h>
#include <room_defs.h>
#include "../thief.h"

#define BIN_CHANNEL_D "/bin/daemons/channel_d"

string query_name();

object owner, summoner, summon_room;
int guildmaster, summon_time;
mixed setlines, setmode;
string tattoo_desc, pretitle;

#endif

status
gmc(string arg)
{
    if (!guildmaster) return 0;

    if (!arg)
	return call_other("/bin/pub/_channel",
	  "channel_cmd", "thiefgmc who", owner);

    return call_other("/bin/pub/_channel", "channel_cmd",
      "thiefgmc send " + arg, owner);
}

status
gmctoggle()
{
    if (!guildmaster) return 0;
    return call_other("/bin/pub/_channel", "channel_cmd",
      "thiefgmc toggle", owner);
}

status
gmcread(string arg)
{
    if (!guildmaster) return 0;

    if (environment(owner)->query(ROOM_ISOLATED))
    {
	owner->tell_me("Nothing on channel log.");
	return 1;
    }

    return "/bin/pub/_channel"->channel_cmd("thiefgmc hist", owner);
}

int
manage_gm(string arg)
{
    int l;
    string victim;

    if (guildmaster < TR_DEMON) return 0;

#ifdef OLD_GOVERNMENT
    if (guildmaster >= TR_DEMON)
    {
	notify_fail("Leave those things to Guildmasters.\n");
	return 0;
    }
#endif
    if (!arg)
    {
	notify_fail("Usage: " + query_verb() + " <thief name>\n");
	return 0;
    }

    victim = lower_case(arg);

#ifdef OLD_GOVERNMENT
    if (query_verb() == "promotegm")
    {
	if (guildmaster != TR_GM)
	{
	    notify_fail("Only the GM can promote Co-Gm's\n");
	    return 0;
	}
	if (member(GM_D->query_enforcers(), victim) != -1)
	    GM_D->remove_enforcer(victim);
	if (member(GM_D->query_demons(), victim) != -1)
	{
	    owner->tell_me("You can't promote demons!");
	    return 1;
	}
	GM_D->add_co_gm(victim);
	return 1;
    }
    else
#endif
    if (query_verb() == "promote")
    {
#ifdef OLD_GOVERNMENT
	if (member(GM_D->query_co_gm(), victim) != -1)
	    GM_D->remove_co_gm(victim);
#endif
	if (member(GM_D->query_demons(), victim) != -1)
	{
	    owner->tell_me("You can't promote Demons!");
	    return 1;
	}
	GM_D->add_enforcer(victim);
	return 1;
    }
#ifdef OLD_GOVERNMENT
    else
    if (query_verb() == "demotegm")
    {
	if (guildmaster != TR_GM)
	{
	    notify_fail("Only the GM can demote Co-Gm's.\n");
	    return 0;
	}
	if (member(GM_D->query_co_gm(), victim) == -1)
	{
	    owner->tell_me(victim + " is not a co-gm.");
	    return 1;
	}
	GM_D->remove_co_gm(victim);
	return 1;
    }
#endif
    if (query_verb() == "demote")
    {
	if (member(GM_D->query_enforcers(), victim) == - 1)
	{
	    owner->tell_me(victim + " is not an enforcer.");
	    return 1;
	}
	GM_D->remove_enforcer(victim);
	return 1;
    }
    owner->tell_me("Do what!?");
    return 1;
}

int
tax_set(string arg)
{
    object *u, tm;
    int am, tb, tpl, tfull, tdec, i;

    if (guildmaster > 0)
	if (arg && arg == "list")
	{
	    write("Thieve's tax debts and time after last paid any:\n");
	    u = users();
	    for (i = sizeof(u) - 1; i >= 0; i--)
	    {
		if (!u[i]->query_coder_level() &&
		  !u[i]->query_testplayer() &&
		  (tm = present("tmark", u[i])))
		{
		    tb = time() - (int)tm->query_tax_time();
		    tpl = tb / 3600;
		    tb = tpl / 24;
		    if (tb > 0) tpl -= (tb * 24);
		    write(sprintf("%-20s: %10d coins\t%d d %d h\n",
			Realname(u[i]),
			(int)tm->query_tax(), tb, tpl));
		}
	    }
	    return 1;
	}

    if (guildmaster < TR_DEMON) return 0;

    /*
      if (guildmaster >= TR_DEMON)
      {
      notify_fail("Let Guildmasters handle those.\n");
      return 0;
      }
      */

    tb  = (int)GUILD->query_tax_base();
    tpl = (int)GUILD->query_tax_per_level();

    if (!arg)
    {
	TM("Tax base level is currently " + tb + "%.");

	tfull = tpl / 10;
	tdec = (tpl - tfull * 10);

	TM("Tax base increases " + tfull + "." + tdec +
	  "% per level of thief.");
	TM("Sample tax rates:");
	for (i = 1; i < 35; i += 5)
	    write("Lvl " + i + ":" + (tb + (tpl * i) / 10) + "% ");
	write(
	  "\nUse commands \"tax base <x>\" and \"tax level <x>\" to change.\n");
	return 1;
    }

    if (sscanf(arg, "base %d", am) == 1)
    {
	if (am < 0 || am > 95)
	{
	    TM("Illegal amount. Base tax should be 0 to 95%.\n");
	    return 1;
	}

	TM("Ok. You set base tax to " + am + "%.\n");
	GUILD->set_tax_base(am);
	tax_set(0);
	return 1;
    }

    if (sscanf(arg, "level %d", am) == 1)
    {
	if (am < 0 || am > 500)
	{
	    TM("Illegal tax increase per level.\n");
	    return 1;
	}

	if (((int)GUILD->query_tax_base() + am * 4) > 95)
	{
	    TM("That would be over 95% with high level characters!\n"+
	      "Try a smaller amount.");
	    return 1;
	}

	tfull = am / 10;
	tdec = am - (tfull * 10);
	TM("Ok. You set tax increase per level to " + tfull + "." +
	  tdec + "%.");
	GUILD->set_tax_per_level(am);
	tax_set(0);
	return 1;
    }

    return 0;
}

int
gmeditor(string arg)
{
    string tit;

    if (!arg)
    {
	notify_fail("Set what?\n");
	return 0;
    }

    if (arg == "tattoo")
    {
	TP->tell_me("Your tattoo looks like this: \"" +
	  (tattoo_desc ? tattoo_desc : (string) query_name()) +
	  "\". Use command \"set tattoo Thieve's Tattoo\" (or \
whatever you want it to look like) to change it.");
	return 1;
    }

    if (arg == "pretitle")
    {
	if (guildmaster < TR_DEMON)
	{
	    notify_fail("Only demons can set their pretitle.\n");
	    return 0;
	}

	TP->tell_me("Your pretitle is \"" + pretitle + "\".\n\
'set pretitle [whatever]' to change it. Max 14 characters.");
	return 1;
    }

    if (sscanf(arg, "tattoo %s", tit) == 1)
    {
	if (owner->query_level() < 30)
	{
	    TP->tell_me("You have to be at least of level 30 to use this!");
	    return 1;
	}

	if (tit == "0")
	{
	    tattoo_desc = 0;
	    TP->tell_me("Using default tattoo description (\"" +
	      query_name() + "\").");
	    return 1;
	}

	if (!valid_desc(tit))
	    return 1;

	tattoo_desc = tit;

	TP->tell_me("Your tattoo now looks like this: \"" + tit + "\".");

	return 1;
    }

    if (sscanf(arg, "pretitle %s", tit) == 1)
    {
	if (guildmaster < TR_DEMON)
	{
	    notify_fail("Only demons can set their pretitle.\n");
	    return 0;
	}

	if (owner->dump_esc(tit))
	    return 1;

	if (sizeof(tit) > 14)
	{
	    TM("Maximum length of pretitle is 14.");
	    return 1;
	}

	if (tit == "clear" || tit == "none")
	{
	    pretitle = "0";
	    TM("Ok, not using any pretitle.");
	    return 1;
	}

	pretitle = tit;
	TM("Ok, your pretitle in channel is now \"" + tit + "\".\n");
	return 1;
    }

    notify_fail("Only the guild leaders can do that!\n");

    if (guildmaster < TR_GUILDMASTER)
	return 0;

    if (!arg ||
      (arg != "rules" && arg != "rewards" && arg[0..5] != "punish"))
    {
	notify_fail("Usage: set <rules/punish(ments)/rewards>\n");
	return 0;
    }

    setlines = ({});

    if (arg == "rules" || arg == "rewards")
	setmode = arg;
    else
	setmode = "punishments";

    write(
      "Type " + setmode + " in (max. 48 lines). ** to finish, ~q to cancel.\n]");

    input_to("set_loop", 0);
    return 1;
}

void set_loop(string arg)
{
    int i;

    if (!setmode)
    {
	notify_fail("What are YOU trying? (Illegal attempt logged).\n");
	return;
    }

    if (arg == "~q")
    {
	notify_fail("\nOk, canceled.\n");
	setmode = 0;
	return;
    }

    if (arg == "**")
    {
	rm(GDIR + "doc/" + setmode);
	for (i = 0; i < sizeof(setlines); i++)
	    LOG_FILE("doc/" + setmode,
	      setlines[i] + "\n");
	LOG_FILE("doc/" + setmode, "\n");
	TM("\nDone.");
	setmode = 0;
	return;
    }

    setlines += ({ arg });

    if (sizeof(setlines) >= 48)
    {
	TM("\nOut of space.\n");
	set_loop("**");
	return;
    }

    write("]");
    input_to("set_loop", 0);
    return;
}

int
wrath(string arg)
{
    string n;
    object victim, tm, *u;
    int t, b;

    if (guildmaster < TR_DEMON)
	return 0;

#ifdef OLD_GOVERNMENT
    if (guildmaster >= TR_DEMON)
    {
	notify_fail("Leave those things to Guildmasters.\n");
	return 0;
    }
#endif

    if (!arg ||
      (arg != "list" &&
	sscanf(lower_case(arg), "%s for %d", n, t) != 2))
    {
	notify_fail("Usage: " + query_verb() +
	  " <thief name> for <time seconds>\n"+
	  "If you give time 0, it clears the wrath.\n"+
	  "'wrath list' lists the current wraths on thieves.\n"+
	  "WRATH MAY NOT BE USED FOR PLAYER KILLING!\n"+
	  "However, it CAN be used to _prevent_ PK!\n");
	return 0;
    }

    if (arg == "list")
    {
	u = users();
	for (t=0;t < sizeof(u);t++)
	{
	    if (u[t]->query_coder_level()
	      || ((string)u[t]->query_guild() != "thief")) continue;
	    if (b = ( (int) u[t]->query_ban() - time() ) > 0)
		TM(sprintf("%-20s: %d seconds\n",
		    capitalize((string)environment(u[t])->query_real_name()),
		    b));
	}
	if (!t)
	    TM("No one seems to be under Wrath of Skert now.");
	return 1;
    }

    if (!(victim = find_player(n)) ||
      victim->query_coder_level() ||
      ((string)victim->query_guild() != GN_THIEF) ||
      !(tm = (object)victim->query_guild_object()))
    {
	notify_fail("Who's that?\n");
	return 0;
    }

#ifdef OLD_GOVERNMENT
    if ((int)tm->query_guildmaster() >= TR_DEMON)
    {
	TM("You can't do that!");
	return 1;
    }
#endif

    // 3600 was nothing. This really does something! /Graah
    if (t && (t < 10 || t > 604800))
    {
	TM("Minimum time is 10 seconds, maximum 604800 seconds (1 week).");
	return 1;
    }

    if (tm->query_ban())
    {
	TM("Old wrath cleared.");
	if (!t)
	{
	    tm->set_ban(0);
	    LOG_FILE("WRATH_LOG",
	      ctime(time()) + ": " + Realname(owner) +
	      " removed Wrath from " +
	      Realname(victim) + "\n");
	    return 1;
	}
    }
    else
    if (!t)
    {
	TM("There wasn't any wrath to remove.");
	return 1;
    }

    tm->set_ban(time() + t);

    LOG_FILE("WRATH_LOG",
      ctime(time()) + ": " + Realname(owner) +
      " set " + t + " sec on " +
      Realname(victim) + "\n");

    TM("Ok. " + capitalize(n) + " is now under Wrath of Skert for " +
      t + " seconds.");

    victim->tell_me(
      "\nSuddenly your tattoo starts to glow red hot!\n"+
      "You are now under the WRATH OF SKERT!");

    return 1;
}
int showlogs(string arg)
{
    if (1)
	return 0;
    if (guildmaster < TR_ENFORCER)
	return 0;

    if (!arg)
    {
	notify_fail("Usage: show <steals/sign/join/resign/burglar/"
	  "eq\n");
	return 0;
    }

    if (arg[0..4] == "steal")
    {
	tail(GDIR + "STEAL_LOG");
	return 1;
    }
    else
    if (arg[0..3] == "sign")
    {
	tail(GDIR + "SIGN_LOG");
	return 1;
    }
    else
    if (arg[0..3] == "join")
    {
	tail(GDIR + "JOIN_LOG");
	return 1;
    }
    else
    if (arg[0..5] == "resign")
    {
	tail(GDIR + "RESIGN_LOG");
	return 1;
    }
    else
    if (arg[0..5] == "burgla")
    {
	tail(GDIR + "BURGLAR");
	return 1;
    }
    else
    if (arg[0..3] == "stab")
    {
	if(owner->query_coder_level())
	    tail(GDIR + "PK_STAB_DMG");
	return 1;
    }
    else
    if(arg[0..1] == "eq")
    {
	tail(GDIR+"EQ_LOG");
	return 1;
    }

    return 0;
}

status
gag_cmd(string who)
{
    owner->tell_me("Gag command is not available at the moment.");
    return 1;
}

int kickout(string arg)
{
    object victim, tm;

    if (guildmaster < TR_DEMON)
	return 0;

#ifdef OLD_GOVERNMENT
    if (guildmaster >= TR_DEMON)
    {
	notify_fail("Leave those things to Guildmasters.\n");
	return 0;
    }
#endif

    if (!arg)
    {
	notify_fail("Who do you want to kick out of the guild?\n");
	return 0;
    }
    if(GM_D->query_runner())
	if(arg == GM_D->query_runner()) {
	    notify_fail("Nice try bitch.\n");
	    return 0;
	}

    if (!(victim = find_player(arg)))
    {
	notify_fail("Can't find player " + capitalize(arg) +" in the game.\n");
	return 0;
    }

    tm = (object)victim->query_guild_object();
    if (!(tm->id("tmark")))
    {
	notify_fail("It seems that " + arg +" has already been kicked out.\n");
	return 0;
    }

#ifdef OLD_GOVERNMENT
    if (tm->query_guildmaster() >= TR_DEMON)
    {
	notify_fail("You can't do that!\n");
	return 0;
    }
#endif

    /* Can't kick co-guildmaster */
    if ((victim->query_coder_level() > 0) ||
      tm->query_guildmaster() >= TR_DEMON)
    {
	notify_fail("You cannot kick this one out. \n");
	return 0;
    }

#ifdef OLD_GOVERNMENT
    if (tm->query_guildmaster())
    {
	notify_fail(capitalize(arg) + " seems to be an Enforcer. Demote " +
	  (string)victim->query_objective() + " first.\n");
	return 0;
    }
#endif

    TM("Ok. You kick " + capitalize(arg) + " out from the Guild!\n");
    victim->tell_me("\n\n" +(string)owner->query_name() +
      " kicks you out of the Guild of Thieves!!!\n\n");

    tm->backup_log("KICKED_LOG"); /* Save skills to log file */

    if (tm->query_sneak())
	tm->stop_sneak();

    // CHANNEL_D->remove_channel_member(victim->query_guild_object());
    BIN_CHANNEL_D->remove_from_channel("thief", victim);
    BIN_CHANNEL_D->remove_from_channel("thiefgmc", victim);
    BIN_CHANNEL_D->remove_from_channel("thiefdmn", victim);

    destruct(tm); /* That's it. */

    victim->set_title("the ex-thief");
    victim->set_guild(0);

    /* TODO perhaps: get his garrotte... */

    return 1;
}


status demon(string arg)
{
    if (guildmaster < TR_DEMON)
	return 0;

    if (!arg)
	return call_other("/bin/pub/_channel", "channel_cmd", "thiefdmn who",
	  owner);

    return call_other("/bin/pub/_channel", "channel_cmd",
      "thiefdmn send " + arg, owner);
}

/*
int showlogs(string arg)
{
  if(guildmaster < TR_DEMON)
      return 0;

   if (!arg)
   {
     notify_fail("Usage: show <steals/join(ings)/resign(ings/burglar/"
     "eq\n");
      return 0;
   }

   if (arg[0..4] == "steal")
   {
      tail(GDIR + "STEAL_LOG");
      return 1;
   }
   else
      if (arg[0..3] == "join")
      {
	 tail(GDIR + "JOIN_LOG");

      }
      else
	 if (arg[0..5] == "resign")
	 {
	    tail(GDIR + "RESIGN_LOG");
	    return 1;
	 }
	 else
	    if (arg[0..5] == "burgla")
	    {
	       tail(GDIR + "BURGLAR");
	       return 1;
	    }
*/

status demonread()
{
    if (guildmaster != TR_DEMON)
	return 1;

    if (environment(owner)->query(ROOM_ISOLATED))
    {
	owner->tell_me("Nothing on channel log.");
	return 1;
    }

    return "/bin/pub/_channel"->channel_cmd("thiefdmn hist", owner);
}

status demontoggle()
{
    if (guildmaster < TR_DEMON)
	return 0;

    return call_other("/bin/pub/_channel", "channel_cmd", "thiefdmn toggle",
      owner);
}

status
goto(string arg)
{
    object ob;

    if (guildmaster < TR_DEMON || owner->query_coder_level()) {
	notify_fail("But it's a demon-only command...\n");
	return 0;
    }

    if (!arg) {
	notify_fail("Ok, discarding the summon request.\n");
	return (summoner = 0);
    }

    if (!summoner) {
	this_player()->tell_me("But no-one is summoning you...");
	return 1;
    }
    if (!(ob = find_player(arg))) {
	this_player()->tell_me("No such player in the game,\
 as far as you can see.");
	return 1;
    }
    if (ob != summoner) {
	this_player()->tell_me("But you are already being summoned\
 by"+(string)summoner->query_real_name()+".");
	return 1;
    }

    if (!environment(summoner))
    {
	notify_fail(sprintf("Too late, %s has ceased to exist.\n", arg));
	return 0;
    }

    if (environment(owner)->query(PREVENT_TELEPORT_FROM))
    {
	notify_fail("You can't teleport from here, sorry.\n");
	return 0;
    }

    if (owner->query_sp() < 10)
    {
	notify_fail("You'll need a formal 10 spell points for this.\n");
	return 0;
    }

    if(time() > summon_time)
    {
	notify_fail("You waited to long to respond..the need is over.\n");
	return (summoner = 0);
    }

    owner->add_sp(-10);

    TM(
      "You answer to the call. The force of the summoning chant carries you away...");
    owner->move_player("X", summon_room);
    summoner = 0;

    return 1;
}
