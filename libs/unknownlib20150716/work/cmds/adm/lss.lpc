#include <ansi.h>
inherit F_CLEAN_UP;


int main(object me, string arg)
{
int mark_loaded;
int i, j, w, col;
string dir;
string path;
int opt_l;
mixed *file;
string result = "";;

seteuid(geteuid(this_player(1))); 

dir = resolve_path(me->query("cwd"), arg);
if (me != this_player(1))
        return notify_fail("不是当前使用者进行操作。\n");
if (file_size(dir) == -2 && dir[strlen(dir) - 1] != '/') dir += "/";
file = get_dir(dir,-1);
if (! sizeof(file))
        {
        if (file_size(dir) == -2)
                return notify_fail(sprintf("目录(%s)是空的。\n", dir));
        else    return notify_fail(sprintf("没有(%s)这个目录。\n", dir));
        }
for(i=0;i<sizeof(file);i++)
        {
        if ( i!=0 && i%5==0 )
                result+= "\n";  
        result+= file[i][0]+" ";
        }
me->start_more(result);
return 1;
}
