// por Nagash '01 Marzo Version 2.0 xD

/**************************************************************/
/********************* LANZA MATAGIGANTES *********************/
/**************************************************************/

inherit "/obj/weapon";

void fun_absorve_vida( object yo,object el, int danyo );
int weapon_attack( object him, object me, int bonusdanyo, int critico ); 

void setup() 
{
  set_base_weapon( "twohanded axe" );
  set_name( "Lanza Matagitantes" );
  set_short( "Lanza %^YELLOW%^BOLD%^Matagigantes%^RESET%^" );

  add_alias( ( {"lanza","matagigante"} ) );
  set_main_plural( "Lanzas %^YELLOW%^BOLD%^Matagigantes%^RESET%^" );
  add_plural( ( {"lanzas","matagiganes"} ) );
  set_long( " Ves una enorme y larga lanza de mas de dos metros. "
           "Esta hecha de una madera negra muy resistente, su "
           "punta esta cubierta de acero, formando dos filos "
           "para penetrar mejor la piel de los enemigos. A la "
           "mitad de ella vemos una delicada empunyadura traba"
           "jada sobre oro dandole al portador de la lanza la "
           "subjecion necesaria.\n\n" );
  
 /************ CARACTERISTICAS ***************/
  set_twohanded( 1 );
  set_weight( 600 );
  set_value(200000);
  set_enchant( 3 );
  //ssadd_property("guild","Guerrero"); // solo para guerreros
}


void init()
{
  ::init();
}

/****************** BONIFICADORES DE USO *******************/
set_in_use( int i ) 
{
  // aumentamos al portador en 1 la fuerza temporalmente
  TO->add_timed_property("str",1,50000);
  
  add_timed_property( "messon", "* Al empunyarla tu miedo a grandes "
                      "adversarios se desvanece.\n",1000000 );
  add_timed_property( "messoff", "* Notas como una sensacion de "
                      "miedo recubre todo tu ser.\n" ,1000000 );
    
  return::set_in_use(i);
}

/****************** BONIFICADOR AL DANYO BASE ****************/
query_damage_roll()
{
  return random(6);
}

/************* WEAPON ATTACK--> DESCRIPCION DEL ATAQUE ********/
int weapon_attack( object him, object me, int bonusdanyo, int critico ) 
{

  // Variables que utilizare.
  int danyo = ::weapon_attack( him, me );
  string def = him->query_cap_name();
  string ata = me->query_cap_name();
  string arma = query_short();
  
  // Descripcion que sale al golpear.
  switch( danyo ) 
  {
    case 1..5:
      tell_object( me, "* Rozas levemente la cara de "+def+" con tu "
                        +arma+".\n" );
      tell_object( him,"* "+ata+" te roza levemente la cara con su "+arma+".\n" );
      tell_room( ENV( me ), "* "+ata+" roza levemente la cara a "+def+" con"
                           " su "+arma+".\n",( {him,me} ) );
    break;
  
    case 6..10:
      tell_object( me, "* Aranyas el cuerpo de "+def+" con tu "+arma+".\n" );
      tell_object( him, ata+" te aranya el cuerpo con su "+arma+".\n" );
      tell_room( ENV( me ), ata+" aranya el cuerpo de "+def+" con su "
                           +arma+".\n",( {him,me} ) );
    break;
    
    case 11..15:
      tell_object( me, "* Haces un tajo profundo a "+def+" en la pierna "
                       "con tu "+arma+".\n" );
      tell_object( him, ata+" te hace un tajo profundo en la pierna con "
                        "su "+arma+".\n" );
      tell_room( ENV( me ), ata+" hace un tajo profundo en la pierna de"
                            " "+def+" con su "+arma+".\n",( {him,me} ) );
    break;
    
    case 16..20:
      tell_object( me, "* Realizas una seria herida en "+def+" con tu "
                       +arma+".\n" );
      tell_object( him, ata+" te realiza una seria herida con su "+arma+
                        ".\n" );
      tell_room( ENV( me ), ata+" realiza una seria herida a "+def+" con"
                            "su "+arma+".\n",( {him,me} ) );
    break;
    
    case 21..25:
      tell_object( me, "Rebanas parte de las tripas de "+def+" con tu "
                       +arma+".\n" );
      tell_object( him, ata+" te rebana parte de las tripas con su "+arma+
                        ".\n" );
      tell_room( ENV( me ), ata+" rebana parte de las tripas de "+def+
                            " con su "+arma+".\n",( {him,me} ) );
    break;
    
    case 26..35:
      tell_object( me, "Haces gritar de dolor a "+def+" con tu "+arma+
                       ".\n" );
      tell_object( him, ata+" te hace gritar de dolor con su "+arma+".\n" );
      tell_room( ENV( me ), ata+" hace gritar de dolor a "+def+" con su "
                            +arma+".\n",( {him,me} ) );
    break;
    
    case 36..50:
      tell_object( me, "Aciertas a golpearle a "+def+" en todo el cuello "
                   +arma+".\n" );
      tell_object( him, ata+" te acierta a dar con su "+arma+" en tu "
                   "cuello.\n" );
      tell_room( ENV(me), ata+" acierta a golpear a "+def+" en todo su "
                "cuello.\n", ( {him,me} ) );
    break;
    
    case 51..100:
      tell_object( me, "Destrozas parte del cuerpo de "+def+" impidiendole "  
                  "su movilidad.\n" );
      tell_object( him, ata+" te destroza el cuerpo con su "+arma+" impidi"
                  "endote que te muevas normalmente.\n" );
      tell_room( ENV(me), ata+" destroza literalmente con su "+arma+" a "
                +def+" no dejadole moverse normalmente.\n",( {him,me} ) );
    break;
    
    case 101..1000:
      tell_object( me, "Dejas al descubierto el corazon de "+def+
                  "notando como su cuerpo se estremece.\n" );
      tell_object( him, ata+" te deja al descubierto el corazon con su "
                  +arma+" notando como tu cuerpo se estremece.\n" );
      tell_room( ENV(me), ata+" deja al descubierto el corazon de "+def+
               " con su "+arma+"estremeciendose de dolor.\n",( {him,me} ) );
    break;
    }
    // Ahora viene el random de chupar vida o no.. 1/3 de hacerlo
    fun_absorve_vida(me,him,danyo);
} // final funcion WEAPON_ATTACK


/********************* FUNCION FUN_ABSORVER_VIDA  ********************/
void fun_absorve_vida( object yo,object el, int danyo)
{  
  int diflevel;
  int suerte = random(3);
  int vida;
  
  // restamos los levels
  diflevel = ( (el->query_level()) - (yo->query_level()) );
  
  // si el k ataka tiene mas level absorvemos vida por random 1/4
  if( (diflevel > 0) && (suerte == 2) ) 
  {
    vida = ( (danyo*diflevel ) / 20 );
    // limitamos a recuperar 20 de vida. xD 
    if( vida > 20 ) 
    { 
      vida = 20; 
    }
    yo->adjust_hp( vida );
    tell_room( ENV(yo), "% Ves como absorves parte "
                "de su %^BOLD%^vitalidad%^RESET%^!\n",( {el,yo} ) );
    tell_object( yo,"% Absorves parte de la %^BOLD%^vitalidad%^RESET%^ al "
                "golpearlo!\n" ); 
    tell_object( el,"% Parte de tu %^BOLD%^vitalidad%^RESET%^ es absorvida "
                 "por tu adversario!\n" );
  }
}/* final funcion FUN_ABSORVER_VIDA */
