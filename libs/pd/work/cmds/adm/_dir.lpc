//      Created by Plura@Nightmare 930208

#include <std.h>

inherit DAEMON;

string *dir,
        cmd,
        from,
        to,
        old,
        new1;

int
cmd_dir(string str)
{
  if(!archp(previous_object())) return 0;
   if(str) str += " ";
   dir=0;
   from=to=old=new1=cmd=0;
   if(!str || sscanf(str,"%s %s %s %s %s",cmd,from,to,old,new1) < 2 ||
         (member_array(cmd,({"cp","du","mv","rm"})) == -1))
   {
      notify_fail("Syntax: dir <cmd> <path> [<topath> [<old> [<new>]]]\n");
      return 0;
   }
   if(from == "*") from = "";
   from = resolv_path((string)this_player()->get_path(),from);
   from += "/";
   if(!old) old = "";
   if(!new1) new1 = "";
   if(!to) to = "";
   else if(cmd != "rm")
      {
      to = resolv_path((string)this_player()->get_path(),to);
      to += "/";
   }
   else
      {
      new1 = old; old = to; to = "";
   }
   if(file_size(from) != -2)
      {
      notify_fail("dir "+cmd+": "+from+" isn't a directory.\n");
      return 0;
   }
   if(cmd != "rm" && cmd != "du" && 
         to != "" && file_size(to) != -2)
   {
      if(mkdir(to))
         write("dir "+cmd+": "+to+" created.\n");
      else
         {
         notify_fail("dir "+cmd+": failed to create "+to+". Create it and try again.\n");
         return 0;
      }
   }
   dir = get_dir(from+old);
   write("Ok to "+cmd+" "+from+old+" "+to+(new1!=""?"*":"")+new1+
      " ("+sizeof(dir)+" file"+(sizeof(dir)!=1?"s)":")")+
      "\n(y/n): ");
   input_to("dir_ok");
   return 1;
}

int
dir_ok(string str)
{
   int i;
   if(str == "y" || str == "Y")
      {
      for(i=0;i<sizeof(dir);i++)
         this_player()->command_hook(cmd+" "+from+dir[i]+" "+
            (to!=""?to+dir[i]+new1:""));
      write("Done.\n");
      return 1;
   }
   write("Ok, no harm done.\n");
   return 1;
}

int help()
{
  write( @EndText
Syntax: dir <cmd> <path> [<topath> [<old> [<new>]]]
Effect: Enacts one of the commands; cp, du, mv or rm on a whole directory.
        <topath>, <old> and <new> should be given when appropriate.
See also: dirupdate, cp, mv, du, rm
EndText
  );
  return 1;
}
