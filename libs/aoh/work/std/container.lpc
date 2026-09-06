//---------------------------------------------------------------------------
// std/container.c
//
// The standard container in One Step Beyond.
//---------------------------------------------------------------------------

#include <classes.h>
#include <properties.h>
#include <search.h>

inherit "/std/container/restrictions";
inherit "/std/thing/description";
inherit "/std/room/description";
inherit "/std/thing/moving";
inherit "/std/base";

public void create () {
  base::create();
  "restrictions"::create();
  AddClassId(C_CONTAINER);
  SetMaxWeight(0);
  SetPreContent("It contains:\n");
  seteuid(getuid());
  Set(P_HELP_MSG,
"The container can hold one or more other things, given that they aren't "
"too big. Simply put them into the container or take them out from it.\n"
     );
}

// Just in case

public void init() { }

/*-------------------------------------------------------------------------
** The content is always visible to the inside, but to the outside only
** if the container is not transparent.
*/

public varargs string Content (string what, mixed exclude) {
  if (member(deep_inventory(this_object()), this_player()) == -1
   && LSTATE_GHOST != ({int})this_player()->Query(P_LSTATE)
   && QueryTransparency() < 500
     )
    return "";
    return ::Content(what, exclude);
}

