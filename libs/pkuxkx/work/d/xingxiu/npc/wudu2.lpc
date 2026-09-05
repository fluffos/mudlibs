// 星宿五毒2配置文件
// created by zine 21 Oct 2010

inherit NPC;
#include <ansi.h>

void init()
{
    add_action("do_follow", ({ "follow" }));
    remove_call_out("keepmoving");
    call_out("keepmoving",1);
    call_out("dest",60);
}

int dest()
{
    if (environment())
    tell_room(environment(),query("name")+"又钻进了地下的石缝里。\n");
    destruct(this_object());
    return 1;
}

int keepmoving()
{
    this_object()->random_move();
    call_out("keepmoving",6);
    return 1;
}

void die()
{
    tell_room(environment(),query("name")+"身体缩成了一团，竟自行成了灰烬。\n");
	if(this_object())
	destruct(this_object());
}

int do_follow(string arg)
{
    object me=this_player();
    object ob=this_object();
    if (!arg)
    {
        tell_object(me,"你要跟随什么东西？\n"NOR);
        return 1;
    }
    if (arg==ob->query("id"))
    {
        tell_object(me,ob->query("name")+HIM"那么小的动物你要怎么跟随？\n"NOR);
        return 1;
    }
}