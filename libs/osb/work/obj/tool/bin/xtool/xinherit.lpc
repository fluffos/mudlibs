#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xinh"; }

object *SubNodes(object obj) {
  int s;
  object *objs;
  string *inlist;

  if(!obj) return 0;
  inlist=inherit_list(obj);
  s=sizeof(inlist);
  objs=({});
  while(s-->1) objs=({find_object(inlist[s])})+objs;
  return objs;
}

void Inheritance(object obj, string func, string pre) {
  int i, s;
  object *ln;
  string str;

  if(!obj) return;
  str=pre+" "+ObjFile(obj);
  if(func) {
    str=sprintf("%-50.50'.'s", str+ " " );
    if(function_exists(func, obj)==object_name(obj))
      str+=sprintf("%19.19'.'s"," "+func);
    else str+=sprintf("%19.19'.'s","");
  }
  tell_object( cloner, str+"\n" );
  ln=SubNodes(obj);
  for(i=0; i<sizeof(ln); i++) ln=ln-SubNodes(ln[i]);
  s=sizeof(ln);
  for(i=0; i<s; i++) Inheritance(ln[i], func, pre+".....");
}

int main(string str ) {
  int s;
  object obj;
  string *strs, *inlist;

  notify_fail( "xinh(erit) <object> [function]\n" );
  if ( ( ! str ) || ( str == "?" ) )
    return 0;

  if(!(strs=(explode(str, " ")-({""})))) return 0;
  if(obj=XFindObj(strs[0])) {
    inlist=inherit_list(obj);
    s=sizeof(inlist);
    while(s--) {
      if(catch(call_other(inlist[s], "???"))) {
	tell_object( cloner,
		     "Failed to load all inheritance objects.\n");
        return 1;
      }
    }
    obj=find_object(inlist[0]);
    if(sizeof(strs)==1) Inheritance(obj ,0 ,"");
    else Inheritance(obj, strs[1], "");
  }
  return 1;
}
 


