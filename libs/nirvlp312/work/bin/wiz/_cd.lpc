int cmd_cd(string str)
{
  int qqq;
  string temp2;
  string temp,junk,pwd;
  
 if(str==".") return 0;
  if((int)this_player()->query_level() < 21) return 0;
  
  qqq = 0;
  pwd = (string)this_player()->get_path();

  if(!str) 
    str = "~";
 
  if(str == "..")
  {
    int i;
    qqq = 1;
    i = strlen(pwd) - 2;
    while(i > 0 && pwd[i] != '/')
    i -= 1;
  
    if(!i)
      str = "/";
    else
    {
      str = pwd[0..i-1];
      if(pwd[0] != '/')
        str = "/"+str;
    }
  }
  if(str)
  {
    if(!qqq)
    {
      if(str == "~")
        str = "/players/" +(string)this_player()->query_real_name();
      if(sscanf(str,"~/%s",temp))
        str = "/players/"+(string)this_player()->query_real_name()+"/"+temp;
      else if(sscanf(str,"~%s/%s",temp2,temp) ==2)
        str = "/players/"+temp2+"/"+temp;
    }
    if(!(temp = (string)this_player()->valid_read(str+"/")))
    {
      write("Illegal path!\n");
      return 1;
    }
    if(file_size("/"+temp) != -2)
    {
      write("That directory does not exist.\n");
      return 1;
    }
    pwd = temp;
    this_player()->set_pwd(pwd);
  }
#ifndef __LDMUD__  /* Need this still ? */
  present("soul", this_player())->set_pwd(pwd);
#endif
 write("pwd: "+pwd+"\n");
 return 1;
}
