// File: getopt.c
// Creator: Grendel@tmi-2 07-10-93
// This simul efun processes command lines for arguments.

// need this until we get a driver with strsrch in it.

// this function parses an argument string into a bit-string and
// the rest of the options unrelated to the arguments.
// e.g.:
//   getopt("-a -bd foo bar -e","abcdef")
//     returns an array of strings, the first element is a bit-string
//     with bits 0,1, and 3 set, the second element is the string:
//     "foo bar -e".
// Notes:  when getopt encounters an argument that is not an option, or
//   the special option "--" it stops parsing the arguments.

string *getopt(string options, string arg)
{
    string flags;
    string *args;

    int i,j,k,l;
    string str, *strs;

    if(!options || options=="" || !arg || arg=="")
	return ({ });
    
    // split the options into an array, zero the various variables
    args=explode(arg," ");
    flags="";
    strs=({ });

    // go through the array one entry at a time
    for(i=0,j=sizeof(args);i<j;i++)
	// make sure the entry isn't null
	if(args[i] && (strlen(args[i])>0))
	    // if it isn't an option, we stop processing
	    if(args[i][0]=='-') {
		// if it is "--" we also stop processing
		if(args[i]=="--") {
                    i++;
		    break;
                }
		// check if any of the options appear, and if so,
		// which ones
		for(k=0,l=strlen(options);k<l;k++)
		    if(strsrch(args[i],options[k])!=-1)
			flags=set_bit(flags,k);
	    }
	    else
		break;
    
    // build up the second string to be returned
    for(;i<j;i++)
	strs += ({ args[i] });
    if(sizeof(strs))
	str=implode(strs," ");
    else
	str="";
    
    // return it
    return ({ flags, str });
}
