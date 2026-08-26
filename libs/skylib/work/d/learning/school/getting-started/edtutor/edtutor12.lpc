// May's Ed Tutorial for Wizards
// brought to FF on 5 Feb 2001
// brought to Riftwar and modified to work here 7/02/01 - Shaydz

#include "defs.h";
inherit ROOM_OBJ;

void setup(){
    set_light(80);
    set_short("Ed Tutorial 1");
    set_long("ed testroom.c\nn\n1z\n\nz\n"
      "x\n\ned testroom.c\nn\n1,$p\nx\n\n\n"
      "ed testroom.c\nn\n1,$p\nw\nq\n\n"
      "Emergency way out\ned testroom.c\nn\nQ\n");

    add_exit("south",EDTUTOR "edtutor11","path");
    add_exit("exit", GETSTART "start","path");
}
