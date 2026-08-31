/* Do not remove the headers from this file! see /USAGE for more info. */

/* Daemon to keep track of what people have been doing.
 * -Beek
 */

#include <ports.h>
#include <security.h>

inherit M_GLOB;
inherit M_ACCESS;

mapping did;

private
nomask int start_index(string version, int after)
{
   int index = sizeof(did[version]);
   if (after > time())
      return 0;

   while (index > 0 && did[version][index - 1][0] > after)
      index--;

   return index;
}

// private
nomask string *get_entries(int after, string *header, string pattern, string version)
{
   int index = start_index(version, after);
   string *output = header;

   if (!did[version])
      did[version] = ({});

   if (index >= sizeof(did[version]))
      return 0;

   if (!header)
      output = ({"Change Log", "**********", ""});

   if (pattern)
      pattern = translate(pattern, 1);

   for (; index < sizeof(did[version]); index++)
   {
      if (!pattern || regexp(did[version][index][1], pattern))
         output += explode(sprintf("%s: %s", ctime(did[version][index][0]), did[version][index][1]), "\n") + ({""});
   }

   return output;
}

string *dump_entries(string version)
{
   return did[version];
}

string *versions()
{
   return keys(did) - ({0});
}

varargs void dump_did_info(int after, string *header, string pattern, function continuation, string version)
{
   string *output = get_entries(after, header, pattern, version);

   if (!output)
   {
      if (continuation)
         evaluate(continuation);
   }
   else
   {
      more(output, 0, continuation, NO_ANSI);
   }
}

varargs string get_did_info(int after, string *header, string pattern, function continuation, string version)
{
   string *output = get_entries(after, header, pattern, version);

   if (!output)
   {
      if (continuation)
         evaluate(continuation);
      return "No recent changes.\n";
   }

   return implode(output, "\n");
}

varargs void print_changelog_to_file(string file, int after, int show_date, string version)
{
   int index = start_index(version, after);
   string output = "";

   if (show_date)
   {
      for (; index < sizeof(did); index++)
      {
         output += sprintf("%s: %s\n", ctime(did[index][0]), did[index][1]) + "\n";
      }
   }
   else
   {
      for (; index < sizeof(did); index++)
      {
         output += sprintf("%s\n", did[index][1]) + "\n";
      }
   }
   write_file(file, output);
}

nomask string create_file_name()
{
   return "/data/lima/daemons/did";
}

//: FUNCTION restore_me
// Restore the data from the save file.  Automatically called by create().
protected
nomask void restore_me()
{
   string fn = create_file_name();
   if (unguarded(1, ( : file_size, fn + __SAVE_EXTENSION__:)) > 0)
      unguarded(1, ( : restore_object, fn, 1 :));
}

void save_me()
{
   write("LIMA_D does not save.");
}

create()
{
   set_privilege(1);
   restore_me();
}
