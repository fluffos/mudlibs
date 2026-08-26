int query_ac() {
        mapping armor ;
        int ac,i ;
        string *types ;
        
  ac= 0;
        armor = this_object()->query("armor") ;
        if (armor) {
        types = keys(armor) ;
   for(i=0;i<sizeof(types);i++) ac += armor[types[i]];
        }
  switch((int)this_object()->query("stat/agility")) {
    case 12..15 : ac += 1; break;
    case 16..19 : ac += 2; break;
    case 20..24 : ac += 3; break;
    case 25..30 : ac += 4; break;
    case 31..50: ac += 5; break;
    default: break;
  }
  if (!userp(this_object())) ac += this_object()->query("monster_ac");
  i = this_object()->query("magical_defense");
  ac += i;
  return ac;
}

int query_wc() {
  object wep;
  int wc;
  wep = this_object()->query("left_hand");
  if (wep) wc = wep->query("weapon");
  wep = this_object()->query("right_hand");
  if (wep) wc += wep->query("weapon");
  switch((int)this_object()->query("stat/dexterity")) {
   case 1..10: break;
   case 11..15: wc += 1;break
;  case 16..20: wc += 2;break;
  case 21..26 : wc += 3;break;
  case 27..32 : wc += 4;break;
  case 33..50 : wc += 5; break;
  default: break;
 }
  if (!userp(this_object())) wc += (int)this_object()->query("monster_wc");
  wc += (int)this_object()->query("magical_offense") ;
  return wc;
}

int query_str_diff() {
  return (int)this_object()->query("stat/strength")/6;
}
