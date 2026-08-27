// Sinister Julio'00
/* la def PROPIEDAD corresponde a la propiedad del mismo nombre del hechizo
   'fuerza'. Es para no poder empunyar el baston si estas afectado por el 
   hechizo. Por lo tanto si cambiara esa propiedad en el hechizo el baston
   se podria empunyar siempre. !cuidado!. Iolo.
*/   
   
   


inherit "/obj/weapon";

#define PROPIEDAD "hechizo_fuerza"
#define NIVEL "25"

void setup()
{
set_base_weapon("twohanded_staff");
  set_name("baston de la Destruccion");
remove_attack("tabla");
  set_main_plural("%^BOLD%^ORANGE%^Bastones de la Destruccion%^RESET%^");
  set_short("Baston de la %^BOLD%^%^BLACK%^Destruccion%^RESET%^");
  add_alias("Destruccion");    
add_alias("destruccion");
add_alias("baston de la destruccion");
  add_alias("baston");
  add_plural("bastones");
  add_plural("bastones de ");
  set_long("   En tus manos esta el que antanyo fue el Baston usado "
  "por varios Dioses para combatir las fuerzas venidas de otros "
  "planos no materiales para destruir este mundo.\n "
  "Madera fina, pulida, imbuida magicamente para que el tiempo no "
  "parezca hacerle mella en ella, crepitaciones de color %^MAGENTA%^purpura, "
  "%^BOLD%^%^BLUE%^azul,%^RED%^ rojo y %^RESET%^%^ORANGE%^marron%^RESET%^ lo recorren de una punta a otra, haciendo "
  "que adquiera un tonalidad que no se puede definir, propia de un "
  "Dios.\n "
  "Cuando lo empunyas, la sensacion es tan intensa, que notas como "
  "el baston drena tu fuerza, haciendo que te encurves de dolor, y "
  "solo, solo al soltarlo notas que has vuelto a ser el de antes.\n");
  set_twohanded(1);
  set_enchant(3);
  set_genero(0);
  add_timed_property("str", -2, 1000000);
  set_weight(query_weight()/(3));

 set_heart_beat(1);
add_property("guild",({"Mago Drow","Mago"}));
}

void heart_beat()
{
   switch(random(100))
   {
        case 0..24 : //ataque de frio
        remove_attack("sinister");
        add_attack("sinister","cold",1,20,1);
        break;
        
        case 25..49 : //ataque de acido
        remove_attack("sinister");
        add_attack("sinister","acid",1,20,1);
        break;
        
        case 50..74 : //ataque de fuego
        remove_attack("sinister");
        add_attack("sinister","fire",1,20,1);
        break;
        
        case 75..100 : //ataque de tierra
        remove_attack("sinister");
        add_attack("sinister","stone",1,20,1);
        break;
   }
}
  
  
// usamos el set_in_use para hacer que el baston solo pueda ser empunyado a partir de 'x' nivel
// cuando la funcion set_in_use se le pasa el valor 1 significa que empunyas
// el objeto. Si vale 0 significa que lo desempunyas. Por ello comprobamos cuando
// vale 1 si tenemos el fuerza echado para no poder empunyarlo         
        
int set_in_use(int i)
{
  if (i==1) {
    if(TP->query_property(PROPIEDAD)) {
      notify_fail("El baston te suelta una descarga electrica cuando intentas "
       "empunyarlo, asique lo dejas al instante.\n");
       return (0);
    }
    if(TP->query_level()<25) {
      notify_fail("Algo te dice que no has alcanzado el suficiente nivel "
      "para poder empunyar este baston sagrado.\n");
        return (0);  
          }
  }
  return ::set_in_use(i);
}

// esta funcion es llamada cuando el baston realiza cualquier ataque. Es por
// si el que lo lleva se lanza el hechizo de fuerza llevando el baston ya empunyado.
// si weapon_attack encuentra la propiedad, lo desempunya.
// (nota para quien lea esto). La forma de 'desempunyar' el baston no es la correcta, 
// pero no me apetecia buscar la funcion, asique que lo haga sinister :P (iolo).


int weapon_attack(object defdr, object atckr,int damage_roll,int critico)
{
  mixed *att_val;                // Guardamos el resultado del golpe
  mixed *temp= keys(attake);
  int c,ret,i,j,z;                   
  int danyo_total = 0;           // Por compatibilidad con combat.c
  object *lista,*armadura,escudo;
  
// ??  this_object()->set_wm_flag(0);
  defensor = defdr;
  atacante = atckr;
  
  
  if(atacante->query_property(PROPIEDAD)) 
  {
     tell_object(atacante,"De repente el baston te suelta una potente descarga electrica "
       "viendote obligado a desempunyarlo.\n");
     TO->move(TP);
     return (0);
  }
  
  for(i=0;i<sizeof(attake);i++)
  {
    att_val=workout_attack(temp[i],attake[temp[i]][1],attake[temp[i]][2],(damage_roll?damage_roll:attake[temp[i]][3]),0,critico); 
    if(att_val[0] == "fumble" )
      if(hacer_pifia()) break;          // Pifia del Ataque. Arma partida
      else continue;                    // Pifia del Ataque. Resto Opcion
    
    if(att_val[0] == "hit")
      if(att_val[1]>25) att_val[1]=25; 
      defensor->weapon_damage(-att_val[1],atacante,TO);
    danyo_total = att_val[1];
    write_message(att_val[0],att_val[1], attake[temp[i]][0],atacante, defensor); 
     
   /* Ajuste de las armaduras despues de recibir un atake. Si tienen         */
   /* resistencias a ese atake se desgastaran solo de esa parte. En caso     */
   /* contrario el danyo que recibe es el doble, pues no esta preparada para */ 
   /* aguantar este tipo de golpes.                                          */
   if(!random(80))
     TO->adjust_cond(-1); // Arma
  
   armadura = defensor->query_worn_ob();      // Las cosas vestidas.
   j = sizeof(armadura);                      // Cuantas cosas vestidas hay.  
   escudo = defensor->query_shields_held();  // El defensor tiene escudo.
   if(att_val[1] < 12)          
   /* Si el golpe es de un danyo menor a 12 solo dara al escudo en caso 
    * de que lo lleve :)
    */
      if(escudo->query_ac(temp[i])) escudo->adjust_cond(att_val[1]/3);
      else escudo->adjust_cond(att_val[1]);
   for(z=0;z<j;z++)
     if(armadura->query_ac(temp[i])) armadura->adjust_cond(att_val[1]/(j+1));    
     else armadura->adjust_cond((att_val[1]/(j+1))*3);    
  }
  return danyo_total;
} /* weapon_attack */
