/* mudlist.c

Tricky @ Rock the Halo
July 22nd, 2006
Lists muds on the I3 network

*/

#include <mudlib.h>

mapping mudlist;
string *mudlist_arr;
int up, total;

string buildMudlist(string mudname, string libname, string driver, int all);

string getNextArg(string *argv, int argc)
{
    string ret;

    ret = argv[argc];

    if(argv[argc][0..0] != "\"") return ret;

    sscanf(implode(argv[argc..<1], " "), "\"%s\"", ret);

    return ret;
}

int main(string str)
{
    object i3_ob, pager;
    string *argv = ({ }), *tmp_argv = ({ });
    string list = "", header = "";
    string mudname = "", libname = "", driver = "";
    int argc = 0;
    int all = 0, sorted = 0;
    int not = 0;

    if(!(i3_ob = load_object("/adm/daemons/chmodules/chdmod_i3"))) return 0;

    if(!(mudlist = i3_ob->get_mudlist())) return notify_fail("Mudlist unavailable.\n");

    if(str && str != "")
    {
    tmp_argv = explode(str, " ");

    foreach(string t in tmp_argv) if(t != "") argv += ({ t });

    }

    while(argc < sizeof(argv))
    {

    switch(argv[argc])
    {
    case "!":
        not = 1;
        break;
    case "-a":
    case "--all":
        all = 1;
        break;
    case "-s":
    case "--sorted":
        sorted = 1;
        break;
    case "-sa":
    case "-as":
        all = 1;
        sorted = 1;
        break;
    case "-m":
    case "--mud":
        argc++;

        if(argc >= sizeof(argv)) return notify_fail("Error [mudlist]: mudname required.\n");

        mudname = getNextArg(argv, argc);

        argc += sizeof(explode(mudname, " ")) - 1;

        if(not)
        {
        mudname = "! " + mudname;
        not = 0;
        }

        break;
    case "-l":
    case "--lib":
        argc++;

        if(argc >= sizeof(argv)) return notify_fail("Error [mudlist]: libname required.\n");

        libname = getNextArg(argv, argc);

        argc += sizeof(explode(libname, " ")) - 1;

        if(not)
        {
        libname = "! " + libname;
        not = 0;
        }

        break;
    case "-d":
    case "--driver":
        argc++;

        if(argc >= sizeof(argv)) return notify_fail("Error [mudlist]: driver name required.\n");

        driver = getNextArg(argv, argc);

        argc += sizeof(explode(driver, " ")) - 1;

        if(not)
        {
        driver = "! " + driver;
        not = 0;
        }

        break;
    }

    argc++;
    }

    mudlist_arr = keys(mudlist);

    if(sorted) mudlist_arr = sort_array(mudlist_arr, 1);

    total = sizeof(mudlist_arr);
    up = 0;

    list += buildMudlist(mudname, libname, driver, all);

    header  = sprintf("I3 Mudlist (%i Up, %i Total)%s\n", up, total, !all ? "" : " - A '*' next to the name means the mud is up.");
    header += sprintf("%-78'='s\n", "");
    header += sprintf(" %-:20s %-:18s %-:15s %-:15s %5s\n", "Mudname", "Lib", "Driver", "IP", "Port");
    header += sprintf("%-78'='s\n", "");

    list = header + list;

    pager = clone_object(OBJ_PAGER);
    pager->page(list + "\n");

    return 1;
}

string buildMudlist(string mudname, string libname, string driver, int all)
{
    string list = "";

    if(mudname != "" || libname != "" || driver != "") total = 0;

    foreach(string name in mudlist_arr)
    {
    mixed val;

    if(mudname != "")
    {

        if(mudname[0..0] == "!")
        {
        if(lower_case(name[0..strlen(mudname[2..]) - 1]) == lower_case(mudname[2..]))
            continue;
        } else
        if(lower_case(name[0..strlen(mudname) - 1]) != lower_case(mudname))
        continue;

    }

    if(libname != "")
    {
        val = mudlist[name];

        if(libname[0..0] == "!")
        {
        if(lower_case(val[5][0..strlen(libname[2..]) - 1]) == lower_case(libname[2..]))
            continue;
        } else
        if(lower_case(val[5][0..strlen(libname) - 1]) != lower_case(libname))
        continue;

    }

    if(driver != "")
    {
        val = mudlist[name];

        if(driver[0..0] == "!")
        {
        if(lower_case(val[7][0..strlen(driver[2..]) - 1]) == lower_case(driver[2..]))
            continue;
        } else
        if(lower_case(val[7][0..strlen(driver) - 1]) != lower_case(driver))
        continue;

    }

    if(mudname != "" || libname != "" || driver != "") total++;

    val = mudlist[name];

    if(!pointerp(val)) continue;

    if(val[0] == 0 && !all) continue;

    if(val[0] > 0)
    {
        list += sprintf("%s is rebooting\n", name);

        continue;
    }

    if(val[0] != 0) up++;

    list += sprintf("%s%-:20s %-:18s %-:15s %-:15s %5i\n",
      val[0] != 0 && all ? "*" : " ", replace_string(name, "%^", "%%^^"), val[5], val[7], val[1], val[2] );
    }

    return list;
}

string help()
{
    string help = HIW + " SYNTAX: " + NOR;

    help += @ENDHELP
mudlist [-a|s] [!] [-m <mudname>] [-l <libname>] [-d <drivername>]

Lists the muds connected to the Intermud 3 network.
The options available are:
-a              List every mud up or down
-s              List muds sorted alphabetically (by name)
-m <mudname>    Filter muds with this name
-l <libname>    Filter muds using this library
-d <drivername> Filter muds using this driver

-a and -s can be combined into either -sa or -as

-m, -l and -d can be combined (with '!') to list a partial selection of muds.
(The names are case-insensitive and can be just the first few letters. If
there are spaces in a name, use quotes such as "dead souls".)

Long options are:
-a: --all
-s: --sorted
-m: --mud
-l: --lib
-d: --driver

ENDHELP;

    help +=       HIW + " EXAMPLES:" + NOR + @ENDHELP

%^GREEN%^mudlist%^RESET%^
  Lists muds online
  unsorted

%^GREEN%^mudlist -s -l lpuni%^RESET%^
  Lists muds online
  using a lib starting with lpuni
  sorted

%^GREEN%^mudlist -a ! -l dead -m l%^RESET%^
  Lists all muds (up or down)
  not using a lib starting with dead
  mud name starting with a 'l'
  unsorted

%^GREEN%^mudlist -a ! -l dead -s ! -m l -d dgd%^RESET%^
  Lists all muds (up or down)
  not using a lib starting with dead
  mud name not starting with a 'l'
  driver name starting with dgd
  sorted

ENDHELP;

    return help;
}


