
public int
filter_live(object ob)
{
  int i, j, sz;
  object *inv;

  if (!first_inventory(ob)) return 0;

     inv = all_inventory(ob);
     sz =0;
     
     for (j=sizeof(inv), i = 0; i < j; i++)
         if (living(inv[i])) sz++;
     return sz;
}

