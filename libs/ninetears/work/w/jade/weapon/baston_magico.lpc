// Guldan Jun'98
inherit "/obj/weapon";
#define CPN capitalize(NOMBRE)
#define	DEBUG(ob) ( ob->query_creator() || ob->query_property("TEST") )
#define	VALOR ( 600+1000*GRADO )
string	NOMBRE="";
string	COLOR="";
string	DESC="";
string	MON="";
string	MOF="";
string	TIPO="";
int	SALV=50;
int GRADO=0;
void setup()
{
  set_base_weapon("quarterstaff");
  set_name("baston de "+NOMBRE);
  set_short("Baston de "+COLOR+CPN+"%^RESET%^");  set_main_plural("Bastones de "+COLOR+CPN+"%^RESET%^");  add_alias(NOMBRE);	
  add_alias("baston");
  add_plural("bastones");
  add_plural("bastones de "+NOMBRE);
  set_long(DESC);
  set_twohanded(1);
  set_enchant(GRADO+1);
  set_weight(query_weight()/(GRADO+1));
  }
int weapon_attack(object him,object me)
{
  int tmp1=::weapon_attack(him,me);
 int
tmp2=-him->spell_damage(-roll(1,6)-me->query_magic_bonus(),TIPO,"weapon",SALV,me);
  int damage=tmp1+tmp2;
  string el=him->query_cap_name();
  string yo=me->query_cap_name();
  string que=query_short();
  switch (tmp1)
  { 
    case 0:
      tell_object(me,"Rozas a "+el+" con tu "+que+".\n");      tell_object(him,yo+" te roza con su "+que+".\n");      tell_room(ENV(me),yo+" roza a "+el+" con su "+que+".\n",({him,me}));
      break;
    case 1..5:
      tell_object(me,"Golpeas ligeramente a "+el+" con tu "+que+".\n");
      tell_object(him,yo+" te golpea ligeramente con su "+que+".\n");      tell_room(ENV(me),yo+" golpea ligeramente a "+el+" con su "+que+".\n",({him,me}));
      break;
    case 6..10:
      tell_object(me,"Golpeas a "+el+" con tu "+que+".\n");      tell_object(him,yo+" te golpea con su "+que+".\n");
      tell_room(ENV(me),yo+" golpea a "+el+" con su "+que+".\n",({him,me}));
      break;
    case 11..15:
      tell_object(me,"Golpeas brutalmente a "+el+" con tu "+que+".\n");
      tell_object(him,yo+" te golpea brutalmente con su "+que+".\n");      tell_room(ENV(me),yo+" golpea brutalmente a "+el+" con su "+que+".\n",({him,me}));
      break;
    case 16..1000:
      tell_object(me,"Escuchas con placer como la caja toracica de "+el+
      " explota al impactarle con tu "+que+".\n");      tell_object(him,yo+" te golpea brutalmente y sientes como algo en tu "      "interior explota al impactar su "+que+" en tu pecho.\n");      tell_room(ENV(me),yo+" golpea brutalmente a "+el+" con su "+que+". "      "Aprecias como incrusta su "+que+" en el pecho de "+el+".\n",({him,me}));
      break;  
}  switch (tmp2)
  { 
    case 1..5:
      tell_object(me,"Tu "+que+" produce una ligera descarga a "+el+".\n");
      tell_object(him,"El "+que+" de "+yo+" te produce una ligera descarga.\n");
      tell_room(ENV(me),"El "+que+" de "+yo+" produce una ligera descarga a "+el+".\n",({him,me}));
      break;
    case 6..10:
      tell_object(me,"Tu "+que+" produce una descarga a "+el+".\n");      tell_object(him,"El "+que+" de "+yo+" te produce una descarga.\n");      tell_room(ENV(me),"El "+que+" de "+yo+" produce una descarga a "+el+".\n",({him,me}));
      break;
    case 11..15:
      tell_object(me,"Tu "+que+" electrocuta a "+el+".\n");      tell_object(him,"El "+que+" de "+yo+" te electrocuta.\n");      tell_room(ENV(me),"El "+que+" de "+yo+" electrocuta a "+el+".\n",({him,me}));
      break;
    case 16..1000:
      tell_object(me,el+" se convulsiona horriblemente por la descarga de tu "+que+".\n");
      tell_object(him,"Te convulsionas horriblemente por la descarga del "+que+" de "+yo+".\n");
      tell_room(ENV(me),el+" se convulsiona horriblemente por la descarga del "+que+" de "+yo+".\n",({him,me}));
      break;
  }
  if (DEBUG(me)) tell_object(me,"Danyo: "+tmp1+","+tmp2+","+damage+".\n");
    return tmp1+tmp2;
}
int query_value()
{
  return VALOR*500;
}
/*
void write_message(int dam,string wtype,object me,object him)
{ 
}
*/