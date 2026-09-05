//it is a test npc made by hacky;please not copy it

#include <ansi.h>

inherit NPC;
int ask_xueyi();
inherit F_MASTER;

string *rnd_say = ({
        "谁想跟我比武? ",
        "为什麽我的精气神都不会恢复？",
        "有谁可以给我一些钱？",
        "这里的人都不理我！",
	"为什么这里的人不聊聊天呢？",
        "怎么没有人跟我玩呢？",
        "hi",
        "hello",
        "hmm",
        "wa...",
        "waley",
        "wait...",
        "hohoho",
        "hehe",
        "ah..",  
});

varargs void drool(string msg, string who);

void create()
{



        set_name("周伯通", ({"zhou botong", "zhou" }) );
        set("nickname", GRN"老顽童"NOR);
        set("gender", "男性");
        set("age", 60);
        set("attitude", "friendly");
        set("combat_exp", 300000);
        set("env/wimpy", 10);
   
        set("max_qi",900);
        set("eff_qi",900);
        set("max_neili",2400);
        set("neili",2400);
        set("score",1000);
        set("shen",10000);

        set("chat_chance", 80);
        set("chat_msg", ({
                (: command, "get all" :),
                (: command, "wear all" :),
                (: command, "wield all" :),
//                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (: drool :),
                (:random_move():),
           }) );
         
        set_skill("parry",170);
        set_skill("cuff",180);
        set_skill("force",110);
        set_skill("xiantian-gong",160);
        set_skill("kongming-quan",200);
        set_skill("daoxue-xinfa",50);
        set_skill("jinyan-gong",100);
        set_skill("dodge",150);
        
        map_skill("dodge","jinyan-gong");
        map_skill("parry","kongming-quan");
        map_skill("cuff","kongming-quan");
        map_skill("force","xiantian-gong");
 
        set("inquiry", ([
         "左右互搏" : (: ask_xueyi : ),
        ])),  
        
        setup();
        if( clonep() ) CHANNEL_D->register_relay_channel("chat");

}

void attempt_apprentice(object ob)
{
   command("chat* haha");
   command("chat "+ob->query("name")+"要拜我为师");
   command("chat 我就是不收! 嘿嘿。。。。");
   return;
 }

int add_phrase(string who, string msg)
{
        msg = replace_string(msg, "?", "");
        msg = replace_string(msg, "？", "");
        msg = replace_string(msg, "!", "");
        msg = replace_string(msg, "！", "");
        msg = replace_string(msg, "啊", "");
        msg = replace_string(msg, "吗", "");
        msg = replace_string(msg, "耶", "");
        msg = replace_string(msg, "吧", "");
        msg = replace_string(msg, "吧", "");

        if( msg!="" ) 
	{
                add("memory/" + who, ({ msg }));
                return 1;
        }
	else return 0;
}

string make_reply()
{
}

void relay_channel(object ob, string channel, string msg)
{
        string who, phrase;

        if( !userp(ob) || (channel != "chat") ) return;
        who = ob->query("name");

        // Don't process our own speech.
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) &&     random(10) > 5 )
                drool(msg, ob->query("name"));
}
/*
void relay_say(object ob, string msg)
{
        string who, phrase;

        if( !userp(ob) ) return;
        who = ob->query("name");

        // Don't process our own speech.
        if( ob==this_object() ) return;

        if( add_phrase(who, msg) &&     random(10) > 4 )
                drool(msg, ob->query("name"));
}
*/
void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb) 
	{
        case "kick":
                if( random(10)<5 ) 
		{
                        command("chat 为什麽踢我？会痛耶！");
                        break;
                }
		break ;
	case "hammer":
	case "hit":
	        command("chat* inn "+ob->query("id"));
		break ;
	case "heihei":
		command("chat "+ob->query("name")+"，你好可怕啊！ ......");
		break ;
        default:
                if( random(10)<5 )
                        command("chat* "+ verb + " " + ob->query("id"));
                else
                        drool();
        }
}

varargs void drool(string msg, string who)
{
        mapping mem;
        string *ob;

        mem = query("memory");
        if( !mapp(mem) ) return;

        if( !msg || !who) {
                ob = keys(mem);
                who = ob[random(sizeof(ob))];
                msg = mem[who][random(sizeof(mem[who]))];
        }

        if( (strsrch(msg, "为什麽") >= 0) ) {
                if( sscanf(msg, "%*s为什麽%s", msg)==2 ) msg = "为什麽" + msg;
                switch(random(8)) {
                case 0: command("chat " + who + "，你是在问我吗？"); 
			break;
                case 1: command("chat 关於" + msg + " ... "); 
			break;
                case 2: command("chat 呃 ... "); drool(); 
			break;
                case 3: command("chat 这个问题嘛 ...."); 
			break;
                case 4: command("chat " + who + "，知道这个问题的答案对你那麽重要吗？"); 
			break;
                case 5: command("chat " + msg + "？"); 
			break;
                case 6: command("chat " + who + "你能不能说清楚一点？"); 
			break;
                case 7: command("chat " + who + "，我不懂你问的问题耶！"); 
			break;
                	}
        }
        else if( (strsrch(msg, "你") >= 0)
        ||      (strsrch(msg, "□") >= 0)
        ||      (strsrch(msg, "drooler") >= 0)
        ||      (strsrch(msg, "Drooler") >= 0)) {
                if( sscanf(msg, "%*s你%s", msg) == 2 ) msg = "你" + msg;
                msg = replace_string(msg, "你", "我");
                msg = replace_string(msg, "□", "我");
                switch(random(10)) {
                case 0: command("chat " + who + "，你是说" + msg + "吗？");      
			break;
                case 1: command("chat 你确定" + msg + "？");     
			break;
                case 2: command("chat " + msg + "跟你有什麽关系？");     
			break;
                case 3: command("chat 嗯 ... " + who + "说得好！"); 
			break;
                case 4: command("chat " + who + "你为什麽对" + msg + "这麽有兴趣？"); 
			break;
                case 5: command("chat 为什麽你认为" + msg + "？"); 
			break;
                case 6: command("chat 换个话题吧"); drool(); 
			break;
                case 7: command("chat 才怪！"); 
			break;
                case 8: command("chat 不一定吧？"); 
			break;
                case 9: command("chat 有这个可能 ...."); 
			break;
                }
        }
        else if( (strsrch(msg, "我") >= 0)) {
                if( sscanf(msg, "%*s我%s", msg) == 2 ) msg = "我" + msg;
                msg = replace_string(msg, "我", "你");
                msg = replace_string(msg, "?", "");
                switch(random(8)) {
                case 0: command("chat 你是说" + msg + "吗？"); break;
                case 1: command("chat 真的？" + msg + "？");     break;
                case 2: command("chat 如果" + msg + "，我能帮你什麽忙吗？");     
			break;
                case 3: /*command("hmm"); */break;
                case 4: command("chat 你认为" + msg + "？"); break;
                case 5: command("chat 我有同感"); break;
                case 6: command("chat 你说的「" + msg + "」我不能苟同"); 
			break;
                case 7: command("chat 有关「" + msg + "」的话题到此为止好吗？"); 
			break;
                }
        } else {
                switch(random(20)) {
                        case 0: command("chat 为什麽说" + msg + "?"); 
				break;
                        case 1: command("chat 「" + msg + "」是什麽意思？"); 
				break;
                        case 2: command("chat " + msg + "？"); break;
//                        case 3: command("grin"); break;
//                        case 4: command("smile"); break;
//                        case 5: command("?"); break;
                        case 6: command("chat ...."); break;
//                        case 7: command("hmm"); break;
                        case 8: command("chat " + rnd_say[random(sizeof(rnd_say))]); break
;
                        case 9: command("chat 你怎麽知道" + msg + "?"); break;
                        case 10: command("chat 刚刚" + who + "不是说了，" + msg); 
				break;
                        case 11: command("chat 我当然知道，" + msg); break;
                        case 12: command("chat 然後呢？"); break;
                        case 13: command("chat 真的吗？"); break;
                        case 14: command("chat 我不这麽认为。"); break;
                        default:
                                break;
                }
        }
}

void reset()
{
        delete("memory");
}


int ask_xueyi()
{
  mapping myfam;
  if(!(myfam = this_player()->query("family"))
     ||myfam["family_name"]!="全真派")
   {
    command("say 你又不是我师兄的徒弟，我为什么要教你?");
    return 1;
    }
   else {
   command("say 左右互搏可是我好不容易研究出来的，可不能随便教给别人!");
   command("say 你要是能给我一件我想要的东西，我还是可以教你的.");                                                
   command("hehe");
   this_player()->set_temp("marks/学艺",1);
   return 1;
    }
}

int accept_object(object ob,object obj)
 {
    ob=this_player();
 //   mapping fam;
 if(obj->query("id")=="feng wang mi")
 {
    if((string)ob->query("family/family_name")=="全真派")
  {   command("say 哇，这就是我想要的蜂王蜜，你从哪里弄来的？");
      command("say 好，我就把我的双手互搏教给你!");
    if(ob->query("int")<20)
    {
      say("你听了老顽童的讲解，学会了左右互搏!\n");
      ob->set("zuoyou-hubo",1);
      return 1;
    }
    else 
 {
     say("老顽童讲了半天，你却不知道他在讲些什么.\n");
     command("chat "+ob->query("name")+",你怎么这么笨啊！");
     return 1;
  }
 }
   else 
  {
    command("say 我可没法报答你啊!");
    return 1;
  }
}
    command("smile");
    command("say 那我就不客气了");
    return 1;
  }

/*void destroying(objece me,object obj)
 {
   destruct(obj);
   return;
 }
*/
