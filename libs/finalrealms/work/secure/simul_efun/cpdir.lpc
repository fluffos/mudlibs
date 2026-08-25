/*
 * Copies an entire dir structure to a new location...
 *    -- Magus@Eden, Wahooka@FR, May '97
 */
 
protected int create_path(string *path) {
  int i, j;
  printf("%O", path);
  for(i=0;i<sizeof(path);i++) {
    j = file_size(implode(path[0..i], "/"));
    printf("%O %O\n",implode(path[0..i],"/"), j);
    if(j == -1)
      if(!mkdir(implode(path[0..i], "/")))
        write("Oh horrible failure!\n");
    if(j > 0)
      return 0;
  }
  return 1;
}
 
int cpdir(string src, string dst) {
  string *bits;
  int i;
  if(dst[sizeof(dst)-1] == '/')
    dst = dst[0..sizeof(dst)-2];
  if(src[0] != '/')
    src = "/"+src;
  write(src+"\n"+dst+"\n");
    
  if(file_size(src) < 0) return -1;
  if(file_size(dst) != -2) return -2;

  bits = explode(dst+src, "/");
  seteuid("Root");
  if((i = file_size(implode(bits[0..sizeof(bits)-2], "/"))) == -1)
    if(!create_path(bits[0..sizeof(bits)-2]))
      return -3;
  if(i > 0) return -3;
  if(file_size(dst+src) > 0)
    rm(dst+src);
  printf("%O %O",src, dst+src);
  return cp(src, dst+src);
}
