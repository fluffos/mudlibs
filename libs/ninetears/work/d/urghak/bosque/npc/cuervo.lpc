// Xerxes '02

inherit "/obj/monster";

void setup() {
  set_name("cuervo");
  set_short("Cuervo");
  set_main_plural("Cuervos");
  set_random_stats(6,14);
  set_long("Cuervo\n\nEs un cuervo de un oscuro plumaje, que vive de los "
           "restos descompuestos de los seres del bosque. No "
           "obstante. Una escalofriante sensacion te recorre la "
           "espina dorsal al fijarte en los ojos de la criatura, "
           "que te escudrinyan, y parecen leerte el alma. Te preguntas "
           "si este cuervo esconde dentro de si algo mas que lo que "
           "aparenta.\n");
  set_aggressive(0);
  set_race("monster");
  set_level(2+random(4));
  set_gender(1);
  set_wimpy(30);
  load_chat(80,
  ({
    1, ":mordisquea los ojos del cadaver de un pequenyo animal.",
    1, ":revolotea entre los arboles, desprendiendo una sinietra sombra sobre tu cabeza.",
    1, ":grazna vilmente.",
  }));
  set_move_after(20+random(10), 20+random(10));
} /* setup() */
