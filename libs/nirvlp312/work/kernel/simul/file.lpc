/*
 * kernel/simul/file.c
 * simul_efuns for working with files
 * Rumplemintz
 */

#include <limits.h>

int file_time(string path) {
  mixed *v;

  if (sizeof(v = get_dir(path, 4)))
    return v[0];
}

varargs void log_file(string file, string str, status no_trunc) {
  "/etc/filer"->log_file(file, str, no_trunc);
}

int copy_file(string source, string dest) {
  return ({ int }) "/etc/filer"->copy_file(source, dest);
}

varargs int tail(string file, int len) {
  int i, bytes, size;
  mixed text;

  if (len <= 0)
    len = 20;
  if (len > 100)
    len = 100;
  bytes = len * 300;
  size = file_size(file);
  if (size < 0)
    return 0;
  if (bytes > size)
    bytes = size;
  text = read_bytes(file, size-bytes, bytes);
  if (!text)
    return 0;
  text = explode(text, "\n");
  if (text[<1] == "")
    text = text[<len+1..<2];
  else
    text = text[<len..<1];
  for (i=0; i<sizeof(text); i++)
    write(text[i] + "\n");
  return 1;
}

int truncate_file(string file, int position) {
  int i;
  string temp_name;

  if (position < 0)  // just assure this
    raise_error("Bad argument 2 to truncate_file()\n");
  if ((i=file_size(file)) <= position)
    return i; // do nothing if the file isn't longer
  for (i=0; file_size(temp_name = file+i) != -1; i++) // -2 means directory
    ;
  if (!read_bytes(file, 0, 1)) // can we read the file?
    return -1;
  if (!write_file(temp_name,"")) // create the new file
    return -1;
  i = 0;
  while (position-i > MAX_READ) {
    write_bytes(temp_name, i, read_bytes(file, i, MAX_READ));
    i += MAX_READ;
  }
  if (position-i > 0)
    write_bytes(temp_name, i, read_bytes(file, i, position-i));
  if (rename(temp_name, file)) { // 1 means error here! (exception)
    rm(temp_name);  // try to remove the temp file at least
    return -1;
  }
  return position;
}

