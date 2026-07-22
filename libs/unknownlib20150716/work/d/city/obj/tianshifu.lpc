//Cracked by Roath
inherit ITEM; 
#include <ansi.h>

int do_burn(string arg);

void create()
{
set_name("天师仙符"NOR, ({"tianshi fu","fu"}));
set_weight(80);
if( clonep() )
        set_default_object(__FILE__);
else    {
        set("long", "   这是一件用于灭火，引水的仙符，它具有非凡的魔力。
你可以用"HIR"burn fu"NOR"来灭火，引水。\n");
        set("unit", "张");
        set("value", 5000);
        }
setup();        
}

void init()
{
add_action("do_burn","burn");
}

int query_autoload() { return 1; }

int err_msg(string str)
{
write(str);
return 1;
}       

int do_burn(string arg)
{
int exp, pot;
object ob = this_player();
object where = environment(ob);
exp =1300;
pot =350;
    
if ( !arg || !id(arg) )
        return err_msg("命令格式：burn fu\n");
if (this_player()->query("mana") < 50)
        return err_msg("你的法力不够了。\n");
if (!where->query("shortstr"))
        return err_msg("这儿用不着烧天师符。\n");
if (!where->query("tianzai"))
        return err_msg("这儿用不着烧天师符。\n");
if (where->query("tianzai")=="fire")
        {
        ob->add("daoxing",exp);
        ob->add("combat_exp",exp);
        ob->add("potential",pot);
        where->delete("tianzai");
        where->set("short",where->query("shortstr"));
        where->delete("shortstr");
        CHANNEL_D->do_channel(this_object(), "job",ob->query("name")+WHT"灭火"HIG+where->query("short")+NOR WHT"。"NOR); 
        CHANNEL_D->do_channel(this_object(), "job","救灾:"YEL+where->query("short")+NOR HIR"("+ob->name(1)+")"NOR WHT"───>"+HIG"奖励:"+exp+"道行"+exp+"经验"+ pot + "潜能。\n"NOR,users());
        log_file("bigtask","["+ctime(time())+"] "+sprintf("%s(%s)救灾"HIW+where->query("name")+NOR"获得%d的道行和%d点潜能.\n",
                                        ob->query("name"),ob->query("id"),exp,pot));
        return 1;
        }
if (where->query("tianzai")=="water")
        {
        ob->add("daoxing",exp);
        ob->add("combat_exp",exp);
        ob->add("potential",pot);
        where->delete("tianzai");
        where->set("short",where->query("shortstr"));
        where->delete("shortstr");
        CHANNEL_D->do_channel(this_object(), "job",""+ob->query("name")+WHT"去水"HIG+where->query("short")+NOR WHT"。"NOR); 
        CHANNEL_D->do_channel(this_object(), "job","救灾:"YEL+where->query("short")+NOR HIR"("+ob->name(1)+")"NOR WHT"───>"+HIG"奖励:"+exp+"道行"+exp+"经验"+ pot + "潜能。\n"NOR,users());
        log_file("bigtask","["+ctime(time())+"] "+sprintf("%s(%s)救灾"HIW+where->query("name")+NOR"获得%d的道行和%d点潜能.\n",
                        ob->query("name"),ob->query("id"),exp,pot));
        return 1;
        }
}
