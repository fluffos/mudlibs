int valid_link(string from, string to) {
  if(previous_object() == master())
    return 1;

  // this is a bit odd -- might want to look at the whole calling stack
  return check_permission("file", from, PERM_READ | PERM_LINK) &&
         check_permission("file", to,   PERM_WRITE | PERM_LINK);
}
