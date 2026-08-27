//ZAGROS '99

inherit "/std/item";

void setup() {
  set_name("papelito");
  add_alias("papel");
  set_main_plural("papelitos");
  add_plural("papeles");
  set_short("Papelito del Editor");
  set_long("Un papelito del tamanyo de una aspirina. En el se puede \"observar\" algo."
	   ".\n");
  set_value(0);
} 

void init()
{
 ::init();
 add_action("lectura","observar");
}

int lectura(string str)
{
 switch (str) 
 {
  case ("papel"):
  case ("papelito"):
       write ("Este papel contiene las acciones basicas que podras realizar"
       	      " con el maravilloso editor del mud. El ed."
       	      "\n ObservarLeer acciones para ver las acciones.\n\n");
       break;
  case ("acciones"):
       write ("El ed es un editor no visible, donde para ver una linea le has de indicar"
       	      "que linea quieres ver especificamente. Cuando estes editando con el ed, recuerda que para "
       	      "finalizar debes poner un punto en la linea siguiente, para poder salir al ed sin editar."
       	      "Si quieres grabar lo que has hecho pon w desde aqui. Tambien te sera util el q para salir"
       	      " y Q para salir sin grabar lo que hayas hecho.\n\n"
              "Las acciones basicas son:\n"
       	      "i\na\nc\nn\nh\nd\n"
       	      "para cualquier comando de estos poned observar <comando>\n\n");
       break;
  case ("c"):
       write("<numero>c <-Te edita la linea en cuestion, en realidad la borra para que la"
       	     "sobreescribas por lo que en verdad estas editando toda la linea otra vez.\n\n");
       break;
  case ("i"):
       write("Sirve para indexar/insertar una linea.\n"
       	     "Ejemplo 12i inserta lineas a partir de la linea 12.\n"
       	     " \n");
       break;
  case ("a"):
       write("Sirve para meter lineas luego de la linea elegida.\n"
       		"Ejemplo 12a mete lineas luego de la linea 12.\n");   	     
       break;
  case ("n"):
       write("Numera el editor, para que al listar un numero indefinido de lineas se vea que numero de linea es.\n"
             "\n");
       break;
  case ("h"):
       write("Te saca el fichero de ayuda del ed junto con estos comandos y otros mas.\n\n");
       break;
  case ("d"):
       write("<numero>d  <-Borra la linea <numero> del fichero.\n\n");
       break;
 default:
       write("que quieres leer de verdad?.\n");
       break;
}
return 1;
}
       
            
       
       
       
       
             
            