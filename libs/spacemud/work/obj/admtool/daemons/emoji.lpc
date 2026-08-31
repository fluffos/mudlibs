/* Do not remove the headers from this file! see /USAGE for more info. */

inherit ADMTOOL_BASE;

nomask string module_name()
{
   return "emoji";
}

nomask string module_key()
{
   return "e";
}

private
nomask void list_emojis()
{
   mapping emojis;
   string out;

   emojis = EMOJI_D->get_emoji_data();

   if (!sizeof(keys(emojis)))
   {
      write("There are no emojis.\n");
   }
   else
   {
      out = sprintf("%-30s %5|s %-10s", "Emoji", "UTF8/16", "Replacement\n");
      foreach (string key, string * arr in emojis)
      {
         out += sprintf("%-30s %-5s %-10s\n", key, arr[0], arr[1]);
      }
      this_user()->do_receive(out, NO_ANSI);
   }
}

private
nomask void show_emoji_data(string emoji)
{
   string *members;

   emoji = lower_case(emoji);
   members = sort_array(EMOJI_D->get_emoji_data()[emoji], 1);
   if (!members)
   {
      printf("There is no emoji named '%s'.\n", emoji);
   }
   else
   {
      printf("emoji %s:\n", emoji);

      switch (sizeof(members))
      {
      case 0:
         write("Data: (none)\n");
         break;

      case 1:
         printf("Data:  %s\n", members[0]);
         break;

      default:
         printf("Data: %s   Replacement for: %s \n", members[0], members[1]);
         break;
      }
   }
}

private
nomask void create_emoji(string emoji)
{
   emoji = lower_case(emoji);

   EMOJI_D->add_emoji(emoji);

   printf("emoji %s created.\n", emoji);
}

private
nomask void delete_emoji(string emoji)
{
   emoji = lower_case(emoji);

   EMOJI_D->remove_emoji(emoji);

   printf("emoji %s deleted.\n", emoji);
}

private
nomask void show_users_emojis(string user)
{
   mapping emojis;

   user = lower_case(user);
   emojis = filter(EMOJI_D->get_emoji_data(), ( : member_array($(user), $2) != -1 :));

   if (!sizeof(emojis))
      printf("%s doesn't belong to any emojis.\n", user);
   else
      printf("%s belongs to: %s.\n", user, implode(sort_array(keys(emojis), 1), ", "));
}

private
nomask void add_data_to_emoji2(string emoji, string utfchar, string replacement)
{
   emoji = lower_case(emoji);
   replacement = replace_string(replacement, "\\:", ":");

   if (!EMOJI_D->get_emoji_data()[emoji])
   {
      create_emoji(emoji);
   }

   EMOJI_D->add_emoji_data(emoji, utfchar, replacement);
   if (replacement)
      printf("Added %s to emoji %s with replacement '%s'.\n", utfchar, emoji, replacement);
   else
      printf("Added %s to emoji %s.\n", utfchar, emoji);
}

private
nomask void add_data_to_emoji(string emoji)
{
   input_two_args("UTF8 Char? ", "Replacement (default empty)? ", ( : add_data_to_emoji2, emoji:));
}

private
nomask void remove_user_from_emoji(string user)
{
   user = lower_case(user);

   EMOJI_D->remove_emoji(user);

   printf("Removed emoji %s.\n", user);
}

nomask class command_info *module_commands()
{
   return ({new (class command_info, key
                 : "l", desc
                 : "list emojis", action
                 : (
                     : list_emojis:)),
            new (class command_info, key
                 : "s", proto
                 : "[emoji]", desc
                 : "show an emoji's data", args
                 : ({"Show data for which emoji? "}), action
                 : (
                     : show_emoji_data:)),
            new (class command_info, key
                 : "a", proto
                 : "[emoji]", desc
                 : "add emoji (or overwrite)", who
                 : "[Mudlib:]", args
                 : ({"Add to which emoji? "}), action
                 : (
                     : add_data_to_emoji:)),
            new (class command_info, key
                 : "d", proto
                 : "[emoji]", desc
                 : "delete a emoji", args
                 : ({"Delete which emoji? "}), who
                 : "[Mudlib:]", action
                 : (
                     : delete_emoji:)),
            new (class command_info, key
                 : "r", proto
                 : "[emoji]", desc
                 : "remove data from a emoji", who
                 : "[Mudlib:]", args
                 : ({"Remove from which emoji? "}), action
                 : (
                     : remove_user_from_emoji:))});
}
