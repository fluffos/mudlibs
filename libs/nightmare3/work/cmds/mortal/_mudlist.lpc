#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_mudlist(string str) {
    mapping borg;
    string *muds;
    int i;

    if(!str) borg = (mapping)NETWORK_D->query_known_muds();
    else borg = (mapping)NETWORK_D->query_mud_info(str);
    if(str && !borg) 
      return notify_fail(mud_name()+" is not aware of that mud.\n");
    else if(str)
      message("info", sprintf("%s:\nAddress: %s %s\nDriver: %s    Mudlib: %s %s",
        borg["NAME"], borg["HOSTADDRESS"], borg["PORT"], 
        (borg["DRIVER"] ? borg["DRIVER"] : "Unknown"),
        (borg["MUDLIB"] ? borg["MUDLIB"] : "Unknown"),
        (borg["VERSION"] && borg["MUDLIB"] ? borg["VERSION"] : "")),
        this_player());
    else {
        muds = sort_array((string *)NETWORK_D->query_muds(), "alphabet",
          this_object());
        message("info", sprintf("%s is aware of the following %d muds:",
          mud_name(), sizeof(muds)), this_player());
        message("info", format_page(muds, 3), this_player());
    }
    return 1;
}

int alphabet(string a, string b) {
    if((a = lower_case(a)) == (b = lower_case(b))) return 0;
    else if(a > b) return 1;
    else return -1;
}

void help() {
    message("help", "Syntax: <mudlist ([mud])>\n\n"
      "Without any arguments, it gives a full listing of all muds "
      "with which this mud is capable of communication through "
      "tell, mail, finger, rwho, and other intermud services.  "
      "\n\nWith a mud given as an argument, it gives you detailed "
      "information about that mud.\n\nSee also: finger, mail, rwho, tell",
      this_player());
}
