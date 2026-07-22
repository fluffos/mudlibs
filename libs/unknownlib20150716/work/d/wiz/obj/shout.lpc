#include <ansi.h>
inherit ITEM;

void create()
{
set_name(HIR"夔牛"NOR WHT"之骨"NOR,({"kuiniu gu","gu"}));
set_weight(5000);
if( clonep() )
        set_default_object(__FILE__);
else    {
        set("long", "乃是上古魔兽夔牛所遗的一块风骨，奇形怪状，其中中空，可以传声千里。\n");
        set("unit", "根");
        set("no_get",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_sell",1);
        }
}       

int query_autoload(){return 1;}

void init()
{
add_action("do_shout","shout");
}

int err_msg(string arg)
{
write(arg);
return 1;
}
        
int do_shout(string arg)
{
object me = this_player();
if ( me!=environment() )
        return 0;
if ( !arg )
        return err_msg("你要传什么音？\n");
if ( me->query("channel/shout")<=0 )
        {
        if ( !me->query("channel/shout_give") )
                {
                me->add("channel/shout",50);
                me->set("channel/shout_give",1);
                me->save();
                }
        }
if ( me->query("channel/shout")<=0 )
        return err_msg("你的bug汇报奖励点不足。\n");
message("shout",HIW+me->name(1)+HIW"("+capitalize(me->query("id"))+")纵声长啸："+arg+"\n"NOR,users());
me->add("channel/shout",-1);
me->save();
tell_object(me,sprintf("你使用了%s,你的bug汇报奖励点自动减少1点<剩余%d点>。\n",name(),me->query("channel/shout")));
return 1;
}
