#include <kernel.h>

inherit "/basic/create";
inherit ACCESS;

mapping callbacks;

void create()
{
  if (!callbacks && !(callbacks = "/etc/shared"->query_global("tmp_edit")))
    "/etc/shared"->set_global("tmp_edit",callbacks = ([ ]));
}

void edit_temp(mixed data,closure callback)
{
  string name,file;
  if (!interactive(this_player()))
    return;
  if (!stringp(data))
    data = implode(data,"\n")+"\n";
  name = this_player()->query_real_name();
  file = "/save/edit/"+name;
  unguarded("@edit",#'rm,file);
  unguarded("@edit",#'write_file,({ file, data }) );
  ed(file,"exit_editor");
  callbacks[name] = callback;
}

void exit_editor()
{
  string data, name;
  if (caller_stack_depth() != 0) // faked call?
    return;
  name = this_player()->query_real_name();
  data = unguarded("@edit",#'read_file,"/save/edit/"+name);
  if (!data)
    data = "";
  unguarded("@edit",#'rm,"/save/edit/"+name);
  funcall(callbacks[name],name,data);
  m_delete(callbacks,name);
}
