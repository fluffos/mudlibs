int valid_write(string file, mixed user, string func) {
  string nom;
  if(user == master())
    return 1;

// special case for player save files
  if(objectp(user) && PO == user && base_name(user) == PLAYER_OBJ) {
    nom = user -> query_name();
    nom = "/u/" + nom[0..0] + "/" + nom + ".o";
    if(file == nom)
      return 1;
  }

  return check_permission("file", file, PERM_WRITE);
}
