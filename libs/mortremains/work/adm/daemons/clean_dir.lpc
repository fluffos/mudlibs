//      File    :  /adm/daemons/clean_dir.c
//      Creator :  Watcher@TMI  (02/04/93)
//      Updated :  Watcher@TMI  (02/20/93) for recursive dir wipe
//                 Robo@TMI     (01/20/95) iterated version
//
//      This daemon cleans the contents of inputed directory.
//      However, any directory selection within the SECURE (adm)
//      directory tree will be blocked.  If flag is set,
//      even the PROTECTed files will be deleted.
 
#include <mudlib.h>
#include <config.h>
#include <uid.h>
 
inherit DAEMON ;
 
#define PROTECT ({ "README" })
 
protected int remove_contents(string path, int flag);
 
int clean_dir(string dir, int flag) {
    string tmp;
 
    //  Check euid of initiator to confirm correct permissions
    if (geteuid(previous_object()) != ROOT_UID &&
          !adminp(geteuid(previous_object())))
        return 0;
 
    if (!dir || dir == "")
        return 0;
 
    if (file_size(dir) != -2)
        return 0;          //  Not a directory
 
    //  Protect the SECURE directory ... just in case :)
    if (sscanf(dir, SECURE_DIR + "%s", tmp) == 1)
        return 0;
 
    return remove_contents(dir + "/", flag);
}
 
//  This function recursively cleans a specific directory path
//  If flag = 1, it will not protect PROTECTed files
protected int remove_contents(string what, int flag) {
    mixed *dir, *subdir;
    string path, subpath, *protect_list, tmp;
    int loop, subloop, cnt = 0;
 
    //  Initialize
    protect_list = PROTECT;
 
    //  Get directory contents array
    dir = get_dir(what);
    if (!dir || !(loop = sizeof(dir)))
        return -1;
 
    //  Loop through and delete contents of dir array
    do {
        reset_eval_cost(); // Try to avoid max eval'ing
        while (loop--) {
            path = what + dir[loop];
 
            //  If selection is a directory
            //  ... recursively clean and remove it
            if (file_size(path) == -2) {
                // Get subdirectory contents array
                subdir = get_dir(path + "/");
                if (subdir && (subloop = sizeof(subdir))) {
                    while (subloop--) {
                        subpath = path + "/" + subdir[subloop];
 
                        // Loop through and move deeper directories up
                        if (file_size( subpath ) == -2) {
                            while (file_size((tmp = what + subdir[subloop] + cnt)) != -1)
                                cnt++;
                            rename(subpath, tmp);
                        }
 
                        // If file isn't protected ... remove it
                        else if (flag || member_array(subdir[subloop],
                              protect_list) == -1) {
                            rm(subpath);
                        }
                    }
                }
                rmdir(path);
            }
 
            //  If file isn't protected ... remove it
            else if (flag || member_array(dir[loop], protect_list) == -1) {
                rm(path);
            }
        }
 
        dir = get_dir(what);
    } while (dir && (loop = sizeof(dir)));
 
    return 1;
}
