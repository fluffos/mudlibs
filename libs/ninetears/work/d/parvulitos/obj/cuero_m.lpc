
#include "./../path.h"
inherit "/obj/armour"; 

void setup()  
  { 
 
  set_base_armour("leather");/*Esto pone el tipode armadura del objeto. Ha de ser la primera linea de setup. */

  set_name("armadura de cuero celestial");
  add_alias("armadura");
  add_alias("cuero");
  add_alias("celestiales");  
  set_short("%^ORANGE%^Armadura de cuero%^CYAN%^ celestial%^RESET%^");  
  set_main_plural("armaduras de cuero %^CYAN%^celestiales%^RESET%^"); 
  add_plural("armaduras");
  add_plural("cueros");
  add_alias("celestiales");
  set_long("Es una armadura de cuero rodeada por un aura de poder sin medidas conocidas. Una muy buena armadura."
		" Tiene un halcon en el pecho que parece cobrar vida cuando lo miras.\n");
  set_enchant(5); /*Esta linea encanta la armadura. Se puede encantar desde grado 1 hasta 5 cada cual mas poderosa. El 5 te da una bonificacion defensiva bastante alta.*/
  add_timed_property("str",10,9999);
  add_timed_property("messon","Al ponerte la armadura sientes como el halcon empieza a brillar.\n",9999);/* Lo que te dicen cuando te pones el objeto*/
  add_timed_property("messoff","El halcon se siente inquieto al quitarte la armadura, y te sientes mas debil tambien por ello.\n",9999);
  }

void destruir()
{
 TO->dest_me();
}
 
void init()
{
 ::init();
 if (!(TP->query_creator()))
 {
  write("Esta armadura no entra dentro de tus posibilidades.\n");
  call_out("destruir",1);
 } 
 add_action("llamada","llamar");
}

int llamada(string pp)
{
 object *obj,*atacantes;

 int i,x,max;

 if (pp != "halcon")  
 { 
    notify_fail("Quieres llamar a tu mama??\n");
    return 0;
 } 
  
   if (TO->query_timed_property("halcon"))
    {
     write("Aun es demasiado pronto para llamarlo otra vez. El halcon esta agotado de su ultimo ataque fugaz.\n");
     return 1;
    }
    else
    {
     obj = find_match("all",environment(TP));
     atacantes = TP->query_attacker_list();
     
/*     for (x=0;x<sizeof(atacantes);x++)
        tell_object(find_living("zagros"), atacantes[x]->query_name()+"\n" );
     
  */   

     write("Llamas al halcon en tu ayuda, entonces un rayo de luz abarca la estancia y se introduce en aquellos que"
		" te estan atacando, electrocutandolos desde dentro dolorosamente.\n Luego el halcon vuelve a ti y su figura"
		" pierde intensidad en el cuero.\n");

     TO->add_timed_property("halcon",1,50); /* El parentesis es: (<nombre de la propiedad>,<cantidad de propiedades>,<tiempo de propiedad en activo>)*/

     for (x=0;x<sizeof(atacantes);x++)
     {
       tell_object(atacantes[i], TP->query_cap_name()+" pronuncia unas palabras y de su cuero sale un haz de luz en forma de halcon."
       			" El halcon se alza altivo y te ataca con fiereza metiendose en tu cuerpo. "
       			"Sientes una punzada electrica y por un momento no ves nada.\n");
       atacantes[i]->set_hp(-50000000000);
       atacantes[i]->add_timed_property("passed out",1,20);
       tell_room(environment(TO),TP->query_cap_name()+ " pronuncia un cantico y de su cuero"
       			" sale un haz de luz en forma de halcon. El halcon se alza altivo y ...de repente "
       			" se vuelve contra %^BOLD%^"+atacantes[i]->query_cap_name()+"%^RESET%^ atacandole "
       			"con gran furia y rapidez. Por un momento ves como se convulsiona.\n",atacantes[i]);
     }

     return 1;
    }

}  
  
