// rmchar.c by drAnil, remove characters...

main(string str)
{
  object obu;
  string arg1,arg2;
  string obudir, *filet;
  int i;

  if(!str)
{
  message("0","Usage: rmchar <character> <reason>\n",THIS);
  return 1;
}

  if (THIS->query_security() < 71)
  {
    message("0","You are not godly enough!\n",THIS);
    return 1;
  }

  if(sscanf(str, "%s %s",arg1,arg2)!=2)
    arg1=str;
  obu=find_player(arg1);

  if(obu)
    destruct(obu);
  if(file_size("/data/player/"+arg1[0..0]+"/"+arg1+".o")!=-1)
  {
    i = rm("/data/player/"+arg1[0..0]+"/"+arg1+".o");
    obudir="/data/player/"+arg1[0..0]+"/"+arg1+"/";
    filet=get_dir(obudir);
    for (int j=0;j<sizeof(filet);j++)
      rm(obudir+filet[j]);
    rmdir("/data/player/"+arg1[0..0]+"/"+arg1);
  }
  if(!i)
    return 1;

  if (!arg2)
  {
         THIS->force_us("info "+capitalize(str)+" has been removed.");
    write_file ("/log/rmchar", ctime(time()) + " :: " +THIS->query_name()+" removed "+arg1+".\n");
  }
  else
  {
    THIS->force_us("info "+capitalize(arg1)+" has been removed for reason:"+arg2+".\n");
    write_file ("/log/rmchar", ctime(time()) + " :: "+THIS->query_name()+" removed "+arg1+", reason: "+arg2+".\n");
  }

  return 1;
}


