/* Do not remove the headers from this file! see /USAGE for more info. */

inherit ADMTOOL_BASE;

private
mapping ansi_colours;

nomask string module_name()
{
   return "colour";
}

nomask string module_key()
{
   return "c";
}

nomask string module_user()
{
   return "[Mudlib:daemons]";
}

nomask mixed module_priv()
{
   return "Mudlib:daemons";
}

private
void receive_remove_colour(string key)
{
   ANSI_D->remove_default_colour(key);
   write("Done.\n");
}

private
int allowed_colour(string s)
{
   if (!ansi_colours)
   {
      mapping tmp = ANSI_D->query_default_translations();
      string *illegal =
          ({"endterm", "clearline", "initterm", "reset", "new reset", "restore", "flash", "save", "home"});
      ansi_colours = ([]);
      foreach (string key, string value in tmp)
      {
         string new_key = lower_case(replace_string(replace_string(key, "B_", "bold,"), "_", " "));
         if (member_array(new_key, illegal) != -1)
            continue;
         ansi_colours[new_key] = key;
      }
   }

   if (strlen(s) == 3 && to_int(s) > 0 && to_int(s) < 256)
      return 1;

   if (member_array(s, keys(ansi_colours)) != -1)
      return 1;

   return 0;
}

private
void receive_add_colour(string key, string value, int restricted)
{
   if (!allowed_colour(value))
   {
      write("Illegal colour '" + value + ".\n" + "Valid ANSI colours are: " + implode(keys(ansi_colours), "\n  ") +
            "\n" + "Valid XTERM colours are: <<res>001> to <<res>255>.");
      return;
   }
   ANSI_D->add_default_colour(key, value, restricted);
   XTERM256_D->update_ansi();
   if (strlen(value) == 3 && to_int(value) > 0 && to_int(value) < 256)
      write("Done. " + upper_case(key) + " set to an XTERM <" + value + ">colour.<res>\n");
   else
      write("Done. " + upper_case(key) + " set to %^" + upper_case(replace_string(upper_case(value), ",", "%^%^")) +
            "%^" + value + "<res>\n");
}

// Returns lower_cased if unrestricted
string restrict_modify(string val)
{
   if (member_array(val, ANSI_D->query_restrictions()) < 0)
      return lower_case(val);
   return val;
}

private
void list_colours()
{
   string *restrict = ANSI_D->query_restrictions();
   mixed tmp;
   mapping colours = ANSI_D->query_translations()[0];
   tmp = ANSI_D->defaults();
   tmp = sort_array(keys(tmp), 1);
   tmp = map(tmp, ( : restrict_modify:));
   write("Default colours (wiz-only in CAPs)\n");
   printf("<bld>%-30.30s   %-20.20s   %-30.30s<res>", "Colour name", "Selected", "Colour example");
   write("------------------------------------------------------------------------------------");
   foreach (string t in tmp)
   {
      string col = colours[upper_case(t)];
      printf("%-30.30s   %-20.20s   %s%-30.30s<res>", t, col,
             strlen(col) == 3 && to_int(col) ? "<" + col + ">"
                                             : ("%^" + replace_string(upper_case(col), ",", "%^%^") + "%^"),
             t);
   }
}

private
void restrict(string key)
{
   ANSI_D->add_restriction(key);
}

private
void unrestrict(string key)
{
   ANSI_D->remove_restriction(key);
}

nomask class command_info *module_commands()
{
   return ({new (class command_info, key
                 : "l", desc
                 : "list default colours", action
                 : (
                     : list_colours:)),
            new (class command_info, key
                 : "a", proto
                 : "[colour] [value]", desc
                 : "add default colour (only ANSI accepted)", args
                 : ({"Colour code? ", "Value? "}), action
                 : (
                     : receive_add_colour:)),
            new (class command_info, key
                 : "r", proto
                 : "[colour]", desc
                 : "remove default colour", args
                 : ({"Remove which colour? "}), action
                 : (
                     : receive_remove_colour:)),
            new (class command_info, key
                 : "w", proto
                 : "[colour]", desc
                 : "make colour wiz-only", args
                 : ({"Make which colour wiz-only? "}), action
                 : (
                     : restrict:)),
            new (class command_info, key
                 : "p", proto
                 : "[colour]", desc
                 : "make colour player-usable", args
                 : ({"Make which colour player-usable? "}), action
                 : (
                     : unrestrict:))});
}
