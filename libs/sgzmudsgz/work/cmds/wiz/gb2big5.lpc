#include <mudlib.h>
#include <daemons.h>
#include <edit.h>

inherit CMD;
inherit M_GRAMMAR;

private void get_input(string *gotten);

private void main()
{
    write("input the contents need to be converted: \n");
    new(EDIT_OB, EDIT_TEXT, ({ }), (: get_input :) );
}
private void get_input(string *gotten)
{
    string cc;

    if ( !sizeof(gotten) ) {
	write("no input gotten, abort!\n");
	return;
    }
    cc = implode(gotten, "\n");
    cc = CONVERT_D->GB2BIG(cc);
    write("\n\n"+cc+"\n\n");
}
