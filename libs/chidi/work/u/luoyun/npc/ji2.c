// jixiaolan 纪晓岚

#include <ansi.h>

inherit BHNPC;

void create()
{
        set_name(HIR"纪晓岚"NOR, ({ "ji xiaolan", "ji","master" }) );
        set("title", HIC "铁齿铜牙" NOR);
        set("gender", "男性");
        set("age", 48);
        set("long", "此人诚恳敦厚，眉目菱角分明，气宇轩昂。\n");
        set("attitude", "peaceful");
        set("str", 38);
        set("int", 39);
        set("con", 32);
        set("dex", 33);
        set("max_qi", 2000000);
        set("max_jing", 2000000);
        set("neili", 30000);
        set("max_neili", 30000);
        set("jiali", 100);
        set("combat_exp", 50000000);        
        set_skill("literate", 25000);       
        set("no_suck", 1);


        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/zhujian")->wield();
        set("startroom", "/d/city2/shuyuan");       
}


void init()
{
   add_action("do_study","qingjiao");
}


int do_study(string arg)
{
     string skill; 
     object me=this_player(),ob=this_object();
     if (ob->is_fighting())
     return notify_fail("纪晓岚忙着料理别人，没空理你耶。\n");
     
     if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

     if( !living(ob) )
     return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");

     if( !arg || arg!="literate")
     return notify_fail(HIY"你要向纪晓岚请教(qingjiao)什么？\n"NOR); 
     
     if (!me->query_condition("can_dushu"))
     return notify_fail(HIG "你还没领悟《四库全书》之精髓!\n" NOR); 
      
     if (me->query_skill("literate", 1) < 2000)
     return notify_fail(HIB"你的读书写字还不够领悟《四库全书》之精髓！\n"NOR);

     if (me->query_skill("literate", 1) > 30000)
     return notify_fail(HIR "这项技能你的程度已经不输你师父了!\n" NOR); 

     if( me->query("potential")<=150 )
     return notify_fail("你的潜能不够了！\n"); 

     if( me->query("jing") < 100 || me->query("qi") < 400 )
     return notify_fail("你现在太累了，先休息一下吧！\n"); 

     me->receive_damage("qi",10 + random(40));
     me->receive_damage("jing", 10 + random(40));        
     me->add("potential",-10);
     tell_object(me,HIC"纪晓岚指点了你一些有关"HIW"「读书写字」"HIC"的问题，"
                    +"你似乎有些心得。\n"NOR);
     me->improve_skill("literate",4000*(10+ random((int)me->query_int() - 9)));

     return 1;
}

int accept_object(object me, object ob)
{

      if (base_name(ob) != "/clone/fam/gift/int_book")
        {
                command("say 你给我这种东西干什么？");
                return 0;
        }
     //   if (!me->query("zhuanshi/times"))
     //   {
    //            command("say 等你投胎转世后再说吧！");
    //            return 0;
   //     }
       // if (!me->query("is_member"))
      // {
        //        command("say 你必须是会员才能领悟《四库全书》之精髓！");
         //       return 0;
       //}


        if (me->query_skill("literate", 1) < 2000)
        {
                command("shake"); 
                command("say 可惜，可惜！你的读书写字还不够深，还无法领悟到《四库全书》之精髓！");                
                return 0;
        }

        if (me->query_condition("can_dushu"))
        {
                command("nod");
                command("say 你已经领悟了《四库全书》之精髓，下去好好练习吧！");                
                return 0;
        }

        if (me->query("int") < 10)
        {
                command("say 你先天悟性不够，不知道你是怎么领悟《四库全书》！\n");
                return 0;
        }

        if (me->query("con") < 10 && me->query("dex") < 10)
        {
                command("say 你先天身法和根骨都不够100，领悟不到《四库全书》之精髓！\n");
                return 0;
        }
        // 开始允许学习技能
        command("nod");
        command("say 不错，不错！既然如此，我就将《四库全书》之精髓传授于你。");        
        me->apply_condition("can_dushu", 360);
        tell_object(me, HIG "你现在可以和我学习「读书写字」了。\n" NOR);
        destruct(ob);
        me->start_busy(1);
        return 1;
}
void unconcious()
{
        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));        
        say( "纪晓岚狞笑着说：我是无敌不死版！\n");
        
}

void die()
{
        unconcious();
}
