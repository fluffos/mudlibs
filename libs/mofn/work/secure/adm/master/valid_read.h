int valid_read(string file, mixed user, string func) {
  string nom;

  if(user == master())
    return 1;
  if(base_name(user) == "/secure/adm/login" && file[0..5] == "/news/")
    return 1;

  if(objectp(user) && PO == user && base_name(user) == PLAYER_OBJ) {
    nom = user -> query_name();
    nom = "/u/" + nom[0..0] + "/" + nom + ".o";
    if(file == nom)
      return 1;
  }

  return check_permission("file", file, PERM_READ);
  return 0;
}
