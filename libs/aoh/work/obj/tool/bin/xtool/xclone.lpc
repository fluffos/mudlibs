#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xclo"; }

int main(string str ) {
  object obj;
  string file, errlog, error;

  if ( ( ! str ) || ( str == "?" ) ) 
    return notify_fail( "xclo(ne) <filename>\n"), 0;

  
  if(!(file=XFindFile(str))) return 1;
  errlog="/players/"+getuid(cloner)+"/.err";
  if(file_size(errlog)>0) rm(errlog);
  if(obj=find_object(file)) {
    Destruct(obj);
    tell_object( cloner, "Update and clone: "+short_path(file)+"\n");
  } 
  else 
    tell_object( cloner, "Clone: "+short_path(file)+"\n");

  if(!(error=catch(obj=clone_object(file)))) {
    AddXVariable( "clone", obj, 0 );

    if(!MoveObj(obj, environment(cloner), 1))
      tell_object( cloner, "Cannot move object into this room.\n");
    else if(!obj->QueryNoGet()) {
      if(!MoveObj(obj, cloner, 1))
        tell_object( cloner, "Cannot move object into your inventory.\n" );
    }
  } 
  else
    tell_object( cloner, "Error: "+error[1..]);

  return 1;
}





