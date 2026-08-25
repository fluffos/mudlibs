/* unarmed combat handler .....
   this handler allows you to set the base damage of each style of
   unarmed combat ...
   you can also define new combat styles by selecting the attacks
   that make them up from the list of defined attacks+messages 
   defined in unarmed_combat.h ..
   Thinking about it it might be more memory efficient to store
   the standard attacks in this object but in doing so we'd probably
   slow things down by calling out of the player object all the time.
 Coded by Sojan, Extensively reworked by Timion.
*/
/* Baldricks verdict:
 * Looking really good, we just have to make the attack and damage routines
 * work the same way as the weapon_logic. 
 * (here it is only the damage return that is calculated)
 */

//save file
#define SAVEFILE "/save/unarmed_combat_handler"

mapping unarmed_combat_styles;

create()
{
  seteuid("Room");
  unarmed_combat_styles=([ "brawling" : ({ 1, 3, ({ "punch", "kick", "headbutt", "knee" }) }) ]);
  restore_object(SAVEFILE);
}

void add_uc_style(string name, int num_dice, int dam_die, string *moves)
{
  unarmed_combat_styles+=([ name : ({ num_dice, dam_die, moves }) ]);
  save_object(SAVEFILE);
}

void remove_uc_style(string name)
{
  map_delete(unarmed_combat_styles, name);
  save_object(SAVEFILE);
}

/* Thi shas to be redone, to take into consideration the different bonuses and
 * such.
 */

int unarmed_damage(string style, int num, int type)
{
  int res;
  int lvl;
  if(num>0 && type>0)
    res=roll(num, type);
  else
  res=roll(unarmed_combat_styles[style][0], unarmed_combat_styles[style][1]);
/*
  lvl = ( this_object()->query_level() +1 ) ;
  if (lvl>num) 
    lvl = num;
  res = roll (1, (lvl + this_player()->query_damage_bonus()) );
*/
  return res;
}

int query_valid_attack(string attack, string style)
{
  if(member_array(attack, unarmed_combat_styles[style][2])>-1)
    return 1;
  return 0;
}

string *query_unarmed_styles()
{
  return keys(unarmed_combat_styles);
}

mapping query_all_uc_info()
{
  return unarmed_combat_styles;
}
