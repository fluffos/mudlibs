
/*
 * This object allows the wizard to configure his own directory to
 * allow write, and read access to his/her files, and directories.
 *
 * name is the name of the caller, and file is the full pathname.
 *
 * A return of 1 means that 'name' has valid access.
 * A return of 0 means that access is denied unless that person has
 * an appropriate security access.
 *
 * Regardless of access given here, there is always read/write access 
 * to your ~ /open/ files, and only you and admin have access to files
 * in ~ /private/
 *
 */


status valid_write(string file, string name) {
  if(!file) return 0;

  /* example - quite redundant as it is overrided but gives idea */

  if(sscanf(file,"/players/"+NAME+"/open/%s",file)) return 1;
  if(sscanf(file,"/players/"+NAME+"/private/%s", file)) {
    if(name == NAME) return 1;
  }
  return 0;
}

status valid_read(string file, string name) {
  if(!file) return 0;
  if(valid_write(file, name)) return 1; 
  return 0;
}
