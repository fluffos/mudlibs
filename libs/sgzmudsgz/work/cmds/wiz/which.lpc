// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CMD;

private void main(string * argv)
{
  mixed result;


  result = CMD_D->find_cmd_in_path(argv[0], 
           this_body()->query_shell_ob()->query_path());

  if(result == -1)
    {
      out("你的命令路径中有这么一个文件，但它没有 main() 函数。\n");
      return;
    }

  if(!result)
    {
      out("你的命令路径中没有这个文件。\n");
      return;
    }
  outf("%s 位于：%s\n", argv[0], result[1]);
  return;
}

