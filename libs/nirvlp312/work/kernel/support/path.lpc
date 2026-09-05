/*
 * /kernel/support/path.c
 *
 * This file is inherited by several objects, one is /kernel/master.c and
 * thus the pointed brackets < > cannot be used in #include-statements in
 * this file. All paths have to be absolute!
 */

varargs string normalize_path(string path, object player) {
  string *p;
  int i,j;

  if (!objectp(player) || !interactive(player))
    player = 0;
  if (path=="")
    return player ? player->query_path() : "/";
  if (path=="/")                 // because of the while() 6 lines below,
    return path;
  p = explode(path,"/");
  if (player && path[0]!='/' && path[0]!='~')
    p = explode(player->query_path(),"/") + p;
  while (sizeof(p) && p[0]=="")  // skipping all "" at the beginning prevents
    p = p[1..];                  // indexing errors below
  if (p[0][0]=='~') {
    if (sizeof(p[0]) > 1) {
      switch (p[0][1]) {
      case 'a'..'z':
        p = ({ "players", p[0][1..] }) + p[1..];
        break;
      case 'A'..'Z':
        p = ({ "domains", lower_case(p[0][1..]) }) + p[1..];
        break;
      }
    }
    else {
      if (player)
        p = ({ "players", player->query_real_name() }) + p[1..];
    }
  }
  for (i=j=0; i <sizeof(p); i++) {
    switch(p[i]) {
    case "":
    case ".":
      break;
    case "..":
      j--;
      if (j<0)
        j = 0;
      break;
    default:
      p[j++]=p[i];
    }
  }
  if (j && p[<1]=="")
    p[j++]="";
  return "/"+implode(p[0..j-1],"/");
}

