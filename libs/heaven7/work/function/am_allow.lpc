/* weap_cfg.c

  loads weapon config file to restrict classes to particular weapons
 */

#define ARMOUR_CFG "/include/skills/armour.dat"
#define CONFIG_OB  "function/config"

#define TYPE       0
#define ID         1
#define MATERIAL   2
#define FAIL       3
#define FIELDS     4



mixed *allowed_armour;  

void load_allowed_armour() {
  allowed_armour = (mixed *)call_other(CONFIG_OB,"load_file",ARMOUR_CFG);
}

mixed *query_allowed_armour() { 
  if(!allowed_armour) load_allowed_armour();
  return allowed_armour;
}


status allowed_armour(object who, string id, string type, string material) {
  string *classes, fail;
  mixed *data;
  int i, j, k;
  status flag;

  if(!allowed_armour) load_allowed_armour();
  if(!who) return 0;
  classes = (string *)who->query_classes();
  if(!classes) return 1;
  for(i = sizeof(classes); i--; ) {
    if((j = member_array(classes[i],allowed_armour)) != -1) {
      data = allowed_armour[j+1];
      for(flag = -1, k = 0; k < sizeof(data); k += FIELDS) {
	if(member_array(type, data[k + TYPE]) != -1) {
	  flag = 0;
	  if(member_array("NA", data[k + ID]) != -1) {
	    tell_object(who, data[k + FAIL]);
	    return 0;
	  }
	  if(member_array("ALL", data[k + ID]) != -1
	  || member_array(id, data[k + ID]) != -1) {
	    if(member_array(material, data[k + MATERIAL]) != -1
	    || member_array("ALL", data[k + MATERIAL]) != -1) {
	      break;
	    }
	  }  
	  flag = 1; /* not allowed */
	  fail = data[k + FAIL];
	}
      }
      if(flag ==  -1) {
        fail =  "Armour Config: Unknown Armour Type - "+type+".\n";
        log_file("ARMOUR", fail + file_name(previous_object()) +"\n\n");
      }
      if(flag) {
	tell_object(who, fail);
	return 0;
      }
    }
  }
  return 1;
}
