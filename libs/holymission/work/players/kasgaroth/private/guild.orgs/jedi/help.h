help(str) {
  string path;
 
  if(!str) return;
 
  if(str=="levels") {
    GM->list_levels(guild);
    return 1;
  }
  path="/players/kelly/guild/helpdir/"+str;
 
  if(file_size(path)>0)
    cat(path);
  else
    return 0;
 
  return 1;
}
  

 
