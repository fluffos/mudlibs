// _boardcheck.c
// Checks all message boards for new posts
// Origionally from Quasimodo@Astaria 9/94
// Brought to TMI-2 by Aurora@Astaria 1/30/95

#include <mudlib.h>


inherit DAEMON;

int cmd_boardcheck()
	{
   int i, j, k, newposts;
	object *boards;
	
	write("\n\tChecking Boards:\n");
	boards = this_object()->query("boards_to_check");
	
	if(!boards)
		{
		boards = ({
			"/d/Conf/boards/bar",
			"/d/Conf/boards/centre",
			"/d/Conf/boards/conf_A",
			"/d/Conf/boards/conf_B",
			"/d/Conf/boards/conf_C",
			"/d/Conf/boards/conf_D",
			"/d/TMI/boards/Imudboard",
			"/d/TMI/boards/amylaarboard",
			"/d/TMI/boards/cdboard",
			"/d/TMI/boards/coders_available",
			"/d/TMI/boards/coders_wanted",
			"/d/TMI/boards/gdboard",
			"/d/TMI/boards/libboard",
			"/d/TMI/boards/lpc4board",
			"/d/TMI/boards/mainboard",
			"/d/TMI/boards/mbugboard",
			"/d/TMI/boards/mudosboard",
			"/d/TMI/boards/mudosprojboard",
			"/d/TMI/boards/politicsboard",
			"/d/TMI/boards/projboard",
			"/d/TMI/boards/protoboard",
			"/d/TMI/boards/sites_available",
			"/d/TMI/boards/sites_wanted",
			"/d/TMI/boards/teachboard",
			"/d/TMI/boards/uriboard",
			});
		}

   k = sizeof(boards);

   for(i = 0; i<k; i++)
		{
		newposts = boards[i]->query_num_new();

		if(newposts)
			{
		j++;
		write("\t"+boards[i]->query_short()+"\n");
			}
		}
   write("\tChecked "+k+" boards.\n");
   write("\tFound "+j+" with new posts.\n\n");
	return 1;
	}
