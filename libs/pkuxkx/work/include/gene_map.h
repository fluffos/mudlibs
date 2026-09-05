#include "ansi.h"

string * gene_area(string area)
{
    string file;
    string *color=({HIR,HIB,HIY,MAG,HIC,HIG,HIW,HBRED,HBWHT,HBBLU,HBYEL,HBCYN,HBMAG});
    string back_color,front_color;
    back_color=color[random(sizeof(color))];
    color-=({back_color});
    front_color=color[random(sizeof(color))];
    file = read_file("doc/help/map_general_for_jobs");
    file = back_color+file+NOR;
    file = replace_string(file, area, NOR+front_color+area+NOR+back_color);
    file = file+"\n"+NOR;
    return ({file,front_color,back_color});
}

string gene_area_songjob(string area1,string area2)
{
	string file;
    file = read_file("doc/help/map_general_for_jobs");
    file = replace_string(file, area1, HIR+"甲地"+NOR);
	file = replace_string(file, area2, HIY+"乙地"+NOR);
    file = file+"\n"+NOR;
    return file;
}



