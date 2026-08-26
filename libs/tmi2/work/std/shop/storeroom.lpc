// storeroom.c
// This is a little room to serve as local storage for shops. All shops must
// have one to receive items sold at that shop. It doesn't come stocked, if
// you want local shops to keep an inventory on hand you have to clone those
// objects in the shop code and move them to the shop's storeroom.
// Created by Mobydick@TMI-2, 8-25-92

#include <mudlib.h>

inherit ROOM ;

void create() {
	::create() ;
	set ("short", "Shop storeroom") ;
	set ("long", "This is the storeroom for one of the shops.\n") ;
	set ("light", 1) ;
}

// We don't want this to clean_up or the shop will get an error if it tries
// to reference it. The clean_up procedure in the shop will destroy the
// associated storeroom, so this should not be a leak.

void clean_up() { return ; }
