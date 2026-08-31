// seeker 06/02/2000
//  Fixed by Whit - 12:02:18 AM 01/04/02
// simplified by Nulvect 2006-08-29
//   don't use a big mapping here anymore,
//   each spell defines its own type with
//   a string type() { return "attack"; } function
#include <std.h>
#include <daemons.h>
inherit DAEMON;
string *directories = 
({
  "/cmds/skills/",
});

string query_spell_class(string what) {
  object ob;
  string file, type;
  if (file_size(what) > 0) file = what;
  else
    foreach (string dir in directories)
      if (file_size(dir+"_"+what+".c") > 0) {
        file = dir+"_"+what+".c";
        break;
      }
  if (!file) return "";
  if (!objectp(ob=load_object(file))) return "";
  if (sizeof(type=ob->type()))
    return type;

  return "";
}

int cmd_spells(string str)
{
    string *list;
    mapping spells = ([
      "attack" : ({}),
      "defense" : ({}),
      "faith" : ({}),
      "healing" : ({}),
      "conjuring" : ({}),
      "other" : ({})
    ]);
    string tmp, type, name;
    int i, a;

    foreach (string dir in directories) {

      list = get_dir(dir+"_*.c");
      if (!(sizeof(list))) continue;

      foreach (string file in list) {
        tmp = dir+file;
        if (load_object(tmp)->spell()) {
          sscanf(file, "_%s.c", name);
          type = query_spell_class(tmp);
          if (!type || member_array(type,keys(spells)) == -1)
            type = "other";
          spells[type] += ({ name });
        }
      }

    }
    
    foreach (string t in keys(spells))
      if (!sizeof(spells[t]))
        spells[t] = ({ "(none)" });

    message("no_wrap", "%^BLUE%^+=+=%^BOLD%^(%^RESET%^ Spells %^BLUE%^%^BOLD%^)"
        "%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+="
        "+=+=+=+=\n",
      this_player());
    message("info","%^RED%^%^BOLD%^Attack:%^RESET%^", this_player());
    message("no_wrap","  "+implode(spells["attack"], ", ")+"\n", this_player());
    message("info","%^MAGENTA%^%^BOLD%^Defense:%^RESET%^", this_player());
    message("no_wrap","  "+implode(spells["defense"], ", ")+"\n", this_player());
    message("info","%^BLUE%^%^BOLD%^Faith:%^RESET%^", this_player());
    message("no_wrap","  "+implode(spells["faith"], ", ")+"\n", this_player());
    message("info","%^GREEN%^%^BOLD%^Healing:%^RESET%^", this_player());
    message("no_wrap","  "+implode(spells["healing"], ", ")+"\n", this_player());
    message("info","%^YELLOW%^%^BOLD%^Conjuring:%^RESET%^", this_player());
    message("no_wrap","  "+implode(spells["conjuring"], ", ")+"\n", this_player());
    message("info","%^CYAN%^%^BOLD%^Other:%^RESET%^", this_player());
    message("no_wrap","  "+implode(spells["other"], ", ")+"\n", this_player());

    return 1;
}

void help() {
  write( @EndText
Syntax: spells
Lists spells you know.
See also: abilities, songs, dances
EndText
  );

}

