 inherit NPC;
#include <ansi.h>
#include <mudlib.h>
#include <combat.h> 
mapping chinese_location = ([
                 "baiyun":              "白云岛",
                 "bat":                 "蝙蝠岛",
                 "bawang":              "饿虎岗",
                 "biancheng":           "边城",
                 "cave":                "风云地下城",
                 "chuenyu":             "黑松堡",
                 "death":               "阎王殿",
                 "fy":                  "风云城",
                 "fywall":              "风云城",
                 "fycycle":              "风云城",
                 "ghost":               "幽灵山庄",
                 "guanwai":             "关外",
                 "guanyin":             "天枫",
                 "huangshan":           "黄山",
                 "huashan":             "华山",
                 "jinan":               "济南",
                 "laowu":               "老屋",
                 "libie":               "无名小镇",
                 "loulan":              "快活林",
                 "manglin":             "莽林",
                 "oldpine":             "老松寨",
                 "palace":              "帝王谷",
                 "qianfo":              "千佛山",
                 "qianjin":             "千金楼",
                 "qingping":            "清平山庄",
                 "quicksand":           "大沙漠",
                 "resort":              "翠竹山庄",
                 "shanliu":             "山流",
                 "shaolin":             "少林寺",
                 "shenshui":            "神水宫",
                 "songshan":            "嵩山",
                 "taiping":             "太平镇",
                 "taishan":             "泰山",
                 "taoguan":             "三清宫",
                 "taoyuan":             "桃源",
            "tieflag":             "大旗谷或者长春岛",
                 "wanmei":              "万梅山庄",
                 "wolfmount":           "狼山",
                 "wudang":              "武当山",
                 "xinjiang":            "新疆",
                 "yinghe":              "银河冥界",
                 "yingou":              "银钩赌场",
                 "zhaoze":              "大沼泽地",   
]); 
int verify_item(object item, string arg); 
void create()
{
        set_name("老土地", ({ "tudi" }) );
        set("title", YEL"有所不知 无所不言"NOR);
        set("gender", "男性" );
        set("cor",20);
        set("age", 68);
        set("str",20);
        set("per",40);
        set("long","
老土地在风云里已经混了五十多年了，很少有他不知道的事，很少有他
没见过的人。如果你有什么东西要打听，尽可以来问(question)他。
注意，除myquest外，其他询问的一律用中文。
如果是有颜色的，请加色彩代码。
$BLK$ - 黑色            $NOR$ - 恢复正常颜色
$RED$ - 红色            $HIR$ - 亮红色
$GRN$ - 绿色            $HIG$ - 亮绿色
$YEL$ - 土黄色          $HIY$ - 黄色
$BLU$ - 深蓝色          $HIB$ - 蓝色
$MAG$ - 浅紫色          $HIM$ - 粉红色
$CYN$ - 蓝绿色          $HIC$ - 天青色
$WHT$ - 浅灰色          $HIW$ - 白色 
举例：question $HIY$天机老人$NOR$
====〉你向老土地打听"HIY"天机老人"NOR"的所在。
      question myquest
====〉你向老土地打听自己的Quest情况。    
\n");
        set("combat_exp", 24000000);
        set("attitude", "friendly");
        set("chat_chance",1);
           set("chat_msg",({
                CYN"\n老土地掏出一杆旱烟袋，呼呼地抽了几下，心满意足地舒了口气。\n\n"NOR,
        }) );  
                        
        set_skill("hammer",200);
        set_skill("dodge",200);
        set_skill("parry",200);
        set_skill("unarmed",200);
                
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init() {
        add_action("do_ask","question");
}  
int do_ask(string arg) { 
        object *item,me,env;
        string location,*e_location,spot;
        int i,j;
        
        me=this_player();
        
        if (!arg||arg=="")
                return notify_fail("你想打听什么？\n\n");
        
        if (this_object()->query("inquiry_time")+2>time())
                return notify_fail("老土地说：“等等，让我喘口气再说。”\n");
                
        if (arg=="myquest")
        if (!arg=me->query("quest/quest"))
                return notify_fail("你现在没有任务。\n");       
                
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
   arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
        
        
        
        message_vision("$N向$n打听"+arg+NOR"的所在。\n",me,this_object());
                
        this_object()->set("inquiry_time",time());     
        item = filter_array(objects(), (: verify_item($1,$2) :) , arg);
        if (sizeof(item)<1) {
                message_vision(CYN"老土地沉吟许久，叹了口气说：“我好像没有听说过这个。唉，长江后浪推前
浪，前浪死在沙滩上，老了，帮不上你的忙了。”\n"NOR,this_object());
                return 1;
        }
        
/*      message_vision("total is "+(string)sizeof(item)+"\n",me);
        
        for (i=0;i<sizeof(item)-1;i++){
                if (objectp(item[i]) && objectp(environment(item[i]))) 
                        message_vision((string)i+" is "+(string)(environment(item[i])->query("name"))+"\n",me);
        }*/
        
        spot = domain_file(file_name(item[0]));
        
        if (!item[0]->is_character())
        for (i=0;i<sizeof(item)-1;i++) {
                if (!objectp(item[i])) continue;
                env=environment(item[i]);
                if (!objectp(env)) continue;
                if (userp(env)) continue;
                if (env->is_character() && !env->is_corpse()) {
                        spot = domain_file(file_name(env));
//                      message_vision(" is in NPC"+(string)(i)+"\n",me);
                        break; 
           }
                spot = domain_file(file_name(item[i]));
        }       
                
        e_location = keys(chinese_location);
        if (member_array(spot,e_location)==-1) {
                message_vision(CYN"老土地苦苦思索着说：“我肯定见过，可惜想不起来了。”\n"NOR,me);
                return 1;
        }
        message_vision(CYN"老土地拍拍$N的脑袋说：去"+chinese_location[spot]+"附近找找吧。\n"NOR,me);
        return 1;
}  
int verify_item(object item,string arg) {
        if ( item->query("name")==arg)  return 1;
        return 0;
} 
int attack() {
        command("say 生命可贵，不要自寻死路。");
        filter_array(this_object()->query_enemy(),(: $1->unconcious() :));
        this_object()->remove_all_killer();
}  
void unconcious() {
        int gin,kee,sen;
        gin =(int)query("max_jing");
        kee =(int)query("max_qi");
        sen =(int)query("max_sen");
        set("eff_qi",kee);set("qi",kee);
        set("eff_jing",gin);set("jing",gin);
        set("eff_sen",sen);set("sen",sen);
        return ; 
} 
void die() {
        int gin,kee,sen;
        gin =(int)query("max_jing");
        kee =(int)query("max_qi");
        sen =(int)query("max_sen");
        set("eff_qi",kee);set("qi",kee);
        set("eff_jing",gin);set("jing",gin);
        set("eff_sen",sen);set("sen",sen);
        return ; 
}    
