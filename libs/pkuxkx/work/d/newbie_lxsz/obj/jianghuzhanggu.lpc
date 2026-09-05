//Cracked by Roath
#include <ansi.h>
// #include <command.h>
inherit ITEM;
inherit F_MASTER;
#include "../newbie_village.h"

int do_du(string);

void create()
{
        set_name(YEL "江湖掌故" NOR, ({ "jianghu zhanggu", "book"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "册");
                set("long", "这本书用浅显易懂的文字记载了一些江湖中的英雄事迹，读罢让你豪气顿生，\n不知为何，也默默回荡了一股苍凉之感。\n");
                set("value", 10000);
                set("material", "paper");
                set("no_drop",1);
             }
        setup();
}

void init()
{
    add_action("do_du","read");
    add_action("do_du","du");
}

int do_du(string arg)
{
    object who,ob;
    string book,times;
    int i;
    
    who=this_player();
    ob=this_object();
    
    if (!arg||arg=="book")
    {
        tell_object(who,"请使用read book for 1格式读书。\n");
        return 1;
    }
    if (sscanf(arg,"%s for %d",book,times)==2)
    {
        if (strcmp(book,"book")!=0) return 0;
        if (who->query("newbie_village/jianghuzhanggu")==1)
        {
            tell_object(who,"你已经读过这本书了，不需要再读了。\n");
            return 1;
        }
        who->set("newbie_village/jianghuzhanggu",1);
        who->add("potential", 500);
        who->add("pot/lxsz", 500);
        message_vision("$N读罢此书，大感畅怀于心。江湖如此豪迈，我又如何能偏安？看来是到离开的时候了。\n$N随手将《江湖掌故》又放回到了书架里。\n",who);
		write("你的潜能提高了！\n");
        set_nextquest(who,"去藏书阁读江湖掌故","到大厅找游鲲翼ask you about 闯荡江湖", 20, 100);
        destruct(ob);
        return 1;
    }
    
    return 0;
}

