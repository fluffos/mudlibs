#define PATH "/room/housing/log/"

void reset(status arg) {
  int i;
  string *files;

  if (arg)
    return;

  files = get_dir(PATH);
  i = sizeof(files);

  if (!i)
    return;

  while(i--)
    if (file_size(PATH+files[i]) > -1)
      write("Results of: "+PATH+files[i]+": "+(rm(PATH+files[i]) ? "REMOVED" : "FAILED")+"\n");
}
