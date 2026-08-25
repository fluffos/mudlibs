
/* Permision handling stuff */

int check_permission(string euid, string *path, int mask) {
/*
 * Permission to /foo gives permission to /foo/bar/gnu too!
 */
  string p;
  int    i;

  p = "";
  for (i = 0; i < sizeof(path); i ++) {
    p = p + "/" + path[i];
    if (permissions[p] && permissions[p][euid] & mask) {
      return 1;
    }
  }
  return 0;
} /* check_perminssion() */

mapping query_permissions() { return permissions + ([ ]); }

int add_permission(string euid, string path, int mask) {
  if (high_programmer(geteuid(previous_object()))) {
    if (!permissions[path]) {
      permissions[path] = ([ euid : mask ]);
    } else {
      permissions[path][euid] |= mask;
    }
    save_object("/secure/master" ,1);
    return 1;
  }
  return 0;
} /* add_permission() */

int add_read_permission(string euid, string path) {
  if (add_permission(euid, path, READ_MASK)) {
    write("Added read permision for "+euid+" to "+path+".\n");
    return 1;
  }
  return 0;
} /* add_read_permission() */

int add_write_permission(string euid, string path) {
  if (add_permission(euid, path, WRITE_MASK)) {
    write("Added write permision for "+euid+" to "+path+".\n");
    return 1;
  }
  return 0;
} /* add_write_permission() */

int add_grant_permission(string euid, string path) {
  if (add_permission(euid, path, GRANT_MASK)) {
    write("Added write permision for "+euid+" to "+path+".\n");
    return 1;
  }
  return 0;
} /* add_grant_permission() */

int remove_permission(string euid, string path, int mask) {
  if (high_programmer(geteuid(previous_object())) &&
      permissions[path] && permissions[path][euid]) {
    permissions[path][euid] &= ~mask;
    if (!permissions[path][euid]) {
      if (m_sizeof(permissions[path]) == 1) {
        map_delete(permissions, path);
      } else {
        map_delete(permissions[path], euid);
      }
    }
    save_object("/secure/master" ,1);
    return 1;
  }
  return 0;
} /* remove_permission() */

int remove_read_permission(string euid, string path) {
  if (remove_permission(euid, path, READ_MASK)) {
    write("Removed read permision for "+euid+" to "+path+".\n");
    return 1;
  }
  return 0;
} /* remove_read_permission() */

int remove_write_permission(string euid, string path) {
  if (remove_permission(euid, path, WRITE_MASK)) {
    write("Removed write permision for "+euid+" to "+path+".\n");
    return 1;
  }
  return 0;
} /* remove_write_permission() */

int remove_grant_permission(string euid, string path) {
  if (remove_permission(euid, path, GRANT_MASK)) {
    write("Removed write permision for "+euid+" to "+path+".\n");
    return 1;
  }
  return 0;
} /* remove_write_permission() */
