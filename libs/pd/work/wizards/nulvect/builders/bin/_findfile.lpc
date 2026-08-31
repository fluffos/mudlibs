#include <std.h>

inherit DAEMON;

string target;
void descend(string str);
object TP=this_player();

int cmd_findfile(string str) {
    if (!str) return notify_fail("Locate what file?
");

    target = str;
    descend("/");
       message("system","\n\n",TP);
    return 1;
}

void descend(string str) {
    string *files = get_dir(str);
    for(int i = 0; i < sizeof(files); i++) {
        if (files[i] == target)
           message("system","%^RED%^%^BOLD%^File has been located at :: %^CYAN%^%^BOLD%^"+str+files[i]+"%^RESET%^", TP);

        if (file_size(str+files[i])==-2) descend(str+files[i]+"/");
    }
}
