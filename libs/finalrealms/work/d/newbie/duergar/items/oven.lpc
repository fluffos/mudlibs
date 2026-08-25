/* This is obviously based on Hamlet's code.  Skie doesn't know about giving credit.  So I'll give my own damn self credit. */
inherit "/std/container";
#include "path.h"
 
object lg;
mixed food;
int opened=0;
int latched=1;
#define LIMIT 1
int foo = 0;
 
void init() {
add_action("do_open","open");
add_action("do_close","close");
add_action("get","get");
::init();
}
 
void reset() { foo = 0;}

void setup() {
set_name("oven");
set_short("Baking Oven");
set_long("An old oven used for making breads.  ");
set_weight(100000);
set_value(0);
food = allocate(4);
}
 
int do_open(string str) {
object *contents;
int i;

contents = all_inventory(this_object());
if(str=="oven") {
  if(!opened) {
    write("You open the oven.\n");
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
  say(this_player()->query_cap_name()+" opens the oven.\n");
  return 1;
  }else if((str=="oven")) {
    write("The oven is already open!\n");
  }else {
    notify_fail("Open what?\n");
    return 1; 
}}
}
 
int do_close(string str) {
object *contents;
int i, lastob;
contents = all_inventory(this_object());
if((str=="oven")) {
  if(opened) {
    write("You close the door to the oven so as not to let out the heat.\n");
    say(this_player()->query_cap_name()+" closes the oven.\n");
    lastob = sizeof(contents);
    for(i=0;i<lastob;i++) {
      contents[i]->reset_get(); 
    }
    opened = 0;
    return 1; 
  }else if(!opened) {
    write("It's already closed!\n");
  }else {
    notify_fail("Close what?\n");
    return 1;
  }
}}
 
string long(string str, int dark) {
if((str=="oven")) {
  if(opened) {
    write("The insides of the oven glow a rosey red, and on the "
	 "center rack are various breads to eat.\n");
    write("Dont forget to close the oven!  Otherwise the oven "
	 "will cool and no more breads will be baked today.\n");
    return ::long(str,dark);
  }else {
    return("An old cooking oven.\nThis old oven appears to have "
	 "been used for many years now.  There is no telling how "
	 "many diffrent things have passed through it, or how many "
	 "people it has fed.\n");
  }
}}


void get() {
if(!opened) {
  notify_fail("You must open the oven before you can remove something from "
	"the case.\n");
}}
