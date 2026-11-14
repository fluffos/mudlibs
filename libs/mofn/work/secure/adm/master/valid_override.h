int valid_override(string file, string name) {
  if(file == SEFUN_OBJ)
    return 1;
  if(ACCESS_H -> has_permission(file, "efun", name, PERM_WRITE))
    return 1;

  return 0;
}
