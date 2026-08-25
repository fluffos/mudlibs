/*
 * this object is saved in every directory and contains the permissions
 * for the directory.
 */

#define MASTER "secure/master"
#define PERMISSIONS "permissions"
#define READ_DEFAULT 1
#define WRITE_DEFAULT 0
#define LOAD_DEFAULT 1

string path;
/*
 * the owner of a directory can only be changed by High Programmers.
 * the owner always has RWL permissions, and is the only person other
 * tha High Programmers who can change the permissions to a directory.
 */
string owner;
/*
 * permission to get a directory listing, and to read files in the
 * directory.
 */
mixed read;
/*
 * permission to add, alter and delete files to/in/from the directory.
 * this also enables the ability to mkdirs in the directory.
 */
mixed write;
/*
 * permission to load objects in the directory.
 * NB: it is theoretically possible for someone to have wrie permission
 *     without load permissions, which is stupid, this is intended so
 *     that objects can be read without being loadable, or loadable
 *     without being writable.
 */
mixed load;

void create() {
  owner = 0;
  path = 0;
  read = READ_DEFAULT;
  write = WRITE_DEFAULT;
  load = LOAD_DEFAULT;
}

int start_up(arg) {
  int i;

  i = file_size(arg+PERMISSIONS+".o");
  if (i == -2) {
    log_file("SECURITY", PERMISSIONS+".o directory in "+arg+".\n");
    return -1;
  }
  if (i == -1) {
    path = arg;
    log_file("SECURITY", "null owner permissions created for "+arg+".\n");
    return 0;
  }

int restore_object(arg+PERMISSIONS,1);
  if (path != arg) {
    log_file("SECURITY", "corrupt permissions for "+arg+".\n");
    dest_me();
  }
  return 1;
}

int save() {
save_object(path+PERMISSIONS,1);
  return 1;
}

void dest_me() {
  destruct(this_object());
}

void set_owner(arg) {
  if ((file_name(previous_object()) != MASTER)
      && !MASTER->high_programmer(this_player()->query_name()))
    return "You don't have the security clearance.";
  owner = arg;
}

string add_read(arg) {
  if ((file_name(previous_object()) != MASTER)
      && !MASTER->high_programmer(this_player()->query_name()))
    return "You don't have the security clearance.";
  if (intp(arg)) read = arg;
  if (!stringp(arg)) return "Invalid argument to add_read().";
  if (intp(read)) {
    if (!read) {
      read = ({ arg });
      return 0;
    }
    return "Directory already has read set to 1.";
  }
  if (!pointerp(read)) {
    read = ({ arg });
    return "Read permissions corrupt!  Read set to "+arg+".";
  }
  read += ({ arg });
  return "";
}

rm_read(arg) {
  int i;

  if ((file_name(previous_object()) != MASTER)
      && !MASTER->high_programmer(this_player()->query_name()))
    return "You don't have the security clearance.";
  if (!stringp(arg)) return "Invalid argument to rm_read().";
  if (intp(read)) return "Read already set to "+arg+".";
  if (!pointerp(read)) {
    read = READ_DEFAULT;
    return "Read permissions corrupt!  Read set to "+READ_DEFAULT+".";
  }
  if ((i = member_array(arg, read)) < 0)
    return arg+" did not have read permission.";
  read = delete(read, i);
}

add_write(arg) {
  if ((file_name(previous_object()) != MASTER)
      && !MASTER->high_programmer(this_player()->query_name()))
    return "You don't have the security clearance.";
  if (intp(arg)) write = arg;
  if (!stringp(arg)) return "Invalid argument to add_write().";
  if (intp(write)) {
    if (!write) {
      write = ({ arg });
      return 0;
    }
    return "Directory already has write set to 1.";
  }
  if (!pointerp(write)) {
    write = ({ arg });
    return "Write permissions corrupt!  Write set to "+arg+".";
  }
  write += ({ arg });
}

rm_write(arg) {
  int i;

  if ((file_name(previous_object()) != MASTER)
      && !MASTER->high_programmer(this_player()->query_name()))
    return "You don't have the security clearance.";
  if (!stringp(arg)) return "Invalid argument to rm_write().";
  if (intp(write)) return "Write already set to "+arg+".";
  if (!pointerp(write)) {
    write = WRITE_DEFAULT;
    return "Write permissions corrupt!  Write set to "+WRITE_DEFAULT+".";
  }
  if ((i = member_array(arg, write)) < 0)
    return arg+" did not have write permission.";
  write = delete(write, i);
}

add_load(arg) {
  if ((file_name(previous_object()) != MASTER)
      && !MASTER->high_programmer(this_player()->query_name()))
    return "You don't have the security clearance.";
  if (intp(arg)) load = arg;
  if (!stringp(arg)) return "Invalid argument to add_load().";
  if (intp(load)) {
    if (!load) {
      load = ({ arg });
      return 0;
    }
    return "Directory already has load set to 1.";
  }
  if (!pointerp(load)) {
    load = ({ arg });
    return "Load permissions corrupt!  Load set to "+arg+".";
  }
  load += ({ arg });
}

rm_load(arg) {
  int i;

  if ((file_name(previous_object()) != MASTER)
      && !MASTER->high_programmer(this_player()->query_name()))
    return "You don't have the security clearance.";
  if (!stringp(arg)) return "Invalid argument to rm_load().";
  if (intp(load)) return "Load already set to "+arg+".";
  if (!pointerp(load)) {
    load = LOAD_DEFAULT;
    return "Load permissions corrupt!  Load set to "+LOAD_DEFAULT+".";
  }
  if ((i = member_array(arg, load)) < 0)
    return arg+" did not have load permission.";
  load += delete(load, i);
}
