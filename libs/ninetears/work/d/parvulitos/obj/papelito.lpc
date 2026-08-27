//ZAGROS '99

inherit "/std/item";

void setup() {
  set_name("papelito");
  add_alias("papel");
  set_main_plural("papelitos");
  add_plural("papeles");
  set_short("Papelito");
  set_long("Un papelito del tamanyo de un alfiler. En el se puede leer algo."
	   ".\n");
  set_value(0);
} 

void init()
{
 ::init();
 add_action("lectura","leer");
}

int lectura(string str)
{
 switch (str) 
 {
  case ("papel"):
  case ("papelito"):
       write ("Este papel contiene los comandos basicos tanto para moverse por el"
       	      " directorio como para interactuar con ficheros.\n"
       	      "  Para ver los comandos de directorios poned leer directorios.\n"
       	      "  Para ver los otros leer comandos.\n\n");
       break;
  case ("directorios"):
       write ("Los comandos basicos son:\n"
       	      "cd\nls\ncp\nmv\nrm\nmkdir\nrmdir\n"
       	      "para cualquier comando de estos poned leer <comando>\n\n");
       break;
  case ("cd"):
       write("cd .. <-Esto sirve para moverte un directorio hacia atras. Pruebalo poniedo dos veces esto mismo.\n"
       	     "cd <nombre> <-Entra en el directorio <nombre>. En este caso pon cd d y luego cd aprendices.\n"
       	     "Ahora estas en el directorio de toda la zona. Escribe cd simplemente y volveras"
       	     " a tu zona(/w/<tu_nombre>).\n\n");
       break;
  case ("ls"):
       write("ls sirve para ver el contenido del directorio en el que estas actualmente.\n");   	     
       break;
  case ("cp"):
       write("cp <origen> <destino> <-Sirve para copiar un fichero de un directorio origen a un directorio destino.\n"
             "Probad a copiar en vuestro directorio lo que hay contenido en /d/aprendices.\n");
       break;
  case ("mv"):
       write("mv <origen> <destino> <-Hace lo mismo que el cp pero borra el origen.\n");
       break;
  case ("rm"):
       write("rm <fichero> <-Borra un fichero a tu eleccion.\n");
       break;
  case ("mkdir"):
       write("mkdir <directorio> <-Crea un directorio de nombre <directorio> en el directorio actual.\n");
       break;
  case ("rmdir"):
       write("rmdir <directorio> <-Borra un directorio vacio 'sin ficheros'.\n");
       break;
 case ("comandos"):
       write("Los comandos basicos son:\n"
       	     "%^BOLD%^more <nombre_fichero>%^RESET%^ <-para ver el fichero sin editarlo. Si poner more here ves la habitacion actual. Si poner more <objeto_en_el_room> ves el fichero del objeto.\n"
       	     "\n%^BOLD%^ed%^RESET%^ <-Ver segundo papelito.\n"
       	     "\n%^BOLD%^call <funcion>%^RESET%^ <-llama la funcion que quieres ejecutandola. Ej: call set_str(90)me <-provadlo y poned ficha.\n\n");
       break;	     
 default:
       write("que quieres leer de verdad?.\n");
       break;
}
return 1;
}
       
            
       
       
       
       
             
            