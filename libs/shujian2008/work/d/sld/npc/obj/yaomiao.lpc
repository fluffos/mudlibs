// yaomiao.c

#include <ansi.h>

inherit ITEM;

int gf=0;

void create()
{
        set_name(HIG "药苗" NOR, ({"yao miao","miao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
                "这是一株需要常常浇水(jiao)的药苗，");
                set("unit", "株");
                set("no_get",1);
                set("5type","土");
                set("8type","乾");
                set("stime",0);
                set("location",1);
        }
}

void init()
{
        add_action("do_jiao","jiao");
                        
}

int do_jiao(string arg)
{
        object ob;
        object me=this_player();
        
        if(gf==0)
        {
                gf=1;
                call_out("grow", 10); 
        }
        if(!arg || !objectp(ob=present(arg, environment(me))))
                return notify_fail("你要浇什么？\n");
        if((uptime()-ob->query("jtime"))>30)
        {
                call_out("destructing", 1, ob); 
                return notify_fail("你已经一天多没浇水，药苗枯死了。\n");
        }
        else if((uptime()-ob->query("jtime"))<10)
        {
                return notify_fail("你刚浇过水了，等会儿再浇吧。\n");
        }
        ob->set("jtime",uptime());
        message_vision("$N浇了一瓢水，药苗又长高了些。\n",me);
        return 1;
}

void destructing(object ob)
{
        if(ob)
                destruct(ob);
}

void grow()
{
        int times;
        object obj;
        object ob=this_object();

        times=uptime()-query("stime");
        if(times>=120)
        {
                if(!objectp(obj=new(__DIR__"yaocao")))
                {
                        call_out("grow", 10);
                } 
                else
                {
                        obj->set("5type",query("5type"));
                        obj->set("8type",query("8type"));
                        obj->set("long",obj->query("long")+query("8type")+query("5type")+"性。\n");
                        obj->move(environment(this_object()));
                        call_out("destructing", 1, ob); 
                }
        }
        else if(times>=60)
        {
                set("name","金黄的药苗");
                call_out("grow", 60);   
        }
        else
        {
                set("name","嫩青的药苗");
                call_out("grow", 30);   
        }
}

