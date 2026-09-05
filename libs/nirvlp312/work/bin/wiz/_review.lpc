int cmd_review(string str)
{
 object soul;

 if(str) return 0;
 if((int)this_player()->query_level() < 20)
  return 0;

  soul = this_player();
 write("mout:\t"+(string)soul->query_msgout()+
     "\nmin:\t"+(string)soul->query_msgin()+
     "\nmmout:\t"+(string)soul->query_mmsgout()+
     "\nmmin:\t"+(string)soul->query_mmsgin()+
     "\nmhome:\t"+(string)soul->query_msghome()+"\n");
 return 1;
}
