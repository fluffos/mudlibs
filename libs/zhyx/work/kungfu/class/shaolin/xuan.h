// xuan.h for fight and get letter from Xuan

#include "shaolin.h"

int accept_object(object ob, object obj)
{
        object me = this_object();

#if IS_XUAN_CI
        int r;

        if (r = ::accept_object(ob, obj))
                return r;
#endif

        if (obj->query("id") == "tuijian xin4" &&
            ob->query_temp("have_letter"))
        {
                ob->set_temp("apprentice_ok",1);
                command("say 好，" + ob->query("name") +
                        "，你愿意拜我为师吗？");
                destruct(obj);
                return 1;
        }

        command("smile");
        command("say 这东西给我可没有什麽用。");
        command("give " + obj->query("id") + " to " + me->query("id"));
        return 0;
}

void attempt_apprentice(object ob)
{
        object me  = this_object();
        mapping ob_fam;
        mapping my_fam  = me->query("family");

        string name, new_name;

        if (! permit_recruit(ob))
                return;

        if (! (ob_fam = ob->query("family")) ||
            ob_fam["family_name"] != "少林派")
        {
                command("say " + RANK_D->query_respect(ob) +
                        "与本派素无来往，不知此话从何谈起？");
                return;
        }

        if ((string)ob->query("class") != "bonze" &&
            ob_fam["family_name"] == "少林派") 
        {
                command("say " + RANK_D->query_respect(ob) +
                        "是俗家弟子，不能在寺内学艺。");
                return;
        }

        if (ob_fam["generation"] <= my_fam["generation"])
        {
                command("say " + RANK_D->query_respect(ob) +
                        "，贫僧哪里敢当 !");
                return;
        }

        if (ob_fam["generation"] == (my_fam["generation"] + 1))
        {
                command("say " + ob_fam["master_name"] +
                        "的徒弟怎麽跑到我这儿来了，哈哈哈 !");
                command("recruit " + ob->query("id"));
        }

        if (ob_fam["generation"] == (my_fam["generation"] + 2))
        {
                if (ob->query_temp("apprentice_ok") ||
                    ob->query("luohan_winner"))
                {
                        ob->delete_temp("have_letter");
                        ob->delete_temp("apprentice_ok");
        
                        command("say 是" + ob_fam["master_name"] +
                                "叫你来找我的吧，哈哈哈！");
                        command("say 贫僧又得一可塑之才，真是可喜可贺！");

                        name = ob->query("name");
                        new_name = "澄" + name[2..3];
                        ob->set("name", new_name);

                        command("say 从今以后你的法名叫做" + new_name +
                                "，恭喜你荣升为少林派澄字辈弟子！");
                        command("recruit " + ob->query("id"));
                } else
                {
                        command("say " + RANK_D->query_respect(ob) +
                                "，你即没有推荐信，也没有过罗汉阵，"
                                "不能越级拜师。");
                        return;
                }
        }

        return;
}

int accept_ask(object me, string topic)  
{
        switch (topic)  
        {        
        
        case "历练" :
        case "历炼" :
        case "锻炼" :
                return QUEST_D->accept_ask(this_object(), me, topic);
                break;
        case "缠绕诀" :  
                return MASTER_D->teach_pfm(me, this_object(),  
                        ([ "perform" : "can_perform/dacheng-fosuo/chanrao",  
                           "name"    : "缠绕诀",  
                           "sk1"     : "dacheng-fosuo",  
                           "lv1"     : 80,  
                           "force"   : 100,  
                           "neili"   : 500,  
                           "gongxian": 100,  
                           "shen"    : 2000, ]));  
                break;  
        
        case "红霞贯日" :  
                return MASTER_D->teach_pfm(me, this_object(),  
                        ([ "perform" : "can_perform/yecha-gun/hongxia",  
                           "name"    : "红霞贯日",  
                           "sk1"     : "yecha-gun",  
                           "lv1"     : 120,  
                           "force"   : 150,  
                           "neili"   : 1000,  
                           "gongxian": 300,  
                           "shen"    : 5000, ]));  
                break;  
         
         case "即世即空" :  
                return MASTER_D->teach_pfm(me, this_object(),  
                        ([ "perform" : "can_perform/weituo-chu/jishi",  
                           "name"    : "即世即空",  
                           "sk1"     : "weituo-chu",  
                           "lv1"     : 120,  
                           "force"   : 180,  
                           "neili"   : 500,  
                           "gongxian": 300,  
                           "shen"    : 5000, ]));  
                break;  
         
         case "金龙疾空" :  
                return MASTER_D->teach_pfm(me, this_object(),  
                        ([ "perform" : "can_perform/longxing-jian/kong",  
                           "name"    : "金龙疾空",  
                           "sk1"     : "longxing-jian",  
                           "lv1"     : 160,  
                           "force"   : 250,  
                           "neili"   : 1500,  
                           "gongxian": 500,  
                           "shen"    : 10000, ]));  
                break;  
         
         case "凌空指穴" :  
                return MASTER_D->teach_pfm(me, this_object(),  
                        ([ "perform" : "can_perform/qufannao-zhi/lingkong",  
                           "name"    : "凌空指穴",  
                           "sk1"     : "qufannao-zhi",  
                           "lv1"     : 100,  
                           "force"   : 150,  
                           "neili"   : 1500,  
                           "gongxian": 500,  
                           "shen"    : 20000, ]));  
                break;  
         
         case "擒龙打" :  
                return MASTER_D->teach_pfm(me, this_object(),  
                        ([ "perform" : "can_perform/qinlong-shou/qin",  
                           "name"    : "擒龙打",  
                           "sk1"     : "qinlong-shou",  
                           "lv1"     : 100,  
                           "force"   : 120,  
                           "neili"   : 1000,  
                           "gongxian": 200,  
                           "shen"    : 20000, ]));  
                break;  
         
         case "如影随形" :  
                return MASTER_D->teach_pfm(me, this_object(),  
                        ([ "perform" : "can_perform/ruying-suixingtui/ruying",  
                           "name"    : "如影随形",  
                           "sk1"     : "ruying-suixingtui",  
                           "lv1"     : 160,  
                           "force"   : 250,  
                           "neili"   : 2000,  
                           "gongxian": 500,  
                           "shen"    : 50000, ]));  
                break;  
         case "一指点三脉" :  
                return MASTER_D->teach_pfm(me, this_object(),  
                        ([ "perform" : "can_perform/jingang-zhi/san",  
                           "name"    : "一指点三脉",  
                           "sk1"     : "jingang-zhi",  
                           "lv1"     : 200,  
                           "force"   : 300,  
                           "neili"   : 3000,  
                           "gongxian": 800,  
                           "shen"    : 50000, ]));  
                break;  
         
        case "碎石破玉" :  
                return MASTER_D->teach_pfm(me, this_object(),  
                        ([ "perform" : "can_perform/woshi-zhang/po",  
                           "name"    : "碎石破玉",  
                           "sk1"     : "woshi-zhang",  
                           "lv1"     : 120,  
                           "force"   : 140,  
                           "neili"   : 1000,  
                           "gongxian": 200,  
                           "shen"    : 20000, ]));  
                break;  
         
         case "罗汉降魔" :  
                return MASTER_D->teach_pfm(me, this_object(),  
                        ([ "perform" : "can_perform/luohan-gun/xiangmo",  
                           "name"    : "罗汉降魔",  
                           "sk1"     : "luohan-gun",  
                           "lv1"     : 80,  
                           "force"   : 100,  
                           "neili"   : 500,  
                           "gongxian": 100,  
                           "shen"    : 2000, ]));  
                break;  
         
         case "赤血爪" :  
                return MASTER_D->teach_pfm(me, this_object(),  
                        ([ "perform" : "can_perform/yingtuo-luozhua/xue",  
                           "name"    : "赤血爪",  
                           "sk1"     : "yingtuo-luozhua",  
                           "lv1"     : 200,  
                           "force"   : 300,  
                           "neili"   : 3000,  
                           "gongxian": 1000,  
                           "shen"    : 50000, ]));  
                break;  
         
         case "六合连环" :  
                return MASTER_D->teach_pfm(me, this_object(),  
                        ([ "perform" : "can_perform/liuhe-bian/lianhuan",  
                           "name"    : "六合连环",  
                           "sk1"     : "liuhe-bian",  
                           "lv1"     : 180, 
                           "sk2"     : "dodge",  
                           "lv2"     : 180,
                           "force"   : 270,  
                           "neili"   : 3000,  
                           "gongxian": 500,  
                           "shen"    : 50000, ]));  
                break;  
         
         case "慈悲字诀" :  
                return MASTER_D->teach_pfm(me, this_object(),  
                        ([ "perform" : "can_perform/leiming-bian/cibei",  
                           "name"    : "慈悲字诀",  
                           "sk1"     : "leiming-bian",  
                           "lv1"     : 160,
                           "sk2"     : "buddhism",  
                           "lv2"     : 150,  
                           "force"   : 250,  
                           "neili"   : 2000,  
                           "gongxian": 1000,  
                           "shen"    : 200000, ]));  
                break;  
                            
        default:  
                return 0;  
        }
}

