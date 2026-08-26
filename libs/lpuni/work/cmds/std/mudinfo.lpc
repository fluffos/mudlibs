/* mudinfo.c

Tricky @ Rock the Halo
July 22nd, 2006
List information about a mud on the I3 network

*/

#include <mudlib.h>

int main(string str)
{
    mapping mudlist;
    object i3_ob;
    mixed *data;
    string *mudlist_lc = ({ });
    string list = "", name;
    int index;

    if(!(i3_ob = load_object("/adm/daemons/chmodules/chdmod_i3"))) return 0;

    if(!(mudlist = i3_ob->get_mudlist())) return notify_fail("Mudlist unavailable.\n");

    if(!str || str == "") return notify_fail("Usage: mudinfo <mudname>\n");

    if(str[0..0] == "\"") sscanf(str, "\"%s\"", str);

    if(!str || str == "") return notify_fail("Usage: mudinfo <mudname>\n");

    foreach(string names in keys(mudlist)) mudlist_lc += ({ lower_case(names[0..strlen(str) - 1]) });

    index = member_array(lower_case(str), mudlist_lc);

    if(index == -1) return notify_fail(str + " was not found.\n");

    name = keys(mudlist)[index];

    list += sprintf("Intermud 3 Information for %s\n%78'='s\n", name, "");

    data = mudlist[name];

    if(data[0] == -1)
    list += sprintf("%-:25s %s is UP\n", "State:", name);

    if(data[0] == 0)
    list += sprintf("%-:25s %s is DOWN\n", "State:", name);

    if(data[0] > 0)
    list += sprintf("%-:25s %s is REBOOTING in %i seconds\n", "State:", name, data[0]);

    list += sprintf("%-:25s %s (%i)\n", "IP Address and port:", data[1], data[2]);

    list += sprintf("%-:25s %s\n", "Mudlib:", data[5]);

    list += sprintf("%-:25s %s\n", "Base Mudlib:", data[6]);

    list += sprintf("%-:25s %s\n", "Driver:", data[7]);

    list += sprintf("%-:25s %s\n", "Mud Type:", data[8]);

    list += sprintf("%-:25s %s\n", "Status:", data[9]);

    list += sprintf("%-:25s %s\n", "Admin Email:", data[10]);

    if(data[11] == 0)
    list += sprintf("%-:25s %-=50s\n", "Services:", "None");
    else
    list += sprintf("%-:25s %-=50s\n", "Services:",
      sizeof(keys(data[11])) ? implode(keys(data[11]), ", ") : "None");

    if(data[12] == 0)
    list += sprintf("%-:25s %-=50s\n", "Other Services:", "None");
    else
    list += sprintf("%-:25s %-=50s\n", "Other Services:",
      sizeof(keys(data[12])) ? implode(keys(data[12]), ", ") : "None");

    foreach(string line in explode(list, "\n")) write(line + "\n");

    return 1;
}

string help()
{
    return(HIW + " SYNTAX: " + NOR + "mudinfo <mudname>\n\n"
      "Lists information about a mud connected to the Intermud 3 network.\n");
}


