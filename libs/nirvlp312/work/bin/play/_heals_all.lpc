/* A deep_inventory version of cmd_heals */
int cmd_heals_all(string str)
{
  mapping heals;
  object *inv;
  string *indices;
  int size;
  int i;
  int total;

  heals=([ ]);

  inv=deep_inventory(this_player());
  size=sizeof(inv);

  for(i=0; i < size; i++)
  {
    if(inv[i]->is_heal())
    {
      heals[(string)inv[i]->query_short()?(string)inv[i]->query_short():(string)inv[i]->short()]+=(int)inv[i]->query_charges();
      total++;
    }
  }

  indices=keys(heals);

  write("Heals                         Charges\n");
  write("-------------------------------------\n");
  size=sizeof(indices);
  for(i=0; i < size; i++)
  {
    write(colour_pad(indices[i],30));
    write(heals[indices[i]]+"\n");
  }

  /* Cobain : Modified to Correct grammar anomalies.*/
  /* write("You have "+total+" heals.\n"); */
  write("\nYou have "+((total == 1) ? "1 heal": total+" heals")+".\n");
  return 1;
}
