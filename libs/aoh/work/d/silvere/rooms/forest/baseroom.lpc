/*  The baseroom for the forest southeast of Silvere
**
**  Created by [e] 19.09.1997
**
**  [e]  eilan
*/

#include <config.h>
#include <silvere.h>

inherit "/std/room";

varargs void create()
{
  ::create();

  AddDetail(( {"forest"}), "You are standing in a forest");

  SetOutdoors(1);

  SetIntLight(MAX_SUNBRIGHT/2);

  Set(P_INT_MAP, "forest2");

}

string QueryIntNoise()
{
  string rc;
  string *tmp;

  rc = ::QueryIntNoise();
  if (stringp(rc) || closurep(rc))
    return rc;

  tmp = ({
   "The pleasant music of birds fills the forest.\n",
   "Serene stillness pervades here in the depths of the wood.\n",
   "The busy sounds of the city cannot invade the quiet forest.\n"
  });

  return random_select(tmp);
}
