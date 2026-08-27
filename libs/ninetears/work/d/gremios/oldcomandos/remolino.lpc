// Tyrael - Dic '01
// Proposicion de comando que de mas golpes (uis espejos :P)
// durante uno o dos asaltos, flood del 15, golpes muy gays
// pero que no deje slicear ni twirlear luego en x asaltos
// y que no sea instant, tarde un turnillo en realizarse
// enterandose todaaa la room.

// modificacion del comando, solo para trolls.
// el comando se ejecutara desarmado, y en las mismas condiciones 
// que el anterior, usease, un turno y mucho flood.

#include "/d/gremios/comandos/new_tweaks.h"
int hb_spell(object me, mixed *params);


int remolino(string str, object doer)
{
  int skill,s1,i;
  int j,x;
  int damage;
  int bonus;
  int hits;
  int rate;
  int extrahits;
  object me;
  object *weap;
  object v_round;
  object protectr;
  object *vlist;
  object victim;
  me = doer ? doer : this_player();
  str = me->expand_nickname(str);

  me->adjust_gp(-3); // Lose some GP whatever, to stop slice being spammed
   if(me->query_gp() <= 0) return;


 //Se ejecutara tanto estando en peleas como no estandolo  
 //	if (sizeof(me->query_attacker_list())) {
//		notify_fail("Necesitas mas tranquilidad y concentracion!\n");
//		return 0;
//	}

    if (me->query_guild_name() == "asesino") {
        notify_fail("Que hace un asesinillo intentando rebanar?\n");
        return 0;
    }
  if (!str)
  {
    notify_fail("A quien estas intentando rebanar?\n");
    return 0;
  }
  vlist = find_match(str,environment(me));
// FIX by Tyrael - query_held_objects (o algo asi xD) por esta
// para no slicear con cosas como dos escudos :D
  weap =   (object *)me->query_weapons_wielded();
  for(i=0;i<sizeof(weap);i++)
      weap-= ({ 0 });
    
  if(!sizeof(vlist)) {
    notify_fail("Fantaseando que rebanas a alguien? intentalo con "
      "alguien que este aqui.\n");
    return 0;  }
    
  victim=vlist[0];
  
  if(victim->query_hide_shadow()) {
     notify_fail("Fantaseando que rebanas a alguien?  intentalo con "
       "alguien que este aqui.\n");
     return 0; } 
    
  if(me->query_property("pacify_on")) {
     notify_fail("Alguien te previene de hacer esto\n");
     return 0; }

  if(victim->query_dead()) {
     notify_fail("Atacando a un fantasma?\n");
     return 0;  }
  
  if(victim->query_property("pacify_on"))  {
     notify_fail("Intenta una manera menos fuerte de atacar.\n");
     return 0;  }
     
  if(victim == me)  {
     notify_fail("Rebanandote a ti mismo?\n");
     return 0;  } 
  
  if(me->query_property("slicing")) {
     notify_fail("Intentas rebanar pero estas demasiado "
      "cansado para hacer este esfuerzo.\n");
     return 0;  }

// comprobacion de armas.. se invierte el tema
  if(sizeof(weap))
    {  notify_fail("Dar tortas con las manos ocupadas? cuando se vio eso?\n");
       return 0;
    }

/*  if(sizeof(weap)==2)
   {  if ( (weap[0]->query_attack_type() != 1 &&
  	   weap[1]->query_attack_type() != 1))
        {
       notify_fail("Rebanar con que?\n");
       return 0; }
   }
   else
      { notify_fail("No puedes rebanar con solo un arma.\n"); return 0; }
*/
  
  me->add_timed_property("slicing", 1, 
    (100/(int)me->query_level()));
    
  bonus = (me->query_dex()-15)*10;
  if(environment(this_player())->query_light()>40)   bonus-=60;
  if (bonus < -60)  bonus = -60;
  x=me->query_dex()+me->query_level();
  
  switch(x) {
  
// NO SE PQ RAZON EL PRIMER TURNO SE SUMAN EL EXTRAHITS Y EL RATE... :?

  	case 0..19: // no deberia ser el caso
   	case 20..29: // tampoco deberia ser el caso :)
   	hits=1;
   	rate=1;
   	extrahits=0;
	break;

	case 30..39: // 6
	hits=3;
	rate=0;
	extrahits=3;
	break;

	case 40..49: // 6 + 4
	hits=4;
	rate=1;
	extrahits=3;
	break;
	
	case 50..59: // 8 + 6
	hits=6;
	rate=2;
	extrahits=4;
	break;
	
	case 60..69: // 12 + 8
	hits=9;
	rate=3;
	extrahits=6;
	break;
	
	case 70..79: // 14 + 8
	hits=8; // curiosamente esto determina la duracion
	rate=3;
	extrahits=5; // pinyos * 2 iniciales
	break;

	case 80..89: // 16 + 10
	hits=12;
	rate=4;
	extrahits=4; // 8
	break;

	case 90..99: // 18 + 12
	hits=14;
	rate=5;
	extrahits=9;
	break;

	default: // si el otro ya era brutal :) 20 + 14
	hits=16;
	rate=6;
	extrahits=10;
	}

/* EXPLICACION SLICE by Tyrael:

Extrahits: Solo se usa en primer heartbeat, indica pinyos por cada
	arma que salen al darle al comando (instant).
	extrahits = 0 -> solo sale rebanas, 0 hits :)
	extrahits = 1 -> 2 hits, etc

Rate: Es en 2 y sucesivos hearts lo mismo que el extrahits, TENIENDO
	en cuenta que se anyaden los 2 pinyos normales de peleas.

Hits: Pinyos correspondientes a SLICE (no a kill normal) que tendra
      en total el comando, debe usarse teniendo en cuenta las dos
	variables anteriores.
*/

	if (me->query_hidden())
		tell_room(ENV(me), "Escuchas el sonido del aire cogiendo una temible aceleracion...\n", me);
	else
                tell_room(ENV(me), me->QCN + " comienza a acelerar sus brazos temerariamente cortando el aire...\n",me);
        tell_object(me, "Tus brazos comienzan a coger una vertiginosa velocidad cortando el aire...\n");

	// poner propiedad aki para no empezar con un slice :P

	call_out("begin_twirl", 2, ({bonus,victim,hits,extrahits,rate,me}));

	return 1;
}

int begin_twirl(mixed *params)
{
	if (!params[1] || !params[5] || params[1]->query_dead() || params[5]->query_dead()) {
		notify_fail("");
		return 0;
	}
	if (ENV(params[1]) != ENV(params[5])) {
		notify_fail("Tu victima ha huido cobardemente al sentir tu rabia  de cerca.\n");
		if (params[5]->query_hidden())
		tell_room(params[5], "De pronto el ruido de tus punyos cortando el aire se extingue.\n");
		else
		tell_room(params[5], "Los brazos de " + params[5]->QCN + " dejan de cortar el aire.\n");
		return 0;
	}
	tell_room(ENV(params[5]),
                params[5]->QCN + " golpea rabiosamente a " + params[1]->QCN + " a una vertiginosa velocidad!\n",
		({params[5],params[1]}));
	tell_object(params[1], params[5]->QCN + " te destroza a golpes moviendo sus brazos endiabladamente!\n");
	tell_object(params[5], "Golpeas furiosamente a "+params[1]->QCN+" moviendo tus brazos endiabladamente!\n");
	
	params[5]->dest_hide_shadow();
  params[1]->attack_by(params[5]);
  
  // de momento el spell effect "slice"
  params[5]->add_spell_effect(params[2], "offensive","slice", this_object(),
    "hb_spell", ({ params[0],params[1],params[2], params[4] }));
  
  hb_spell(params[5],({params[0],params[1],params[2], params[3]}));

  return 1;
}

int hb_spell(object me, mixed *params)
{
  object protectr,victim,v_round;
  object *weap;
  int bonus, dam_bonus, i;
  int damg = 0;    // Event trigger - Radix
   if(me->query_gp() < 3) return;

  bonus = params[0];
  //dam_bonus=bonus/20; this will either be bonus or penalty, depending on light
	dam_bonus = (me->query_damage_bonus() > 0) ? -me->query_damage_bonus():0;
	dam_bonus -= 2; // espero que a nadie se le ocurra hacer 1 arma q meta menos de 2
  victim = params[1];
  weap =  (object *)me->query_held_ob();

  if( !victim || (environment(me) !=  environment(victim)) )
    return 0;
 
  if(me->query_property("noguild")) return 0;

  if(environment(me)->query_property("noguild")) 
    return 0;

  protectr =  victim->query_protector();

  if( protectr && 
      environment(protectr) !=  environment(victim) ) 
    protectr = 0;
  
  if(victim->query_property("no_slice")) 
    bonus = 0;

   me->adjust_tmp_damage_bon(dam_bonus);
  me->adjust_tmp_tohit_bon(bonus);
 
  if(me->adjust_gp(-3)) {
 
     for(i = 0; i < params[3]; i++) {
    
        
        if ( protectr && protectr->query_protect_valid(victim, me) ) {
          tell_room(environment(me), protectr->query_cap_name()+
            " protege valientemente a "+victim->query_cap_name()+".\n",
            ({ me, protectr, victim }) );
          tell_object(victim, protectr->query_cap_name()+
            " te protege valientemente!\n");
          tell_object(me, protectr->query_cap_name()+
            " protege a "+ victim->query_cap_name()+" de tus ataques!\n");
          tell_object(protectr, "Proteges a "+victim->query_cap_name()+
            " de los ataques de "+me->query_cap_name()+"!\n");
          v_round = protectr;
        }   
        else v_round = victim;
          
        if(weap[0] && weap[0]->query_attack_type() == 1)
        {
		if (weap[0]->query_property("no_slice")) {
			tell_room(ENV(me), me->QCN + " no consigue "
			" rebanar a " + victim->QCN + " y desperdicia el esfuerzo.\n", ({me, victim}));
			tell_object(me, "Tu " + weap[0]->query_short() +
			" no esta disenyada para rebanar y desperdicias el esfuerzo.\n");
			tell_object(victim, me->QCN + 
			" no consigue rebanarte, desperdiciando el esfuerzo.\n");
		}
		else {
            damg = weap[0]->weapon_attack(v_round,me);
            weap[0]->event_slice(damg,me,v_round);
		}
        }
        if(weap[1] && weap[1]->query_attack_type() == 1)
        {
		if (weap[1]->query_property("no_slice")) {
			tell_room(ENV(me), me->QCN + " no consigue "
			" rebanar a " + victim->QCN + " y desperdicia el esfuerzo.\n", ({me, victim}));
			tell_object(me, "Tu " + weap[1]->query_short() +
			" no esta disenyada para rebanar y desperdicias el esfuerzo.\n");
			tell_object(victim, me->QCN + 
			" no consigue rebanarte, desperdiciando el esfuerzo.\n");
		}
		else {
            damg = weap[1]->weapon_attack(v_round,me);
            weap[1]->event_slice(damg,me,v_round);
		}
        }
        v_round->attack_by(me);
    
        params[2]--;
        if( params[2] <= 0 ) call_out("remove_twirl",0,me);
     } /* for */ 
     
  }  /* if gp */
  else tell_object(me,"No puedes acabar de rebanar.\n");

  me->adjust_tmp_tohit_bon(-bonus);
  me->adjust_tmp_damage_bon(-dam_bonus);
  return 1;
}

void remove_twirl(object me) {
    if(me)  me->remove_spell_effect("slice");
}

string help(string str) {
  return
    "Sintaxis: twirl <persona>\n\n"
    "Rebanar es un ataque de los guerreros Drow basado en su habilidad con la espada. "
    "Tu consigues una seri de golpes extra, el numero de golpes depende de "
    "tu nivel y de tu destreza.  Tambien consigues una bonificacion al golpear "
    "y al hacer danyo, dependiendo de tu destreza.  Ambos estan afectados por "
    "el nivel de luz que haya en lugar donde te encuentras.\n\n";
}
