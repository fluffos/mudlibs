#include "path.h"

inherit "/std/room.c";
object arma,armadura;

void setup()
{
   set_short("\n%^ORANGE%^Armeria%^RESET%^\n");

   set_long("Al entrar en la armeria, la luz baja de intensidad de forma estrepitosa. Si no fuera por tu condicion "
	"de inmortal seguramente te hubiera afectado. Las antorchas que hay en la zona estan medio desgastadas "
	"por el paso del tiempo. Al fondo ves un baul entreabierto. Alrededor tuyo ves infinidad de estantes llenos "
	"de armaduras y armas de todo tipo y forma. Para ser dioses les gusta mucho la destruccion por lo visto. Esto "
	"ultimo te hace temblar un poco. Donde te has metido?\n\n");

   set_light(20);

   add_item(({"antorcha","antorchas"}),"A saber desde cuando estan encendidas!!! aqui arriba pueden haber pasado eones.\n");
   add_item ("armaduras","De todo tipo y forma, las armaduras que ves a tu alrededor te hacen estremecer al sentir el"
			  " poder que emana de ellas.\n");
   add_item ("armas","Quien sabe que cosas o quienes habran caido ante ellas. Sientes como te miran con desden, aunque no tienen ojos.... \n");
   add_item (({"estantes","estante"}),"enormes y sobresalientes en calidad, es increible ver el peso que llegan a soportar. Uno al extremo superior de todos"
			  " parece estar medio vacio, con solo una armadura de cuero en el.\n");
   add_item ("baul","\nEs un baul abierto por su imposibilidad de cerrarse de la cantidad de cosas que sobresalen."
			  " Ves un destello cuando te acercas al baul. Sale del fondo del mismo. Al mirarlo con mas detenimiento"
			  " te das cuenta de que se trata del filo de una espada.\n");
   add_item (({"arma","espada"}),"\nAl fondo del baul ves brillar una espada de la que sobresale un rubi rojo.\n");
   add_item (({"armadura","cuero"}),"\nDel estante superior cuelga un cuero de calidad indiscutible. Ves tambien que tiene una"
			    "insignia parecida a un halcon en el pecho, como de color dorado.\n");

   add_feel ("antorcha","Auch!!!, Quema hombre!!!!");
   add_feel (({"armas","armaduras"}),"cuando te acercas a tocarlas tienes la extranya sensacion de que no deberias hacerlo y retiras la mano.\n");

   add_exit("sur",APRENDICES+"pasillo_2","door");   

}

void init()
{
   ::init();
   add_action("coger","coger");
   add_action("trampa",({"go","goback","goto","dest","ed","home"}));
}

int coger(string str)
{
   switch (str)
   {
     case ("espada"):
       if (TP->query_timed_property("espada"))
        {
           write("Ya tienes una espada. Si quieres otra tendras que esperar un tiempo a que se reponga malandrin.\n");
           return 1;
        }
       else
        {
           write("Coges la espada del baul. Al cogerla sientes un escalofrio intenso al que relacionas con"
		     " la mortalidad perdida.\n");
     arma=new(OBJ+"espada_m",1)->move(this_player());
           TP->add_property("reto",1);
           TP->add_timed_property("espada",1,100);
           say(TP->query_name()+" rebusca en el baul y saca una espada al mismo tiempo que un rayo de luz lo alcanza.\n");
           return 1;
        }
       break; 
     case ("cuero"):
     case ("armadura"):
       if (TP->query_timed_property("cuero"))
        {
           write("Como vas a ponerte dos armaduras??? Se un poco consecuente.\n");
           return 1;
        }
       else
        {
           write("Te levantas y estirar tus brazos como puedes para coger la armadura. Al cogerla"
		     " te sientes mas fortalecido, como mas poderoso.\n");
      armadura=new(OBJ+"cuero_m",1)->move(this_player());
           TP->add_timed_property("cuero",1,100);
           say(TP->query_name()+" se alza para coger la armadura de cuero que hay sobre el estante mas elevado.\n");
           return 1;
        }
       break; 
     default:
        notify_fail(str+" posiblemente tenga y reconozca a su duenyo. Mejor no te acerques por si te pasa algo.\n\n");
        return 0;
        break;
   }
   return 1;
}

int trampa()
{
 write("Nonono, Eso es trampa.\n");
 return 1;
}





