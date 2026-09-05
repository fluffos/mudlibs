int
gen_wc_bonus()
{
    object e, x;
    if((e = environment()) && (x = (object)e->query_attack()) && !x->is_player())
    {

      if(!random(10))
        if((int)x->query_alignment() < -333) return (-random(3));
      else
        if((int)x->query_alignment() > -1) return random((int)e->query_guild_rank() * 3 / 4);
    }

    return 0;
}
