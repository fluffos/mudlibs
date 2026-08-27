/*** Drow Warrior Dark Globe***/
/* Taniwha 1995 */
/*** level 5 ***/
#define GP_COST 2
#define LEV 5
#define GLOBE_LOCK 200

string help() {
   return
   "\n\n"
   "Dark Globe\n"
   "Level: "+LEV+"\n"
   "Gp Cost: "+GP_COST+"\n"
   "Description: \n"
   "    This is an innate Drow Warrior ability to create an aura "
   "of darkness, or to darken a room. (dark globe here) "
   "The skill can only be used occasionally, but lasts until the target "
   "logs off. In the case of rooms, it will be very erratic if cast outside. "
   "The strength of dark globe increases with level."
    "\n\n";
}
int dark_globe(string str,object cast)
{
 object target;
 object caster;
 object *olist;
 caster = cast ? cast : this_player();
 if(interactive(caster))
	 str = (string)caster->expand_nickname(str);
 if( (caster->query_level() < LEV) || caster->query_property("dark globe") || (caster->query_gp() < GP_COST))
 {
    tell_object(caster,"You can't seem to work up the bad attitude required "
    "to create the dark aura.\n");
    return 1;
 }
 caster->add_timed_property("dark globe",1,GLOBE_LOCK);
 tell_object(caster,"Rage builds within you as you contemplate those who exiled you to the underdark and revile their names.\n");
 tell_room(environment(caster),caster->query_cap_name()+
 "'s features darken and a flush of rage crosses "+
 caster->query_possessive()+" face."
   "\n",({ caster }) );
 if(!str || str =="") target = caster;
 else if(str == "here") target = environment(caster);
 else
 {
    olist = find_match(str,environment(caster));
    if(sizeof(olist)) target = olist[0];
    else target = caster;
 }
 target->adjust_light(-(10+(int)caster->query_level()/2));
   caster->adjust_gp(-GP_COST);
 return 1;
}

