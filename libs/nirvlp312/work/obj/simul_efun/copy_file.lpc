/*
 * copy_file sefun for use with the 'cp' and 'mv' commands
 * Rumplemintz
 */

#define BUFFERSIZE 30000

int cp(string from, string to) {
#if 1 /* Trying something different - Rumplemintz */
  int size;
  int pos;
  string buffer;
  int blocksize;

  size = file_size(from);
  if (size < 0)
    return 0;
  rm(to);
  if (!size)
    return write_file(to,"");
  pos = 0;
  do
  {
    if (size > BUFFERSIZE)
      blocksize = BUFFERSIZE;
    else
      blocksize = size;
    buffer = read_bytes(from, pos, blocksize);
    if (!buffer)
      return 0;
    if (!write_file(to, buffer))
      return 0;
    pos += blocksize;
    size -= blocksize;
  } while (size);
  return 1;
#else
  string str;

  set_this_object(previous_object());
  rm(to);
  str = read_file(from);
  return write_file(to, str);
  /* Don't call this locally, unless you add code to set this_object() back */
#endif
}

