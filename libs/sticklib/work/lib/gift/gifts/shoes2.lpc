#include <treasure.h>

void
create()
{
    set_id("shoes");
    set_short("perfect black pair of Moonsilk shoes (worn)");
    set_long("The elaborate runes on the perfect black pair of Moonsilk \
shoes indicate that these shoes belong to Nova.");
}

string 
extra_look()
{
    return "perfect black pair of Moonsilk shoes (worn)";
}

string query_auto_load() {
    int    dummy;
    string chainname;
    sscanf(object_name(this_object()),"%s#%d",chainname,dummy);
    return chainname+":";

}
int get() { return 1; }
int drop() { return 1; }







