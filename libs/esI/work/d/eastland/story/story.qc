    

                      「神仙岛」区域简介 

I.历史简介 :
       
          神仙岛位於遥远的东方大陆，原来是个人烟罕至的地方，却因为航海

　　　技术发达，岛四周暴风圈的减小，渐渐地揭开了它神秘的面纱。 

          在原始洪荒的大地上，原本混杂著各种的族类，并和天界串连在一起

　　　千万年来各安天命，彼此相安无事，和乐融融。大地上分为五个部分，各

　　　受著四个不同天帝所统治，但尊崇为中央部分的天帝－黄帝。不料三千多

　　　年前，南方的巨人族里，一个凶残暴厉名叫「蚩尤」的，表面上是顺从，

　　　骨子里却不怀好意。蚩尤自从把南方天帝－炎帝的宝座夺过来後，因为他

　　　本是炎帝的後代，於是便「名正言顺」地自称起 "炎帝" 来。这个蚩尤是

　　　不会把这样一个小小的一方天帝的位置看在眼里的，最终目的乃是想夺取

　　　中央上帝的黄帝的宝座。

        　这场争夺之战是免不了的，起初，战事是一面倒的，蚩尤籍著煽动地

　　　面上的人民，在各处打了不时胜仗，这对於黄帝而言是相当不利，但故事

　　　的结局都是一样的，最後由代表正义的黄帝所战胜。有鉴於神和人不分出

　　　界限，混居在一起，总是弊多利少，将来难免没有第二个 "蚩尤" 起来煽

　　　动人民。自此，天和地的通路被阻隔断，叫人们再也上不了天，又维持了

　　　安全。

　　　　　人们总是渴望能到天上的，於是便产生了 "巫师" 来传达上天的消息

　　　，做为沟通的媒介，於是在神仙岛上形成了一座名叫「巫咸城」的城市，

      当然，有著不为人知的秘密才能有那个神仙岛，才能有那城在那座岛上。
　
　        随著时间的流逝，人们多已死心於窥往天界想，神仙岛渐被遗忘，加

      上前往神仙岛诸多凶险。近来航海技术发达，神仙岛这个名字才又被人们

      想了起来。

　　

II.特殊房间：
       
       I). 买卖 eq ( /story/wiz/city/store.c)
       II).旅馆    ( /story/wiz/city/hotel1.c")
       III).药店   ( /story/wiz/city/hospital1.c")     


III.任务概要：

       I). 帮助受伤者 (/story/monster/patient1.c)
      II). 帮巫罗王找回巽灵珠 (/story/wiz/city/monster/wiz_king1.c)



IV. PART １ 武器： /story/weapon/

武器名称    档案名称        武器类别     WC    Damage      特殊攻击

战士□匕    dagger1.c        dagger      20    13/23
钓杆        fisher_staff.c   blunt       20    8/15
天魔之杖    imp_wand.c       wand        30    10/20       evil
玄铁重剑    sword1.c         longblade   35    20/30


IV. PART ２ 防具： /story/armor/

防具名称      档案名称            型态       质料      AC/DB     特殊效果

□符          amulet1.c           misc       cloth      0/1 
乱环环        fisher_armband.c    arms     heavy_metal  3/3
十二天都符□  imp_amulet.c        misc       cloth      0/1
战士□臂环    imp_armband.c       arms      element     3/4      energy:-20
								 electric:20
大首领披风    imp_cloak.c         cloak      cloth      7/6     dex-2
								 meditate:10
羽神衣        imp_cloth.c         body       cloth      22/2     magic:35
								 fire:30
战士□胫甲    imp_leggings.c      legs      element     6/3      electric:5
战士□铠甲    imp_plate.c         body      element     27/4       
七彩琉璃戒    imp_ring.c         finger     element     0/6
大红衣服      lucky_cloth.c       body      cloth       0/1      electric:50
□戒          ring1.c            finger     element     0/7
九魔阴阳符    vampire_amulet.c    misc      cloth       0/6     evil:-50


IV. PART ３ 物品： /story/item/

       物品名称         档名                   
                              
       巽灵珠          ball1.c            
       进财符          card1.c           
       飞翔之笛        flute1.c          
       大红葫          gourd1.c
   「蚩尤」的□体      head1.c
    「文蛛」毒液       liquid.c
      奇妙吸管         straw.c


IV. PART ４ 怪物: /story/monster  PS * 表主动攻击

   怪物名称        档名      AC/DB  WC  伤害范围   武器装备      特殊能力    

[ 11 ] 羽民壮丁  adult1.c    55/2   24   11/24
[  6 ] 小蝙蝠     bat1.c     30/2   13   4/9 
[ 11 ] 大蝙蝠     bat2.c     55/2   24   11/24
[  8 ] 羽民小弟弟 boy1.c     40/2   15   6/12
[  5 ] 小螃蟹     crab1.c    25/0   11   5/11
[  6 ] 小螃蟹     crab2.c    30/0   13   6/13
[  4 ] 小螃蟹     crab3.c    20/0   9    4/9
[ 16 ] 小螃蟹     crab4.c    70/0   36   19/36
*[ 18 ] 地狱□犬  dog1.c     1/1    90   33/57                  bleeding
[ 18 ] 雷兽 应龙 dragon1.c   117/20 66   24/45                  lightning
[ 19 ] 羽民族大首领 羽后     104/66 78   35/60     天魔□杖     全部魔法  
		 elder1.c		           羽神衣
                                                   十二天都符□
						   七彩琉璃戒 
						   大首领披风 
						   战士□胫甲
[ 16 ] 老钓者    fisher.c    73/28  41   18/35     钓杆	        special damage
						   乱环环
[  8 ] 羽民小妹妹 girl1.c    40/2   15   6/12
[ 16 ] 羽民族守卫 guard1.c   76/25  59   22/33     战士□匕     aim weakest
						   战士□铠甲
						   战士□胫甲	
						   战士□臂环
*[ 13 ] 热带昆虫 insect1.c   65/0   26   13/27     
*[ 16 ] 玄天玉狮 liong1.c    60/15  38   19/36     大红衣服 
[ 17 ] 吉神 泰逢 lucky_god.c 1/101  309  16/16     进财符          
       						   大红葫 
[ 13 ] 羽民老者  older1.c    65/2   31   12/30
[ 19 ] 受伤者    patient1.c                                     quest
								cant kill
 
[ 16 ] 吟游诗人  poet1.c     75/5   38   15/36 

[ 19 ] 人面蓝蝎的头部 head.c 80/15  74   45/63
[ 19 ] 人面蓝蝎的尾部 tail.c 10/45  9    1/7
                
*[ 19 ] 文蛛     spider1.c   1/1    67   36/60                  poison
								block
[ 18 ] 剑客 八门吹雪         80/32  65   35/35     玄铁重剑     special damage
	        swordman1.c          		   □符
						   □戒  
[  1 ] 旅行商人[骑在驴子上]  			   水晶玻璃球
[ 10 ] 羽民妈妈  woman1.c    50/2   22   10/14

*[ 19 ] 万年妖□ 谷辰                                           请看 code  
                vampir1.c




V. PART １ 武器： /story/war/weapon/

武器名称    档案名称        武器类别     WC    Damage      特殊攻击

巨斧        axe1.c          axe          33    23/38       bleeding
木棒        blunt1.c        blunt        15    5/14    
嗜血       chi_blood.c      dagger      lv*2   lv+5/lv*2   receive_healing 
血镰刀      scythe.c        longblade    20    14/22
魔风杖      staff1.c        wand         30    10/20       evil
雨神鞭      whip1.c         whip         30    13/22


V. PART ２ 防具： /story/war/armor/

防具名称      档案名称            型态       质料      AC/DB     特殊效果

蚩尤战袍      chi_cloak.c         body       cloth     20/4      
蚩尤战盔      chi_helmet.c        head       cloth     0/2       
地狱之盾      chi_shield.c       shield      cloth     0/5       
蚩尤绑腿      chi_skirt.c         legs       cloth     0/1       
披襟褴衣      cloth1.c            body       cloth     15/5 
风神衣        cloth2.c            body       cloth     15/5      
风神套        gloves1.c           hands      cloth     3/2
雨符          rain_amulet.c       body       cloth     0/4       evil:20
						                 divine:-15 
雨师之袍      rain_cloth.c        body       cloth     0/5       cold:-20
								 magic:30

V. PART ３ 怪物: /story/monster  PS * 表主动攻击

   怪物名称        档名      AC/DB  WC   Damage   武器装备      特殊能力

*[ 19 ] 蚩尤       chi_eu.c  20/12  67   37/60    蚩尤战盔      evil
                                                  蚩尤战袍      poison
    						  蚩尤绑腿      
						  嗜血 
						  地狱之盾
*[ 14 ] 魑鬼       ghost1.c  70/15  28   14/22    血镰刀        evil
*[ 14 ] 魅鬼       ghost2.c  40/25  33   18/27    血镰刀        
*[ 16 ] 魉鬼	   ghost3.c  50/25  50   21/33    血镰刀        evil
								confused
*[ 16 ] 魍鬼       ghost4.c  50/25  50   21/33    血镰刀        poison
*[ 16 ] 神嵬       ghost5.c  50/25  53   19/37                  poison
[ 16 ] 夔兽        healer1.c 53/35  42   16/30                  healing
*[ 13 ] 巨神兽     pet1.c    60/15  46   9/25                   poison
*[ 18 ] 雨师      rain_god.c 65/30  55   23/25    雨符          poison
						  雨师之袍
						  雨神鞭
[ 16 ] 天界奇兵   soldier1.c 80/22  45   22/35    白银铠甲
						  太乙青霜剑
[ 17 ] 众天神将   soldier2.c 85/25  50   24/39    白银铠甲
						  白银盾牌
						  太乙青霜剑
*[  8 ] 巨人族士兵 troll1.c  50/6   16   7/17     披襟褴衣
						  木棒
*[ 17 ] 巨人族战士 troll2.c  75/35  52   27/42    披襟褴衣
						  巨斧
*[ 18 ] 风伯      wind_god.c 68/27  62   26/38    风神套        evil
						  风神衣
						  魔风杖
               

VI. PART １ 武器： /story/wiz/weapon/

武器名称    档案名称        武器类别     WC    Damage      特殊攻击

太皓古弋   captain_hook1.c  thrusting    45    28/47
冰精       ice_dagger.c     dagger       20    13/20
黄金枪     jousting1.c      jousting     25    14/24
黄金枪     jousting2.c      jousting     30    15/33
芭蕉扇     p_fan1.c         blunt        25    13/22
黄金长矛   polearm1.c       polearm      30    19/30
黄金长矛   polearm2.c       polearm      33    19/33
渡劫金针   wiz_dagger1.c    dagger       30    19/33
霸王枪     wiz_lance.c      jousting     35    10/30        nosecond
金笔       wiz_pen1.c       thrusting    30    15/20
混沌□杖   wiz_wand1.c      wand         35    20/30        electric


VI. PART ２ 防具： /story/wiz/armor/

防具名称      档案名称            型态       质料      AC/DB     特殊效果

长袖对襟棉袍  captain_cloth1.c    body       cloth     0/5       evil:-20													
麻纱帽        captain_hat1.c      head       cloth     7/1       
雪魂凝指      ice_ring.c         fihger      element   0/5       dex:-1
							         meditate:10
琉璃珠项□    p_amulet1.c         misc       element   0/5       light
 								 str:-1
红缎地彩绣肚兜 p_cloth1.c         body       cloth     20/5
护国师□符□  wiz_amulet1.c       misc       cloth     0/8      evil:30
								 poison:30
								 fire:-30
								 cold:-30
白练腰带      wiz_belt1.c	  legs       cloth     6/5      
王者披风      wiz_cloak1.c        cloak    heavy_metal 7/3
白色官服      wiz_cloth1.c        body       cloth     26/5
药师诊袍      wiz_cloth2.c        body       healer    32/7      evil:30
							         poison:30
								 fire:-20
								 cold:20													
药师手套      wiz_gloves1.c       hands      healer     4/3       evil:20
								 poison:20
								 fire:-20
						                 cold:-20
皇冠          wiz_helmet1.c       head     heavy_metal 7/1 
药师护头      wiz_helmet2.c       head     healer      7/4       evil:20
								 poison:20
								 fire:-20
								 cold:-20
黄金铠甲      wiz_plate1.c        body     heavy_metal 34/5      
护国师□戒    wiz_ring1.c         finger   element     0/5       magic:30
								 divine:-60
王者之戒      wiz_ring2.c         finger   element     0/5
护国师□袍    wiz_robe1.c         body     cloth       30/5
黄金盾        wiz_shield1.c       shield   heavy_metal 5/0
黄金盾        wiz_shield2.c       shield   heavy_metal 7/4
黄金盾        wiz_shield3.c       shield   heavy_metal 10/1


VI. PART ３ 物品： /story/wiz/item/

       物品名称         档名

       无底袋           bag1.c
       金色篮子        basket1.c 
       水晶玻璃球      crystal1.c
       遁龙桩          flee1.c
       令牌            mark1.c
       灭魔符          spell1.c
       万相俱灭术      spell2.c
       

VI. PART ４ 怪物: /story/wiz/monster  PS * 表主动攻击

   怪物名称        档名      AC/DB  WC   Damage  武器装备       特殊能力

[  1 ] 旅馆老板   boss1.c                                       不能砍
[  5 ] 小男孩     boy1.c     25/0   11    2/6     
[  1 ] 小白狗 吉利 dog1.c					不能砍
[  9 ] 宫女     f_servant1.c 45/0   20    8/19
[  5 ] 小女孩     girl1.c    25/0   11    2/6
[  1 ] 金石老人 golden_older.c		                        不能砍
[ 18 ] 雪山灵魅 寒玉娘娘     85/14  64    30/50  雪魂凝指       poison
               icewoman.c			 冰精           block
								bleeding
[ 11 ] 路边卖蚵仔煎的        55/2   24    11/24  
               merchant1.c
[ 11 ] 路边卖米粉羹的        55/2   24    11/24
               merchant2.c
[  6 ] 老头子  older1.c      30/0   13    4/12
[  7 ] 患者    patient1.c    15/2   26    11/23
[ 17 ] 铁扇公主 princess1.c  75/35  76    35/55  红缎地彩绣肚兜 forget 
 						 琉璃珠项□
						 芭蕉扇
[ 13 ] 卜筮者 soothsayer1.c  65/0   29    10/28
[  3 ] 学子   student1.c     25/0   6     2/6
[ 12 ] 私塾教师 teacher1.c   60/0   23    10/25
[  6 ] 路边小贩 vendor1.c					不能砍
[ 15 ] 一大群观光旅客        75/0   33    15/33
              visitor2.c
[ 16 ] 皇宫禁军              66/17  52    22/34  黄金盾
	 wiz_bodyguard1.c 			 黄金枪
[ 17 ] 皇宫禁军 城主的贴身待卫      72    30/45  黄金盾
         wiz_bodyguard2.c    98/30		 黄金长矛
[ 18 ] 皇宫禁军队长          86/28  60    30/40  黄金盾
	 wiz_captain1.c 			 黄金长矛
[ 18 ] 京城四大名捕 夏侯忍   65/34  68    33/48  长袖对襟棉袍
	 wiz_captain2.c				 麻纱帽
						 太皓古弋
[ 17 ] 药师 巫姑             55/53  95    27/50  药师护头       aim    
	 wiz_doctor1.c				 药师手套
						 药师诊袍
						 渡劫金针
[ 18 ] 护国师 巫真           75/48  72    28/48  护国师□符□   spells
	 wiz_elder1.c				 护国师□戒
						 护国师□袍
						 混沌□杖
[ 18 ] 武将 巫既             100/11 65	  23/53	 黄金铠甲	special_damage
	wiz_general1.c				 黄金盾 
						 黄金枪
[ 13 ] 城门守卫              56/11 39     19/30  黄金盾
        wiz_guard1.c		                 黄金长矛
[ 14 ] 县役捕快		     68/10 39     19/30  黄金盾
        wiz_guard2.c			         黄金长矛
[ 19 ] 城主 巫罗王          110/65 77     40/75  皇冠          special_damage 						
	wiz_king1.c				 王者披风 
						 王者之戒

						 黄金盾
						 霸王枪
[ 18 ] 文官 巫礼             70/40 65      21/35 金笔          aim g
	wiz_scholar1.c             65      21/35 金笔
				   		 白色官服
						 白练腰带
 


 	     
 
VII. PART １ 武器： /story/palace/weapon/

武器名称    档案名称        武器类别     WC    Damage      特殊攻击

昊天神剑   dragonsword.c    longblade    35    20/40       
神禹令     dragonwand1.c    wand         23    7/22        evil
蒲扇        fan1.c	    blunt        20    15/22
水晶匕首 northgod_dagger.c  dagger       25    14/28
玉如意     queen_weapon.c   blunt        35    10/20
大花剪     scissors.c       shortblade   20    15/22
七彩璇天尺 ruler.c          thrusting    45    30/45       mantel or divine
          ( unique )                                       
青狼锁     chain.c          chain        30    15/23
太乙青霜剑  sword1.c        shortblade   25    15/22
太乙青霜剑  sword2.c        shortblade   28    16/32
三叉□     westgod_fork.c   thrusting    30    18/35

          
VII. PART ２ 防具： /story/wiz/armor/

防具名称      档案名称            型态       质料      AC/DB     特殊效果

浅黄色宫装    f_cloth1.c	  body	     cloth     0/5
白练战裙      gardener_belt.c     leges      cloth     1/2
陆吾之戒      gardener_ring1.c	  finger     elmenet   0/5	  poison:30
								  evil:30
								  divine:-30
							          fire:-50
潜龙符        god_amulet.c	  misc       element   0/5	  
界龙铠甲      god_cloth.c	  body       element   26/5	  
天龙镯        god_gloves.c	  hands	     element   3/3	  
亢龙盔	      god_helmet.c	  head       element   6/2	  
星龙戒	      god_ring.c	  finger     element   0/10 
升龙盾	      god_shield.c	  shield     element   7/5      dex:-7
水晶云肩     northgod_cape.c      cloak      element   6/3	  fire:-20
								  cold:40
水晶铠甲     northgod_cloth.c 	  body	     element   35/8	  
潜于琉璃镜   northgod_shield.c    shield     element   6/8        light
								  cold:-20
龙戒	     northgod_ring.c 	  finger     element   0/5	  
绣丝彩靴     queen_boots.c	  feet	     cloth     6/2	  energy:20
绣丝曳尾云肩 queen_cape.c	  cloak	     cloth     0/10	  
玉胜	     queen_helmet.c       head	     element   6/2	  acid:30
曲盾         goldgod_shield.c     shield   heavy_metal 5/1
白银铠甲     soldier_plate1.c     body	   heavy_metal 27/4	      
白银铠甲     soldier_plate2.c     body     heavy_metal 34/5
白银盾牌     soldier_shield1.c    shield   heavy_metal 7/4
星天衣 	     westgod_cloth.c	  body     heavy_metal 33/5       magic:-20     
						                  mental:25
星天冠       westgod_helmet.c     head     heavy_metal 8/3       divine:10
龙形项□     westgod_necklace.c   misc     heavy_metal 0/5        
	

VII. PART ３ 怪物: /story/wiz/monster  PS * 表主动攻击

   怪物名称        档名      AC/DB  WC   Damage  武器装备       特殊能力

[ 16 ] 应龙     dragon1.c    76/39  53   34/59                  horse
[ 13 ] 天都仙女  f_se1.c     70/5   30   15/27   浅黄色宫装
						 蒲扇
[ 16 ] 後花园管理者 招英     69/32  35   19/32   白练战裙
	        gardener1.c		         大花剪
[ 17 ] 天神 陆吾 gardener2.c 1/6    134  14/22   陆吾之戒
						 神禹令
[ 19 ] 中央天帝 黄帝 king1.c 125/79 80   45/77   星龙戒         magic
						 界龙铠甲       special_damage
						 亢龙盔
						 潜龙符 
						 天龙镯
						 升龙盾 
						 昊天神剑
[ 19 ] 北方天帝 颛顼 	     50/50  82   22/36   水晶匕首 		
             northgod.c  		         龙戒
						 水晶铠甲 
						 水晶云肩
[ 16 ] 火凤凰  phoenix.c     76/39  53   34/59   
[ 19 ] 西王母娘娘 queen1.c   62/44  65   35/60   玉胜           special damage
						 绣丝彩靴		
						 绣丝曳尾云肩
						 玉如意
[ 16 ] 天界神兵 soldier1.c   80/14  35   17/36   白银铠甲
						 太乙青霜剑
[ 19 ] 金神蓐收 goldgod.c    75/53  85  44/66   青狼锁
              ( unique )            75  38/58   曲盾
 						 七彩璇天尺
[ 17 ] 诸天神将 soldier2.c   81/24  40   22/40   白银铠甲
						 白银盾牌
						 太乙青霜剑
[ 19 ] 西方天帝少昊 westgod.c 71/39 50   31/48   星天衣         special_damage
						 星天冠
					         龙形项□
					         三叉□




PS.
     
      关於这区□的怪物，多设为高 level 的，一来不想区域是所谓所有等级

　　　 "皆宜" ，变得没有什麽突显的地方；二来是在进来这里以前，必须经
　　　
　　　过 "镜湖" ( "/d/eastland/legend" ) 那支 "无支祈" 的考验 ( "/d/
     
      eastland/legend/monster/water_mob.c")，寻常 low level 是到不了

      的，於是怪物定会有很多 "大支" 之说，希望诸位考量以上这两点。



                                                     That's all .
                                                     作者 : Dony 於1996




              
	    						


  
