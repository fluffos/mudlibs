inherit "/obj/armour"; 

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
add_timed_property("str",2,30000);
} 

void init()
 {
   add_action ("dar",({"dar","give"}));
   add_action ("coger",({"coger","get"}));
   add_action ("wear",({"wear","ponerse","equip"}));
   add_action ("unwear",({"unwear","quitarse"}));
   add_action ("introducir",({"introducir"}));
   add_action ("dejar",({"dejar","drop"}));
   add_action ("vender",({"vender","sell"}));   
   add_action("more",({"path","debug"}));
   ::init();
 }

void dar(object ob)
{
write_file("/d/anduar/logs/bota_dar", TP->query_cap_name()+" dio las botas a las

 "+ctime(time())+". Y en la habitacion estaban: "+TO->environment()+".\n", 0);
}
void dejar(object ob)
{
write_file("/d/anduar/logs/bota_dejar", TP->query_cap_name()+" dejo las botas a 

las "+ctime(time())+". Y en la habitacion estaban: "+TO->environment()+".\n", 0)
;
}
void coger(object ob)
{
write_file("/d/anduar/logs/bota_coger", TP->query_cap_name()+" cogio las botas a

 las "+ctime(time())+". Y en la habitacion estaban: "+TO->environment()+".\n", 0
);
}
void wear(object ob)
{
write_file("/d/anduar/logs/bota_wear", TP->query_cap_name()+" se puso las botas 

a las "+ctime(time())+". Y en la habitacion estaban: "+TO->environment()+".\n", 
0);
}
void vender(object ob)
{
write_file("/d/anduar/logs/bota_vender", TP->query_cap_name()+" se puso las bota
s 
a las "+ctime(time())+". Y en la habitacion estaban: "+TO->environment()+".\n", 
0);
}
void unwear(object ob)
{
write_file("/d/anduar/logs/bota_wear", TP->query_cap_name()+" se quito las botas

 a las "+ctime(time())+". Y en la habitacion estaban: "+TO->environment()+".\n",
 0);
}
void introducir(object ob)
{
write_file("/d/anduar/logs/bota_introducir", TP->query_cap_name()+" introducio l

as botas a las "+ctime(time())+". Y en la habitacion estaban: "+TO->environment(
)+".\n", 0);
}

void  more()
{
write("Eres un curioso mirando cosas que no deves. \n");
return(1);
}
