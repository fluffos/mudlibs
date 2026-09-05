// yang.cg.c
#include <ansi.h>
#include <title.h>
inherit NPC;
//inherit F_MASTER;
inherit F_QUESTMASTER;

#include <no1master.h>
int ask_zd();
string ask_me();
string ask_lieyandao();
void consider();
void heal();
string ask_for_leave();

void create()
{
		set_name("张无忌",({"zhang wuji","zhang"}));
        set("long", "他今年二十多岁。\n");
        set("title",GRN "明教" NOR + YEL "教主" NOR);
        set("gender", "男性");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("per", 50);
        set("str", 50);
        set("int", 35);
        set("con", 50);
        set("dex", 30);
		set("chat_chance", 100);
		set("chat_msg", ({
                (: heal :),
        }));
        set("max_qi", 24000);
        set("max_jing", 22000);
        set("neili", 24000);
        set("max_neili", 24000);
        set("jiali", 400);
        set("combat_exp", 15000000);
        set("score", 400000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: consider() :)
        }) );
		set("inquiry", ([
                "倚天屠龙记" : "听说倚天剑和屠龙刀中藏着大秘密，也许你可以去参详参详。\n",
                "烈焰刀" : (: ask_lieyandao :),
                "ling" : (: ask_me :),
                "圣火令" : (: ask_me :),
                "指点" : (: ask_zd :),
                "脱离教派" : (: ask_for_leave :), 
        ]) );
		set("book_count", 1);
		set("no_teach_skills",({"jiuyang-shengong","taiji-shengong","taiji-jian","taiji-quan","tiyunzong","qishang-quan"}));
		set_skill("force",380);
		set_skill("jiuyang-shengong",380);
        set_skill("guangming-shenghuogong",350);
		set_skill("taiji-shengong",380);
		set_skill("qishang-quan",250);
		set_skill("taiji-jian",300);
		set_skill("sword",300);
		set_skill("cuff",300);
		set_skill("taiji-quan",320);
		set_skill("tiyunzong",250);
		set_skill("dodge",300);
		set_skill("datengnuo-bufa", 300);
		set_skill("hanbing-zhang",300);
		set_skill("shenghuo-lingfa",380);
		set_skill("blade",300);
		set_skill("medical-skill",300);
		set_skill("parry",350);
		set_skill("dagger",300);
		set_skill("lieyan-dao",300);
		set_skill("qiankun-danuoyi", 330);
		set_skill("strike",300);
        map_skill("strike", "hanbing-zhang");
        map_skill("force", "guangming-shenghuogong");
        map_skill("dodge", "tiyunzong");
        map_skill("parry", "qiankun-danuoyi");
        map_skill("dagger", "shenghuo-lingfa");
        map_skill("blade", "lieyan-dao");
		map_skill("cuff", "taiji-quan");
        map_skill("sword", "taiji-jian");
		prepare_skill("cuff", "taiji-quan");
		prepare_wskill("dagger","shenghuo-lingfa");
		prepare_wskill("blade", "lieyan-dao");
		set_temp("apply/armor", 600);
		set_temp("apply/damage", 450);
		reset_action();
        create_family("明教",19,"教主");
        setup();
		setup_no1master();
		carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
		carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/d/mingjiao/obj/changpao")->wear();
}

int ask_zd()
{
    object me=this_player();
    if (!me->query("mingjiaonewbiejobdone"))
    {
        command("say 你对本教贡献不够，多去帮帮杨左使吧。");
        return 1;
    }
    else
    {
        command("say 其实圣火令法和烈焰刀是我教的基础，可惜很多人练到了误区。");
        tell_object(me,"张无忌传授了你圣火令法和烈焰刀的运功方式。\n");
        return 1;
    }
}

void init()
{
	add_action("give_wsquest","quest");
	add_action("do_leave",  "leave");
}
string ask_for_leave()
{
	object me;

	me = this_player();

	if( (string)me->query("family/family_name") != "明教")
		return "你非我明教弟子，脱离教派的事情我作不得主。";

	me->set_temp("pending/leave_mingjiao", 1);
  return "如果" + RANK_D->query_respect(me) + "真想离我明教而去，就请下决心(leave)吧！";
}

int do_leave()
{
	object me = this_player();
	
	if (me->query_temp("pending/leave_mingjiao") != 1)
		return 0;
	message_vision("$N对$n说道：「从此你就不再是我明教门下了，请好自为之！」\n",this_object(), me );
	tell_object(me,HIR "你决定叛出明教门下！\n" NOR);
	me->delete_temp("pending/leave_mingjiao");
  me->expell_family("明教");
	if (me->query("combat_exp") >= 1000)
		me->add("betrayer",1);
	return 1;
}	

void attempt_apprentice(object ob)
{
        if (ob->query("family/family_name")=="明教"&& ob->query("family/enter_time")>1303862399 &&!ob->query("mingjiaonewbiejobdone"))
        {
            command("say 你对本教贡献不够，我暂时不能收你，多去帮帮杨左使吧。");
            return;
        }
        if ((string)ob->query("family/family_name")!="明教")
        {
                command("say 你非我派弟子，我不能收你。");
                return ;
        }
        if((int)ob->query("betrayer")>=1)
        {
command("say "+RANK_D->query_respect(ob)+"你多次判师，背信弃义。我怎会收你。\n")
;
                return;
        }
        if ((int)this_player()->query_int() < 30 )
        {
   command("say 学习本教秘技要有好的悟性，"+RANK_D->query_respect(ob)+"资质不够??");
                return;
        }

        if ((int)ob->query("score")<1500 )
        {

  command("sigh"+ob->query("id"));
             command("say 小兄弟还是回去吧.我是不会收一个对本教不忠之人的\n");
             return;
       }
        if ((int)ob->query_skill("guangming-shenghuogong", 1) < 100) {
                command("say 你的内功心法修为不够。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在光明圣火功上多下点功夫？");
                return;
        }
        command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
        command("recruit "+ob->query("id"));
        ob->set("title", GRN "明教" NOR + YEL "圣使" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
}

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(6) )
        {
            case 0:
            command("perform dagger.duo " + target->query("id"));
             break;
            case 1:
            command("perform dodge.zong " +target->query("id"));
             break;
             case 2:
            command("perform parry.xunxia " +target->query("id"));
             break;
			 case 3:
            command("perform dagger.shenghuo " + target->query("id"));
             break;
			 case 4:
            command("perform dagger.yinfeng " + target->query("id"));
             break;
			 case 5:
            command("exert powerup");
             break;
             }
}
string ask_me()
{
        mapping fam;
        object ob;
            if (!(fam = this_player()->query("family"))
            || fam["family_name"] != "明教")
                return RANK_D->query_respect(this_player()) +
                "与本派素无来往，不知此话从何谈起？";
        if((string)this_player()->query("family/master_id") != "zhang wuji")
        return "你的身份太底，圣火令乃本教镇教之宝，不能给你。";
        if (query("book_count") < 1)
                return "你来晚了，本教的圣火令不在此处。";
        add("book_count", -1);
        ob = new("/d/mingjiao/obj/shenghuo-ling");
        ob->move(this_player());
        return "好吧，这个圣火令你拿回去好好保管。";
}
void heal()
{
        object ob=this_object();
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("enforce 50");
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
string ask_lieyandao() //iszt@pkuxkx, 2007-01-26, jinwu-dao转为lieyan-dao
{
        object me = this_player();
        int jinwu = me->query_skill("jinwu-dao", 1);

        if(me->query("mingjiao/jinwu"))
                return "不是传授给你了么？";
        if(!jinwu)
                return "烈焰刀是本门绝技，必须有金乌刀法作为根底。";
        me->set_skill("lieyan-dao", jinwu);
        me->set("mingjiao/jinwu", jinwu);
        me->delete_skill("jinwu-dao");
        return "好吧，我就传给你本门绝技「烈焰刀」。";
}

#include "/kungfu/class/masterdie.h"