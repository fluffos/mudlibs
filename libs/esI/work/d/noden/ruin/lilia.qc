魔族帝国遗迹

	作者 Lilia (athena@cs.nthu.edu.tw)


I. 故事背景与写作计画

	古代魔族建造了一个庞大的帝国，帝国後来无端地由地面消失，使得文
    明从零开始。文明消失的原因是因为帝国两大法师大对决，引发一场空前的
    灾难，而当初祭司希达曾尝试消弭这个两虎相争的局面，但是并没有成功。

	玩家就是後知後觉的勇者，要取得七个封印打开通往异次元世界的通道
    去见魔族的真神女王 (:p) 得到神奇的力量，当然解救是来不及啦，人都死
    了几千年了。不过自己得到些好处也是不错的 :)

	原始的计画和任务线设计放在 README 以及  quest 这两个档案里，由
    於实际制作的困难，可能会只做给医生公会玩家的奖赏。当然技能要由各公
    会的 arch 认定是否可以加入 :p 任务线以这个档案所描述的为准，原始的
    设计有点过於理想化 :p

	这个 quest 基本设定是  10 级以上的玩家可以不费吹灰之力完成，不
    过我好像有点乐观，目前测试的结果一致认为这个题目太困苦了，所以请各
    位 arch 高抬贵手对 QC 睁只眼闭只眼吧呵呵 *smirk*


II. 任务线设计 (房间存放目录 /u/l/lilia/ruin/room)

	由封印之厅 (sealroom.c) 进入遗迹入口，走过水道□杆迷宫 (en*.c)
    到达帐蓬 (camp.c)，取得魔法字典和密语进入罗斯托丽城 (rose*.c)。路
    上的出口均通向诺顿大陆远风镇外的小河 (11,6.noden.c)。

	罗斯托丽城内有大图书馆 (lib*.c) 及波塔祭坛 (altar.c)，解开大图
    书馆大厅 (lib0.c) 内的接水管谜题可以进入秘室 (lib8.c) 得到纳突尼之
    印。进秘室的提示写在墙上。取得第一印後以後可以直接进入罗斯托丽城外
    的小径，不必再走水道迷宫。 

	接下来到波塔祭坛传送到米拉瓦神殿 (min*.c)，回答大祭司的谜语或是
    将大祭司干掉可以进入神殿内厅。按下蓝红黄三钮可以通过气盾墙，取得巴
    拉斯之印後 pray 即可回罗斯托丽城。 (暗示在风神布莱 bry 三个字上)

	到罗斯托丽城的废墟里找到秘门，把巴拉斯印画在门上，就可以打开秘
    门到依达波第亚城 (eda*.c) 废墟去。进依达波第亚宫，按一下王座上的独
    眼怪的眼睛会掉到放波西凤印的房间里，然後 pray 回罗斯托丽城 (轻松一
    下 :p)。

	再来到深渊去 (abyss*.c)，点完深渊上层的蜡烛之後，到六角形的中心
    去用自己的血启动魔法阵到达冥府。回答□天使的谜题，或是选择把灵魂出
    卖给魔鬼就可以得到弗雷斯之印并回到罗斯托丽城或远风镇 *grin*

	再来进入空中花园 (g*.c)，走过死亡迷宫 (通过的提示是奉女王之圣名
    前进，也就是 ...)，就可以取得海地亚印。这一关比较简单，但是容易死呵
    呵。

	接下来到温柔乡 (wenro*.c) 去，会见著石化的美女雕像 (维纳斯) 及守
    护雕像的骑士卡谬。摘花供在雕像面前才可以亲雕像，如果你坚持要把卡谬干
    掉的话我也不反对，他和雷思差不多强，稍微逊一点。得到希特斯印。

	再来到魔术师塔 (tower*.c)，走完迷宫就可以拿到最後的封印，然後进
    卡榭布兰卡宫 (p*.c) 见女王。Mission Accomplished。魔术师塔的迷宫以乱
    数决定出口，所以理论上每次 update room 之後出口的方位不同。

III. NPC (存放目录 /u/l/lilia/ruin/monster)

1. 考古学家 达特纽斯 (deltazeus.c)
   no_attack npc

2. 大祭司 卡帕 (archbishop.c)
   str 25 int 30 dex 27 con 30 pie 20 kar 25 hp 1000 sp 2700
   aim_difficulty critical 100 weakest 100
   special_defense cold 90 fire 70 all 70 none 80
   spell heal 2 fireball 7
   skill dodge 70 
   法术施放机率 < 0.3
   装备祭司袍、神圣匕首
   装备後 ac 72 db 35 wc 95 dam 45-70

3. 地狱骑士 (deathknight.c)
   str 23 int 21 dex 23 con -- pie 21 kar 22 hp 5000 sp --
   skill dodge 100 longblade 100 parry 100
   killer
   装备死神镰刀
   装备後 ac 80 db 50 wc 113 dam 35-65
   不死之身 (任务用 mob，目的是要给喜欢硬砍的玩家惨痛的教训 *grin*)

4. □天使亚奇芬德 (archfiend.c)
   no_attack npc

5. 吟游诗人纪罗斯 (bard.c)
   str 30 int 30 dex 20 con 25 pie 20 kar 20 hp 1200 sp --
   aim_difficulty critical 80 weakest 80
   special defense all 30 none 30 monk 20 scholar 20
   skill blunt 85 dodge 100
   装备银色长笛，白衣 (死亡大陆那件)
   装备後 ac 40 db 42 wc 69 dam 35-65

6. 圣骑士卡谬 (carmue.c)
   str 30 int 20 dex 25 con 25 pie 30 kar 25 hp 2000 sp --
   aim_difficulty critical 80 weakest 80 vascular 80 ganglion 80
   special defense all 40 none 50
   skill longblade 100 dodge 100 parry 100
   装备铠魔剑
   装备後 ac 157 db 53 wc 97 dam 35-70

7. 鬼魂 (ghost.c)
   no_attack npc

8. 圣骑士杰特 (jitter.c)
   str 30 int 20 dex 25 con 25 pie 30 kar 25 hp 2000 sp --
   aim_difficulty critical 80 weakest 80 vascular 80 ganglion 80
   special defense all 40 none 50
   skill jousting 100 dodge 100 parry 100 block 100
   装备铠魔枪
   装备後 ac 157 db 56 wc 97 dam 35-70

9. 圣骑士亚姆罗列 (emerald.c)
   str 30 int 20 dex 25 con 25 pie 30 kar 25 hp 2000 sp 2000
   aim_difficulty critical 80 weakest 80 vascular 80 ganglion 80
   special defense all 40 none 50
   skill polearm 100 dodge 100 parry 100 longblade 100
   装备众神之怒、诸神的黄昏、钢手套、钢战靴、钢头盔、钢护膝、钢战甲、白色披风
   ( 除第一项外皆为 /d/noden 下已有之装备 )
   装备後 ac 154 db 33 wc1 60 dam 22-35 wc2 25 dam 8-16

10. 女王 (queen.c)
    no_attack npc


IV. 武器 (存放目录 /u/l/lilia/ruin/weapon)

1. 铠魔剑 (sword.c)
   wc 35 longblade dam 20-40 weight 250
   骑士专用，蜥蜴人不能用
   玩家使用时会幻化出一件铠魔甲
   巫师及 npc 使用时会幻化出整套的铠魔甲

2. 神圣匕首 (holy_dagger.c)
   wc 40 dagger dam 25-40 weight 30
   特攻机率 < 0.3
   特攻最大伤害 50，计算公式以双方阵营值差除一千为准，持者阵营为负则反噬，
   反噬的伤害为 random(40)，每次特攻消耗 10 点 spell_points。
   
3. 死神镰刀 (scythe.c)
   wc 42 longblade dam 25-45 weight 150 no_sale no_second
   玩家拿不到，如果拿到就是有 bug。

4. 银色长笛 (flute.c)
   wc 35 blunt dam 10-25 weight 100
   特攻机率 < 0.4
   特攻种类 fire 伤害力 5

5. 铠魔枪 (lance.c)
   wc 35 jousting dam 20-40 weight 250
   骑士专用
   玩家使用时会幻化出一件铠魔甲
   巫师及 npc 使用时会幻化出整套的铠魔甲

6. 众神之怒 (polearm.c)
   wc 50 polearm dam 30-40 weight 245
   需与诸神之黄昏合用 (所以 .... 嘿嘿 .... 啦啦 ....)
   特攻机率目标 15 级以上 33% 9-15 级 40% 9 级以下 80%
   特攻种类 mental 伤害力 15 级以上 120 9-15 级 140 其他 250
   一般人用会折断，折断後
   wc 30 polearm dam 14-28


V. 护具 (存放目录 /u/l/lilia/ruin/armor)

1. 铠魔甲 (plate.c)
   ac 35 db 6 body 骑士公会专用

2. 铠魔盔 (helm.c)
   ac 8 db 3 head 骑士公会专用

3. 铠魔臂 (arms.c)
   ac 4 db 4 arms 骑士公会专用

4. 铠魔手 (hands.c)
   ac 4 db 4 hands 骑士公会专用

5. 铠魔裆 (leggings.c)
   ac 8 db 3 legs 骑士公会专用

6. 铠魔鞋 (feet.c)
   ac 8 db 3 feet 骑士公会专用

7. 祭司袍 (bishop_robe.c)
   ac 22 db 5 body 医生公会专用 weight 80 value 2000 silver

8. 铠魔盾 (shield.c)
   ac 8 db 6 shield 骑士公会专用


VI. 其他物品 (存放目录 /u/l/lilia/ruin/obj)

1. 魔法字典 (dictionary.c)
   任务必备用品，必须向达特纽斯讨取。


VII. 奖赏技能 (存放目录 /u/l/lilia/ruin/cmd)

1. 气盾术 (_amass.c)
   sp -50 extra ac +10 db +(douin level)
   duration pie*3+50
   need skill: concentrate & douin


