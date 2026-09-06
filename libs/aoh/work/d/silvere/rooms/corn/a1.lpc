// A cornfield. Newbie area for Silvere
// created:      Tune       [14-May-99]

#include <silvere.h>
#include <properties.h>
#include <macros.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <nightday.h>

inherit SILCORNFIELD;

varargs void create()
{
   ::create();

   Set(P_INDOORS, 0);

   SetIntShort("a cornfield");
   SetIntLong(
     "You are standing in the midst of a large cornfield.\n");

   AddItem( NPC("crow"), REFRESH_DESTRUCT, 2 );
   Set(P_INT_WIZMSG,
     " East: ...\n"
     " West: ...\n");

}
