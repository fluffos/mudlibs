
nomask int query_pct_weight()
{
  int max;
  recalc_carry();
  if(strength < 21)
    max = level + 6 + strength/5;
  if(strength > 20)
    max = level + 10 + (strength-20)/5;
  if (level == 1)
    max = level + 6 + strength/2;
  if(ex_lv) max += (ex_lv / 4);
  return local_weight*100/max;
}
