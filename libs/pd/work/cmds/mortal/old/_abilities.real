// modified by stormbringer
// seeker 06/02/2000
// Fixed by Whit 01:03:12 AM 01/04/02
// simplified by Nulvect 2006-08-29
//   don't use a big mapping here anymore,
//   each ability defines its own type with
//   a string type() { return "attack"; } function
#include <std.h>
#include <daemons.h>
inherit DAEMON;

string *directories = 
({
  "/cmds/skills/",
  "/cmds/hm/" 
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

int cmd_abilities(string str)
{
    string *list;
    mapping abils = ([
      "attack" : ({}),
      "defense" : ({}),
      "weapon" : ({}),
      "deception" : ({}),
      "other" : ({})
    ]);
    string tmp, type, name;
    int i, a;

    foreach (string dir in directories) {

      list = get_dir(dir+"_*.c");
      if (!(sizeof(list))) continue;

      foreach (string file in list) {
        tmp = dir+file;
        if (load_object(tmp)->abil()) {
          sscanf(file, "_%s.c", name);
          type = query_spell_class(tmp);
          if (!type || member_array(type,keys(abils)) == -1)
            type = "other";
          abils[type] += ({ name });
        }
      }

    }
    
    foreach (string t in keys(abils))
      if (!sizeof(abils[t]))
        abils[t] = ({ "(none)" });

    message("no_wrap", "%^BLUE%^+=+=%^BOLD%^(%^RESET%^ Abilities %^BLUE%^%^BOLD%^)"
      "%^RESET%^%^BLUE%^+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n",
      this_player());
    message("info","%^RED%^%^BOLD%^[Attack]%^RESET%^", this_player());
    message("no_wrap","  "+implode(abils["attack"], ", ")+"\n", this_player());
    message("info","%^MAGENTA%^%^BOLD%^[Defense]%^RESET%^", this_player());
    message("no_wrap","  "+implode(abils["defense"], ", ")+"\n", this_player());
    message("info","%^BLUE%^%^BOLD%^[Weapon]%^RESET%^", this_player());
    message("no_wrap","  "+implode(abils["weapon"], ", ")+"\n", this_player());
    message("info","%^GREEN%^%^BOLD%^[Deception]%^RESET%^", this_player());
    message("no_wrap","  "+implode(abils["deception"], ", ")+"\n", this_player());
    message("info","%^CYAN%^%^BOLD%^[Other]%^RESET%^", this_player());
    message("no_wrap","  "+implode(abils["other"], ", ")+"\n", this_player());

    return 1;
}

void help()
{
    write( @EndText
Syntax: abilities
Gives a list of the abilities your character has.
See also: spells, songs, dances
EndText
    );
}

