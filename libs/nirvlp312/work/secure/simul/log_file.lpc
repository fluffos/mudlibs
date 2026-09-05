#define MAX_LOG_SIZE 50000

void log_file(string file, string str) {
  string file_name;
  int *st;

  file_name = "/log/" + file;
  if (sizeof(st = get_dir(file_name, 2)) && st[0] > MAX_LOG_SIZE) {
    catch(rename(file_name, file_name + ".old")); /* No panic if failure */
  }
  set_this_object(previous_object());
  write_file(file_name, str);
}

void syserror(string err_message) {
  log_file("sys_errors", err_message + "\n");
}

