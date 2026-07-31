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
        set_name("郭旭", ({ "guo xu", "guo"}) );
        set("gender", "男性" );
        set("nickname", "长风镖局");
        set("age", 31);
        set("long", "他是长风镖局的少局主郭旭，江湖上他的朋友甚多，所以出镖都很安全。\n");
        set("str", 29);
        set("dex", 26);
        set("con", 24);
        set("int", 22);
        set("per", 38);
        set("shen", 7500);
        set("max_qi", 2000);
        set("max_jing", 2000);
	 set("neili",2000);
	 set("max_neili",2000);
        set("eff_jingli", 1800);
	 set_skill("blade",100);
	 set_skill("zixia-shengong",200);
	 set_skill("fanliangyi-dao",100);
	 map_skill("blade","fanliangyi-dao");
	 
        set("combat_exp", 1000000);
        set("chat_chance_combat", 55);
        set("chat_msg_combat", ({
                (: perform_action, "blade.sanshen" :),
        }));
        set("inquiry", ([
                "出镖" : (: ask_job :),
                "保镖" : (: ask_job :),
                "job" : (: ask_job :),
        ]));        
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
        add_money("silver", 20);
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
 
    if(me->query_condition("job_busy"))
            return "你现在还有任务在身，等会儿再来吧。";       
    if(me->query_temp("on_biao")) 
            return "嘿嘿，你身上不是有一趟镖了吗？";
 	if(ob->query_temp("gived"))
		return "现在没有镖可以让你保。";
    if(me->query("shen") < 10000) return "哼！看来你的名气不太好，这种事没人肯信你。";
       if(me->query("balance") < 1000000) return "万一出意外，我看你没能力补偿。";

    me->set_temp("on_biao", 1);
    message_vision(CYN"\n$N高兴地道：看你武艺也不错，就让你试试吧\n",ob);
    
    me->set_temp("end_place", aquest["start"]);
    me->set_temp("biao_place", aquest["place"]);
    me->start_busy(4);
	ob->set_temp("gived",1);
    remove_call_out("ready");
    call_out("ready", 2, me); 
    remove_call_out("clear");
    call_out("clear",900,ob);
	return "现在有一趟镖运往"+me->query_temp("biao_place")+"，你要负责路上的安全，不可有差错。\n";    
}
void ready(object me)
{	object biaoshi,cart,biaoshi1;
	cart=new(__DIR__"cart");
       message_vision("郭旭把一个包裹塞在$N怀里。\n", me);       
       cart->move(me);
	biaoshi=new(__DIR__"biaoshi1");
	biaoshi->move(environment(me));
	biaoshi1=new(__DIR__"biaoshi1");
	biaoshi1->move(environment(me));
	biaoshi->set_leader(me);
	biaoshi1->set_leader(me);
	message_vision("郭旭道：你可以启程了,千万要保护好镖银。\n",me);
	
}
void clear(object ob)
{
ob->delete_temp("gived");
}