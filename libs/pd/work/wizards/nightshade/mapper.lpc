//Mapper daemon for room descriptions
//Written by Nightshade 7-10-01

#include <std.h>

inherit DAEMON;

string nightshady(string str);

string mapper(object who) {

    int tem, flg, i;
    object env, *livs;
    string descript, shady, tempo, nothin;

    env = environment(who);
    tem = 0;
    flg = 0;

    descript = sprintf("%-="+61+"s", env->query_long(0) + "\n");

    sscanf(descript, "%s\n", tempo);

    tempo = nightshady(tempo);
    tempo += "%^GREEN%^|%^RESET%^ ";
    if (env->query_exit("northwest") != "/d/standard/void") {
        livs = all_inventory(find_object(env->query_exit()));
        for(i=0;i<sizeof(livs);i++)
            if(living(livs[i]))
                flg = 1;
        if(flg)
            tempo += "[%^GREEN%^*%^RESET%^] ";
        else
            tempo += "[ ] ";
        flg = 0;
    }
    else
        tempo += "    ";
    if (env->query_exit("north") != "/d/standard/void") {
        livs = all_inventory(find_object(env->query_exit()));
        for(i=0;i<sizeof(livs);i++)
            if(living(livs[i]))
                flg = 1;
        if(flg)
            tempo += "[%^GREEN%^*%^RESET%^] ";
        else
            tempo += "[ ] ";
        flg = 0;
    }
    else
        tempo += "    ";
    if (env->query_exit("northeast") != "/d/standard/void") {
        livs = all_inventory(find_object(env->query_exit()));
        for(i=0;i<sizeof(livs);i++)
            if(living(livs[i]))
                flg = 1;
        if(flg)
            tempo += "[%^GREEN%^*%^RESET%^]\n";
        else
            tempo += "[ ]\n";
        flg = 0;
    }
    else
        tempo += "\n";

    shady = tempo;

    sscanf(descript, "%*s\n%s\n", nothin);
    sscanf(descript, "%s\n", tempo);

    if (nothin == tempo){
        tempo = "";
        tem = 1;
    }
    else
        tempo = nothin;

    tempo = nightshady(tempo);
    tempo += "%^GREEN%^|%^RESET%^    ";
    if (env->query_exit("northwest") != "/d/standard/void")
        tempo += "\\ ";
    else
        tempo += "  ";
    if (env->query_exit("north") != "/d/standard/void")
        tempo += "|";
    else
        tempo += " ";
    if (env->query_exit("up") != "/d/standard/void")
        tempo += "+";
    else
        tempo += " ";
    if (env->query_exit("northeast") != "/d/standard/void")
        tempo += "/\n";
    else
        tempo += "\n";

    shady += tempo;

    sscanf(descript, "%*s\n%*s\n%s\n", nothin);
    sscanf(descript, "%*s\n%s\n", tempo);

    if (nothin == tempo){
        tempo = "";
        tem = 1;
    }
    else
        tempo = nothin;

    if(tem)
        tempo = "";

    tempo = nightshady(tempo);
    tempo += "%^GREEN%^|%^RESET%^ ";
    if (env->query_exit("west") != "/d/standard/void") {
        livs = all_inventory(find_object(env->query_exit()));
        for(i=0;i<sizeof(livs);i++)
            if(living(livs[i]))
                flg = 1;
        if(flg)
            tempo += "[%^GREEN%^*%^RESET%^]-[%^RED%^X%^RESET%^]";
        else
            tempo += "[ ]-[%^RED%^X%^RESET%^]";
        flg = 0;
    }
    else
        tempo += "    [%^RED%^X%^RESET%^]";
    if (env->query_exit("east") != "/d/standard/void") {
        livs = all_inventory(find_object(env->query_exit()));
        for(i=0;i<sizeof(livs);i++)
            if(living(livs[i]))
                flg = 1;
        if(flg)
            tempo += "-[%^GREEN%^*%^RESET%^]\n";
        else
            tempo += "-[ ]\n";
        flg = 0;
    }
    else
        tempo += "\n";

    shady += tempo;

    sscanf(descript, "%*s\n%*s\n%*s\n%s\n", nothin);
    sscanf(descript, "%*s\n%*s\n%s\n", tempo);

    if (nothin == tempo){
        tempo = "";
        tem = 1;
    }
    else
        tempo = nothin;

    if(tem)
        tempo = "";

    tempo = nightshady(tempo);
    tempo += "%^GREEN%^|%^RESET%^    ";
    if (env->query_exit("southwest") != "/d/standard/void")
        tempo += "/";
    else
        tempo += " ";
    if (env->query_exit("down") != "/d/standard/void")
        tempo += "-";
    else
        tempo += " ";
    if (env->query_exit("south") != "/d/standard/void")
        tempo += "| ";
    else
        tempo += "  ";
    if (env->query_exit("southeast") != "/d/standard/void")
        tempo += "\\\n";
    else
        tempo += "\n";

    shady += tempo;

    sscanf(descript, "%*s\n%*s\n%*s\n%*s\n%s\n", nothin);
    sscanf(descript, "%*s\n%*s\n%*s\n%s\n", tempo);

    if (nothin == tempo){
        tempo = "";
        tem = 1;
    }
    else
        tempo = nothin;

    if(tem)
        tempo = "";

    tempo = nightshady(tempo);
    tempo += "%^GREEN%^|%^RESET%^ ";
    if (env->query_exit("southwest") != "/d/standard/void") {
        livs = all_inventory(find_object(env->query_exit()));
        for(i=0;i<sizeof(livs);i++)
            if(living(livs[i]))
                flg = 1;
        if(flg)
            tempo += "[%^GREEN%^*%^RESET%^] ";
        else
            tempo += "[ ] ";
        flg = 0;
    }
    else
        tempo += "    ";
    if (env->query_exit("south") != "/d/standard/void") {
        livs = all_inventory(find_object(env->query_exit()));
        for(i=0;i<sizeof(livs);i++)
            if(living(livs[i]))
                flg = 1;
        if(flg)
            tempo += "[%^GREEN%^*%^RESET%^] ";
        else
            tempo += "[ ] ";
        flg = 0;
    }
    else
        tempo += "    ";
    if (env->query_exit("southeast") != "/d/standard/void") {
        livs = all_inventory(find_object(env->query_exit()));
        for(i=0;i<sizeof(livs);i++)
            if(living(livs[i]))
                flg = 1;
        if(flg)
            tempo += "[%^GREEN%^*%^RESET%^]\n";
        else
            tempo += "[ ]\n";
        flg = 0;
    }
    else
        tempo += "\n";

    shady += tempo;

    sscanf(descript, "%*s\n%*s\n%*s\n%*s\n%*s\n%s", nothin);
    sscanf(descript, "%*s\n%*s\n%*s\n%*s\n%s\n", tempo);

    if (nothin == tempo){
        tempo = "";
        tem = 1;
    }
    else
        tempo = nothin;

    if(tem)
        tempo = "";

    shady += tempo;

    return shady;
}

string nightshady(string str) {
    int x, y;
    string out;

    if(!str || (str == ""))
        return "                         "
        "                                     ";

    out = arrange_string(str, 62);
    return out;
}
