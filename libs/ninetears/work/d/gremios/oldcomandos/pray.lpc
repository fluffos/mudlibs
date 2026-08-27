// Pray command.  Coded by Timion.
// Updated by Timion 12 May 97
 
object me;
int x;
 

 
int check_pray(object me, string str)
{
  string god;
  int num;
 
  if(me->query_time_remaining("nopray"))
  {
    tell_object(me,"Aun estas maldito y no puedes rezar.\n");
    return 0;
  }

  god=me->query_deity();
    if(!(god) || god=="ninguna" || god == "Ninguna")
	{
	tell_object(me,"Diriges tus rezos a nadie, y nadie responde.\n");
	return 0;
	}
  switch( lower_case(str) )
  {
    case "healing":
      if(god=="tyrael")
      {
        tell_object(me,"Tu dios se niega a escuchar rezos por curaciones.\n");
        return 0;
      }
      break;

    case "money":
      if(god=="barthleby")
      {
        tell_object(me,"Tu dios se niega a escuchar rezos por dinero.\n");
        return 0;
      }
      break;

    case "power":
      if(god=="timion")
      {
        tell_object(me,"Your Diety refuses to hear a prayer for Power.\n");
        return 0;
      }
      break;

    case "experience":
	if(god=="virga" || god=="raisa")
//    if(1)
      {
        tell_object(me,"Your Diety refuses to hear a prayer for "
          "Experience.\n");
        return 0;
      }
      break;

    case "bless":
    case "blessing":
	if(god=="bivins" || god=="grimbrand" || god=="radix")
      {
        tell_object(me,"Your Diety refuses to hear a prayer for Blessing.\n");
        return 0;
      }
      break;

    case "strength":
      if(god=="hokemj")
      {
        tell_object(me,"Your Diety refuses to hear a prayer for Strength.\n");
        return 0;
      }
      break;

    case "wisdom":
      if(god=="baldrick")
      {
        tell_object(me,"Your Diety refuses to hear a prayer for Wisdom.\n");
        return 0;
      }
      break;

  }
 
if(god=="timion"||god=="hokemj"||god=="taniwha"||god=="virga"||god=="raisa")
  num=300+(me->query_time_remaining("prayed"));
else
  num=500+(me->query_time_remaining("prayed"));
  if( (num>=5000) && (num<=8000) )
  {
    tell_object(me,capitalize(god)+" te dice: Deja de molestarme o "
      "sentiras mi ira!\n");
    me->add_timed_property("prayed",num, num);
    return 0;
  }
 
  if (num>=8001)
  {
    tell_object(me,capitalize(god)+" te dice: Ya he tenido suficiente. "
      "No me molestaras mas, estaras maldito a mis ojos durante un tiempo.\n");
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
    tell_object(me,"Tus plegarias son escuchadas!\n");
    me->add_timed_property("prayed",num+500,num+500);
    return 1;
  }
  else
  {
    tell_object(me,"Tus rezos no son escuchados.\n");
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
    tell_object(me, "No puedes demostrar el suficiente respeto en medio "
      "de una pelea!\n");
    return 1;
  }

  switch( lower_case(str) )
  {
	case "healing":
    case "curacion":
      if(check_pray(me,str))
      {
        x = 1+random(5) * (int)me->query_level();
        tell_object(me, "Recuperas "+x+" puntos de vida!\n");
        me->adjust_hp(x,me);
      }
      return 1;

	case "money":
    case "dinero":
      if(check_pray(me,str))
      {
        x = 1+random(3) * (int)me->query_level();
        tell_object(me, "Te son concedidas "+x+" monedas de platino!\n");
        me->adjust_money(x,"platinum");
      }
      return 1;
	case "power":
    case "poder":
      if(check_pray(me,str))
      {
        x = 1+random(5) * (int)me->query_level();
        tell_object(me, "Te sientes mas poderoso al recuperar "+x+" puntos de gremio!\n");
        me->adjust_gp(x);
      }
      return 1;
	case "experience":
    case "experiencia":
      if(check_pray(me,str))
      {
        x = 100+random(1000) * (int)me->query_level();
        tell_object(me, "You are granted "+x+" experience points!\n");
        me->adjust_xp(x);
      }
      return 1;
    case "bless":
    case "blessing":
	case "bendicion":
      if(check_pray(me,str))
      {
        x=random(5)+1;
        tell_object(me, "Has sido bendecido!\n");
        me->adjust_tmp_cha(x);
      }
      return 1;
    case "strength":
	case "fuerza":
      if(check_pray(me,str))
      {
        x=random(5)+1;
        tell_object(me, "Una fuerza divina corre por tus venas!\n");
        me->adjust_tmp_str(x);
      }
      return 1;
    case "wisdom":
	case "sabiduria":
      if(check_pray(me,str))
      {
        x=random(2)+1;
        tell_object(me, "Te es concedida sabiduria divina!\n");
        me->adjust_tmp_wis(x);
        me->adjust_tmp_int(x);
      }
      return 1;
    default:
      tell_object(me, "Rezar que?\nOpciones: "
        "Curacion, Dinero, Poder, Experiencia, Bendicion, Fuerza, Sabiduria."
        "\nSintaxis: rezar dinero\n");
      return 1;
  }
}
