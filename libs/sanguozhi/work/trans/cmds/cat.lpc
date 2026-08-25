// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CMD;

// Rust

private void main(mixed *arg, mapping flags, string stdin) {
  string file;
  int i;
  string chunk;

  if(end_of_pipeline())
    {
      if(arg[0])
        foreach(file in arg[0])
          {
            i = 0;
            if(!is_file(file))
              printf("Warning: %s failed.\n", file);
            else
              chunk = read_file(file);
            write(chunk);
          }
        else
          {
            write(stdin);
          }
        return;
    }
  else
    {
      if(arg[0])
        foreach(file in arg[0])
          {
            i = 0;
            if(!is_file(file))
              printf("Warning: cat of %s failed.\n", file);
            else
              chunk = read_file(file);
            out(chunk);
          }
        else
          {
            out(stdin);
          }
    }
}


int help()
{
//    write(wrap(
//        "Usage:  cat <filename>\n"
//        "Displays the entire contents of the specified file to your screen "
//        "all at once.  See also more.\n" ));
      write(
          "用法：cat <文件名>\n"
          "显示指定文件的全部内容。\n"
          "参考：more \n");
}

