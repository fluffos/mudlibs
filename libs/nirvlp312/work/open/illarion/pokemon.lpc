inherit "/obj/monster";
#include "/players/illarion/dfns.h"

int spchance;
mapping spells;
string *spell_list;

void add_spell(string name,string damage,string mess_target,string mess_room) {
  if(!spell_list) spell_list=({});
  if(!spells) spells=([]);
  spell_list+=({name});
  spells+=([name:({damage,mess_target,mess_room})]);
}
void set_spchance(int x) {
  spchance=x;
}
attack() {
  if(attacker_ob && present(attacker_ob,environment()) && random(100)<spchance) {
    string spname;
    spname=spell_list[random(sizeof(spell_list))];
    tell_object(attacker_ob,format(spells[spname][1]));
    tell_room(environment(),format(spells[spname][2]),({attacker_ob}));
    attacker_ob->hit_player(random(spells[spname][0]));
  }
  ::attack();
}
void create(int lev) {
  set_level(lev);
  set_wc(GUIDE->wc_guide(lev));
  set_ac(GUIDE->ac_guide(lev));
  set_hp(GUIDE->hp_guide(lev));
  add_money(GUIDE->gold_guide(lev));
}
