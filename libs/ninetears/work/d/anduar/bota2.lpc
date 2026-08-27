inherit "/obj/armour"; 
object *olist;
int i;

void setup()  
{ 
  set_base_armour("slippers");
  set_name("botas plateadas");
  set_short("botas plateadas");
  set_main_plural("botas plateadas");
  set_weight(10);
  set_value(99999);
  set_genero(0);
  set_long("  Estas botas es una curiosa obra de artesania enana, con una "
  "talla que es de una rosa de color plata, con los detalles hasta lo mas "
  "infimo, como por ejemplo un pequenyo tallo con sus espinas minusculas y "
  "unas pequenyas hojas, esta sin ir mas lejos esta a punto de cerrarse.\n");
  set_genero(1);
add_timed_property("str",1,30000);
add_timed_property("dex",1,30000);
} 

void init()
 {
   add_action ("manipular",({"dar","give","coger","get","wear","ponerse",
   "equip","unwear","quitarse","introducir","dejar","drop","vender","sell"
   "valorar","examinar","juzgar"}));
   ::init();
 }

void manipular(object ob)
{
write_file("/d/anduar/logs/bota_manipular",TP->query_cap_name()+" dejo las botas a las "+ctime(time())+"./n Y en la habitacion estaban: "+TO->environment()+" esta ahi cuando se usa el objeto.\n");
}

