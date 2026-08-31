/* Do not remove the headers from this file! see /USAGE for more info. */

#include <config/guild.h>

inherit M_CONVERSATION;
inherit M_RSTVIEW;

varargs void targetted_action();
void add_a_member(object who);
void release_a_member(object who);

private
string which_guild;

/* ---------------------------------------------------
**
** These functions can be overridden to modify the behavior of the
** messages/errors issued by the "guild master"
*/
void guildmsg_new_conflict(object who, string why)
{
   targetted_action("$N $vlook sternly at $t and $vsay, \"As a member of $o, I cannot allow you to use our facilities "
                    "anymore.  When you leave them, I'm sure that you'll be more than welcome back.\"",
                    who, why);
}
void guildmsg_welcome_back(object who)
{
   targetted_action("$N $vwelcome $t back to the $o.", who, GUILD_D->query_guild_title(which_guild));
   CHANNEL_D->cmd_channel(which_guild, "/off");
}
void guildmsg_not_member(object who)
{
   targetted_action("$N $vpoint out to $t, \"You aren't a member of the $o.\"", who,
                    GUILD_D->query_guild_title(which_guild));
}
void guildmsg_already_member(object who)
{
   targetted_action("$N $vpeer quizzically at $t and $vsay, \"You already belong to our association.\"", who);
}
void guildmsg_refuse_entry(object who, string why)
{
   targetted_action("$N $vstare unpleasantly at $t and $vgrowl, \"Not while you belong to $o.\"", who, why);
}
void guildmsg_welcome(object who)
{
   targetted_action("$N $vwelcome $t to the $o.", who, GUILD_D->query_guild_title(which_guild));
   CHANNEL_D->cmd_channel(which_guild, "/on");
}

void guildmsg_leave_nicely(object who)
{
   targetted_action("$N $vbid $t farewell, \"Perhaps another time?\".", who);
   CHANNEL_D->cmd_channel(which_guild, "/off");
}

void guildmsg_leave_badly(object who)
{
   targetted_action("$N $vsay, \"So be it, $tp. Leave this place.\"", who);
   CHANNEL_D->cmd_channel(which_guild, "/off");
}
void guildmsg_leave_as_enemy(object who)
{
   targetted_action("$N $vsnarl, \"So be it, $tp. You have chosen your doom.\"", who);
   CHANNEL_D->cmd_channel(which_guild, "/off");
}

/* --------------------------------------------------- */

void artefact_install()
{
}

void more_specials_help()
{
   write("\n\n" + rst_format_file("/cmds/guild/" + which_guild + "/SPECIALS_HELP.rst"));
}

string guild_name()
{
   return GUILD_D->query_guild_abbrev(which_guild);
}

void setup_guild_conversation()
{
   string *start = ({"artefact", "specials"});

   add_options((["join":"Can I join " + guild_name() + "?",
                "release":"I need to leave " + guild_name() + " ...",
               "artefact":"Would a " + GUILD_ARTEFACT + " be useful for me in " + guild_name() + "?",
        "artefact_module":"If I have an empty " + GUILD_ARTEFACT + " " + GUILD_ARTEFACT_PLUGIN + ", can you put a " +
                              guild_name() + " program on it?",
       "artefact_install":"Okay, then I'll give you one.", "comms":"Can we communicate somehow?",
               "specials":"Which special skills can I learn?", ]));

   add_responses((["join":(
                              : add_a_member($1)
                              :),
                "release":(
                              : release_a_member($1)
                              :),
               "artefact":"Yes, we use those to coordinate our activities. Go find or buy a " + GUILD_ARTEFACT +
                              " somewhere and a " GUILD_ARTEFACT + " " + GUILD_ARTEFACT_PLUGIN +
                              ".@@artefact_module,comms",
        "artefact_module":"No, but I can swap that empty one for one with our program on it.@@artefact_install",
       "artefact_install":"That's fine, give it to me when we're done chatting and I'll swap it for you.",
                  "comms":"Yes, try 'chan " + which_guild + " /on'. That should tune you in.",
               "specials":({"Let me see... have a look here", (
                                                                  : more_specials_help:)}),
   ]));
   add_start(start);
}

string *filter_start(string *a, object body)
{
   if (body->query_member_guild(which_guild))
      a += ({"release"});
   else
      a += ({"join"});

   return a;
}

protected
nomask void set_which_guild(string new_guild)
{
   which_guild = new_guild;
   setup_guild_conversation();
}

mixed do_guild_check(object who)
{
   if (!who)
      who = this_body();

   return GUILD_D->guild_is_ok(which_guild, who->guilds_belong());
}

string query_which_guild()
{
   return which_guild;
}

void recheck_a_member(object who)
{
   mixed p;

   if (!who)
      who = this_body();

   p = do_guild_check(who);
   if (p)
   {
      guildmsg_new_conflict(who, p);
      who->suspend_guild(which_guild, GUILD_D->query_guild_suspend_level(which_guild));
   }
   else
   {
      guildmsg_welcome_back(who);
      who->unsuspend_guild(which_guild);
   }
}

void add_a_member(object who)
{
   mixed p;

   if (!who)
      who = this_body();

   if (who->query_member_guild(which_guild))
   {
      guildmsg_already_member(who);
   }
   else
   {
      p = do_guild_check(who);
      if (p)
      {
         guildmsg_refuse_entry(who, p);
      }
      else
      {
         who->add_guild(which_guild, 1);
         guildmsg_welcome(who);
      }
   }
}

void release_a_member(object who)
{
   if (!who)
      who = this_body();

   if (!who->query_member_guild(which_guild))
   {
      guildmsg_not_member(who);
      return;
   }

   switch (GUILD_D->query_guild_begone(which_guild))
   {
      // ### --OH: 0 should do a revoke guild, 1 do a ban guild(1)
      // ###       that means that when try to rejoin get welcome back msg

   default:
   case 0:
   case 1:
      guildmsg_leave_nicely(who);
      who->revoke_guild(which_guild);
      return;

   case 2:
      guildmsg_leave_nicely(who);
      who->revoke_guild(which_guild);
      who->ban_guild(which_guild, 2);
      return;

   case 3:
      guildmsg_leave_as_enemy(who);
      who->revoke_guild(which_guild);
      who->ban_guild(which_guild, 3);
      return;
   }
}

mixed guild_master_receive(object target)
{
   string questState;

   if (base_name(target) == "/domains/std/guild/item/artefact_module")
   {
      if (!target->query_module_name())
      {
         this_object()->simple_action("$N $vsay, \"An empty module, just a second ...\".");
         target->set_module_name(which_guild);
         this_object()->targetted_action("$N $vhand $n1 a programmed module back.", this_body());
         return 0;
      }
      else
      {
         this_object()->simple_action(
             "$N $vsay, \"There's also a program on that one, but it can be reset later ... give me a second.\".");
         target->set_module_name(which_guild);
         this_object()->targetted_action("$N $vhand $n1 a programmed module back.", this_body());
         return 0;
      }
   }
   else
   {
      this_object()->simple_action("$N $vsay, \"Why would I want that?\".");
      return 0;
   }
}

mixed indirect_give_obj_to_liv(object ob, object liv)
{
   if (base_name(ob) == "/domains/std/guild/item/artefact_module")
   {
      return 1;
   }
   return 0;
}