inherit "/room/camino_avalon/camino_avalon";

void setup()
{
	do_desc(0);
     set_long("%^CYAN%^Camino en construccion a Avalon: Extremo%^RESET%^\n\n"
      "Has llegado a lo que parece ser el fin provisional del camino, "
	"donde se espera seguir abriendo paso hacia Avalon. Parece que "
	"tendras que volver sobre tus pasos, ya que este lugar estara "
	"bastante abandonado hasta que los elfos prosigan con su "
	"obra. La zona esta poblada de arboles que impiden el paso, "
	"formando un bonito lugar que visitar. Algunas hojas cubren "
	"el suelo de forma que al caminar sobre ellas produces un "
	"debil y agradable sonido que te recuerda aquellas primeras "
	"veces que paseaste por los bosques.\n\n");

add_item(({"hojas", "suelo", "hoja"}), "El suelo esta cubierto por multitud "
	"de hojas, quizas demasiadas para esta zona. Junto a un arbol "
	"observas demasiada maleza.\n");

add_item(({"maleza"}), "Mucha maleza. Al acercarte, notas una pequenya "
	"depresion en el firme, como existiese algo oculto bajo ella... "
	"o bajo tierra.\n");

add_exit("norte","/room/camino_avalon/camino05","road");
add_exit("abajo", "/room/camino_avalon/hoyo00", "hidden");
modify_exit("abajo", ({"function", "go_abajo",
	"message", "@Escuchas un debil golpe seco y $N desaparece de tu vista."}));
	// para poner hacia donde se va -> $F
}

int go_abajo(string str, object ob, string special_mess)
{
	tell_object(ob, "Te introduces entre la maleza y caes.\n");
	if (ob->query_stoneskin_spell())
		ob->adjust_hp(-random(5)-1);
	else
		ob->really_adjust_hp(-random(5)-1);
	return 1;
}
