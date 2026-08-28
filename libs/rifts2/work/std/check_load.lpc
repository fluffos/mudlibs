#include <dirs.h>
//check_load(mixed room) inheritable function/object
int check_load(mixed dest);//prototype? 8) heh

//inherit this to any bad boy you are going access save rooms with.

int check_load(mixed dest)
{
object ob;
string str;
if(stringp(dest)) 
    {
        ob = find_object(dest);
        if(!ob)
        {
            str = catch(call_other(dest, "???"));
            if(str)
            {
                write(str+"\n");
                return 0;
            }
            ob = find_object(dest);
            if(ob->query_room())
                if(file_exists(DIR_ROOM+base_name(ob)+".o"))
                    ob->restore();
        return 1;
        }
return 1;
    }
return 1;
}
