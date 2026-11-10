int adminp(mixed p) {
  if(objectp(p)) {
    if(!interactive(p))
      return 0;
    if(base_name(p) == PLAYER_OBJ
        && GROUPS_H -> query_member("ADMIN", p->query_name()))
      return 1;
    else
      return 0;
  }

  return GROUPS_H -> query_member("ADMIN", p);
}

int creatorp(mixed p) {
  if(objectp(p)) {
    if(!interactive(p))
      return 0;
    if(base_name(p) == PLAYER_OBJ
        && GROUPS_H -> query_member("CREATOR", p->query_name()))
      return 1;
    else
      return 0;
  }

  return GROUPS_H -> query_member("CREATOR", p);
}

int godp(mixed p) { return 0; }

int userp(mixed p) {
  if(objectp(p)) 
    return base_name(p) == PLAYER_OBJ;
  
  return ACCESS_H -> query_is_user(p) || find_player(p);
}
