// by fire on Jan 8 1998
// dunjia.c 遁甲天书
#include <ansi.h>
#include <sanguo.h>

inherit OBJ;
inherit M_GETTABLE;
inherit M_STUDYABLE;

string m_sk;
int m_lev;

int study_book()
{
  int p_res;
  string p_st;
  p_res=LEARNCHECK_D->check_can_learn_skills(m_sk,m_lev);
  this_body()->simple_action("$N翻开$o仔细阅读了半个时辰。\n",this_object());  
  switch(p_res)
  {
        case TOO_TIRED:
                this_body()->simple_action("$N想研究兵书，可瞌睡得连眼睛都睁不开。\n");
		break;
        case LESS_EXP:
                this_body()->simple_action("$N把书翻了半天，总是领会不了其中的奥妙。\n");
                break;
        case TOO_EASY:
                this_body()->simple_action("$N发现这本书太简单了。\n");
                break;
	case TOO_DIFFICULT:
		this_body()->simple_action("$N发现这本书太困难。\n");
		break;
	case LESS_LITERATE:
		this_body()->simple_action("$N文学修养不足，无法理解！\n");
		break;
	case 15:
		this_body()->simple_action("$N受基本修养所限，不能再学习这种技能了！\n");
		break;
        case CAN_LEARN:
                p_st=SG_SKILL_D->query_get(m_sk);
                this_body()->simple_action(p_st);
		DELAY_D->delay_simple_action(this_body(),"$N读完书，马上把它恭恭敬敬地书放回到了书架上。\n");
                break;
        default :
		SGSYS("return value from sk_learn_d is "+p_res);
                write("不知为什么你学不会，问问巫师吧。\n");
  }
  this_object()->remove();
  return 0;
}
void set_skill (string str) {
	m_sk=str;
}
void set_lev (int l) {
	m_lev=l;
}

void setup() {
    set_adj("装订精细的");
    set_unit("本");
    set_size(VERY_SMALL);
    set_id("cang shu");
    set_long("一本装订精细的皇室藏书，书页已经有点发黄。\n");
    set_study_action((: study_book :));
    set_gettable(1);
    set_can_drop(0);
    set_can_give(0);
}
