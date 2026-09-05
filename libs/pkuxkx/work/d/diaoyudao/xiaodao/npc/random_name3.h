// write by: dfbb
// date 97/01/25

#ifndef __RANDOM_NAME_H__
#define __RANDOM_NAME_H__

string *first_name = ({


"左丘","东门","西门","佰赏","南官","山本","安达","相川","河村",
"桑田","冬月","伊藤","安井","佐々木","西园寺","藤堂","井伊","板部"
"朝仓","武田","大畑","永安","羽柴","铃木","宫崎","神崎","新岛",
"平冢","远山","上杉","上泉","小泉","大塩","远藤","林原","后藤",
"赤井","高野","福沢","冈田","渡辺","北原","星野","安在","胜村",
"华原","広末","豊川","本多","瀬戸","鹤田","镰田","吉野","山部",
"大伴","堀河","吉备","山上",


    });
string *name_mid=({
        "小",
        "大","二","三","四","五","六","七","八","九","十",
        "阿",
        "团",
        "生",
        "百",
        "铁","金","水","木","火",
        "常","久","有","无","多","少",
        "明","贵","虎","豹","庆","顺","云","飞","坚","翔","超",
        "为",
        "胜","横","平","弘","天","保","群","田",
        "鹏","龙","琨","纶","羽","柯","生","亮","浪","涛","波","峦","杰","剑",
        "英","雄","潜","胤","云","日","猛","威","令","云","峰","博","智","志",
        "檀","筇","冕","敬","载","麓","歌","哙","玄","征","轩","东","彪","虬",
        "劲","捷","永","海","景","航","晓","成","晟","玮","湘","宏","雪",
        "中","司","鼎","钟","柏","盈","慕","宇","云","天","立",
        "飞",
        });
string *name_words = ({
    "顺","昌","振","发","财","俊","彦","良","志","忠",
    "孝","雄","益","添","金","辉","长","盛","胜","进","安","福","同","满",
    "富","万","龙","隆","祥","栋","国","亿","寿","汉","血",
"忠","孝","礼","义","智","勇","仁","匡","宪","令","福","禄","大","小","晓",
"高","可","阿","金","世","克","叔","之","公","夫","时","若","庆","文","武",
"多","才","长","子","永","友","自","人","为","铁",
"霸","白","班","斌","宾","昌","超","诚","川","鼎","定","斗",
"法","飞","风","锋","钢","罡","贯","光","海","虎","华",
"浩","宏","济","坚","健","剑","江","进","杰","俊","康",
"良","麟","民","明","鸣","宁","培","启","强","荣","山",
"泰","涛","挺","伟","熙","祥","雄","旭",
"毅","瑜","羽","宇","岳","舟",
    });

string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri","ne","she",
    "sa","ba","ti","pe","ge","de","se","pk","lu","xi","dri","neo","the",
});
string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte",
"ph","ix","se","y","ty","d","dy","m","tee"
});

string *nick_first_name = ({"追风","霹雳","无常","五行","闪电","无情",
        "飞凤","游龙","鸳鸯","七杀","疾风","幽冥","飞龙","冷血","追命",
    "快活","逍遥","长白一","昆仑一","河洛一","绝情","无极","忘情",
    "雷霆","急电","点苍一","中条一","江南一","神龙",
    "南海","平原","辽东","川西","平阳","天外","独孤","飘雪","求败","无心","红粉","夕阳",
    });
string *nick_wea_name =({"刀","剑","手","斧","枪","戟","叉","锤","钩",
"霸","刀","剑","枪","鞭","索","红","娇","虎","豹","老人","客","侠","龙",
});
string *all_color = ({HIR,HIY,HIG,HIB,HIM,HIW,HIC});

string get_rndname();
string get_rndid();
string get_rndnick();

string get_rndname()
{
    string name;
    name = first_name[random(sizeof(first_name))];
    if( random(10) > 3 ) name += name_mid[random(sizeof(name_mid))];
    name += name_words[random(sizeof(name_words))];
    return name;

}

string get_rndid()
{
    string id;
        id = rnd_id[random(sizeof(rnd_id))];
        if( random(10) > 4 ) id += rnd_id[random(sizeof(rnd_id))];
        id += rnd_id_tail[random(sizeof(rnd_id_tail))];
    return id;
}

string get_rndnick()
{
        string nickname;
        nickname = all_color[random(sizeof(all_color))]
                   +nick_first_name[random(sizeof(nick_first_name))];
        nickname +=all_color[random(sizeof(all_color))]+
                  nick_wea_name[random(sizeof(nick_wea_name))]+NOR;

        return nickname;

}


#endif
/*
用法附例：//另可参见/adm/damons/named.c
#include <ansi.h>
#include <random_name.h>

    set_name(get_rndname(), ({get_rndid(), }));
    set("nickname", get_rndnick());
*/
