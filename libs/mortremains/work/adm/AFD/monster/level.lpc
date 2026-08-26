void set_level(int lvl) {
  level=lvl;
  set("level", lvl);
  set("stat/strength",level);
  set("stat/intelligence",level);
  set("stat/constitution",level);
  set("stat/dexterity",level); 
  if (lvl > sizeof(STAT))
    lvl = sizeof(STAT);
  else if (lvl < 1)
    lvl = 1;
  lvl--;
  set("hit_points",STAT[lvl][0]);
  set("max_hp",query("hit_points"));
  set("spell_points",query("hit_points"));
  set("max_sp",query("hit_points"));
  set("attack_strength",STAT[lvl][1]);
  set("armor_class",STAT[lvl][2]);
  set("spell_chance",STAT[lvl][3]);
  set("mon_spell_dam",STAT[lvl][4]);
  set("spell_mess1",SPELL_MSG[0]);
  set("spell_mess2",SPELL_MSG[1]);
  if(level>1)
    experience=GUILD_D->query_xp_for_next(level-1);
  else
    experience=random(100);
   add_exp(experience);
}
