/*
 * command                            /command/mortal/bug.c
 * description                        bug report system
 * coder                              dazzt, namhas
 * */


int main (string args)
{
	string coder, file, target, msg, str, *rep, tmp;
	object *ob;
	int i, szi;
	
	if (!args)
	{
		notify_fail("usage: bug [object | coder] <bug report>\n");
		return 0;
	}
	
	if (sscanf(args, "%s %s", target, msg) == 2)
	{
		if (present(target))
		{
			file = file_name(present(target));
			coder = (string) author_file(file);
            file = file_name(ENV(THIS));
		}
		else
		{
			if (file_size("/home/" + target) == -2)
			{
				file = file_name(ENV(THIS));
				coder = target;
			}
		}
	}
	
	if (!file)
	{
		file = file_name(ENV(THIS));
		msg = args;
		coder = (string) author_file(file);
	}
	
	if (!coder || coder == "NONAME")
		coder = "namhas";

	coder = lower_case(coder);

	msg = "  " + wrap(capitalize(msg), 76, 2);
	
	str = "^cc[^cW" + ctime(time())[4..15] + "^c0^cc]^c0: ^c1" + THIS->query_name() + 
		"^c0^cc@^c0^c1" + file[1..<1] + "^c0 ^cc(^c0^c1" + coder + "^c0^cc)^c0\n" +
		msg + "\n\n";
		
	write_file("/log/bugs", str, 0);
	tmp = read_file("/log/" + coder + ".rep");
	if (tmp)
		rep = explode(tmp, "\n");
	else
		rep = ({ "" });

	rm ("/log/"+coder+".rep");

	if (sizeof(rep) > 20)
		write_file ("/log/"+coder+".rep", implode(rep[<19..], "\n"));
	else
		write_file ("/log/"+coder+".rep", implode(rep, "\n"));
	
	write_file("/log/" + coder + ".rep", 
			   "BUG REPORT " + ctime(time())[4..15] + " "+THIS->query_name()+"@"+file[1..]+":\n"+msg+"\n\n\n");
	
	ob = users();
	
	for (i = 0, szi = sizeof(ob); i < szi; i++)
		if (ob[i]->query_security())
			message("0","^cWBUG REPORT^c0 " + str, ob[i]);
	
	message("standard", "Your bug report has now been sent to "+capitalize(coder)+".\n", THIS);
	return 1;
}

query_author ()
{
  return "dazzt";
}

query_synopsis ()
{
  return "bug [coder] <bug report>";
}

query_help ()
{
  return "Use this command to report bugs to the powers that here "
       + "in the Majik realm. The bug report parameter should "
       + "contain a brief description of what the bug is and how you "
       + "got it to happen. If you use coder parameter then the bug "
       + "is directed to the coder specified.";
}

query_see_also ()
{
  return "wizlist(1), idea(1), typo(1)";
}
