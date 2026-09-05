#include <security.h>


int cmd_dump(string arg)
{
    string pth;      int line;

/*  commented out so other objects can query it

    if((int)this_player()->query_level() < APPRENTICE)
      return 0;
*/

    if(!arg)
      return (write("Syntax: 'dump [file]'\n"), 1);

    pth=resolv_path((string)this_player()->get_path(), arg);

    if(file_size(pth) < 1)
      return (write("That file does not exist.\n"), 1);

    write(read_bytes(pth, 0, file_size(pth)));

    return 1;
}
