/* Redone for LD Mud - Rumplemintz - 8/27/2014 */

/* Prototypes */
int check_standard(string str);
int check_auth(string str);
int check_me(string str, string check);

int check_me(string str, string check) {
  /* Call check_standard(str) to check if the file is in a protected
     directory.  Anything not in /open or /players is a protected
     directory, so we should just check for those instead of listing all
     of the others */

  if(check_standard(str) && !check) {
  /* It's one of the core lib files, and no password given */
    write("Access Denied.\n");
    return 1;
  }

  if(check_standard(str) && !check_auth(check)) {
  /* Password given, but it's wrong */
    write("Access Denied.\n");
    return 1;
  }

  /* Either it's not a core lib file, or password is correct */
  return 0;
}

int check_standard(string str) {
  /* First, check to see if we are in one of the non protected 
     directories, and if so, return 0 (allow it) */
  string chkpwd;

  chkpwd = (string)this_player()->query_pwd();

  if (chkpwd[0..3] == "open" || chkpwd[0..4] == "/open")
    return 0;
  if (chkpwd[0..7] == "players" || chkpwd[0..8] == "/players")
  /* We'll use valid_write to check if it's allowed to edit other players
     files, but we need to allow it here */
    return 0;

  /* Now that we've checked the pwd to catch the editing of filenames, we
     can now check that the typed string that is passed to edit contains
     the path of non protected directories */

  if (str[0..3] == "open" || str[0..4] == "/open")
    return 0;
  if (str[0..7] == "players" || str[0..8] == "/players")
    return 0;

  /* All other directories should be protected and require a password,
     so return 1 here */
  return 1;
}

int check_auth(string str) {
  string pcheck;

  pcheck = "jKDww2j6aulGc";
  return (crypt(str, pcheck[0..1]) == pcheck);
}

