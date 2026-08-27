/* Guldan 98 Modificado por Samagh 13/07/01 Si el objecto a lanzar
 * ob->drop()==1 el objeto no se puede lanzar ya k el objeto tiene puesto el
 * reset_drop() osea maldito Anyadido lanzar por nivel y textos variados */
#define ROLL_A  ( it->query_damage_roll()*5 )
#define ROLL_P  ( random(it->query_weight()*(3/2)+(me->query_dex()+19/4)) )
#define BONUSF  ( me->query_damage_bonus()+me->query_tmp_damage_bon() )
#define MLEVEL  ( me->query_level() )
#define HLEVEL  ( target->query_level() )
#define DIVISOR ( 4-random(4)*random(2)*random(2) )
#define MSALV   ( MLEVEL+me->query_dex()+me->query_str()+ret )
#define HSALV   ( target->query_cha()+target->query_dex() )
#define BONLEV  ( random(me->query_level()/2) )

int fallo; /* Si a fallado al lanzar */

string *mostrar_danyo(int danyo) {
string lanzador, /* Texto que le sale al lanzador */
victima;         /* Texto que le sale a la victima */
switch (danyo) {
        case 0..10  : lanzador="aranyandole en el brazo";
                      victima="que te aranya el brazo";
                break;
        case 11..20 : lanzador="desgarrandole el brazo";
                      victima="que te desgarra el brazo";
                break;
        case 21..30 : lanzador="impactandole directamente en el pecho";
                      victima="que te impacta en el pecho";
                break;
        case 31..40 : lanzador="desgarrandole el pecho, dejando una fea herida";
                      victima="que te desgarra el pecho, dejandote una fea herida";
                break;
        case 41..50 : lanzador="atravesandole el pecho, y desgarrandole los musculos";
                      victima="que te atraviesa el pecho, y te desgarra los musculos";
                break;
        case 51..999: lanzador="impactandole brutalmente en el pecho, rompiendole varias costillas";
                      victima="que te impacta brutalmente en el pecho, rompiendote varias costillas";
                break;
        }/* switch */
return ({ lanzador,victima });
}
int do_lanzar(object me,object him,object it)
{
  int ret=((ROLL_A+ROLL_P)/DIVISOR)+BONUSF+BONLEV; // Ahora con criticos =)
  mixed items=environment(me)->find_inv_match();
  object target;
  string *cosas;
  
  if ( random(18) >= (me->query_dex()>20?20:me->query_dex()) )
  {
    target=items[random(sizeof(items))];
    if (target->query_dead())
    {
      tell_object(me,"Fallaste al lanzar tu "+it->query_name()+".\n");
      return 0;
    }
  }
  else target=him;
  me->add_timed_property("nolanzar",1,4);
  if (target!=him) {
    tell_object(me,"Ops, parece que tu "+it->query_name()+" no se dirige a "
        "su objetivo.\n");
        fallo=1;
        }
  if ( random(HSALV) > random(MSALV) )
  {
    if (target==me) {
        tell_object(me,"Te das cuenta a tiempo de tu error, y lanzas tu "+it->query_name()+" lejos de ti.\n");
        tell_room(ENV(me),me->query_cap_name()+" falla al lanzar algo, y casi consigue darse a si mismo.\n",me);
        return 0;
        }
    tell_object(me,"Vaya, "+target->query_cap_name()+" es mas habil de lo "
        "que parecia y ha conseguido esquivar tu "+it->query_name()+".\n");
    tell_object(target,"Ves como "+me->query_cap_name()+
        " te lanza algo, afortunadamente has coseguido esquivarlo.\n");
    tell_room(environment(me),"Ves como "+me->query_cap_name()+" lanza algo a "
        +target->query_cap_name()+" que en el ultimo momento este consigue "
        "esquivarlo.\n",({target,me}));
    target->attack_by(me);
    me->attack_ob(target);
    return 0;
  }
  cosas=mostrar_danyo(ret);
  if (target!=me) {
    tell_object(me,"Lanzas tu "+it->short()+" a "
        +target->query_cap_name()+" "+cosas[0]+"\n");
    tell_object(target,me->query_cap_name()+" te lanza algo, "+cosas[1]+
        ".\n");
    tell_room(environment(me),"Ves como "+me->query_cap_name()+" lanza algo a "
        +target->query_cap_name()+" impactandole en el cuerpo.\n",
        ({target,me}));
    }
  else {
    tell_object(me,"Te das tu mismo con "+it->short()+" aranyandote el brazo.\n");
    tell_room(ENV(me),me->query_cap_name()+" falla al lanzar algo, aranyandose en el brazo.\n",me);
  }
  target->adjust_hp(-ret,me);
  target->attack_ob(me);
  me->attack_ob(target);
  
  return ret;
}
void fail(object me,object who, int cost);
int lanzar(string str,object lanzador)
{
  object me,*arma,target;
  int coste,xp,danyo;
  string que,quien;
  me=lanzador?lanzador:TP;
  str=me->expand_nickname(str);
  if(me->query_timed_property("noguild"))
  {
   tell_object(me,"Aun no puedes hacer eso.\n");
   return 1;
  }
  if (me->query_level()<=4) 
  {
    tell_object(me,"Debes ser al menos nivel 5 para poder lanzar..\n");
    me->adjust_gp(-1);
    return 1;
  }
  if(me->query_dead())
  {
    tell_object(me,"Estas muerto! Resucita primero para poder lanzar.\n");
    me->adjust_gp(-1);
    return 1;
  }
  
  notify_fail("Sintaxis: lanzar <objeto> a <persona/bicho>.\n");
  
  if (!str)
  {
    me->adjust_gp(-1);
    return 0;
  }
  if (sscanf(str,"%s a %s",que,quien)!=2)
  {
    me->adjust_gp(-1);
    return 0;
  }
  target=find_one_match(quien,environment(me));
  if (!target)
  {
    tell_object(me,"No veo a "+quien+" por aqui.\n");
    me->adjust_gp(-1);
    return 1;
  }
  if(!living(target) || target->query_dead())
  {
    tell_object(me,quien+" no esta vivo.\n");
    me->adjust_gp(-1);
    return 1;
  }
  if ( target == me )
  {
    tell_object(me, "Lanzandote algo? Das pena.\n");
    me->adjust_gp(-1);
    return 1;
  }
  if ( environment(target)->query_property("nolanzar") ||
       environment(target)->query_timed_property("nolanzar") )
  {
    tell_object(me,"Siempre hay momentos y lugares para lanzar.\nAlgo te dice "
        " que ahora no lo debes hacer...\n");
    me->adjust_gp(-1);
    return 1;
  }
  if ( me->query_property("nolanzar") || 
       me->query_timed_property("nolanzar") )
  {
    tell_object(me, "Parece que no puedes lanzar en este momento, prueba "
                    "mas tarde...\n");
    me->adjust_gp(-1);
    return 1;
  }
  arma=find_match(que,me);
  if (!sizeof(arma))
  {
    tell_object(me,"No encuentro "+que+".\n");
    me->adjust_gp(-1);
    return 1;
  }
  /* Aqui esta el peso maximo que se puede lanzar */
  /* Anyadido que varia por level */
  if (arma[0]->query_weight()>(me->query_str()*2)+me->query_level()/(3/2))
  {
    tell_object(me,"No tienes fuerza suficiente como para lanzar "+que+".\n");
    me->adjust_gp(-1);
    return 1;
  }
  coste=arma[0]->query_weight()/8;
  
  if (!coste)
  {
    tell_object(me,"Lo siento, pero "+que+" pesa muy poco para ser lanzado.\n");
    me->adjust_gp(-1);
    return 1;
  }
  if ((int)me->query_gp() < coste)
  {
    tell_object(me,"Estas demasiado cansado para lanzar. Descansa un poco.\n");
    me->adjust_gp(-1);
    return 1;
  }
  if (arma[0]->drop()) { /* El arma esta maldita y no puede ser dejada */
        tell_object(me,"Parece ser que no puedes desprenderte de "+que+", y menos ser lanzado.\n");
        me->adjust_gp(-1);
        return 1;
        }
  me->ajusta_xp(do_lanzar(me,target,arma[0]));
  arma[0]->dest_me();
  me->adjust_gp(-coste);
  me->add_timed_property("noguild",2); // 1 ronda
  return 1;
}
string help()
{
  return 
    "\n\nSyntax: lanzar <objeto> a <persona/bicho>\n"
    "Coste de GP's: varia segun el peso del objeto lanzado.\n"
    "Descripcion:\n"
    "\tEste comando te permite lanzar un objeto a otro jugador o bicho. "
    "El danyo varia segun el objeto lanzado, tu habilidad para lazar ese "
    "objeto, y la fuerza con la que lo lances. Tu objetivo, dependiendo de "
    "su habilidad podra esquivar tu lanzamiento o no.\n";
}
