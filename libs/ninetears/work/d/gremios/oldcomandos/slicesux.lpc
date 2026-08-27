#include "/d/gremios/comandos/new_tweaks.h"
int hb_spell(object me, mixed *params);


int slice(string str, object doer)
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

  if(!sizeof(weap))
    {  notify_fail("Rebanar con que?\n");
       return 0;
    }

  if(sizeof(weap)==2)
   {  if ( (weap[0]->query_attack_type() != 1 &&
  	   weap[1]->query_attack_type() != 1))
        {
       notify_fail("Rebanar con que?\n");
       return 0; }
   }
   else
      { notify_fail("No puedes rebanar con solo un arma.\n"); return 0; }

  
  me->add_timed_property("slicing", 1, 
    (100/(int)me->query_level()));
    
  bonus = (me->query_dex()-15)*10;
  if(environment(this_player())->query_light()>40)   bonus-=60;
  if (bonus < -60)  bonus = -60;
  x=me->query_dex()+me->query_level();
	//x=x+20;??
	tell_object(me, "DEBUG: "+x+"\n");  
  switch(x) {
  
  	case 0..19: // no deberia ser el caso
   	case 20..29: // tampoco deberia ser el caso :)
   	hits=1;
   	rate=1;
   	extrahits=0;
	break;

	case 30..39: // 2 + 4
	hits=2;
	rate=1;
	extrahits=1;
	break;

	case 40..49: // 2 + 4 + 4
	hits=3;
	rate=1;
	extrahits=1;
	break;
	
	case 50..59: // 4 + 4 + 4
	hits=4;
	rate=1;
	extrahits=2;
	//break;
	
	case 60..69: // 2 + 6 + 6
	hits=5;
	rate=2;
	extrahits=1;
	break;
	
	case 70..79: // 4 + 6 + 6
	default:
	hits=6; // curiosamente esto determina la duracion
	rate=2;
	extrahits=2; // pinyos * 2 iniciales
	break;
/*
	case 80..89: // 6 + 6 + 6
	hits=7;
	rate=2;
	extrahits=3;
	break;

	case 90..99: // 6 + 8 + 8
	hits=9;
	rate=3;
	extrahits=3;
	break;

	default: // si el otro ya era brutal :) 8 + 10 + 10
	hits=12;
	rate=4;
	extrahits=4;
*/	}

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

  tell_object(victim,(string)me->query_cap_name()+" hace girar su hoja "
    "y te rebana con una serie de ataques rapidos!\n");

  tell_object(me, "Rebanas a "+victim->query_cap_name()+
    " con una serie de ataques rapidos!\n");

  tell_room(environment(me), me->query_cap_name()+
    " hace girar su hoja y rebana a "+
    victim->query_cap_name()+" con una serie "
    "de ataques rapidos como el rayo!\n", ({ me, victim }) );
 
	// Parece que a veces sale muy tarde el notas a...
	me->dest_hide_shadow();

  victim->attack_by(me);
  
  me->add_spell_effect(hits, "offensive","slice", this_object(),
    "hb_spell", ({ bonus,victim,hits, rate }));
  
  hb_spell(me,({bonus,victim,hits, extrahits}));

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
  dam_bonus=bonus/20;     // this will either be bonus or penalty, depending on light
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
        if( params[2] <= 0 ) call_out("remove_slice",0,me);
     } /* for */ 
     
  }  /* if gp */
  else tell_object(me,"No puedes acabar de rebanar.\n");

  me->adjust_tmp_tohit_bon(-bonus);
  me->adjust_tmp_damage_bon(-dam_bonus);
  return 1;
}

void remove_slice(object me) {
    if(me)  me->remove_spell_effect("slice");
}

string help(string str) {
  return
    "Sintaxis: rebanar <persona>\n\n"
    "Rebanar es un ataque de los guerreros Drow basado en su habilidad con la espada. "
    "Tu consigues una seri de golpes extra, el numero de golpes depende de "
    "tu nivel y de tu destreza.  Tambien consigues una bonificacion al golpear "
    "y al hacer danyo, dependiendo de tu destreza.  Ambos estan afectados por "
    "el nivel de luz que haya en lugar donde te encuentras.\n\n";
}
