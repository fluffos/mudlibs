/* Debug-Room
 * Hier werden alle Debugmeldungen angezeigt.
 * Samtpfote@Tamedhon
 *
 * ... naja und auch an mich gesendet. 
 */

#include <properties.h>
#include <ansi.h>
#include <config.h>
#include <wizlevels.h>

#define DEBUGMAGIER		"samtpfote"

inherit "/std/room";

int		tm_debug_on;

void debug_message(object sender, string msg)
{
  object        dm;

  tell_room(this_object(), 
	break_string(msg, 79, "{ "+efun::explode(object_name(sender),"#")[0]+" } "));
	
  if(tm_debug_on &&
     !present(DEBUGMAGIER, this_object()) &&
	 find_player(DEBUGMAGIER))
  {
      dm=find_player(DEBUGMAGIER);
      if(dm)
      {
        if(dm->QueryProp(P_TTY) != "dumb")
        { tell_object(dm, ANSI_BOLD); }
	tell_object(dm,
	  break_string(msg, 79, "{ "+efun::explode(object_name(sender),"#")[0]+" } "));
        if(dm->QueryProp(P_TTY) != "dumb")
        { tell_object(dm, ANSI_NORMAL); }
      }
  }	 
}

string det_hebel()
{
  return
	break_string(
	"Mit diesen Hebel kann man die tms an den Debugmagier ein- und "+
	"ausschalten. Zur Zeit werden die Meldungen "+
	(tm_debug_on?"":"NICHT ")+
	"mitgeteilt. Er kann einfach umgelegt ('umlegen') werden.");
}

int cmd_umlegen(string str)
{
  if(!IS_QUESTWIZ(this_player()))
  {
	notify_fail("Nee, dazu bist Du zu schwach.\n");
	return 0;
  }

  tm_debug_on= !tm_debug_on;  
  write("Ok, Hebel wurde umgelegt.\n");
  return 1;
}

void create()
{
  ::create();
  
  SetProp(P_LIGHT, 1);
  SetProp(P_INT_SHORT, "Debugraum von "+MUDNAME);
  SetProp(P_INT_LONG, break_string(
	"Das ist der offizielle Raum von "+MUDNAME+", wo alle "+
	"Debugmeldungen eintreffen. Er ist bis auf einen großen "+
	"Hebel leer."));
	
  AddDetail("hebel", #'det_hebel);
  AddCmd("umlegen", "cmd_umlegen");
  
  tm_debug_on=1;
}

