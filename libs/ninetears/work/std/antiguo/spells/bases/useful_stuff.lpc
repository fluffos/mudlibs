void force_unhold_weapons(object ob)
{
  object *tmp=ob->query_held_ob();
  for (int i=0;i<sizeof(tmp);i++) ob->unhold_ob(tmp[i]);
}
 
void force_unwear_armour(object ob)
{
  object* tmp=ob->query_worn_ob();
  for (int i=0;i<sizeof(tmp);i++) ob->unwear_ob(tmp[i]);
}

void force_drop_everything(object ob)
{
  object *tmp=all_inventory(ob);
  for (int i=0;i<sizeof(tmp);i++) ob->drop_ob(tmp[i]->query_name());
  ENV(ob)->add_property("no_cleanup",1);
}

void force_drop_one(object ob)
{
  object *tmp=all_inventory(ob);
  if (sizeof(tmp)) ob->drop_ob(tmp[random(sizeof(tmp))]->query_name());
}
