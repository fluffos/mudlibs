#include <properties.h>
#include "path.h"

inherit "/std/container";

object garlic;

create () {
  ::create();
  SetShort ("a sack");
  SetLong ("It's an elongated brown sack smelling of hot peppers.\n");
  SetIntShort ("a sack");
  SetIntLong ("You look into a brown sack.\n");
  SetValue (12);
  SetWeight (1000);
  AddId ("sack");
  SetMaxWeight (3500);
  SetTransparent (0);
  SetWeightChg (250);
  seteuid(getuid(this_object()));
  garlic=clone_object(OBJ("garlic"));
  call_other(garlic,"move",this_object());
}
