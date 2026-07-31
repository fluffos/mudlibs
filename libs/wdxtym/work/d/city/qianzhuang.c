// Room: /city/qianzhuang.c
inherit ROOM;

object N_b();
object N();
object R_b();
object R();
object UR_potential();
object UR_yuanbao();
object UR_yuanbao_2();
object SR_b();
object SR();
object SSR_b();
object SSR();
object UUR();
void create()
{
	set("short", "钱庄");
	set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。它发
行的银票信誉非常好，通行全国。
    在对面的墙上挂了块牌子(paizi)。
LONG );
	set("no_fight", 1);
	set("exits", ([
		"east" : __DIR__"beidajie1",
	]));
	set("item_desc", ([
		"【牌子】" : "本钱庄提供以下服务：\n"
		ZJOBACTS2+ZJMENUF(3,3,8,30)"存钱:cun"ZJSEP"取钱:qu"ZJSEP"查账:check\n",
		"抽奖机" : "这是一台巫师做的机器，你可以抽到很多的奖品。\n",
	]) );
    set("action_list", ([
		HIY"神奇抽奖(20灵石)"NOR : "chou -yuanbao",
	  // HIY"神奇抽奖(30点券)"NOR : "chou -jifeng", 	
	  //	HIW"白色扭蛋(10银票)"NOR : "chou -cash",
//MAG"紫色扭蛋(3000潜能)"NOR : "chou -potential",
	]));
	set("objects", ([
		__DIR__"npc/qian" : 1
	]));
	setup();
}
void init()
{
	add_action("do_chou", "chou");
}
int do_chou(string arg) {
    object gift, money, me;
    int i, j,number,p;
    mapping my;
    me = this_player();
       if (!arg) return notify_fail("你要要动那个抽奖？\n");
       
       if ((int)me->query("max_qi")>10000000) return notify_fail("你气血太多没办法抽奖？\n");

        if (arg == "-yuanbao") {
            if (me->query("yuanbao") >= 20) {
                me->add("yuanbao", -20);
                me->add("nd_yuanbai", 1);
                tell_object(me, HIM"你花费20灵石，翻动了"HIY"神奇抽奖盒\n"NOR);
            } else {
                return notify_fail("你身上的灵石不足20个\n");
            }
          i=random(10000);
          if(i<1){
          gift=UUR();
          log_file("new_gift/nd_yuanbao", sprintf("%s：%s(%s)用灵石抽奖第%d次抽到%s,随机值是%d。\n",
				ctime(time()),me->query("name"),me->query("id"),me->query("nd_yuanbao"),gift->name(),i));
          call_out("b",1,gift);
          me->set_temp("nd",1); 
          }else if(i<10){
          gift=UR_yuanbao();
          log_file("new_gift/nd_yuanbao", sprintf("%s：%s(%s)用灵石抽奖第%d次抽到%s,随机值是%d。\n",
				ctime(time()),me->query("name"),me->query("id"),me->query("nd_yuanbao"),gift->name(),i));
          call_out("b",1,gift);
          me->set_temp("nd",1);
          }else if(i<500){
          gift=SSR();
          log_file("new_gift/nd_yuanbao", sprintf("%s：%s(%s)用灵石抽奖第%d次抽到%s,随机值是%d。\n",
				ctime(time()),me->query("name"),me->query("id"),me->query("nd_yuanbao"),gift->name(),i));
          call_out("b",1,gift);
          me->set_temp("nd",1);
          }else if(i<3000){//不播报
          gift=SR();
          
          call_out("a",1,gift);
          me->set_temp("nd",1);
          }else if(i<6000){
          gift=R();
          call_out("a",1,gift);
          me->set_temp("nd",1);
          }else{
          gift=N();
          call_out("a",1,gift);
          me->set_temp("nd",1);               
          }
          return 1;//抽奖完成
        } else if (arg == "-jifeng") {
            if (me->query("jifeng") >= 30) {
                me->add("jifeng", -30);
                me->add("nd_jifeng", 1);
                tell_object(me, HIM"你花费30点券，翻动了"HIY "神奇抽奖盒\n"NOR);
            } else {
                return notify_fail("你身上的点券不足30张\n");
            }
          i=random(10000);
          if(i<1){
          gift=UUR();
          log_file("new_gift/nd_jifeng", sprintf("%s：%s(%s)用点券抽奖第%d次抽到%s,随机值是%d。\n",
				ctime(time()),me->query("name"),me->query("id"),me->query("nd_yuanbao_2"),gift->name(),i));
          call_out("b",1,gift);
          me->set_temp("nd",1); 
          }else if(i<10){
          gift=UR_yuanbao_2();
          log_file("new_gift/nd_jifeng", sprintf("%s：%s(%s)用点券抽奖第%d次抽到%s,随机值是%d。\n",
				ctime(time()),me->query("name"),me->query("id"),me->query("nd_yuanbao_2"),gift->name(),i));
          call_out("b",1,gift);
          me->set_temp("nd",1);
          }else if(i<500){
          gift=SSR_b();
          log_file("new_gift/nd_jifeng", sprintf("%s：%s(%s)用点券抽奖第%d次抽到%s,随机值是%d。\n",
				ctime(time()),me->query("name"),me->query("id"),me->query("nd_yuanbao_2"),gift->name(),i));
          call_out("b",1,gift);
          me->set_temp("nd",1);
          }else if(i<3000){//不播报
          gift=SR_b();
          call_out("a",1,gift);
          me->set_temp("nd",1);
          }else if(i<6000){
          gift=R_b();
          call_out("a",1,gift);
          me->set_temp("nd",1);
          }else{
          gift=N_b();
          call_out("a",1,gift);
          me->set_temp("nd",1);
            }
           return 1;//抽奖完成
           } else if (arg == "-cash") {
           if (money = present("cash", me)) {
            number = money->query_amount();
            if (number >= 10) {
                money->add_amount(-10);
                me->add("nd_cash", 1);
                tell_object(me, HIM"你花费十张张银票，拉动了"HIW"白色抽奖杆\n"NOR);
            } else { //存在银票却数量不够一张
                return notify_fail("你身上的银票不够十张\n");
            }
        }else{    
        return notify_fail("你身上的没有银票\n");        
       }
        
        i=random(100);
        if(i<1){
        gift=new("/clone/shangren/bai");
        call_out("a",1,gift);
        me->set_temp("nd",1);
        }else if(i<30){
        gift=R_b();
        call_out("a",1,gift);
        me->set_temp("nd",1);
        }else{
        gift=N_b();
        call_out("a",1,gift);
        me->set_temp("nd",1);
        }
   
         }else if(arg == "-potential"){
           my =me->query_entire_dbase();
                p=my["potential"];
              //  tell_object(me, "当前潜能："+p);
           if (p>= 3000) {
                me->add("potential", -3000);
                me->add("nd_potential", 1);
                tell_object(me, HIM"你花费3000潜能，拉动了"MAG "紫色抽奖杆\n"NOR);
            } else {
                return notify_fail("你的潜能不足3000\n");
            }
      
      i=random(100);
        if(i<1){
        gift=UR_potential();
        call_out("a",1,gift);
        me->set_temp("nd",1);
        }else if(i<30){
        gift=SR_b();
        call_out("a",1,gift);
        me->set_temp("nd",1);
        }else if(i<60){
        gift=R_b();
        call_out("a",1,gift);
        me->set_temp("nd",1);
        }else{
        gift=N_b();
        call_out("a",1,gift);
        me->set_temp("nd",1);
        }  
    }
    return 1;
}
object N_b(){//N卡绑定
object ob;
string *list = ({
"/clone/aaa/vip2/book_tianfu",//天赋书
"/clone/aaa/vip2/book_wuliang",//无量
"/clone/aaa/vip2/dan_chongmai1",//下冲
"/clone/aaa/vip2/jinsha",//金沙
"/clone/aaa/vip2/putao",//葡萄
"/clone/aaa/vip2/dan_zhengqi",//正气
"/clone/aaa/vip2/dan_xieqi",//邪气
"/clone/aaa/vip2/dan_chongmai2",//菩提子
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}


object N(){//N卡不绑定
object ob;
string *list = ({
"/clone/aaa/book_tianfu",//天赋书
"/clone/aaa/book_wuliang",//无量
"/clone/aaa/dan_chongmai1",//下冲
"/clone/aaa/jinsha",//金沙
"/clone/aaa/putao",//葡萄
"/clone/aaa/dan_zhengqi",//正气
"/clone/aaa/dan_xieqi",//邪气
"/clone/aaa/dan_chongmai3",//菩提子
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}



object R(){//R卡不绑定
object ob;
string *list = ({
"/clone/aaa/fushougao",//福寿
//"/clone/aaa/hua5",//翡翠兰
"/clone/aaa/dan_chongmai2",//中冲
"/clone/aaa/dan_chongmai2",//灵芝
"/clone/aaa/lingzhi2",//小还丹
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}


int a(object gift){
object me = this_player();
tell_object(me,"神奇抽奖盒卡片随风起舞，你随手拿起一张卡片。定眼一看\n");
call_out("a_b",1,gift);
}
void b(object gift){
object me = this_player();
tell_object(me,"神奇抽奖盒卡片随风起舞，你随手拿起一张卡片。定眼一看\n");
call_out("b_b",1,gift);
}
void a_b(object gift){
object me = this_player();
gift->move(me);
tell_object(me,"求爷爷告奶奶，翻开手一看。拐咯"+gift->name()+"\n");
me->delete_temp("nd");
}
void b_b(object gift){
object me = this_player();
gift->move(me);
tell_object(me,"求爷爷告奶奶，翻开手一看。拐咯"+gift->name()+"\n");
//CHANNEL_D->do_channel(this_object(), "rumor",me->name()+"在抽奖机里获得了"+gift->name());
me->delete_temp("nd");
}


object R_b(){//R卡绑定
object ob;
string *list = ({
"/clone/aaa/vip2/fushougao",//福寿
"/clone/aaa/vip2/hua5",//翡翠兰
"/clone/aaa/vip2/dan_chongmai2",//中冲
"/clone/aaa/vip2/lingzhi",//灵芝
"/clone/aaa/vip2/lingzhi2",//小还丹
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}




object UR_potential(){//UR卡潜能
object ob;
string *list = ({
"/clone/shangren/hetian",//和田玉
"/clone/aaa/vip2/dan_jiuzhuan",//九转
"/clone/aaa/vip2/putao1",//神奇
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}



object SSR(){//SSR卡不绑定
object ob;
string *list = ({
"/clone/aaa/dan_con",//洗髓
"/clone/aaa/dan_dex",//火红
"/clone/aaa/dan_str",//神力
"/clone/aaa/dan_int",//醍醐
"/clone/aaa/dan_chongmai4",//极冲
"/clone/aaa/yanzhi",//胭脂
"/clone/aaa/avipcard",//月卡
"/clone/aaa/ling_wolong",//卧龙
"/clone/aaa/jinpiao",//金票
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}


object SSR_b(){//SSR卡绑定
object ob;
string *list = ({
"/clone/aaa/vip2/dan_con",//洗髓
"/clone/aaa/vip2/dan_dex",//火红
"/clone/aaa/vip2/dan_str",//神力
"/clone/aaa/vip2/dan_int",//醍醐
"/clone/aaa/vip2/dan_chongmai4",//极冲
"/clone/aaa/vip2/yanzhi",//胭脂
"/clone/aaa/vip2/aaaacard",//月卡
"/clone/aaa/vip2/ling_wolong",//卧龙
"/clone/aaa/vip2/jinpiao",//金票
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}





object UR_yuanbao(){//UR卡不绑定
object ob;
string *list = ({
"/clone/aaa/dan_jiuzhuan",//九转
"/clone/aaa/butian",//补天
"/clone/aaa/tiancs",//冰蚕
"/clone/aaa/card_name",//更名卡
"/clone/aaa/tianxingdan",//天性丹
"/clone/shangren/lantian",//蓝田
"/clone/aaa/putao1",//月卡
"/clone/aaa/xidianka",//洗点
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}



object UR_yuanbao_2(){//UR卡不绑定
object ob;
string *list = ({
"/clone/aaa/vip2/dan_jiuzhuan",//九转
"/clone/aaa/vip2/butian",//补天
"/clone/aaa/vip2/tiancs",//冰蚕
"/clone/aaa/hua",//福袋
"/clone/aaa/vip2/card_name",//更名卡
"/clone/aaa/vip2/tianxingdan",//天性丹
"/clone/shangren/lantian",//蓝田
"/clone/aaa/vip2/putao1",//月卡
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}




object UUR(){//UUR卡不绑定
object ob;
string *list = ({
"/clone/shangren/book_mengzi",//孟
"/clone/shangren/guigu",//鬼谷
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}








object SR_b(){//SR卡绑定
object ob;
string *list = ({
"/clone/shangren/putao3",//葡萄干
"/clone/aaa/vip2/tianxiang",//天香
"/clone/aaa/vip2/dan_chongmai3",//上冲
"/clone/aaa/vip2/dan_chongmai2",//中冲
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}







object SR(){//SR卡不绑定
object ob;
string *list = ({
"/clone/putao3",//葡萄干
"/clone/aaa/tianxiang",//天香
"/clone/aaa/dan_chongmai3",//上冲
"/clone/aaa/dan_chongmai2",//中冲
}); 
 ob=new(list[random(sizeof(list))]);
 return ob;
}
