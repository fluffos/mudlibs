int vampiric_func(int dice, object who) {
  int res, i, mult;
  int sides = 6;
  object wield = previous_object();

  res = 0;
  if(dice < 0) {
    mult = -1;
    dice *= -1;
  } else
    mult = 1;
  for(i=1; i<=dice; i++) res += 1+random(sides);
  res *= mult;
  who->add_hp(-1 * res/10);
  wield = wield->query_wielded();
  if(wield) {
    wield->add_hp(res/10);
    message("info", "%^MAGENTA%^%^BOLD%^The blade drains %^RESET%^"+
	    "%^CYAN%^"+sprintf("%d hp", res/10)+"%^RESET%^%^MAGENTA%^"+
	    "%^BOLD%^ from your victim!", wield);
  }
  return 0;
}




