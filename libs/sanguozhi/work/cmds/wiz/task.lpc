/* task.c by fire on 28/12/99
   to display the tasks
*/
#include <mudlib.h>
#include <daemons.h>
inherit CMD;
nomask private void main(string str)
{
    string p_id=str;
    string extra = 0;
    if (!str)
    {
	write(TASK_D->show_me());
        return;
    }
    sscanf(p_id, "%s %s", p_id, extra);
    if ( extra )
    {
        write("错误用法．\n");
	return;
    }
}
