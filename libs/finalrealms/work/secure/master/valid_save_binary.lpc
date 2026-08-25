 /* this stuff added by asmodean, stolen from sojan, who stole it from
chrisy */
int valid_save_binary(string file)
{
  string *path;
 
  if(!file || file=="")
    return 0;
 
  if(file_name(previous_object()) == "/global/virtual/compiler")
    return 0;
 
  path = explode(file, "/") - ({ "" });
 
  if(!sizeof(path))
    return 0;
 
 
  switch(path[0])
  {
  case "w":
  case "tmp":
  case "open":
  case "d":
    return 0;
 
  case "secure":
  case "std":
  case "global":
  case "net":
    return 1;
 
  case "obj":
    if(sizeof(path)==2)
      return 1;
 
    if(path[1] == "armours" || path[1] == "weapons")
      return 0;
 
    return 1;
  }
  return 0;
}
 
