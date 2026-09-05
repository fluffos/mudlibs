//Xiakedao NPC
//modified by aiai on 6/3/1999

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();
string ask_me();
void heal();
int ask_skill();

void create()
{
        set_name("龙亦凡", ({"long yifan", "long", "yifan"}));
        set("nickname", RED"不败神龙"NOR);
        set("title",GRN "侠客岛" NOR + YEL "岛主" NOR);
        set("gender", "男性");
        set("age", 120);
        set("long", 
                "这难道就是传说中的侠客岛岛主龙亦凡吗？\n他看上去跟一般的中年人无异，可是他已有百岁高龄。\n");
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 80);
        set("int", 80);
        set("con", 80);
        set("dex", 80);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("chat_chance", 10);
        set("chat_msg", ({
                (: heal :),
        }));

       
        set("max_qi", 10000);
        set("max_jing",10000);
        set("neili", 10000);
        set("max_neili", 10000);
        set("jiali", 400);
        
        set("combat_exp", 5000000);
        set("score", 500000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                  (: consider() :)
        }) );
        
        set("inquiry", ([
                "" : (: ask_me :),
        ]) );
        
        set_skill("force", 500);
        set_skill("strike", 500);
        set_skill("xiake-strike", 500);
        set_skill("dodge", 500);
        set_skill("xiake-shenfa", 500);
        set_skill("literate", 500);
        set_skill("xiake-shengong",500);
        set_skill("literate", 500);
        set_skill("xiake-jianfa",500);
        set_skill("sword",500);
        set_skill("xiake-daofa",500);
        set_skill("blade",500);
        set_skill("throwing",500);
        map_skill("strike", "xiake-strike");
        map_skill("dodge", "xiake-shenfa");
        map_skill("force","xiake-shengong");
        map_skill("sword","xiake-jianfa");
        map_skill("blade","xiake-daofa");
        map_skill("parry","xiake-jianfa");
        prepare_skill("strike", "xiake-strike");

        create_family("侠客岛",1,"岛主");
	 set("inquiry",([
		"自创武功" : (: ask_skill :),
	 ]));        
        setup();
        carry_object("/d/xiakedao/npc/obj/xguang")->wield();
        carry_object("/d/xiakedao/npc/obj/xgjia")->wear();
//      carry_object("")->wear();
}

void attempt_apprentice(object ob)
{
        string *callname;
        callname = RANK_D->query_respect(ob);
        if ( ob->query("family") )
        {
                command("say 我龙亦凡有生之年不会再收徒弟了,但这个岛上有一处秘密所在可供修炼,"+RANK_D->query_respect(ob)+"可以自行方便。\n");
                return ;
        }
        if ( ! ob->query("menpai") )
        {
                command("say 以你现在的武功我还不能收你为徒。我只收那些能够自成门派的玩家。年轻人，你要多多努力呀！\n");
                return;
        }
        
        if((int)ob->query("betrayer")>=1)
        {
                command("say "+RANK_D->query_respect(ob)+"你多次判师，背信弃义。我怎会收你。\n");
                return;
        }
/*        if ((int)this_player()->query_int() < 30 )
        {
                command("say 学习本教秘技要有好的悟性，"+RANK_D->query_respect(ob)+"资质不够??);
                return;
        }
*/
       if ( ob->query_skill("xiake-shengong",1) < 150 || ob->query_skill("xiake-jianfa",1) < 150 || ob->query_skill("xiake-strike",1 ) < 150 )  
        command("say 好吧，"+RANK_D->query_respect(ob)+"！我就收下你了！\n");
        command("recruit "+ob->query("id"));
        ob->set("title", GRN "侠客岛" NOR + YEL "使者" NOR);
}       

void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
        switch( random(2) )
        {
            case 0:
                command("perform  " + target->query("id"));
                break;
            case 1:
                command("perform  " + target->query("id"));
                break;
             }
}

void heal()
{
        object ob=this_object();
        if (ob->query("eff_qi") < ob->query("max_qi"))
        {
                command("exert heal");
                command("enforce 400");
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
int ask_skill()
{
	object me = this_player();
	if ( ! me->query("xkdling")) 
	{
		command("ah");
		command("say 你是怎么混上侠客岛的。");
		command("pk " + me->query("id"));
		this_object()->kill_ob(me);
		return 1;
	}
	else if(me->query("createskill/long"))
	{
		command("say 你去找石破天拿闭关室的钥匙吧。");
		return 1;
	}
	else if(me->query("combat_exp") < 10000000)
	{
		command("say 你的经验不够，还无法自行领悟高深的武功，还是请回吧。");
		return 1;
	}
	else if(me->query("repute") < 100000)
	{
		command("say 你的武林声望不够，即使自创了武功也无人信服，还是请回吧。");
		return 1;
	}
	else
	{
	command("say 武林人士到我侠客岛，一般都在闭关室思考武功的秘诀。");
	command("say 贵客若真想钻研高深的武功，可以一试。");
	command("say 闭关室的钥匙我交给石破天保管了。");
	me->set("createskill/long",1);
	return 1;
	}
}
        
