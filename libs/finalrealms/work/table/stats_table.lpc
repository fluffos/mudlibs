// Taniwha 1995. to make good dex fair AC.
#define AC_MULT 2

/* Stats table.
 * here goes all tables for a players stats. 
 * Easier to maintain.
 * Baldrick, june '94
 * 
 * Now including: 
 * hp_bonus, tohit bonus, damage bonus and body ac.
 */

/* Calculate the Constitution bonus.. */
int calc_hp_bonus(int e)
  {
  int hp_bonus;

  switch (e)
    {
    case 1:        hp_bonus = -3; break;
    case 2 .. 3:   hp_bonus = -2; break;
    case 4 .. 6:   hp_bonus = -1; break;
    case 7 .. 14:  hp_bonus = 0; break;
    case 15:       hp_bonus = 1; break;
    case 16:       hp_bonus = 2; break;
    case 17 .. 18: hp_bonus = 3; break;
    case 19 .. 40: hp_bonus = 4; break;
    default:       hp_bonus = -1; break;  
    } /* switch e */
  return hp_bonus;
}

/* Calculate the body_ac bonus the AD&D way.. */
int calc_body_ac(int e)
  {
  int body_ac_bon; 
  /* Hmm need a neato calc here..
   * this should probably be queried against guild.c */
  switch (e)
    {
    case 1 .. 2: 
     body_ac_bon = -20;
     break;
    case 3:
     body_ac_bon = -15;
     break;
    case 4:
     body_ac_bon = -10;
     break;
    case 5:
     body_ac_bon = -5;
     break;
    case 6:
      body_ac_bon = -2;
      break;
    /* Can use a smarter way with base 100.. */
    case 7 .. 100:
      body_ac_bon = e * AC_MULT;
      break;
    default: 
      body_ac_bon = 0;
      break;
    } /* switch */
  return body_ac_bon;
}

int calc_damage_bonus(int e)
  {
  int damage_bonus;

  switch (e)
    {
    case 1:
      damage_bonus = -4;
      break;
    case 2:
      damage_bonus = -2;
      break;
    case 3 .. 5:
      damage_bonus = -1;
      break;
    case 6 .. 15:
      damage_bonus = 0;
      break;
    case 16:
      damage_bonus = 1;
      break;
    case 17: 
      damage_bonus = 1;
      break;
    case 18:
      damage_bonus = 2;
      break;
    case 19 .. 25:
      damage_bonus = 3;
      break;
    case 26 .. 27:
      damage_bonus = 4;
      break;
    case 28 .. 100:
      damage_bonus = 5;
      break;
    default:
      damage_bonus = 0;
      break;
    } /* switch e */
  return damage_bonus;
} /* void calc damage bonus */

int calc_tohit_bonus(int e)
  {
  int tohit_bonus;

  switch (e)
    {
   case 1:
     tohit_bonus = -5;
     break;
   case 2 .. 3:
     tohit_bonus = -3;
     break;
   case 4 .. 5 :
     tohit_bonus = -2;
     break;
   case 6 .. 7:
     tohit_bonus = -1;
     break;
   case 8 .. 16:
     tohit_bonus = 0;
     break;
   case 17:
     tohit_bonus = 1;
     break;
   case 18 .. 23:
     tohit_bonus = 1;
     break;
   case 24 .. 27:
     tohit_bonus = 2;
     break;
   case 28 .. 100:
     tohit_bonus = 3;
     break;
   default:
     tohit_bonus = 0;
     break;
    } /* Switch e */
  return tohit_bonus;
}
