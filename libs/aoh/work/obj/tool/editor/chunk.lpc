 
chunk(arg) {
   int size;
   if (!holding()) return 0;
   if (security()) return 1;
   if (!object_name) {write("No file name selected.\n"); return 1;}
   sscanf(arg,"%d",size);
   if (!size)
      write("Please give a number.\n");
   else
      chunk_size = size;
   write("Chunk size is now " + chunk_size + ".\n" );
   return 1;
}
 
