int verify_dir_exists(string filename)
   {
   string *elems;
   string path;
   int i;
   seteuid(getuid());
   if (file_size(filename) == -2)
      return 1;
   if (file_size(filename) > -1)
      return -1;
   elems = explode(filename, "/");
   path = "";
   for (i=0; i < sizeof(elems); i++)
      path += "/" + elems[i];
   mkdir(path);
   if (file_size(path) != -2)
      return -1;
   return 1;
   }

