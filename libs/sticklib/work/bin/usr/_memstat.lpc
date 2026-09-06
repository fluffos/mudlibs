/*
	Wiz command:	apath
	Syntax:		apath <path>
	Conditions:
		Gotta be a wiz
	Effects:
		Adds <path> to your path
*/
int help();

int memstat_cmd(string str)
{
    object obj;
    string first,last,name,tmp;
    int special,x;

    if (!interactive(this_player()) || !this_player()->query_coder_level())
	return 0;

    if(!str) {
	notify_fail("Usage: memstat object\n");
	return 0;
    }

    if(str[0..1]=="-h") return help();

    special=0;
    first  =str[0..0];
    last   =str[1..-1];

    switch(first) {
    case "#":
	obj=find_player(last);
	special=1; break;
    case "%":
	obj=present(last,this_player());
	special=1; break;
    case "|":
	obj=present(last,environment(this_player()));
	special=1; break;
    case "&":
	obj=find_living(last);
	special=1; break;
    case "*":
	obj=this_player();
	special=1; break;
    case "@":
	obj=environment(find_player(last));
	special=1; break;
    case "$":
	obj=environment(find_living(last));
	special=1; break;
    case "!":
	obj=environment(find_object(last));
	special=1; break;
    default:
	obj=present(str,this_player());
	if(!obj) obj=present(str,environment(this_player()));
	if(!obj) obj=find_player(str);
	if(!obj) obj=find_living(str);
	if(!obj) {
	    if(str=="me") obj=this_player();
	    if(str=="here") obj=environment(this_player());
	}
	str=(string)this_player()->absolute_path(str);
	if(!obj) obj=find_object(str);
	special=0; break;
    }


    if(!obj) {
	if(special) {
	    name="Unable to locate";
	    switch(first) {
	    case "#":
		name=sprintf("%s player: %s.\n",name,last);
		break;
	    case "%":
		name=sprintf("%s %s in you.\n",name,last);
		break;
	    case "|":
		name=sprintf("%s %s in your environment.\n",name,last);
		break;
	    case "&":
		name=sprintf("%s living object %s.\n",name,last);
		break;
	    case "*":
		name=sprintf("Error: you do not exist, go away.\n");
		break;
	    default:
		name=sprintf("Warning: %s has no environment.\n",last);
		break;
	    }
	} else {
	    name=sprintf("Unable to locate: %s.\n",str);
	}

	notify_fail(name);
	return 0;
    }

    name=(string)obj->query_name();
    if(!name) name="<No name>";

    tmp="\nMemory info for: %s (%s).\n";

    printf(tmp,name,object_name(obj));

    //debug_info(1,obj);

    return 1;
}

int help() {
    printf("memstat [-h] <object/object-path>\n");
    printf("-h - displays this help screen\n");
    printf("\tSpecial object path spefications are:\n");
    printf("\t#<player name>\n");
    printf("\t%%<object in your inventory>\n");
    printf("\t|<object present in your environment>\n");
    printf("\t&<living object>\n");
    printf("\t*<yourself>\n");
    printf("\t@<player name>  (returns environment stats)\n");
    printf("\t$<living object>(returns environment stats)\n");
    printf("\t!<file path>    (returns environment stats)\n");
    return 1;
}
