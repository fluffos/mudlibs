/*
 * find_all_living ( string name )
 *
 * Returns a list of objects that can be found by find_living()
 * Basically giving the contents of the living 'name' hash table
 *
 * Limitations: Eval limits to less then 30,
 *              works in conjunction with lfun set_living(name),
 *              (it will stop evaluating if it doesn't have this lfun )
 *
 * Example lfun (it's in base_obj.c)
 *     void set_living(string str) {
 *       if (file_name(previous_object()) == SIMUL_EFUN) {
 *         set_living_name(str);
 *       }
 *     }
 */

object *find_all_living(string name) {
  object ob;
  object *all;
  int i;

  for (all = ({}); (ob = find_living(name)) && i < 45; i++) {
#ifndef __LDMUD__
    if (member_array(ob, all) != -1) break;
#else
    if (member(all, ob) != -1) break;
#endif
    all += ({ ob, });
    ob->set_living("DUMMY");
  }
  for (i = sizeof(all); i--; ) all[i]->set_living(name);
  return all;
}

