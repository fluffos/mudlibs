/*    /www/gateways/mudlist.c
 *    from Nightmare IV
 *    a gateway to produce a mudlist for connecting to muds
 *    created by Descartes of Borg 940524
 */

#include <std.h>
#include <daemons.h>

inherit DAEMON;

string gateway(string unused) {
    mapping borg;
    string *muds;
    string str;
    int i, maxi;

    maxi = sizeof(muds=sort_array(keys(borg=(mapping)NETWORK_D->query_known_muds()),
      "alphabetize_muds", this_object()));
    str = sprintf("<TITLE>%s Mudlist Gateway</TITLE><h1>"
      "%s is aware of the following %d muds.</h1><OL>", mud_name(),
      mud_name(), maxi);
    for(i=0; i<maxi; i++)
      str += sprintf("<LI><a href=telnet://%s:%s>%s</a> (%s %s), Driver: %s, "
        "Mudlib: %s %s\n", borg[muds[i]]["HOSTADDRESS"], borg[muds[i]]["PORT"],
        borg[muds[i]]["NAME"], borg[muds[i]]["HOSTADDRESS"],
        (borg[muds[i]]["PORT"]), 
        (borg[muds[i]]["DRIVER"] ? borg[muds[i]]["DRIVER"] : "Unknown"),
        (borg[muds[i]]["MUDLIB"] ? borg[muds[i]]["MUDLIB"] : "Unknown"),
        (borg[muds[i]]["VERSION"] ? borg[muds[i]]["VERSION"] : ""));
    str += "</OL>This mudlist is maintained dynamically through the "
      "Nightmare Mudlib intermud network system.";
    return str;
}

int alphabetize_muds(string a, string b) { return strcmp(a, b); }
