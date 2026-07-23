/*------------------------------
 RPG泥潭游戏--魔法大陆
 1.游戏数据：
        x   : 坐标 x 轴 <int>
        y   : 坐标 y 轴 <int>  
        hp  : 气血      <int>
        mp  : 魔法      <int>
        exp : 经验      <int>
    max_exp : 最大经验  <int>
        lvl : 等级      <int>
        job : 职业      <string>
      items : 物品      <*string>
       gold : 金钱      <int>

     weapon : 武器      <string>
      armor : 盔甲      <string>
      cloth : 衣服      <string>
       head : 头盔      <string>
     shield : 盾牌      <string>
      shoes : 鞋子      <string>
       ring : 首饰      <string>

         ad : 物攻      <int>
         md : 魔攻      <int>
         ac : 物防      <int>
         mc : 魔防      <int>
         sp : 敏捷      <int>
                         
 2.游戏设置：
        回合制RPG泥潭游戏，遇敌
        方式：随机<?>
 3.游戏背景：
        魔法为主的世界。
 4.战斗选择：
        进攻|           
        特技|
        魔法|
        物品|
        防御|
        逃跑| 
        
                Snowtu/2004/11        
------------------------------*/

mapping *maps = ({
        ([
                "short" : "出生地",
                "long"  : "这里是新手的出生地，如果你有不明白的，可以在这里看相关帮助(help)。",
                "x"     : 0,
                "y"     : 0,
                "cmds"  : ({"help","look","inventory","eat","drop","get","hp"}),
        ]),
        
        ([
                "short" : "杂货店",
                "long"  : "这里是杂货店，你可以在这里补给。",
                "x"     : 1,
                "y"     : 1,
                "cmds"  : ({"look","inventory","sell","buy","drop",}),
        ]),

        ([
                "short" : "道具店",
                "long"  : "这里是道具店，你可以在这里买你需要的商品。",
                "x"     : -1,
                "y"     : 1,
                "cmds"  : ({"look","inventory","sell","buy","drop",}),
                "shop"  : 1,
                "npc"   : ([
                        "name"  : "店老板",
                        "id"    : "boss",
                        ]),
                "goods" : ({    "金创药",
                                "魔法药",
                        }),
        ]),
        
        ([      
                "short" : "武器店",
                "long"  : "这是一家老字号的武器店，你可以在这里购买你称手的武器。",
                "x"     : -1,
                "y"     : -1,
                "cmds"  : ({"look","inventory","sell","buy","drop",}),
        ]),
        
});                     

mapping d_items = ([
        "金创药"  : ([
                "id"    : ({"jinchuang yao","yao"}),
                "long"  : "治疗的良药，可以恢复 10 点的 HP。",          
                "values": 5,
                "type"  : "hp",
                "add"   : 10,
                ]),
        "大金创药" : ([
                "id"    : ({"jin chuang yao","yao"}),
                "long"  : "治疗的良药，可以恢复 50 点的 HP。",
                "values": 25,
                "type"  : "hp",
                "add"   : 50,
                ]),
        "魔法瓶"  : ([
                "id"    : ({"mofa ping","ping"}),
                "long"  : "神奇的药瓶，可以恢复 10 点的 MP。",
                "value" : 10,
                "type"  : "mp",
                "add"   : 10,
                ]),
        "大魔法瓶"  : ([
                "id"    : ({"mo fa ping","ping"}),
                "long"  : "神奇的药瓶，可以恢复 50 点的 MP。",
                "value" : 45,
                "type"  : "mp",
                "add"   : 50,
                ]),
]);                             

int errs( string msg )
{
if( !msg ) 
        return 0;
write( msg );
return 1;
}


