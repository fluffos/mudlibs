//for ask npc about here,Zine
#include <ansi.h>

mapping *cities = ({
            ([  "id":"yangzhou","name":"扬州","big_area":"中原平原","job_desc":"这里有慕容复、多尔衮和史可法正在找人帮忙做任务。","quest_desc":"这里的谜题极多，包含易容术、过劫难、捐福源、修兵器、宝石库等等。","family_desc":"这里的门派有丐帮（东门向北）、慕容（茶馆）。","author":"zine"]),
            ([  "id":"wudang","name":"武当山","big_area":"中原平原","job_desc":"这里有冲虚、俞莲舟和崔老汉（山脚下村子里面）正在找人帮忙做任务，宋远桥会给你发例银。","quest_desc":"这里的谜题极多，包含静修阁悟道、天柱峰采气、校场演练阵法、炼丹、龟泉、桃园决义谷、山洞中诡秘尸体、龟蛇相斗等等。","family_desc":"这里的门派有武当派。","author":"静电清水 yhzzyahoo"]),
            ([  "id":"xiangyang","name":"襄阳","big_area":"中原平原","job_desc":"这里有郭靖正在找人帮忙做任务（保卫襄阳）或者捐助物资（获取道德）。","quest_desc":"这里的谜题极多，包含射雕英雄传、白雕、掌法秘籍、九转熊胆丸、黑松寨藏宝等等。","family_desc":"这里的门派有武馆（搬家后成立）。","author":"静电清水 yhzzyahoo"]),
            ([  "id":"xiangyangnan","name":"荆州","big_area":"中原平原","job_desc":"这里没有什么任务。","quest_desc":"这里的谜题包括杀山贼、华容道等等。","family_desc":"这里没有门派。","author":"zine"]),
            ([  "id":"beijing","name":"北京","big_area":"北方平原","job_desc":"这里有多隆、康亲王和胡一刀(在郊区)正在找人帮忙做任务。","quest_desc":"这里的谜题极多，包含鳌拜家、慈宁宫太后处、独臂神尼、天地会分舵、双儿、宗人府、对诗、韦爵爷家、等等。","family_desc":"这里的门派有朝廷、天地会。","author":"hash"]),
            ([  "id":"huanghebei","name":"黄河北岸","big_area":"北方平原","job_desc":"这里没有任务，小孩闲得没事可以找个地方钓鱼。可以花钱请艄公搭你过河，也可以等免费的慢船。","quest_desc":"这里的没有谜题，另外邪恶的天神经常让江河决堤。","family_desc":"这里没有门派。","author":"hash"]),
            ([  "id":"huanghenan","name":"黄河南岸","big_area":"中原平原","job_desc":"这里没有任务，小孩闲得没事可以找个地方钓鱼。可以花钱请艄公搭你过河，也可以等免费的慢船。","quest_desc":"据说有人发现燕青和李师师在黄河入海口出现过，另外邪恶的天神经常让江河决堤。","family_desc":"这里没有门派。","author":"hash"]),
            ([  "id":"changjiangbei","name":"长江北岸","big_area":"中原平原","job_desc":"这里没有任务，小孩闲得没事可以找个地方钓鱼。可以花钱请艄公搭你过河，也可以等免费的慢船。","quest_desc":"这里的没有谜题，另外邪恶的天神经常让江河决堤。","family_desc":"这里没有门派。","author":"hash"]),
            ([  "id":"changjiangnan","name":"长江","big_area":"江南平原","job_desc":"这里没有任务，小孩闲得没事可以找个地方钓鱼。可以花钱请艄公搭你过河，也可以等免费的慢船。","quest_desc":"这里的没有谜题，另外邪恶的天神经常让江河决堤。","family_desc":"这里没有门派。","author":"hash"]),
            ([  "id":"luoyang","name":"洛阳","big_area":"中原平原","job_desc":"这里有萧峰、陈近南、鹿杖客、南海神尼正在找人帮忙做任务，陈近南会给天地会会众发经费。","quest_desc":"这里的谜题不少，包含铁匠job、任盈盈夫妻团聚、武门比武，在镖局门口还可以买到武林秘籍等等。","family_desc":"这里的门派有天地会。","author":"静电清水 yhzzyahoo"]),
            ([  "id":"lingzhou","name":"灵州","big_area":"西北地区","job_desc":"这里没什么人找人做任务，偏僻的紧，从西边过去能到黄河南岸，过河是明教。","quest_desc":"这里的谜题不多，包含天龙八部解密等等。","family_desc":"这里没有门派。","author":"静电清水 yhzzyahoo"]),
            ([  "id":"suzhou","name":"苏州","big_area":"江南平原","job_desc":"这里有管事、老夫子正在找人帮忙做任务。","quest_desc":"这里的谜题不多，包含大明秘密情报站，七星海棠等等。","family_desc":"这里没有门派。","author":"静电清水 yhzzyahoo"]),
            ([  "id":"jiaxing","name":"嘉兴","big_area":"江南平原","job_desc":"这里有韩宝驹正在找人帮忙做任务。","quest_desc":"这里的谜题不多，包含玄铁剑，怒涛练剑，解密欧阳锋等等。","family_desc":"这里没有门派。","author":"静电清水 yhzzyahoo"]),
            ([  "id":"quanzhou","name":"泉州","big_area":"江南平原","job_desc":"这里没什么人找人做任务。","quest_desc":"这里的谜题不多，包含上侠客岛喝粥等。","family_desc":"这里没有门派。","author":"静电清水 yhzzyahoo"]),
            ([  "id":"lingjiu","name":"灵鹫","big_area":"西北地区","job_desc":"石嫂正在募集人手以御外敌。灵鹫本门可以找石嫂和余婆婆要任务。","quest_desc":"这里的谜题不多，饿了可以上树找松果吃，虚竹想找他的梦中姑娘。假山下面有密道。","family_desc":"北面就是灵鹫宫了。","author":"depct"]),
            ([  "id":"xiaocun","name":"小山村","big_area":"中原平原","job_desc":"这里没人找人做任务。","quest_desc":"这里的谜题不少，烧红的铁锤，华山剑谱，李铁嘴知道不少秘密，还有个水平很差的职业杀手住在这里等待雇佣。","family_desc":"这里没有门派。","author":"hash"]),
            ([  "id":"shashoubang","name":"杀手帮","big_area":"江南平原","job_desc":"梁总管和楚云飞在招募杀手。","quest_desc":"这里的谜题有杀手任务，妓院的姑良知道后山的秘密。","family_desc":"这里没有门派。","author":"hash"]),
            ([  "id":"jinyang","name":"晋阳","big_area":"北方平原","job_desc":"这里有萧半和正在找人做任务。","quest_desc":"这里的谜题不多，包含洗经伐髓等等。","family_desc":"这里没有门派。","author":"静电清水 yhzzyahoo"]),
            ([  "id":"minnan","name":"福州","big_area":"江南平原","job_desc":"这里有林震南正在找人做任务。","quest_desc":"这里的谜题不多，包含护镖、辟邪剑法等等。","family_desc":"这里没有门派。","author":"luopan"]),
            ([  "id":"yuewangmu","name":"岳王墓","big_area":"江南平原","job_desc":"这里有没有人找帮手做任务。","quest_desc":"这里的谜题较多，包含盗墓、凭吊（加道德）、紧身宝甲等等。","family_desc":"这里没有门派。","author":"luopan"]),
            ([  "id":"zhangjiakou","name":"张家口","big_area":"北方平原","job_desc":"这里没有人找人帮忙。","quest_desc":"绝情谷据说就在不远的地方。","family_desc":"这里的没有门派。","author":"hash"]),
            ([  "id":"pingxi","name":"平西王府","big_area":"西南地区","job_desc":"这里没有人找人帮忙。","quest_desc":"这里的谜题有密室和英雄剑。","family_desc":"这里的没有门派。","author":"hash"]),
            ([  "id":"qufu","name":"曲阜","big_area":"中原平原","job_desc":"这里没有什么任务。","quest_desc":"向孔子像祭拜，对读书很有好处。孔翘好像知道燕青的事。","family_desc":"文人墨客皆聚于此，却没有什么武林门派。","author":"depct"]),
            ([  "id":"wuliang","name":"无量山","big_area":"山地","job_desc":"这里没有人找人帮忙。","quest_desc":"这里的谜题极多，包含无量玉壁，游侠宝剑，石门后的琅缳福地，北冥神功图谱，残局等。","family_desc":"这里的门派有琅缳福地中的天龙寺武学宗师段誉偕夫人王语嫣。","author":"depct"]),
            ([  "id":"xingxiu","name":"星宿","big_area":"西北地区","job_desc":"阿紫妹子和飘然子在找人帮忙。","quest_desc":"这里的谜题极多，包含炼毒，蒙汗药，冰魄杖，星宿毒经，天山器法，天山雪莲，伊犁马，阿凡提等。","family_desc":"这里的门派有星宿派。","author":"hash"]),
            ([  "id":"taishan","name":"泰山","big_area":"山地","job_desc":"这里没人在找人帮忙。","quest_desc":"这里的谜题不多，可以抢武林盟主，参观小毛家等。","family_desc":"这里没有门派。","author":"hash"]),
            ([  "id":"shaolin","name":"少林寺","big_area":"山地","job_desc":"这里道果禅师、玄惠大师和黄眉僧在找人帮忙。","quest_desc":"这里的谜题太多了，有伏魔圈，五行洞，达摩老祖，面壁，藏经阁小屋，慕容博，洪荒古洞，无名老僧，十八罗汉阵，参禅，藏经阁，大小还丹，虚劫与药性，跳楼/走竹林，太多不写了。","family_desc":"这里有少林派和姑苏慕容的慕容博。","author":"hash"]),
            ([  "id":"emeihoushan","name":"峨眉后山","big_area":"山地","job_desc":"这里没人在找人帮忙。","quest_desc":"这里的谜题不多，有倚天剑，金顶，硫磺，草药 人参","family_desc":"这里有峨眉派。","author":"hash"]),
            ([  "id":"meizhuang","name":"江南梅庄","big_area":"江南平原","job_desc":"这里没人在找人帮忙。","quest_desc":"这里的谜题不多，有四宝，判官笔法，任我行与吸星大法","family_desc":"这里有日月前教主任我行。","author":"hash"]),
            ([  "id":"mingjiao","name":"明教","big_area":"西北地区","job_desc":"这里有张无忌、杨逍、唐洋正在找人帮忙做任务。","quest_desc":"这里的谜题不多，包含大沙漠、天竺梵语、乾坤大挪移、圣火令等。","family_desc":"这里的门派有明教、丐帮（草棚密室）。","author":"alucar"]),
            ([  "id":"kangqinwang","name":"康亲王府","big_area":"北方平原","job_desc":"这里有康亲王正在找人帮忙做任务。","quest_desc":"这里的谜题很少，包含四十二章经（正红）等。","family_desc":"这里的门派有朝廷。","author":"alucar"]),
            ([  "id":"tiantan","name":"天坛","big_area":"北方平原","job_desc":"这里没有人需要帮忙。","quest_desc":"这里没有谜题。","family_desc":"这里是朝廷的势力范围，经常有巡逻的官员路过，守门的锦衣卫比较厉害。","author":"alucar"]),
            ([  "id":"zijincheng","name":"紫禁城","big_area":"北方平原","job_desc":"这里有康熙在找四十二章经。","quest_desc":"这里的谜题很少，包含四十二章经（正黄、镶红、镶白、镶蓝），雪参玉蟾丹，朝廷升一品等。","family_desc":"这里的门派有朝廷。","author":"alucar"]),
            ([  "id":"baituo","name":"白驼山","big_area":"西北地区","job_desc":"这里有欧阳克、管家正在找人帮忙做任务。","quest_desc":"这里的谜题很多，包含培养怪蛇、蛇谷、大沙漠、密道、配药、捉蛐蛐、储藏室等等。","family_desc":"这里的门派有白驼。","author":"alucar"]),
            ([  "id":"riyue","name":"日月神教","big_area":"北方平原","job_desc":"这里有向问天、厨师、看守竹篓的弟子、紫衫使者和狱卒正在找人帮忙做任务。","quest_desc":"这里的谜题极多，包含见东方不败、救任我行、黑木令、日月刀剑、笑傲江湖曲谱、华山奸细、大光明心法、三尸脑神丹及解药等。","family_desc":"这里的门派有日月神教。","author":"alucar"]),
            ([  "id":"shenlong","name":"神龙岛","big_area":"海岛","job_desc":"海边小屋的沐剑屏正在找人帮忙做任务。","quest_desc":"这里的谜题很多，包含英雄三招、美人三招、毒龙鞭、雄黄酒、地道、古刺客秘笈、升天丸、山泉洗澡等。","family_desc":"这里的门派有神龙。","author":"alucar"]),
            ([  "id":"changan","name":"长安","big_area":"西北地区","job_desc":"朱雀街广场的游方和尚在找人做任务，也会帮人找亲戚。","quest_desc":"这里暂时没有谜题，但有北侠唯一的物品代售场所榷场，以及鉴定和保存古董的古董店。","family_desc":"这里没有门派。","author":"alucar"]),
            ([  "id":"qilingcun","name":"麒麟村","big_area":"中原平原","job_desc":"这里没有什么可做的任务。","quest_desc":"这里的谜题不多，包含土匪迷宫、仙丹、沥泉灵等。","family_desc":"这里没有门派。","author":"alucar"]),
            ([  "id":"gumu","name":"古墓","big_area":"山地","job_desc":"这里有小龙女、陆无双正在找人帮忙做任务。","quest_desc":"这里的谜题极多，包含进出古墓、寒玉床、地下河、密室、机关、君子剑、淑女剑、玉女心经、九阴真经等、素心剑法。","family_desc":"这里的门派有古墓。","author":"alucar"]),
            ([  "id":"quanzhen","name":"全真","big_area":"山地","job_desc":"这里有王重阳、程遥伽、杂役道人正在找人帮忙做任务。","quest_desc":"这里的谜题较多，包含蜂王蜜、天香断玉膏、一灯解谜、三花聚顶掌、空明拳左右互搏等。","family_desc":"这里的门派有全真教。","author":"alucar"]),
            ([  "id":"huashan","name":"华山","big_area":"山地","job_desc":"这里有岳不群、宁中则、梁发、岳灵珊正在找人帮忙做任务。","quest_desc":"这里的谜题极多，包含天外飞龙、思过崖、比武大会、华山论剑、金蛇山洞、游龙剑、碧水剑、风清扬等。","family_desc":"这里的门派有华山派。","author":"alucar"]),
            ([  "id":"zhongyuan","name":"中原","big_area":"中原平原","job_desc":"这里没有什么任务，但四通八达，是交通要道。","quest_desc":"这里谜题极少，要找霍都的话可以去南阳看看。","family_desc":"这里的门派有丐帮（何师我）。","author":"alucar"]),
            ([  "id":"xinyang","name":"信阳","big_area":"中原平原","job_desc":"这里没有什么任务。","quest_desc":"这里没有谜题，闲时可以去南湾湖钓钓鱼，也可以去汤泉池泡个澡。","family_desc":"这里没有门派","author":"alucar"]),
            ([  "id":"gaibang","name":"丐帮","big_area":"中原平原","job_desc":"这里有左全、彭有敬、鲁有脚正在找人帮忙做任务。","quest_desc":"这里的谜题很多，包含棒法秘籍、青竹林、升袋、暗道、雷霆降龙、打狗棒绝招等。","family_desc":"这里是丐帮的根据地。","author":"alucar"]),
            ([  "id":"lingxiao","name":"凌霄城","big_area":"西北地区","job_desc":"这里有李万山、花万紫正在找人帮忙做任务。","quest_desc":"这里的谜题较多，据说有白虹剑、静修室、雪山双宝、金乌刀法、吊桥、松林谜宫等，背太多东西的时候千万不要过一线索。","family_desc":"这里的门派有雪山派，多行不义者难以入城。","author":"alucar"]),
            ([  "id":"dalunsi","name":"大轮寺","big_area":"西南地区","job_desc":"这里有黑林钵夫正在找人帮忙做任务。","quest_desc":"这里的谜题极多，包含上山绞盘、春宫图、血刀秘籍、血刀老祖、藏红花、雪莲子、血菩提、敲钟、击鼓、抄经、禅定、冥想等。","family_desc":"这里的门派有西域大轮寺密宗。","author":"alucar"]),
            ([  "id":"yueyang","name":"岳阳","big_area":"西南地区","job_desc":"这里没有什么任务。","quest_desc":"这里的谜题很少，从洞庭湖边可以去君山游览，李保长家是江南八镇解谜任务的一站。","family_desc":"这里没有门派。","author":"alucar"]),
            ([  "id":"yingtiannorth","name":"建康府北城","big_area":"江南平原","job_desc":"这里有清凉寺地宫可能有任务给出。","quest_desc":"这里是江南八镇解谜的终点，存义街的无名氏对兵器使用有不少心得，据说还与浑天仪有关。","family_desc":"这里没有门派，但有不少江湖人士在此为官。","author":"alucar"]),
            ([  "id":"yingtiansouth","name":"建康府南城","big_area":"江南平原","job_desc":"这里有孟之经给出刺杀任务，陆世清新开了一家镖局。","quest_desc":"这里的谜题不详。","family_desc":"这里没有门派，但有不少江湖人士在此为官。","author":"alucar"]),
			([  "id":"zhenjiang","name":"镇江","big_area":"江南平原","job_desc":"这里没有什么任务。","quest_desc":"这里是江南八镇解谜任务的一站，金山寺的老和尚似乎知道些什么。此外，据传义兴县有三害为祸乡里，期待大侠前去降龙伏虎。","family_desc":"这里没有门派。","author":"alucar"]),
            ([  "id":"chengdu","name":"成都","big_area":"西南地区","job_desc":"这里没有什么任务。","quest_desc":"这里是江南八镇解谜任务的起点，去老唐家问问应该会有一些线索。民间流传燕青曾在此留下一册拳谱。","family_desc":"这里没有门派。","author":"alucar"]),
            ([  "id":"taoyuan","name":"桃源","big_area":"西南地区","job_desc":"这里没有什么任务。","quest_desc":"这里的谜题与南帝段王爷有关，但要见他很不容易，穿过黑沼可以见到曾经的王妃瑛姑。","family_desc":"这里没有门派，铁掌帮常在此出没打劫过往镖队。","author":"alucar"]),
            ([  "id":"miaojiang","name":"苗疆","big_area":"西南地区","job_desc":"这里没有什么任务。","quest_desc":"这里是江南八镇解谜任务的一站，但苗岭中瘴气漫溢，冒然进入将有去无回。","family_desc":"这里没有门派。","author":"alucar"]),
            ([  "id":"guiyun","name":"归云庄","big_area":"江南平原","job_desc":"这里有曲灵风和陆乘风正在找人帮忙做任务。","quest_desc":"这里的谜题极多，包含桃药岛内功、桃花林、池塘、兰花扶穴手秘诀、御马靴、疾风靴、七星剑、金轮铠甲、天仙玉露、铁八卦、含羞草、女娲石等。","family_desc":"这里的门派有桃花岛。","author":"alucar"]),
            ([  "id":"tianlong","name":"天龙寺","big_area":"山地","job_desc":"这里有本尘大师、本相大师正在找人帮忙做任务。","quest_desc":"这里的谜题很少，寺中藏有六脉神剑剑谱，更高深的武学就要去无量山中探寻。","family_desc":"这里的门派有天龙寺。","author":"alucar"]),
            ([  "id":"murong","name":"姑苏慕容","big_area":"江南平原","job_desc":"琴韵小居的阿碧姑娘正在找人帮忙做任务，燕子坞的书生在文学方面颇有造诣。","quest_desc":"这里的谜题极多，包含划船、踩桩、摘莲蓬、打猎、斗转星移图谱、慕容博、观星、曼陀山庄、琅镮福地（雁翎刀）、听香剑、各种花露等。","family_desc":"这里的门派有姑苏慕容。","author":"alucar"]),
            ([  "id":"taohua","name":"桃花岛","big_area":"海岛","job_desc":"这里没有什么任务。","quest_desc":"这里的谜题很多，包含左右互搏、天王保命丹、田七沙胆散、无常丹、软猬甲、叫化鸡、落英神剑掌、易容术等。","family_desc":"这里的门派有桃花岛。","author":"alucar"]),
            ([  "id":"emei","name":"峨嵋","big_area":"西南地区","job_desc":"这里有静和师太、静心师太正在找人帮忙做任务。","quest_desc":"这里的谜题很多，包含蛇窟、洗象池、凤凰台、宋青书配剑、峨嵋令、灭剑绝技等。","family_desc":"这里的门派有峨眉派。","author":"alucar"]),
            ([  "id":"yashan","name":"牙山","big_area":"江南平原","job_desc":"每逢单日12点、双日21点可以在这里参加甲午海战任务。","quest_desc":"这里少有人来，但听说有洋人在此贩卖军火，清兵们则人手一份军舰操作指南。","family_desc":"这里没有门派，但最近有不少雪山弟子在此出现，据说是白老先生派来打鬼子的。","author":"alucar"]),
            ([  "id":"nanchang","name":"南昌","big_area":"江南平原","job_desc":"这里是江南八镇解谜任务的一站，听说老白正在找人帮忙干活。","quest_desc":"这里的谜题不多，包含大擒拿手、老林迷宫、山寨打虎等。","family_desc":"这里没有门派，但常有大明官员在此打听宁王的情况。","author":"alucar"]),
            ([  "id":"dali","name":"大理城中","big_area":"西南地区","job_desc":"这里没有什么任务。","quest_desc":"目前这里的谜题极少，大理王府的承光壁上似乎常有人攀爬的痕迹。","family_desc":"这里暂时没有门派，据说大理段家曾打算开宗立派并扩建大理城，但不知什么原因一直没有动工。","author":"alucar"]),
            ([  "id":"hangzhou","name":"临安府","big_area":"江南平原","job_desc":"这里没有什么任务，但店铺很多，可以修理兵器、存放宝石等，常有镖师在此落脚休整。","quest_desc":"这里的谜题很少但比较复杂，红华会四当家据说被囚禁在提督府内，清兵们常在酒家吹嘘抓捕过程，西湖边的小院需要暗号才能进入。","family_desc":"这里的门派有红花会，但暂时没有扩招弟子的打算。","author":"alucar"]),
            ([  "id":"kunming","name":"昆明","big_area":"西南地区","job_desc":"这里没有什么任务。","quest_desc":"这里是江南八镇解谜任务的一站，镖局的张崇威似乎欠了平西王府总管一些银子，城郊可以采到茯苓、鸡血藤等中草药材。","family_desc":"这里没有门派","author":"alucar"]),
            ([  "id":"jiangzhou","name":"江州","big_area":"江南平原","job_desc":"这里有韩元外和钓鱼人在找人帮忙。","quest_desc":"这里是江南八镇解谜任务的一站，韩员外会铁琵琶手不过不轻易外传，钓鱼人旁边的树和石头可以看看，温峤府上据说在闹鬼。","family_desc":"这里没有门派。","author":"alucar"]),
            ([  "id":"sichou","name":"丝绸之路","big_area":"西北地区","job_desc":"这里没有什么任务。","quest_desc":"这里是莫高窟遗址，另外，据说这里藏着黄沙万里鞭法的秘密。","family_desc":"这里没有门派。","author":"zine"]),
            });
mapping *undefined_cities = ({
                  ([  "path":"/d/bhdao/","name":"冰火岛","big_area":"海岛","job_desc":"这里没有人找帮手做任务。","quest_desc":"这里的谜题有 烤鹿肉 七伤拳 屠龙刀。","family_desc":"这里没有门派。","author":"hash"]),
                  ([  "path":"/d/diaoyudao/","name":"钓鱼岛","big_area":"海岛","job_desc":"这里没人找人做任务。","quest_desc":"这里有不少鬼子，可以杀鬼子头目有赏。可以帮助渔夫，寻找财宝，可以去找护体软甲，可以树林找史小翠学刀法，也可以安安静静钓鱼。","family_desc":"这里没有门派。","author":"depct"]),
                  ([  "path":"/d/xiakedao/","name":"侠客岛","big_area":"海岛","job_desc":"这里没人找人做任务。","quest_desc":"这里可以学习很多武功。","family_desc":"这里没有门派。","author":"zine"]),
                  ([  "path":"/d/ruyang-wangfu/","name":"汝阳王府","big_area":"中原平原","job_desc":"这里暂时没有任务。","quest_desc":"这里的谜题较少，可以尝试从后门翻进王府，但不要冒然去西卧房，否则一旦落入水牢就难以脱身了。","family_desc":"这里没有门派。","author":"alucar"]),
                  ([  "path":"/d/jiaofei/","name":"铁掌山","big_area":"山地","job_desc":"每周六晚9点可以在这里参加剿匪任务，裘千丈最近逛到扬子津附近找人干活去了。","quest_desc":"这里的谜题都与剿匪任务有关，包括大沼泽、阻援、卧底、灭火、五仙大补酒、震天雷、防穹硬甲、天魔秘籍等。","family_desc":"这里没有门派。","author":"alucar"]),
                  ([  "path":"/d/xinfang/","name":"玩家别墅区","job_desc":"这里没有任务。","quest_desc":"这里没有谜题。","family_desc":"这里没有门派。","author":"zine"]),
                  ([  "path":"/d/wizard/zine/","name":"铜雀台","job_desc":"这里的铜雀台榜上有任务可以揭。","quest_desc":"这里没有谜题。","family_desc":"这里没有门派。","author":"zine"]),
                  ([  "path":"/d/wananta/","name":"万安塔","job_desc":"这里的你已经在做万安塔任务了。","quest_desc":"这里没有谜题。","family_desc":"这里没有门派。","author":"zine"]),
                  ([  "path":"/d/death/","name":"鬼门关","job_desc":"在这里你唯一的任务是复活。","quest_desc":"在这里你唯一的任务是复活。","family_desc":"这里没有门派。","author":"zine"]),
                  ([  "path":"/d/newbie/","name":"新手村","job_desc":"在这里你唯一的任务是进入这个江湖。","quest_desc":"在这里你唯一的任务是进入这个江湖。","family_desc":"这里没有门派。","author":"zine"]),
                  ([  "path":"/d/wizard/","name":"名人堂、宝石库、蜡像馆","job_desc":"这里没有任务。","quest_desc":"这里可以储存宝石、过劫难、做蜡像。","family_desc":"这里没有门派。","author":"zine"]),
                  ([  "path":"/d/jinshe/","name":"华山绝壁","job_desc":"这里没有任务。","quest_desc":"这里可以学习金蛇郎君的武功。","family_desc":"这里没有门派。","author":"zine"]),
                  ([  "path":"/newbiequest/shaolin/cjg/","name":"藏经阁副本","job_desc":"这里有藏经阁任务。","quest_desc":"这里可以使用藏经阁积分换取一些物品。","family_desc":"这里没有门派。","author":"zine"]),
                  ([  "path":"/d/wuguan/","name":"太乙武馆","job_desc":"这里没有任务。","quest_desc":"这里可以有太乙系武功，以及侠之大者的Quest。","family_desc":"这里没有门派。","author":"zine"]),
                  ([  "path":"/d/changbai/","name":"长白山","job_desc":"这里没有任务。","quest_desc":"这里有一些quest，但是我也不清楚。","family_desc":"这里没有门派。","author":"zine"]),
				  ([  "path":"/d/menggu/","name":"蒙古","job_desc":"这里有李萍任务和马贼任务。","quest_desc":"这里有一些quest，具体可在不儿罕山的主峰查询。","family_desc":"这里没有门派。","author":"zine"]),
				  ([  "path":"/include/","name":"不明区域","job_desc":"这里没有任务。","quest_desc":"这里没有谜题。","family_desc":"这里没有门派。","author":"zine"]),
				  ([  "path":"/d/jueqinggu/","name":"绝情谷","job_desc":"这里暂无任务。","quest_desc":"这里暂无谜题。","family_desc":"这里没有门派。","author":"zine"]),
                  });
string get_my_bigarea(object ob)
{
    object env=environment(ob);
    string city,dir_name,*path;
    int i,flag=0;
    mapping query_city;
    if (!env)
    {
        return "无环境";
    }
    if (base_name(env)=="/clone/misc/void")
    {
        return "最后乐园";
    }
    if (city=TASK_D->place_belong(env))
    {
    
        for (i=0;i<sizeof(cities);i++)
        {
            if (city==cities[i]["name"])
            {
                flag=1;
                query_city=cities[i];
                return query_city["big_area"];
            }
        }
    }
    if (flag==0)
    {
        path=explode(base_name(environment(ob)),"/");
        dir_name="/";
        for (i=0;i<sizeof(path)-1;i++)
        {
            dir_name+=path[i]+"/";
        }
        for (i=0;i<sizeof(undefined_cities);i++)
        {
            if (dir_name==undefined_cities[i]["path"])
            {
                query_city=undefined_cities[i];
                return query_city["big_area"];
            }
        }
        return "未知区域";
    }
}
string get_room_area(object env)
{
    string city,dir_name,*path;
    int i,flag=0;
    mapping query_city;
    if (!env)
    {
        return "无环境";
    }
    if (base_name(env)=="/clone/misc/void")
    {
        return "最后乐园";
    }
    if (city=TASK_D->place_belong(env))
    {
    
        for (i=0;i<sizeof(cities);i++)
        {
            if (city==cities[i]["name"])
            {
                flag=1;
                query_city=cities[i];
                return query_city["name"];
            }
        }
    }
    if (flag==0)
    {
        path=explode(base_name(env),"/");
        dir_name="/";
        for (i=0;i<sizeof(path)-1;i++)
        {
            dir_name+=path[i]+"/";
        }
        for (i=0;i<sizeof(undefined_cities);i++)
        {
            if (dir_name==undefined_cities[i]["path"])
            {
                query_city=undefined_cities[i];
                return query_city["name"];
            }
        }
        return "未知区域";
    }
}
string get_my_area(object ob)
{
    object env=environment(ob);
    string city,dir_name,*path;
    int i,flag=0;
    mapping query_city;
    if (!env)
    {
        return "无环境";
    }
    if (base_name(env)=="/clone/misc/void")
    {
        return "最后乐园";
    }
    if (city=TASK_D->place_belong(env))
    {
    
        for (i=0;i<sizeof(cities);i++)
        {
            if (city==cities[i]["name"])
            {
                flag=1;
                query_city=cities[i];
                return query_city["name"];
            }
        }
    }
    if (flag==0)
    {
        path=explode(base_name(environment(ob)),"/");
        dir_name="/";
        for (i=0;i<sizeof(path)-1;i++)
        {
            dir_name+=path[i]+"/";
        }
        for (i=0;i<sizeof(undefined_cities);i++)
        {
            if (dir_name==undefined_cities[i]["path"])
            {
                query_city=undefined_cities[i];
                return query_city["name"];
            }
        }
        return "未知区域";
    }
}
string get_myarea(object ob)
{
    object env=environment(ob);
    string city,dir_name,*path;
    int i,flag=0;
    mapping query_city;
    if (!env)
    {
        return "无环境";
    }
    if (base_name(env)=="/clone/misc/void")
    {
        return "最后乐园";
    }
    if (city=TASK_D->place_belong(env))
    {
    
        for (i=0;i<sizeof(cities);i++)
        {
            if (city==cities[i]["name"])
            {
                flag=1;
                query_city=cities[i];
                return query_city["name"];
            }
        }
    }
    if (flag==0)
    {
        path=explode(base_name(environment(ob)),"/");
        dir_name="/";
        for (i=0;i<sizeof(path)-1;i++)
        {
            dir_name+=path[i]+"/";
        }
        for (i=0;i<sizeof(undefined_cities);i++)
        {
            if (dir_name==undefined_cities[i]["path"])
            {
                query_city=undefined_cities[i];
                return query_city["name"];
            }
        }
        return "未知区域："+dir_name;
    }
}
string get_area_info(object ob)
{
    string city,msg,dir_name,*path;
    mapping query_city;
    int i,flag=0;
    object sta=load_object("/d/changjiang/cjn1");
    if (environment(ob))
    city=TASK_D->place_belong(environment(ob));
    if (city)
    {
    
        for (i=0;i<sizeof(cities);i++)
        {
            if (city==cities[i]["name"])
            {
                flag=1;
                query_city=cities[i];
                break;
            }
        }
    }
    if (flag==0)
    {
        path=explode(base_name(environment(ob)),"/");
        if (sizeof(path)==3)
        {
            dir_name="/"+path[0]+"/"+path[1]+"/";
        }
        else if (sizeof(path)==4)
        {
            dir_name="/"+path[0]+"/"+path[1]+"/"+path[2]+"/";
        }
        else
        {
            return msg;
        }
        for (i=0;i<sizeof(undefined_cities);i++)
        {
            if (dir_name==undefined_cities[i]["path"])
            {
                flag=1;
                query_city=undefined_cities[i];
                break;
            }
        }
    }
    if (flag==0)
    {
        return msg;
    }
    msg="";
    msg+="这里是"+CYN+query_city["name"]+CYN+"。\n";
    if (query_city["job_desc"])
    {
        msg+=CYN+query_city["job_desc"]+NOR+"\n";
    }
    else
    {
        msg+=CYN+"这里没有人可以提供任务。\n"+NOR;
    }
    if (query_city["quest_desc"])
    {
        msg+=CYN+query_city["quest_desc"]+NOR+"\n";
    }
    else
    {
        msg+=CYN+"这里没有什么像样的谜题。\n"+NOR;
    }
    if (query_city["family_desc"])
    {
        msg+=CYN+query_city["family_desc"]+NOR+"\n";
    }
    else
    {
        msg+=CYN+"这里没有什么像样的谜题。\n"+NOR;
    }
    if (sta->get_area_player(ob))
    {
        msg+=CYN+sta->get_area_player(ob)+NOR;
    }
    if (query_city["author"])
    {
        msg+=CYN+"这些事情是 "+HIR+query_city["author"]+CYN+" 告诉我的，如果不对的话，你记得要找他算账。\n";
    }
    return msg;
}

string random_area_name()
{
	string *area_names=({});
	for (int i=0;i<sizeof(cities);i++)
	area_names+=({cities[i]["name"]});
	return area_names[random(sizeof(area_names))];
}
