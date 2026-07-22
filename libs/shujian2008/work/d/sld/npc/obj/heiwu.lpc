// heiwu.c
// 黑屋
inherit ROOM;
void create()
{
	set("short","黑屋");
	set("long",@long
这里是神龙教弟子犯错时受惩罚的地方，整个屋子没有一扇窗子，也没
有门，只在屋顶开了个洞口，装了块翻板。这里整日暗不见光，腥臭扑鼻，
里面无桌无椅更无床，累了只能躺在地上或扶(fu)墙站着。这里只有诚心悔
过(repent)的人才能出去。
long);
      //set("no_fight",1);
      set("valid_startroom", 1);      setup();
}

void init()
{        
     add_action("do_fu","fu");
     add_action("do_mo","mo");
     add_action("do_repent","repent");
     add_action("do_quit","quit");
}

int do_quit(string arg)
{
    object me=this_player();

    me->set("startroom","/d/sld/npc/obj/heiwu");    return 0; 
}

int do_fu(string arg)
{
    object me=this_player();
    //object ob=this_object();
    //int qi;

    if(!arg || (arg!="wall" && arg!="墙" && arg!="墙壁"))
        return notify_fail("你要扶什么？\n");
    if(random(10)>5)
    {
        tell_object(me,"你扶了下墙壁，触摸(mo)到墙上好象刻着一些字。\n");
        me->set_temp("heiwu/mo",1);
    }
    else
        tell_object(me,"你扶了下墙壁。\n");
    return 1;
}

int do_mo(string arg)
{
    object me=this_player();
    int cost,i,j,my_skill;
    string zhao_name;
    string* skill= ({ "force","dodge","parry","strike","throwing","whip","shenlong-yaoli","poison" });
    int flag;

    if(!arg || (arg!="wall" && arg!="墙" && arg!="墙壁") || (me->query_temp("heiwu/mo",1)!=1))
        return notify_fail("你要摸什么？\n");
    if( !me->query_skill("literate", 1) )
        return notify_fail("你是个文盲，先学点文化(literate)吧。\n");              
    //if( me->query_int() < skill["difficulty"])
        //return notify_fail("以你目前的领悟能力，还没有办法学这个技能。\n");
    i=random(sizeof(skill));
    j=i;
    flag=0;
    do
    {
        if(me->query_skill(skill[j], 1)!=0)
        {
            if( !SKILL_D(skill[j])->valid_learn(me) ) 
            {
                if(flag==0) flag=1;
            }
            else if( me->query_skill(skill[j], 1) > 49 )
                flag=2;
            else 
                break;
        }    
        j++;
        if(j>=sizeof(skill)) j=0;
        if(j==i)
        {
            if(flag!=2)
                return notify_fail("你摸了半天，结果一无所获。\n");
            else
                return notify_fail("你摸了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
        }
    } while(1);
    //if( !SKILL_D(skill[j])->valid_learn(me) )
        //return notify_fail("你摸了半天，结果一无所获。\n");     
    cost = 50-me->query_skill(skill[j],1)*(int)me->query_int()/20;
    if (cost < 10) cost = 10; // minimum cost
    //if( me->query_skill(skill[j], 1) > 49 )
        //return notify_fail("你摸了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
    my_skill = me->query_skill(skill[j], 1);
    if( (int)me->query("jing") > cost ) {
        if( (string)SKILL_D(skill[j])->type()=="martial" &&
          my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
        {
            printf("也许是缺乏实战经验，你对摸到的东西总是无法领会。\n");
        } 
        else {
            if(zhao_name = SKILL_D(skill[j])->query_skill_name(my_skill))
                printf("你钻研有关%s的技巧，对「%s」这一招似乎有些心得。\n", 
                       to_chinese(skill[j]), zhao_name);
            else
                printf("你钻研有关%s的技巧，似乎有点心得。\n", to_chinese(skill[j]));
            me->improve_skill(skill[j], 
            ((int)me->query_skill("literate", 1)/5+1)*me->query_kar()/20);
        }
        me->receive_damage("jing", cost );
    } 
    else {
                //cost = me->query("jing");
        write("你现在过于疲倦，无法专心下来研读新知。\n");
    }
    return 1;
}

int do_repent(string arg)
{
    object me=this_player();

    if((time()-me->query("in_heiwu"))/60<15)
        return notify_fail("你悔过的时间太短。\n");
    if(random(me->query_kar())==0)
    {
        me->set("in_heiwu",time()-840);
        return notify_fail("你还不够诚心。\n");
    }
    me->delete_temp("heiwu/mo");
    me->move("/d/sld/dt");
    me->set("startroom","/d/city/kedian");    return 1;   
}
    
