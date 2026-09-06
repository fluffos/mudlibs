#include <treasure.h>

void
create()
{
    set_name("hazardous finn reward");
    set_id("prize");
    set_short("The Yearly Hazardous Finn Reward");
    set_long("This is the prize given to those who accurately guess the \
number of Finns risking their lives during some special holiday \
season or day: Christmas, Midsummer, Easter and New Year. \n\
Year 1998, Midsummer: 9 drowned Finns. Winner, Njien, with the guess of 11.");
}

string 
extra_look()
{
    return "The Yearly Hazardous Finn Reward";
}

string query_auto_load() {
    int    dummy;
    string chainname;
    sscanf(object_name(this_object()),"%s#%d",chainname,dummy);
    return chainname+":";

}
int get() { return 1; }
int drop() { return 1; }







