inherit SPELL;

create_spell ()
{
  set_level (1);
  set_casting_time (1);
  set_components (1, 1, 0);
  set_offensive (1);
}

perform_spell (object caster, string target_name, int result)
{
  object target;

  target = present (target_name);

  if (!target)
    {
      write ("There is no "+target_name+".\n");
      return 0;
    }

  emote ("A magical missile surges up from $s fingertip and strikes "
    + "at $N!", caster, target, ENV(THIS));

  target->add_hp (-(random(40) + 10));
  return 1;
}

query_help ()
{
  return "Use of this spell creates up to five missiles of magical energy "
    + "that dart forth from the caster's fingertip and unerringly strike their "
    + "target. The amount of missiles is determined by the skill of the caster.";
}
