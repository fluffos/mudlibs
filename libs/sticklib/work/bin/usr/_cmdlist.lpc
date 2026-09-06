#include <cmd.h>
#include <daemons.h>

nomask int
cmdlist_cmd(string str)
{
    //  string c;
    mapping list;

    if (!CHECK) return 0;
    /* This does not work anymore ++Tron
	if ((c = (string)TP->list_cmds()))
	    write(c);
	else
	    write(
     "You got no /bin commands at all (how did you call this one!??!)\n");
    */

    list = (mapping)CMD_D->query_full_hash();
    write("Public commands:\n\n");
    TP->tell_me(implode(m_indices(list["/bin/pub"]), " "));
    write("\nCoder commands:\n\n");
    TP->tell_me(implode(m_indices(list["/bin/usr"]), " "));

    return 1;
}
