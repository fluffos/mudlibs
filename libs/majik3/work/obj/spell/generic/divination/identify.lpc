inherit SPELL;

create_spell ()
{
  set_level (1);
  set_casting_time (8);
  set_components (1, 1, "pearl");
}

perform_spell (object caster, string target_name, int result)
{
  object target;

  target = present(target_name);

  if (!target)
    {
      tell_object (caster, "There is no "+target_name+".\n");
      return 0;
    }

  emote ("$n {identify} "+target->query_name()+".", caster, 0, ENV(caster));
  tell_object (caster, target->identify());
  return 1;
}

query_help ()
{
  return "Using this spell the caster can identify items.";
}
