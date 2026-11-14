/* weap_cfg.c

  loads weapon config file to restrict classes to particular weapons
 */

#define WEAPON_CFG "/include/skills/weapon.dat"
#define CONFIG_OB  "function/config"

mixed *allowed_weapons;  

void load_allowed_weapons() {
  allowed_weapons = (mixed *)call_other(CONFIG_OB,"load_file",WEAPON_CFG);
}

mixed *query_allowed_weapons() { 
  if(!allowed_weapons) load_allowed_weapons();
  return allowed_weapons;
}


status allowed_weapon(object who, string weapon_name) {
  string *classes, fail;
  int i, k;

  if(!allowed_weapons) load_allowed_weapons();
  if(!who) return 0;
  classes = (string *)who->query_classes();
  if(!classes) return 1;
  for(fail = "", i = sizeof(classes); i--; ) {
    if((k = member_array(classes[i],allowed_weapons)) != -1) {
      if(sizeof(allowed_weapons[k+1]) != 2) {
        log_file("WEAPONS","Error: Config File Corrupt at field "+ i +"\n");
        continue;
      }
      if(member_array(weapon_name, allowed_weapons[k+1][0]) != -1
      || member_array("all", allowed_weapons[k+1][0]) != -1) {
        return 1;
      }
      else if(fail == "") {
        fail = allowed_weapons[k+1][1];
      }
    }
  }
  if(fail == "") {
    log_file("WEAPONS","Unknown weapon type: "+ 
                       file_name(previous_object()) 
                      +"\n\tClasses: ");
    for(i = sizeof(classes); i--; ) {
      log_file("WEAPONS", classes[i] +" ");
    }
    log_file("WEAPONS","\n\n");
  }
  tell_object(who, fail);
  return 0;
}
