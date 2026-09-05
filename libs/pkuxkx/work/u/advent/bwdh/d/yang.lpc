// yang.c 扬过 modify by Chui
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_me();
string ask3();
string ask2();
void consider();
void heal();

void create()
{
        set_name("杨过", ({ "yang guo", "yang","guo" }));
       set("nickname", HIR "西狂" NOR);
        set("long",
                "他就是古墓派的扬过、人们都叫他神雕大侠。\n"
                "身穿一件灰衣。\n"
                "身材高大，三十多岁的样子，据说蒙古皇帝蒙哥就是他杀的。\n");
        set("title",RED "终南山" NOR + RED "隐士" NOR);
        set("gender", "男性");
        set("age", 32);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 20);
        set("per",35);
        set("anran",1);
        set("max_qi", 10000);
        set("max_jing", 10000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 200);
        set("combat_exp", 15000000);
        set("score", 300000);

        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: consider :),
        }) );
        set_skill("force", 300);
        set_skill("jiuyin-shengong", 300);
        set_skill("dodge", 300);
        set_skill("xianyun", 300);
        set_skill("strike", 300);
        set_skill("xiaohun-zhang", 350);
        set_skill("parry", 300);
        set_skill("sword", 300);
        set_skill("quanzhen-jian", 300);
        set_skill("cuff",300);
        set_skill("meinu-quan",300);
        set_skill("xuantie-jian",300);
        set_skill("literate", 200);
        set("book_count",1);

        map_skill("force", "jiuyin-shengong");
        map_skill("dodge", "xianyun");
        map_skill("cuff", "meinu-quan");
        map_skill("strike","xiaohun-zhang");
        map_skill("parry", "xiaohun-zhang");
        map_skill("sword", "quanzhen-jian");
        prepare_skill("strike", "xiaohun-zhang");

        create_family("古墓派", 4, "弟子");
        set("chat_chance", 100);
        set("inquiry", ([
   		"君子剑" : (: ask_me :),      
                "黯然销魂": (: ask2 :),
                "玄铁剑法": (: ask3 :),
        ]) );
        setup();        
        carry_object("/clone/weapon/changjian")->wield();
}
void attempt_apprentice(object ob)
{
        if((string)ob->query("family/family_name")!="古墓派")
                {
                 command("say " + RANK_D->query_respect(ob) + "若想拜我派可先拜小虹小玲.");
                return;
                }
   if((int)ob->query("betrayer")>0)
   {
   command("say 学武之人最忌背信弃义，你是判师之人，我怎么能够收你!\n");
   return;
    }
                
        if((int)ob->query("score")<1500)
{
   command("say 你对我派的贡献还不够，我暂时不能够收你!\n");
return;
}
        if((int)ob->query_skill("jiuyin-shengong",1)<50)
                {
                command("say " + RANK_D->query_respect(ob) + "九阴神功火候不够，不适合学我的功夫。");
                return;
                }
        if((int)ob->query("max_neili")<500)
                {
                 command("say " + RANK_D->query_respect(ob) + "内力太低，不适合练我的功夫。"); 
                return;
                }
        if (((int)ob->query("dex")+(int)ob->query_skill("dodge",1)/10)<20)
      {
                command("say" + "我古墓派的功夫以轻灵为主，" + RANK_D->query_respect(ob) + "似乎对轻功不太重视吧。");
  		return;
                }
        else
          {
        command("say 好吧，"+RANK_D->query_respect(ob)+"，我就收下你了！");
        command("recruit "+ob->query("id"));
           }
       
}
void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                {       
                        if(ob->query("gender")=="女性")
                        ob->set("title",GRN "古墓派" NOR + MAG +"圣女" NOR);      
                        else
                        ob->set("title",GRN "古墓派"NOR + MAG + "圣使" NOR);
                        return;               
                }
}
void re_rank(object student)
{       if(student->query("gender")=="女性")
        student->set("title",GRN "古墓派" NOR + MAG +"圣女" NOR);
        else student->set("title",GRN "古墓派"NOR + MAG + "圣使" NOR);  
      return;
             
}
string ask_me()
{        mapping fam;
        object ob;
         object me=this_player();
            if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "古墓派")
             return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if((int)me->query_temp("sword1")==1)
        return "你已经拿了一把宝剑了，还想要第二把呀";
        if((int)me->query_skill("quanzhen-jian",1)<80)
        return "你的全真剑法太低，要了君子剑也发挥不出它的威力。";
        if (query("book_count") < 1)
                return "你来晚了，本派的君子剑不在此处。";
        add("book_count", -1);
        ob = new("/d/gumu/obj/sword2");
        ob->move(this_player());
        me->set_temp("sword1",1);
        return "好吧，这把君子剑你拿回去好好保管。";
}
string ask2()
{mapping fam;
        object me=this_player();
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派" )
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        else
        {
        message_vision("杨过说道：“好吧，我就教你黯然销魂一式吧。”\n",me);
       
        me->set("anran",1);
 return "记住，不要用我教你的来作恶，不然我决不轻饶。\n";
        }
}
string ask3()
{	mapping fam;
        object me=this_player();
        if (!(fam = this_player()->query("family")) || fam["family_name"] != "古墓派" )
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        else
        {
         if (this_player()->query("score")<1000 )
                return RANK_D->query_respect(this_player()) +"是否能够多为本派出点力？";
               else
                  {
        message_vision("杨过说道：“当年我面对汹涌的海潮领悟的剑招。”\n",me);
         if (this_player()->query_skill("xuantie-jian",1)<1)
            {
        message_vision("杨过说道：“好吧，我就教你玄铁剑法一式吧。”\n",me);
        me->set_skill("xuantie-jian",1);
                 }
            else 
            {
          message_vision("杨过说道：“我不是交给你玄铁剑的心法吗？。”\n",me);
            }
 	return "记住，不要用我教你的来作恶，不然我决不轻饶。\n";
                     }
        }
}  
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(3) )
        {
            case 0:
            command("exert yihun " + target->query("id"));
            break;
            case 1:
            if (query("eff_qi")<query("max_qi"))
            command("perform strike.anran " +target->query("id"));
            break;
            case 2:
            command("wield jian");
            command("perform sword.xiongyong " +target->query("id"));
            command("unwield jian");
        }
}    
void heal()
{
        object ob=this_object();
        
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("enforce 100");
                return;
        }

        if (ob->query("qi") < ob->query("eff_qi"))
        {
                command("exert recover");
                return;
        }

        if (ob->query("jing") < ob->query("eff_jing"))
                command("exert regenerate");

        return;
}
