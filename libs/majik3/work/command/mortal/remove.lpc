int main(string str)
{
    object o;

    if (!str)
    {
		notify_fail("Usage: remove <item>\n");
		return 0;
    }

    o = present(str, THIS);
    if (!o)
    {
		write ("You don't have "+str+".\n");
		return 1;
    }
	
	if (!o->query_is_worn())
	{
          if (o->is_weapon())
            write ("You aren't wielding "+o->query_maybe_cap_name()+".\n");
          else if (o->is_armour())
            write ("You aren't wearing "+o->query_maybe_cap_name()+".\n");
          return 1;
	}
	
	o->set_is_worn(0);

        THIS->update_worn_armour();
        THIS->update_wielded_weapon();

    message("environment", capitalize(THIS->query_name()) + " removes " + o->short() + ".\n",
      environment(THIS), THIS);
    message("environment", "You remove " + o->short() + ".\n", THIS);

    return 1;
}

query_author()
{
  return "namhas";
}

query_help()
{
  return "This is used to remove wielded or worn equipment.";
}

query_synopsis()
{
  return "remove <item>";
}

query_see_also()
{
  return "wield(1), wear(1)";
}

query_example()
{
  return "remove longsword";
}
query_position ()
{
  return POS_RESTING;
}

