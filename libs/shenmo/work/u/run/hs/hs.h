/* 原始设定 */

mapping pangolin,tortoise,tapir,cow,elephant,bear,hippo,crocodile,shark,bat,cat,monkey,hawk,horse,hare,peacock,mouse,chicken,pig,dog,snake,sheep,deer,wolf,fox,leopard,tiger,lion;


/*             kee---体力                  atk---力量                def---防御               spd---敏捷                基本属性      */
/*             fkee---体力波动率           fatk---力量波动率          fdef---防御波动率         fspd---敏捷波动率         基本属性变化  */
/*             rkee---体力成长率*10        ratk---力量成长率*10       rdef---防御成长率*10      rspd---敏捷成长率*10      属性成长率    */
/*             keef---体力成长波动率*10    atkf---力量成长波动率*10    deff---防御成长波动率*10  spdf---敏捷成长波动率*10  成长率变化    */
/*             total  100 级 属性最高最低评测  {血的计算：min=rkee*10+kee , max=(rkee+keef)*10+kee+fkee }                             */

pangolin = ([ "name"  :  "穿山甲"  ,  "id"  :  "pangolin" ,
		"kee"   :    7      ,  "atk"  :    3        ,  "def"  :    15    ,     "spd"  :   2	,
		"fkee"  :    2      ,  "fatk" :    1        ,  "fdef" :    3     ,     "fspd" :   1	,
		"rkee"  :    12     ,  "ratk" :    8        ,  "rdef" :    20    ,     "rspd" :   5	,   
		"keef"  :    2      ,  "atkf" :    1        ,  "deff" :    5     ,     "spdf" :   1	,
/*     total            127-149                83-94                  215-268                 52-63              */  
               
tortoise = ([ "name"  :  "龟"     ,  "id"   :  "tortoise" ,
		"kee"   :    10     ,  "atk"  :    1        ,  "def"  :    13    ,     "spd"  :   1	,
		"fkee"  :    2      ,  "fatk" :    1        ,  "fdef" :    2     ,     "fspd" :   1	,       
		"rkee"  :    15     ,  "ratk" :    8        ,  "rdef" :    16    ,     "rspd" :   3	,
		"keef"  :    3      ,  "atkf" :    1        ,  "deff" :    5     ,     "spdf" :   1	,
/*     total            160-192                81-92                  173-225                 31-42              */  

tapir    = ([ "name"  :  "貘"     ,  "id"   :  "tapir"    ,
		"kee"   :    5      ,  "atk"  :    5        ,  "def"  :    10    ,     "spd"  :   5	,
		"fkee"  :    2      ,  "fatk" :    1        ,  "fdef" :    2     ,     "fspd" :   1      ,  
		"rkee"  :    12     ,  "ratk" :    8        ,  "rdef" :    13    ,     "rspd" :   8	,   
		"keef"  :    2      ,  "atkf" :    2        ,  "deff" :    3     ,     "spdf" :   2      ,
/*     total            125-147                85-106                 140-172                 85-106            */  

cow      = ([ "name"  :  "牛"     ,  "id"   :  "cow"      ,
		"kee"   :    12     ,  "atk"  :    7        ,  "def"  :    12    ,     "spd"  :   3	,
		"fkee"  :    3      ,  "fatk" :    1        ,  "fdef" :    2     ,     "fspd" :   1      ,  
		"rkee"  :    16     ,  "ratk" :    11       ,  "rdef" :    14    ,     "rspd" :   7	,
		"keef"  :    3      ,  "atkf" :    2        ,  "deff" :    3     ,     "spdf" :   2      ,
/*     total               */  

elephant = ([ "name"  :  "象"     ,  "id"   :  "elephant" ,
		"kee"   :    15     ,  "atk"  :    10       ,  "def"  :    12    ,     "spd"  :   2	,
		"fkee"  :    3      ,  "fatk" :    2        ,  "fdef" :    3     ,     "fspd" :   1      , 
		"rkee"  :    18     ,  "ratk" :    13       ,  "rdef" :    15    ,     "rspd" :   5      ,
		"keef"  :    4      ,  "atkf" :    3        ,  "deff" :    3     ,     "spdf" :   1      ,
/*     total            195-238               140-172                 162-195                 52-63             */  

bear     = ([ "name"  :  "熊"     ,  "id"   :  "bear"     ,
		"kee"   :    10     ,  "atk"  :    13       ,  "def"  :    10    ,     "spd"  :   2	,
		"fkee"  :    2      ,  "fatk" :    2        ,  "fdef" :    2     ,     "fspd" :   1      , 
		"rkee"  :    12     ,  "ratk" :    18       ,  "rdef" :    12    ,     "rspd" :   5   	,
		"keef"  :    2      ,  "atkf" :    4        ,  "deff" :    2     ,     "spdf" :   2      ,
/*     total            130-152               193-235                 130-152                 52-73             */  

hippo    = ([ "name"  :  "河马"   ,  "id"   :  "hippo"    ,
		"kee"   :    15     ,  "atk"  :    10       ,  "def"  :    10    ,     "spd"  :   2	,
		"fkee"  :    4      ,  "fatk" :    2        ,  "fdef" :    2     ,     "fspd" :   1      ,  
		"rkee"  :    20     ,  "ratk" :    13       ,  "rdef" :    12    ,     "rspd" :   3   	,
		"keef"  :    5      ,  "atkf" :    2        ,  "deff" :    2     ,     "spdf" :   1      ,
/*     total            215-269               140-162                 130-152                 32-43             */  

crocodile= ([ "name"  :  "鳄鱼"   ,  "id"   :  "crocodile"    ,
		"kee"   :    13     ,  "atk"  :    13       ,  "def"  :    8     ,     "spd"  :   2	,
		"fkee"  :    2      ,  "fatk" :    3        ,  "fdef" :    2     ,     "fspd" :   1      ,  
		"rkee"  :    13     ,  "ratk" :    15       ,  "rdef" :    10    ,     "rspd" :   3   	,
		"keef"  :    3      ,  "atkf" :    4        ,  "deff" :    2     ,     "spdf" :   1      ,
/*     total            143-175               163-206                 108-130                 32-43            */  

shark    = ([ "name"  :  "鲨鱼"   ,  "id"   :  "shark"    ,
		"kee"   :    8      ,  "atk"  :    18       ,  "def"  :    8     ,     "spd"  :   8	,
		"fkee"  :    2      ,  "fatk" :    4        ,  "fdef" :    2     ,     "fspd" :   2      ,  
		"rkee"  :    10     ,  "ratk" :    15       ,  "rdef" :    10    ,     "rspd" :   8   	,
		"keef"  :    2      ,  "atkf" :    3        ,  "deff" :    1     ,     "spdf" :   2      ,
/*     total            108-130               168-202                 108-120                 88-110            */  

bat      = ([ "name"  :  "蝙蝠"   ,  "id"   :  "bat"      ,
		"kee"   :    5      ,  "atk"  :    12       ,  "def"  :    8     ,     "spd"  :   13	,
		"fkee"  :    1      ,  "fatk" :    2        ,  "fdef" :    2     ,     "fspd" :   4      ,  
		"rkee"  :    8      ,  "ratk" :    9        ,  "rdef" :    9     ,     "rspd" :   14   	,
		"keef"  :    1      ,  "atkf" :    1        ,  "deff" :    1     ,     "spdf" :   4      ,
/*     total             85-96                102-114                  98-110                163-197            */  

cat      = ([ "name"  :  "猫"     ,  "id"   :  "cat"      ,
		"kee"   :    8      ,  "atk"  :    13       ,  "def"  :    10    ,     "spd"  :   11	,
		"fkee"  :    1      ,  "fatk" :    2        ,  "fdef" :    2     ,     "fspd" :   3      ,  
		"rkee"  :    10     ,  "ratk" :    10       ,  "rdef" :    11    ,     "rspd" :   12   	,
		"keef"  :    1      ,  "atkf" :    2        ,  "deff" :    1     ,     "spdf" :   3      ,
/*     total            108-119               113-135                 120-132                131-164            */  

monkey   = ([ "name"  :  "猴"     ,  "id"   :  "monkey"   ,
		"kee"   :    10     ,  "atk"  :    13       ,  "def"  :    12    ,     "spd"  :   12	,
		"fkee"  :    2      ,  "fatk" :    2        ,  "fdef" :    2     ,     "fspd" :   3      ,  
		"rkee"  :    12     ,  "ratk" :    12       ,  "rdef" :    11    ,     "rspd" :   13   	,
		"keef"  :    2      ,  "atkf" :    2        ,  "deff" :    1     ,     "spdf" :   3      ,
/*     total            130-152               133-155                 122-134                142-175            */  

hawk     = ([ "name"  :  "鹰"     ,  "id"   :  "hawk"     ,
		"kee"   :    9      ,  "atk"  :    14       ,  "def"  :    9     ,     "spd"  :   15	,
		"fkee"  :    2      ,  "fatk" :    2        ,  "fdef" :    2     ,     "fspd" :   4      ,  
		"rkee"  :    11     ,  "ratk" :    13       ,  "rdef" :    10    ,     "rspd" :   15   	,
		"keef"  :    2      ,  "atkf" :    3        ,  "deff" :    1     ,     "spdf" :   4      ,
/*     total            119-141               144-176                 109-121                165-209            */  

horse    = ([ "name"  :  "马"     ,  "id"   :  "horse"    ,
		"kee"   :    12     ,  "atk"  :    12       ,  "def"  :    11    ,     "spd"  :   13	,
		"fkee"  :    2      ,  "fatk" :    2        ,  "fdef" :    2     ,     "fspd" :   3      ,  
		"rkee"  :    12     ,  "ratk" :    12       ,  "rdef" :    11    ,     "rspd" :   13   	,
		"keef"  :    2      ,  "atkf" :    2        ,  "deff" :    1     ,     "spdf" :   4      ,
/*     total            132-153               132-154                 121-133                143-186            */  

hare     = ([ "name"  :  "兔"     ,  "id"   :  "hare"     ,
              "kee"   :    9      ,  "atk"  :    9        ,  "def"  :    10    ,     "spd"  :   13	,
              "fkee"  :    1      ,  "fatk" :    1        ,  "fdef" :    2     ,     "fspd" :   2      ,  
              "rkee"  :    10     ,  "ratk" :    10       ,  "rdef" :    10    ,     "rspd" :   13   	,
              "keef"  :    1      ,  "atkf" :    1        ,  "deff" :    1     ,     "spdf" :   3      ,
/*     total            109-120               109-120                 110-122                143-175            */  

peacock  = ([ "name"  :  "孔雀"   ,  "id"   :  "peacock"  ,
              "kee"   :    9      ,  "atk"  :    9        ,  "def"  :    9     ,     "spd"  :   9	,
              "fkee"  :    1      ,  "fatk" :    1        ,  "fdef" :    1     ,     "fspd" :   1      ,  
              "rkee"  :    10     ,  "ratk" :    10       ,  "rdef" :    10    ,     "rspd" :   10  	, 
              "keef"  :    1      ,  "atkf" :    1        ,  "deff" :    1     ,     "spdf" :   1      ,
/*     total            109-120               109-120                 108-119                108-119            */  

mouse    = ([ "name"  :  "鼠"     ,  "id"   :  "mouse"    ,
              "kee"   :    5      ,  "atk"  :    8        ,  "def"  :    8     ,     "spd"  :   13	,
              "fkee"  :    1      ,  "fatk" :    1        ,  "fdef" :    1     ,     "fspd" :   3      ,  
              "rkee"  :    8      ,  "ratk" :    10       ,  "rdef" :    8     ,     "rspd" :   11  	, 
              "keef"  :    1      ,  "atkf" :    1        ,  "deff" :    1     ,     "spdf" :   3      ,
/*     total             85-96                108-119                  88-99                 123-156            */  

chicken   = ([ "name"  :  "鸡"     ,  "id"   :  "chicken"  ,
              "kee"   :    8      ,  "atk"  :    10       ,  "def"  :    8     ,     "spd"  :   11	,
              "fkee"  :    1      ,  "fatk" :    1        ,  "fdef" :    1     ,     "fspd" :   2      ,  
              "rkee"  :    8      ,  "ratk" :    10       ,  "rdef" :    8     ,     "rspd" :   10  	, 
              "keef"  :    1      ,  "atkf" :    1        ,  "deff" :    1     ,     "spdf" :   2      ,
/*     total             88-99                110-121                  88-99                 111-133            */  

pig      = ([ "name"  :  "猪"     ,  "id"   :  "pig"      ,
              "kee"   :    12     ,  "atk"  :    10       ,  "def"  :   11     ,     "spd"  :   7	,
              "fkee"  :    2      ,  "fatk" :    1        ,  "fdef" :    2     ,     "fspd" :   1      ,  
              "rkee"  :    10     ,  "ratk" :    9        ,  "rdef" :   10     ,     "rspd" :   9   	,
              "keef"  :    2      ,  "atkf" :    1        ,  "deff" :    1     ,     "spdf" :   1      ,
/*     total            112-134               100-111                 111-123                 97-108            */  

dog      = ([ "name"  :  "狗"     ,  "id"   :  "dog"      ,
              "kee"   :    11     ,  "atk"  :    12       ,  "def"  :   12     ,     "spd"  :   10	,
              "fkee"  :    1      ,  "fatk" :    2        ,  "fdef" :    2     ,     "fspd" :   2      ,  
              "rkee"  :    9      ,  "ratk" :    11       ,  "rdef" :   10     ,     "rspd" :   11   	,
              "keef"  :    2      ,  "atkf" :    1        ,  "deff" :    1     ,     "spdf" :   2      ,
/*     total            111-121               122-134                 112-124                120-142            */  

snake    = ([ "name"  :  "蛇"     ,  "id"   :  "snake"    ,
              "kee"   :   10      ,   "atk"  :   13       ,  "def"  :    9     ,     "spd"  :   12	,
              "fkee"  :    1      ,  "fatk" :    2        ,  "fdef" :    1     ,     "fspd" :   3      ,  
              "rkee"  :    9      ,  "ratk" :    12       ,  "rdef" :    9     ,     "rspd" :   12   	,
              "keef"  :    1      ,  "atkf" :    2        ,  "deff" :    1     ,     "spdf" :   2      ,
/*     total            110-111               133-155                  99-110                132-155            */  

sheep    = ([ "name"  :  "羊"     ,  "id"   :  "sheep"    ,
              "kee"   :    9      ,  "atk"  :    9        ,  "def"  :    9     ,     "spd"  :   12	,
              "fkee"  :    1      ,  "fatk" :    1        ,  "fdef" :    1     ,     "fspd" :   2      ,  
              "rkee"  :    9      ,  "ratk" :    9        ,  "rdef" :    9     ,     "rspd" :   11   	,
              "keef"  :    1      ,  "atkf" :    1        ,  "deff" :    1     ,     "spdf" :   2      ,
/*     total             99-110                99-110                  99-110                122-144            */  

deer     = ([ "name"  :  "鹿"     ,  "id"   :  "deer"     ,
              "kee"   :    10     ,  "atk"  :    10       ,  "def"  :    11    ,     "spd"  :   13	,
              "fkee"  :    2      ,  "fatk" :    1        ,  "fdef" :    2     ,     "fspd" :   3      ,  
              "rkee"  :    10     ,  "ratk" :    10       ,  "rdef" :    11    ,     "rspd" :   12   	,
              "keef"  :    1      ,  "atkf" :    1        ,  "deff" :    1     ,     "spdf" :   2      ,
/*     total            110-122                110-121                121-133                133-156            */  

wolf     = ([ "name"  :  "狼"     ,  "id"   :  "wolf"     ,
              "kee"   :    12     ,  "atk"  :    18       ,  "def"  :    13    ,     "spd"  :   13	,
              "fkee"  :    2      ,  "fatk" :    3        ,  "fdef" :    2     ,     "fspd" :   3      ,  
              "rkee"  :    13     ,  "ratk" :    15       ,  "rdef" :    12    ,     "rspd" :   12   	,
              "keef"  :    2      ,  "atkf" :    2        ,  "deff" :    2     ,     "spdf" :   2      ,
/*     total            142-164               168-191                 133-155                133-156            */  

fox      = ([ "name"  :  "狐"     ,  "id"   :  "fox"      ,
              "kee"   :    11     ,  "atk"  :    13       ,  "def"  :    12    ,     "spd"  :   15	,
              "fkee"  :    1      ,  "fatk" :    2        ,  "fdef" :    2     ,     "fspd" :   4      ,  
              "rkee"  :    11     ,  "ratk" :    12       ,  "rdef" :    12    ,     "rspd" :   13   	,
              "keef"  :    1      ,  "atkf" :    1        ,  "deff" :    2     ,     "spdf" :   3      ,
/*     total            121-132               133-145                 132-154                145-179            */  

leopard  = ([ "name"  :  "豹"     ,  "id"   :  "leopard"  ,
              "kee"   :    13     ,  "atk"  :    20       ,  "def"  :    13    ,     "spd"  :   15	,
              "fkee"  :    2      ,  "fatk" :    3        ,  "fdef" :    2     ,     "fspd" :   4      ,  
              "rkee"  :    11     ,  "ratk" :    16       ,  "rdef" :    12    ,     "rspd" :   14   	,
              "keef"  :    2      ,  "atkf" :    2        ,  "deff" :    2     ,     "spdf" :   2     , 
/*     total            123-143               180-203                133-155                 155-179            */  

tiger    = ([ "name"  :  "虎"     ,  "id"   :  "tiger"    ,
              "kee"   :    14     ,  "atk"  :    22       ,  "def"  :    14    ,     "spd"  :   13	,
              "fkee"  :    2      ,  "fatk" :    3        ,  "fdef" :    2     ,     "fspd" :   3      ,  
              "rkee"  :    12     ,  "ratk" :    18       ,  "rdef" :    13    ,     "rspd" :   12   	,
              "keef"  :    2      ,  "atkf" :    3        ,  "deff" :    2     ,     "spdf" :   2      ,
/*     total            134-156               202-235                 144-166                133-156            */  

lion     = ([ "name"  :  "狮"     ,  "id"   :  "lion"     ,
              "kee"   :    15     ,  "atk"  :    21       ,  "def"  :    14    ,     "spd"  :   12	,
              "fkee"  :    2      ,  "fatk" :    3        ,  "fdef" :    2     ,     "fspd" :   3      ,  
              "rkee"  :    13     ,  "ratk" :    17       ,  "rdef" :    13    ,     "rspd" :   11   	,
              "keef"  :    2      ,  "atkf" :    3        ,  "deff" :    2     ,     "spdf" :   2      ,
/*     total            145-167               191-224                 144-166                122-145            */  



//  "光之虎","烈火雄狮","碧水蓝鹰","大地之熊","疾风之狐","邪狼"


//6个特殊hs,4圣兽，太初，太始 还未设定。
//光与暗属性只有6个特殊hs中的2个和太初,太始才能具有。
//有部分较弱的，比如猪，孔雀等，虽然本身属性不好，但可学某些特殊技能，尽量使每种hs都有其独特的长处。
//特殊技能：比如有铸造合成类的，或是孔雀独有的迷惑技能等。



