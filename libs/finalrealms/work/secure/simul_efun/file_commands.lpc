/*
   simul efuns for destructive file commands
   Radix
*/

int rename(string src, string dst)
{
   string tmp;
   if(sscanf(src,"%s.o", tmp) == 1 && src[0..<3] == tmp)
      log_file(".FILES",ctime(time())+": "+this_player(1)->query_name()+
         " MV'ed "+src+" > "+dst+"\n");
   return efun::rename(src, dst);
}
