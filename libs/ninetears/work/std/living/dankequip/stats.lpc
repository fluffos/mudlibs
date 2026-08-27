/* the stat data for the living objects... */
nosave int intbon,
       dexbon,
       conbon,
       strbon,
       wisbon,
       chabon;
int Dex,
    Int,
    Con,
    Str,
    Wis,
    Cha,
    inttmp,
    dextmp,
    contmp,
    wistmp,
    strtmp,
    chatmp;
nosave int no_check;

int extra_attack_bonus, extra_defend_bonus, magical, ac;

int query_no_check() { return no_check;}
void set_no_check(int i) { no_check = i;}

void reset_hp() {
  object guild_ob;

  if (no_check) return ;
  guild_ob = (object)this_object()->query_guild_ob();
  if(!guild_ob)
    this_object()->set_max_hp((int)this_object()->query_level()*8+4);
  else
   guild_ob->set_hp(this_object());
}

void reset_gp() {
  object guild_ob;

  if (no_check) return ;
  guild_ob = (object)this_object()->query_guild_ob();
  if (!guild_ob)
    this_object()->set_max_gp(this_object()->query_level());
  else
    guild_ob->set_gp(this_object());
}

void reset_carry_cap() {
  int old_cap, cap, st;
  object ob, ob1;

  if (no_check) return ;
  old_cap = (int)this_object()->query_loc_weight();
  st = Str+strtmp+strbon;

  if (st < 8)
    cap = 500;
  else if (st > 28)
    cap = 3500+(st-28)*300;
  else
    cap = ({ 500, 550, 600, 650, 750, 850, 950, 1150, 1300, 1450, 1600,
  1750,1900,2100,2300,2500,2700,2950,3200,3500,3850})[st-8];
  this_object()->set_max_weight(cap);
  if (cap >= old_cap)
    return ;
  ob = first_inventory(this_object());
  while (ob) {
    ob1 = next_inventory(ob);
    if (ob->query_weight())
      if (ob->move(environment())) {
        old_cap -= (int)ob->query_weight();
        say(this_object()->query_cap_name()+" drops "+ob->short()+
                 " under strain.\n");
        write("Your fading strength makes you drop "+ob->short()+".\n");
      }
    if (cap >= old_cap)
      return ;
  ob = ob1;
  }
}

void reset_bon_stats()
  {
  strbon = 0;
  dexbon = 0;
  conbon = 0;
  intbon = 0;
  wisbon = 0;
  chabon = 0;
  }

void reset_all() {
  call_out("reset_all2",0);
}

void reset_all2() {
/* make sure for reset_all's */
  no_check = 0;
  reset_hp();
  reset_gp();
  reset_carry_cap();
}

int set_str(int i) {
  Str = i;
  reset_carry_cap();
  return 1;
}

int set_con(int i) {
  Con = i;
  reset_hp();
  return 1;
}

int set_int(int i) {
  Int = i;
  reset_gp();
  return 1;
}

int set_dex(int i) {
  Dex = i;
  return 1;
}

int set_wis(int i) {
  Wis = i;
  reset_gp();
  return 1;
}

int set_cha(int i) {
  Cha = i;
  return 1;
}

int query_str() { return Str+strtmp+strbon; }
int query_int() { return Int+inttmp+intbon; }
int query_dex() { return Dex+dextmp+dexbon; }
int query_wis() { return Wis+wistmp+wisbon; }
int query_con() { return Con+contmp+conbon; }
int query_cha() { return Cha+chatmp+chabon; }

int query_real_str() { return Str; }
int query_real_int() { return Int; }
int query_real_dex() { return Dex; }
int query_real_wis() { return Wis; }
int query_real_con() { return Con; }
int query_real_cha() { return Cha; }

int query_tmp_str() { return strtmp; }
int query_tmp_int() { return inttmp; }
int query_tmp_dex() { return dextmp; }
int query_tmp_wis() { return wistmp; }
int query_tmp_con() { return contmp; }
int query_tmp_cha() { return chatmp; }

int query_bonus_str() { return strbon; }
int query_bonus_int() { return intbon; }
int query_bonus_dex() { return dexbon; }
int query_bonus_wis() { return wisbon; }
int query_bonus_con() { return conbon; }
int query_bonus_cha() { return chabon; }

int adjust_dex(int i) {
  Dex += i;
  return Dex;
}

int adjust_con(int i) {
  Con += i;
  reset_hp();
  return Con;
}

int adjust_str(int i) {
  Str += i;
  reset_carry_cap();
  return Str;
}

int adjust_wis(int i) {
  Wis += i;
  reset_gp();
  return Wis;
}

int adjust_int(int i) {
  Int += i;
  reset_gp();
  return Int;
}

int adjust_cha(int i) {
  Cha += i;
  return Cha;
}

int adjust_tmp_int(int i) {
  inttmp += i;
  reset_gp();
  return inttmp;
}

int adjust_tmp_dex(int i) {
  dextmp += i;
  return dextmp;
}

int adjust_tmp_wis(int i) {
  wistmp += i;
  reset_gp();
  return wistmp;
}

int adjust_tmp_str(int i) {
  strtmp += i;
  reset_carry_cap();
  return strtmp;
}

int adjust_tmp_con(int i) {
  contmp += i;
  reset_hp();
  return contmp;
}

int adjust_tmp_cha(int i) {
  chatmp += i;
  return chatmp;
}

int adjust_bonus_int(int i) {
  intbon += i;
  reset_gp();
  return intbon;
}

int adjust_bonus_dex(int i) {
  dexbon += i;
  return dexbon;
}

int adjust_bonus_wis(int i) {
  wisbon += i;
  reset_gp();
  return wisbon;
}

int adjust_bonus_str(int i) {
  strbon += i;
  reset_carry_cap();
  return strbon;
}

int adjust_bonus_con(int i) {
  conbon += i;
  reset_hp();
  return conbon;
}

int adjust_bonus_cha(int i) {
  chabon += i;
  return chabon;
}

void update_tmps() {
  if ( (strtmp||contmp||wistmp||inttmp||dextmp) !=0)
   	write("You feel your abilities become somewhat more normal \n");

  strtmp = strtmp/2;
  contmp = contmp/2;
  wistmp = wistmp/2;
  inttmp = inttmp/2;
  dextmp = dextmp/2;
  reset_hp();
  reset_gp();
  reset_carry_cap();
}

string stat_string(int i) {
  if (i<19)
    return i +"";
  if (i>28)
    return i-10+"";
  if (i==28)
    return "18/00";
  return "18/"+(i-18)+"0";
}

/* Add of Sojans code to get the new combat system working */

void set_extra_bonus(string type, int exbon)
{
  switch (type)
  {
    case "attack" :
      extra_attack_bonus=exbon;
    case "defend" :
      extra_defend_bonus=exbon;
    default : 0;
  }
} /* set extra_bonus */

int extra_bonus(string type)
{
  switch (type)
  {
    case "attack" :
      return extra_attack_bonus;
    case "defend" :
      return extra_defend_bonus;
    default :
      return 0;
  }
} /* extra_bonus */

int query_thac0()
{
  /* calculate thac0 here I don't know how so for now return 10 */
  /* Will be a table in guild.c i guess. It just varies from guild to
   * guild. Base THAC0 is 22, and 20 if the player has a proficiency.
   * Baldy.. */
  return 20;
} /* query_thac0 */

void set_magical(int mnm)
{
  magical=mnm;
} /* set magical */

int query_magical()
{
  return magical;
} /* query_magical */

void set_ac(int bing)
{
  ac=bing;
}

int query_ac()
{
  return ac;
}

void adjust_ac(int bing)
{
  ac=ac+bing;
}
