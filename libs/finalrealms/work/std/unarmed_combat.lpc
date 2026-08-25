
#include "unarmed_combat.h"

/*
    Unarmed Combat for FR by Sojan
    Currently unlobotomised/castrated by Baldrick :)
    (sorry B)

    * On my way... Baldrick. June '94

    Ummm this is designed to be as similar to the weapon_logic
    as I could get it ... there are a few notable differences
    but not enough to be significant ..
    Okay due to current problems the unarmed/armed combat
    is gonna yield the same actual combat result ....
    damage will still be better for martial arts than for
    standard brawling though ......
    Oh - also most of the stuff in this file will come from
    an include file cause this doesn't rely on different weapons
    classes and stuff ... bingles ...
*/

/* Ok, slaughtering started.
 * The extra_bonus("attack" & "defend" should not be nessesary, it is
 * tohit_bonus and body_ac_bonus thingie..
 */

nosave int ovr_num,
           ovr_type;
nosave object defender,
              attacker;

string *known_unarmed_styles,
        current_unarmed_style;


/* Hmm, I'll do it the same way as weapon_logic.. Baldrick. */
//int unarmed_attack(object att, object def);
int unarmed_attack(object def, object att);

/* This is wrong too I think.. should make the att / defdr thing a
 * standard! Hmm... maybe it is? this is starting to be a mess..:=)
 */
void write_message(int damage, string attack_style, object att, object defdr);
void apply_damage(int hps, object att);
mixed *workout_attack(string unarmed_type);
void unarmed_combat_commands();
int set_unarmed_combat_style(string style);
int add_known_unarmed_style(string style);
int remove_known_unarmed_style(string style);
string *query_known_unarmed_combat_styles();
mapping valid_attack();

void create()
{
  ovr_num=0;
  ovr_type=0;
  known_unarmed_styles=({ "brawling" });
  current_unarmed_style="brawling";
}

int unarmed_attack(object def, object att)
{
  mixed *att_val;
  attacker=att;
  defender=def;
  att_val=({ });
  att_val=workout_attack(current_unarmed_style);
  if(att_val[0]=="hit")
    apply_damage((int)att_val[1], attacker);
  write_message((int)att_val[1], current_unarmed_style, attacker, defender);
  return att_val[1];
} /* unarmed_attack */

mixed *workout_attack(string unarmed_type)
{
  string happen;
  int tmproll, result, achit, defenderac, damage_done, THAC0;

  THAC0=(int)attacker->query_thac0();
  tmproll=roll(1,200);
  // Taniwha 1995, LUCK factor
  if(tmproll < defender->query_cha() )
    return ({ "fumble", 0});

  /* This is the way it is done everywhere else.. */
  achit = ((THAC0 - (int)attacker->query_tohit_bonus()) - tmproll);
  defenderac = (int)defender->query_total_ac();

  result = (achit - defenderac);

  if (result < 1)
  {
      happen = "hit";
      if(member_array(unarmed_type, known_unarmed_styles)>-1)
      damage_done=(int)UNARMED_BASE->
                   unarmed_damage(unarmed_type, ovr_num, ovr_type) +
                   (int)attacker->query_damage_bonus();
      else
        damage_done=roll(BDEFNUM, BDEFTYPE);
      // Taniwha 1995, critical hit, luck based
      if( random(200) < attacker->query_cha() ) damage_done *= 2;
  }
  else
  {
      happen = "miss";
      damage_done = 0;
  }

  return ({ happen, damage_done });
} /* workout_attack */

int set_unarmed_combat_style(string style)
{
  if(member_array(style, known_unarmed_styles)>-1)
  {
      current_unarmed_style=style;
      write("Unarmed Combat Style set to : "+style+"\n");
      return 1;
  }
  notify_fail("You do not know : "+style+"\n");
  return 0;
}

int add_known_unarmed_style(string style)
{
  if(!style) return 0;
  known_unarmed_styles+=({ style });
  return 1;
}

int remove_known_unarmed_style(string style)
{
  if(!style) return 0;
  known_unarmed_styles=filter_array(known_unarmed_styles, "delarit", this_object(), style);
  return 1;
}

int delarit(string bongle, string style)
{
  if(bongle==style) return 1;
  return 0;
}

void unarmed_combat_commands()
{
  add_action("set_unarmed_combat_style", "unarmed");
}

string query_current_unarmed_style()
{
  return current_unarmed_style;
}

/* This needs the attacker's object too.. */
void apply_damage(int hps, object att)
{
  if(hps<0) hps=0;
  /* taniwha, was attacker here, God knows ;) who that was */
  defender->adjust_hp(-hps, att);
  return;
}


//okay super complicated write_message handling system ...
//its designed to give varying messages depending on what messages
//are registered as valid with the unarmed combat base style handling
//system - see that for more details .......


void write_message(int damage, string attack_style, object att, object defdr)
{
  string *vatts;
  int i;
  mapping va_all;
  string *va_keys;
  vatts=({ });

  tell_object(att, "You do " + damage + " hp's unarmed damage.\n");
  tell_object(defdr, "You get " + damage + " hp's unarmed damage.\n");

  va_all = valid_attack();
  va_keys = keys(va_all);

  for(i=0;i<sizeof(va_keys);i++)
  if (UNARMED_BASE->query_valid_attack(va_keys[i], attack_style))
    vatts += ({ va_keys[i] });

  i=random(sizeof(vatts));

  tell_room(environment(attacker),
    va_all[vatts[i]][0], ({attacker, defender}));
  tell_object(attacker, va_all[vatts[i]][1]);
  tell_object(defender, va_all[vatts[i]][2]);
}


mapping valid_attack()
{
  int bing, bong;
  bing=random(3);
  bong=random(2);
  return ([
        "punch" : ({ AN+" punches "+DN+" in the "+({ "stomach", "face", "solar plexus"})[bing]+".\n",
                     "You punch "+DN+" in the "+({ "stomach", "face", "solar plexus"})[bing]+".\n",
                     AN+" punches you in the "+({ "stomach", "face", "solar plexus"})[bing]+".\n" }),
        "rapid" : ({ AN+" rapidly punches "+DN+" in the "+({ "stomach", "face", "solar plexus"})[bing]+".\n",
                     "You rapidly punch "+DN+" in the "+({ "stomach", "face", "solar plexus"})[bing]+".\n",
                     AN+" rapidly punches you in the "+({ "stomach", "face", "solar plexus"})[bing]+".\n" }),
        "kick" : ({ AN+" kicks "+DN+" in the "+({ "stomach", "groin", "shin"})[bing]+".\n",
                     "You kick "+DN+" in the "+({ "stomach", "groin", "shin"})[bing]+".\n",
                     AN+" kicks you in the "+({ "stomach", "groin", "shin"})[bing]+".\n" }),
        "spinkick" : ({ AN+" spin kicks "+DN+" in the "+({ "side of the head", "neck", "chest"})[bing]+".\n",
                     "You spin kick "+DN+" in the "+({ "side of the head", "neck", "chest"})[bing]+".\n",
                     AN+" spin kicks you in the "+({ "side of the head", "neck", "chest"})[bing]+".\n" }),
        "chop" : ({ AN+" karate chops "+DN+" in the "+({ "side of the head", "throat", "chest"})[bing]+".\n",
                     "You karate chop "+DN+" in the "+({ "side of the head", "throat", "chest"})[bing]+".\n",
                     AN+" karate chops you in the "+({ "side of the head", "throat", "chest"})[bing]+".\n" }),
        "roundhouse" : ({ AN+" roundhouse kicks "+DN+" in the "+({ "side of the head", "face", "chest"})[bing]+".\n",
                     "You roundhouse kick "+DN+" in the "+({ "side of the head", "face", "chest"})[bing]+".\n",
                     AN+" roundhouse kicks you in the "+({ "side of the head", "face", "chest"})[bing]+".\n" }),
        "knee" : ({ AN+" knees "+DN+" in the "+({ "side", "groin"})[bong]+".\n",
                     "You knee "+DN+" in the "+({ "side", "groin"})[bong]+".\n",
                     AN+" knees you in the "+({ "side", "groin"})[bong]+".\n" }),
        "headbutt" : ({ AN+" headbutts "+DN+".\n",
                        "You headbutt "+DN+".\n",
                        AN+" headbutts you.\n" }),
        "footsweep" : ({ AN+" foot sweeps "+DN+".\n",
                        "You foot sweep "+DN+".\n",
                        AN+" foot sweeps you.\n" }),
         ]);
}





void set_damage_dice(int numdie, int dietype)
{
  if(numdie>0 && dietype>0)
  {
    ovr_num=numdie;
    ovr_type=dietype;
  }
  return;
}


