#include <object.h>
#include <desc.h>
#include <inven.h>

string site_object;

// on_construct must create the construction site.
int on_construct() {
   object ob;

   ob = clone_object( site_object );
}

void set_site_object( string x ) {
   site_object = x;
}

string query_site_object() {
   return site_object;
}

void create() {
   ::create();
/* OBJEDIT { */
/* } OBJEDIT */
}
