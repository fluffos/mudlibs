// Zine dec 7 2010 ,铜雀台
#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_yanjiu", "yue");
	add_action("do_yanjiu", "du");
	add_action("do_yanjiu", "fan");
	add_action("do_yanjiu", "yanjiu");
}

void create()
{
	set_name(CYN"武功秘籍"NOR, ({ "wugong miji","miji","book"}));
	set_weight(500);
    set("value",1);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一本不知何人撰写的武功秘籍，你可以研究(yanjiu)一下。\n");
			set("unit", "本");
		}
}

int do_yanjiu(string arg)
{
    
    object me=this_player();
    mapping sk = me->query_skills();
    string *sname= keys(sk);
    int i,flag=0;
    if (this_object()->query("owner")!=me->query("id"))
    {
        tell_object(me,"你翻了翻这本武功秘籍，却觉得过于晦涩难懂。\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你要研究什么武功？\n");
        return 1;
    }
    for (i=0;i<sizeof(sname);i++)
    {
        if (arg==sname[i])
        {
            flag=1;
        }
    }
    if (!flag)
    {
        tell_object(me,"你只能研究你会的武功。\n");
        return 1;
    }
    if (arg=="tianmo-jieti")
    {
        tell_object(me,"天魔解体无法通过武功秘籍习得。\n");
        return 1;
    }
    if (me->query_skill(arg,1)<1)
    {
        tell_object(me,"你这种武功基础过于薄弱，无法研究。\n");
        return 1;
    }
    message_vision(YEL"$N开始认真研读$n"+YEL+"，以往关节之处统统迎刃而解！\n"NOR, me,this_object());
    me->set_skill(arg, me->query_skill(arg, 1)+1);
    if (!SKILL_D(arg)->valid_enable("force")&&arg!="qiankun-danuoyi")
    {
        me->set_skill(arg,me->query_skill(arg,1)+1);
        write(HIC"你的「"+CHINESE_D->chinese(arg)+"」进步了！\n"NOR);
    }
    write(HIC"你的「"+CHINESE_D->chinese(arg)+"」进步了！\n"NOR);
    message_vision("$N很诡异地无风自燃起来了。\n",this_object());
    destruct(this_object());
    return 1;		
}