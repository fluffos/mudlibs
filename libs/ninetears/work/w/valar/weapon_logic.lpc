
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

void create() { }

void set_wm_flag(int j) { wm_flag=j; }
/* set_wm_flag */

void add_attack(string weapon_type, int nm_bonus, int m_bonus, string fn_code) { setup_weapon(weapon_type, "str", nm_bonus, m_bonus, fn_code); } /* add_attack mask */

void setup_weapon(string weapon_type, string w_sk, int nm_bonus, int m_bonus, string fn_code) {
  	weapon_table=weapon_type;
  	weapon_skill=w_sk;
  	norm_bonus=nm_bonus;
  	magic_bonus=m_bonus;
  	extra_code=fn_code;
	}

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

// VILAT 24.10.2002 - ESTE ARCHIVO DA VERDADERO ASCO!!! VIA VER COMO LE METO LAS SKILLS SIN ENGUARRARME MUCHO, AUNQUE ME DA QUE VOY
// A ACABAR CARGANDOMELO POR COMPLETO...
int weapon_attack(object defdr, object atckr) {
  	mixed *att_val;
	string hab;

  	this_object()->set_wm_flag(0);

  	defender=defdr;
  	attacker=atckr;
  	att_val=workout_attack();

	switch(TO->query_attack_type()) {
		case 1:hab="filo";break;
		case 2:hab="contundente";break;
		case 3:hab="perforacion";break;
		}

	att_val[1]+=(atckr->query_habilidad(hab)+random(atckr->query_habilidad(hab)))/20;

  	if(att_val[0]=="fumble") return TO->fumble_weapon("weapon_table", attacker, defender);

  	if(att_val[0]=="hit" || att_val[0] == "critical") if (!apply_damage(att_val[1])) wm_flag = 1;

  	if (extra_code) call_other(this_object(), extra_code);

  	if(wm_flag==0) write_message(att_val[0], att_val[1], TO->query_short(), attacker, defender);
  	return (int)att_val[1];
	}

mixed *workout_attack() {
  	int THAC0, bon, tmproll, result, achit, defenderac, damage_done;
  	string happen;
  	THAC0=attacker->query_thac0();

   	bon=norm_bonus;
   	if(magic_bonus>norm_bonus || defender->query_magical()) bon=magic_bonus;

  	tmproll = random(1000) +1;

   	if(tmproll < ((50 - defender->query_cha() > 0) ? 50 - defender->query_cha() : 1) ) return ({ "fumble", 0});
  	achit = ((THAC0 - bon - (int)attacker->query_tohit_bonus()) - tmproll);
  	achit += attacker->query_dual_wield_penalty();

	defenderac = ((int)defender->query_total_ac() - (int)defender->extra_bonus("defend"));

   	result = (achit - defenderac);

   	if (result < 1) {
     		happen = "hit";
     		damage_done = this_object()->query_damage_roll() + (int)attacker->query_damage_bonus();

		if( random(600) < attacker->query_cha()+attacker->query_habilidad("anatomia") ) {
			damage_done *= 2;
			happen = "critical";
			}
     		}
   	else {
     		happen = "miss";
     		damage_done = 0;
     		}

   	return ({ happen, damage_done, });

	} /* workout_attack */

int fumble_weapon(string lookup_table, object atckr, object defdr) {
	if (!random(5)) {
		string oa;
		oa = (atckr->query_gender() == 1) ? "o" : "a";
		tell_room(ENV(atckr), atckr->QCN + " hace un mal movimiento y se da a si mism"+oa+".\n", atckr);
		tell_object(atckr, "Realmente un mal movimiento. Te das a ti mism"+oa+".\n");
		atckr->adjust_hp(-random(TO->query_damage_roll())-1);
		}
	else {
		tell_room(ENV(atckr), atckr->QCN + " falla por completo su maniobra.\n", atckr);
		tell_object(atckr, "Fallas la maniobra y pierdes tu oportunidad.\n");
		}
  	return 0;
	} /* fumble_weapon */

int apply_damage(int hps) { return defender->adjust_hp(-hps, attacker); } /* apply_damage */

void write_message(string happen, int damage, string w_type, object attr, object defdr) {
  	if (happen == "miss") {
      		tell_room(environment(attr), defdr->query_cap_name()+" esquiva habilmente el ataque de "+attr->query_cap_name()+".\n",({ attr, defdr }));
      		tell_object(defdr, "* Esquivas habilmente el ataque de "+attr->query_cap_name()+".\n");
      		tell_object(attr, "# "+defdr->query_cap_name()+" esquiva habilmente tu ataque.\n");
		return;
  		}

  	if ( damage<0) {
		if ( defdr->query_equip_ac() ) {
			tell_room(environment(attr), attr->query_cap_name()+" golpea la armadura de "+defdr->query_cap_name()+" sin producirle danyo.\n",({ attr, defdr }));
      			tell_object(defdr, "* "+attr->query_cap_name()+" golpea tu armadura con su "+w_type+".\n");
      			tell_object(attr, "# No consigues danyar a "+defdr->query_cap_name()+" al golpearle en su armadura.\n");
    			}
    		else {
      			tell_room(environment(attr), attr->query_cap_name()+" golpea a "+defdr->query_cap_name()+" inofensivamente.\n",({ attr, defdr }));
      			tell_object(defdr, "* "+attr->query_cap_name()+" te golpea inofensivamente con su "+w_type+".\n");
      			tell_object(attr, "# Tu golpe no parece danyar a "+defdr->query_cap_name()+".\n");
    			}
  		}
  	else if (damage == 0) {
      		tell_room(environment(attr), defdr->query_cap_name()+" no recibe danyo cuando es golpeado por "+attr->query_cap_name()+".\n",({ attr, defdr }));
      		tell_object(defdr, "* No recibes danyo cuando "+attr->query_cap_name()+" te golpea.\n");
      		tell_object(attr, "# "+defdr->query_cap_name()+" no recibe danyo cuando le golpeas.\n");
		}
	// Vilat metiendo el moco again 01.09.2002
  	else switch(TO->query_attack_type()) {
  		case 1:
  		if (damage<3) {
  			tell_room(environment(attr), attr->query_cap_name()+" roza a "+defdr->query_cap_name()+".\n", ({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te roza.\n");
    			tell_object(attr, "# Rozas a "+defdr->query_cap_name()+".\n");
  			}
  		else if (damage < 6) {
    			tell_room(environment(attr), attr->query_cap_name()+" aranya debilmente a "+defdr->query_cap_name()+" en la cara.\n", ({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te aranya debilmente en la cara.\n");
    			tell_object(attr, "# Aranyas debilmente la cara de "+defdr->query_cap_name()+".\n");
  			}
  		else if (damage < 9) {
    			tell_room(environment(attr), attr->query_cap_name()+" produce un profundo corte en el antebrazo de "+defdr->query_cap_name()+".\n", ({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te produce un profundo corte en el antebrazo.\n");
    			tell_object(attr, "# Produces un profundo corte en el antebrazo de "+defdr->query_cap_name()+".\n");
  			}
  		else if (damage < 12) {
    			tell_room(environment(attr), attr->query_cap_name()+" raja el brazo de "+defdr->query_cap_name()+" dejandole una sangrienta herida.\n", ({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te raja el brazo dejandote una sangrienta herida.\n");
    			tell_object(attr, "# Rajas el brazo de "+defdr->query_cap_name()+" dejandole una sangrienta herida.\n");
  			}
  		else if (damage < 15) {
  			tell_room(environment(attr), attr->query_cap_name()+" raja el abdomen de "+defdr->query_cap_name()+" manchandole las vestiduras de sangre.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te raja el abdomen dejandote manchas de sangre en las vestiduras.\n");
    			tell_object(attr, "# Rajas el abdomen de "+defdr->query_cap_name()+" manchandole las vestiduras de sangre.\n");
  			}
  		else if (damage < 18) {
    			tell_room(environment(attr), attr->query_cap_name()+" provoca una herida a "+defdr->query_cap_name()+" de la que mana sangre a borbotones.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te provoca una herida de la que mana sangre a borbotones.\n");
    			tell_object(attr, "# Cortas la carne de "+defdr->query_cap_name()+" de donde mana sangre a borbotones.\n");
  			}
  		else if (damage < 21) {
    			tell_room(environment(attr), attr->query_cap_name()+" corta gravemente el brazo de "+defdr->query_cap_name()+" dejandole los tendones severamente danyados.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te corta gravemente el brazo dejandote los tendones severamente danyados.\n");
    			tell_object(attr, "# Cortas gravemente el brazo de "+defdr->query_cap_name()+" dejandole los tendones severamente danyados.\n");
  			}
  		else if (damage < 24) {
    			tell_room(environment(attr), defdr->query_cap_name()+" se retuerce de dolor cuando "+attr->query_cap_name()+" le corta en el cuello.\n",({ attr, defdr }));
    			tell_object(defdr, "* * Te retuerces de dolor cuando "+attr->query_cap_name()+" te corta en el cuello.\n");
    			tell_object(attr, "# Ves retorcerse de dolor a "+defdr->query_cap_name()+" cuando le cortas en el cuello.\n");
  			}
  		else if (damage < 27) {
    			tell_room(environment(attr), attr->query_cap_name()+" abre el pecho de "+defdr->query_cap_name()+" danyando seriamente sus pulmones.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te abre el pecho danyando seriamente tus pulmones.\n");
    			tell_object(attr, "# Abres el pecho de "+defdr->query_cap_name()+" danyando seriamente sus pulmones.\n");
  			}
  		else if (damage < 30) {
    			tell_room(environment(attr), attr->query_cap_name()+" deja malherido a "+defdr->query_cap_name()+" con una serie de rapidos cortes.\n", ({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te deja malherido con una serie de rapidos cortes.\n");
    			tell_object(attr, "# Una serie de rapidos cortes dejan malherido a "+defdr->query_cap_name()+".\n");
  			}
  		else if (damage < 33) {
    			tell_room(environment(attr), attr->query_cap_name()+" abre el abdomen de "+defdr->query_cap_name()+" dejandole los intestinos al aire.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te abre el abdomen dejandote los intestinos al aire.\n");
    			tell_object(attr, "# Abres el abdomen de "+defdr->query_cap_name()+" dejandole los intestinos al aire.\n");
  			}
  		else if (damage < 36) {
    			tell_room(environment(attr), attr->query_cap_name()+" corta en la frente a "+defdr->query_cap_name()+" haciendole perder el control.\n",({ attr, defdr }));
    			tell_object(defdr, "* * Pierdes el control cuando "+attr->query_cap_name()+" te corta en la frente.\n");
    			tell_object(attr, "# Cortas en la frente a "+defdr->query_cap_name()+", haciendo que pierda momentaneamente el control.\n");
  			}
  		else if (damage < 39) {
    			tell_room(environment(attr), attr->query_cap_name()+" desgarra el pecho de "+defdr->query_cap_name()+" destrozando organos vitales.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te desgarra el pecho destrozando tus organos vitales.\n");
    			tell_object(attr, "# Desgarras el pecho de "+defdr->query_cap_name()+" destrozando organos vitales.\n");
  			}
  		else if (damage < 42) {
    			tell_room(environment(attr), attr->query_cap_name()+" hiere brutalmente en la pierna a "+defdr->query_cap_name()+" desgarrandole los musculos.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te hiere brutalmente en la pierna desgarrandote los musculos.\n");
    			tell_object(attr, "# Hieres a "+defdr->query_cap_name()+" brutalmente en la pierna desgarrandole los musculos.\n");
  			}
  		else if (damage < 52) {
    			tell_room(environment(attr), attr->query_cap_name()+" entierra su arma en el plexo solar de "+defdr->query_cap_name()+".\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" entierra su "+w_type+" en tu plexo solar.\n");
    			tell_object(attr, "# Entierras tu "+w_type+" en el plexo solar de "+defdr->query_cap_name()+".\n");
  			}
  		else if (damage < 69) {
    			tell_room(environment(attr), attr->query_cap_name()+" hiere a "+defdr->query_cap_name()+" en el ojo con un magnifico movimiento.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te hiere en el ojo con un magnifico movimiento.\n");
    			tell_object(attr, "# Alcanzas el ojo de "+defdr->query_cap_name()+" con un magnifico movimiento.\n");
  			}
  		else {
    			tell_room(environment(attr), defdr->query_cap_name()+" siente como su vida se le escapa cuando "+attr->query_cap_name()+" le hiere en el corazon.\n",({ attr, defdr }));
    			tell_object(defdr, "* * Sientes como tu vida se te escapa cuando "+attr->query_cap_name()+" te hiere en el corazon.\n");
    			tell_object(attr, "# Sientes como la vida de "+defdr->query_cap_name()+" se le escapa cuando le hieres en el corazon.\n");
  			}
  		break;

  		case 2:
  		if (damage<3) {
  			tell_room(environment(attr), attr->query_cap_name()+" roza a "+defdr->query_cap_name()+".\n", ({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te roza.\n");
    			tell_object(attr, "# Rozas a "+defdr->query_cap_name()+".\n");
  			}
  		else if (damage < 6) {
    			tell_room(environment(attr), attr->query_cap_name()+" magulla a "+defdr->query_cap_name()+".\n", ({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te magulla.\n");
    			tell_object(attr, "# Magullas a "+defdr->query_cap_name()+".\n");
  			}
  		else if (damage < 9) {
    			tell_room(environment(attr), attr->query_cap_name()+" provoca pequenyos derrames en el brazo de "+defdr->query_cap_name()+" al golpearselo.\n", ({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te provoca pequenyos derrames en el brazo al golpeartelo.\n");
    			tell_object(attr, "# Provocas pequenyos derrames en el brazo de "+defdr->query_cap_name()+" al golpearselo.\n");
  			}
  		else if (damage < 12) {
    			tell_room(environment(attr), attr->query_cap_name()+" golpea a "+defdr->query_cap_name()+" produciendole serios moratones.\n", ({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te golpea produciendote serios moratones.\n");
    			tell_object(attr, "# Golpeas a "+defdr->query_cap_name()+" produciendole serios moratones.\n");
  			}
  		else if (damage < 15) {
  			tell_room(environment(attr), attr->query_cap_name()+" golpea fuertemente a "+defdr->query_cap_name()+" haciendo que se tambalee.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te golpea fuertemente haciendo que te tambalees.\n");
    			tell_object(attr, "# Golpeas fuertemente a "+defdr->query_cap_name()+" haciendo que se tambalee.\n");
  			}
  		else if (damage < 18) {
  			tell_room(environment(attr), attr->query_cap_name()+" golpea fuertemente a "+defdr->query_cap_name()+" en el abdomen.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te golpea fuertemente en el abdomen.\n");
    			tell_object(attr, "# Golpeas fuertemente a "+defdr->query_cap_name()+" en el abdomen.\n");
    			}
  		else if (damage < 21) {
    			tell_room(environment(attr), attr->query_cap_name()+" golpea a "+defdr->query_cap_name()+" en la mandibula dejandosela ligeramente desencajada.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te golpea en la mandibula dejandotela ligeramente desencajada.\n");
    			tell_object(attr, "# Golpeas a "+defdr->query_cap_name()+" en la mandibula dejandosela ligeramente desencajada.\n");
  			}
  		else if (damage < 24) {
    			tell_room(environment(attr), attr->query_cap_name()+" golpea a "+defdr->query_cap_name()+" en el costado, aplastando sus organos vitales.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te golpea en el costado, aplastando tus organos vitales.\n");
    			tell_object(attr, "# Golpeas a "+defdr->query_cap_name()+" en el costado, aplastando sus organos vitales.\n");
  			}
  		else if (damage < 27) {
    			tell_room(environment(attr), attr->query_cap_name()+" machaca el antebrazo de "+defdr->query_cap_name()+", dejando una herida muy fea.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te machaca en el antebrazo dejando una herida muy fea.\n");
    			tell_object(attr, "# Machacas a "+defdr->query_cap_name()+" en el antebrazo dejando una herida muy fea.\n");
  			}
  		else if (damage < 30) {
    			tell_room(environment(attr), attr->query_cap_name()+" machaca el pecho de "+defdr->query_cap_name()+", rompiendole algunas costillas.\n", ({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te machaca el pecho, rompiendote algunas costillas.\n");
    			tell_object(attr, "# Machacas el pecho de "+defdr->query_cap_name()+", rompiendole algunas costillas.\n");
  			}
  		else if (damage < 33) {
    			tell_room(environment(attr), attr->query_cap_name()+" aplasta la rodilla de "+defdr->query_cap_name()+", dejandosela momentaneamente inutilizada.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te aplasta la rodilla, dejandotela momentaneamente inutilizada.\n");
    			tell_object(attr, "# Aplastas la rodilla de "+defdr->query_cap_name()+", dejandosela momentaneamente inutilizada.\n");
  			}
  		else if (damage < 36) {
    			tell_room(environment(attr), attr->query_cap_name()+" aplasta la cabeza de "+defdr->query_cap_name()+", causando severos danyos.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te aplasta la cabeza, causandote severos danyos.\n");
    			tell_object(attr, "# Aplastas la cabeza de "+defdr->query_cap_name()+", causando severos danyos.\n");
  			}
  		else if (damage < 39) {
    			tell_room(environment(attr), attr->query_cap_name()+" impacta brutalmente en la espalda a "+defdr->query_cap_name()+", rompiendole algunas vertebras.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te impacta brutalmente en la espalda rompiendote algunas vertebras.\n");
    			tell_object(attr, "# Impactas brutalmente a "+defdr->query_cap_name()+" en la espalda rompiendole algunas vertebras.\n");
  			}
  		else if (damage < 42) {
    			tell_room(environment(attr), attr->query_cap_name()+" impacta en la ingle a "+defdr->query_cap_name()+", provocandole dolorosos espasmos.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te impacta en la ingle provocandote dolorosos espasmos.\n");
    			tell_object(attr, "# Impactas a "+defdr->query_cap_name()+" en la ingle provocandole dolorosos espasmos.\n");
  			}
  		else if (damage < 52) {
    			tell_room(environment(attr), attr->query_cap_name()+" hunde el craneo de "+defdr->query_cap_name()+" con un poderoso golpe.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" hunde tu crane con su "+w_type+".\n");
    			tell_object(attr, "# Hundes tu "+w_type+" en el craneo de "+defdr->query_cap_name()+".\n");
  			}
  		else if (damage < 69) {
    			tell_room(environment(attr), attr->query_cap_name()+" asesta un increible golpe en la cabeza a "+defdr->query_cap_name()+" causandole derrames masivos.\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te asesta un increible golpe en la cabeza causandote derrames masivos.\n");
    			tell_object(attr, "# Asestas un increible golpe en la cabeza a "+defdr->query_cap_name()+" causandole derrames masivos.\n");
  			}
  		else {
    			tell_room(environment(attr), "Un brutal golpe en el pecho de "+defdr->query_cap_name()+" provoca que sus rotas costillas se claven en sus pulmones!\n",({ attr, defdr }));
    			tell_object(defdr, "* * "+attr->query_cap_name()+" te propina un brutal golpe en el pecho. Tus costillas se parten atravesandote los pulmones!\n");
    			tell_object(attr, "# Propinas un golpe brutal a "+defdr->query_cap_name()+". Sus costillas crujen al partirse y le atraviesan los pulmones!\n");
  			}
  		break;
		case 3:
		tell_room(ENV(attr),attr->query_cap_name()+" pega a "+defdr->query_cap_name()+" con un arma perforante.\n",({attr,defdr}));
		tell_object(defdr,"* * "+attr->query_cap_name()+" te pega con un arma perforante pero no sale un buen mensaje porque nadie se ha molestado en hacerlo.\n");
		tell_object(attr,"# Pegas con tu arma perforante a "+defdr->query_cap_name()+" pero no sale mensaje porque nadie se lo ha currado.\n");

  		default:
  		break;
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
