//tanchuduan.c  谭处端
#include <ansi.h> 
#include <ansi.h>
inherit BHNPC;

void create()
{
        set_name("谭处端", ({"tan chuduan", "tan", "chudan"}));
        set("nickname", HIC"长真子"NOR);
        set("gender", "男性");
        set("age", 53);
        set("long",
             "他脸上筋肉虬结，浓眉大耳，身形魁梧，据说出家前是山东的铁匠。\n"
                "他就是全真七子的二师兄“长真子”谭处端。\n");
        set("attitude", "peaceful");
        set("class", "taoist");

        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("chat_chance", 1);
        set("chat_msg", ({
//                (: random_move :),
        }));

        
        set("inquiry", ([
                "铸剑"  : "铸剑是一门很高深的学问，我自问不比前人差，谁要铸剑呢？\n",
                "原料"  : "铸剑可用寒丝羽竹，海底金母，千年神木，千年玄铁。。。你找到了我才能帮你铸剑。。\n",
        ]) );


        
        set("qi", 1500);
        set("max_qi", 1500);
        set("jing",1350);
        set("max_jing", 1350);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);
        
        set("combat_exp", 3000000);
        set("score", 50000);
 
        set_skill("force",290);             // 基本内功
        set_skill("tiangang-zhengqi",290);    //天罡正气
        set_skill("unarmed",280);           // 基本拳脚
        set_skill("kongming-quan",280);    //空明拳 
        set_skill("dodge",280);              // 基本躲闪
        set_skill("qixing-huanwei",280 );        //七星换位
        set_skill("parry",290 );             // 基本招架
        set_skill("sword",290 );             // 基本剑法
        set_skill("quanzhen-jianfa",290);        //天罡剑法 
        set_skill("taoism",280 );            //道学心法  
        set_skill("literate",280);           //读书写字  
  
        map_skill("force", "tiangang-zhengqi");
        map_skill("unarmed", "kongmingquan");
        map_skill("dodge", "qixing-huanwei");
        map_skill("parry", "quanzhen-jianfa");
        map_skill("sword", "quanzhen-jianfa");
        
        create_family("全真教", 2, "长老");
        
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.qixing" :),
                (: exert_function, "recover" :),
        }) );


        setup();
        
        carry_object("/d/quanzhen/npc/obj/changjian")->wield();
        carry_object("/d/quanzhen/npc/obj/greyrobe")->wear();

}


/* void init()
{
        ::init();
        add_action("do_zhu","zhu");
}


int accept_object(object who, object ob)
{       
        
        who->delete_temp("sword");
        who->set_temp("m_sword",1);
        switch ((string)ob->query("name") ) 
        {
                case "千年神木": 
                        who->add_temp("shenmu",1);
                        break;
                case "海底金母":
                        who->add_temp("jinmu",1);
                        break;
                case "寒丝羽竹": 
                        who->add_temp("hanzhu",1);
                        break;
                default :
                        message("vision","这是什么！师傅说这不能用来打造兵器！",who);
                        return 0;
        }
        message("vision","谭处端低头检视了一下手中的"+(string)ob->query("name")+
                        "点了点头说：\n", who);
        message("vision","。。。好我们现在就开始铸剑\n", who);
        write("请这位"+RANK_D->query_respect(who)+"给剑起名字吧！(zhu 剑的名字 英文代号)\n");
        return 2;
}

int do_zhu(string arg)
{
        string o_name,id,w_name;
        object sword,make_time;   //生成的武器句柄
        object me;
        me = this_player();
        if(!(me->query_temp("m_sword")) ) 
                return notify_fail("什么?\n");
        me->delete_temp("m_sword");
        me->delete_temp("get_orc");
        me->delete_temp("or");

        if((me->query("weapon/make")) ){
                say("谭处端一脸茫然：您已经有一把自造的武器了，还来干什么？难到不称手么？\n");
                return 1;
        }
        if( !arg )
                return notify_fail("谭处端认真的说：想好剑的名称及代号后在对我说。\n");

        sscanf(arg ,"%s %s" ,w_name ,id);
        if(!w_name||!id)
                return notify_fail("什么?(使用zhu 剑的名字 英文代号\n)");
        if(me->query_temp("shenmu") ) o_name="千年神木";
        if(me->query_temp("jinmu") )   o_name="海底金母";
        if(me->query_temp("hanzhu") )   o_name="寒丝羽竹";
        make_time=NATURE_D->game_time();
        message_vision(me->name()+"沉吟了一会，对谭处端巧声说了几句话。谭处端点了点头。说：好吧！\n",me );
        message_vision("\n谭处端回过身，转向身后的一个巨大的火炉，鼓动真气燃起了熊熊的大火。说：开始！\n",me );
        message_vision(BLU "$N双手握住一个巨大的铁锤，猛的向炉中渐渐红热起来的"+o_name+"挥去！\n" NOR,me);
        message_vision(RED "只听得棚的一声巨响，锤头和"+o_name+"粘在了一起。\n" NOR,me );
        message_vision(YEL "$N只觉得掌心一热，浑身的血液似乎都沸腾了起来！\n" NOR,me);
        message_vision(HIM "一身精血胶合着汩汩的内气，源源不断的向炉中的"+o_name+"涌去！\n" NOR,me );
        if( (me->query("qi"))<(me->query("max_qi")) || (me->query("jing"))<(me->query("max_jing")) || (me->query("neili"))<(me->query("max_neili")) )
        {
                message_vision(HIR "突然$n觉得气血一阵翻涌，一口真气接不上来。。。。 \n" NOR, me);
                me->set("neili",0);
                me->unconcious();
                return 1;
        }
        message_vision(HIR "只听咯的一声轻响，一柄巨剑从炉中倏然跃起。化作一道青电猛的向$N的前胸刺来！！\n" NOR,me );
        say("谭处端见状大叫：神剑初成，人血以祭！！闪开！\n");
        message_vision("$N只觉得眼前一花，一条白影迅捷无比的挡在了$N的身前。\n",me );   
        message_vision("巨剑透胸穿出，谭处端惨号一声，鲜血溅得你满脸都是！\n",me );
        message_vision(RED "谭处端脚下一个不稳，倒在了地上。谭处端已经奄奄一息了。\n" NOR,me);
        this_object()->set("max_qi",10);
        message_vision("巨剑又飞了起来，飞到半空，当的一声落回到地上。\n炉中的火灭了。一室的劲气化于无形，一切又归于沉寂。\n",me );
        
        me->set("qi",10);
        me->set("jing",10);
        me->set("neili",0);

        me->set("weapon/make",1);               //武器制造后防止再造的标志              
        me->set("weapon/name",w_name);  //武器的名称
        me->set("weapon/id",id);                //武器的代号
        me->set("weapon/lv",1);         //武器等级
        me->set("weapon/or",o_name);    //记录制造原料
        me->set("weapon/value",0);              //记录武器升级已有的点数        
        me->set("weapon/type","剑");
        me->set("weapon/time",make_time);

        sword=new("/d/quanzhen/npc/obj/m_sword",1);     //生成新剑
        sword->move(this_player());
        message_vision("谭处端摸起地上，带着斑斑血迹还有些烫手的巨剑，说：\n剑。。已。。成。。，侍剑的任务。。。也就完成了。。。。\n",me );
        say("谭处端艰难的说：剑。。您。。收好，记住。\n剑在。。人在。。剑亡。人亡。你该走了。。。\n");
//      message_vision("$N只觉眼前一花，醒来已经在三清殿了。\n",me);
//      message_vision("$N只觉眼前一花，$n已不见了踪影。\n",me);
//      message_vision("$N只觉眼前一花，$n突然出现在你的面前。\n",me);
        this_player()->move("/d/quanzhen/sanqingdian");
        return 1;
} */

