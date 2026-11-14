/*
 * secure/combat.c
 *
 * the combat master object. It defines some useful functions to be
 * used by weapons, armour and livings.
 */
#pragma strict_types
#pragma no_clone
#pragma no_shadow
#pragma verbose_errors
#pragma combine_strings
#pragma warn_deprecated
 
#include <combat.h>
 
int default_weapon_class(string type) {
 	switch(type) {
		 case "knife":
			 return 50;
		 case "club":
			 return 70;
		 case "sword":
			 return 100;
		 case "axe":
			 return 90;
	 }
	 return 30;
}
 
int default_weapon_weight(string type) {
	 switch(type) {
		 case "knife":
			 return 100;
		 case "club":
			 return 1500;
		 case "sword":
			 return 2000;
		 case "axe":
			 return 1500;
	 }
	 return 1000;
}
 
int default_weapon_value(string type) {
	 switch(type) {
		 case "knife":
			 return 10;
		 case "club":
			 return 50;
		 case "sword":
			 return 500;
		 case "axe":
			 return 300;
	 }
	 return(0);
}
 
int valid_weapon_type(mixed t) {
	 if (VALID_WEAPON_TYPE(t)) {
		  return 1;
	 }
	 else {
		 log_file("COMBAT","Invalid weapon type: "+t+", object: "+
				 object_name(previous_object())+"\n");
		 return 0;
	 }
}
 
 
int valid_armour_type(mixed t) {
	 if (VALID_ARMOUR_TYPE(t)) {
		  return 1;
	 }
	 else {
		 log_file("COMBAT","Invalid armour type: "+t+", object: "+
				 object_name(previous_object())+"\n");
		 return 0;
	 }
}
 
 
int query_prevent_shadow() { return 1; }
 
 