inherit "/std/container";
#include "path.h"
 
object lg;
mixed food;
int opened=0;
int latched=1;
#define LIMIT 1
int foo = 0;
 
void init() {
add_action("do_open","abrir");
add_action("do_close","cerrar");
add_action("get","sacar");
::init();
}
 
void reset() { foo = 0;}

void setup() {
set_name("horno");
set_short("Horno");
set_long("Un viejo horno usado para cocer pan.  ");
set_weight(100000);
set_value(0);
food = allocate(4);
}
 
int do_open(string str) {
object *contents;
int i;

contents = all_inventory(this_object());
if(str=="horno") {
  if(!opened) {
    write("Abres el horno.\n");
if(foo<LIMIT) {
foo++;
for(i=0;i<sizeof(food);i++) {
  object ob1, ob2, ob3;
  ob1 = clone_object(ITEMS+"dbread1");
  ob2 = clone_object(ITEMS+"dbread2");
  ob3 = clone_object(ITEMS+"dbread3");
  ob1->move(this_object());  ob2->move(this_object());
  ob3->move(this_object());
  }
 }
  opened=1;
  say(this_player()->query_cap_name()+" abre el horno.\n");
  return 1;
  }else if((str=="horno")) {
    write("El horno ya esta abierto!\n");
  }else {
    notify_fail("abrir el que?\n");
    return 1; 
}}
}
 
int do_close(string str) {
object *contents;
int i, lastob;
contents = all_inventory(this_object());
if((str=="horno")) {
  if(opened) {
    write("Cierras el horno para que no se escape el calor.\n");
    say(this_player()->query_cap_name()+" cierra el horno.\n");
    lastob = sizeof(contents);
    for(i=0;i<lastob;i++) {
      contents[i]->reset_get(); 
    }
    opened = 0;
    return 1; 
  }else if(!opened) {
    write("Ya esta cerrado!\n");
  }else {
    notify_fail("Cerrar el que?\n");
    return 1;
  }
}}
 
string long(string str, int dark) {
if((str=="horno")) {
  if(opened) {
    write("El interior del horno luce con un tono rosaceo, y "
	 "en una rejilla central hay varios panes.\n");
    write("No te olvides de cerrar el horno! Si se enfria "
	 "no se podran cocer mas panes por hoy.\n");
    return ::long(str,dark);
  }else {
    return("Un viejo horno de cocer.\nEste viejo horno aparenta "
	 "haber sido usado por muchas generaciones. A saber la "
	 "de cosas que habran pasado por su interior, y a cuantos "
	 "habra alimentado.\n");
  }
}}


void get() {
if(!opened) {
  notify_fail("Deberas abrir el horno antes de poder coger algo "
	"de su interior, no crees?\n");
}}
