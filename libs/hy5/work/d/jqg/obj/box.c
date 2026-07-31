// box.c 铁盒
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(RED "大铁盒" NOR, ({ "da tiehe", "tiehe", "box" }) );
        set_weight(30000000);
        if( clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个锈迹斑斑的大铁盒子，看来很久没有人动过了。\n");
                set("value", 1000);
                set("material", "steel");
                set("no_get",1);
                set("no_drop",1);
                set("amount",30);
        }
        setup();
}

void init()
{
      add_action("do_xian","xian");
}

int do_xian(string arg)
{
      object me,suo,ob;
      me=this_player();
      ob=this_object();
      if (me->is_busy() || me->is_fighting())
           return notify_fail("你正忙着哪！\n");
      if (!me->query_temp("marks/铁盒")) return 0;
      if ( arg =="box" || arg=="da tiehe" || arg =="tiehe") {   
//        if(!objectp( present("silver key", me)))        
//           return notify_fail("你没有钥匙，用什么开啊？\n");
        suo=new(__DIR__"yinsuo");
        if(!clonep(suo))
         return notify_fail("你掀开铁盒，发现来晚了，里面空无一物。\n");         
if (this_object()->query("aget"))
{
           destruct(suo);
           return notify_fail("你掀开铁盒，发现来晚了，里面空无一物。\n");
           } 
        if(clonep(suo) && ob->violate_unique()){
           destruct(suo);
           return notify_fail("你掀开铁盒，发现来晚了，里面空无一物。\n");
           } 
        message_vision(HIY"$N掀开铁盒，发现里面放着一团冰绡般的物事。\n"NOR,me);
        me->delete_temp("marks/铁盒");
        suo->move(me); 
this_object()->set("aget",1);
//        destruct(ob);               
        return 1;
        }
       return notify_fail("你要掀开什么？\n");
}
