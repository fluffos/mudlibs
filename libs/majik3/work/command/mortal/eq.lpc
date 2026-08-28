/****
****    Command                                 eq
***         Description                         Shows worn equipment
**          Coder                                       Dazzt
*/

int eq(object targob, object targmsg)
{
  object *all = targob->query_wielded_weapon();
  int found;
    
    for (int i=0;i<sizeof(all);i++)
      {
        if (all[i]->short())
          {
            write(sprintf ("Wielded in %s hand: ^cP%s^c0\n", ({ "left",
              "right" })[i], all[i]->short()));
            found++;
          }
      }

    all = targob->query_worn_armour();

    for (int i=0;i<sizeof(all);i++)
      {
        if (all[i])
          {
            printf ("%d: ^cc%O^c0\n", i, all[i]);
            found++;
          }
      }

    if (!found)
      {
        write ("Nothing.\n");
      }

    return 1;
}

int main ()
{
    message("standard", "^cgYou are wearing the following equipment:^c0\n", THIS);

    eq(THIS, THIS);

    return 1;
}

query_author ()
{
  return "namhas";
}

query_help ()
{
  return "This command will show you what equipment you have worn "
       + "or wielded and into what slots they are.";
}

query_see_also ()
{
  return "i(1), wield(1), health(1)";
}

query_position ()
{
  return POS_RESTING;
}

