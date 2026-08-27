#include "path.h"

#include "standard.h";
inherit "/obj/monster";

void setup()
{
    set_name("pirata dan");
    set_short("Pirata Dan");
   add_alias("dan");
   add_alias("pirata");
    set_gender(1);
    set_level(12+random(4));
    set_random_stats(15,5);
    set_str(22);
    set_long("Lo primero que observas es su parche en el ojo, despues las cicatrices, "
    "y tambien notas que esta encorbado y camina ligeramente escorado hacia su derecha."
    " No obstante se le ve aun fuerte y robusto, no es muy apetecible luchar con "
    "el. Parece estar mirando fijamente hacia alguna parte... "
    "podria ser el lejano horizonte, podria ser algun tiempo pasado"
    ". "
    "\n");
    load_chat(75, ({
        1,({
        "'Bien $lcname$, pareces tan feliz como yo de estar aqui. ",
        "'No dejo de pensar en ir a Hoerk algun dia. ",
        ":guinya el ojo",
        "'Aqui elaboran una cerveza que parece pis, hecho en falta la taverna -El Drakkar-. ",
        "'-El drakkar- es la taverna donde comence las aventuras que acabaron con mi carrera. ",
        "'Muchas aventuras comienzan en esa taverna, aunque uno de ha de ser de nivel alto para acabarlas. ",
        }),
        1,"'Nada como el tabaco de mascar cuando los tiburones se acercan demasiado.",
        1,({
        "'Yo podria construir una balsa, supongo, pero mis pobres huesos no estan para muchas aventuras.",
        ":suspira",
        "'Unos barriles, y algo con lo que amarrarlos a una superficie plana serviria. ",
        "'Yo tuve una balsa una vez, la marea te trae y te lleva de aqui para alla.",
        ":hace una mueca.",
        "'Bien, la ultima vez me toco nadar de vuelta, los tiburones no fueron muy malos, pero las serpientes marinas son una pesadilla."
        }),
        1,({
        "'Te preguntas como acabe de esta guisa $lcname$ ?",
        "'Decidi incursionar en Rakhmar's manteniendo rumbo al norte de Hoerk. ",
        "'El bastardo demonio rompio todos mis huesos y luego me dejo pudriendome en sus mazmorras.",
        "'Tiempo despues Kel y Trish me dejaron salir, yo ya estaba en las ultimas.",
        "'Despues de todo no puedo quejarme, salvaron mi vida y me trajeron aqui. ",
        "'Me alegre al verles cuando decidieron retirarse aqui ellos tambien.",
        "'Debes mantenerte alejado de Rakhmar's ,me oyes?  En aquella epoca yo era un guerrero de nivel alto.",
        ":suspira"
        }),
        1,({
        "'Ser un guerrero esta bien, sin desmerecer a los ladrones, como Kel, claro. ",
        ":frunce el cenyo",
        "'Tuvimos nuestras diferencias, antes y ahora, pero hemos ido solventando las mas graves. ",
        "'Siempre es bueno tener amigos para llegar a ser un guerrero temible. ",
        "'Berserk y otras habilidades ayudan a combatir con mas posibilidades de exito aunque luches solo. ",
        "'Pero de cualquier manera, tarde o temprano, necesitaras amigos para emprender alguna aventura. ",
        "'Cuando busques amistades, nada como un clerigo de Taniwha o de Hokemj, para mi gusto."
        }),
        1,({
        ":mira lejos en el mar",
        "'Porque me llaman Pirata Dan ?",
        ":rie",
        "'Tal vez por el parche, perdi el ojo en los tuneles de Banefall ",
//        ":grins",
        "'procura no perder tu algo mas.",
        "'Si entras en esos tuneles recuerda moverte rapido pero en silencio. ",
        "'Alli hay Umber Hulks y Hell hounds que podrian matarte en segundos. ",
        "'No es buen sitio para newbies ciertamente, y mas sabiendo que tambien abundan los drows rondando. ",
        ":escupe."
        }),
    }),
    );
    new("/baseobs/armours/studded")->move(this_object());
   new(OBJ+"boots")->move(this_object());
    new("/baseobs/weapons/short_sword")->move(this_object());
    new("/baseobs/weapons/long_sword")->move(this_object());
    adjust_money(2+random(2),"gold");
   init_equip();
}
