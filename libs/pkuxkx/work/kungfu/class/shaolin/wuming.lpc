 // wuming.c 无名老僧
 // Create by chui
 
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
#include <title.h>

string ask_me();
void consider();
void heal();

void create()
{
        set_name("无名老僧", ({"wuming laoseng","wuming"}));
        set("long",
        "他就是天龙八步中提到的无名老僧. \n"
        "他端坐这那里，口中喃喃的诵读着佛经. \n");
        set("title",RED "少林" NOR + GRN "无名老僧" NOR);
        set("gender", "男性");
        set("age", 60);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);

        set("max_qi", 8000);
        set("max_jing",8000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 150);
        set("combat_exp", 30000000);
        set("score", 500000);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
           (: consider() :)
        }) );
        set("chat_chance", 100);
        set("chat_msg", ({
                (: heal :),
        }));
        set_skill("force", 500);
        set_skill("yijin-jing", 500);
        set_skill("yizhi-chan", 500);
        set_skill("dodge", 500);
        set_skill("shaolin-shenfa", 500);
        set_skill("cuff", 500);
        set_skill("jingang-quan",500);
        set_skill("parry",500);
        set_skill("sword", 500);
        set_skill("wuying-jian", 500);
        set_skill("blade", 500);
        set_skill("ranmu-daofa", 500);
        set_skill("whip", 500);
        set_skill("riyue-bian", 500);
        set_skill("buddhism", 500);
        set_skill("finger", 500);
        set_skill("hunyuan-yiqi", 400);
        set_skill("buddhism", 400);
        set_skill("nianhua-zhi", 500);
        set_skill("literate", 300);

        map_skill("force","yijin-jing");
        map_skill("dodge","shaolin-shenfa");
        map_skill("cuff","jingang-quan");
        map_skill("parry","jingang-quan");
        map_skill("whip","riyue-bian");
        map_skill("blade","ranmu-daofa");
        map_skill("sword","wuying-jian");
        map_skill("finger","yizhi-chan");
        prepare_skill("finger", "yizhi-chan");
        set("inquiry",
        ([
        "易筋经" : (: ask_me :),
        ]));
        set("book_count", 1);
        create_family("少林派",26,"长老");
        set("class", "bonze");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/weapon/changjian");
        carry_object("/d/shaolin/obj/cloth")->wear();
}
string ask_me()
{
        mapping fam;
        object ob;
        if(!(fam=this_player()->query("family")) || fam["family_name"]!="少林派")
                return RANK_D->query_respect(this_player())+"与本派素无往来，不知此话从何说起?";
        if(this_player()->query_skill("force") <1000)
                return RANK_D->query_respect(this_player())+"你的内力修为不够，要了也没用";
        if (query("book_count") <1)
                return "易筋经已被别人取走，你请回吧.";
        add("book_count", -1);
        ob=new("d/shaolin/obj/xisui");
        ob->move(this_player());
        return "好吧，你就拿去吧,一定要好好保管.";
}

void attempt_apprentice(object ob)
{
        int i;
        mapping skills;

        if ((string)ob->query("family/family_name")!="少林派" || (string)ob->query("class")!="bonze") {
                 command("say 少林乃佛门圣地");
                 command("say " + RANK_D->query_respect(ob) + "六根未净，老衲不能收你");
                 return;
        }
        if((int)ob->query("betrayer")>=1){
                 command("say "+RANK_D->query_respect(ob)+"你多次叛师，背信弃义。我怎会收你。\n");
                 return;
        }
        if ((int)ob->query_skill("buddhism", 1) < 250) {
                 command("say 你的禅宗心法太弱，不易修行上乘武功.");
                 command("say " + RANK_D->query_respect(ob) + "还是回去吧");
                 return;
        }
        if ((int)ob->query("shen") < 100000) {
                 command("say 出家人慈悲为怀，德行是很重要的");
                 command("say 德行乃修行之本" + RANK_D->query_respect(ob) + " 德行还欠缺了些，希望你能加强这方面的修行.");
                 return;
        }
        if ((int)ob->query("wuming")<10) {
                 command("say 佛家讲求缘分，贫僧与大师无缘！");
                 return;
        }
        if ( base_name(environment(this_object())) != "/d/shaolin/hantan4"){
                command("say 你使用如此卑劣手段拜师，老衲实在看不过去，今天要为武林除害！");
                ob->start_busy(100);
                command("kill " + ob->query("id"));
                return;
        }
        if (ob->query_int() < 50) {
                command("say 禅宗最重视顿悟");
                command("say " + RANK_D->query_respect(ob) + "悟性不够,不能传我衣钵.");
                return;
        }  

        skills = ob->query_skills();
        for(i=0; i<sizeof(skills); i++){
                //少林排它性设置 by Jpei
                if(load_object(SKILL_D(keys(skills)[i]))->valid_enable("force")
                  && keys(skills)[i] != "hunyuan-yiqi"
                  && keys(skills)[i] != "yijin-jing")
                       command("say 你不先散了别派内功，我怎么收你？！\n");
                       return;
        }
        command("recruit " + ob->query("id"));
        ob->set("title" , RED "少林" NOR + GRN "长老" NOR);
//title系统记录玩家title by seagate@pkuxkx
	      ob->set_title(TITLE_RANK, ob->query("title"));
        ob->set("name" , "渡" + ob->query("name")[2..3]);
        ob->set_face( FACE_FACT, ob->query("name") );
}

void init()
{
        object ob;
        object* inv;
        int i;
        mapping fam;

        ::init();

        ob = this_player();
        if(base_name(environment(this_object())) != "/d/shaolin/hantan4")
        {
                message_vision("无名老僧对$N缓缓念道：这位施主这又何苦呢？\n",ob);
                command("slapfy " + ob->query("id"));
                //destruct(this_object()); // 因为destruct 导致 负重异常： 你身上带著下列这些东西(负重 -45%)
        }
        if ((int)ob->query("shen") < 0 && (string)ob->query("family/master_id") == "wuming laoseng") 
        {
                command("say 你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
        }
/*
        if ((int)ob->query("PKS") > 5 && (string)ob->query("family/master_id") == "wuming laoseng") 
        {
                command("say 你多次杀人越货，胡作非为，我岂能仍是你的师傅。\n");
                command("expell "+ ob->query("id"));
        }
*/
        inv = deep_inventory(ob);
        for (i=sizeof(inv)-1;i>=0;i--)
        {
                if (userp(inv[i]))
                {
                        command("say 你怎敢不听我的教诲擅自带人进入这里！我岂能还是你的师傅！\n");
                        command("expell " + ob->query("id"));
                        tell_object(ob,"你被无名老僧赶了出去。\n");
                        ob->move("/d/shaolin/tianjing");
                }
        }
}               
void consider()
{
        object *enemy,target;
        enemy = query_enemy() - ({ 0 });
        target = enemy[random(sizeof(enemy))];
         switch( random(4) )
        {
            case 0:
            command("perform sword.wuying");
            break;
            case 1: 
            command("perform sword.lidichenfo");
            break;
            case 2: 
            command("unwield jian");
              command("perform finger.jingmo "+target->query("id"));
            command("wield jian");           
            break;
            case 3: 
            command("unwield jian");
            command("enable parry nianhua-zhi");
            command("perform parry.fuxue " +target->query("id"));
            command("wield jian");           
            break;
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

