#include <std.h>
inherit ROOM;
string creator;
void set_creator(string str);
string query_creator();
void set_creator(string str) {
    creator = str;
}
string query_creator() { return creator; }
string log_access(string area, string dir, string person) {
    string personname;
    personname=person->query_cap_name();
    if(creator)
	write_file("/d/guilds/owner/"+creator, "Area access ["+area+"] by ["+personname+"] of level ["+person->query_level()+
	  "].\n");
    write_file("/d/guilds/"+area, "Area access ["+area+"] by ["+personname+"] of level ["+person->query_level()+
      "].\n");
}
