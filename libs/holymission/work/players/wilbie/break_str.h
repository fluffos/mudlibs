
 /* ---------------------------------------------------------------
   Coded by: Tatsuo
   name: break_string(string what, int number)
   desc: Break a string after certain number of chars
   usage: This function breaks a string without newlines into a string
          with newlines inserted every "num" characters.
   ------------------------------------------------------------------ */
nosave varargs string 
break_string(string what, int num)
{
    string *ploder, dummy;
    int       i, sz, curr;

    if (!what || !strlen(what)) return "";

    dummy = "";

    ploder= explode(what," "); 
    what  = dummy;
    curr = 0;

    for (i=0, sz=sizeof(ploder); i < sz; i++)
    {
	if (curr + strlen(ploder[i]) > num) {
	    what += "\n" + dummy;
	    curr = 0;
	}
	if (ploder[i]!="") {
	    what  += ploder[i];
	    if (i < sz - 1)
		what += " ";
	}
	curr += strlen(ploder[i]) + 1;
    }
    return what;
}

