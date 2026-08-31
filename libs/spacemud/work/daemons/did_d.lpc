/* Do not remove the headers from this file! see /USAGE for more info. */

/* Daemon to keep track of what people have been doing.
 * -Beek
 */

#include <ports.h>
#include <security.h>

inherit M_DAEMON_DATA;
inherit M_GLOB;

mapping did = ([]);
string version;

// Current version. Includes a hack for LIMA, do not change
// this to fit your own. It has been made this way on purpose.
string curver()
{
   if (mud_name() == "LIMA")
      return lima_version()[5..];
   return version;
}

void set_version(string s)
{
   version = s;
   did[s] = ({});
   save_me();
}

private
string *help_me()
{
   return ({"No active mudlib version. Set your first version with:", "  didlog -newversion 0.0.1",
            "  didlog -help (for more)"});
}

int someone_did(string str)
{
   object *who;

   if (!is_directory(wiz_dir(this_user())))
   {
      write("Sorry, but only full wizards may use the didlog.\n");
      return 0;
   }
   if (!curver())
   {
      write(implode(help_me(), "\n"));
      return;
   }

   str = capitalize(this_user()->query_userid()) + " " + str;
   did[curver()] += ({({time(), str})});
   save_me();

   who = filter_array(users(), ( : wizardp($1) :)) - ({this_user()});
   who -= ({0});
   who->deliver_didlog_message(str);

   return 1;
}

void someone_didnt()
{
   if (!check_privilege("Mudlib:daemons"))
      error("Only Admins may remove didlogs.\n");
   if (sizeof(did))
      did[curver()] = did[curver()][0.. < 2];
   save_me();
}

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

private
nomask string *get_entries(int after, string *header, string pattern, string v)
{
   int index;
   string *output = header;
   if (!v)
      v = curver();
   index = start_index(v, after);

   if (!did[v])
      did[v] = ({});

   if (index >= sizeof(did[v]))
      return 0;

   if (!header)
      output = ({"Change Log", "**********", ""});

   if (pattern)
      pattern = translate(pattern, 1);

   for (; index < sizeof(did[v]); index++)
   {
      if (!pattern || regexp(did[v][index][1], pattern))
         output += explode(sprintf("%s: %s", ctime(did[v][index][0]), did[v][index][1]), "\n") + ({""});
   }

   return output;
}

string *dump_entries()
{
   return did[curver()];
}

string *versions()
{
   return keys(did) - ({0});
}

varargs void dump_did_info(int after, string *header, string pattern, function continuation)
{
   string *output;

   if (!curver())
   {
      output = help_me();
   }
   else
      output = get_entries(after, header, pattern, curver());

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
   string *output;

   if (!curver())
   {
      output = help_me();
   }
   else
      output = get_entries(after, header, pattern, version || curver());

   if (!output)
   {
      if (continuation)
         evaluate(continuation);
      return "No recent changes.\n";
   }

   return implode(output, "\n");
}

varargs void print_changelog_to_file(string file, int after, int show_date)
{
   int index = start_index(curver(), after);
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

private
string who_link(string name)
{
   return sprintf("<a href=http://%s:%d/cgi/who.c?=%s>%s</a>", __HOST__, PORT_HTTP, lower_case(name), name);
}

string get_changelog_for_web(string version, int dont_link_names)
{
   int index = 0;
   string output = "======\nDidlog\n======\n\n";
   int space;
   string entry;
   string name;

   for (; index < sizeof(did[version]); index++)
   {
      entry = did[version][index][1];
      space = strsrch(entry, " ");
      name = entry[0..space-1];
      output += sprintf("- **%s**: *%s* %s\n", ctime(did[version][index][0]), dont_link_names ? name : who_link(name),
                        capitalize(entry[space..]));
   }
   return output + "\n";
}

void print_weblog_to_file(string version, string fname)
{
   write_file(fname, get_changelog_for_web(version, 1), 1);
}

void create()
{
   //Do not chance or remove, this function handles data saved to /data/lima and
   //your own mudlib saved under /data/. It's fine!
   set_lima_save();
   ::create();
}