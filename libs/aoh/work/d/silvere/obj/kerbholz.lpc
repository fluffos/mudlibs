// This is a little stick, where a player/wizard can engrave
// little notches as signs of his kills
// created:          Sonic [07-Jun-1997]
// last changed:     Sonic [08-Jun-1997]

#include <properties.h>
#include <combat.h>
#include <macros.h>
#include <moving.h>

inherit "/std/thing";

#define KERBHOLZ_MARK      "/d/silvere/obj/kerbholz_mark"

mixed dead_name, dead_number;

mixed AddKill(string name)
{
   int a;
   string save_file;

   if(!name) return 0;

   save_file="/save/obj/kerbholz/"+(RNAME(TP))[0..0]+"/"+RNAME(TP);
   a=member(dead_name, lower_case(name));
   if(a!=-1)
   {
      write("One of the notches on your stick glows for a moment.\n");
      dead_number[a]+=1;
      save_object(save_file);
      return ({ dead_name, dead_number});
   }
   write("A new notch appears on the stick.\n");
   dead_name+=({ lower_case(name) });
   dead_number+=({1});
   save_object(save_file);
   return ({ dead_name, dead_number});
}

int point_stick(string str)
{
   string what, target;

   notify_fail("Point what at whom?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(sscanf(lower_case(str),"%s at %s",what, target)==2)
   {
      if(what=="kerbholz")
      {
         object who;

         if(target==RNAME(TP))
         {
            write("Are you mad? Or do you want to commit suicide?\n");
            show(CAP(RNAME(TP))+" waves the kerbholz around.\n");
            return 1;
         }
         if(who=present(target,environment(TP)))
         {
            object item;

            if(item=present("kerbholzmark",who))
            {
               if(({string})item->QueryOwner()==RNAME(TP))
               {
                  write("You already marked the "+({string})who->Query(P_RACE)+".\n");
                  return 1;
               }
            }
            write("You point the item at "+CAP(target)+" and a blue tattoo appears on "+HISHER(who)+" forehead.\n");
            show(CAP(NAME(TP))+" points "+HISHER(TP)+" kerbholz at "+CAP(NAME(who))+". A blue tattoo appears on "+HISHER(who)+" forehead.\n", ({who}) );
            tell_object(who,CAP(NAME(TP))+" points "+HISHER(TP)+" kerbholz at you. Suddenly you have a cold feeling.\n");
            item=clone_object(KERBHOLZ_MARK);
            item->move(environment(who),M_SILENT);
            item->SetOwner(RNAME(TP),who);
            return 1;
         }
         write(CAP(target)+" is not here with you.\n");
         return 1;
      }
   }
}

string print_list()
{
   int a,b;
   mixed desc;

   if(sizeof(dead_name)==0)
      return "There are no notches on the stick. How about you kill someone?\n";
   desc="You look at the stick and suddenly you see a list of names.\n";
   b=0;
   for(a=0;a<sizeof(dead_name); a++)
   {
      desc+=sprintf("%12s (%5d confirmed kills.)",CAP(dead_name[a]),dead_number[a]);
      if(b==1) desc+="\n"; else desc+="   ";
      if(b==0) b++; else b=0;
      if(a==sizeof(dead_name)-1 && b==1) desc+="\n";
   }
   return desc;

}

int show_list(string str)
{
   string source, target;

   notify_fail("Show what to whom?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(sscanf(lower_case(str),"%s to %s",source, target)==2)
   {
      if(source=="stick" || source=="kerbholz")
      {
         object who;

         if(who=present(target,environment(TP)))
         {
            write("You show your kerbholz to "+CAP(target)+".\n");
            show(CAP(NAME(TP))+" shows "+HISHER(TP)+" kerbholz proudly to "+CAP(target)+".\n", ({ who }) );
            tell_object(who,CAP(NAME(TP))+" shows you proudly "+HISHER(TP)+" kerbholz.\n");
            tell_object(who,print_list());
            return 1;
         }
         notify_fail(CAP(target)+" is not here with you.\n",NOTIFY_ILL_ARG);
         return 0;
      }
   }
}

int check_list(string str)
{
   notify_fail("Check what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"kerbholz")!=-1)
   {
      show(CAP(NAME(TP))+" checks the notches on "+HISHER(TP)+" kerbholz.\n");
      write(print_list());
      return 1;
   }
}

varargs mixed QueryLong(string what)
{
   string desc;

   desc=
"This is a little, wooden stick with a smooth surface. There is "
"lots of free space for notches, where you can engrave marks for "
"your killed enemies. ";
   switch(sizeof(dead_name))
   {
      case 0: desc+="The surface of the stick is untouched.\n"; break;
      case 1: desc+="There is a single notch on the stick.\n"; break;
      case 2..10: desc+="There are some notches on the stick.\n"; break;
      default: desc+="Lots of notches are carved into the stick.\n"; break;
   }
   return desc;
}

void create()
{
   string restore_name;

   ::create();
   seteuid(getuid(TO));
   Set(P_SHORT,CAP(RNAME(TP))+"'s kerbholz");
   Set(P_HELP_MSG,
"If you want to keep track of killed enemies, this little stick will "
"be very valuable to you. There is lots of free space on it to engrave "
"notches in it. You can also show the record of your killed enemies "
"to other people to show off a little bit.\n"
"The usage is very simple. Point the stick at the being, you want to "
"see dead and if you manage to kill it, a notch will appear on the "
"stick. For example:\n\n"
">wizmode on\n"
">point kerbholz at superj\n"
">kill superj\n\n"
"Now, if you manage to kill Superj, you should examine the kerbholz. "
"This list of available commands may help you a bit more:\n\n"
"- point kerbholz at <target>: show the kerbholz who you want to kill.\n"
"- check kerbholz: This shows you the record of notches on the stick.\n"
"- show kerbholz to <player>: Shows your dead enemies to a player.\n");
   Set(P_IDS, ({"kerbholz","stick"}) );
   Set(P_ADS, ({"little","wooden"}) );
   Set(P_NODROP,"The kerbholz refuses to leave you.\n");
   Set(P_NOGIVE,"The kerbholz refuses to leave you.\n");
   Set(P_AUTOOBJECT,1);

   dead_name=({ });
   dead_number=({ });

   restore_name="/save/obj/kerbholz/"+(RNAME(TP))[0..0]+"/"+RNAME(TP);
   if(file_size(restore_name+".o")>=0) restore_object(restore_name);
}

void init()
{
   ::init();
   add_action("check_list", "check");
   add_action("show_list",  "show");
   add_action("point_stick","point");
}
