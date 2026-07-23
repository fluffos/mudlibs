#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIB"坛子"NOR, ({ "tan zi","tanzi"}));
        set_weight(1000);
        set_max_encumbrance(60);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long","这是一个陶制的坛子。\n"+
                           "你可以往这个坛子里装(zhuang)一些小虫子。\n");
                set("value", 499);
        }
        setup();
}

void init()
{
        add_action("do_zhuang","zhuang");
        add_action("do_noput","put");
}

int do_zhuang(string arg){
        string item,target;
        object ob,obj;
        

        if(!arg || sscanf(arg,"%s in %s",item,target)!=2)return notify_fail("命令格式：zhuang <虫子> in <坛子>。\n");
        if(!objectp(ob=present(target,this_player()))) return notify_fail("你身上没有这个东西。\n"); 
        if(!objectp(obj=present(item,this_player()))) return notify_fail("你身上没有这个东西。\n");
        if(!obj->query("cook/allow")) return notify_fail("这个坛子，只能装一些毒虫。\n");
        if(ob->query("id")!="tan zi") return notify_fail("只能用坛子装毒虫。\n");
        if(ob->query_encumbrance()>=60) return notify_fail("这个坛子，已经装不下虫子了。\n");
        message_vision("$N将一只"+(string)obj->query("name")+"装入$n。\n",this_player(),ob);
        obj->move(ob);
        return 1;
        }

int do_noput(string arg) {
        string item, target;
        if(!arg) return notify_fail("你要将什么东西放进哪里？\n");
        if(sscanf(arg,"%s in %s",item,target)==2 && target == "tan zi"||target =="tanzi" ) {
          write("你只可以把虫子装(zhuang)到坛子里。\n");
          return 1; 
          }
}
