#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

    position = 1;
}



protected int cmd(mixed str, object me) {
    int i, j, num;
    string *files, *bit;
    string s1, s2, s3, s4;

    if(!str) {
      notify_fail("Usage: grep <pattern> <file(s)>\n");
      return 0;
    }

    num = 1;
    if (sscanf(str,"-n %s", str) == 1)
	num = 0;
    if (sscanf(str, "%s -n %s", s1, s2) == 2) {
	num = 0;
	str = s1+" "+s2;
    }
    if (sscanf(str, "%s %s", s1, s2) != 2) {
	notify_fail("Usage: grep pattern <files>\n");
	return 0;
    }

    files = this_player()->get_files(s2);
    if(!sizeof(files)) {
	notify_fail("File(s) " + s2 + " not found.\n");
	return 0;
    }
    for (i=0;i<sizeof(files);i++)
	if (file_size(files[i]) > 0)
	{
	    str = read_file(files[i],0,900);
	    if(!str) 
	    {
		notify_fail("File empty or too large for grep.\n");
		return 0;
	    }
	    if (sscanf(str, "%s"+s1+"%s", s3, s4) == 2) {
		j = 0;
		str = read_file(files[i], 0, 900);
		write("File : "+files[i]+"\n");
		while (str && num) {
		    while (sscanf(str, "%s"+s1+"%s", s3, s4) == 2) {
			bit = explode(s3,"\n");
			if(sizeof(bit))
			    printf("%4d: %s\n", j+sizeof(bit), bit[sizeof(bit)-1]+s1+
			      explode(s4,"\n")[0]);
			j += sizeof(bit);

			str = implode(explode(s4,"\n")[1..1000],"\n");
		    }
		    j = ((j/900)+1)*900;
		    str = read_file(files[i],j, 900);
		}
	    }
	}
    return 1;
} /* grep() */


