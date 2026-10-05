//Created by kuku@sjsh 2003.10.3 挖宝任务探宝图

inherit ITEM;
#include <ansi.h>

int move_money(int amount);
int write_money_log(object room,int amount);
int get_number();
int get_write_number();
void write_log(object room_o,string number);
int del_log(string x);

void create()
{
        set_name(YEL"藏宝图"NOR, ({"cangbao tu","tu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这张图里蕴涵着一个宝库所在地的秘密，它只有在(jianbie) \n"+
                            "后，你才能知道这其中的奥妙所在。\n");
                set("unit", "张");
                set("value", 150);
        }
}

void init()
{
        add_action("do_jianbie","jianbie");
}
                
int do_jianbie(string arg)
{
        string mvdir,*dir,room_s;
        string r_long,new_long,str;
        int f,amount,i;
        object room_o,me,ob;
       string* exlst; 
       mapping exits; 

        string *path = ({
           "/d/changan/",            "/d/sea/",               "/d/death/",
           "/d/eastway/",            "/d/westway/",           "/d/city/",
           "/d/nanhai/",             "/d/kaifeng/",           "/d/lingtai/",  
           "/d/lanling/",            "/d/moon/",              "/d/ourhome/honglou/",
           "/d/death/",              "/d/qujing/baoxiang/",   "/d/qujing/biqiu/",
           "/d/qujing/chechi/",      "/d/qujing/fengxian/",   "/d/qujing/jindou/",
           "/d/qujing/jinping/",     "/d/qujing/jisaiguo/",   "/d/qujing/nuerguo/",
           "/d/qujing/pansi/",       "/d/qujing/tongtian/",   "/d/qujing/qilin/",
           "/d/qujing/qinfa/",       "/d/qujing/tianzhu/",    "/d/qujing/wuji/",
           "/d/qujing/yuhua/",       "/d/qujing/zhujie/",     "/d/qujing/zhuzi/",
           });
        str="你仔细的看了看这张图，通过仔细的观察，你终于发现原来你日思夜想一直在寻找的宝贝在\n";
        me=this_player();
        ob=this_object();
           
        if(!arg || arg!="cangbao tu")
                return notify_fail("你要鉴别什么？\n");
        if(me->query("level")<40)
                return notify_fail("你的等级不够，看不出图里有啥东西。\n");
        if(ob->query("jianbie_done")){
                if(ob->query("owner")){
                        if(ob->query("owner")!=me->query("id"))
                                return notify_fail("这张图已经被人用过了。\n");
                        else
                                return notify_fail("这张图已经鉴别过了。\n");
                }
        }
  
        mvdir=path[random(sizeof(path))];
        dir=get_dir(mvdir);

        room_s=dir[random(sizeof(dir))];
        room_s=mvdir+room_s;
        room_o=find_object(room_s);
        if(!room_o) room_o=load_object(room_s);
        if(!room_o) return 0;
        r_long=room_o->query("long");
              exits=room_o->query("exits"); 
               exlst=keys(exits); 
        
        new_long=str+r_long+"这里明显的出口是" ; 
        if(sizeof(exlst)){
                for(i=0;i<sizeof(exlst);i++)
                        new_long+=exlst[i]+"、"; 
        }
        ob->set("long",new_long);       
        amount>=1000 ?f=amount:f=10+random(91);
        ob->set("jianbie_done",1);
        ob->set("owner",me->query("id"));
        "/adm/daemons/ran_moneyd"->write_money_log(room_o,f);
        return 1;
}
