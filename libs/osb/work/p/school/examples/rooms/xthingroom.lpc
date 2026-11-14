/*   Room for Thing Examples  (Mateese, 13-Aug-94)
**
** This room serves as a storage for example items.
*/

#include <rooms.h>

inherit "/std/room";
#include <properties.h>

object make_item(); // forward declaration

/*----------------------------------------------------------------------------
** Initialize us
*/

void create() {
  int ix;

  ::create();

  SetIntShort("The Storage of Example Things");

  SetIntLong(
"A 'multimedia' room. (/d/archwiz/common/lpc/exm/xthingroom.c)\n"
"This room is cluttered with various examples of things. "
"Since some curious visitors took some away, the collection may "
"be 'rebuild' manually.\n"
"You see a doorway to the west, leading to the entrance.\n"
"There is a faint smell and a noticeable noise in the room.\n"
            );

  AddExit("west", "/d/archwiz/common/lpc/entrance");

  AddRoomCmd("rebuild", "_do_reset");

  /* SetIntLight(1); */

    /* Add a smell and a noise to the room.
    ** The strings are process_string()ed, but we don't use that.
    */

  SetIntSmell("You smell the typical odor of newly created things.\n");
  SetIntNoise("You hear the low hum of working machinery.\n");

    /* We can also give certain details of the room a smell or a noise:
    **   AddSmell (<name>, <smell>);
    **   AddNoise (<name>, <noise>);
    ** After this, the command 'smell <name>' would return '<smell>'.
    ** <name> can also be an array of names, for which the smell/noise
    ** is valid.
    ** A second form is:
    **   AddSpecialSmell (<name>, <fun>);
    **   AddSpecialNoise (<name>, <fun>);
    ** Here, the function <fun> is called and has to return the
    ** string with the smell/noise.
    ** Again, the <name> might be an array of names.
    */

  AddItem("/d/archwiz/common/lpc/exm/xweapon", REFRESH_REMOVE);
  AddItem("/d/archwiz/common/lpc/exm/xweapon2", REFRESH_REMOVE);
  AddItem("/d/archwiz/common/lpc/exm/xweapon3", REFRESH_REMOVE);
  AddItem("/d/archwiz/common/lpc/exm/xarmour", REFRESH_REMOVE);
  AddItem("/d/archwiz/common/lpc/exm/xarmour2", REFRESH_REMOVE);
  AddItem("/d/archwiz/common/lpc/exm/xcontainer", REFRESH_REMOVE);
  AddItem("/d/archwiz/common/lpc/exm/xcontainer2", REFRESH_REMOVE);
  AddItem("/d/archwiz/common/lpc/exm/xthing1", REFRESH_REMOVE);
  AddItem("/d/archwiz/common/lpc/exm/xthing2", REFRESH_REMOVE);
  AddItem("/d/archwiz/common/lpc/exm/xthing3", REFRESH_REMOVE);
  AddItem("/d/archwiz/common/lpc/exm/xnpc1",   REFRESH_HOME);
  AddItem("/d/archwiz/common/lpc/exm/xnpc2",   REFRESH_DESTRUCT);
  AddItem("/d/archwiz/common/lpc/exm/xnpc3",   REFRESH_DESTRUCT);
  AddItem("/d/archwiz/common/lpc/exm/xautoload2", REFRESH_REMOVE);
  AddItem("/d/archwiz/common/lpc/exm/xequipment", REFRESH_REMOVE);
  AddItem("/obj/torch", REFRESH_REMOVE);
  AddItem(#'make_item, REFRESH_REMOVE);

 AddItem("/d/archwiz/common/lpc/exm/xunit", REFRESH_REMOVE);
  /* xunit is an example for a /std/unit. Due to the way /std/units work,
   * this way of adding the item might lead to unwanted reproduction.
   * An alternative is:
   *   AddItem("/d/archwiz+/common/lpc/exm/xunit", REFRESH_ALWAYS, ([ P_AMOUNT:1 ]));
   * It is preferable for amounts > 1.
   */
}


/*----------------------------------------------------------------------------
** Clone, configure and return an object.
** This is quite useful to generate objects w/o writing extra files for them.
*/

object make_item() {
  object ob;
  ob = clone_object("/std/thing");
  ob->SetShort("a fileless thing");
  ob->SetLong (
"This is a fileless thing. It is cloned and configured on the fly\n"+
"by the Room of Example Things (/d/archwiz/common/lpc/exm/xthingroom.c).\n"
              );
  ob->SetWeight (10);
  ob->SetValue(1);
  ob->AddId("thing");
  ob->AddId("xthing");
  ob->AddAdjective ("fileless");
  return ob;
}

/*----------------------------------------------------------------------------
** Manually trigger a reset() to refresh the example items
*/

_do_reset (str) {
  if (str) return 0;
  ::reset();
  write ("Ok, take a look now.\n");
  return 1;
}

/*---------------------------------------------------------------------------*/
