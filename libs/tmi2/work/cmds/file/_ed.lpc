// The "ed" command.
// Written by Buddha@TMI (2-19-92)
// Expanded by Buddha@TMI (6-10-92) for file locking.
// This file allows entry into the "ed" editor, and keeps track of
// people editing and what file they are editing, so that there are
// no stupid accidents involving two people editing the same file and
// losing changes.
// This is part of the TMI mudlib.  To strip away this header is very wrong.
// Very very wrong.

// Butchered by Robocoder (6-23-93) to use file locking daemon

#include <flock.h>
#include <mudlib.h>
#include <logs.h>
#include <uid.h>

inherit DAEMON ;

int cmd_ed(string file) {
    mixed *dir;
    int test;
    string tmp, err;
   
    if (in_edit(this_player())) {  // get real! you can't do this!
        notify_fail("You are already editing a file.\n");
        return 0;
    }
   
    // set our permissions.
    seteuid(geteuid(this_player()));
   
    // If they haven't given an arguement as to what file...
    if (!file) file=(string)this_player()->query("cwf");
    if (!file) { 
        write("Editing: [no file specified]\n");
        ed();
        return 1;
    }
   
    // get the filename to edit
    tmp = (string)this_player()->query("cwd");
    file = resolv_path(tmp, file);
   
    // Check if there is such a directory ..

    dir = explode(file, "/");
    if (file_size(implode( dir[0..sizeof(dir)-2], "/")) != -2) {
    write("Ed: No such directory file path.\n");
    return 1; }
 
    //  Check to make sure the file isn't actually a directory.
 
    if (directory_exists(file)) {
        notify_fail("Ed: Directory with that name already exists.\n");
        return 0;
    }
 
    // Can we write here?
    err = catch( test = write_file(file, "") );

    if (err) {
        write("Ed: Could not edit requested file.\n" + err );
        return 1;
    }

    // now check and see if the file is being edited by someone else.
    if (test) {
        if (file_size(file) == 0) rm(file);

        if (!(file_lock(file, F_LOCK))) {
            // in this case, it is, so we make a temp copy.
               tmp = "/tmp/" + geteuid(this_player()) + "." + 
               implode(explode(file, "/"), "_");
            write("That file is being edited by " +
                  capitalize(geteuid(query_lock_object(file))) + ".\n");
            if (!(file_lock(tmp, F_LOCK))) {
                write("Ed: Unable to create temporary file.\n");
                return 1;
            }
            // cp(file, tmp);  // Is cp broken?
            if (file_size(tmp)) rm(tmp);
            if (file_size(file) > 0)
                write_file(tmp, read_file(file));
            file = tmp;
        }
    }

    // Now let's make the message you see as you go into ed.
    tmp = "Editing: " + file;
   
    // Can we write here?
    err = catch( test = write_file(file, "") );
    if (err) {
        write("Ed: Could not edit requested file.\n" + err );
	file_lock(file, F_UNLOCK);
        return 1;
    }

    if (!test)
        tmp += " [read only]";
   
    // is it new?
    else if (!file_size(file)) tmp += " [new file]";
    tmp += "\n";
   
    // write the message that we're editing a file...
    write(tmp);

    this_player()->set("cwf",file);
   
    // Yes, the evil admin logging... it can be circumvented, but
    // this tells us at least most of what gets changed.
    // actually, this would be better if it only logged when a crucial
    // file is actually changed.

#ifdef ED_LOG
    log_file(ED_LOG, wrap(capitalize(geteuid(this_player())) + " : \"" +
          file + "\" [" + extract(ctime(time()), 4, 15) + "]"));
#endif
 
    // okay, let's invoke the editor, and have it go to the done function after.
   ed(file, "done_editing");
   
    return 1;
}

void done_editing() {
    string file;
    int access, size;

    if (!geteuid(this_player())) return;

    file = query_lock_filename(this_player());

    access = 0;
    if (file && (size = file_size(file)) >= 0) {
        access = write_file(file, "");
        if (!size) rm(file);
    }

    if ((!file || !(file_lock(file, F_UNLOCK))) && access) {
        seteuid(ROOT_UID);
        log_file("ed_accidents", geteuid(this_player()) + " not listed\n");
    }
    return;
}

void query_editors() {
    query_locks();
}

int clean_up() { return 0; }
