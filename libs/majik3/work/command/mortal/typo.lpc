/*
 * command                            /command/mortal/typo.c
 * description                        typo report system
 * coder                              dazzt, namhas
 * */


int main (string args)
{
	string coder, file, target, msg, str, *rep, tmp;
	object *ob;
	int i, szi;
	
	if (!args)
	{
		notify_fail("usage: typo [object | coder] <typo report>\n");
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
		
	write_file("/log/typos", str, 0);
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
			   "TYPO REPORT " + ctime(time())[4..15] + " "+THIS->query_name()+"@"+file[1..]+":\n"+msg+"\n\n\n");
	
	ob = users();
	
	for (i = 0, szi = sizeof(ob); i < szi; i++)
		if (ob[i]->query_security())
			message("0","^cWTYPO REPORT^c0 " + str, ob[i]);
	
	message("standard", "Your typo report has now been sent to "+capitalize(coder)+".\n", THIS);
	return 1;
}

query_author()
{
  return"dazzt, namhas";
}

query_help()
{
  return "If you find a typo in a description you can report it to the responsible"
  + " coder. There are various ways you can do it. First of all, you can just enter"
  + " <msg> and will be sent to the creator of room you are standing in. Second"
  + " change is that you name <coder> and then the <msg> will be sent to him/her."
  + " Third way is to name the object <obj> you saw a typo on and then the <msg>"
  + " will be sent to the coder responsible for this object.";
}

query_synopsis()
{
  return "typo [creator | obj] <msg>";
}

query_example()
{
  return"typo namhas cat is written with 'c', not 'k'";
}

query_see_also()
{
  return "bug(1)";
}
query_position()
{
  return POS_RESTING;
}

