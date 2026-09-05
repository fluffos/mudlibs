/*************************************************************/
/* Will auto heal wearer if hps or sps get too low.          */
/* High ac, low weight, limited charges, non-storable        */
/* The only prize you get for killing Ani.                   */
/* Made storable by saving energy value. -Bp                 */
/*************************************************************/

inherit "obj/armor";
int nrgy;
string x;

reset(arg){
   ::reset(arg);
   set_name("cloak");
   set_short("The cloak of the Night Sky");
   set_type("misc");
   set_ac(1);
   set_weight(1);
   set_value(500);
/* see other note -Bp
   set_save_flag(1);
*/
   if(!nrgy)
   nrgy = 20+random(6);
}

long(){
  if(nrgy > 14)
	  x = "strong";
  else if(nrgy > 6)
	  x = "subtle";
  else if(nrgy > 0)
	  x = "weak";
  else
	  x = "soft";
  write(
"This beautiful black and blue cloak was once worn by the fabled woman\n"+
"known as Ani.  It is as light as a feather, and captivates you with its\n"+
"beauty.  A "+x+" aura of energy radiates from the cloak.\n");
}

do_special(owner)
{
  if(!owner || !owner->query_attack()) return 1;
  if(!owner->is_player()) return 1;
  if(owner->query_hp() < 100 && nrgy)
  {
    tell_object(owner, 
	    "Your cloak wraps you in an aura of healing!\n");
	tell_room(environment(owner), owner->query_name()+
		"is wrapped in an aura of healing!\n", ({ owner }));
    owner->add_hit_point(50);
	nrgy -=1;
	return 2;
  }
  else if(owner->query_sp() < 50 && nrgy)
  {
    tell_object(owner, 
	    "Your cloak wraps you in an aura of healing!\n");
	tell_room(environment(owner), owner->query_name()+
		"is wrapped in an aura of healing!\n", ({ owner }));
    owner->add_spell_point(50);
	nrgy -=1;
	return 2;
  }
  return 2; 
}
/* If we save the energy value, this cloak can be savable. -Bp */
locker_arg() {
  string blah;
  blah="--"+nrgy+"--";
  return blah;
 }
locker_init(arg) { 
  int blah;
  sscanf(arg,"--%d--",blah);
  nrgy = blah;
  }
generic_object() { return 1; }
restore_thing(str){
      restore_object(str);
      return 1;
   }
save_thing(str){
      save_object(str);
      return 1;
   }
