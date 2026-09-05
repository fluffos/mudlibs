//职业钓鱼配置，Zine
//diffculty是钓鱼的难度（1-10由难到易），size是鱼体形的大小。1-5（由小到大）决定重量和food_supply
//nutri是这条鱼的营养含量（1-5由小到大），决定成品的增益。value是市场价值，单位是coin
//fishing技能300级可以不借助外力（鱼竿加成）掉到难度10的鱼.鱼竿加成是query("assist_fishing"),0-300.
#include "ansi.h"
int gene_fish();
mapping * fish_ZHONGYUAN=({
                ([  "name":CYN+"青鱼"+NOR,"id":"qing yu","diffculty":3,"size": 3,"nutri":3,"value":200,]),
                ([  "name":HIG+"草鱼"+NOR,"id":"cao yu","diffculty":2,"size": 2,"nutri":2,"value":150,]),
                ([  "name":GRN+"鲢鱼"+NOR,"id":"lian yu","diffculty":1,"size": 2,"nutri":1,"value":50,]),
                ([  "name":HIC+"鳙鱼"+NOR,"id":"yong yu","diffculty":5,"size": 2,"nutri":4,"value":300,]),
                ([  "name":HIY+"鳡鱼"+NOR,"id":"gan yu","diffculty":6,"size": 1,"nutri":4,"value":310,]),
                ([  "name":GRN+"鳊鱼"+NOR,"id":"bian yu","diffculty":1,"size": 1,"nutri":1,"value":50,]),
                ([  "name":HIC+"鲂鱼"+NOR,"id":"fang yu","diffculty":5,"size": 3,"nutri":3,"value":250,]),
                ([  "name":HIR+"红鲌鱼"+NOR,"id":"hongbo yu","diffculty":7,"size": 2,"nutri":5,"value":400,]),
                ([  "name":HIM+"鲴鱼"+NOR,"id":"gu yu","diffculty":4,"size": 2,"nutri":2,"value":180,]),
                ([  "name":GRN+"马口鱼"+NOR,"id":"makou yu","diffculty":3,"size": 3,"nutri":3,"value":200,]),
                ([  "name":BLU+"鱲鱼"+NOR,"id":"lie yu","diffculty":6,"size": 1,"nutri":5,"value":600,]),
                ([  "name":GRN+"蛇鮈"+NOR,"id":"she ju","diffculty":7,"size": 1,"nutri":2,"value":400,]),
                ([  "name":GRN+"突吻鮈"+NOR,"id":"tuwen ju","diffculty":6,"size": 1,"nutri":2,"value":380,]),
                ([  "name":YEL+"鳅鮀"+NOR,"id":"qiu tuo","diffculty":3,"size": 2,"nutri":2,"value":250,]),
                ([  "name":HIW+"似白鮈"+NOR,"id":"sibai ju","diffculty":6,"size": 1,"nutri":4,"value":450,]),
                ([  "name":WHT+"似鮈"+NOR,"id":"si ju","diffculty":6,"size": 1,"nutri":4,"value":350,]),
                ([  "name":GRN+"颌须鮈"+NOR,"id":"hexu ju","diffculty":6,"size": 1,"nutri":3,"value":290,]),
                ([  "name":WHT+"鳈"+NOR,"id":"quan","diffculty":5,"size": 2,"nutri":5,"value":350,]),
                ([  "name":RED+"赤眼鳟"+NOR,"id":"chiyan zun","diffculty":8,"size": 3,"nutri":4,"value":500,]),
                ([  "name":GRN+"鳤"+NOR,"id":"guan","diffculty":4,"size": 2,"nutri":2,"value":280,]),
                ([  "name":HIY+"鯮鱼"+NOR,"id":"zong yu","diffculty":5,"size": 2,"nutri":3,"value":300,]),
                ([  "name":HIY+"鲖鱼"+NOR,"id":"tong yu","diffculty":4,"size": 3,"nutri":1,"value":250,]),
    });

mapping * fish_BEIFANG=({
                ([  "name":CYN+"狗鱼"+NOR,"id":"gou yu","diffculty":2,"size": 3,"nutri":2,"value":120,]),
                ([  "name":HIM+"雅罗鱼"+NOR,"id":"yaluo yu","diffculty":4,"size": 2,"nutri":5,"value":350,]),
                ([  "name":WHT+"银鲫"+NOR,"id":"yin ji","diffculty":3,"size": 2,"nutri":3,"value":280,]),
                ([  "name":HIC+"湖鱥"+NOR,"id":"hu gui","diffculty":6,"size": 3,"nutri":3,"value":320,]),
    });
              
mapping * fish_JIANGNAN=({
                ([  "name":HIY+"黄鳝"+NOR,"id":"huang shan","diffculty":7,"size": 1,"nutri":6,"value":300,]),
                ([  "name":CYN+"青鳉"+NOR,"id":"qing jiang","diffculty":3,"size": 3,"nutri":2,"value":250,]),
                ([  "name":GRN+"刺鳅"+NOR,"id":"ci qiu","diffculty":5,"size": 1,"nutri":4,"value":320,]),
                ([  "name":HIW+"胡子鲇"+NOR,"id":"huzi nian","diffculty":2,"size": 2,"nutri":2,"value":130,]),
                ([  "name":HIG+"鲮鱼"+NOR,"id":"ling yu","diffculty":4,"size": 2,"nutri":3,"value":150,]),
                ([  "name":YEL+"土鲮"+NOR,"id":"tu ling","diffculty":3,"size": 2,"nutri":4,"value":180,]),
    });

mapping * fish_XIBEI=({
                ([  "name":HIW+"七鳃鳗"+NOR,"id":"qisai man","diffculty":7,"size": 4,"nutri":3,"value":500,]),
                ([  "name":WHT+"鳇鱼"+NOR,"id":"huang yu","diffculty":8,"size": 5,"nutri":5,"value":550,]),
                ([  "name":GRN+"苏氏鮈"+NOR,"id":"sushi ju","diffculty":6,"size": 3,"nutri":4,"value":320,]),
                ([  "name":YEL+"泥鳅"+NOR,"id":"ni qiu","diffculty":5,"size": 2,"nutri":4,"value":230,]),
                ([  "name":HIW+"六须鲇"+NOR,"id":"liuxu nian","diffculty":5,"size": 3,"nutri":3,"value":200,]),
                ([  "name":HIW+"虎鱼"+NOR,"id":"hu yu","diffculty":4,"size": 3,"nutri":2,"value":180,]),
    });
mapping * fish_XINAN=({
                ([  "name":HIW+"方氏品唇鳅"+NOR,"id":"fangshi pinchunqiu","diffculty":8,"size": 2,"nutri":2,"value":500,]),
                ([  "name":WHT+"多鳞爬岩鳅"+NOR,"id":"duoling payanqiu","diffculty":7,"size": 2,"nutri":2,"value":450,]),
                ([  "name":GRN+"犁头鳅"+NOR,"id":"litou qiu","diffculty":6,"size": 1,"nutri":2,"value":320,]),
                ([  "name":HIG+"中华鲟"+NOR,"id":"zhonghua xun","diffculty":7,"size": 2,"nutri":4,"value":430,]),
                ([  "name":HIW+"鳗鲡"+NOR,"id":"man li","diffculty":6,"size": 3,"nutri":3,"value":300,]),
                ([  "name":HIW+"银鱼"+NOR,"id":"yin yu","diffculty":4,"size": 1,"nutri":4,"value":280,]),
                ([  "name":BLU+"长尾鮡"+NOR,"id":"changwei yao","diffculty":5,"size": 3,"nutri":2,"value":320,]),
    });
mapping * fish_SHANDI=({
                ([  "name":HIW+"细鳞鱼"+NOR,"id":"xiling yu","diffculty":3,"size": 2,"nutri":2,"value":200,]),
                ([  "name":WHT+"哲罗鱼"+NOR,"id":"zheluo yu","diffculty":5,"size": 3,"nutri":4,"value":450,]),
                ([  "name":GRN+"茴鱼"+NOR,"id":"hui yu","diffculty":4,"size": 2,"nutri":2,"value":220,]),
                ([  "name":HIM+"杜父鱼"+NOR,"id":"dufu yu","diffculty":7,"size": 2,"nutri":5,"value":430,]),
                ([  "name":HIW+"白鲑鱼"+NOR,"id":"baigui yu","diffculty":6,"size": 3,"nutri":4,"value":350,]),
                ([  "name":RED+"红点鲑"+NOR,"id":"hongdian gui","diffculty":6,"size": 3,"nutri":4,"value":380,]),
                ([  "name":WHT+"江鳕"+NOR,"id":"jiang xue","diffculty":3,"size": 2,"nutri":3,"value":220,]),
                ([  "name":HIG+"真鱥"+NOR,"id":"zhen gui","diffculty":4,"size": 3,"nutri":3,"value":250,]),
    });

mapping * fish_SEA=({
                ([  "name":YEL+"黄花鱼"+NOR,"id":"huanghua yu","diffculty":2,"size": 2,"nutri":2,"value":180,]),
                ([  "name":HIY+"带鱼"+NOR,"id":"dai yu","diffculty":2,"size": 3,"nutri":2,"value":190,]),
                ([  "name":GRN+"鱿鱼"+NOR,"id":"you yu","diffculty":3,"size": 1,"nutri":1,"value":150,]),
                ([  "name":BLU+"墨鱼"+NOR,"id":"mo yu","diffculty":3,"size": 1,"nutri":2,"value":200,]),
                ([  "name":HIW+"鳕鱼"+NOR,"id":"xue yu","diffculty":4,"size": 2,"nutri":3,"value":310,]),
                ([  "name":GRN+"鳗鱼"+NOR,"id":"man yu","diffculty":4,"size": 4,"nutri":3,"value":350,]),
                ([  "name":HIM+"三文鱼"+NOR,"id":"sanwen yu","diffculty":5,"size": 3,"nutri":5,"value":450,]),
                ([  "name":HIW+"石斑鱼"+NOR,"id":"shiban yu","diffculty":5,"size": 3,"nutri":5,"value":400,]),
                ([  "name":HIM+"偏口鱼"+NOR,"id":"biankou yu","diffculty":6,"size": 3,"nutri":2,"value":280,]),
                ([  "name":GRN+"马面鱼"+NOR,"id":"mamian yu","diffculty":7,"size": 2,"nutri":3,"value":300,]),
                ([  "name":HIW+"旗鱼"+NOR,"id":"qi yu","diffculty":8,"size": 5,"nutri":2,"value":300,]),
                ([  "name":HIB+"大乌贼"+NOR,"id":"da wuzei","diffculty":8,"size": 5,"nutri":1,"value":300,]),
                ([  "name":HIG+"大海龟"+NOR,"id":"da haigui","diffculty":9,"size": 4,"nutri":1,"value":480,]),
                ([  "name":HIR+"大龙虾"+NOR,"id":"da longxia","diffculty":9,"size": 3,"nutri":5,"value":600,]),
                ([  "name":RED+"蜘蛛蟹"+NOR,"id":"zhizhu xie","diffculty":9,"size": 4,"nutri":4,"value":650,]),
                ([  "name":WHT+"鲨鱼"+NOR,"id":"sha yu","diffculty":10,"size": 5,"nutri":2,"value":700,]),
    });
mapping * fish_NORMAL=({
                ([  "name":HIW+"鲤鱼"+NOR,"id":"li yu","diffculty":1,"size": 2,"nutri":2,"value":80,]),
                ([  "name":WHT+"草鲫"+NOR,"id":"cao ji","diffculty":1,"size": 2,"nutri":2,"value":80,]),
                ([  "name":HIG+"青鲩"+NOR,"id":"qing huan","diffculty":1,"size": 2,"nutri":2,"value":85,]),
    });

int gene_fish()
{
    object fish,ob=this_object();
    object env,user;
    string day_phase,area;
    mapping the_fish,*fishes,*fishes_normal;
    int coe1,coe2,coe3,fish_ability,i;
    if (!environment(ob))
    {
        return 1;
    }
    else if (!userp(environment(ob)))
    {
        return 1;
    }
    user=environment(ob);
    env=environment(user);
    day_phase=NATURE_D->get_current_day_phase();
    if (day_phase=="凌晨"||day_phase=="午夜")
    {
        coe1=200;
    }
    else if (day_phase=="正午"||day_phase=="晌午")
    {
        coe1=50;
    }
    else
    {
        coe1=125;
    }
    coe2=user->query_skill("fishing",1);
    coe3=(int)ob->query("assist_fishing");
    fish_ability=coe3+coe2+coe1;
    area=AREA_INFO->get_my_bigarea(user);
    if (area=="中原平原")
    {
        fishes=fish_ZHONGYUAN;
    }
    else if (area=="北方平原")
    {
        fishes=fish_BEIFANG;
    }
    else if (area=="江南平原")
    {
        fishes=fish_JIANGNAN;
    }
    else if (area=="西北地区")
    {
        fishes=fish_XIBEI;
    }
    else if (area=="西南地区")
    {
        fishes=fish_XINAN;
    }
    else if (area=="山地")
    {
        fishes=fish_SHANDI;
    }
    else if (area=="海岛")
    {
        fishes=fish_SEA;
    }
    else
    {
        area="未知区域";
        fishes=fish_NORMAL;
    }
    fishes_normal=fish_NORMAL;
    for (i=0;i<sizeof(fishes);i++)
    {
        if (fishes[i]["diffculty"]*20+fishes[i]["diffculty"]*(1+random(10))>fish_ability)
        {
            fishes-=({fishes[i]});
        }
    }
    if (!sizeof(fishes))
    {
        fishes=fish_NORMAL;
    }
    if (random(3000)<coe2*(8+random(3)))
    {
        the_fish=fishes[random(sizeof(fishes))];
    }
    else
    {
        the_fish=fishes_normal[random(sizeof(fishes_normal))];
    }
    if (!the_fish)
    {
        return 1;
    }
    if (wizardp(user))
    {
        tell_object(user,the_fish["name"]+"\t"+the_fish["id"]+"\n");
    }
    fish=new("/obj/fishing/fish");
    fish->set_name(the_fish["name"], ({the_fish["id"],"fish"}));
    fish->set_weight(the_fish["size"]*(4000+random(3000))+random(1000));
    fish->set("value",the_fish["value"]);
    fish->set("nutri",the_fish["nutri"]);
    fish->set("place",env);
    fish->set("big_area",area);
    fish->set("catcher",user->query("id"));
    fish->set("is_new_fish",1);
    fish->set("long","这是一条生长在"+area+"的"+fish->query("name")+"，"+user->query("name")+"("+capitalize(user->query("id"))+")在"+env->query("short")+"所获。\n");
    fish->move(user);
    message_vision(HIG+"$N"+HIG+"一提杆，钓到了一条$n"+HIG+"。\n"+NOR,user,fish);
    return the_fish["diffculty"];
}