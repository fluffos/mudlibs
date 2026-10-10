// write by: dfbb 
// date 97/01/25

#ifndef __RANDOM_NAME_H__
#define __RANDOM_NAME_H__

string *first_name = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈",
	"刘","林","穆" });
string *name_words = ({ "顺","昌","振","发","财","俊","彦","良","志","忠",
	"孝","雄","益","添","金","辉","长","盛","胜","进","安","福","同","满",
	"富","万","龙","隆","祥","栋","国","亿","寿","汉","血" });

string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri","ne","she"});
string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});

string *nick_first_name = ({"追风","霹雳","无常","五行","闪电","无情",
        "飞凤","游龙","鸳鸯","七杀","疾风","幽冥","飞龙","冷血","追命",
	"快活","逍遥","长白一","昆仑一","河洛一","绝情","无极","忘情",
	"雷霆","急电","点苍一","中条一","江南一","神龙"});
string *nick_wea_name =({"刀","剑","手","斧","枪","戟","叉","锤","钩"});
string *all_color = ({HIR,HIY,HIG,HIB,HIM,HIW,HIC});

string get_rndname( );
string get_rndid( );
string get_rndnick();
 
string get_rndname( )
{
	string name;
	name = first_name[random(sizeof(first_name))];
	name += name_words[random(sizeof(name_words))];
	if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];

	return name;

}

string get_rndid( )
{
	string id;
        id = rnd_id[random(sizeof(rnd_id))];
        if( random(10) > 4 ) id += rnd_id[random(sizeof(rnd_id))];
        id += rnd_id_tail[random(sizeof(rnd_id_tail))];
	return id;
}

string get_rndnick( )
{
        string nickname;
        nickname = all_color[random(sizeof(all_color))]
                   +nick_first_name[random(sizeof(nick_first_name))];
        nickname +=all_color[random(sizeof(all_color))]+
                  nick_wea_name[random(sizeof(nick_wea_name))]+NOR;

        return nickname;  
 
}


#endif
