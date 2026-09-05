int cmd_tellhistory(string str)
{
  int tmpi;
  string output;
  mixed *tellhistory;
  int tellhidx;
  
  object obj;
  
  if(str){
    if(!(obj=find_player(str))) {
      write(str+" is not online.\n");
      return 1;
    }
    else if(!(tellhistory=(mixed*)obj->query_tellhistory())){
      write("You can't view "+capitalize(str)+"'s tellhistory.\n");
      return 1;
    }
    
    write("~ ~ ~ ~ ~ ~ "+capitalize(str)+"'s Tellhistory ~ ~ ~ ~ ~ ~\n");
  }
  else {
    tellhistory=(mixed*)this_player()->query_tellhistory();
    obj=this_player();
  }
  
  tellhidx=(int)obj->query_tellhidx();
  
  output="";
  for(tmpi=tellhidx; tmpi < 7; tmpi++)
    output+=(tellhistory[tmpi]?tellhistory[tmpi]+"\n":"");
  for(tmpi=0; tmpi < tellhidx; tmpi++)
    output+=(tellhistory[tmpi]?tellhistory[tmpi]+"\n":"");
  write(output==""?"No tells to show.\n":output);
  
  if(obj->Replyer())
    write("\tReply to: "+(string)obj->Replyer()+"\n");
  return 1;
}