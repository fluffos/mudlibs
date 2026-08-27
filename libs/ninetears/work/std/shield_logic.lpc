
/*
   New weapon Logic by Sojan.  Designed to implement weapons in a such a way
   to make combat/weapons design as close as possible to the way it is
   implemented in the Rolemaster FRPG system.  Hopefully it should be
   easily modifiable to any other FRPG system as well.

   * Baldrick here, tuned it so that it works witth the new FR lib.
*/

/* AD&D rules:

   Base dice: 20
   The point is to hit a better AC then the opponents
   the hitter has a figure calle THAC0 (to hit AC 0). you throw the dice
   and the result is calculated this way:

   THAC0 - dice = AC to hit.

   This is the basic rule.
   the thac0 is based on levels and class. maybe we could calculate the AC hit
   i some other way, more close to what is done on DS. find

   Baldrick.

   Aug '95: chaned the basic AC/thaco from base-10/20 to base 100/200.
   Baldrick.
*/
/*
   To make coders feel at home with the old style I had to keep it as
   add_attack although I would have preferred to use setup_weapon - maybe
   I'll let add_attack be a mask to setup_weapon and then phase out add_attck
*/

/* Variable Declarations */

nosave object defender,
              attacker;

nosave int wm_flag;

string  weapon_table,
        weapon_skill,
        extra_code;

int magic_bonus,
    norm_bonus;

mixed *fumble_range;

/* end of declarations */

/* function prototypes */

void add_attack(string weapon_type, int nm_bonus, int m_bonus, string fn_code);

void setup_weapon(string weapon_type, string w_sk, int nm_bonus, int m_bonus, string fn_code);

int weapon_attack(object defdr, object atckr);

mixed *workout_attack();

int apply_damage(int hps) ;
mixed *weapon_stats();
mixed *stats();
void write_message(string happen, int damage, string w_type, object attr, object defdr);

/* end prototypes */

void create()
{
  /* doing nothing here atm */
} /* create */

void set_wm_flag(int j) { wm_flag=j; }
/* set_wm_flag */

void add_attack(string weapon_type, int nm_bonus, int m_bonus, string fn_code)
  {

  /* We have a problem here, weapon_skill will be used in the new setup_weapon
     but for compat reasons we can't have it here..
     What can we do ? */
//simple answer - make people still use add_attack and not setup_weapon()
//when using the standard weapon defs, and in the standard weapon_defs have
//them do the setup_weapon.

  /* STR is *not* the way to go.. */

  setup_weapon(weapon_type, "str", nm_bonus, m_bonus, fn_code);
} /* add_attack mask */

void setup_weapon(string weapon_type, string w_sk, int nm_bonus, int m_bonus, string fn_code)
{
  weapon_table=weapon_type;
  weapon_skill=w_sk;
  norm_bonus=nm_bonus;
  magic_bonus=m_bonus;
  extra_code=fn_code;
} /* setup_weapon */

/*
   brief explanation,
   weapon_type - the table the weapon is to look on for its damage results
   weapon_skill - The skill used to attack with the weapon
   nm_bonus - the normal combat bonus of the weapon (if any)
   m_bonus - the magical combat bonus of the weapon, at times this may
             be the only bonus availible to the wielder (when facing
             magical monsters for example)

        Either bonus may be used but they are not cumalative - normally the
        highest bonus will be used.
   fn_code  - the function called when an attack takes place.  This can be
              used to add extra or unusual effects in that are not catered
              for in the standard weapon code.
*/

int shield_attack(object defdr, object atckr)
{
  mixed *att_val;

  this_object()->set_wm_flag(0);

  defender=defdr;
  attacker=atckr;
  att_val=workout_attack();

//DEBUG LINE FOLLOWS
//   tell_object(attacker, sprintf("DEBUG: ATT_VAL=%O.\n", att_val));

/* Anyadido/modificado fumble_weapon - Tyrael(Alex) y cambiado su
   prototipo original, ahora recibe mas parametros */

// cuidado con esto, ya que los shields tb andaran por aqui
  if(att_val[0]=="fumble")
    return TO->fumble_weapon("weapon_table", attacker, defender);

  if(att_val[0]=="hit" || att_val[0]=="critical")
     if (!apply_damage(att_val[1])) // New by Tyrael - Jun'02
     	wm_flag = 1;

/* goes to damage resolution if result is a hit */

  if (extra_code)
    call_other(this_object(), extra_code);

/* okay if you don't want the write message routines to happen make sure
   the extra_code routines set flag to 1 ie. do this_object()->set_wm_flag(1)
   this routine resets its value to 0 when it starts execution. */

  if(wm_flag==0)
    // write_message(att_val[1], weapon_table, attacker, defender);
	// NUEVO write_message. EL PRIMER PARAMETRO ES "hit",
	// "fumble", "miss" o "critical" - Alex
/*    write_message(att_val[0], att_val[1], (string)this_object()->query_name(),
                  attacker, defender);*/
    write_message(att_val[0], att_val[1], TO->query_short(),
                  attacker, defender);

  return (int)att_val[1];
} /* weapon_attack */

int weapon_attack(object defdr, object atckr)
{
	TO->shield_attack(defdr, atckr);
}

/*
   Thats the main combat control routine
*/

/*
   Okay, actual routines to work it all out
*/

// Cambiado para permitir calcular_critico(danio, atakante, defensor)
// en las armas - Tyrael
// calcular_critico debe devolver un mixed * con el danyo final en
// el parametro [0] y el "happen" (critical o hit) en el [1].
mixed *workout_attack()
{
  int THAC0, bon, tmproll, result, achit, defenderac, damage_done;
  string happen;
  THAC0=attacker->query_thac0();

//DEBUG LINE FOLLOWS
//tell_object(attacker, sprintf("DEBUG: THAC0=%d.\n", THAC0));

   bon=norm_bonus;
   if(magic_bonus>norm_bonus || defender->query_magical())
     bon=magic_bonus;
/* this line makes sure of magical adders.  if the weapon has a normal adder
   then it is used but if it also has a magical adder which is greater then it uses
   that or it uses the magical adder in preference if a normall adder will not affect
   the creature being attacked.  As yet no provision for cursed weapons - this is
   coming */

   /* The arg for Roll is an int  */

//DEBUG LINE FOLLOWS
  tmproll = random(200) +1;
 //   tell_object(attacker, sprintf("DEBUG: Roll is %d.\n", tmproll));
    // Taniwha 1995, add luck

// AL TENER MAS CHA FALLAS MAS??? PERO ESTO KE ES? Alex

   if(tmproll <= defender->query_cha() )
     return ({ "fumble", 0});

   /* This is a long one, prolly split it up a bit.
    * trying to fix it, baldy.. */
   /* The bonus should ed as a subratcor tp the THAC0 */

   /* I am not quite sure what the weapon_attack want as the return value,
    * But the best would be: fumble, hit, or critical (roll = 20)
    */

    /* the AC the attacker will hit. */
  achit = ((THAC0 - bon - (int)attacker->query_tohit_bonus()) - tmproll);
  // Added a dual wield penalty, Wonderflug '95
  achit += attacker->query_dual_wield_penalty();

//DEBUG LINE FOLLOWS
    // tell_object(attacker, sprintf("DEBUG: achit = %d.\n", achit));

    /* The AC of the defender */
   defenderac = ((int)defender->query_total_ac() -
                (int)defender->extra_bonus("defend"));

   result = (achit - defenderac);

   /* here we will have calc_damage, or a call to it. */

   /* can use this as a quick lookup. */
   if (result < 1)
   {
     happen = "hit";
     damage_done = this_object()->query_damage_roll() +
                   (int)attacker->query_damage_bonus();
// Taniwha, make this equivalent to luck, this is == charisma 12 == 1 in 200
// Tyrael - Cambiado para permitir criticos de armas y mas y mas
	if (function_exists("calcular_critico", TO)) {
		mixed *critico;
		critico = TO->calcular_critico(damage_done, attacker, defender);
		damage_done = critico[0];
		happen = critico[1];
	}
	else if( random(600) < attacker->query_cha() ) {
		damage_done *= 2;
		happen = "critical";
	}
     }
   else
     {
     happen = "miss";
     damage_done = 0;
     }

   return ({ happen, damage_done, });

} /* workout_attack */

int fumble_weapon(string lookup_table, object atckr, object defdr)
{
  /* code for handling weapon fumble goes here */
// modificar para permitir que se caiga el arma, que se rompa, etc
// devolver siempre 0... no? xD
	if (!random(3)) {
	tell_room(ENV(atckr), atckr->QCN + " hace un mal movimiento y se da a si mismo.\n", atckr);
	tell_object(atckr, "Realmente un mal movimiento. Te das a ti mismo.\n");
	// mmm, no se si usar really_adjust_hp ...
	// o acabar poniendo una propiedad comprobable en really_adjust_hp
	// para que por ejemplo a un tio con pieles no le kite pero si a
	// uno con imagenes. - Tyrael
	atckr->adjust_hp(-random(TO->query_damage_roll())-1);
	}
	else {
	tell_room(ENV(atckr), atckr->QCN + " falla por completo su maniobra.\n", atckr);
	tell_object(atckr, "Fallas la maniobra y pierdes tu oportunidad.\n");
	}
  return 0;
} /* fumble_weapon */

/*
   Routines the attacker (or the attacking weapon) calls upon the defender
*/

// NEW by Tyrael - Jun'02
int apply_damage(int hps)
{
  return defender->adjust_hp(-hps, attacker);
} /* apply_damage */

/* Thats the end of those */

/* this function can stay because I like it */

/*
   The function to display the messages - called write_message cause I couldn't
   be bothered with thinking up a new name and it'll make people feel at home.
   what it does - well it receives the damage done and the weapon type and can
   then decide what sort of message to write depending on the severity of the
   attack and the type of weapon.  I guess we can add other parameters into
   this as time goes on.
*/

void write_message(string happen, int damage, string w_type, object attr, object defdr)
{
  /* Changed from the query_wearing_armour Sojan had to the one we
   * already have, query_equip_ac */

  // This looks a bit silly with the other stuff below as well. -A
  //  tell_object(attr, "You do " + damage + " HP's damage.\n");
  // tell_object(defdr, "You get " + damage + " HP's damage.\n");

  if (happen == "miss") {
      tell_room(environment(attr), defdr->query_cap_name()+" esquiva habilmente el ataque de "+
                attr->query_cap_name()+".\n",
                ({ attr, defdr }));
      tell_object(defdr, "* Esquivas habilmente el ataque de "+attr->query_cap_name()+".\n");
      tell_object(attr, "# "+defdr->query_cap_name()+" esquiva habilmente tu ataque.\n");
	return;
  }

  // Small recode by Aragorn to speed things up (and make the right messages)
  if ( damage<0)
  {
    if ( defdr->query_equip_ac() )
    {
      tell_room(environment(attr), attr->query_cap_name()+" hits "+
                defdr->query_cap_name()+"s armour harmlessly.\n",
                ({ attr, defdr }));
      tell_object(defdr, attr->query_cap_name()+" hits your armour with "+
                attr->query_possessive()+" "+w_type+".\n");
      tell_object(attr, "You hit "+defdr->query_cap_name()+"'s armour with no "
                 "effect.\n");
    }
    else
    {
      tell_room(environment(attr), attr->query_cap_name()+" hits "+
           defdr->query_cap_name()+" harmlessly.\n",
                ({ attr, defdr }));
      tell_object(defdr, attr->query_cap_name()+" hits you with "+
                attr->query_possessive()+" "+w_type+".\n");
      tell_object(attr, "You hit "+defdr->query_cap_name()+" with no "
                 "effect.\n");
    }
	/* A MI BOLA XD
      tell_room(environment(attr), defdr->query_cap_name()+" esquiva habilmente el ataque de "+
                attr->query_cap_name()+".\n",
                ({ attr, defdr }));
      tell_object(defdr, "* Esquivas habilmente el ataque de "+attr->query_cap_name()+".\n");
      tell_object(attr, "# "+defdr->query_cap_name()+" esquiva habilmente tu ataque.\n");
	*/
  }
  else if (damage == 0) {
      tell_room(environment(attr), defdr->query_cap_name()+" no recibe danyo cuando es golpeado por "+
                attr->query_cap_name()+".\n",
                ({ attr, defdr }));
      tell_object(defdr, "* No recibes danyo cuando "+attr->query_cap_name()+" te golpea.\n");
      tell_object(attr, "# "+defdr->query_cap_name()+" no recibe danyo cuando le golpeas.\n");
  }
  else if (damage < 6) {
    tell_room(environment(attr), attr->query_cap_name()+" golpea levemente el brazo "+
		"de "+defdr->query_cap_name()+".\n", ({ attr, defdr }));
    tell_object(defdr, "* * "+attr->query_cap_name()+" te golpea levemente el brazo.\n");
    tell_object(attr, "# Golpeas levemente el brazo de "+
		defdr->query_cap_name()+".\n");
  }
  else if (damage < 11) {
    tell_room(environment(attr), attr->query_cap_name()+" provoca pequenyos derrames a "+
		defdr->query_cap_name()+".\n", ({ attr, defdr }));
    tell_object(defdr, "* * "+attr->query_cap_name()+" te provoca "+
		"pequenyos derrames.\n");
    tell_object(attr, "# Provocas pequenyos derrames a "+defdr->query_cap_name()+ ".\n");
  }
  else if (damage < 16) {
    tell_room(environment(attr), attr->query_cap_name()+" golpea fuertemente "+
		"el abdomen de "+defdr->query_cap_name()+".\n",
		({ attr, defdr }));
    tell_object(defdr, "* * "+attr->query_cap_name()+" te golpea "
		"fuertemente en el abdomen.\n");
    tell_object(attr, "# Golpeas fuertemente a "+defdr->query_cap_name()+
			" en el abdomen.\n");
  }
  else if (damage < 21) {
    tell_room(environment(attr), attr->query_cap_name()+" golpea a "+
		defdr->query_cap_name()+" dejandole serios moratones.\n",
		({ attr, defdr }));
    tell_object(defdr, "* * "+attr->query_cap_name()+" te golpea "
		"dejandote serios moratones.\n");
    tell_object(attr, "# Golpeas a "+defdr->query_cap_name()+
			" dejandole serios moratones.\n");
  }
  else if (damage < 26) {
    tell_room(environment(attr), attr->query_cap_name()+" emplaza su escudo "+
		"en el pecho de "+defdr->query_cap_name()+" provocandole un agudo dolor.\n",
		({ attr, defdr }));
    tell_object(defdr, "* * "+attr->query_cap_name()+" te golpea en el pecho "+
		"cortandote la respiracion.\n");
    tell_object(attr, "# Ubicas tu escudo en el pecho de "+defdr->query_cap_name()+
			" provocandole un agudo dolor.\n");
  }
  else if (damage < 31) {
    tell_room(environment(attr), defdr->query_cap_name()+" se tambalea cuando "+
		attr->query_cap_name()+" le golpea brutalmente en el torax.\n",
		({ attr, defdr }));
    tell_object(defdr, "* * Te tambaleas cuando "+attr->query_cap_name()+
		" te golpea brutalmente en el torax.\n");
    tell_object(attr, "# "+defdr->query_cap_name()+
			" se tambalea cuando le golpeas brutalmente en el torax.\n");
  }
  else if (damage < 36) {
    tell_room(environment(attr), attr->query_cap_name()+" choca fuertemente con su escudo sobre la figura de "+
		defdr->query_cap_name()+" danyandole seriamente.\n",
		({ attr, defdr }));
    tell_object(defdr, "* * "+attr->query_cap_name()+" choca con su escudo "+
		"sobre ti danyandote seriamente.\n");
    tell_object(attr, "# Chocas contra la figura de "+defdr->query_cap_name()+
			" danyandole seriamente.\n");
  }
  else if (damage < 41) {
    tell_room(environment(attr), attr->query_cap_name()+" golpea salvajemente la cara de "+
		defdr->query_cap_name()+" dejandosela tenyida de sangre.\n",
		({ attr, defdr }));
    tell_object(defdr, "* * "+attr->query_cap_name()+" te golpea en la cara "+
		"abriendote labios, cejas y nariz.\n");
    tell_object(attr, "# Golpeas con furia la cara de "+defdr->query_cap_name()+
			" dejando un intenso liquido rojo corriendo sobre tu escudo.\n");
  }
  else if (damage < 51) {
    tell_room(environment(attr), attr->query_cap_name()+" choca contra "+
		defdr->query_cap_name()+" y este grita agonicamente al romperse sus huesos.\n",
		({ attr, defdr }));
    tell_object(defdr, "* * "+attr->query_cap_name()+" choca contra ti "+
		"y escuchas diferentes 'cracks' en tu cuerpo.\n");
    tell_object(attr, "# Chocas brutalmente contra "+defdr->query_cap_name()+
			" y este entona la sinfonia de los huesos rotos.\n");
  }
  else if (damage < 66) {
    tell_room(environment(attr), attr->query_cap_name()+" apaliza la cabeza de "+
		defdr->query_cap_name()+" a la vez que la sangre salta a borbotones.\n",
		({ attr, defdr }));
    tell_object(defdr, "* * "+attr->query_cap_name()+" apaliza tu cabeza "+
			"haciendote reventar la cara en sangre.\n");
    tell_object(attr, "# Apalizas la cabeza de "+
			defdr->query_cap_name()+" haciendo salir la sangre a presion.\n");
  }
  else { /* damage >= 66 */
    tell_room(environment(attr), defdr->query_cap_name()+" siente su vida acabada "+
		"cuando "+attr->query_cap_name()+" golpea de pleno su cabeza, deformandola y haciendo saltar sangre y sesos.\n",
		({ attr, defdr }));
    tell_object(defdr, "* * "+ attr->query_cap_name()+" te destroza la "
	" cabeza desgarrando tu cuello y haciendo saltar huesos "
	"y sangre.\n");
    tell_object(attr, "# Empalmas tu movimiento con la cabeza de "+defdr->query_cap_name()+
			" para endosarle la marca de tu escudo en la cara, sintiendo su vida finiquitada.\n");
  }

  return;
} /* write_message */


/* other stuff for backwards compatibility */

mixed *weapon_stats()
{
  return ({
                "   Weapon Type          ", weapon_table,
                "   Weapon Skill         ", weapon_skill,
                "   Non Magical Bonus    ", norm_bonus,
                "   Magical Bonus        ", magic_bonus,
                "   Extra Function Code  ", extra_code
         });
} /* weapon_stats */

mixed *stats()
{
  return weapon_stats();
} /* stats */
