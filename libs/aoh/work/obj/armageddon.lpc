/*************************************************************************/
/* This is the NPC-Frontend to the shutdown daemon.
 * It implements the 'transport to shop' facility in case of shutdowns.
 * TODO: Also add some noise message here.
 */

#include <properties.h>   /* for the property names */
#include <living.h>
#include <attributes.h>   /* Physical attributes of livings*/
#include <combat.h>       /* For weapons and armours */
#include <moving.h>
#include <stdrooms.h>

inherit "/std/npc";

#define WHERE_TO_GO STARTROOM

int rescue; /* Has the 'rescue' facility been activated? */

/*-------------------------------------------------------------------------
** Initialize us.
*/

void create () {
  object ob;

  while (ob = find_living("armageddon")) {
    ob->remove(); 
    if (ob) destruct(ob);
  }

  if (::create())  return;

  SetName ("Armageddon");
  SetShort("Armageddon the god of world destruction");
  SetLong ("He looks like he enjoys to prepare to wipe out all reality.\n");

  SetRace ("god");
  SetGender (1);
  Set(P_WEIGHT, 100000);
  Set(P_MAX_HP, 1000);    
  Set(P_HP, 1000);
  Set(P_MAX_SP, 1000);
  Set(P_SP, 1000);
  SetAttribute (A_STR, 20);
  SetAttribute (A_DEX, 20);
  SetAttribute (A_CON, 20);
  SetAttribute (A_INT, 20);
  Set(P_ALIGN, 2001);
  Set(P_HANDS, ({
    ({ "right hand", 0, 100 }),
    ({ "left hand", 0, 100 })
    })
           );
  Set(P_MMSGIN, "arrives in a puff of smoke");
  Set(P_MSGIN, "arrives in a puff of smoke");

  rescue = 0;
  move(WHERE_TO_GO, M_GO);
}

/*-------------------------------------------------------------------------
** We can't die of combat!
*/

varargs int DoDamage () { return 0; }
varargs void Die() { }
string QueryRealName() { return "armageddon"; }

/*-------------------------------------------------------------------------*/
void move_to_loc() {
  if (!environment())
    return;
  if (object_name(environment()) == WHERE_TO_GO)
    return;
  tell_room(environment(), 
"Armageddon looks up and says: Folks, it was nice to be here with you, but\n"
"  now duty calls - I have a world to destruct.\n"
	   );
  catch(move(WHERE_TO_GO, M_TELEPORT));
}

void Shut() 
{
  SetLong("He is firmly concentrated on counting and prepares the\n" +
          "destruction of the world!\n");
}

void TransportOk()
{
  rescue = 1;
}

/*-------------------------------------------------------------------------*/
void catch_tell(string str) {
  string who, what, msg;
  int    tleft, seconds;
  object ob, shut;

  if (sscanf(str, "%s tells you: %s", who, what) < 1)
    return;

  shut = find_object(SHUTDEMON);
  if (-1 != strstr(what, "time") || -1 != strstr(what, "shutdown"))
  {
    if (!shut || !shut->query_progress())
      tell_object(this_player()
                 , "Armageddon tells you: There is no shutdown in progress.\n"
                 );
    else
    {
        seconds = shut->query_time_left();
      tleft = (seconds * 3 / 4 - 10) + tleft;
      msg = "";
      if (seconds > 59) {
        msg = seconds / 60 + " minutes ";
        seconds = seconds % 60;
      }
      if (seconds != 0)
        msg += seconds + " seconds";
      tell_object( this_player()
                 , "Armageddon tells you: "+msg+" till shutdown.\n"
                 );
    }
    return;
  }
  if (!rescue) {
    tell_object(this_player(), 
"Armageddon tells you: What do you want? Please tell me later, i'am busy now!\n"
               );
    return;
  }
  tell_object(this_player(),
"Armageddon teleports you to a special shop...\n"
             );
    this_player()->move(SHUTSHOP, M_TELEPORT);
}

/*************************************************************************/
