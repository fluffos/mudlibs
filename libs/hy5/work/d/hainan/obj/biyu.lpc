// music yangzhou's 雪莲
#include <ansi.h>

inherit ITEM;
int count=20;
void create()
{
        set_name(HIC"青龙碧血玉"NOR, ({ "yu","biyu","qinglong" }) );
        set("long", "一块碧玉,上面天然形成一条雪红的飞龙。
你可以用(use yu)来恢复你各项值,不过只能使用20次.
超过此限,后果自负.\n");
        set("unit", "块");
        set("weight", 100);
        set("money_id",1);
}

void init()
{
        add_action("do_use", "use");
}

int do_use(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("你要使用什麽？\n");
if( living(this_player()) ==0 ) return 0;
        ob=this_player();
        if (count==0) {
 message_vision("$N手中的$n突然暴起一声巨响,爆炸了.\n",ob,this_object());
 ob->die();
 destruct(this_object());
 return 1;
                 }
        ob->set("qi",(int)ob->query("max_qi"));
        ob->set("jing",(int)ob->query("max_jing"));
        ob->set("neili",(int)ob->query("max_neili"));

         ob->set("food",((int)ob->query("str")-10)*10+200);
        ob->set("water",((int)ob->query("str")-10)*10+200);
        ob->set_temp("windnod",1);
        write("[1;33m你手中的碧玉发出雪红的光茫！\n[0;37m");
        message("vision", HIY + ob->name() + 
"手中的碧玉发出雪红的光,一闪不见！\n"+NOR,
                environment(ob), ob);
     count--;
        return 1;
}
