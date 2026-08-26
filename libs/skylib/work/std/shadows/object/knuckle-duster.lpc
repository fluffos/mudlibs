inherit "/std/effect_shadow";

int modify_damage(int damage, string attack_name) {
    int mod_damage = damage*1.3;

    if (attack_name == "hands")
        return mod_damage;
    return damage;
}

int query_skill_bonus(string skill, int true) {
    int value;

    if (true)
        return player->query_skill_bonus(skill, true);

    switch( skill ){
      case "fighting.combat.melee.pierce":
        value = player->query_skill_bonus(skill, true)*0.90;
        return value;
        break;
      case "fighting.combat.melee.sharp":
      case "fighting.combat.melee.blunt":
        value = player->query_skill_bonus(skill, true)*0.85;
        return value;
        break;
      case "fighting.combat.range.thrown":
        value = player->query_skill_bonus(skill, true)*0.80;
        return value;
        break;
      case "fighting.combat.range.fired":
        value = player->query_skill_bonus(skill, true)*0.75;
        return value;
        break;
      default:
        value = player->query_skill_bonus(skill, true);
        return value;
    }
}

void dest_knuckle_effect() {
    remove_this_effect();
}

