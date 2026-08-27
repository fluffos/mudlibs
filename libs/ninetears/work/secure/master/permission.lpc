int add_lord(string str) {
  if ("/secure/login"->test_user(str)) { // &&
    //high_programmer(geteuid(previous_object()))) {
    positions[str] = LORD;
	save_object("/secure/master",1);
    return 1;
  }
  return 0;
} /* add_lord() */

int remove_lord(string str) {
  //if (high_programmer(geteuid(previous_object())) &&
    if (positions[str] == LORD) {
    map_delete(positions, str);
save_object("/secure/master",1);
    return 1;
  }
  return 0;
} /* remove_lord() */

int add_high_lord(string str) {
    if ("/secure/login"->test_user(str)) { // &&
    //high_programmer(geteuid(previous_object()))) {
    positions[str] = HIGH_LORD;
save_object("/secure/master",1);
    return 1;
  }
  return 0;
} /* add_high_lord() */

int remove_high_lord(string str) {
  //if (high_programmer(geteuid(previous_object())) &&
    if (positions[str] == HIGH_LORD) {
    map_delete(positions, str);
save_object("/secure/master",1);
    return 1;
  }
  return 0;
} /* remove_high_lord() */


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
  //if (high_programmer(geteuid(previous_object()))) {
    if (!permissions[path]) {
      permissions[path] = ([ euid : mask ]);
    } else {
      permissions[path][euid] |= mask;
    }
save_object("/secure/master",1);
    return 1;
  //}
  //return 0;
} /* add_permission() */

int add_read_permission(string euid, string path) {
  if (add_permission(euid, path, READ_MASK)) {
    write("Concedido permiso de lectura a "+capitalize(euid)+" en "+path+".\n");
    return 1;
  }
  return 0;
} /* add_read_permission() */

int add_write_permission(string euid, string path) {
  if (add_permission(euid, path, WRITE_MASK)) {
    write("Concedido permiso de escritura a "+capitalize(euid)+" en "+path+".\n");
    return 1;
  }
  return 0;
} /* add_write_permission() */

int add_grant_permission(string euid, string path) {
  if (add_permission(euid, path, GRANT_MASK)) {
    write("Concedido permiso de administracion a "+capitalize(euid)+" en "+path+".\n");
    return 1;
  }
  return 0;
} /* add_grant_permission() */

int remove_permission(string euid, string path, int mask) {
  //if (high_programmer(geteuid(previous_object())) &&
  //    permissions[path] && permissions[path][euid]) {
    if(  permissions[path] && permissions[path][euid]) {
    permissions[path][euid] &= ~mask;
    if (!permissions[path][euid]) {
      if (m_sizeof(permissions[path]) == 1) {
        map_delete(permissions, path);
      } else {
        map_delete(permissions[path], euid);
      }
    }
save_object("/secure/master",1);
    return 1;
  }
  return 0;
} /* remove_permission() */

int remove_read_permission(string euid, string path) {
  if (remove_permission(euid, path, READ_MASK)) {
    write("Quitado permiso de lectura a "+capitalize(euid)+" en "+path+".\n");
    return 1;
  }
  return 0;
} /* remove_read_permission() */

int remove_write_permission(string euid, string path) {
  if (remove_permission(euid, path, WRITE_MASK)) {
    write("Quitado permiso de escritura a "+capitalize(euid)+" en "+path+".\n");
    return 1;
  }
  return 0;
} /* remove_write_permission() */

int remove_grant_permission(string euid, string path) {
  if (remove_permission(euid, path, GRANT_MASK)) {
    write("Quitado permiso de administracion a "+capitalize(euid)+" en "+path+".\n");
    return 1;
  }
  return 0;
} /* remove_write_permission() */
