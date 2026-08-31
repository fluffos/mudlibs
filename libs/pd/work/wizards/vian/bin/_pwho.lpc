///bin/dev/_people.c
//from the Nightmare mudlib
//created by Cynosure@Nightmare
//      check_invis() added by Plura 930201
//      sort_by_name() added by Plura 930201
//     parameters mort, newbie, wiz, arch, dead added by Plura 930204
//      and hmort aswell.
//      paramter -i -r  by seeker 08/2002
//     list partying added by Vian 12/2010
#include <writef.h>
#include <daemons.h>
#include <std.h>
#define DIV "---------------------------------------"
#define DIVIDER DIV+DIV
#define POSITIONS ({ "player", "high mortal", "immortal", "creator", "elder", \
                      "mentor", "wizard", "Realms Avatar", "MudMom Avatar", \
                      "Archon Avatar" })
inherit DAEMON;
int cmd_pwho(string arg)
{   object *list;
   string line, zone_name;
   string *argv;
   int i, do_more, time_zone, level;
    mixed xyzpdq;
   
   line = DIVIDER + "\n";
   //list = filter_array(users(), "check_invis", this_object());
  // this is imm only anyway, I think we can learn not to bother each other :P
  list = users();
   if(arg)
      {
      if(arg && !sizeof((argv=explode(arg," "))))
         argv = ({ arg });
      if (member_array("-i",argv)!=-1) level=1; else
      if (member_array("-r",argv)!=-1) level=2;
      if(member_array("m",argv)!=-1||member_array("more",argv)!=-1)
         do_more = 1;
      if(member_array("w",argv)!=-1||member_array("wiz",argv)!=-1)
         list = filter_array(list, "check_wiz", this_object());
      if(member_array("arch",argv)!=-1)
         list = filter_array(list, "check_arch", this_object());
      if(member_array("mort",argv)!=-1)
         list = filter_array(list, "check_mort", this_object());
      if(member_array("hmort",argv)!=-1)
         list = filter_array(list, "check_hmort", this_object());
      if(member_array("newbie",argv)!=-1)
         list = filter_array(list, "check_newbie", this_object());
      if(member_array("dead",argv)!=-1)
         list = filter_array(list, "check_dead", this_object());
      if(member_array("a",argv)!=-1||member_array("alpha",argv)!=-1)
         list = sort_array(list, "sort_by_name", this_object());
      else
         list = sort_array(list, "sort_by_level", this_object());
   }
   else
      list = sort_array(list, "sort_by_level", this_object());
   if(!sizeof(list))
   {
      message("system", "No such players.  Type <help people> for help.",
        this_player());
      return 1;
   }
   
   // Time zone code, by Docz
   zone_name = (string)this_player()->getenv("TZONE");
   time_zone = (int)TIME_D->query_tzone(zone_name);
   if (!zone_name)
      line += "                  Mud time is "+ctime(time())+"\n";
   else
      line += "                "+zone_name+" time is "+ctime(time_zone)+"\n";
   
   line += DIVIDER + "\n";
   
   for (i=0; i<sizeof(list); i++)
   {   string field;
      mixed val;
      
      if( !list[i]->query_name() ) continue;
      xyzpdq = (int)list[i]->query_age();
      if(xyzpdq>86400) field = (xyzpdq/86400 + " D");
      else if(xyzpdq>3600) field = (xyzpdq/3600) + " h";
      else field = (xyzpdq/60) + " m";
      line += sprintf("%-7s", field);
      if(list[i]->query_invis()) field =
"("+capitalize((string)list[i]->query_name())+")";
      else field = (string)list[i]->query_name();
      if(field) field = capitalize(field);
      if (in_edit(list[i]) || in_input(list[i]))
         field = "*" + field;
      line += sprintf("%-18s", field);
      switch(level) {
        case 1: field = (string)query_ip_number(list[i]); break;
        case 2: field = (string)file_name(environment(list[i]));break;
        default: field = (string) list[i] -> query_ip();
}
      if (!field) field = "-";
      line += sprintf("%-17s", field[0..24]);
      xyzpdq = (int) list[i] -> query_level();
      field = ""+xyzpdq+"";
      if (!field) field = "-";
      line += sprintf("%-5s", field);
      val = query_idle(list[i]);
      if ( val <= 0 ) field = " ";
      else if( val >= 3600 ) field = val/3600 + "h";
      else if( val >= 60 ) field = val/60 + "m";
      else field = " ";
      line += sprintf("%-5s", field);
/*      val = environment(list[i]);
      if (!val) field = "(null)";
      else {
         field = file_name(val);
         if(sscanf(field, "/wizards/%s", str2) == 1) field = "~"+str2;
         if(sscanf(field, "/d/%s", str2) == 1) field = "^"+str2;
        }
      line += sprintf("%-28s", field[0..24]);  */
      xyzpdq = (string) list[i] -> query_guild();
      field = ""+xyzpdq+"";
      if ( xyzpdq = 0 ) field = "-";
      if (!field) field = "-";
      line += sprintf("%-11s", field);
      xyzpdq = (string) list[i] -> query_party();
      field = ""+xyzpdq+"";
      xyzpdq = (string) list[i]->query_recent_outlaw();
      if (!xyzpdq) xyzpdq = "none";
      field = xyzpdq[0..1]+":" + field;
      if ( xyzpdq = 0 ) field = "-";
      if (!field) field = "-";
      line += sprintf("%-15s", field);
      line += "\n";
   }
   line += DIVIDER + "\n";
   if(do_more)
      this_player()->more(explode(line, "\n"));
   else
    message("Nsystem", line, this_player());
   return 1;
}
int
sort_by_level(object u1, object u2)
{
   int level1, level2;
   string name1, name2;
   
   level1 = (int)u1->query_level();
   level2 = (int)u2->query_level();
   if(wizardp(u1)) level1 += 100;
   if(wizardp(u2)) level2 += 100;
   if (level1 == level2) {
      name1 = (string)u1->query_name();
      name2 = (string)u2->query_name();
      if (name1 == name2)
         return 0;
      if (name1 < name2)
         return -1;
      else
         return 1;
   }
   if (level1 > level2)
      return -1;
   else
      return 1;
}
int
sort_by_name(object u1,object u2)
{
   string name1, name2;
   name1 = (string)u1->query_name();
   name2 = (string)u2->query_name();
   if(!name1 || !name2)
      return -1;
   if (name1 == name2)
      return 0;
   if (name1 < name2)
      return -1;
   else
      return 1;
}
// Levels redone by Valodin, July 12, 1993
int
get_pos(object ob)
{
  string *pos;
  int ret;
  pos = POSITIONS;
  ret = member_array(ob->query_position(), pos);
  if (ret == -1)
    // better error handling is needed, but for now...
    return 0;
  return ret;
}
int
check_invis(object ob)
{
   string *pos;
   pos = POSITIONS;
   if((int)ob->query_invis() && get_pos(this_player()) < get_pos(ob) &&
wizardp(ob))
     return 0;
   return 1;
}
int
check_wiz(object ob)
{
   return wizardp(ob);
}
int
check_arch(object ob)
{
   string p;
     return (wizardp(ob) && ((p = (string)ob->query_position()) == "Archon
Avatar" ||
                           p == "Realms Avatar" || p == "MudMom Avatar"));
}
int
check_hmort(object ob)
{
   return high_mortalp(ob);
}
int
check_mort(object ob)
{
   return (ob->is_player() && (string)ob->query_position() == "player");
}
int
check_newbie(object ob)
{
   return (ob->is_player() && ob->query_level() < 6 && 
           (string)ob->query_position() == "player");
}
int
check_dead(object ob)
{
   return (int)ob->query_ghost();
}
void help() {
    message("help",
      "Syntax: <people (more) (alpha) (a) (arch) (wiz) (hmort) (mort)>\n\n"
      "Gives a special listing of people online.\n\n"
      "See also: finger, users, who", this_player()
    );
}
