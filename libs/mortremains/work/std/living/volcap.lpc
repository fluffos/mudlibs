// These functions do all the mass and capacity stuff.
// Note that bulk no longer exists...

#include <daemons.h>
#include <mudlib.h>

// This function is the func that determines an object's
// mass according to its height and strength.
// Cyanide, 15 July 1997

int query_mass() {
    int str, ht, x;
    float percy;

    percy = 1.0;
    str = PROPERTY_D->query_str_dam_bonus(this_object());
    percy += (0.0128 * str);

    if (this_object()->query("gender") == "female")
	percy = (percy * 0.85);

    ht = (int)this_object()->query("size");

    switch (ht) {
    case 0..5 : x = (5*ht*ht) - (2*ht) + 12; break;
    default : x = (18*ht*ht) - (77*ht); break;
    }

    x = x * percy;

    if (x>200000) x = 200000;
    return x;
}  //end query_mass();   


// Cyanide added this func 22 July 97. 
// It invokes a function of the same name in the property deamon
// (i.e., /adm/daemons/propertyd.c).

int query_max_cap() {
    int cap;

    cap = PROPERTY_D->query_max_cap(TO);
    return cap;
}

// Cyanide also added this func 22 July 97.
// It should be used to set size from now on in monsters.

int set_size (int size) {
    if (!size||(size<1)) {
	return 0;
    }

    TO->set("SIZE", size);
    TO->set("size", size); 

    TO->set("mass", "@@query_mass");
}
