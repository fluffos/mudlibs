// Vilat 26.09.2002
inherit "/std/item";

void setup() {
 set_name("libro");
 set_short("Libro");
 add_alias("Libro");
 set_main_plural("Libros");
 add_plural("libros");
 set_weight(10);
 set_value(0);
 }

void init() {
 ::init();
 add_action("lectura","leer");
 }

int lectura(string str) {
 if (!str || str!="libro") return notify_fail("Sintaxis: leer libro\n");
if (catch(file_size("/open/biblioteca/"+TO->query_property("texto"))) ) return notify_fail("Parece que te han timado, este libro esta en blanco...\n");
TP->more_string(read_file("/open/biblioteca/"+TO->query_property("texto"),0,file_size("/open/biblioteca/"+TO->query_property("texto"))),"Libro");
 return 1;
 }
