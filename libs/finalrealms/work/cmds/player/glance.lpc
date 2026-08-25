
// glance cmd from player.c, now external. Morgoth 2/Mar/95
#include <standard.h>
#include <cmd.h>
#include <commands.h>
#define DEFAULT_TIME 10
inherit CMD_BASE;
void setup()
{
   position = 0;
}
string query_usage()
{
   return "glance [at <object>]";
}
string query_short_help()
{
   return "Returns short description of an object or (default) the "+
      "place where you are.";
}
protected int cmd (string arg, object me)
{
   object here, *ob;
   int i, j, dark;
   string ret;
   me = me;
   here = environment(me);
   if (!here)
   {
      notify_fail("You are in limbo... sorry you can't look at "+
            "anything.\n");
      return 0;
   }
   if(me->query_property("BLIND"))
   {
      notify_fail("You are blind, you cannot see anything!\n");
      return 0;
   }

   dark = me->check_dark((int)here->query_light());
   if (!arg)
   {
      if (me->query_creator())
         tell_object(me,file_name(here)+"\n");
      ret = "";
      me->adjust_time_left(-LOOK_TIME);
      switch(dark)
      {
        default:
          ret = (string)here->query_contents();
        case 3:
        case 4:
          ret = (string)here->query_short_exit_string()+".\n" + ret;
        case 2:
        case 5:
          ret = (string)here->short(dark,1) + ret;
          tell_object(me,ret);
        break;
        case 1:
           tell_object(me,"It's too dark to see anything.\n");
        break;
        case 6:
           tell_object(me,"You are blinded by the light.\n");
        break;
      }
      return 1;
   }
/*
   if (!sscanf(arg, "at %s", arg))
   {
      notify_fail("Glance at something!\n");
      return 0;
    }
*/
   ob = find_match (arg, ({ me, here }) ,1);
   /* Following line added by Baldrick 1998-08-10 
    * maybe it will help the so called movement-lag
    */
   me->adjust_time_left(-DEFAULT_TIME);
   if (sizeof(ob))
     {
       /* Fix to always place me first, even if hidden - Bishop */
       j = member_array(me, ob);
       if (j!=-1)
	 {
	   tell_object(me,"Yourself.\n");
           /* Fixed Bishop's fix. Flode - 070698
	   delete(ob,j,1);
            */
           ob = delete(ob,j,1);
	 }
       for (i=0;i<sizeof(ob);i++)
         // Wonderflug - Nov '95
         if(me == ob[i]) tell_object(me,"Yourself.\n");
         else
      if(!interactive(ob[i]))
        tell_object(me,ob[i]->short(dark)+".\n");
      else
        tell_object(me,ob[i]->glance_long()+"\n");
      return 1;
   }
   notify_fail("You do not think that the "+arg+" is here.\n");
   return 0;
}
