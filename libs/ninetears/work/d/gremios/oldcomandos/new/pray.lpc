// Pray command, first draft.
 
object me;
int x;
 

 
check_pray(object me, string str)
{
  string god;
  int num;
 
  if(me->query_time_remaining("nopray"))
  {
    tell_object(me,"No estas adorando a ningun Dios.\n");
    return 0;
  }

  god=me->query_deity();
  switch( lower_case(str) )
  {
    case "vida":
      if(god=="sinister")
      {
        tell_object(me,"Tu Dios no quiere oir nada sobre vida.\n");
        return 0;
      }
      break;

    case "dinero":
      if(god=="mystical")
      {
        tell_object(me,"Tu Dios no quiere oir nada sobre dinero.\n");
        return 0;
      }
      break;

    case "poder":
      if(god=="raf")
      {
        tell_object(me,"Tu Dios no quiere oir nada sobre poder.\n");
        return 0;
      }
      break;

    case "experiencia":
      if(god=="fredrick")
      {
        tell_object(me,"Tu Dios no quiere oir nada sobre experienca.\n");
        return 0;
      }
      break;

    case "bendicion":
      if(god=="yvendur"||god=="sinister")
      {
        tell_object(me,"Tu Dios no quiere oir nada sobre bendiciones.\n");
        return 0;
      }
      break;

    case "fuerza":
      if(god=="theiwar")
      {
        tell_object(me,"Tu Dios no quiere oir nada sobre fuerza.\n");
        return 0;
      }
      break;

    case "sabiduria":
      if(god=="yvendur")
      {
        tell_object(me,"Tu Dios no quiere oir nada sobre sabiduria.\n");
        return 0;
      }
      break;

  }
 
  num=500+(me->query_time_remaining("prayed"));
  if( (num>=5000) && (num<=8000) )
  {
    tell_object(me,capitalize(god)+" te dice: Desiste en rezar mas o "
      "te destruire como mortal que eres!!!\n");
    me->add_timed_property("prayed",num, num);
    return 0;
  }
 
  if (num>=8001)
  {
    tell_object(me,capitalize(god)+" te dice: Te adverti y no me quisiste"
    " hacer caso, atente a las consecuencias ahora, estas maldito ante "
    "mis ojos!.\n");
    me->set_hp(1);
    me->adjust_tmp_con(-1);
    me->adjust_tmp_str(-1);
    me->adjust_tmp_wis(-1);
    me->adjust_tmp_int(-1);
    me->adjust_tmp_dex(-1);
    me->adjust_tmp_cha(-2);
    me->add_timed_property("nopray",num,num);
    return 0;
  }

  if(random(num)<=75)
  {
    tell_object(me,"Tu Dios es benevolo y concede tus plegarias!\n");
    me->add_timed_property("prayed",num+500,num+500);
    return 1;
  }
  else
  {
    tell_object(me,"Tu Dios no te ha escuchado.\n");
    me->add_timed_property("prayed",num, num);
    return 0;
  }

  return 0;
}
 
 
int pray(string str,object who)
{
  object me = ( who ? who : this_player() );
 
  if ( sizeof(me->query_attacker_list()) )
  {
    tell_object(me, "No puedes dar suficiente respeto a tu Dios mientras "
      "estes luchando!\n");
    return 1;
  }

  switch( lower_case(str) )
  {
    case "vida":
      if(check_pray(me,str))
      {
        x = 1+random(5) * (int)me->query_level();
        tell_object(me, "Recibes "+x+" puntos vida!\n");
        me->adjust_hp(x,me);
      }
      return 1;

    case "dinero":
      if(check_pray(me,str))
      {
        x = 1+random(3) * (int)me->query_level();
        tell_object(me, "Recibes "+x+" monedas de platino!\n");
        me->adjust_money(x,"platino");
      }
      return 1;
    case "poder":
      if(check_pray(me,str))
      {
        x = 1+random(5) * (int)me->query_level();
        tell_object(me, "Sientes "+x+" puntos de poder que recorren tus venas!\n");
        me->adjust_gp(x);
      }
      return 1;
    case "experiencia":
      if(check_pray(me,str))
      {
        x = 100+random(1000) * (int)me->query_level();
        tell_object(me, "Se te regalan "+x+" puntos de experiencia!\n");
        me->adjust_xp(x);
      }
      return 1;
    case "bendicion":
      if(check_pray(me,str))
      {
        x=random(5)+1;
        tell_object(me, "Tu Dios te bendice!\n");
        me->adjust_tmp_cha(x);
      }
      return 1;
    case "fuerza":
      if(check_pray(me,str))
      {
        x=random(5)+1;
        tell_object(me, "Notas como tu Dios te da algo de su fuerza Divina!\n");
        me->adjust_tmp_str(x);
      }
      return 1;
    case "sabiduria":
      if(check_pray(me,str))
      {
        x=random(2)+1;
        tell_object(me, "Tu sabiduria alcanza limites insospechables.\n");
        me->adjust_tmp_wis(x);
        me->adjust_tmp_int(x);
      }
      return 1;
    default:
      tell_object(me, "Rezar el que?\nLas opciones son: "
        "vida, dinero, poder, experiencia, bendicion, fuerza, sabiduria."
        "\nSintaxis: rezar dinero\n");
      return 1;
  }
}
 
