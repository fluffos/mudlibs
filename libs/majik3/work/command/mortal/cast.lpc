int
main (string str)
{
  string spell_name, target;

  if (!str)
    {
      notify_fail ("Usage: cast <spell name> [at <target>]\n");
      return 0;
    }

  if (sscanf(str, "%s at %s", spell_name, target) == 2)
    THIS->chant_spell (replace_string(spell_name, " ", "_"), target);
  else
    THIS->chant_spell (str);

  return 1;
}

query_position ()
{
  return POS_STANDING;
}

query_help ()
{
  return "Using this command you can cast spells if you know some.";
}

query_synopsis ()
{
  return "cast <spell name> [at <target>]";
}

query_author ()
{
  return "namhas";
}

