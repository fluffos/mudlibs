/* Protect.c ripped off from combat.c to make it more versatile.
 * Baldrick, oct '94
 */

nosave object *protecting,
              *protector;

void init ()
  {
  protecting = ({ });
  protector = ({ });
}

void combat_commands() 
  {
  add_action("do_protect", "protect");
}

/* The add and remove stuff .. */

void add_protecting(object ob)
  {
  protecting += ({ ob, });  
  ob->add_protector(this_object());
  return;
} /* void add */

void add_protector(object ob)
  {
  protector += ({ ob, });
  return;
} /* add protector */

void remove_protecting(object ob)
  {
  protecting -= ({ ob, });
  ob->remove_protecor(this_object());
  return;
}   

void remove_protector(object ob)
  {
  protector -= ({ ob, });
  return;
} /* remove protector */

object *query_protector() { return protector; }


int do_protect(string str) 
  {
  object *obs, *ok; int i;
  if (!str) 
    {
    notify_fail("Syntax: protect <objects>\n");
    return 0;
    }
  obs = find_match(str, environment());
  if (!sizeof(obs)) 
    {
    notify_fail("Protect what?\n");
    return 0;
    }
//dk added member_array to this next line:
  if (member_array(this_object(), obs))
//dk I changed this next line from this_object() to this_object():
    obs -= ({ this_object() });
  ok = ({ });
  for (i=0; i<sizeof(obs); i++)
    {
    /* adding the lucky guy */
    if (member_array(obs[i], query_protector()) == -1)
      {
      add_protecting( obs[i] ); 
      ok += ({ obs[i] });
      }
     else
      return notify_fail("You already protects " + obs[i]->query_cap_name() +
          ".\n"); 
    }
  if (!sizeof(ok)) 
    {
    notify_fail(query_multiple_short(obs)+
      (sizeof(obs)==1?" doesnt":" don't")+" want your protection.\n");
    return 0;
    }
  if (sizeof(obs) != sizeof(ok))
    write("You fail to protect "+query_multiple_short(obs - ok)+".\n");

  write("You protect "+query_multiple_short(ok)+".\n");
  say(this_object()->query_cap_name()+" protects "+query_multiple_short(ok)+
      ".\n", ok);
  for (i=0; i<sizeof(ok); i++)
    tell_object(ok[i], this_object()->query_cap_name()+" protects "+
                query_multiple_short(({ "you" }) + (ok - ok[i..i]))+".\n");
  return 1;
}
