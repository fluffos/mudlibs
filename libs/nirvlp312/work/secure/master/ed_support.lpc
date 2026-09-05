/*
 * ed_suppport.c
 *
 * Provides ed() Support
 *
 * Rumplemintz
 *
 */

varargs string normalize_path(string path, object player) {
  string *split_path;
  int j;

  if (objectp(player) && !interactive(player)) {
    // a non interactive player is not a player used for this function
    player = null;
  }

  if (!path || path == "") {
    // get actual path of player, if no player is given, return "root"-path
    return player ? (string)player->query_path() : "/";
  }

  split_path = explode(path, "/");
  if (path[0] != '/' && path[0] != '~' && player) {
    // if the given path does not start with a / or a ~ it's an incomplete
    // string given from the current directory of the player, so this has
    // to be inserted before the path
    split_path = explode((string)player->query_path(), "/") + split_path;
  }

  if (split_path[0][0] == '~') {
    // path starts with ~, special behaviour for home directories
    switch(split_path[0][1]) {
      case 'a'..'z':
        // lower cased home directories belong to creators
        // path is "players" <name of wiz> <rest>
        split_path = ({"players", split_path[0][1..]}) + split_path[1..];
        break;
      case 0:
        if (player) {
          // null path leads to players home
          split_path = ({"players", (string)player->query_real_name()}) +
                         split_path[1..];
        }
        break;
    }
  }

  for (int i=0, j=0; i<sizeof(split_path); i++) {
    switch(split_path[i]) {
      case "":
      case ".":
        // stay in this directory, so nothing to do
        break;
      case "..":
        // one directory back/up in the tree
        --j;
        if (j < 0) {
          // root is the last, root is 0, nothing lower than root
          j = 0;
        }
        break;
      default:
        // count the subdirectories
        split_path[j++] = split_path[i];
    }
  }

  if (j && split_path[<1] == "") {
    split_path[j++] = "";
  }

  return "/" + implode(split_path[0..j-1], "/");
}


//---------------------------------------------------------------------------
string make_path_absolute (string str)

// Absolutize a relative filename given to the editor.
//
// Argument:
//   str : The relative filename (without leading slash).
//
// Result:
//   The full pathname of the file to use.
//   Any non-string result will act as 'bad file name'.
{
  return normalize_path(str, this_interactive());
}

//---------------------------------------------------------------------------
int save_ed_setup (object wiz, int setup)

// Save individual settings of ed for a wizard.
//
// Arguments:
//   wiz   : The wizard using the editor
//   setup : The encoded options to be saved
//
// Result:
//   Return 0 on failure, any other value for success
//
// This function has to save the given integer into a safe place in the
// realm of the given wizard, either a file, or in the wizard itself.
//
// Be aware of possible security breaches: uner !compat, a wirte_file()
// should be surrounded by a temporary setting of the master's euid to
// that of the wizard.
{
  string file;

  if (intp(setup)) {
    file = WIZARD_DIR + (string)wiz->query_real_name() + "/" + ED_SAVE;
    rm(file);
    write_file(file, to_string(setup));
    return true;
  }
  else {
    return false;
  }
}

//---------------------------------------------------------------------------
int retrieve_ed_setup (object wiz)

// Retrieve individual settings of ed for a wizard
//
// Arguments:
//   wiz : The wizard using the editor
//
// Result:
//   The encoded options retrieved (0 if there are none).
{
  string file;
  mixed setup;

  file = WIZARD_DIR + wiz->query_real_name() + "/" + ED_SAVE;
  return (setup = read_file(file)) && to_int(setup);
}

//---------------------------------------------------------------------------
string get_ed_buffer_save_file_name (string file)

// Return a filename for the ed buffer to be saved into
//
// Arguments:
//   this_player() : The wizard using the editor
//   file          : The name of the file currently in the buffer
//
// Result:
//   The name of the file to savfe the buffer into, or 0
//
// This function is called whenever a wizard is destructed/goes netdeath
// while editing.  Using this function, the editing is not done in vain
{
  string *file_ar;
  string path;

  path = WIZARD_DIR + this_player()->query_real_name() + "/" + DEAD_ED;
  if (file_size(path) == -1) {
    mkdir(path);
  }
  file_ar = explode(file, "/");
  file = file_ar[sizeof(file_ar)-1];
  return path + "/" + file;
}

