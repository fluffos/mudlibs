/*
 * command                       /obj/more.c
 * description                   more object
 * coder                         dazzt
 * */

string *file;
int more_active;
int current_line;

do_more()
{
    int i, j, szj;
    int cmore;
    string tmp, out;

    cmore = THIS->query_rows()-2;
    if ((current_line + cmore) > sizeof(file))
    {
		cmore = sizeof(file) - current_line;
		more_active = 0;
    }
	
	
    for (i = current_line; i < (current_line + cmore); i++)
    {
		if (strsrch(file[i], "_\b") != -1)
		{               /* bolds found */
	    tmp = "";
	    for (j = 0, szj = sizeof(file[i]); j < szj; j++)
	    {
			if ((file[i][j..j] == "_") && (file[i][j + 1..j + 1] == "\b"))
			{
		    tmp += "^cc" + file[i][j + 2..j + 2] + "^c0";
		    j += 2;
		}
			else
				tmp += file[i][j..j];
	    } 
	    message("0", tmp + "\n", THIS);
	}
        else if (strsrch(file[i], "\b") != -1)
        {
			out = "";
			for (int k=0;k<sizeof(file[i]);k++)
            {
				if (file[i][k] == '\b') {
				  out += "\b";
				  out += "^c1";
				  k++;
				  out += file[i][k..k];
				  out += "^c0";
              }
				else
					out += file[i][k..k];
            }
			message ("0", out + "^c0\n", THIS);
        }
		else
			message("0", file[i] + "\n", THIS);
    }
    current_line += cmore;
    if (more_active)
    {
		message("0", "^bb^cW-more-^c0", THIS);
		input_to("more_input");
    }
    else
      destruct (THOB);
}

more (string filename)
{
	string s;
	
    file = ({ });
	
	s = read_file(filename);
	if (sizeof(s) == 0)
	{
		write("Nothing to display!\n");
		return 1;
	}

    file = explode(read_file(filename), "\n");
    more_active = 1;
    current_line = 0;
    do_more();
}

more_string (string jotai)
{
  file = explode(jotai, "\n");
  more_active = 1;
  current_line = 0;
  do_more();
}

more_input (string input)
{
    if (input == "q" || input == "n")
    {
		current_line = 0;
		more_active = 0;
		file = ({ });
		destruct(THOB);
		return;
    }
    do_more();
}
