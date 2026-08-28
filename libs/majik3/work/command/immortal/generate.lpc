int
main (string str)
{
  string s1, s2, s3;
  object o;

  if (!str)
    {
      notify_fail ("  Usage: generate what_material_type\n");
      notify_fail ("Example: generate weapon_random_random\n"); 
      return 0;
    }

  if (sscanf(str, "%s_%s_%s", s1, s2, s3) != 3)
    {
      write ("mokasit mokasit.\n");
      return 1;
    }

  o = clone_object("/obj/generic_weapon");
  o->generate (s2+"_"+s3);
  o->create_item();
  o->move (ENV(THIS));
  write ("You generate "+o->short()+".\n");
  message ("3", THIS->query_cap_name()+" generates "+o->short()+".\n", ENV(THIS), THIS);
  return 1;
}
