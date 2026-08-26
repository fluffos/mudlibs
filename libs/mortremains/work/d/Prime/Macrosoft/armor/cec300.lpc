// FILE:	cec300.c
// PURPOSE: MAJOR body armor.
// Created by Cyanide, 12 Mar 2000

#include <mudlib.h>

inherit ARMOR ;

void create() {
    seteuid(getuid());

    set("author", "cyanide");
    set ("id", ({ "armor", "cec", "class 300" }) ) ;
    set ("short", "CEC Class 300 Body Armor") ;
    set ("long", @EndLong
A full suit of rigid cerametal plates including articulated joints and a
helmet, it is a sealed environment, with climate control and gas filters.
EndLong
    );
    set("dest_at_sell", 1);
    set_armor_type("full plate");  
    set("value", 7150);
    set("armor", 9);
    set("stat_mod", ([
      "strength" : 4
    ]) );
    set("equip_func", "equipme");
    set("unequip_func", "unequipme");
}

int equipme() {
    TP->resistance("acid", 50);
    TP->resistance("cold", 30);
    TP->resistance("fire", 30);
    TP->resistance("electricity", 90);
    TP->resistance("suffocation", 10);
    return 1;
}

int unequipme() {
    TP->resistance("acid", 200);
    TP->resistance("cold", 334);
    TP->resistance("fire", 334);
    TP->resistance("electricity", 112);
    TP->resistance("suffocation", 1000);
    return 1;
}

/* EOF */
