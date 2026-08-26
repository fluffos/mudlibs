
/**
 * This method is used by the driver to determine whether or
 * not an efun can be overriden in an object.
 * @param file the file that is trying to override the efun
 * @param func the efun we are trying to override
 * @param filename the full filename of the file being compiled
 * @return 1 if we are allowed to override, 0 if not
 */
int valid_override( string file, string func, string filename ) {
    string *bing;

    bing = explode( file, "/") - ({"", "."});
    switch( bing[0] ) {
      case "secure" :
        return 1;
      case "std" :
      case "obj" :
      case "simul_efun" :
      case "global" :
      case "cmds" :
        return func != "snoop";
      default :
        return 0;
    }

} /* valid_override() */
