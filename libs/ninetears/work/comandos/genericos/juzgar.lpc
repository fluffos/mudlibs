//Gareth 20.12.02 // Fixed por Xerxes el Dia de Navidad de 2002
//comando Judgar // Renombrado a juZgar por Xerxes en el mismo dia

string help()
{
    return
        "Nombre del Comando: Juzgar\n"
	"Coste en Energia: 5\n"
        "Sintaxis: juzgar <objeto>\n"
	"Descripcion:\n"
	"    Con esta habilidad podras deducir "
	"la calidad de cualquier arma, objeto o"
	" armadura que poseas.\n\n";
}

string query_judge_mess(int flag)
{
  switch(flag)
  {
    case 1 : return "Pesimo";
    case 2 : return "Muy malo";
    case 3 : return "Malo";
    case 4 : return "Pobre";
    case 5 : return "Regular";
    case 6 : return "Bueno";
    case 7 : return "Muy bueno";
    case 8 : return "Grande";
    case 9 : return "Maravilloso";
    case 10 : return "Increible";
    case 11 : return "Impresionante";
    case 12 : return "EL MEJOR";
  }
  return "desconocido";
}

int munge_value(int dmg, object me)
{
  int flag;
  flag = 0;
  switch(me->query_level())
  {
    case 0..6:
      switch(dmg)
      {
        case 0..2: flag =1; break;
        case 3..14: flag = 5; break;
        default: flag = 8; break;
      }
      break;
    case 7..13 :
      switch(dmg)
      {
        case 0..3 : flag = 1; break;
        case 4..7 : flag = 3; break;
        case 8..10 : flag = 5; break;
        case 11..13 : flag = 8; break;
        case 14..99 : flag = 9; break;
      }
      break;
    case 14..20 :
      switch(dmg)
      {
        case 0..2 : flag = 1; break;
        case 3..4 : flag = 2; break;
        case 5..8 : flag = 3; break;
        case 9..11 : flag = 5; break;
        case 12: flag = 7; break;
        case 13: flag = 8; break;
        case 14..19: flag = 9; break;
        case 20..99: flag = 11; break;
      }
      break;
    case 21..99999 :
      switch(dmg)
      {
        case 0..2 : flag = 1; break;
        case 3..4 : flag = 2; break;
        case 5: flag = 3; break;
        case 6..7: flag = 4; break;
        case 8..9: flag = 5; break;
        case 10..11: flag = 6; break;
        case 12: flag = 7; break;
        case 13: flag = 8; break;
        case 14..17: flag = 9; break;
        case 18..19 : flag = 10; break;
        case 20: flag = 11; break;
        default: flag = 12; break;
     }
  }
  return flag;
}

int query_max_weapon_damage(object ob)
{
int r1,r2,r3;
r1=ob->query_damage_vals()[0];
r2=ob->query_damage_vals()[1];
r3=ob->query_damage_vals()[2];
return((r1*r2)+r3);
}

 
int judge_weapon(object ob, object me)
{
  int dmg;
  int flag;
  
  dmg=query_max_weapon_damage(ob);
  flag = munge_value(dmg, me);

  if(!flag)
    tell_object(me,"No puedes deducir la calidad de "+ob->query_short()+".\n");
  else
    tell_object(me,"Tu "+ob->query_short()+" es "+query_judge_mess(flag)+
      " haciendo danyo.\n");

   return(1);
}

void judge_armour(object ob, object me)
{
  int dmg;
  int flag;
 
  dmg = (int)ob->query_ac()/5;
  flag = munge_value(dmg, me);
  if(!flag)
    tell_object(me,"No puedes deducir la calidad de "+ob->query_short()+".\n");
  else
    tell_object(me,"Tu "+ob->query_short()+" es "+query_judge_mess(flag)+
      " protegiendo.\n");
  return;
}
 
int inicio(string str, object who)
{
  object *ob;
  int i;
  object me;
 
  me = ( who ? who : this_player() );
 
  if(!str)
  {
    tell_object(me,"Sintaxis: juzgar <objeto>\n");
    return 1;
  }
 
  if( (str=="all") || (str=="ALL") || (str=="All") )
str="0";
    ob=find_match(str,me);

  if(!sizeof(ob))
  {
    tell_object(me,"No tienes nada llamado "+str+".\n");
    return 1;
  }

  for(i=0;i<sizeof(ob);i++)
  {
    if(ob[i]->query_weapon())
      judge_weapon(ob[i],me);
    else if(ob[i]->query_armour())
      judge_armour(ob[i],me);
    else if(ob[i]->query_short())
      tell_object(me,ob[i]->query_short()+" no parece ser muy util en combate.\n");
  }

  return 1;
}
