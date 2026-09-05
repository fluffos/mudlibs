#include <ansi.h>
inherit ITEM;

void create()
{
      set_name("线索", ({"clue", "xian suo"}));
      set_weight(100);
      set("long", "一张慕容复给出的叛徒所在的线索。\n");
      set("unit", "张");
      set("value", 2);
}



void init()
{
    add_action("do_chai","chai");
}

string gene_area(string area)
{
    string file;
    string *color=({HIR,RED,HIB,BLU,HIY,YEL,HIM,MAG,HIC,CYN,HIW,WHT,HBRED,HBWHT,HBBLU,HBYEL,HBGRN,HBCYN,HBMAG});
    string back_color,front_color;
    back_color=color[random(sizeof(color))];
    front_color=color[random(sizeof(color))];
    while (back_color==front_color)
    {
        front_color=color[random(sizeof(color))];
    }
    file = read_file("doc/help/map_general_for_jobs");
    file = back_color+file+NOR;
    file = replace_string(file, area, front_color+area+NOR+back_color);
    file = file+"\n"+NOR;
    return file;
}

int do_chai()
{
    object me=this_player();
    string area,map;
    area=TASK_D->place_belong(environment(me));
    map=gene_area(area);
    tell_object(me,map);
    write(" ___________________________________________________________\n");
    return 1;
}
                                                                                   



