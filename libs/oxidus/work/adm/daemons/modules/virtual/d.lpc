inherit STD_DAEMON;

public nomask object compile_object(string file) {
  string
   *dir_parts,
    top_level_zone,
    zone_path,
    relative_path,
    e;
  /** @type {STD_OBJECT} */ object result;
  /** @type {STD_VIRTUAL_SERVER} */ object zone_daemon;

  dir_parts = explode(file, "/");
  top_level_zone = dir_parts[1];
  zone_path = "/d/" + top_level_zone + "/controller";

  e = catch(zone_daemon = load_object(zone_path));
  if(e) {
    log_file("VIRTUAL", e);
    return 0;
  }

  if(!zone_daemon)
    return 0;

  relative_path = implode(dir_parts[2..], "/");
  e = catch(result = zone_daemon->compile_object(relative_path));

  if(e) {
    log_file("VIRTUAL", e);
    return 0;
  }

  return result;
}
