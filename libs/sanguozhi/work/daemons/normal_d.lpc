// normal_d.c write by fire on 26 Dec. 1997
// daemons NORMAL_D
#include <sanguo.h>
inherit M_DAEMON_DATA;
inherit CHINESE_DA;
int query_money_value(int number,string str)
{
        if ((number<0)||(number>1000000))
                return 0;
        switch(str)
        {
                case "coin" :
                        return number;
                case "silver" :
                        return number*100;
                case "gold" :
                        return number*10000;
                default :
                        return 0;
        }
}
mixed get_monster(object who,string m_id)
{
	object env;
        env=environment(who);
	if(!objectp(env))
{
		return 0;
}
	if (env->is_horse())
	{
		env=environment(env);
	}
        foreach (object ob2 in all_inventory(env)) 
	{
                if((ob2->attackable())&&(member_array(m_id, ob2->query_id()) !=-1))
		{
			return ob2;
		}
		if(ob2->is_horse())
                foreach(object ob3 in all_inventory(ob2)) 
                        if((ob3->attackable())&&(member_array(m_id,ob3->query_id()) != -1))
			{
				return ob3;
			}
	}
      return 0;
}
string get_dis1(int p_age, int p_gender)
{
        string p_tmp;
        int pp_age;
        pp_age=p_age/10;
        switch(pp_age)
        {
                case 0:
                        p_tmp="儿童";
                        break;
                case 1:
                        p_tmp="少年";
                        break;
                case 2:
                        p_tmp="青年";
                        break;
                case 3: 
                        p_tmp="成年";
                        break;
                case 4:
                        p_tmp="中年";
                        break;
                case 5:
                case 6:
                        p_tmp="壮年";
                        if(p_gender==2)
                                p_tmp="中年";
                        break;
                default :
                        p_tmp="老年";
        }
        switch(p_gender)
        {
                case 1:
                        p_tmp=p_tmp+"男子";
                        break;
                case 2:
                        p_tmp=p_tmp+"女子";
                        break;
                default :
                        p_tmp=p_tmp+"中性人";
        }
       return p_tmp;
}
string age_desc(object ob)
{
        int p_age;
        string p_head=ob->query_objective()+"看上去";
        string p_tmp;
       if(ob==this_body())
           return "";
        p_age=ob->query_age();
        if (p_age<10)
                p_head=p_head+"还不到十岁。\n";
        else
        {
                p_age=p_age/10;
                p_age=p_age*10;
                p_tmp="有"+chinese_number(p_age)+"多岁。\n";
                p_head=p_head+p_tmp;    
        }
        return p_head;
}
void remove_item_when_quit(object ob)
{
    if(!objectp(ob)) return;
    ob->put_m_all_money();
    foreach (object ob2 in all_inventory(ob)) {
	if (!ob2->query_is_keeping()) {
	    if (ob->query_link())
                ob->simple_action(
                "$N要离开三国时代，看看$o似乎无法带走，于是把它扔了。\n", ob2);
	    destruct(ob2);
	}
    }
}
string get_rongmao(int p_age,int p_rongmao, int p_gender )
{
        string p_res;
	int p_rand;
	if(p_rongmao==-1)
		return "";
        if(p_gender==1) // a male
        {
                if(p_age<20)
                {
                        if(p_rongmao<15)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "塌鼻小眼，头发凌乱，身材瘦削，一副无精打采的样子。\n";
				else
					return "佝头缩颈，双目无神，看上去不象是一个十几岁的少年。\n";
			}
			else if(p_rongmao<20)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "五官还算端正，但是没什么特别的地方。\n";
				else
					return "相貌平平，一眼看去不会给人留下什么印象。\n";
			}
			else if(p_rongmao<25)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "鼻直口方，虽然谈不上十分英俊，但也是一位翩翩少年。\n";
				else
					return "五官端正，身材匀称，虽然不是相貌出众，但也算俊朗。\n";
			}
		
			else
			{
				p_rand=random(2);
				if(p_rand)
	                                return "唇红齿白，身材挺拔，好一个英俊少年！\n";
				else
					return "面目俊朗，神采飞扬，实乃同辈中之姣姣者。\n";
			}
		}  // if(p_age<20)
		else if(p_age<40)
		{
                        if(p_rongmao<15)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "呲牙咧嘴，小眯缝眼，长得一副丑陋的样子。\n";
				else
					return "五短身材，面目可憎，令人看了不喜欢。\n";
			}
			else if(p_rongmao<20)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "相貌平平，没什么特别的地方。\n";
				else
					return "相貌平平，没有什么吸引人的地方。\n";
			}
			else if(p_rongmao<25)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "五官端正，虽不是英俊过人，但也相貌堂堂。\n";
				else
					return "相貌还算俊朗，身材也较匀称，举手投足，怡然自得。\n";
			}
		
			else
			{
				p_rand=random(2);
				if(p_rand)
	                                return "面如满月，目似朗星，顾盼之间，神采飞扬。\n";
				else
					return "英俊无比，举止潇洒，身材伟岸，气宇轩昂。\n";
			}
		}
		else if(p_age<60)
		{
                        if(p_rongmao<15)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "暴眼环睛，咀唇肥厚，实在是奇丑无比。\n";
				else
					return "相貌丑陋，身材佝偻，一副没精打采的样子。\n";
			}
			else if(p_rongmao<20)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "相貌一般，实在没什么与众不同的。\n";
				else
					return "五官还算齐整，但不会给人留下什么印象。\n";
			}
			else if(p_rongmao<25)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "五官棱角分明，面色红润，是一个气度不凡的中年男子。\n";
				else
					return "五官端正，满头乌发，只在两鬓处夹杂着些银色，别有一番气质。\n";
			}
		
			else
			{
				p_rand=random(2);
				if(p_rand)
	                                return "面容英俊，身材挺拔，令人想到他年轻时一定是世间少见的美男子。\n";
				else
					return "长得十分俊朗，额上微微的皱纹又凭添几分稳重，实在是英气逼人。\n";
			}
		}
		else 
		{
                        if(p_rongmao<15)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "面似橘皮，手若枯枝，象一截快风干的朽木。\n";
				else
					return "相貌平平，没有什么特别的地方。\n";
			}
			else if(p_rongmao<20)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "看上去平淡无奇，是一个平凡的老人。\n";
				else
					return "五官还算齐整，但不会给人留下什么印象。\n";
			}
			else if(p_rongmao<25)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "五官棱角分明，面色红润，是一个气度不凡的长者。\n";
				else
					return "五官端正，满头银发，别有一番气质。\n";
			}
		
			else
			{
				p_rand=random(2);
				if(p_rand)
	                                return "面容英俊，身材挺拔，令人想到他年轻时一定是世间少见的美男子。\n";
				else
					return "长得十分俊朗，额上微微的皱纹又凭添几分稳重，实在是英气逼人。\n";
			}
		}
	}  //        if(p_gender==1) // a male
	else
        {
                if(p_age<20)
                {
                        if(p_rongmao<15)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "身材瘦小，皮肤黝黑，没有人愿意看第二眼。\n";
				else
					return "发黄肤黑，爆牙细眼，小小年纪就长得一付老相。\n";
			}
			else if(p_rongmao<20)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "相貌平平，不会给人留下特别的印象。\n";
				else
					return "五官还算端正，没什么和别的女孩不同。\n";
			}
			else if(p_rongmao<25)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "柳眉杏眼，皮肤白晰，看上去长得不错。\n";
				else
					return "虽然不是貌美如花，但也颇有几分姿色。\n";
			}
		
			else
			{
				p_rand=random(2);
				if(p_rand)
	                                return "俏脸生春，妙目含情，娇柔无限，不可方物。\n";
				else
					return "体态婀娜，风情万种，小小年纪已经出落得楚楚动人，我见犹怜。\n";
			}
		}  // if(p_age<20)
		else if(p_age<40)
		{
                        if(p_rongmao<15)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "眼歪嘴斜，皮肤粗糙，是一个丑陋的女子。\n";
				else
					return "身材佝偻，五官不正，看来往后找不到婆家。\n";
			}
			else if(p_rongmao<20)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "相貌一般，实在长得平淡无奇。\n";
				else
					return "相貌平平，没有什么和别的女子不同的地方。\n";
			}
			else if(p_rongmao<25)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "面容清秀，仪态大方，颇有几分姿色。\n";
				else
					return "眉清目秀，举止大方，看上去颇有韵味。\n";
			}
		
			else
			{
				p_rand=random(2);
				if(p_rand)
	                                return "有沉鱼落雁之容，闭月羞花之貌，堪称是人间仙子。\n";
				else
					return "云鬓似墨，肌肤胜雪，不知倾倒了多少英雄豪杰。\n";
			}
		}
		else if(p_age<60)
		{
                        if(p_rongmao<15)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "体态臃肿，五官不正，是一个丑陋的中年妇女。\n";
				else
					return "相貌丑陋，令人生厌，没有人愿意多看一眼。\n";
			}
			else if(p_rongmao<20)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "相貌平平，看上去实在是长得一般。\n";
				else
					return "五官还算齐整，身形略显滞重，看上去是个平凡的中年妇人。\n";
			}
			else if(p_rongmao<25)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "面容尚是清秀，皮肤还算白晰，年轻时一定长得不错。\n";
				else
					return "虽然两鬓微白，但徐娘半老，风韵犹存。\n";
			}
		
			else
			{
				p_rand=random(2);
				if(p_rand)
	                                return "面容姣好，肌肤细腻，让人难以相信她的真实年龄。\n";
				else
					return "容颜艳丽，眉目传情，仪态大方，风情万种。\n";
			}
		}
		else 
		{
                        if(p_rongmao<15)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "面似橘皮，手若枯枝，象一截快风干的朽木。\n";
				else
					return "相貌平平，没有什么特别的地方。\n";
			}
			else if(p_rongmao<20)
			{
				p_rand=random(2);
				if(p_rand)
	                                return "看上去平淡无奇，是一个平凡的老女人。\n";
				else
					return "五官还算齐整，但不会给人留下什么印象。\n";
			}
		
			else
			{
					return "长得再好，终究老了，唉！\n";
			}
               }
	}  //        if(p_gender==1) // a male
	return "";
}
