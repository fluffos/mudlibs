/* only an object for to update rooms */

#include <moving.h>

update_me(object ob)
{
  string filename;
  int i;
  object *inv;

  inv = all_inventory(ob);
  filename = object_name(ob);
  for(i = sizeof(inv); i--; )
    inv[i]->move("/std/void",M_SILENT);
  destruct(ob);
  for(i = sizeof(inv); i--; )
    inv[i]->move(filename,M_SILENT);
}
