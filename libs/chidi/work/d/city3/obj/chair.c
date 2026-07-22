#include <ansi.h>

inherit ITEM;

void create()
{
        string *pname = ({"锦面", "丝绣", "缎面","鹅绒" });
        string *mname = ({"", "大", "靠背", "安乐", "扶手", "折叠" });
        string *lname = ({"长椅","长凳" });
        string name;
        string zname = lname[random(2)];
        name = sprintf("%s%s%s",pname[random(4)],mname[random(6)],zname);
        set_name( name, ({ "chair" }));
        set("class", zname);
        set_weight(30000);
        set("long", "这是一张椅子，你可以坐(sit)下来点菜。\n" );
        set("no_sell", "这样东西不能随便买卖");
        set("no_get","凳椅是酒楼的财产,任何人都不能拿走!");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("material", "wood");
                set("value", 2000);
        }        
        setup();
}
void init()
{
        add_action("do_sit", "sit");
        add_action("do_stand", "stand");
}

int do_sit(string arg)
{
        object ob, who;
        if( !arg || arg == "" ) 
                return notify_fail("你要坐什么？\n");
        ob = this_object();
        who = this_player();
        if( arg != "chair" && arg != "椅子" && arg != ob->name() )
                return notify_fail("这里没有" + arg + "\n");
        if( who->query_temp("rode") )
                return notify_fail("你现在不在地上，怎么坐？\n");
        if( (int)ob->query("rode") >= 3 ) 
                return notify_fail( ob->name() + "已经坐满了！\n");

        who->set_temp("rode/type", "sit");
        who->set_temp("rode/desc", "坐在" + ob->name() + "上");
        ob->add("rode",1);
        ob->set("no_get", "有人坐在上面哪！\n");
        message_vision("$N一屁股坐在了" + ob->name() + "上。\n", who);
        return 1;
}

int do_stand()
{
     object ob,who;
     int max_qi;
     
     ob = this_object();
     who = this_player();
     if( who->query_temp("rode/type") != "sit")   
             return notify_fail("你本来就没有坐着！\n");
      who->delete_temp("rode");
        ob->add("rode", -1);
        if( !ob->query("rode") )
        ob->set("no_get","凳椅是酒楼的财产,任何人都不能拿走!");
        max_qi = (int)who->query("max_qi");
        if( (int)who->query("qi") > ( max_qi - max_qi/2) )
                message_vision("$N“嗖”的一声，从" + ob->name() + "上站了起来。\n", who);
        else message_vision("$N懒洋洋地伸了伸手，从" + ob->name() + "上缓缓地站了起来。\n", who);
        return 1;
}

