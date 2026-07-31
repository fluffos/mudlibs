#include <ansi.h>
inherit NPC;

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
       (["place":                "武道场",
       "start":                "/d/city/wudao4",]),
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
//});
string ask_job();

void create()
{
        set_name("马仇", ({ "ma chou", "ma"}) );
        set("gender", "男性" );
        set("nickname", "土匪");
        set("age", 31);
        set("long", "住在山西一带的土匪头，略有名气，常常以打劫镖车为生。\n");
        set("str", 29);
        set("dex", 26);
        set("con", 24);
        set("int", 22);
        set("per", 18);
        set("shen", -7500);
        set("max_qi", 12000);
        set("max_jing", 12000);
	 set("neili",12000);
	 set("max_neili",12000);
        set("eff_jingli", 11800);
	 set_skill("blade",300);
	 set_skill("zixia-shengong",300);
	 set_skill("fanliangyi-dao",300);
	 map_skill("blade","fanliangyi-dao");

        set("combat_exp", 1750000);
        set("chat_chance_combat", 55);
        set("chat_msg_combat", ({
                (: perform_action, "blade.sanshen" :),
        }));
        set("inquiry", ([
                "劫镖" : (: ask_job :),
                "抢劫" : (: ask_job :),
                "rob" : (: ask_job :),
        ]));
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver", 10);
}
int accept_object(object me, object obj)
{
   object ob=this_object();
   if(!me || environment(me) != environment()) return 0;
   if(!objectp(obj)) return 0;
   if(!present(obj, me)) return notify_fail("你没有这件东西。");
   if(userp(obj)){
       command("consider "+(string)me->query("id"));
       command("say 你拿个快死的人来骗我？");
       return 0;
       }
   if(obj->query("id") == "prize" && obj->query("owner") == me->query("id")){
       command("nod "+(string)me->query("id"));
       command("say 好样的！干得好！\n");
       message_vision(HIY"$N将$n"HIY"拆开，拿出了一大堆金银财宝。\n"NOR,ob, obj);
       remove_call_out("destroying");
       call_out("destroying", 5, obj, ob, me);
       return 1;
       }
   if(obj->query("money_id")) {
       command("pat " + me->query("id"));
       command("say 钱我有的是，你以后还是留给自己吧。");
       return 0;
       }
   if(obj->query("owner") != me->query("id")){
       command("hehe "+(string)me->query("id"));
       command("say 不错啊，但这活可不是你干的。");
       return 1;
       }
   else return 0;
}
void destroying(object obj, object ob, object me)
{
   object n_money;
   if(obj) destruct(obj);
   if(!ob) return;
   if(!me || environment(me) != environment()){
      command("say 咦，人呢？");
      return;
      }
   command("pat "+me->query("id"));
   message_vision(HIY"$N对$n说道：你这次做得极为出色，这是你该得的部分，拿去吧！\n"NOR,ob, me);
   n_money = new("/clone/money/gold");
   n_money->move(me);
   n_money->add_amount(1);
   me->set_temp("robjob_exp", 100+(me->query_temp("biaoshi")*100));
   me->add("combat_exp", me->query_temp("robjob_exp"));
   me->add("potential", me->query_temp("biaoshi")*40);
   tell_room(environment(me), me->name()+"数着钱袋里的金子，脸上的肌肉不住地颤动，眼睛散发着一种奇怪的光芒。\n" NOR, ({ me }));
   tell_object(me, "你被奖励了"+chinese_number(me->query_temp("robjob_exp"))+"点修为值！\n"+chinese_number(me->query_temp("biaoshi")*20)+"点潜能\n");
   me->delete_temp("robjob_exp");
   me->delete_temp("biaoshi");
   ob->delete_temp("job_asked");
   ob->delete_temp("robjob_asked");
   ob->delete_temp("dest");
   ob->delete_temp("start_place");
   ob->delete_temp("place");
   return;
}
string ask_job()
{
  object me, ob;
  mapping aquest;
  int exp, j;
  aquest = quest[random(sizeof(quest))];
  me = this_player();
  ob = this_object();
  exp = me->query("combat_exp");

   // if(me->query_condition("rob_task"))
   //         return "我现在还没有得到任何消息，你等会儿再来吧。";
    if(me->query_condition("job_busy"))
            return "你现在还有任务在身，等会儿再来吧。";
    if(ob->query_temp("job_asked") == me->query("id"))
            return "不是叫你先去那里等我吗？怎么还赖在这里？";
    if(ob->query_temp("job_asked"))
            return "嘿嘿，你来晚了，等下一次吧。";
    if(me->query("shen") > -10000) return "哼！看来你的心肠还不够黑啊，这种事你不问也罢。";
    if(exp>=600000) j=6;
    else if(exp>=500000) j=5;
    else if(exp>=400000) j=5;
    else if(exp>=300000) j=4;
    else j=3;

    me->set_temp("rob_job", 1);
    me->delete_temp("biaoshi");
    message_vision(CYN"\n$N阴阴一笑，说道：这两天长风镖局会有一趟镖经过，你够胆就和我一起去看看吧。\n"NOR, ob, me);
    ob->set_temp("job_asked", me->query("id"));
//    ob->set_temp("dest", aquest["name"]);
    ob->set_temp("dest", "robjob");
    ob->set_temp("start_place", aquest["start"]);
    ob->set_temp("place", aquest["place"]);
    me->set_temp("j", j);
    me->apply_condition("rob_task", 60+(j*20));
    me->start_busy(1);
    remove_call_out("going");
    call_out("going", 30, ob);
    return "我还有些事要办，你先去"+ob->query_temp("place")+"等我。\n";
}
void going(object me)
{
       message_vision("$N急急忙忙地走了出去。\n", me);
       me->move(me->query_temp("start_place"));
	message_vision("$N急急忙忙地走了过来。\n", me);
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
	  me->move("/d/tiezhang/lx");
        message_vision("$N急急忙忙地走了过来。\n", me);
        remove_call_out("del_temp");
        call_out("del_temp", 400, me);
}
void del_temp(object me) {me->delete_temp("job_asked");}

int wait_target(object ob, object me)
{
   object obj;
   if(!objectp(present(me, environment(ob)))){
       message_vision("$N说道：耶？那家伙怎么不见了？\n", ob);
       remove_call_out("do_back");
       do_back(ob);
       return 1;
       }
   if(!objectp(ob = present("ma chou", environment(me)))){
       tell_object(me,"你发现马仇不见了，只好转身离开。\n");
       tell_room(environment(me), me->name()+"突然一脸茫然的表情，看来是想要离开了。\n", ({ me }));
       me->delete_temp("rob_job");
       me->clear_condition("rob_task");
       me->delete_temp("wait_target");
       return 1;
       }

    obj = new(__DIR__"shangdui");
    obj->move(environment(me));
    obj->set("arg", ob->query_temp("dest"));
    message_vision(HIY"\n只听一阵车轮声传来，一只长风镖局的镖队出现在眼前！\n\n"NOR, ob);
    tell_object(me,"猎物终于出现了！\n");
    message_vision(HIY"$N对着$n大声命令道：你快抢(qiang)镖队，我来对付其他人！\n"NOR, ob, me);
    message_vision("说完$N就冲上前去，和几个护镖镖师打斗追逐开了。\n", ob);
    remove_call_out("do_back");
    do_back(ob);
    me->delete_temp("wait_target");
    me->set_temp("rob_start", 1);
}