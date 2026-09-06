// Elwood 02/98

#include <cmd.h>
#include <daemons.h>

nomask int which_cmd(string str) {
    mapping list;
    mapping *arr,*arr2;
    int i,j;

    if (!str) {
	notify_fail("Usage: which <command>\nSearches for a command in your path.\n");
	return 0;
    }
    list=(mapping)CMD_D->query_full_hash(); 
    arr=m_indices(list);
    for(i=0;i<sizeof(arr);i++) {
	arr2=m_indices(list[arr[i]]);
	if (member(arr2, str)!=-1) {
	    write(str+" is in ");
	    write(arr[i]);
	    write("\n");
	    return 1;
	}

    }
    notify_fail("Command not found.\n");
    return 0;
}
