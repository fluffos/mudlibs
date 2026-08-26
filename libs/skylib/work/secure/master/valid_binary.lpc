/*  -*- LPC -*-  */

int valid_save_binary(string fname) {
  string *bits;

  bits = explode(fname, "/");
  switch (bits[0]) {
/*
    case "secure" :
      if ( bits[ 1 ] == "simul_efun" )
        return 0;
*/
    case "global" :
    case "std" :
    case "secure" :
    case "cmds" :
    case "d" :
    case "p" :
      return 1;
    case "obj" :
      //if (sscanf(bits[sizeof(bits)-1], "%*s-%*d%*s") == 0)
        return 1;
  }
  return 0;
} /* valid_save_binary() */
