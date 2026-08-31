/* Do not remove the headers from this file! see /USAGE for more info. */

inherit ADMTOOL_BASE;

nomask string module_name()
{
   return "messages";
}

nomask string module_key()
{
   return "M";
}

nomask string module_user()
{
   return "[Mudlib:daemons]";
}

nomask string module_priv()
{
   return "Mudlib:daemons";
}

nomask void stat_messages()
{
   MESSAGES_D->stat_me();
}

nomask void refresh_messages()
{
   MESSAGES_D->refresh_messages();
}

nomask void test_message(string s)
{
   MESSAGES_D->test_msg(s);
}

nomask class command_info *module_commands()
{
   return ({
       new (class command_info, key
            : "l", desc
            : "list message set and types", action
            : (
                : stat_messages:)),
       new (class command_info, key
            : "r", desc
            : "refresh messages", action
            : (
                : refresh_messages:)),
       new (class command_info, key
            : "t", proto
            : "[msg type]", desc
            : "test message type", args
            : ({"Which msg?\n" + format_list(MESSAGES_D->combat_messages())}), action
            : (
                : test_message:)),

   });
}
