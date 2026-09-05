/* List heals and show their charges. */
int cmd_heals(string str)
{
  mapping heals;
  object ob;
  string *indices;
  int total;
  int i;

  heals=([ ]);
  ob=first_inventory(this_player());
  while(ob)
  {
    if((int)ob->is_heal())
    {
      heals[(string)ob->query_short()?(string)ob->query_short():(string)ob->short()]+=(int)ob->query_charges();
      total++;
    }
    ob=next_inventory(ob);
  }

  indices=keys(heals);

  write("Heals                         Charges\n");
  write("-------------------------------------\n");
  for(i=0; i < sizeof(indices); i++)
  {
    write(colour_pad(indices[i],30));
    write(heals[indices[i]]+"\n");
  }
  /* Cobain: Modified to correct grammar anomalies */
  /* write("You have "+total+" heals.\n"); */
  write("\nYou have "+(total == 1 ? "1 heal": total+" heals")+".\n");
  return 1;
}
