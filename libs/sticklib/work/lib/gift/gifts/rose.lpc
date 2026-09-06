#include <treasure.h>

void
create()
{
    set_id("rose", "single", "red rose");
    set_short("A single red rose");
    set_long("A single red rose from the celestial gardens of love. \
The thorns of the rose have been picked off and a rich, sweet smell \
drifts from the flower.");
}

string 
extra_look()
{
    return "A single red rose";
}

string query_auto_load() {
    int    dummy;
    string chainname;
    sscanf(object_name(this_object()),"%s#%d",chainname,dummy);
    return chainname+":";

}
int get() { return 1; }
int drop() { return 1; }






