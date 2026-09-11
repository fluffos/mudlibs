// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/* Created by Ranma@Koko Wa 951001 */

/* This command will show you your current exec path */

#include <mudlib.h>

inherit CMD;

private void main() 
{
    string * paths = this_body()->query_shell_ob()->query_path();

    out(iwrap(//"Your current path is: "
              "你当前的目录是：" + implode(paths, (: $1 + ", " + $2 :)) + "\n"));
}
