/*
 * command                            /command/mortal/idea.c
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
		notify_fail("usage: idea [object | coder] <your idea>\n");
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
		
	write_file("/log/ideas", str, 0);
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
			   "IDEA " + ctime(time())[4..15] + " "+THIS->query_name()+"@"+file[1..]+":\n"+msg+"\n\n\n");
	
	ob = users();
	
	for (i = 0, szi = sizeof(ob); i < szi; i++)
		if (ob[i]->query_security())
			message("0","^cWIDEA^c0 " + str, ob[i]);
	
	message("standard", "Your idea has now been sent to "+capitalize(coder)+".\n", THIS);
	return 1;
}

query_author ()
{
  return "dazzt";
}

query_synopsis ()
{
  return "idea [coder] <idea report>";
}

query_help ()
{
  return "This command sends 'idea report' to the coder of the current "
       + "environment, or the 'coder' specified. Remember to think "
       + "seriously about an idea and if you really think that it "
       + "would be an improvement to the game, then send it. Consider "
       + "also if it is codeable.";
}

query_see_also ()
{
  return "creator(1), bug(1), typo(1)";
}
