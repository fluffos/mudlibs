/* drown.h
// This is the include file for the underwater rooms.  This file
// contains the functions to query players inventory for a brooch
// (~WaterWorld/obj/brooch.c), and damage them if it is not found.
// 6 June 97- adapted to a header file from a room coded by Dragoon.
*/

#define ITEM "#BROOCH#"
#define DAMAGE 5
#define TIMER 5

int water_on;
void turn_on() {
    if (water_on==1) return;
    call_out("drown",TIMER);
    water_on=1;
    return;
}

void drown() {
    int flag;
    object inv;
    flag=0;
    inv=first_inventory( this_object() );
    while (inv!=0) {
	if (!present(ITEM,inv) && interactive(inv)) {
	    inv->receive_damage( DAMAGE );
	    tell_object( inv , "You swallow a lung full of air.\n");
	    flag=1;
	}
	inv=next_inventory(inv);
    }
    if (flag==1) {
	call_out( "drown" , TIMER );
	water_on=0;
    }
}
