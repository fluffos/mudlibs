#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name("通灵宝玉",({"jade"}));
        set_weight(40);
        if(clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit","块");
                set("value",1000);
}
        setup();
}
void init()
{
}
int wear(string arg)
{
 if (environment(this_object())->query("id")!="mudy"&&environment(this_object())->query("id")!="anya")
{
message_vision(HIW"$N指尖一碰到"+this_object()->query("name")+this_object()->query("name")+HIW"竟然化成了一堆粉末，消散在风中!\n"NOR,this_player());
call_out("des",1,this_object());
return 1;
}
message_vision(HIW"$N突然觉得自己青春焕发！\n"NOR,this_player());
this_player()->add("per",10);
this_player()->set("mud_age",500000);
return 1;
}
void des(object jane)
{
destruct(jane);
return;
}
