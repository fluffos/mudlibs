
// glance cmd from player.c, now external. Morgoth 2/Mar/95
#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;
void setup()
{
   position = 0;
}
string query_usage()
{
   return "glance [<objeto>]";
}
string query_short_help()
{
   return "Returns short description of an object or (default) the "+
      "place where you are.";
}
int cmd (string arg, object me)
{
   object here, *ob;
   int i, dark, numhid;
   string ret;
   me = me;
   here = environment(me);
   if (!here)
   {
      notify_fail("Estas en el limbo... intentas mirar a algo "+
            "pero te resulta imposible.\n");
      return 0;
   }
   if(me->query_property("BLIND"))
   {
      notify_fail("Estas ciego, no puedes ver nada!\n");
      return 0;
   }

   dark = me->check_dark((int)here->query_light());
   if (!arg)
   {
      if (me->query_creator())
         tell_object(me,file_name(here)+"\n");
      ret = "";
      if (dark == 2) ret = "\nLa oscuridad apenas te permite ver a tu alrededor.\n";
      if (dark == 4) ret = "La luz comienza a ser molesta.\n";
		       
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
           tell_object(me,"Esta demasiado oscuro para ver algo.\n");
        break;
        case 6:
           tell_object(me,"Estas deslumbrado por la luz.\n");
        break;
      }
      return 1;
   }
   /* Glance a algo? Glance ALGO!
   if (!sscanf(arg, "a %s", arg))
   {
      notify_fail("Glance a algo!\n");
      return 0;
    }
    */
   ob = find_match (arg, ({ me, here }) );
   if ((numhid = sizeof(ob)))
   {
   	// bug de glance a <escondido> - Reportado por Xerxes
   	// corregido - Tyrael - May '02
      for (i=0;i<sizeof(ob);i++)
         // Wonderflug - Nov '95
         if(me == ob[i]) tell_object(me,"Eres tu.\n");
         else {
         	if (ob[i]->query_hidden()) {
         		if (!--numhid)
         			tell_object(me, "Hmm, no crees que "+arg+" este aqui.\n");
         	}
         	else		
      		tell_object(me,CAP(ob[i]->short(dark))+".\n");
      	}
      return 1;
   }
   notify_fail("Hmm, no crees que "+arg+" este aqui.\n");
   return 0;
}



