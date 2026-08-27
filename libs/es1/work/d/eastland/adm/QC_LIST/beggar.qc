
                      『薪胆村』区域简介(仅就目前已完成做描述)

                      作者：Dony

I.历史背景：

        大约在二百八十年前,中原江湖上各大帮派林立;多馀万人的大帮会少说
    有二、三百个;小如一、两百人的小派门更是不下千个,一时风云涌起袭卷著
    武林的每一个角落。
        然而, 学过经济学的人都知道,在这块有限的土地资源之下,一旦帮派多
    了起来相对的能分配给众人的区域就少了起来。 更由於人类的恶根性---『
    深信著暴力就能够解决一切』的支使之下, 凡是有地盘之争或者彼此理念不
    同或者其它的芝麻小事都能使人大动干伐。若是单纯两派之斗还好,就是有那
    些想趁火打劫,想从中分一杯羹的, 往往引得一派的覆亡累至满门於一夜之间
    悉数消失殆尽。不过总是有人会看不惯因而从中加以调停,调停的结果虽然表
    面上能使之罢斗,但彼此总还会有或多或少的隙缝存在, 甚至有那些不甘於调
    停结果的,往往呼朋引伴其结果是引来更大的斗争。这时, 就有些属於『较大
    』的门派倡议大家选一个武林盟主来领导众人, 颇得江湖中人的支持。但是,
    人人为争那一个盟主席位更是打的头破血流,引来的却是另一场更大的血腥。
    出乎意料的是,武林盟主却能够带来江湖上数十年的安宁, 想必是人类天生的
    努役性驱使吧!数十年之後,武学日式衰微,江湖上再也找不到一个足以担当武
    林盟主之位的人,於是,干戈大起,引发了一场更大的浩劫。   
        这时正值异族入侵,朝廷正苦於无法把整个中原势力纳入统治之中, 更乐
    於那些武人自相残杀,但为保千秋大业, 把整个帮会势力给连根拔起是免不了
    的。於是,朝廷计划筹谋,正当布置好了所有准备,但恰逢武林盟主相安後的数
    十年,却告作废。无奈数十年之後,武林自斗并且给了朝廷一个最大的机会,朝
    廷也知道这个良机一踪即失,遂派遗鹰门爪牙逐一铲除各大帮派。出手不外乎
    是威胁利诱,如有顺从归顺那是最好不过,不服就连根给拔起, 手段极其狠毒,
    仅仅几个月之间,各大帮派已十之去九,这时武林像一盘散沙,又有那一个派门
    抵挡得了呢?
        位天下第一大帮的丐帮在面临朝廷这波的攻击之下,不免也有些狠狈, 更
    何况在异族还未入侵之前,丐帮处处在反著;入关之後,丐帮又到处滋扰生事,
    种种举动早已被朝廷视为眼中钉,背後的芒刺。丐帮在朝廷的一场决战里,自八
    袋弟子已上,悉部阵亡,所幸一名七袋见得快,得以保住帮中重要的物事,更忧於
    朝廷防不胜防的攻势,无奈只好退居到一处隐密之处,俟机复帮, 并把所在之地
    命名为『薪胆村』取'卧薪尝胆'之意....... 
                                                            前事完           

                               ps 没想到我还真会掰

II.商店：
       
       I). 买卖 eq ( /u/d/dony/beggar/store.c)
       II).药铺    ( /u/d/dony/beggar/hospital1.c)
       III).赌坊   ( /u/d/dony/beggar/game_room.c)
      
III.任务概要：

       I). 帮忙帮主找回打狗棒



IV.怪物 : /u/d/dony/monster

   怪物名称    档名    等级 AC/DB  WC  伤害范围  武器装备    特殊能力    

丐帮帮主 乔峰 master.c  19  56/83  115  51/73    束云戒指    1.解 quest 
                                                 束云头带    2.打落别人
                                                 束云腰带      武器
                                                 束云白袍    3.火系伤害 

囚犯 不知名  prisoner.c 19  55/57  104  41/62    阿修罗之戒  1.block_command
         ( ch_prisoner.c  19  70/70  125  46/82 )            2.让人混乱
                                                          (  3.火系攻击
                                                             4.冰系攻击
                                                             5.让人迟缓 )
                                                    
祠堂老院长 old_garden.c 19  80/0   70   30/55    破扫帚      1.解 quest
                                                 元气玉      2.反弹攻击

江湖术士 神算小瓜 
           soothsayer.c 19  76/55  94  37/62    诛仙剑      1.summon mob
                                                风火雷电七星袍 

陷仙剑[发狂状态] kill1.c 19 110/50 75  36/72

绝仙剑[发狂状态] kill2.c 19 110/50 75  36/72 

戮仙剑[发狂状态] kill3.c 19 110/50 75  36/72
                               
画中仙          spirit.c 19 68/67  96  30/76    绝龙牌
                                   70  27/73    冰魄银针 
                                                打神鞭

东瀛武士 黑月 fighter.c 18  45/34  72  45/48    螺旋刃      1.解 quest
                                                 黑色紧身衣  2.邪恶系伤
                                                               害
                                                             3.一般的特
                                                               殊攻击

一代神医 小雪子 uki.c   17  55/58  84   28/43    小小银针    1.解 quest
                                                 医者护符    2.瞄 weakest      
                                                 医者之袍         critical
                                                                  vascular    
                                          ps #2 12/6 改 aim
                                                                    
巧匠 冯阿三 blackmaster.c 17 63/50 70   40/58    倚天剑      1.解 quest
                                                 火云护臂    2.书生解完 
                                                 冰晶盾        quest 後
                                                               给聚剑术

谜样剑客 风飞雪         17  48/71  81   30/50    七星剑      1.冰系伤害  
        occult_swordman.c                        至阳头带    2.神圣伤害
                                                 元阴斗蓬    3.邪恶系伤害  
                                                 陷阱

执法长老 白世镜         17  52/55  57   21/36    判官笔      1.解 quest 
        law_master.c               53   21/36    判官笔
                                                 白纶巾 

天山二老 天鹭 couple1.c 17  45/42  59   26/47    黑披风      1.解 quest
                                                             2.毒系伤害
                                                             3.和天鸠一
                                                               同攻击敌人

监牢守卫 jail_guard.c   17  85/34  65   32/40    竹棒       
 
全副帮主的女儿 月读     16  62/56  64   30/48    七宝金幢    1.解 quest
        unary.c                                  七彩云衣    2.会 forget 
                                                 七彩云靴    3.aim weakest
                                                 七彩云套

项长老  gonfu_master.c  16  30/23  50   24/45    竹棒        1.解 quest
                                                 鸠衣        2.会 block 人
                                                             3.打落武器

祠堂执事僧 enforcer.c   16  70/18  30   18/33    执事者之袍
                                                 破扫帚
                   
大笨驴     donkey.c     16  79/40  53   41/66                1.骑士可以骑 
                                                             2.会保护主人

天山二老 天鸠 couple2.c 15  40/20  49   18/36    黑披风      1.会 block 人
                                                             2.和天鹭一同
                                                               攻击敌人

太行山冲霄洞 谭公
         tan_male.c     15  40/46  59   26/47    冲霄云戒    1.会 healing
                                                 小盒子        group
                                                             2.和谭婆一同
                                                               攻击敌人  
    
太行山冲霄洞 谭婆
         tan_female.c   15  40/46  59   26/47    冲霄云戒    1.一般特殊攻
                                                 小盒子        击
                                                             2.和谭公一同
                                                               攻击敌人 

赵钱孙   chau.c         15  80/59  65   24/39    暖衣        1.招唤 donkey
                                                               攻击   

丐帮 七袋弟子 seventh.c 14  75/40  48   19/26    

丐帮 六袋弟子 sixth.c   13  50/35  46   14/24       

 
小侍童        servant.c 12  55/20  25   16/23    骨刀

丐帮 五袋弟子 fifth.c   11  45/10  28   14/21 

庄稼汉 阿土仔 ahtu.c    7   55/20  26   11/23                1.exp 1150

丐帮 二袋弟子 second.c  7   15/10  24   11/19

大公鸡   big_chicken.c  6   30/0   4    1/4

甲虫          beetle.c  5   5/1    9    3/7

母公鸡 mother_chicken.c 4   10/0   3    1/3

小公鸡 little_chicken.c 2   5/0    3    1/3

全冠清         chan.c   1   5/2    3    1/3                   1.解 quest
                                                              2.healing 
                                                                himself       

倒在桌上的醉汉 chan_master.c                                  1.解 quest
                                                              2.cant attack

帐房 霍先生   keeper.c                                        1.解 quest
                                                              2.cant attack 


V.武器： /u/d/dony/weapon

武器名称    档案名称      武器类别     WC   伤害范围     特殊攻击

小小银针    needle.c      dagger       45    23/36       divine
风月魔刀    evil_glaive.c longblade    45    30/50       evil
七宝金幢    seven_blunt.c blunt        35    15/38       divine
名刀 七星剑 seven_sword.c shortblade   40  int/(int+10)  sleet
诛仙剑 god_killed_sword4.c shortblade  42    27/47
陷仙剑      kill1.c       longblade    47    27/50       bleeding
                                                         block 4
绝仙剑      kill2.c       longblade    45    27/50       bleeding
                                                         sleet
戮仙剑      kill3.c       longblade    48    27/50       bleeding
冰魄银针    ice_needle.c  dagger       40    25/40       anatomlogy 10
打神鞭   flog_god_whip.c  whip         40    25/40       divine
倚天剑      sky_sword.c   longblade    35    20/40       sleet
螺旋刃      katana.c      longblade    35    20/35       bleeding
灵气剑     spirit_sword.c longblade    25    18/28       隔一段时间会不见 
骨刀        blade.c       longblade    15    13/18       bleeding
判官笔      pen.c         thrusting    37    20/35     
竹棒        blunt.c       blunt        20    12/20
破扫帚      broom.c       blunt        30    15/30



VI.防具： /u/d/dony/armor

防具名称     档案名称      型态     质料      AC/DB     特殊效果

束云白袍   wind_cloth.c    body     cloth     32/9      fire:-20
                                                        cold:10
束云头带   wind_helmet.c   head     cloth     7/3       
束云戒指   wind_ring.c     finger   element   0/8
束云腰带   wind_belt.c     legs     cloth     7/3
阿修之戒   fighter_ring.c  finger   cloth     0/7       evil:5  
          (fighter_ring1.c)                  (0/10)     evil:10 
鸠衣       broken_cloth.c  body     cloth     10/3      fire:-10
暖衣       chau_cloth.c    body     cloth     15/4      fire:5
                                                        cold:5
绝龙牌     dragon_shield   shield   cloth     8/7
黑披风     couple_cloak.c  cloak    leather   5/2       poison:10
执事者之袍 enforcer_robe.c body     cloth     10/3    
火云护臂   fire_armband.c  arms     element   1/5
元阴斗蓬   fun_cloak.c     cloak    cloth     4/9       cold:5
至阳头带   fun_turban.c    head     cloth     4/5       fire:5
黑色紧身衣 japan_cloth.c   body     thief     15/9      evil:15
                                                        divine:-20
冰晶盾     orb_shield.c    shield   element   2/10      light 
风火雷电七星袍
       soothsayer_cloth.c  body     cloth     36/10     all:10
破马鞍     saddle.c        saddle   leather   3/1
七彩云靴   seven_boots.c   feet     leather   1/5
七彩云衣   seven_cloth.c   body     cloth     26/7
七彩云套   seven_gloves.c  hands    cloth     0/4       pie:-2
                                                        int:2
                                                        con:-2
                                                        str:-1
冲霄云指   tan_ring.c      finger   element   0/6
白纶巾     turban.c        head     cloth     7/5       fire:-10
医者护符   uki_amulet.c    misc     element   0/8       
医者之袍   uki_cloth.c     body     healer    15/10     fire:-10
                                                        poison:15
                                                        acid:10

                           
VII.其他物品：/u/d/dony/item
  
       物品名称       档名            用途
 
       舍利子       ball.c            加全部 skill 5% , 要花 fp 80 或 int 100
       复元术       heal_spell.c      可以恢复部分的状态
       舒跑五十     super_supra.c     加 ap 500
       小盒子       box.c             可以当 bag 用
       家书         chan_letter.c     quest 用
       打狗棒       dog_blunt.c       quest 用
       铜钥匙       key.c             开 room jail1.c 用
       信件         letter.c          quest 用
       元气玉       life_ball.c       『血库』,请看 life_ball.c 的内容
       手论         password.c        quest 用
    天山九转熊蛇丸  pill.c            quest 用
       聚剑术       spell.c           可以 clone 灵气剑 (给书生用) 
       六阳正气丹   sun_pill.c        quest 用
       治伤灵药     tan_plaster.c     和 plaster 一样,只不过一次恢复 8 hp
       陷阱材料     trap.c            可以使玩家 blockcommand 2 分钟       

