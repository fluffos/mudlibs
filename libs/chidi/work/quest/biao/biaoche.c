#include <ansi.h>
inherit ITEM;

mapping default_dirs = ([
        "north":        "北面",
        "south":        "南面",
        "east":         "东面",
        "west":         "西面",
        "northup":      "北边",
        "southup":      "南边",
        "eastup":       "东边",
        "westup":       "西边",
        "northdown":    "北边",
        "southdown":    "南边",
        "eastdown":     "东边",
        "westdown":     "西边",
        "northeast":    "东北",
        "northwest":    "西北",
        "southeast":    "东南",
        "southwest":    "西南",
        "up":           "上面",
        "down":         "下面",
        "enter":        "里面",
        "out":          "外面",
]);

void create()
{       
        seteuid(getuid());
        set_name(HIW"镖车"NOR, ({ "biao che", "cart", "che"}) );
        set_weight(300000);
        set("no_get", 1);
        set("unit", "辆");
        set("value", 0);
        set("long", 
          HIW"一辆福威镖局的镖车，一干镖头正准备赶车(gan)起程呢。"NOR); 
        set("owner","xingyun");
        set("owner_name","无云");
        set("no_clean_up",1);
        setup();
        call_out("destroy1",2,this_object());
}

void init()
{
    if(this_player()->query("id") == this_object()->query("owner"))
    {
         add_action("do_gan","gan"); 
         add_action("do_gan","drive");
    }
}

void start_escape_me()
{
    call_out("destroy2",(int)query("time"),this_object());
}

int destroy2(object ob)
{
    object me;
    if(objectp(ob))
    {
     message("channel:rumor",MAG"【镖局传闻】由于"+query("owner_name")+
     "护送的镖车未能如期抵达，福威镖局已派人前去接管镖车！\n"NOR,users());

     tell_object(all_inventory(environment(ob)),
        HIW"忽然，远远走来一群人，原来是总镖头派人前来了，为首的镖师\n"
        +"边走嘴里还边骂道：“他奶奶的！等了这么久也还没到，总镖头\n"
        +"还以为让人给劫了，害老子白跑一趟！”说完，一干人等拉起镖\n"
        +"车，扬长而去！\n"NOR);

     remove_call_out("destroy1");
     remove_call_out("destroy2");

     me=present(ob->query("owner"),environment(ob));
     if(objectp(me))
     {
     me->set_temp("quest_yunbiao/have_task",0);
     me->set_temp("quest_yunbiao/finished_time",time());
     }
     destruct(ob);
    }
    return 1;
}

int do_gan(string arg)
{        
        object me,ob, env, obj, robber,*killer;
        string item, dir, dest, target;
        int reward_exp,reward_pot,reward_score,flag,i;

        mapping exit;
        me = this_player();
        ob = this_object();

        if(!arg) return notify_fail("你要赶什么？\n");

        if( me->query("id")!=ob->query("owner")) 
          return notify_fail("你赶的不是自己的镖车吧？\n"); 

        if( sscanf(arg, "%s to %s", item, dir) != 2 
           || item != "biao che" && item != "che")
          return notify_fail("指令：gan 镖车 to 方向 \n");        
                        
        if( me->is_busy() )
        return notify_fail("你现在正忙着哩。\n");

        flag=0;
        killer=all_inventory(environment(me));
        for(i=0;i<sizeof(killer);i++)
        {
        if(objectp(killer[i]) 
          && killer[i]->query("killer")==me->query("id"))
         flag=1;
        }

        if (flag)   
        return notify_fail(CYN"你还是先把眼前的敌人解决了再说吧！\n"NOR);
        
        env = environment(me);
        if(!env) return notify_fail("你要去那里？\n");

        if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) ) 
        return notify_fail("这个方向过不去。\n");
        
        dest = exit[dir];

        if( !(obj = find_object(dest)) )
                call_other(dest, "???");
        if( !(obj = find_object(dest)) )
                return notify_fail("那里好象过不去。\n");

        if( !undefinedp(default_dirs[dir]) )
                target = default_dirs[dir];
        else
                target = obj->query("short");

       message_vision(HIG"$N赶着镖车往" + target + "驶去。\n" NOR,me);  
        
       if(file_name(obj)!=ob->query("file"))
       {
         if( ob->move(obj) && me->move(obj)) 
         {
          all_inventory(env)->follow_me(me, dir);
          message_vision(HIG "$N赶着镖车驶了过来。\n" NOR,me);
          me->start_busy(random(2)+2);
         }

         if (random(12)<2 && !environment(ob)->query("no_fight"))
         {
          robber=new(__DIR__"robber");
          robber->set("killer",me->query("id")); 
          robber->move(environment(ob));  
          message_vision(HIB"冷不丁，从斜路里忽得杀出一道人影，拦住"
                                           +"了你的去路！\n"NOR,me);
          robber->check_me();  
          me->start_busy(2);
          robber->start_busy(2);
         }
       } else
       {
        reward_exp=(int)me->query("kar")*1000+(int)me->query("per")*1000;
        reward_exp=reward_exp+(int)me->query("quest_yunbiao/bonus")*15;
        if(reward_exp>100000) reward_exp=100000;
        reward_exp=reward_exp*5+random(reward_exp*5);
        reward_pot=reward_exp/4;
        reward_score=reward_exp/40;

message("channel:rumor",HIY"【镖局传闻】"+me->query("name")+
"运送的镖车历经千辛万苦，终于顺利抵达！\n"
+me->query("name")+"获得了"+CHINESE_D->chinese_number(reward_exp)
+"点实战经验、"+CHINESE_D->chinese_number(reward_pot)+"点潜能\n"
+"及"+CHINESE_D->chinese_number(reward_score)+"点综合评价奖励！\n"NOR,
users());

       me->add("quest_yunbiao/reward_exp",reward_exp);
       me->add("quest_yunbiao/reward_potential",reward_pot);
       me->add("combat_exp",reward_exp);
       me->add("potential",reward_pot);
       me->add("score",reward_score);

       me->set_temp("quest_yunbiao/have_task",0);
       me->set_temp("quest_yunbiao/finished_time",time());
       remove_call_out("destroy1");
       remove_call_out("destroy2");
       destruct(ob);
       }
   
   return 1;
}

int destroy1(object ob)
{
    object me;

    if(!objectp(ob) || !environment(ob) )
    return 1;

    if(objectp(ob) && !present(ob->query("owner"),environment(ob)))
    {
     me=find_player(ob->query("owner"));
     if(!me) me=find_living(ob->query("owner"));
     if(objectp(me))
     me->delete_temp("quest_yunbiao");

     message("channel:rumor",HIB"【镖局传闻】"+query("owner_name")
     +"护送的镖车在半路让人给劫了！\n"NOR,users());
     remove_call_out("destroy1");
     remove_call_out("destroy2");
     destruct(ob);
    } else
    {
    remove_call_out("destroy1");
    call_out("destroy1",2,ob);
    return 1;
    }
}

