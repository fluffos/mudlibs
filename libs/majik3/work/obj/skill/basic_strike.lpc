inherit "obj/skill/obj/maneuver";
#define TPOS (target->query_possessive())
#define TOBJ (target->query_objective())
#define TPRO (target->query_pronoun())
#define TNAME (target->query_cap_name())
#define APOS (attacker->query_possessive())
#define AOBJ (attacker->query_objective())
#define APRO (attacker->query_pronoun())
#define ANAME (attacker->query_cap_name())

create_skill()
{
	set_skill_name("basic strike");
	set_train_difficulty(8);  // Easy skill, combat
	set_base_percent(20);
	add_base_stat("str",30);  // Total of Base Stats is 100
	add_base_stat("siz",30);
	add_base_stat("agi",30);
	add_base_stat("int",10);
	set_parent_skill("weapons");
	set_weapon_types(({"dagger","axe","mace","sword"}));
	set_damage(2);           	// The rules for battle attributes are found from
	set_defense(-1);		// doc/misc/battle_attribute.txt
	set_protection(-1);
	set_fatique(-1);
	set_offense(1);
	set_speed(5);
}

void do_combat_msg(object attacker, object target)
{
	if(random(5)||!attacker||!target)
		return;
	if(target->query_is_unconscious())
		return;
	tell_room(environment(attacker),
		ANAME+" holds "+APOS+" weapon above his head and gathers courage to attack "+
		TNAME+"!\n",
	    	({attacker, target}));
	tell_object(attacker,
		"You prepare to strike "+TNAME+"!\n");
	tell_object(target,
		ANAME+" holds "+APOS+" weapon high above "+APOS+
			" head and is ready to strike you!\n");
	return;
}

void do_maneuver_msg(object target, object attacker, object weapon,
  string location, int offres, int defres, int dmgres, int hitres, int parres)
{
  string off1, off2, off3;
  string def1, def2, def3;
  string par1, par2, par3, tmp, tmp2;
  string msg1, msg2, msg3;
  
  location=handle_location(location, target);
  if(target->query_is_unconscious())
    {
      tell_room(environment(attacker),
		ANAME+" strikes unconscious "+TNAME+" with "+
		APOS+" "+weapon->short()+" to "+location+"! ",
		({attacker, target}));
      tell_object(attacker,
		  "You strike "+TNAME+" as hard as you can. You hit "+
		  TPOS+" "+location+"! ");
      tell_object(target,
		  "Someone strikes you hard to "+location+"! ");
      return;
    }
  if(offres<1)
    {
      off1=ANAME+" fumbles around with "+APOS+" "+weapon->short()+". ";
      off2="You almost hit yourself with your "+weapon->short()+". ";
      off3=ANAME+" is doing some fancy feinting maneuvers";
      if(random(3))
	off3+=". ";
      else
	off3+=" and almost drops "+APOS+" weapon! ";
    }
  else
    {
      off1=ANAME+" strikes with "+APOS+" "+weapon->short()+"! ";
      off2="You try to hit "+TNAME+" with your "+weapon->short()+"! ";
      off3=ANAME+" tries to hit you with "+APOS+" "+weapon->short()+"! ";
    }
  if(defres<1&&hitres<1)
    {
      def1=TNAME+" leaps to a very surprising direction - towards "+
	ANAME+"'s weapon and avoids being hit! ";
      def2=TNAME+" leaps towards you making you miss your swing! ";
      def3="You totally mistime your dodge and leap towards "+
	ANAME+" when "+APRO+" strikes! Fortunately "+
	APRO+" is at least as surprised as you are and misses! ";
    }
  else
    if(defres<1&&hitres>0)
      {
	def1=TNAME+" leaps in front of "+ANAME+"'s swing! ";
	def2=TNAME+" leaps in front of your swing! Yeah! ";
	def3="You totally mistime your dodge and leap in front of "+
	  ANAME+"'s swing! ";
      }
    else
      if(defres>0&&hitres<1)
	{
	  def1=TNAME+" sidesteps "+TNAME+"'s attack! ";
	  def2=TNAME+" quickly steps to a side and you miss "+TOBJ+"! ";
	  def3="You just barely manage to sidestep "+ANAME+"'s swing! ";
	}
      else
	{
	  def1=TNAME+" tries to sidestep "+TNAME+" swing but "+
	    ANAME+" is too quick for "+TOBJ+"! ";
	  def2=TNAME+" sidesteps but you are ready and manage to turn your "+
	    weapon->short()+" and hit "+TOBJ+"! ";
	  def3="You grin and sidestep "+TNAME+"'s attack but are hit anyway! ";
	}
  if(parres<1)
    {
      par1=TNAME+"'s parry is a futile attempt to stop "+
	ANAME+"'s "+weapon->short()+". ";
      par2=TNAME+"'s parry is way too slow for you. ";
      par3="You try to parry but in vain!";
    }
  else
    {
      switch (parres)
	{
	case 1..20:
	  tmp="a bit.";
	  break;
	case 21..40:
	  tmp="a little.";
	  break;
	case 41..60:
	  tmp="somewhat.";
	  break;
	case 61..80:
	  tmp="much.";
	  break;
	case 81..100:
	  tmp="really much";
	  break;
	case 101..120:
	  tmp="almost all";
	  break;
	}
      switch (dmgres)
	{
	case 1..3:
	  tmp2="before it touches "+TPOS+" "+location+".";
	  break;
	case 4..6:
	  tmp2="before it hits "+TPOS+" "+location+" weakly.";
	  break;
	case 7..10:
	  tmp2="but "+ANAME+"'s strike still hits "+TPOS+
	    " "+location+" quite nastily!";
	  break;
	case 11..15:
	  tmp2="but "+TNAME+"'s location still receives a "+
	    "really nasty hit!";
	  break;
	case 16..25:
	  tmp2="but it still connects hard with "+TPOS+
	    " "+location+"!";
	  break;
	case 26..50:
	  tmp2="but the attack still makes "+TOBJ+" yell from pain!";
	  break;
	default:
	  tmp2="but the attack still breaks bones!";
	  break;
	}
      /* before 'it hits TNAME's location how' */
      par1=TNAME+" manages to parry "+tmp+" of "+ANAME+"'s attack "+
	"before "+tmp2;
      par2=TNAME+" manages to parry "+tmp+" of your attack "+
	tmp2;
      par3="You manage to parry "+tmp+" of "+ANAME+"'s attack "+
	tmp2;
    }
  if(hitres>0)
    {
      msg1=off1+def1+par1;
      msg2=off2+def2+par2;
      msg3=off3+def3+par3;
    }
  else
    {
      msg1=off1+def1;
      msg2=off2+def2;
      msg3=off3+def3;
    }
  tell_room(environment(attacker),
	    sprintf("%-=60s",msg1)+"\n", ({attacker, target}));
  tell_object(attacker, sprintf("%-=60s",msg2)+"\n");
  tell_object(target, sprintf("%-=60s",msg3)+"\n");
  return;
}

