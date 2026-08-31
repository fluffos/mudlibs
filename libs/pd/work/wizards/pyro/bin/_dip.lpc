// Command written by Pyro

#include <std.h>

inherit DAEMON;

#define USE_NONCALLABLE_FUNCTIONS 1

void deep_inherit(string fileName, string funcName);
void deep_inherit_recursive(string fileName, int depth, string funcName);

string* deepFileList;

int cmd_dip(string str) {
  string fileName, funcName;
  object fileObj;
  if(sscanf(str, "%s %s", funcName, fileName) != 2)
    return notify_fail("Syntax: dip [function name] [file/object]\n");
  fileObj = get_object(fileName);
  if(funcName == "all" && fileObj && !function_exists(funcName, fileObj, USE_NONCALLABLE_FUNCTIONS)) {
    foreach(string fun in functions(fileObj)) { cmd_dip(fun+" "+fileName); }
    return 1;
  }
  if(!fileObj) return notify_fail("Could not find "+fileName+"\n");
  if(!function_exists(funcName, fileObj, USE_NONCALLABLE_FUNCTIONS))
    return notify_fail("No such function "+funcName+" exists in "+fileName+".\n");
  fileName = file_name(fileObj);
  deep_inherit(file_name(fileObj), funcName);
  return 1;
}

//added by Pyro
void deep_inherit(string fileName, string funcName) {
  deepFileList = ({});
  deep_inherit_recursive(fileName, 0, funcName);
}

//added by Pyro
void deep_inherit_recursive(string fileName, int depth, string funcName) {
  string pointer, leftBuff = "";
  object fileObj;
  if(!deepFileList) deepFileList = ({});
  if(member_array(fileName, deepFileList) != -1) return;
  deepFileList += ({ fileName });
  if(!fileName) return;
  if(!(fileObj=get_object(fileName))) return;
  if(!(pointer = function_exists(funcName, fileObj, USE_NONCALLABLE_FUNCTIONS))) return;
  for(int i=0;i<depth;i++) { leftBuff += ":"; }
  message("info", leftBuff+funcName+" in "+fileName, this_player());
  foreach(string inheritedFile in inherit_list(fileObj)) {
    deep_inherit_recursive(inheritedFile, depth+1, funcName);
  }
}
void help() {
  message("help",
   "Syntax: Syntax: dip [function name] [file/object]\n"
   +"returns a deep inherit list of files in [file/object] that have the function [function name]\n"
   +"You can also use \"all\" instead of [function name]",
   this_player() );
}
