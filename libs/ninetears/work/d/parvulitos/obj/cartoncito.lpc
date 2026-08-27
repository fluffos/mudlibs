//ZAGROS '99
#include "./../path.h"
inherit "/std/item";

void setup() 
{
  set_name("carton");
  add_alias("papel");
  add_alias("ayuda");
  add_alias("nota");
  set_main_plural("%^RED%^BOLD%^Ultimas notas para los nuevos.%^RESET%^");
  add_plural("notas");
  add_plural("papeles");
  add_plural("ayudas");
  set_short("%^RED%^Ultima nota para los nuevos.%^RESET%^");
  set_long("Estas son las ultimas cosas que debeis recordar:"
	     "%^BOLD%^\nErrores\nAyudas\nOrden\n%^RESET%^Elige una de las 3:\n"
	     "\nQue disfrutes haciendo tu casita.\nPor cierto, una vez salgas de este dominio"
	     " volveran a funcionar el ed dest home go goback goto.\n");
} 

void init()
{
 ::init();
 add_action("orden","orden");
 add_action("errores","errores");
 add_action("ayuda","ayudas");
}

void orden()
{
 write("\nManten ordenados los ficheros y alinealos todo lo que puedas. Por ejemplo si abres una llave, las siguientes "
	 " lineas empiezalas despues de haber sobrepasado la llave con espacios...y luego al cerrar la lllave ponla a "
	 "la misma altura. Con esto facilitaras la lectua de ficheros y posiblemente encuentras mas rapidamente los errores"
	 " que puedan salirte\n");
}

void ayuda()
{
 write("\nSi necesitais ayuda de algun sentido siempre podeis preguntar a los demas por el canal..pero si puede ser "
	"esperaros a que este "+CREATOR+" para resolver vuestras dudas. Podeis entrar al directorio /d/aprendizaje/ para ver"
	" todo lo de esta zona y copiaroslo en vuestro directorio a modo de ejemplo, pero no lo plagieis..solo los teneis para"
	" aprender a programar. \n");
}
 
void errores()
{ 
 write("\nPara compilar ficheros para ver si funcionan debesi poner update <nombre_del_fichero>, como norma general "
	 " al principio os saldran siempre muchos errores. Tranquilos, revisadlo bien, normalemente os dicen en que linea"
	 " se encuentra dicho error. Si no lo sabeis despues de revisarlo, preguntad, pero no antes.\n"
	 " Hay un error muy comun que te pone parse error... Cuando te salga, revisa el fichero por la linea que te "
	 "indique y mira a ver si te falta alguna comilla, parentesis, llave, punto y coma o cualquier tonteria de esas"
	 ". Siempre es algo de eso.\n");
}


