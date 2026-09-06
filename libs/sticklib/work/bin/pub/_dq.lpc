
/********************************************************************** 
  Quicktyper command: 'dq'.

  PURPOSE: Drop quicktyper command queue.

  AUTHOR: Tron
 **********************************************************************/

varargs nomask status
dq_cmd(string s, object me) {
    string *list;

    if(!me) {
	me = this_player();
	if(!me) return 0;
    }

    list = (string *)me->query_queue();
    if(!list || !sizeof(list)) {
	write("No command queue.\n");
	return 1;
    }
    me->set_queue(({}));

    write("Dropped---------------------\n");
    write(implode(list, "\n"));
    write("\nEnd-------------------------\n");
    return 1;
}
