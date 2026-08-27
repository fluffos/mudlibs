/*  A bunch of useful functions for use in various spells
 */

/* Unholds all the targets held stuff.  --wf */
void force_unhold_weapons(object ob)
{
  object* held_stuff;
  int i;

  held_stuff = (object*)ob->query_held_ob();
  for (i=0;i<sizeof(held_stuff);i++)
        if ( held_stuff[i] )
          ob->unhold_ob(held_stuff[i]);

  return;
}
 
/* Unwears all the targets worn stuff. --wf */
void force_unwear_armour(object ob)
{
  object* worn_stuff;
  int i;

  worn_stuff = (object*)ob->query_worn_ob();
  for (i=0;i<sizeof(worn_stuff);i++)
        if ( worn_stuff[i] )
          ob->unwear_ob(worn_stuff[i]);

  return;
}

/* Drops everything in the target's inventory  --wf */
void force_drop_everything(object ob)
{
  object* stuff;
  int i;

  stuff = all_inventory(ob);
  for (i=0;i<sizeof(stuff);i++)
        ob->drop_ob(stuff[i]->query_name());
//Prevent it from desting in .5 seconds.
  environment(ob)->add_property("no_cleanup",1);

  return;
}
/* Drops everything in the target's inventory  --wf */
void force_drop_one(object ob)
{
  object* stuff;
  int i;

  stuff = all_inventory(ob);
   if(sizeof(stuff)) ob->drop_ob(stuff[random(sizeof(stuff))]->query_name());

  return;
}
