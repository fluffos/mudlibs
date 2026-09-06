/* 
 * Guest Server From the cathedral
 *
 * Allows Guests enter without Guards being Hostile towards them.
 */

#include "../priest.h"

#define GUEST_SAVE PRIEST_SAVE_DIR "guest_save"

string *guests;


create() {
    restore_object(GUEST_SAVE); 
    if(!guests) guests=({});
}


void
add_guest(string guest) {
    guests += ({guest});
    guests = sort_array(guests, #'>);
    save_object(GUEST_SAVE);
}


void
remove_guest(string guest) {
    guests -= ({guest});
    save_object(GUEST_SAVE);
}


status
query_guest(string guest) {
    return member(guests, guest)>=0;
}


string
query_guests() {
    int i;
    string *strs;

    if(sizeof(guests)>0) {
	i = sizeof(guests);
	strs = allocate(i);
	while(--i>=0) strs[i] = capitalize(guests[i]);

	return "Guests of the Cathedral:" +
	sprintf("\n%-78#s",implode(strs,"\n"));
    }
    return "No guests.";
}

debug() {
    printf("guests: %O\n", guests);
}

