// miejue.c 灭绝师太
// Modified by That Oct.1997
#include <command.h>
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_job();
string ask_for_quit();
mixed out_master(mixed arg);
int ask_zhou();
int ask_guo();
int ask_dragon();
int ask_jiuyin();

mapping *quest = ({
      (["place":                "大理北门",
       "start" :              "/d/dali/northgate",]),
      (["place":                "扬州密林",
       "start" :              "/d/city/jiaowai5",]),
     (["place":                "峨嵋草棚",
       "start" :              "/d/emei/caopeng",]),
     (["place":                "扬州西门",
       "start" :              "/d/city/ximen",]),
     (["place":                "雪山土路",
       "start" :              "/d/xueshan/tulu2",]),
     (["place":                "苏州留园",
       "start" :              "/d/suzhou/liuyuan",]),
     (["place":                "苏州寒山寺",
       "start" :              "/d/suzhou/hanshansi",]),
     (["place":                "杭州飞来峰",
       "start" :              "/d/hangzhou/feilaifeng",]),
     (["place":                "杭州净慈寺",
       "start" :              "/d/hangzhou/jingcisi",]),
     (["place":                "杭州翠微亭",
       "start" :              "/d/hangzhou/cuiweiting",]),
     (["place":                "杭州聚景园",
       "start" :              "/d/hangzhou/jujingyuan",]),
     (["place":                "苗疆易溪部",
       "start" :              "/d/dali/yixibu",]),
      (["place":                "扬州中央广场",
       "start" :              "/d/city/guangchang",]),
      (["place":                "杭州沿湖大道",
       "start" :              "/d/hangzhou/dadao1",]),
      (["place":                "杭州断桥",
       "start" :              "/d/hangzhou/duanqiao",]),
      (["place":                "杭州灵隐寺",
       "start" :              "/d/hangzhou/lingyinsi",]),
      (["place":                "星宿海伊犁",
       "start" :              "/d/xingxiu/beijiang",]),
      (["place":                "武当三天门",
       "start" :              "/d/wudang/santiangate",]),
      (["place":                "峨嵋十二盘",
       "start" :              "/d/emei/shierpan3",]),
      (["place":                "峨嵋千佛庵",
       "start" :              "/d/emei/qianfoan",]),
      (["place":                "峨嵋九十九道拐",
       "start" :              "/d/emei/jsjdg1",]),
      (["place":                "明教厚土旗门",
       "start" :              "/d/mingjiao/htqmen",]),
      (["place":                "明教烈火旗后门",
       "start" :              "/d/mingjiao/lhqhoumen",]),
      (["place":                "福州东门",
       "start" :              "/d/fuzhou/dongmen",]),
      (["place":                "福州北大街",
       "start" :              "/d/fuzhou/beidajie",]),
      (["place":                "星宿海沙漠",
       "start" :              "/d/xingxiu/shamo2",]),
      (["place":                "少林寺石阶",
       "start" :              "/d/shaolin/shijie4",]),
      (["place":                "襄阳石阶",
       "start" :              "/d/xiangyang/walle1",]),
      (["place":                "华山猢狲愁",
       "start" :              "/d/huashan/husun",]),
      (["place":                "华山玉女峰",
       "start" :              "/d/huashan/yunu",]),
      (["place":                "慕容小径",
       "start" :              "/d/mr/xiaojing1-2",]),
      (["place":                "慕容柳树林",
       "start" :              "/d/mr/liulin",]),
      (["place":                "大理大和街",
       "start" :              "/d/dali/dahejiewest",]),
      (["place":                "苏州城北门",
       "start" :              "/d/suzhou/beimen",]),
      (["place":                "苏州城玄妙观",
       "start" :              "/d/suzhou/xuanmiao",]),
      (["place":                "少林寺山门殿",
       "start" :              "/d/shaolin/smdian",]),
      (["place":                "少林寺走廊",
       "start" :              "/d/shaolin/zoulang7",]),
      (["place":                "武当山路",
       "start" :              "/d/wudang/shanlu3",]),
      (["place":                "少林寺般若堂九部",
       "start" :              "/d/shaolin/banruo9",]),
      (["place":                "雪山山脚",
       "start" :              "/d/xueshan/shanjiao",]),
      (["place":                "峨嵋九老洞",
       "start" :              "/d/emei/jiulaodong",]),
       (["place":                "峨嵋古德林",
       "start" :              "/d/emei/gudelin1",]),
       (["place":                "函古关",
       "start" :              "/d/city4/hanguguan",]),
       (["place":                "终南山口",
       "start" :              "/d/city4/zhongnan",]),
       (["place":                "闽江",
       "start" :              "/d/fuzhou/fzroad8",]),
       (["place":                "汉水南岸",
       "start" :              "/d/shaolin/hanshui1",]),
       (["place":                "中条山密林",
       "start" :              "/d/huashan/jzroad5",]),
       (["place":                "天山脚下",
       "start" :              "/d/xingxiu/shanjiao",]),
       (["place":                "华山脚下",
       "start" :              "/d/huashan/path1",]),
       (["place":                "平定州",
       "start" :              "/d/heimuya/pingdingzhou",]),
       (["place":                "乱石坡",
       "start" :              "/d/heimuya/road1",]),
       (["place":                "华山村南村口",
       "start":                "/d/village/sexit",]),
       (["place":                "闽赣古道",
       "start":                "/d/fuzhou/fzroad7",]),
       (["place":                "玉皇顶",
       "start":               "/d/taishan/yuhuang",]),
       (["place":                "六盘山",
       "start":                "/d/xingxiu/xxroad3",]),
       (["place":                "天山山路",
       "start":                "/d/xingxiu/tianroad1",]),
       (["place":                "嘉峪关",
       "start":                "/d/xingxiu/jiayuguan",]),
       (["place":                "西单北大街",
       "start":                "/d/beijing/xidan1",]),
       (["place":                "巴陵广场",
       "start":                "/d/baling/guangchang",]),
       (["place":                "王府井大街",
       "start":                "/d/beijing/wangfu2",]),
       (["place":                "全真教碑",
       "start":                "/d/quanzhen/jiaobei",]),
       (["place":                "老妪岩",
       "start":                "/d/gumu/juyan",]),
       (["place":                "老龙头",
       "start":                "/d/guanwai/laolongtou",]),
       (["place":                "嘉兴城",
       "start":                "/d/quanzhou/jiaxing",]),
       (["place":                "扬州西门",
       "start":                "/d/city/ximen",]),
       (["place":                "仙霞岭",
       "start":                "/d/fuzhou/fzroad1",]),
       (["place":                "宁远",
       "start":                "/d/taishan/yitian",]),
       (["place":                "小土屋",
       "start":                "/d/guanwai/tuwu",]),
       (["place":                "下关城",
       "start":                "/d/dali/xiaguan",]),
       (["place":                "李子箐石林",
        "start":                "/d/dali/shilin1",]),
        (["place":                "大叠水瀑布",
        "start":                "/d/dali/dadieshui",]),
        (["place":                "罗伽甸",
        "start":                "/d/dali/luojiadian",]),
        (["place":                "阳宗镇",
        "start":                "/d/dali/yangzong",]),
        (["place":                "太室阙",
        "start":                "/d/songshan/taishique",]),
        (["place":                "少林石阶",
        "start":                "/d/shaolin/shijie7",]),
        (["place":                "铁梁峡",
        "start":                "/d/songshan/tieliang",]),
        (["place":                "峻极禅院山门",
        "start":                "/d/songshan/junjigate",]),
        (["place":                "神禾原",
        "start":                "/d/gumu/shenheyuan",]),
        (["place":                "终南山大校场",
        "start":                "/d/gumu/daxiaochang",]),
        (["place":                "金锁关",
        "start":                "/d/huashan/jinsuo",]),
        (["place":                "平心石",
        "start":                "/d/huashan/pingxinshi",]),
        (["place":                "千尺幢",
        "start":                "/d/huashan/qianchi",]),
        (["place":                "山洪瀑布",
        "start":                "/d/huashan/shanhongpb",]),
        (["place":                "清音阁",
        "start":                "/d/emei/qingyinge",]),
        (["place":                "十二盘",
        "start":                "/d/emei/shierpan1",]),
        (["place":                "九老洞口",
        "start":                "/d/emei/jldongkou",]),
        (["place":                "九十九道拐",
        "start":                "/d/emei/jsjdg2",]),
        (["place":                "千佛庵",
        "start":                "/d/emei/qianfoan",]),
        (["place":                "终南山空地",
        "start":                "/d/gumu/kongdi",]),
        (["place":                "终南山主峰",
        "start":                "/d/gumu/zhufeng",]),
        (["place":                "悬天崖",
        "start":                "/d/mingjiao/shanlu3",]),
         (["place":                "烈火旗大门",
        "start":                "/d/mingjiao/lhqmen",]),
        (["place":                "雪山寺山门",
        "start":                "/d/xueshan/shanmen",]),
        (["place":                "洪水旗大门",
        "start":                "/d/mingjiao/hsqmen",]),
        (["place":                "洪水旗大门",
        "start":                "/d/mingjiao/hsqmen",]),
        (["place":                "北大街",
        "start":                "/d/mingjiao/hsqmen",]),
        (["place":                "青石大道",
        "start":                "/d/wudang/wdroad1",]),
        (["place":                "关洛道",
        "start":                "/d/city4/road1",]),
        (["place":                "大驿道",
        "start":                "/d/taishan/yidao",]),
        (["place":                "官道",
        "start":                "/d/quanzhen/guandao2",]),
        (["place":                "东街",
        "start":                "/d/quanzhen/dongjie",]),
        (["place":                "富家大门",
        "start":                "/d/quanzhen/fu-damen",]),
        (["place":                "山路",
        "start":                "/d/quanzhen/shanlu1",]),
        (["place":                "小村庄",
        "start":                "/d/quanzhen/xiaocun",]),
        (["place":                "星宿海",
        "start":                "/d/xingxiu/xxh2",]),
        (["place":                "天山脚下",
        "start":                "/d/xingxiu/shanjiao",]),
        (["place":                "丝绸之路",
        "start":                "/d/xingxiu/silk2",]),
        (["place":                "长安城西门",
        "start":                "/d/city4/westgate",]),
        (["place":                "长安城东门",
        "start":                "/d/city4/eastgate",]),
        (["place":                "城东门",
        "start":                "/d/city4/eastgate",]),
        (["place":                "上天梯",
        "start":                "/d/huashan/shangtianti",]),
        (["place":                "树林",
        "start":                "/d/xiaoyao/shulin3",]),
        (["place":                "南大街",
        "start":                "/d/xiaoyao/shulin3",]),});

string ask_for_quit();
mixed out_master(mixed arg);

void create()
{
        set_name("灭绝师太", ({ "miejue shitai","miejue","shitai"}));
        set("long",
                "她是峨嵋派的第三代弟子，现任峨嵋派掌门人。\n");
        set("gender", "女性");
        set("age", 62);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("shen", 100000);
        set("class", "bonze");
set_temp("huifeng/jue",1);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mie" :),
                (: perform_action, "sword.sanqing" :),
                	(: perform_action, "sword.jue" :),
                	(: perform_action, "sword.liaoyuan" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "strike.puzhao" :),
                (: perform_action, "strike.puzhao" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),
                (: exert_function, "juemie" :),
        }) );
        set("inquiry",([
                "剃度"  : "贫尼只知除妖杀魔，不剃度弟子。",
                "出家"  : "贫尼只知除妖杀魔，不剃度弟子。",
                "还俗"  :  (: ask_for_quit :),
		"周芷若" : (: ask_zhou :),
		"郭靖" : (: ask_guo :),
		"黄蓉" : (: ask_guo :),
		"倚天屠龙" : (: ask_dragon :),
		"武林至尊" : (: ask_dragon :),
		"九阴速成篇" : (: ask_jiuyin :),
                "除妖" : (: ask_job :),
                "杀魔" : (: ask_job :),
                "job" : (: ask_job :),
        ]));

        set("str", 50);
        set("int", 55);
        set("con", 55);
        set("dex", 55);
        set("per", 20);

        set("max_qi", 28000);
        set("max_jing", 28000);
        set("neili", 38000);
        set("max_neili", 38000);
        set("jingli", 11500);
        set("max_jingli", 11500);

        set("combat_exp", 8500000);
        set("score", 1000);
        set_skill("persuading", 500);
        set_skill("throwing", 250);
        set_skill("force", 300);
        set_skill("dodge", 250);
        set_skill("finger", 250);
        set_skill("parry", 250);
        set_skill("strike", 250);
        set_skill("sword", 280);
        set_skill("blade", 280);
        set_skill("literate", 260);
        set_skill("mahayana", 500);
        set_skill("buddhism", 500);
        set_skill("jinding-zhang", 380);
        set_skill("tiangang-zhi", 380);
        set_skill("huifeng-jian", 380);
        set_skill("yanxing-dao", 380);
        set_skill("zhutian-bu", 380);
        set_skill("linji-zhuang", 380);
        set_skill("bagua-dao", 380);
        set_skill("bagua-zhang", 380);

        set_skill("huixin-strike", 380);
        set_skill("piaoxue-hand", 380);
        set_skill("yinlong-whip", 380);
        set_skill("yitian-jian", 380);
        set_skill("whip", 220);
        set_skill("hand", 220);
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("blade","yanxing-dao");
        map_skill("parry","huifeng-jian");


if (random(2)==0)
{
set("isyt",1);
	        map_skill("hand","piaoxue-hand");
        map_skill("strike","huixin-strike");
        map_skill("parry","yitian-jian");
        map_skill("sword","yitian-jian");
        prepare_skill("strike", "huixin-strike");
        prepare_skill("hand", "piaoxue-hand");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fumo" :),
                (: perform_action, "sword.yitian" :),
                (: perform_action, "strike.cuixin" :),
                (: perform_action, "strike.gu" :),
                (: perform_action, "hand.yun" :),
                (: perform_action, "hand.zhao" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),
                (: exert_function, "juemie" :),
        }) );
}
else
{
        prepare_skill("strike", "jinding-zhang");
        prepare_skill("finger", "tiangang-zhi");
}
//        map_skill("magic","bashi-shentong");
        create_family("峨嵋派", 3, "掌门人");
	set_temp("apply/attack",190);
	set_temp("apply/defense",190);
	set_temp("apply/armor",900);
	set_temp("apply/damage",900);
        setup();

if (random(3)==0 && query("isyt")==1) carry_object("/clone/box/baowu/57")->wield();
else         carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/city/obj/cloth.c")->wear();
}


void attempt_apprentice(object ob)
{
   mapping ob_fam;
   mapping my_fam  = ob->query("family");

   string name, new_name;
   name = ob->query("name");

   if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "峨嵋派")
   {
      command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
      return;
   }
   switch (random(2))
   {
        case 1: break;
        default:
           if ((string)ob->query("class")!="bonze" )
           {
               command ("say 阿弥陀佛！贫尼不收俗家弟子。");
               return;
           }
           else
           {
               command ("say 阿弥陀佛！贫尼不收弟子。");
               return;
           }
   }
   if ((int)ob->query_skill("mahayana",1)<90||(int)ob->query_skill("linji-zhuang",1)<90)
   {
      command("say 你本门的功夫修为还太低。");
      return;
   }
   if ((int)ob->query("shen") < 50000)
   {
      command("say " + RANK_D->query_respect(ob) + "你行侠仗义之事还做的不够。");
      return;
   }
   if ((string)ob->query("class")=="bonze" )
   {
        name = ob->query("name");
        new_name = "静" + name[2..3];
        ob->set("name", new_name);
        command("say 从今以后你的法名叫做" + new_name + "，恭喜你成为峨嵋第四代弟子!");
   }

   command("say 阿弥陀佛，善哉！善哉！好吧，我就收下你了。");
   command("say 希望你能以慈悲之心，以智慧之力，努力行善，济度众生。");
   command("recruit " + ob->query("id"));
}

string ask_for_quit()
{
    object me;
    mapping myfam;
    me = this_player();

    myfam = (mapping)me->query("family");
    if (!myfam || (myfam["family_name"] != "峨嵋派"))
        return ("你和峨嵋没有渊源，贫尼不敢给你还俗。\n");
    if( (string)me->query("class")!="bonze" )
        return "阿弥陀佛！出家人不打诳语。你已经是俗家人了。\n";
    me->set_temp("pending/quit_bonze", 1);
        command ("say 阿弥陀佛！善哉！善哉！你一心要还俗，我也不挽留。\n");
        command ("say 我将废去你部分武功。请跪下(kneel)听宣。\n");
        return "如果不愿还俗的，就安心在此修炼吧。\n";
}

int do_kneel()
{
    object me,ob;
    mapping myfam;
    ob = this_object();
    me = this_player();
    myfam = (mapping)me->query("family");
    if (!myfam || (myfam["family_name"] != "峨嵋派"))
{
        command ("say 你和峨嵋没有渊源，贫尼不敢给你还俗。\n");
return 1;
}
    if( (string)me->query("class")!="bonze" )
{
        command ("say 阿弥陀佛！出家人不打诳语。你已经是俗家人了。\n");
return 1;
}
    if (!me->query_temp("pending/quit_bonze"))
{
        command ("say 阿弥陀佛，你想做什么啊？\n");
return 1;
}
command ("say 好，接下来，我将废去，你本门的武功。\n");
if (me->query_skill("linji-zhuang")>1)
{
me->delete_skill("linji-zhuang");
me->map_skill("force");
me->prepare_skill("force");
me->reset_action();
me->set("class","emei");
me->delete_temp("pending/quit_bonze");
}
message_vision(RED"\n$N在$n的身上点了几下,$n混身的力量，一下子全没了！。\n"NOR, ob, me);
command ("say 从现在开始，你就不是出家人了！。\n");
return 1;
}

int accept_object(object me, object obj)
{
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("你没有这件东西。");
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say 你拿个快死的人来骗贫尼？");
       return 0;
       }
   if(me->query_temp("emjob2") <2){
       command("consider "+(string)me->query("id"));
       command("say 你任务怎么做的，杀了几个敌人？");
       return 0;
       }
   if(obj->query("id") == "mingjiao ling" && obj->query("owner") == me->query("id")){
       command("nod "+(string)me->query("id"));
       command("say 干得好！\n");
       message_vision(HIY"$N将$n"HIY"叫起来。\n"NOR,ob, obj);
       remove_call_out("destroying");
       call_out("destroying", 0, obj, ob, me);
       return 1;
       }
   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say 贫尼我要钱干什么?");
       return 0;
       }
//   if(obj->query("owner") != me->query("id")){
//       command("hehe "+(string)me->query("id"));
//       command("say 不错啊，但这活可不是你干的。");
//       /return 1;
//       }
//   else return 0;
}
void destroying(object obj, object ob, object me)
{
   object n_money;
   int exp,pot;
   if(obj) destruct(obj);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say 咦，人呢？");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N对$n说道：你这次做得极为出色！贫尼就指点你两手功夫吧.\n"NOR,ob, me);
   me->set_temp("robjob_exp", 380+(me->query_temp("biaoshi")*(random(30)+60)));
   me->add("combat_exp", me->query_temp("robjob_exp"));
   me->add("potential", 360+me->query_temp("biaoshi")*60);
  me->add("shen",100);
  me->add("score",10);
   tell_object(me, "你被奖励了"+chinese_number(me->query_temp("robjob_exp"))+"点修为值！\n"+chinese_number(200+me->query_temp("biaoshi")*60)+"点潜能\n");
   tell_object(me, "你的侠义正气变强了，你了江湖阅历变强了。\n");
	//destruct(present("mingjiao ling",ob));

me->delete_temp("emjob2");
   me->delete_temp("xx_rob");
   ob->delete_temp("job_asked");
   me->delete_temp("robjob_exp");
   me->delete_temp("biaoshi");
   return;
}
string ask_job()
{
  object me, ob,obn;
  mapping aquest;
  int exp, j;
  aquest = quest[random(sizeof(quest))];
  me = this_player();
  ob = this_object();
  exp = me->query("combat_exp");

    if(ob->query_temp("job_asked") == me->query("id"))
            return "不是叫你先去那里等我吗？怎么还在这里？";
    if( me->query("family/family_name") != "峨嵋派")
            return "你是哪里来的奸细？";
      if( (int)me->query_skill("linji-zhuang",1) < 50)
            return "贫尼认为你的本门内功太差了。";

    if(me->query_condition("emeijob"))
            return "贫尼现在还没有得到任何消息，你等会儿再来吧。";


    if(exp>=600000) j=5;
    else if(exp>=500000) j=4;
    else if(exp>=400000) j=3;
    else if(exp>=300000) j=2;
    else j=3;

    me->set_temp("rob_job", 1);
    me->delete_temp("biaoshi");
    message_vision(CYN"\n$N说到,有消息说魔教有一批弟子在密谋,对我派不利。\n"NOR, ob, me);
    ob->set_temp("job_asked", me->query("id"));
    ob->set_temp("dest", "emeijob");
    ob->set_temp("start_place", aquest["start"]);
    ob->set_temp("place", aquest["place"]);
    me->set_temp("j", j);
    me->apply_condition("emeijob", 15);
    me->start_busy(1);
    obn = new(__DIR__"shangdui");
    obn->move(aquest["start"]);
    obn->set("arg", ob->query_temp("dest"));
    me->set_temp("rob_start", 1);
    return "你就去"+ob->query_temp("place")+"消灭(xiaomie)魔教队伍。\n";
}

void init()
{
   object ob, where, me;
   ::init();
   ob=this_object();
   where = environment(ob);
   if(ob->query_temp("dest")){
     if(interactive(me = this_player()) && me->query_temp("rob_job")
        && ob->query_temp("job_asked") == me->query("id")
        && file_name(where) == ob->query_temp("start_place")) {
           remove_call_out("waiting");
           call_out("do_back",120,me);
	    call_out("waiting", 1, ob, me);
           }
     else{
         remove_call_out("do_back");
         call_out("do_back", 90, ob);
         }
     }
  add_action("do_kneel", "kneel");
}
void waiting(object ob, object me)
{
    if(!ob || !living(me)) return;
    command("nod "+me->query("id"));
    command("say 好，我们就在这里等着他们来吧。");
    ob->set_temp("wait_target", 1);
    me->set_temp("wait_target", 1);
    remove_call_out("wait_target");
    call_out("wait_target", 30, ob, me);
    return;
}
void do_back(object me)
{
        me->delete_temp("wait_target");
        me->delete_temp("start_place");
        me->delete_temp("place");
        me->delete_temp("dest");
        message_vision("$N转过山丘，几个起落就不见了。\n", me);
        me->move("/d/emei/hcahoudian");
        message_vision("$N急急忙忙地走了过来。\n", me);
        remove_call_out("del_temp");
        call_out("del_temp", 400, me);
}
void del_temp(object me) {me->delete_temp("job_asked");}

int wait_target(object ob, object me)
{
   object obj;
   if(!objectp(present(me, environment(ob)))){
       message_vision("$N说道：耶？人怎么不见了？\n", ob);
       remove_call_out("do_back");
       do_back(ob);
       return 1;
       }
   if(!objectp(ob = present("miejue shitai", environment(me)))){
       tell_object(me,"你发现灭绝师太不见了，只好转身离开。\n");
       tell_room(environment(me), me->name()+"突然一脸茫然的表情，看来是想要离开了。\n", ({ me }));
       me->delete_temp("rob_job");
//       me->clear_condition("rob_task");
       me->delete_temp("wait_target");
       return 1;
       }

    obj = new(__DIR__"shangdui");
    obj->move(environment(me));
    obj->set("arg", ob->query_temp("dest"));
    message_vision(HIY"\n只听一阵脚步声传来，一队明教的人马出现在眼前！\n\n"NOR, ob);
    tell_object(me,"敌人终于出现了！\n");
    message_vision(HIY"$N对着$n大声命令道：你快消灭(xiaomie)魔教队伍，我来对付其他人！\n"NOR, ob, me);
    message_vision("说完$N就冲上前去，和几个明教高手打斗追逐开了。\n", ob);
    remove_call_out("do_back");
    do_back(ob);
    me->delete_temp("wait_target");
    me->set_temp("rob_start", 1);
}
int ask_guo()
{
    object me=this_player();
    if( me->query("shen") < -10000 ) {
        command("say 看你一身邪气，还敢打听郭大侠的名号？\n");
        command("consider "+ me->query("id"));
        return 1;
    }

    command("say 本派的创派祖师郭女侠，乃是当年大侠郭靖的小女儿。郭大侠当年名震天下，生平有两
项绝艺，其一是行军打仗的兵法，其二便是武功。郭大侠的夫人黄蓉黄女侠最是聪明机智
，她眼见元兵势大，襄阳终不可守，他夫妇二人决意以死报国，那是知其不可而为之的赤
心精忠，但郭大侠的绝艺如果就此失传，岂不可惜？何况她料想蒙古人纵然一时占得了中
国，我汉人终究不甘为鞑子奴隶。日后中原血战，那兵法和武功两项，将有极大的用处。
因此她聘得高手匠人，将杨过杨大侠赠送本派郭祖师的一柄玄铁重剑熔了，再加以西方精
金，铸成了一柄屠龙刀，一柄倚天剑。");
	me->set_temp("jiuyin/emei", 1);
        return 1;
}

int ask_zhou()
{
    object me=this_player();
    if( me->query_temp("jiuyin/emei") >= 1 ) {
        command("say 周芷若是我派的第四代弟子，此刻虽然不及众位师姊，日后却是不可限量。");
        me->set_temp("jiuyin/emei", 2 );
        return 1;
    }
    command("say 你问她做什么？\n");
    command("say " + me->query("name") + "定然是看上了她，要她堕入你的彀中。");
    command("consider " + me->query("id") );
    return 1;
}

int ask_dragon()
{
    object me=this_player();
    object ob = this_object();
    if( me->query_temp("jiuyin/emei") < 4 ) {
        command("say 我派的重大秘密你怎么知道了？拿命来！");
        ob->set("neili", 10000);
        ob->kill_ob(me);
        return 1;
    }
    command("say 既然周芷若难成大器，那你就给我起个誓吧。");
    me->set_temp("jiuyin/emei", 5 );
    return 1;
}

int ask_jiuyin()
{
	object me=this_player();
	object ob=this_object();
	if (me->query("jiuyin/emei")) {
if(environment(ob)->query("short")!="华藏庵后殿")
{
tell_object(me,"这是什么地方？？这地方不能给你\n");
 return 1;
}
if(environment(ob)->query("already"))
{
tell_object(me,"你来晚了，别人已经把九阴速成篇拿走了!\n");
return 1;
}



		if (present("jiuyin sucheng", me)) {
			command("say 我不是已经给你了么？");
			return 1;
		}
		if( me->query_skill("xianglong-zhang", 1) > 0)
        		command("say 降龙十八掌你已经学了，这卷九阴速成篇你就拿去学吧。");
		else
        		command("say 你的武学路子与降龙十八掌的刚阳劲力不符，这本九阴速成篇你就拿去学吧。");

                environment(ob)->set("already",1);

		new("/clone/book/jiuyin-sucheng")->move(me);
		message("channel:rumor", MAG"【谣言】某人："+me->query("name")+"拿到九阴速成篇啦。\n"NOR, users());
		return 1;
	}
	return 0;
}
