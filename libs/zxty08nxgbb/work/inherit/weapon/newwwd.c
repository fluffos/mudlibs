// written by stey

#include <ansi.h> 
#include <dbase.h> 

#define WW_NAME       0 
#define WW_ID         1 
#define WW_VALUE      2 
#define WW_HARM       3 
#define WW_MAR        4 
 
string *s_type=({"fire","ice","poison","air","earth",}); 
mapping name_type=([ 
   "sword":"剑","stick":"棍","hammer":"锤","staff":"杖","whip":"鞭","axe":"斧","blade":"刀", 
   "fork":"叉","spear":"枪","mace":"锏", 
]); 
static mapping weapon_type = ([ 
 //类型           中文名     英文名          价值    附加伤害值 武器损害值 
   "fire0": ({ HIR"火焰"NOR, "flame",        20000,     10,   30 , }),  
   "fire1": ({ HIR"极烈火"NOR, "fire",         40000,     20,   40 , }),  
   "fire2": ({ HIR"魔玄火"NOR, "magicfire",    70000,     30,   50 , }),  
   "fire3": ({ HIR"天炙火"NOR, "skyfire",     150000,     40,   60 , }),  
   "fire4": ({ HIR"火海"NOR, "inferno",     200000,     50,   70 , }),  
   "fire5": ({ HIR"艳阳火"NOR, "fire",        250000,     60,   80 , }),  
   "fire6": ({ HIR"烈日火"NOR, "inferno",     600000,     70,   90 , }), 
   "fire7": ({ HIR"九阳火"NOR, "suns",        800000,     80,   100, }),  
   "fire8": ({ HIR"爆裂火"NOR, "explosion",   900000,     95,   120, }),  
 
  
  "ice0":   ({ HIC"寒冰"NOR, "ice",           20000,      10,   30 , }),  
  "ice1":   ({ HIC"玄冰"NOR, "magicice",      40000,      20,   40 , }),  
  "ice2":   ({ HIC"炙冰"NOR, "coolest",       70000,      30,   50 , }),  
  "ice3":   ({ HIC"天冻"NOR, "skyice",       150000,      40,   60 , }),  
  "ice4":   ({ HIC"冰极"NOR, "fearfully ice",      200000,      50,   70 , }),  
  "ice5":   ({ HIC"千冰"NOR, "millenary ice",          250000,      60,   80 , }),  
  "ice6":   ({ HIC"万冰"NOR, "myriad ice",      600000,      70,   90 , }),  
  "ice7":   ({ HIC"九阴"NOR, "nineshade",         800000,      80,   100, }),  
  "ice8":   ({ HIC"寒裂"NOR, "iceblow",    900000,      95,   120, }),  
 
 
  
 "poison0": ({  HIG"散毒"NOR, "disperse",        20000,      10,   30 , }),  
 "poison1": ({  HIG"鹤顶红"NOR, "crane",           40000,      20,   40 , }),  
 "poison2": ({  HIG"蛇胆毒"NOR, "serpent",         70000,      30,   50 , }),  
 "poison3": ({  HIG"蝎尾毒"NOR, "scorpion",        150000,      40,   60 , }),  
 "poison4": ({  HIG"蛾粉毒"NOR, "moth",            200000,      50,   70 , }),  
 "poison5": ({  HIG"蛊虫毒"NOR, "gu",              250000,      60,   80 , }),  
 "poison6": ({  HIG"腐尸粉"NOR, "ptomaine",        600000,      70,   90 , }),  
 "poison7": ({  HIG"妖魂毒"NOR, "evil spirit",        800000,      80,   100, }),  
 "poison8": ({  HIG"魔血毒"NOR, "evil",               900000,      95,   120, }),  
 
 
 
  
    "air0": ({ HIW"气暴弹"NOR, "air bomb",           20000,      10,   30 , }),  
    "air1": ({ HIW"气箭"NOR,   "air arrow",              40000,      20,   40 , }),  
    "air2": ({ HIW"魔气剑"NOR, "air sword",        70000,      30,   50 , }),  
    "air3": ({ HIW"神气刀"NOR, "air falchion",   150000,      40,   60 , }),  
    "air4": ({ HIW"疾风"NOR,   "high wind",      200000,      50,   70 , }),  
    "air5": ({ HIW"烈风"NOR,   "strong wind",      250000,      60,   80 , }),  
    "air6": ({ HIW"暴风"NOR,   "strom wind",   600000,      70,   90 , }),  
    "air7": ({ HIW"雷电"NOR,   "thunder",       800000,      80,   100, }),  
    "air8": ({ HIW"链电"NOR,   "chain thunder",        900000,      95,   120, }),  
 
 
  
  "earth0": ({ YEL"五行玄土"NOR, "earth",              20000,      10,   30 , }),  
  "earth1": ({ YEL"爆石裂片"NOR, "stone bump",     40000,      20,   40 , }),  
  "earth2": ({ YEL"巨石轰顶"NOR, "megalith hit",    70000,      30,   50 , }),  
  "earth3": ({ YEL"泰山压顶"NOR, "hill hit",      150000,      40,   60 , }),  
  "earth4": ({ YEL"火山裂轰"NOR, "volcano hit",       200000,      50,   70 , }),  
  "earth5": ({ YEL"流星火雨"NOR, "star hit",            250000,      60,   80 , }),  
  "earth6": ({ YEL"金星撞击"NOR, "hesper bump",      600000,      70,   90 , }),  
  "earth7": ({ YEL"九星聚轰"NOR, "stars bump ",    800000,      80,   100, }),  
  "earth8": ({ YEL"地裂山崩"NOR, "earthquake",     900000,      95,   120, }),  
]);  
mapping *base_names = ({ 
   
  (["name": HIR"铜","id": "copper",]),  
  (["name": HIR"钢","id": "steel",]),             
  (["name": HIR"铁","id": "iron",]),  
  (["name": HIR"金","id": "gold",]),  
  (["name": HIC"灵玉","id": "jade",]), 
  (["name": HIC"翠玉","id": "greenjade",]), 
  (["name": HIC"霞玉","id": "sunjade",]), 
  (["name": HIC"彩玉","id": "colourful jade",]), 
  (["name": HIY"虎啸","id": "tiger",]), 
  (["name": HIY"鱼肠","id": "harmful",]), 
  (["name": HIY"龙吻","id": "dargonkiss",]), 
  (["name": HIY"凤凰","id": "phoenix",]), 
  (["name": HIW"雷龙","id": "thunder dragon",]), 
  (["name": HIW"狂龙","id": "mad dradon",]), 
  (["name": HIW"暴龙","id": "fury dragon",]), 
  (["name": HIW"神龙","id": "deity dragon",]), 
  (["name": HIW"光明","id": "light",]), 
  (["name": HIW"黑暗","id": "dark",]),    
  (["name": HIW"邪恶","id": "evil",]),    
  (["name": HIW"正气","id": "justice",]),    
  (["name": HIR"精灵","id": "spirit",]),    
  (["name": HIR"天灵","id": "genius",]),    
  (["name": HIR"神灵","id": "jinni",]),    
  (["name": HIR"恶灵","id": "ahriman",]),    
  (["name": BLINK+HIR"天界","id": "sky circles",]),    
  (["name": BLINK+HIR"人界","id": "human circles",]),    
  (["name": BLINK+HIR"地界","id": "abuttals",]),    
  (["name": BLINK+HIR"神界","id": "gods circles",]),    
  (["name": BLINK+HIR"三界巫师","id": "sanjie koradji",]), 
  (["name": BLINK+HIR"三界巫神","id": "sanjie powwow",]), 
  (["name": BLINK+HIR"三界天皇","id": "sanjie emperor",]), 
  (["name": BLINK+HIR"三界天神","id": "sanjie deity",]), 
 
}); 
varargs void updatename(string ty) 
{ 
    int i,ii, j,k,kk,ppl,hr,val; 
    mapping nkl,mkl; 
    string name,ad_type,type,idd,*kn,*id,long; 
   // k=random(100); 
   long="天地初开之时，盘古开天的时代已经出现一个神秘的大师，他掌握天地间古今所有灵物秘密，\n" 
         +"就此他制做的许多武器已成后世各种神魔使用的宝物利器，后来在三界他化作无形灵气四处游荡，\n" 
         +"于是三界就不断出现各种利器，此物乃其灵气所制，绝世罕有的武器！\n"; 
    
    for (j = 0;j < 8; j++)  
        {  
    
       if(random((j+1)*(j+1)*20) < 5) 
       { 
        i=random(4)+j*4; 
        ppl=1; 
        break;  
        } 
        } 
        if(ppl!=1)  i=random(8); 
     
        nkl=base_names[i]; 
//       ty=query("skill_type"); 
        name=nkl["name"]+name_type[ty]+NOR; 
        id=({nkl["id"]+" "+ty,ty}); 
        set("weapon_prop/damage", (48+i*2+random(i+1))); 
        set("w_lvl",i); 
        long +="此乃一"+query("unit")+nkl["name"]+name_type[ty]+"。\n"+NOR; 
        hr=(48+i*2+random(i+1))*10; 
        val=(i+1)*200000+((random(i+1))*20000); 
      for(kk=0;kk<sizeof(s_type);kk++) 
       { 
        if(random(100)>80) 
        { 
                        ppl=0; 
                         for (j = 0;j < 9; j++)  
                         {  
                      
                        if(random((j+1)*(j+1)*10) < 5) 
                        { 
                         ii=j; 
                         ppl=1; 
                         break;  
                         } 
                         } 
                         if(ppl!=1)ii=random(3); 
                ad_type=s_type[kk]+ii; 
                set("h_w_"+s_type[kk],ii); 
                val+=weapon_type[ad_type][WW_VALUE]; 
                hr+=(weapon_type[ad_type][WW_MAR])*10; 
                set("weapon_prop/"+s_type[kk]+"_damage",weapon_type[ad_type][WW_HARM]); 
                long +="此物具有"+weapon_type[ad_type][WW_NAME]+"特殊攻击,伤害值:  "+HIC+weapon_type[ad_type][WW_HARM]+"\n"+NOR; 
        } 
        } 
    set("weapon_scar",hr); 
    long +="此物损坏耐度值为:  "+hr+"度。\n"; 
    set("no_sell", 1); 
    set("long", long); 
    set("sell_value", val);
    set(name,id);
//      set("name",name);
//      set("id",id[0]);
 
}    
/* 
void changename(int i) 
{ 
    int j,k; 
    string name,*id; 
    object ob=this_object(); 
          if(i>27){ 
 
        j=i-28; 
        ob->set("is_monitored", 1); 
      }else if(i>20){ 
 
        j=i-21; 
        ob->set("is_monitored", 1); 
      }else if(i>13){ 
 
        j=i-14; 
       ob->set("is_monitored", 1); 
      }else if (i>7) 
         { 
         j=i-7; 
         ob->set("is_monitored", 1); 
        }else 
        { 
        j=i;} 
     ob->set("b_lvl",i+1); 
 
     
    name=b_names[i]+"宝石"; 
 
    id=({names[b_names[i]]+" baoshi","baoshi"}); 
 
    ob->set("baoshi",b_names[i]); 
 
    ob->set("reward_lvl",j+1); 
 
    if(j==0){ 
    ob->set_name(BLINK+HIR+name+NOR,id); } 
    if(j==1){ 
    ob->set_name(BLINK+HIB+name+NOR,id); } 
    if(j==2){ 
    ob->set_name(BLINK+HIG+name+NOR,id); } 
    if(j==3){ 
    ob->set_name(BLINK+HIC+name+NOR,id); } 
    if(j==4){ 
    ob->set_name(BLINK+HIY+name+NOR,id); } 
    if(j==5){ 
    ob->set_name(BLINK+HIM+name+NOR,id); } 
    if(j==6){ 
    ob->set_name(BLINK+YEL+name+NOR,id); } 
    if(j==7){ 
    ob->set_name(BLINK+YEL+name+NOR,id); } 
} 
*/ 
 

