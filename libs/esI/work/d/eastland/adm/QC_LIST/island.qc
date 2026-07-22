                 谪仙岛区域开放说明----odin

I.背景大纲:

    本岛的背景是以三族合战做基础，各族的历史及背景，都希望以
各说各话的方式来设定；东方的区域是由魔族飘移至此所开阔，南方
则是原住民的蜥蜴人族，西方则是由一群落难的人类武士在此建立的
城堡；位置则是接近东方大陆的一个岛，与东方大陆的交通是由一道
称为『遁甲之门』的传送工具来运送，由於该岛四周都是汹涌的暗潮
，无法以船只航行来往，所以这个岛长年以来彷佛披著神秘面纱似的
，一直与外界孤立。


II.任务概要:
   三族战争,发动方法:
            (1) 完成 tsunami 的任务三,可以得到原神一颗
            (2) 将原神给(give)圣骑士金身,金身将变回圣骑士,然後走下楼(
                圣骑士)
            (3) 若是完成tsunami的任务者，将得到一把创世神戟(一天一把)
            (3)在有和平碑处,乞求(beg Lizard Holy Knight),将发动战争
(关於战争用的npc,分别列在tsunami,ishige,mercury的QC档中)


     
III.NPC 列表:(/o/open/odin/island/monster)
NAME    FILE_NAME  LV  AC/DB  WC/MAX/MIN  WEAPON  ARMOR      备注
一虚    e-shi      19  80/18  53/38/16    ------  流云靴     .使用五种七十二绝
                                                  六祖袈裟    技(包括金刚不坏)
                                                             .提供有关战争讯息
                                                             .对玩家特难,所以
							      LV19

圣骑士  holy_knight 19 130/47 105/68/36   ------  钛合金覆面 .与战争有关 
                              85/25/50            钛合金护手 .难度特高,exp
                                                  钛合金臂环  5000 
                                                  钛合金□甲 .原则上,不希望被
                                                  钛合金尾甲  杀,一次reboot一
                                                  钛合金战靴  只,被杀就没战争!
                                                  蓝宝石项□
                                                  蓝宝石戒指

小贩    vendor      19 90/30  95/68/26    ------  ---------- .可杀 *grin* 


税官    taxman      18 100/40 80/21/73    ------  ---------- .会隐形,有wimpy
							      税抽1/3
    
钱掌柜  shopkeeper  12 35/15  24/22/14    ------  ---------- .原本不可杀,ask
                                                              thief後变身成lv
                                                              12的钱行次郎
                                                             .特殊攻击:金钱镖
                                                              成功:damage 18
                                                              失败:victim得4 
                                                                   gold

蜥蜴猎人lizardman   9  26/13  29/29/15   蜥蜴短剑 蜥蜴人短甲 .带个补兽袋

大白鲨  shark       18 78/30  80/67/31   -------  ---------- .会追人
  
章鱼    octpus      14 62/30  62/34/18   -------  ---------- .特殊攻击:捆人
                                                              damage:14+
                                                                random(20)

章鱼    octpus1     10 45/19  44/23/10   -------  ---------- .特殊攻击:捆人
							        damage:10+
								random(11)

樱花鲑  salmon      10 50/20  27/23/12
                              15/18/8    -------  ---------

鬼魅乌鸦spec_crow   4  10/1   11/11/4    -------  ---------  .特殊攻击:
							       codition:WEAK  

乌鸦    crow        2  10/4   6/8/4      -------  ---------

小鱼    s_fish      5  25/8   16/12/6    -------  ---------


松鼠    squirrel    2  7/0    7/6/3      -------  ---------


巨龟    turtle      6  20/0   10/12/4    -------  ---------   .所有乌龟会相
                                                               互扶持....:)

老龟    turtle1     8  25/6   11/16/6    -------  ---------

小龟    turtle2     3  15/0   8/9/3      -------  ---------

壮年龟  turtle3     11 33/12  17/22/10   -------  ---------




IV.OBJ 列表:(/open/odin/island/obj)
NAME     FILE_NAME    TYPE  用途
补兽袋   bag          ----  普通袋子,比八宝带差!

收据     bill         ----  quest 用,乱放东西会收到一张收据 ......*Grin*

百草丹   green_pill   ----  药店卖的,与一般相同
 
小还丹   small_pill   ----  
    
大还丹   large_pill   ----

断续膏   spicy_plater ----  

云南白药 white_plater ----

枇杷膏   paste        ----  恢复tp,100点

纪念碑   stone        ----  发动战争用,战争爆发stone将消失


V.WEAPON 列表:(/open/odin/island/weapon)

NAME        FILE_NAME  TYPE        WC/MAX/MIN   备注

创世神戟    jousting   jousting    45/25/55

蜥蜴人短剑  sword01    shortblade  15/19/8



VI.ARMOR 列表:(/open/odin/island/obj)
NAME       FILE_NAME  TYPE   MATERIAL    AC/DB  备注
流云靴     boots01    feet   cloth       8/3
 
钛合金战靴 boots02    feet   light_metal 8/3

六祖袈裟   cloth01    body   cloth       32/5   special_defense:
						  fire,none : 20

蜥蜴人短甲 plate01    body   leather     11/3   

钛合金□甲 plate02    body   light_metal 35/5

钛合金覆面 helmet01   head   light_metal 8/3

蓝宝石戒指 ring01     finger element      0/5

蓝宝石项□ necklace01 misc   element      0/6

钛合金尾甲 tail01     tail   light_metal  8/3

钛合金盾   shield01   shield light_metal  8/5

钛和金臂环 arm01      arms   light_metal  4/3

钛合金护手 glove01    hands  light_metal  4/4

        
VII. 未完成部份

(A).地图:

     野外的virtual_server,地图

(B).战争的功劳:

     将会发与war_score,以score为依据发给适合的武器(个人用)

     请参考/open/odin/island/weapon/psword.c

     将会有一个铁匠之类的npc发给武器
  
