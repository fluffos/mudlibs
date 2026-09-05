// hong.c 洪安通

#include <ansi.h>;
#include <title.h>
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;
#include <no1master.h>
int ask_hero();
string ask_for_leave();

void create()
{
        set_name("洪安通", ({ "hong antong", "hong" }));
        set("title",  MAG"神龙教"NOR+HIW"教主"NOR );
        set("nickname", HIR "永享仙福" NOR);
        set("no_get",1);
        set("long", "他就是武功盖世、令江湖人等谈之色变的神龙教教主洪安通。\n他看起来甚老，白鬓垂胸，脸上都是伤疤皱纹，丑陋已极。");
        set("gender", "男性");
        set("age", 50);
        set("shenlong/yingxiong", 1);
        set("shenlong/meiren", 1);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 35);
        set("int", 30);
        set("con", 30);
        set("dex", 38);
        
        set("max_qi", 15000);
        set("qi", 15000);
        set("max_jing", 15000);
        set("jing", 15000);
        set("neili", 14000);
        set("max_neili", 14000);
        set("jiali", 200);
        set("combat_exp", 15000000);
        set("score", 400000);

        set_skill("force", 350);
//        set_skill("yangsheshu", 210);
//  加200级poison. by lordstar 2017/9/12
	set_skill("poison", 200);
        set_skill("zhaosheshu", 210);
        set_skill("shenlong-xinfa", 370);
        set_skill("dodge", 380);
        set_skill("yixingbu", 360);
        set_skill("strike", 360);
        set_skill("huagu-mianzhang", 360);
        set_skill("parry", 380);
        set_skill("literate", 280);
        set_skill("dagger", 350);
        set_skill("whip", 350);
        set_skill("shenlong-bian", 350);
        set_skill("dulong-bi", 350);

        map_skill("force", "shenlong-xinfa");
        map_skill("dodge", "yixingbu");
        map_skill("whip", "shenlong-bian");
        map_skill("dagger", "dulong-bi");
        map_skill("strike", "huagu-mianzhang");
        map_skill("hand", "shenlong-bian");
        prepare_skill("strike", "huagu-mianzhang");
		set_temp("apply/armor", 300);
		set_temp("apply/damage", 350);

        create_family("神龙教",1,"教主");

        set("inquiry", ([
                "神龙教" :  "\n一般人是入不了我神龙教的。\n",
                "入教" :  "\n一般人是入不了我神龙教的。\n",
                "洪安通" :  "\n你不想活了是不是?\n",
                "教主" :  "\n我就是神龙教教主。\n",
                "口号" : "\n万年不老!永享仙福!寿与天齐!文武仁圣!\n",
                "武功": (: ask_hero :),
                "英雄三招": (: ask_hero :),
                "绝招": (: ask_hero :),
                "脱离教派" : (: ask_for_leave :),
       ]) );
        set("chat_chance_combat", 50);  
        set("chat_msg_combat", ({
                (: command("smile") :),
                (: command("haha") :),
                (: CHANNEL_D->do_channel(this_object(), "bd", "凭你这" + RANK_D->query_rude(this_player())+",也敢在太岁爷头上动土?") :),
                (: command("say 你活得不耐烦了找死啊？\n") :),
                (: perform_action, "dagger.yingxiong" :),
                (: perform_action, "dagger.meiren" :),
                (: perform_action, "strike.hua" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "dagger.meiren" :),
                (: perform_action, "dagger.meiren" :),
                (: perform_action, "dagger.yingxiong" :),
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                      }) );
        setup();
		setup_no1master();
      carry_object("/d/pingxiwangfu/obj/dagger")->wield();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}

int recognize_apprentice(object me)
{
        if( me->query("learnhong")) return 1;
        if ((int)me->query("shen") > -1000) {
                command("say 我越看你越象白道派来卧底的。");
                        this_object()->set_leader(me);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, me); 
                return 0;
        }
        if( me->query_temp("pending/flatter") ) {
                command("say 你如此不把我放在眼里，我又怎能容你？!");
                        this_object()->set_leader(me);
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, me); 
                return 0;
        } else {
                command("say 我洪安通比起古往今来的圣人怎么样啊？");
                message_vision("洪安通微闭双眼，手捻长须，一付等人拍马(flatter)的样子。\n",
                this_player());
                me->set_temp("pending/flatter", 1);
        return 0;
        }
}

int do_flatter(string arg)
{
        if( !this_player()->query_temp("pending/flatter") )
                return 0;
        if( !arg ) return notify_fail("你说我什么？\n");
        this_player()->set_temp("pending/flatter", 0);
        message_vision("$N大声说道：" + arg + "\n", this_player());
        if( strsrch(arg, "万年不老") >=0 && (strsrch(arg, "永享仙福") >=0
         || strsrch(arg, "寿与天齐") >=0 || strsrch(arg, "文武仁圣") >=0 )) {
                command("smile");
                command("say 这还差不多。\n");
                this_player()->set("learnhong", 1);
                command("recruit " + this_player()->query("id"));
        } else {
                command("say 你如此不把我放在眼里，我又怎能容你？!");
                        this_object()->set_leader(this_player());
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, this_player()); 
        }
        return 1;
}

// 万年不老,永享仙福,寿与天齐,文武仁圣

/*void die()
{
message_vision("\n$N奇道：“咦,居然有人能杀了我,....”说完睁着两眼倒地死了。\n", this_object());
        ::die();
}*/

#include "/kungfu/class/masterdie.h"

void init()
{
        object ob;

	      add_action("do_leave",  "leave");	
        ::init();

        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
//                call_out("greeting", 50, ob);
        }
        add_action("do_flatter", "flatter");
}

string ask_for_leave()
{
	object me;

	me = this_player();

	if( (string)me->query("family/family_name") != "神龙教")
		return "你非我神龙教弟子，脱离教派的事情我作不得主。";

	me->set_temp("pending/leave_shenlong", 1);
  return "如果" + RANK_D->query_respect(me) + "真想离我神龙教而去，就请下决心(leave)吧！";
}

int do_leave()
{
	object me = this_player();
	
	if (me->query_temp("pending/leave_shenlong") != 1)
		return 0;
	message_vision("$N对$n说道：「从此你就不再是我神龙教门下了，请好自为之！」\n",this_object(), me );
	tell_object(me,HIR "你决定叛出神龙教门下！\n" NOR);
	me->delete_temp("pending/leave_shenlong");
  me->expell_family("神龙教");
	if (me->query("combat_exp") >= 1000)
		me->add("betrayer",1);
	return 1;
}	

void greeting(object ob)
{
        object obj;
        if (!ob) return;
        if (interactive(ob))
        {
        if (obj = present("usedgao", ob))          
           set("combat_exp",500000);
           set("qi",10);
           set("jing",10);
        }
        return;
}

void attempt_apprentice(object ob)
{
    if (ob->query("party/party_name") != MAG "神龙教" NOR ) {
        command("say 你不是本教教众, 想来找死啊!");
        return;
    }
    if ((int)ob->query_skill("shenlong-xinfa",1) < 100 ) {
        command("say 你的本门内功心法太低了,还是努努力先提高一下吧!");
        return;
    }
    if ((int)ob->query("score") < 1500 ) {
        command("say 你扪心自问一下，对本门有多少贡献？!");
        return;
    } 

    if ((int)ob->query("combat_exp") < 500000 ) {
        command("say 你的经验太少了，还是去江湖上闯荡闯荡吧!");
        return;
    }
    if ((int)ob->query("repute") < 30000 ) {
        command("say 你在江湖上还没有混出什么名堂，我怎么能收你做我的弟子？");
        return;
    } 

    if ((int)ob->query("shen") > -10000  ) {
        command("say 我神龙教与世隔绝，向来不与这种白道人物打交道，您请回吧！");
        return;
    }
    command("say 很好，很好。");
    command("recruit " + ob->query("id"));
    ob->set("title",ob->query("party/party_name")+HIC"使者"NOR);
//title系统记录玩家title by seagate@pkuxkx
	  ob->set_title(TITLE_RANK, ob->query("title"));
}
 

int accept_object(object me, object ob)
{
        string men;
        if( !me || environment(me) != environment() ) return 0;
        if ( !objectp(ob) ) return 0;
        if ( !present(ob, me) ) return 0;

        if (me->query("party/party_name") != MAG"神龙教"NOR && me->query("family/family_name") != "神龙教")
        {
                tell_object(me, "你无缘无故给我这个干什么啊？\n");
                return 0;
        }

        if (me->query("family/master_name") != "洪安通")
        {
                tell_object(me, "你好好练功，做了我的弟子再帮我找经书吧。\n");
                return 0;
        }
 
       if (me->query("shenlong/42jing")>0)
        {
                tell_object(me, "你已经找了经书给我了啊，这个又是从哪里弄来的？\n");
                return 0;
        }
        
        if ( (string)ob->query("name") == YEL"四十二章经"NOR && ob->query("id") == "sishierzhang jing")
        {
                if (!me->query("shenlong/jingp1"))
                me->set("shenlong/jingp1", 1);
                else
                {
                        tell_object(me, "这本经书你已经给过我了啊？\n");
                        return 0;
                }
        }
        if ( (string)ob->query("name") == HIY"四十二章经"NOR && ob->query("id") == "sishierzhang jing")
        {
                if (!me->query("shenlong/jingp2"))
                me->set("shenlong/jingp2", 1);
                else
                {
                        tell_object(me, "这本经书你已经给过我了啊？\n");
                        return 0;
                }
        }
        if ( (string)ob->query("name") == BLU"四十二章经"NOR && ob->query("id") == "sishierzhang jing")
        {
                if (!me->query("shenlong/jingp3"))
                me->set("shenlong/jingp3", 1);
                else
                {
                        tell_object(me, "这本经书你已经给过我了啊？\n");
                        return 0;
                }
        }
        if ( (string)ob->query("name") == HIB"四十二章经"NOR && ob->query("id") == "sishierzhang jing")
        {
                if (!me->query("shenlong/jingp4"))
                me->set("shenlong/jingp4", 1);
                else
                {
                        tell_object(me, "这本经书你已经给过我了啊？\n");
                        return 0;
                }
        }
        if ( (string)ob->query("name") == RED"四十二章经"NOR && ob->query("id") == "sishierzhang jing")
        {
                if (!me->query("shenlong/jingp5"))
                me->set("shenlong/jingp5", 1);
                else
                {
                        tell_object(me, "这本经书你已经给过我了啊？\n");
                        return 0;
                }
        }
        if ( (string)ob->query("name") == HIR"四十二章经"NOR && ob->query("id") == "sishierzhang jing")
        {
                if (!me->query("shenlong/jingp6"))
                me->set("shenlong/jingp6", 1);
                else
                {
                        tell_object(me, "这本经书你已经给过我了啊？\n");
                        return 0;
                }
        }
        if ( (string)ob->query("name") == WHT"四十二章经"NOR && ob->query("id") == "sishierzhang jing")
        {
                if (!me->query("shenlong/jingp7"))
                me->set("shenlong/jingp7", 1);
                else
                {
                        tell_object(me, "这本经书你已经给过我了啊？\n");
                        return 0;
                }
        }
        if ( (string)ob->query("name") == HIW"四十二章经"NOR && ob->query("id") == "sishierzhang jing")
        {
                if (!me->query("shenlong/jingp8"))
                me->set("shenlong/jingp8", 1);
                else
                {
                        tell_object(me, "这本经书你已经给过我了啊？\n");
                        return 0;
                }
        }
        call_out("destroy", 1, ob);
        if ( me->query("shenlong/jingp1")+ me->query("shenlong/jingp2") + me->query("shenlong/jingp3") + me->query("shenlong/jingp4")
             + me->query("shenlong/jingp5") + me->query("shenlong/jingp6") +  me->query("shenlong/jingp7") + me->query("shenlong/jingp8")>=3 )
        {
                me->delete_temp("jing");
                message_vision("$N大喜道：“干得好！”。\n", this_object());
                me->set("shenlong/42jing", 1);
                me->delete("shenlong/jingp1");
                me->delete("shenlong/jingp2");
                me->delete("shenlong/jingp3");
                me->delete("shenlong/jingp4");
                me->delete("shenlong/jingp5");
                me->delete("shenlong/jingp6");
                me->delete("shenlong/jingp7");
                me->delete("shenlong/jingp8");
                switch (random(5))
                {
                case 0 : men=HIC"青龙使"NOR; break;
                case 1 : men=HIW"白龙使"NOR; break;
                case 2 : men=BLK"黑龙使"NOR; break;
                case 3 : men=HIR"赤龙使"NOR; break;
                default: men=HIY"黄龙使"NOR; break;
                }
    tell_object(me, RANK_D->query_respect(me) + "辛苦了，本座这就荣升你为"+men+"吧!");
                me->add("combat_exp", 10000);
                me->set("title",MAG"神龙教"+men);
//title系统记录玩家title by seagate@pkuxkx
	              me->set_title(TITLE_RANK, me->query("title"));
                tell_object(me, "你的经验增加了！\n");
        }
        else
                tell_object(me, RANK_D->query_respect(me) + "快把剩下的经书找齐给我吧。\n");
	      call_out("destroy",1,ob);

        return 1;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}
int ask_hero()
{
        object ob;
        ob=this_player();
        if(ob->query("party/party_name") != MAG "神龙教" NOR)
        {
        command("slap "+ob->query("id"));        
        message_vision("洪安通怒道：哪里来的奸细，给我滚！！！\n",ob);
        return 1;
        }
        if(ob->query("family/family_name") !=  "神龙教")
        {
        command("slap "+ob->query("id"));        
        message_vision("洪安通怒道：哪里来的奸细，给我滚！！！\n",ob);
        return 1;
        }
        if(ob->query("family/master_name") != "洪安通")
        {
        command("look "+ob->query("id"));        
        message_vision("洪安通说道：我的绝招只传授给我的弟子！\n",ob);
        return 1;
        }
        if((int)ob->query("score") <2000)
        {
        command("consider");        
        message_vision("洪安通说道：你对本教的贡献太小了，绝招还不能传授给你！\n",ob);
        return 1;
        }
       if((int)ob->query("shenlong/42jing") <1)
        {
        command("consider");        
        message_vision("洪安通说道：本教正在全力寻找四十二章经，如果你能找到其中几本，我就把绝招传授给你！\n",ob);
        return 1;
        }
        if(ob->query("shenlong/yingxiong"))
        {
        command("?");        
        message_vision("洪安通说道：我不是已经教会你了么？！\n",ob);
        return 1;
        }
        command("wa1");
        command("great");
        command("pat "+ob->query("id"));
       ob->set("shenlong/yingxiong",1);
        command("say 我这就把英雄三招传授给你! ");
        return 1;
}
