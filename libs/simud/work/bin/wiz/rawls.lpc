#include <const.h>

int main() {
    mapping info;
    int i;

    WIZ_CHECK

    info = ([]);
    info["line"] = 0;
    info["files"] = get_dir(this_player()->make_path_absolute(".")+"/");
    for(i = (sizeof(info["files"])/200)+1;i--;) {
        call_out("rawls",1,info);
    }
    write("Processing...\n");
    return 1;
}

void rawls(mapping info) {
    int max;
    int i;
    if(info["line"] == 0) write("\n");
    max = ((info["line"]+200) < sizeof(info["files"])) ? (info["line"]+200) : sizeof(info["files"]);

    for(;info["line"] < max; info["line"]++) {
        write(info["files"][info["line"]]+"\n");
    }
}