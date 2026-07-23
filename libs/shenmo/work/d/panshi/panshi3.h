
mapping familys = ([
// 门派 : 特内，特法，temp标志
        "五庄观"        : ({"zhenyuan-force","taiyi","wzg"}),
        "南海普陀山"    : ({"lotusforce","buddhism","putuo"}),
        "方寸山三星洞"  : ({"wuxiangforce","dao","fc"}),
        "东海龙宫"      : ({"dragonforce","seashentong","lg"}),
        "月宫"          : ({"moonforce","moonshentong","moon"}),
        "阎罗地府"      : ({"tonsillit","gouhunshu","hell"}),
        "三界散仙"      : ({"butian-force","mysticism","sanxian"}),
        "将军府"        : ({"lengquan-force","baguazhou","jjf"}),
        "陷空山无底洞"  : ({"huntian-qigong","yaofa","wdd"}),
        "火云洞"        : ({"huomoforce","pingtian-dafa","hyd"}),
        "大雪山"        : ({"ningxie-force","dengxian-dafa","xs"}),
        "黄花观五毒门"        : ({"wudu-xinfa","xiuluo-yinshagong","wudu"}),
        "盘丝洞"        : ({"jiuyin-xinjing","pansi-dafa","psd"}),
        "蜀山剑派"        : ({"zixia-shengong","taoism","shushan"}),
        "峨嵋派"        : ({"emeiforce","mahayana","emei"}),
        "江湖浪子"        : ({"wuji-force","tianjijue","youxia"}),
        "少林寺"	: ({"yijinjing","chanzong","shaolin"}),
        "轩辕古墓"        : ({"jiuyin-force","youming-spells","gumu"}),
        "昆仑山玉虚洞"       :  ({"xuanzong-force","yuxu-spells","kunlun"}),
       "三界山"          : ({"huntianforce","tianmogong","sanjie"}),
 "神剑山庄"        : ({"cloudforce","xueying-xianfa","shenjian"}),
 "移花宫"        : ({"yihua-force","mingyu-jue","yhg"}),
"乱石山碧波潭"        : ({"zhuanlong-force","bihai-spells","bibitan"}),
        "剑客联盟"        : ({"guixi-force","renshu","swordman"}),
]);

string fam;
int pot;

string askLeave()
{
object me = this_player();
fam = query("family/family_name");
if ( !fam )
        error(__FILE__" 叛师NPC，没有family_name ... \n");
if ( me->query("family/family_name")!=fam )
        return "你又不是我"+fam+"的人。";
me->set_temp("叛师/"+familys[fam][2],1);
return RANK_D->query_rude(me)+"当真要离开我"+fam+"？(agree)";
}

int doAgree()
{
string msg;
int i;
object me = this_player();
if ( !fam )
        error(__FILE__" 叛师NPC，没有family_name ... \n");
if ( me->is_busy() )
        return notify_fail("你正忙着呢。\n");

message_vision("$N朝$n点头道：弟子愿意！\n",me,this_object());
message_vision("$n低头沉思片刻，道：好吧，既然你下定决心了，我也不留你。\n",me,this_object());
pot = me->query("叛师/num");
if ( !pot || pot<=0 )
        pot=1;
i = me->query("combat_exp")/(9+pot);
i*= 9;
me->set("combat_exp",i);

i = me->query("daoxing")/(9+pot);
i*= 9;
me->set("daoxing",i);

me->add("叛师/num",1);
if ( me->query_skill(familys[fam][0],1)>=0 )
        {
        me->command("enable force none");
        me->delete_skill(familys[fam][0]);
        }
if ( me->query_skill(familys[fam][1],1)>=0 )
        {
        me->command("enable spells none");
        me->delete_skill(familys[fam][1]);
        }
me->set("title","普通百姓");
me->delete("family");
me->delete_temp("叛师");
me->save();
msg = me->query("name")+"脱离我"+fam+"，江湖风浪，自此我派与之再无瓜葛";
SDS_D->do_chat(this_object(),msg,"chat",fam,0);
return 1;
}





        
        


