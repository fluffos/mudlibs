/**
 * Controller for loading objects from files.
 *
 * @alias LoadController
 */
inherit CommandController;

inherit ValidationLib;

int load_files(mapping model, string verb);

int execute(mapping model, string verb) {
  return load_files(model, verb);
}

int load_files(mapping model, string verb) {
  int count = 0;
  foreach (mixed *f : model["files"]) {
    string file = f[0];
    if (FINDO(file)) {
      if (!model["quiet"]) {
        stderr_msg(sprintf("%s: %s: Already loaded. Destruct or use the "
                           "reload command.\n", verb, file));
      }
      continue;
    }

    string err = catch (load_object(file); publish);
    if (err) {
      stderr += sprintf("%s: %s: Caught error %s\n", verb, file, err); 
      mixed *last_err = get_error_file(MasterObject->get_wiz_name(file));
      if (last_err && !model["quiet"]) {
        stderr_msg(sprintf("%s line %d: %s\n", 
                           last_err[0], last_err[1], last_err[2]));
      }
      continue;
    } else {
      count++;
      if (model["verbose"]) {
        stdout_msg(sprintf("%s: %s: loaded\n", verb, file));
      }
    }
  }
  
  if (!model["quiet"]) {
    stdout_msg(sprintf("%s: %d object%s loaded.\n", 
                       verb, count, (count != 1 ? "s" : "")));
  }
  return count;
}
