/* Advent - Giant Clam -- Mateese, 22-Aug-96
 *
 * The giant clam from the Shell Room.
 * It can be opened just with the jeweled trident (Cave with Waterfall)
 * and reveals a precious pearl (which immediately rolls into Cul De Sac).
 * The identifying property ADV_CLAM is used to store these two states:
 *   ADV_CLAM == 1: clam hasn't been opened yet.
 *   ADV_CLAM == 2: clam has been opened once
 */

#include <config.h>
#include <properties.h>
#include <moving.h>
#include <search.h>
#include "advent.h"

inherit "/std/thing";

/*-----------------------------------------------------------------------*/
public void create()
{
  ::create();

  Set(P_SHORT, "a giant clam");
  Set(P_LONG, "This is an enormous clam with its shell tightly closed.\n");
  Set(P_WEIGHT, 25000);
  Set(P_VALUE, 50);
  AddId(({"clam", "oyster", ADV_CLAM}));
  AddAdjective(({ "enormous", "giant"}));
  Set(ADV_CLAM, 1);
}

/*-----------------------------------------------------------------------*/
public void init()
{
  ::init();
  add_action("fopen", "open");
  add_action("fopen", "unlock"); /* Illogical, but the original says so... */
}

/*-----------------------------------------------------------------------*/
public void Aloha (int flag)

/* Upon room reset, put the pearl back into us.
 */

{
  Set(ADV_CLAM, 1);
  Set(P_SHORT, "a giant clam");
  Set(P_LONG, "This is an enormous clam with its shell tightly closed.\n");
}

/*-----------------------------------------------------------------------*/
public int fopen (string arg)

/* Try to open the clam. The player have to use the jeweled trident to
 * achieve this.
 * Formats: 'open clam'
 *          'open clam with <...>'
 */
{
  string *args;
  string what, with;
  object obj;
  int i;
    
  if (!arg)
  {
    notify_fail(capitalize(query_verb())+" what?\n", NOTIFY_NOT_CMD);
    return 0;
  }

  /* Extract the <what> and <with> from the args.
   */
  args = norm_id(arg, 1);
  i = member(args, "with");
  if (i != -1)
  {
    what = implode(args[0..i-1], " ");
    with = implode(args[i+1..], " ");
  }
  else
  {
    what = implode(args, " ");
    with = 0;
  }
  
  /* Is this object meant? */
  if (this_object() != wsearch_env_inv(what))
  {
    notify_fail(capitalize(query_verb())+" what?\n", NOTIFY_NOT_OBJ);
    return 0;
  }

  /* With bare hands? */
  if (!with)
  {
    notify_fail("You aren't strong enough to "+query_verb()
	       +" it with your bare hands.\n", NOTIFY_ILL_ARG);
    return 0;
  }

  /* Has the player something with her to open the clam? */
  obj = wsearch_inv(with);
  if (!obj)
  {
    notify_fail(capitalize(query_verb())+" the clam with what?\n"
	       , NOTIFY_ILL_ARG);
    return 0;
  }

  /* Just the jeweled trident will work! */
  if (!obj->Query(ADV_TRIDENT))
  {
    notify_fail(capitalize(obj->Short())+" isn't strong enough to "
		+query_verb()+" the clam.\n"
	       , NOTIFY_NOT_VALID);
    return 0;
  }
  
  show(this_player()->Query(P_NAME)+" "+query_verb()+"s the clam with "
      +(obj->Query(P_SHORT))+".\n");

  if (Query(ADV_CLAM) < 2)
  {
    object pearl, room;

    pearl = clone_object(ADVENT("o/treasure"));
    pearl->Set(P_SHORT, "a glistening pearl");
    pearl->Set(P_LONG, "It's incredibly large.\n");
    pearl->Set(P_WEIGHT, 100);
    pearl->Set(P_VALUE, 1000);
    pearl->Set(P_TREASURE, F_PEARL);
    pearl->Set(P_XP, 1600);
    pearl->AddId("pearl");
    pearl->AddAdjective(({"large", "glistening"}));
      
    show_room(environment(this_object()),
"A glistening pearl falls out of the clam and rolls away. Goodness, this must "
"really be an oyster. Anyway, it has now snapped shut again.\n"
	     );
    Set(P_SHORT, "an enormous oyster");
    Set(P_LONG, "This is an enormous oyster with its shell tightly closed.\n");
    Set(ADV_CLAM, 2);

    room = find_object(ADVENT("o/raggedcorr"));
    if (room)
      show_room(room, "A glistening pearl rolls downwards.\n");

    room = load_object(ADVENT("r/culdesac"));
    show_room(room, "A glistening pearl rolls in and comes to rest.\n");
    if (ME_OK != pearl->move(room, M_SILENT))
      raise_error("Move of pearl into "+to_string(room)+" failed.\n");
  }
  else
  {
    show_room(environment(this_object()),
"The oyster creaks open, revealing nothing but oyster inside. It promptly "
"snaps shut again.\n"
	     );
  }

  return 1;
}

/*************************************************************************/
