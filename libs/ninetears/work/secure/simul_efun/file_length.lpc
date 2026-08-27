/* This is a very temporary hack.  file_length() seems to crash and burn
   with directories.  So let's wrap it...   -- Hamlet 
*/
int file_length(string file_name) {
   int tmp;

   tmp = file_size(file_name);
   if(tmp < 1)
     return tmp;

   return efun::file_length(file_name);
}
