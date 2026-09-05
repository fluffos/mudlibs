//小剑 zine Oct 16 2010
inherit ITEM;
#include <ansi.h>
void create()
{
        string* color=({RED,BLU,WHT});
        
        set_name(color[random(sizeof(color))]+"小剑"NOR, ({"sword", "xiao jian", "jian","iron essence" }));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个神奇的玩意，你可以用(ch)命令让自己的声音更清楚。\n");
                set("unit", "个");
                set("value", 0);
                set("available", 10);
             }
        setup();
        call_out("dest",7200);

}

int dest()
{
    tell_object(this_player(),"小剑剑身出现皲裂，迅速扩大，片刻化成灰烬。\n");
    destruct(this_object());
    return 1;
}

void init()
{	
	add_action("do_ch",({"ch"}));
}

int do_ch(string arg)
{
    object me=this_player();
    string word;
    string* color=({HIR,RED,HIY,YEL,HIB,BLU,HIG,GRN,HIC,CYN,MAG,HIM,HIW,WHT});
	
	string color1=color[random(sizeof(color))];
    
    if (!arg)
    {
        word="...";
    }
    else
    {
        word=arg;
    }
	message("chat",color1+"【"+me->query("name")+color1+"】"+sprintf ("%s\n",word)+NOR,users());
    this_object()->add("available",-1);
    if (this_object()->query("available")<0)
    {
        tell_object(this_player(),"小剑剑身出现皲裂，迅速扩大，片刻化成灰烬。\n");
        destruct(this_object());
        
    }
    return 1;
}