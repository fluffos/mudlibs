#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", HIW"太阿"NOR);
        set("long", @LONG
这里是上古时代保存一个神秘洞穴，据说里面陈列着上古时代遗留下来的
一把名为太阿的宝剑，洞中有些黑呀呀的，不知暗伏着什么机关。    
LONG );
        set("indoors", "city");
        set("exits", ([
        "south":   __DIR__"dongkou",
        ]));
        set("no_fly",1);
        set("no_clean_up", 0);
        set("no_clean_up", 0);
        set("no_fight", "1");
        set("no_steal", "1");
        set("no_beg", "1");
        setup();
}
void init()
{
       if(this_player()->query("zhuanshi/jineng"))
       add_action("do_break","break");
       else
       {
        message_vision(HIY"忽然洞中狂风大作，$N被狂风一把卷起，"
        +"转眼不知去向！\n"NOR,this_player());
        this_player()->move(__DIR__"yongdao");
       }
}

int do_break(string arg)
{
       object me=this_player(),ob,*ulist,*ilist;
       int i,j;

        ilist=all_inventory(me);
        j=sizeof(ilist);
        while(j--)
        if(ilist[j]->query("zhuanshi/jineng"))
        {
         write("你身上已经带有神兵宝物了，不要贪得无厌！\n");
         return 1;
        } 

       if(!arg || arg!="bi")
       {
        write("你要用掌力震碎什么？\n");
        return 1;
       }
       if(me->query("neili") < me->query("max_neili"))
       {
        write("你现在内力不充盈，无法施展内功震开洞壁！\n");
        return 1;
       }
       me->set("neili",0);
       me->start_busy(10);
       ulist=users();
       i=sizeof(ulist);
       while (i--)
       {
        if ( !environment(ulist[i]) ) continue; 
        ilist=all_inventory(ulist[i]);
        for(j=0;j<sizeof(ilist);j++)
        if(ilist[j]->query("biwu") && ilist[j]->query("id_id")=="tai-e jian")
        {
         ob=ilist[j];
         write("你来迟了，"+ob->query("name")+"已经被人取走了！\n");
         return 1;
        }
       }

       ob=new(__DIR__"obj/tai-e");
       ob->move(environment(me)); 
       message_vision(
       HIW"$N运足掌力，猛地朝洞壁击去，只听轰的一声巨响，一道白光\n"
       +"夺壁而出，嚓的一声落到了你的眼前！\n"NOR,me);
       message("channel:rumor",HIM"【浴血秘闻】据闻"NOR+ob->query("name")
       +HIM"重新得遇良主！\n"NOR,users()); 
       return 1;
}

