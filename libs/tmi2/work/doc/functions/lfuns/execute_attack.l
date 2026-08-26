
EXECUTE_ATTACK(L)       LOCAL FUNCTIONS         EXECUTE_ATTACK(L)

NAME
     execute_attack() - make a single  meelee  attack  against  a
     target.

SYNOPSIS
     varargs  private  void   execute_attack(int   hit_mod,   int
     dam_mod) ;

DESCRIPTION
     The execute_attack() lfun is defined in all body objects. It
     is  called  from the continue_attack() lfun, when the object
     decides that it is going to make a  meelee  attack  in  this
     round.  Each body keeps a list of attackers in its data; the
     object at the top of this list is automatically selected for
     attack.  First,  the function chooses a weapon to use in the
     attack, and queries the attacker for skills,  strength,  and
     damage.  Second, the function queries the defender for armor
     rating and dexterity. Using these numbers, the function cal-
     culates  the  the  hit_chance  and the amount of damage that
     will be done by the attack if it succeeds.  It  then  allows
     the  skills  of  the  attacker  and  defender  to improve if
     needed, and prints the approprriate message. If  the  attack
     fails to hit, or if the damage done is less than zero due to
     defensive modifications by the armor of the defender, the  a
     miss message is printed. Otherwise a message that depends on
     the amount of damage done is printed.   The  excute_attack()
     lfun  can  take two option arguments which are a modifier to
     the hit roll and the damage roll respectively. These can  be
     used   to  implement  special  attacks  such  as  backstabs,
     although since continue_attack does not use these  arguments
     such  special  attacks  must  be  implemented by calling the
     execute_attack()     lfun     directly.      Because     the
     execute_attack()  lfun  is  defined seperately in each body,
     you can give different combat formulas,  or  skill  improve-
     ments,  or damage rolls or messages, or anything you like to
     different bodies.  Bodies which do  not  engage  in  combat,
     such  as  the  ghost  body, do not need to define this lfun,
     although they may want to just  in  case  execute_attack  is
     somehow directly called. A simple message such as "Your body
     does not respond to your will" is  probably  sufficient  for
     most cases.

SEE ALSO
     continue_attack(),  receive_damage(),  clean_up_attackers(),
     /std/user.c, /std/monster.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

