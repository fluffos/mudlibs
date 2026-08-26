/* get_text.c: coded by Truilkan

   This object is intended to be inherited by objects which wish to
   query for multi-line input.  See get_text.README for an example
   of how to use it.
*/
private nosave string gtext;
private nosave string gfunc;

string query_text()
{
        return gtext;
}

void set_gfunc(string t)
{
        gfunc = t;
}

void more_text(string str)
{
    if (str == "**") {
                call_other(this_object(),gfunc,gtext);
        return;
    }
    gtext += str;
        gtext += "\n";
    write("]");
    input_to("more_text");
}

int get_text(string str)
{
        if (str) {
                call_other(this_object(),gfunc,str + "\n");
                return 1;
        }
        gtext = "";
        write("Finish message with '**'\n");
        write("]");
        input_to("more_text");
        return 1;
}
