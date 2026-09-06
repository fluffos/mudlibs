#include <secure/udp.h>

#ifdef CDLIB 
#include <const.h>
#define MANHEAD "/doc/man/"
#endif

void udp_man(mapping data) {
    INETD->send_packet(data[NAME], ([
	REQUEST: REPLY,
	RECIPIENT: data[SENDER],
	ID: data[ID],
#ifdef CDLIB
	DATA: this_object()->man(data[DATA])
#else
	DATA: "/bin/cmds/_man"->get_man_string(data[DATA])
#endif
    ]) );
}

#ifdef CDLIB 
man(string page)
{
	string *chaparr;
	string path;
	int i, g_mannum;
	string man_chapt, str;
	mixed *man_arr;

	seteuid(getuid());
	    if (file_size(MANHEAD + page) < 0)
	    {
	        chaparr = (string *)MANCTRL->get_chapters();
		    for (i = 0 ; i < sizeof(chaparr) ; i++)
		    {
			man_chapt = chaparr[i];
			man_arr = (mixed *)MANCTRL->get_keywords(man_chapt,
								 page)[1];
			if (sizeof(man_arr) > 0)
			    break;
		    }
		    if (!sizeof(man_arr) && member( chaparr, page) >= 0)
		    {
			man_arr = MANCTRL->get_index(page)[1];
			g_mannum = 2;
			str = implode(man_arr, "\n");
			return "Available subjects:\n" +
				sprintf("%-*#s\n", 76, str);
		    }
		if (sizeof(man_arr) == 0)
		    return "No such man page: " + page + "\n";
		else
		{
		    path = MANHEAD + man_chapt + "/" + man_arr[0];

		    if (file_size(path) < 0)
			return "No such man page: " + page + "\n";
		    else
		    {
			return "File: " + path + "\n" + read_file(path);
		    }
		}
	    }
	    else
	    {
		return "File: " + MANHEAD + page + "\n" + read_file(MANHEAD + page);
	    }
    return 1;
}

#endif
