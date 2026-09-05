string * grassland_animal=({"牦牛","绵羊","马","野马","黄鼠狼","野驴"});
string * grassland_animal_id=({"mao niu","mian yang","ma","ye ma","huangshu lang","ye lv"});
int * grassland_animal_weight=({80000,30000,60000,50000,12000,55000});
int * grassland_animal_possibility=({30,45,20,25,5,7});//出现概率百分比
int * grassland_animal_move=({5,6,20,35,45,30});//random_move概率百分比,越高说明此动物越喜欢乱动
int * grassland_animal_exp=({100000,25000,70000,75000,10000,65000});
string * grassland_animal_number=({"C0001","C0002","C0003","C0004","C0005","C0006",});//动物类型编号，比如草原动物用C0001,C0002顺序编号

string * desert_animal=({"蝎子","响尾蛇","秃鹫","野骆驼","羊驼"});
string * desert_animal_id=({"xie zi","xiangwei she","tu jiu","ye luotuo","yang tuo"});
int * desert_animal_weight=({200,1000,12000,85000,45000});
int * desert_animal_possibility=({5,8,5,15,6});
int * desert_animal_move=({35,30,65,25,20});
int * desert_animal_exp=({30000,55000,110000,120000,40000});
string * desert_animal_number=({"S0001","S0002","S0003","S0004","S0005"});

string * mountain_animal=({"山鸡","猕猴","山羊","麻雀","狼","野猪","狐狸","豹子"});
string * mountain_animal_id=({"shang ji","mi hou","shan yang","ma que","lang","ye zhu","hu li","bao zi"});
int * mountain_animal_weight=({1800,3000,25000,500,28000,60000,15000,25000});
int * mountain_animal_possibility=({50,10,35,55,20,5,7,2});
int * mountain_animal_move=({25,50,8,35,28,12,30,35});
int * mountain_animal_exp=({5000,15000,20000,500,45000,70000,25000,65000});
string * mountain_animal_number=({"SD0001","SD0002","SD0003","SD0004","SD0005","SD0006","SD0007","SD0008",});

string * forest_animal=({"鹿","老虎","黑熊","野兔","巨蟒","竹叶青","松鼠","孔雀","貂"});
string * forest_animal_id=({"lu","lao hu","hei xiong","ye tu","ju mang","zhuye qing","song shu","kong que","diao"});
int * forest_animal_weight=({45000,75000,85000,5000,8000,1000,4000,8000,3500});
int * forest_animal_possibility=({30,3,5,60,3,4,40,2,4});
int * forest_animal_move=({15,25,10,55,3,4,45,35,75});
int * forest_animal_exp=({80000,150000,120000,5000,135000,40000,4500,10000,12000});
string * forest_animal_number=({"L0001","L0002","L0003","L0004","L0005","L0006","L0007","L0008","L0009",});

string * lakeside_animal=({"鳄鱼","野鸭","大雁","白鹤"});
string * lakeside_animal_id=({"e yu","ye ya","da yan","bai he"});
int * lakeside_animal_weight=({120000,15000,20000,23000});
int * lakeside_animal_possibility=({5,40,15,5});
int * lakeside_animal_move=({2,25,35,10});
int * lakeside_animal_exp=({180000,1500,2500,35000});
string * lakeside_animal_number=({"H0001","H0002","H0003","H0004"});
//以下是各种区域出现动物打散分类。
string * big_animal=({"C0001","C0002","C0003","C0004","SD0003","S0004","C0006",});//大型牛马类动物
string * small_animal=({"SD0002",});//小型灵长类动物
string * middle_animal=({"SD0005","SD0006","SD0007","L0001","L0002","L0003","L0004","L0007","H0001","S0005","C0005","SD0008","L0009",});//中性野兽
string * insect=({"S0001",});//虫类
string * snake=({"S0002","L0005","L0006"});//蛇类
string * bird=({"S0003","SD0001","SD0004","H0002","H0003","H0004","L0008",});//猛禽类

//所有动物战斗动作，具体动物在specilize里可用定义动作
string get_limbs()
{
    string limb,*limbs=this_object()->query("act_limbs");
    if (limbs)
    {
        limb=limbs[random(sizeof(limbs))];
    }
    else
    {
        limb="前爪";
    }
    return limb;
}

mapping combat_action =
([
        "hoof": ([
                "action":               "$N用"+get_limbs()+"往$n的$l用力一蹬",
                "damage":               100,
                "damage_type":  "瘀伤",
        ]),
        "bite": ([
                "action":               "$N扑上来张嘴往$n的$l狠狠地一咬",
                "damage":               20,
                "damage_type":  "咬伤",
        ]),
        "claw": ([
                "action":               "$N用"+get_limbs()+"往$n的$l一抓",
                "damage":               50,
                "damage_type":  "抓伤",
        ]),
        "poke": ([
                "action":               "$N用嘴往$n的$l一啄",
                "damage":               30,
                "damage_type":  "刺伤",
        ]),
        "qian": ([
                "action":               "$N用前螯往$n的$l用力一夹",
                "damage":               50,
                "damage_type":  "夹伤",
        ]),
        "sao": ([
                "action":               "$N用翅膀往$n的$l一扫",
                "damage":               40,
                "damage_type":  "瘀伤",
        ]),
        "sao2": ([
                "action":               "$N用尾巴往$n的$l一扫",
                "damage":               40,
                "damage_type":  "瘀伤",
        ]),
        "zhuang": ([
                "action":               "$N低下头，猛然发力冲过来，对着$n的$l猛撞过去",
                "damage":               45,
                "damage_type":  "瘀伤",
        ]),//大型动物如野牛
]);