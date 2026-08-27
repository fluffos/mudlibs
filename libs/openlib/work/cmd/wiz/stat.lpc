#include <object_types.h>
#include <cmdline.h>

int
main(string* argv, string* argv2)
{
  string info = "";
  mixed tmp;
  object ob;

  if( !sizeof(argv2) )
    return notify_fail("usage: stat <object name>\n");

  if( !(ob = present(argv2[0], environment(this_player()))) )
    ob = present(argv2[0], this_player());
  if( !ob )
    ob = find_object(argv2[0]);
  if( !ob )
    return notify_fail("Couldn't find specified object.\n");

  if( living(ob) ) {
    info += sprintf("Name: %s\n", ob->query_name());
    info += sprintf("Cap Name: %s\n", ob->query_cap_name());
    info += sprintf("Race: %s\n", ob->query_race());
    info += sprintf("Gender: %i <see gender.h>\n", ob->query_gender());
    info += sprintf("Coins: %i silver, %i gold.\n",
		    ob->query_money()[0], ob->query_money()[1]);
  }
  if( ob->query_object_class() & OBJECT_CONTAINER ) {
    info += sprintf("Weight Cap: %i\n", ob->query_weight_capacity());
    info += sprintf("Bulk Cap: %i\n", ob->query_bulk_capacity());
    info += sprintf("Rigid: %s lbs.\n", (ob->query_rigid() ? "yes" : "no"));
  }
  info += sprintf("Base Weight: %i lbs.\n", ob->query_base_weight());
  info += sprintf("Weight: %i lbs.\n", ob->query_weight());
  info += sprintf("Base Bulk: %i\n", ob->query_base_bulk());
  info += sprintf("Bulk: %i\n", ob->query_bulk());
  info += sprintf("Light Level: %i\n", ob->query_light());
  info += "Id's: ";
  foreach(string id in ob->query_ids())
    info += id + ", ";
  info += "\n";
  if( tmp = ob->query_value() )
    info += sprintf("Value: %i silver, %i gold.\n", tmp[0], tmp[1]);

  this_player()->more(explode(info, "\n"));
  return 1;
}
