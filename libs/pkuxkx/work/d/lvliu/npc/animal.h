string * grassland_animal=({"牦牛","绵羊","马","野马","黄鼠狼","野驴"});
string * grassland_animal_id=({"mao niu","mian yang","ma","ye ma","huangshu lang","ye lv"});
int * grassland_animal_weight=({80000,30000,60000,50000,12000,55000});
int * grassland_animal_possibility=({30,45,20,25,5,7});//出现概率百分比
int * grassland_animal_move=({5,6,20,35,45,30});//random_move概率百分比,越高说明此动物越喜欢乱动
int * grassland_animal_exp=({100000,25000,70000,75000,10000,65000});
string * grassland_animal_number=({"C0001","C0002","C0003","C0004","C0005","C0006",});//动物类型编号，比如草原动物用C0001,C0002顺序编号

string * mountain_animal=({"山鸡","猕猴","山羊","麻雀","狐狸"});
string * mountain_animal_id=({"shan ji","mi hou","shan yang","ma que","hu li"});
int * mountain_animal_weight=({1800,3000,25000,500,15000});
int * mountain_animal_possibility=({50,10,35,55,7});
int * mountain_animal_move=({25,50,8,35,30});
int * mountain_animal_exp=({5000,15000,20000,500,25000});
string * mountain_animal_number=({"SD0001","SD0002","SD0003","SD0004","SD0005",});

string * forest_animal=({"鹿","野兔","松鼠","孔雀","貂"});
string * forest_animal_id=({"lu","ye tu","song shu","kong que","diao"});
int * forest_animal_weight=({45000,5000,4000,8000,3500});
int * forest_animal_possibility=({30,60,40,2,4});
int * forest_animal_move=({15,55,45,35,75});
int * forest_animal_exp=({80000,5000,4500,10000,12000});
string * forest_animal_number=({"L0001","L0002","L0003","L0004","L0005",});

string * lakeside_animal=({"锦毛野鸡","野鸭","大雁","白鹤"});
string * lakeside_animal_id=({"ye ji","ye ya","da yan","bai he"});
int * lakeside_animal_weight=({12000,15000,20000,23000});
int * lakeside_animal_possibility=({35,40,15,5});
int * lakeside_animal_move=({23,25,35,10});
int * lakeside_animal_exp=({1800,1500,2500,35000});
string * lakeside_animal_number=({"H0001","H0002","H0003","H0004"});
//以下是各种区域出现动物打散分类。
string * big_animal=({"C0001","C0002","C0003","C0004","SD0003","L0001","C0006",});//大型牛马类动物
string * small_animal=({"SD0002",});//小型灵长类动物
string * middle_animal=({"SD0005","L0002","L0003","C0005",});//中性野兽
string * bird=({"SD0001","SD0004","H0002","H0003","L0004","H0001","H0004",});//猛禽类

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