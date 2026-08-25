/* Do not remove the headers from this file! see /USAGE for more info. */

/**
 * MESSAGING_D for holding different messages for the MUD in the standard format.
 * The files in this daemon is held in /data/messages/ in a simple format.
 * Lines can be repeated for random selections of messages.
 */

#define MESSAGE_DIR "/data/messages/"
#define PRIV_NEEDED "Mudlib:daemons"

inherit M_DAEMON_DATA;
inherit M_COLOURS;

private
mapping messages;
private
nosave string *mandatory_cmbt_msgs = ({"none", "disarm", "knockout", "knockdown", "miss", "fatal", "dam1", "dam2",
                                       "dam3", "dam4", "dam5", "dam6", "dam7", "dam8", "dam9", "dam10"});
private
object troll;

mixed query_messages(string type)
{
   return messages[type];
}

void save_messages()
{
   save_me();
   write("MESSAGES_D saved.");
}

varargs void load_messages(string type, int batch)
{
   string *content = explode(read_file(MESSAGE_DIR + type), "\n");
   int combat = type[0..5] == "combat";
   mapping m = ([]);

   foreach (string c in content)
   {
      string name, action;
      if (sscanf(c, "%s:%s", name, action) != 2 || c[0] == '#')
         continue;
      action = punctuate(trim(action));

      // If action is too short or doesn't contain a $n or a verb $v, it's not a valid combat action.
      if (strlen(action) < 3 ||
          (combat && (strsrch(lower_case(action), "$n") == -1 || strsrch(lower_case(action), "$v") == -1)))
         error("Bad action in " + type + " for " + name);

      if (arrayp(m[name]))
         m[name] += ({action});
      else if (stringp(m[name]))
         m[name] = ({m[name], action});
      else if (!m[name])
         m[name] = action;
   }

   // Combat messages
   if (combat)
   {
      if (sizeof(mandatory_cmbt_msgs - keys(m)) != 0)
         error("Missing combat message types in " + type + ": " + format_list(mandatory_cmbt_msgs - keys(m)));
      if (sizeof(keys(m) - mandatory_cmbt_msgs) != 0)
         error("Unknown message types in " + type + ": " + format_list(keys(m) - mandatory_cmbt_msgs));
      messages[type] = m;
   }
   // Defeault messages for living
   else if (type == "living-default" || type == "trainer-default")
   {
      messages[type] = m;
   }
   // Base messages are inserted directly into messages mapping.
   else if (type == "base-default")
   {
      messages += m;
   }
   // Fail explicitly on other file types for now.
   else
      error("Unknown file type: " + type);

   write("Messages '" + type + "' updated from file.");
   if (!batch)
      save_messages();
}

string *combat_messages()
{
   return sort_array(mandatory_cmbt_msgs, 1);
}

void refresh_messages()
{
   string *files = get_dir("/data/messages/");
   messages = ([]);
   foreach (string fi in files)
   {
      load_messages(fi, 1 /* batch - to skip saving before the end */);
   }
   save_messages();
}

void create()
{
   ::create();
   if (!mapp(messages))
   {
      messages = ([]);
      refresh_messages();
   }
}

void clean_up()
{
   destruct();
}

/* Count the messages in the messages mapping recursively. Likely not a very reusable function since it's fitted to this
 * exact mapping. */
private
int count_msgs(mixed m)
{
   if (arrayp(m))
      return sizeof(m);
   if (mapp(m))
   {
      int c = 0;
      foreach (mixed smth in values(m))
      {
         c += count_msgs(smth);
      }
      return c;
   }
   if (stringp(m))
      return 1;
}

private
void do_action(string type, string msg)
{
   // Gun with ammo descriptions contain $o3.
   if (strsrch(msg, "$o3") != -1)
      this_body()->targetted_action("<bld>" + type + ":<res>\n" + msg, troll, "<bullet type>", "<targets weapon>",
                                    "<limb>", "<gun type>");
   else
      this_body()->targetted_action("<bld>" + type + ":<res>\n" + msg, troll, "<weapon>", "<targets weapon>", "<limb>",
                                    "<2>");
}

void test_msg(string msg)
{
   string *combat_msgs = sort_array(filter(keys(messages), ( : strlen($1) > 7 && $1[0..6] == "combat-" :)), 1);

   if (member_array(msg, mandatory_cmbt_msgs) == -1)
   {
      write("Unknown combat type msg '" + msg + "'.");
      return;
   }

   if (!troll)
      troll = new ("/domains/std/monster/troll");
   foreach (string t in combat_msgs)
   {
      if (stringp(messages[t][msg]))
         do_action(t, messages[t][msg]);
      else if (arrayp(messages[t][msg]))
      {
         foreach (string s in messages[t][msg])
            do_action(t, s);
      }
   }
}

void stat_me()
{
   int msg_cnt = count_msgs(messages);

   write("%^CYAN%^Combat message sets:%^RESET%^\n");
   write(colour_table(filter(keys(messages), ( : strsrch($1, "combat") != -1 :)), this_user()->query_screen_width()));
   write("\n\n%^CYAN%^Combat message types are:%^RESET%^\n");
   write(colour_table(combat_messages(), this_user()->query_screen_width()));
   write("\n\n%^CYAN%^Other message types:%^RESET%^\n");
   write(colour_table(filter(keys(messages), ( : strsrch($1, "combat") == -1 :)), this_user()->query_screen_width()));
   write("\n\nA total of %^YELLOW%^" + msg_cnt + "%^RESET%^ messages.");
}