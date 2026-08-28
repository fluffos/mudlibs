inherit SPELL;

create_spell ()
{
  set_level (4);
  set_casting_time (3);
  set_components (1, 1, "candle");
}

perform_spell (object caster, string target_name, int result)
{
  object target;

  target = find_player (target_name);

  if (!target)
    {
      write ("You are unable to summon "+target_name+".\n");
      return 0;
    }

  emote ("$n has summoned you!", caster, 0, target);
  target->move_player (file_name(ENV(caster)));
  return 1;
}

query_help ()
{
  return "Use of this spell summons specified mortal here instantly.";
}
