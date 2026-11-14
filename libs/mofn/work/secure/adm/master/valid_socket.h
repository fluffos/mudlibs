int valid_socket(object caller, string f, mixed *info) {
  if(caller == master())
    return 1;

  return 1;
  return check_permission("file", f, PERM_SOCKET);
}
