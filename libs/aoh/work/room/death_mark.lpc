/* Death-Mark
**
** The main purpose of the mark is to be autoloading to prevent cheating.
** Thus we don't make it a fullfledged 'thing'.
** But since we have it, it can also do some nicies.
**
**   26-Aug-92 [m] Adapted for native.
**   16-Apr-97 [t] Small update to give different messages depending on
**                 the kills of a player.
**
**  [m] Mateese@Nightfall
**  [t] Thragor@Nightfall
*/

#include <config.h>
#include <properties.h>
#include <moving.h>

#define ME this_object()
#define TP this_player()
#define SF(x) #'x //' Emacs Hack

inherit "/std/base";

private nosave object pPlace;  /* Here we'll return from death */

private string block(string what)
{
  string *letters;
  letters = map(explode(what,""),SF(capitalize));
  return implode(letters,"");
}

public void start_death()
  // Just print out some comments and move the player into the deathroom.
  // The player is the one carrying us, and it must be a ghost already.
{
  object my_host, ob;
  my_host = environment();

  if (   !my_host
      || !living(my_host)
      || pPlace)
    return;
  if (!({int})my_host->QueryGhost())
    {
      remove();
      if (ME) destruct(ME);
      return;
    }

  pPlace = environment(my_host);
  show_room(pPlace, "You see a dark shape gathering some mist...\n"
      "...or maybe you're just imagining that.\n");
  tell_object(my_host,
        "You can see a dark hooded man standing beside your corpse.\n"
	"He is wiping the bloody blade of a wicked looking scythe with slow "
	"measured motions.\n"
	"Suddenly he stops and seems to look straight at you with his "
	"empty...\n"
	"no, not empty but.... orbs....\n\n");
  if (({int})my_host->QueryKills())
    tell_object(my_host,
      "Death says: COME WITH ME, "+block(getuid(my_host))+"!\n\n");
  else
    tell_object(my_host,
      "Death says: COME WITH ME, MORTAL ONE!\n\n");
  tell_object(my_host,
    "He reaches for you and suddenly you find yourself in another "
	"place.\n\n");
  if (   ME_OK != ({int})my_host->move("/room/death_room", M_SILENT)
      && ME_OK != ({int})my_host->move("/room/death_room", M_NOCHECK)
     )
    {
      CHANNEL_D->SendTell("error", "DEATH_MARK",
			     sprintf("[error] death_mark: Can't move player "
				     "%s out of its env %O.",
				     capitalize(geteuid(my_host)),
				     environment(my_host)
				    ),1
			    );
      my_host->SetGhost(0);
      destruct(this_object());
    }
}

public int QueryAutoObject()
{
  return 1;
}

public object QueryPlace()
{
  return pPlace;
}

public varargs int move(mixed dest, mixed method, mixed extra)
{
  if (stringp(dest)) dest = find_object(dest);
  if (!dest) return 0;
    /* If a living is dead, it's dead. */
/*  if (method != 1 && living(environment(this_object()))) return 0; */
  move_object(this_object(), dest);
  start_death();
  return ME_OK;
}

public int id(string str) { return str == "death_mark"; }
