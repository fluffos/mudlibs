//如意 Zine 17 Oct 2010

#include <ansi.h>

inherit ITEM;
object holder,spouse;

void create()
{
        set_name(HIY "玉如意" NOR, ({"ru yi","jade" }));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("no_sell",1);
                set("no_give",1);
                set("value", 99000);
                set("long", "这是一件玉如意，上面刻着“执子之手”。\n");
                set("material", "jade");
                
        }
        setup();
}

int query_autoload() { return 1; }

void init()
{
    int i,count=0;
    object* all=all_inventory(environment());
    add_action("do_show",({"show"}));
    add_action("do_xiangnian",({"xiangnian"}));
    holder=environment();
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("id")=="ru yi")
        {
            count=count+1;
            if (count==2)
            {
                if (all[i]!=this_object())
                {
                    destruct(all[i]);
                    count=count-1;
                }
            }
        }
    }
    if (holder && userp(holder))
    {
        if (holder->query("marry/lover"))
        {
            set("long","这是一件玉如意，上面刻着“执子之手”"+holder->query("marry/lover")+"。\n");
            spouse=find_player(holder->query("marry/lover"));
            if (spouse)
            {
                tell_object(spouse,"你的"+holder->query("name")+"回到了北侠的世界。\n");
                set("long","这是一件玉如意，上面刻着“执子之手”"+spouse->query("name")+"。\n");
            }
        }
    }
    return;
}

int miss()
{
    this_object()->delete("miss");
}

int do_xiangnian()
{
    object where;
    holder=environment();
    if (this_object()->query("miss"))
    {
        tell_object(holder,HIM"多思则神殆，片刻的分离会让团聚时更加甜蜜。\n"NOR);
        return 1;
    }
    if (holder && userp(holder) && holder->query("marry/lover"))
    {
        this_object()->set("miss",1);
        remove_call_out("miss");
        call_out("miss",600);
        spouse=find_player(holder->query("marry/lover"));
        if (spouse)
        {
            tell_object(holder,"片刻分离，让你更加想念你的"+spouse->query("name")+"。\n");
            if (random(10)>5)
            {
                where=environment(spouse);
                tell_object(holder,"你的"+spouse->query("name")+"现在似乎在"+HIR+where->query("short")+NOR+"附近。\n");
            }
            return 1;
        }
        else
        {
            tell_object(holder,"片刻分离，让你更加想念你的配偶。\n");
            tell_object(holder,"此刻完全无法感应出你的配偶在哪里。\n");
            return 1;
        }
    }
}

int removeshow()
{
    this_object()->delete("show");
    return 1;
}



int do_show()
{
    object me=this_player();
    string* color=({HIG,HIM,HIR,HIY,HIC});
    if (this_object()->query("show"))
    {
        tell_object(me,"又想起了你那最幸福的一天，你也很累了，等会再展示吧。\n");
        return 1;
    }
    else
    {
        message_vision(color[random(sizeof(color))]+"$N回想起了最幸福的那一天她装扮得如斯华丽，缨络垂旒，玉带蟒袍，下面百\n花裥裙，大红绣鞋，一抹浓艳满身喜庆一如心中漫溢的幸福。\n"+NOR,me);
        this_object()->set("show",1);
        call_out("removeshow",15);
        return 1;
    }
}

