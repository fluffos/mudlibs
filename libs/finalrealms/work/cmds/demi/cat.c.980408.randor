#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}

static int cmd(string str, object me) {
   string *filenames;
   int loop;

    if (!str) {
        notify_fail("Cat what file ?\n");
        return 0;
        }
    if (str == "*") {
        notify_fail("Forget it!\n");
        return 0;
        }
    filenames = this_player()->get_files(str);

    if (!sizeof(filenames)) {
       notify_fail(str + ": No such file.\n");
       return 0;
    }
    for(loop = 0; loop < sizeof(filenames); loop++) {
       str = filenames[loop];
       if(sizeof(filenames) > 1) {
          write("FILE : " + str + "\n");
       }
        if (file_size(str) < 8196)
         cat(str);
       else {
         write(read_bytes(str,0,8195));
         write("\n ----- TRUNCATED ----- \n");
       }
    }
    return 1;
} /* exa_file() */
 
