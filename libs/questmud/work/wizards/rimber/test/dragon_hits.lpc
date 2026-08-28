void fire_breath(object drg) {
  int dama = 66 + random(51) + random(drg->query_str()) - drg->query_attacker()->fire_resists("fire");
 say("Dragon inhales deeply and exhales a red fire burst over "+drg->query_attack()->query_name()+".\n");
 drg->query_attack()->hit_with_spell((dama), "fire");
 say("Dragon did "+dama+"\n");
}

void claw_scratch(object drg) {
 int dama = drg->query_str()/2 + drg->query_dex()/3;
 say("Dragon rises its claw and strucks it forcefully deep into "+drg->query_attack()->query_name()+"'s flesh.\n");
 drg->query_attack()->hit_with_spell(dama, "physical");
 say("Dragon did "+dama+" damage.\n");
}

void fire_blast(object drg) {
 int dama = random(51)+drg->query_int() + (drg->query_str()/4);
 say("Dragon rises its head high and inhales deeply and exhales huge burst of fire making pool of fire.\n");
 drg->query_attack()->hit_with_spell(dama, "fire");
 say("Dragon did "+dama+" damage.\n");
}
