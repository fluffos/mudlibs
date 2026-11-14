/*
 *	Mainly written by Billy at Shattered World 1991.
 *
 *  19980915 Dredd Some sanity updates from really ancient code...
 */

display_cautions()
{
    string out;

    if (caution == 0 || sizeof(caution) == 0)
    {
        write("(none)\n");
        return;
    }

    out = "<" + implode(caution, ", ") + ">\n";
    write(out);
}


push_caution(str)
{
    if (caution != 0)
        caution = ({ str }) + caution;
    else
        caution = ({ str });
    USER_SERV->update_who(this_object());
}


pop_caution()
{
    caution = caution[1..];

    if (catch_buf) 
    tell_object(myself, 
	"You have some messages waiting in your 'what-happened' buffer.\n");
    USER_SERV->update_who(this_object());
}


query_caution()
{
    if (caution == 0) return 0;
    if (sizeof(caution) < 1) return 0;
    return caution[0];
}

set_term_type(str) 
{
    this_object()->add_store("term", str);
}
 
query_term_type(str)
{
string termtype;
    termtype = this_object()->query_store("term");
    if (termtype == 0)
        return "vt100";
    else
        return termtype;
}

