// Amuleto maldito de KenderMore

inherit "/obj/armour"; 

int inicial;
int frecuencia=20;
// 45
int mirando=0;
object room;
object objeto=TO;
object ultimo=TO;

void setup()  
  { 
  set_base_armour("amulet");
  set_name("amuleto de kender");   
  set_short("Amuleto de %^MAGENTA%^Kender%^RESET%^"); 
  add_alias("amuleto");
  set_main_plural("Amuletos de %^MAGENTA%^Kender%^RESET%^"); 
  add_plural("amuletos de kender");  
  set_long("Es un fino alambre redondo que rodea a una pequenya capa de cristal en cuyo "
  	   "interior se pueden observar vivos colores que parecen en movimiento.");
  add_property("maldito",1);
  reset_drop();
  set_value(0);
} 

void init()
{
if (mirando==0)
	{
		mirando=1;
   call_out("mirar",frecuencia+random(10));
   	}
   ::init();
}

/* void heart_beat()
{
	call_out("mirar",1);
}
*/

 int mirar()
{ 

  int i,i2,i3;
  int robado;  
  object *hab, *mochila;
  object *equipo;
  string donde;
  mirando=0;

/*
if (TP->query_time_on()>-86400)
	{
	destruct(TO);
	}
  */
  // inicial++;
  // if (inicial<4){return 1;}
room=ENV(TP);
// tell_object(find_player("ather"),"La room es: "+room->query_short()+"\n");

hab = all_inventory(room);
  
  for (i=0;i<sizeof(hab);i++)
  {
//  tell_object(find_player("ather"),"Comprobando: "+hab[i]->query_short()+"\n");
    if(hab[i]->is_player() && hab[i]->query_short()!=TP->query_short())     
    {  
	    	equipo = all_inventory(hab[i]);
for (i2=0;i2<sizeof(equipo);i2++)
    		{    		
    		if (equipo[i2]->query_short()=="Mochila sin Fondo")   		
    			{
			mochila = all_inventory(equipo[i2]);    				
			for (i3=0;i3<sizeof(mochila);i3++)    				
				{		
    					if (random(3) && mochila[i3]->query_short()!=ultimo->query_short())    			
    					{ 
// tell_object(find_player("ather"),"Antes: "+objeto->query_short()+" Ahora: "+mochila[i3]->query_short()+"\n");    						   				    					
    					objeto=mochila[i3];    					
    					}
				}
    			}
    		if (!equipo[i2]->query_in_use() && equipo[i2]->query_short()!=ultimo->query_short())
    			{    			
    			if (random(3) && equipo[i2]->query_short()!="moneda" )    			
    			{    				    			
// tell_object(find_player("ather"),"Antes: "+objeto->query_short()+" Ahora: "+equipo[i2]->query_short()+"\n");    						   				    					    				
    			objeto=equipo[i2];
    			}
    			}
    		}
    	
    		if (TO->query_property("robando")) return 1;    				
    		TO->add_timed_property("robando",1,20);

    				call_out("robar",3,objeto,hab[i],ENV(TP));
	
    		}
    		    
 
}

if (mirando==0)
	{
	mirando=1;
   call_out("mirar",frecuencia+random(10));
   	}
}


int robar(object objeto,object quien,object room)
{
object *hab;
int i;
int peso;

int probabilidad;
int nivel=TP->query_level();

ultimo=objeto;

if (TP->query_guild_ob()!="/std/guilds/rogues/thief")
	{
	nivel=nivel/2;
	}

if (nivel<10){probabilidad=10;} 
if (nivel>=10 && nivel<15){probabilidad=20;} 
if (nivel>=15 && nivel<20){probabilidad=40;} 
if (nivel>=20 && nivel<25){probabilidad=57;} 
if (nivel>=25 && nivel<30){probabilidad=62;} 
if (nivel>=30 && nivel<35){probabilidad=70;} 
if (nivel>=35 && nivel<40){probabilidad=80;} 
if (nivel>=40 && nivel<45){probabilidad=85;} 
if (nivel>=45 && nivel<50){probabilidad=90;} 
if (nivel>=50){probabilidad=95;} 

hab = all_inventory(room);

  for (i=0;i<sizeof(hab);i++)
  {
    if(hab[i]==quien)     
    {   
    	peso=objeto->query_weight()/3;
//    	tell_object(find_player("ather"),"Prob: "+probabilidad+" Objeto: "+objeto->query_short()+" Peso: "+peso+"\n");
    	probabilidad=probabilidad-peso-random(probabilidad);
//    	tell_object(find_player("ather"),"Prob Final: "+probabilidad+"\n");
    	if (probabilidad>0)    	
    	{    	    	
    	write_file("/d/anduar/logs/kender.txt",""+TP->query_cap_name()+" ROBO "+objeto->query_short()+" A "+quien->query_cap_name()+" CON FECHA: "+ctime(time())+".\n");    		
	objeto->move(TP);	 
	}
	if (probabilidad<0)    	
	{
	write_file("/d/anduar/logs/kender.txt",""+TP->query_cap_name()+" FALLO ROBANDO "+objeto->query_short()+" A "+quien->query_cap_name()+" CON FECHA: "+ctime(time())+".\n");    				
	tell_object(quien,"Notas a "+TP->query_cap_name()+" hurgando en tu equipaje!!\n");
	tell_room(ENV(quien),quien->query_cap_name()+" pilla a "+TP->query_cap_name()+" hurgando en su equipaje.\nVaya pillada!!\n",quien);	
	
	quien->attack_ob(TP);
	}	
    	TO->remove_timed_property("robando");
if (mirando==0)
	{
		mirando=1;
   call_out("mirar",frecuencia+random(10));
   	}
    	return 1;
    }
  }	
  
  TO->remove_timed_property("robando");
  if (mirando==0)
	{
		mirando=1;
   call_out("mirar",frecuencia+random(10));
   	}
  return 1;	
  
}


