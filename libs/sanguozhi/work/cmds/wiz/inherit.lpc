// Created by tset on 3 Oct 1998
// updated by tset on 1 Dec 1998

#include <mudlib.h>
inherit CMD;

private void main( string str )
{
    object*     targets;
    string*     files;
    string	outstr, tempstr;
    int         l;
    object shell_ob = this_body()->query_shell_ob();

    if ( !str )
    {
//      write("用法：inherit filename\n");
	str = shell_ob->get_variable("cwf");
//      return;
    }
    if ( !str || str == "here" ) str = file_name(environment(this_body()));
//    else
        targets = filter(objects(), (: inherits($(str), $1) :));


    if ( targets ) {
        files = map_array(targets, (: file_name :));
        l = sizeof(targets);
        outstr = "下列"+chinese_number(l)+"个物件继承文件 " + str +":\n";
        while (l--) {
           outstr += files[l]+": "
        +((tempstr=targets[l]->short()) ? "\""+tempstr+"\" " : "[no short]")
        +"\n";
        }
     out(outstr);
     }
}
