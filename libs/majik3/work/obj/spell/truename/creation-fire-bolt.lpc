do_success(object me, string target)
{
  object o;

  if (target)
    o = present(target);

  if (!o)
    {
      emote ("$n {create} a firebolt which explodes in $s hands!",
        me, 0, ENV(me));

      me->add_hp (-(random(80) + 80));

      return 1;
    }
  else
    {
      emote ("$n {create} a firebolt and {throw} it at $N!",
        me, o, ENV(me));

      o->add_hp (-(random(80) + 80));

      return 1;
    }
}

do_failure(object me, string target)
{
  emote ("$n feel a warm feeling surging through your body but nothing "
    + "seem to happen.", me, 0, me);

  return 1;
}

query_offensive() { return 1; }
query_true_magick() { return 1; }
