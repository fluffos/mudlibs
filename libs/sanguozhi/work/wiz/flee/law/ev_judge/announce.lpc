#include <ansi.h>

nosave protected string *title = ({"丞相","太尉","大司空","太仆卿","太常卿",
                                "鸿胪卿","廷尉卿","卫尉卿","宗正卿","司农卿" });

void announce_elect_result(string *ss, int turn);
void call_for_meeting(string *ss);
void announce_process(int tt);
void announce_start();
void call_for_ministers(string *ss);
void announce_end();
void announce_nojudge(string k);
void announce_who_win(string k);
void announce_who_lose(string k);
void announce_end_meeting();
void call_for_judge();

void announce_elect_result(string *ss, int turn)
{    
    string str  = "%^H_YELLOW%^【东汉宫廷】%^H_RED%^国舅%^H_CYAN%^董承：\n";
    string *msg = ({ 	"%^H_RED%^国舅%^H_CYAN%^董承：吾皇万岁万万岁，臣有一本，启奏陛下。%^RESET%^\n",
			"%^H_CYAN%^汉献帝：念。%^RESET%^\n",
			"%^H_RED%^国舅%^H_CYAN%^董承：是。%^RESET%^\n",
			"%^H_RED%^国舅%^H_CYAN%^董承：孝灵皇帝，早弃臣民，皇帝承嗣，海内仰望。而帝年少，威仪\n                      不恪，难免居丧慢惰。宜择良臣，为其锦囊，辅佐朝纲，应天\n                      顺人，以慰生灵之望。%^RESET%^\n",
			"%^H_CYAN%^汉献帝羞得满脸通红，恨不得找个地缝钻进去。%^RESET%^\n",
			"%^H_CYAN%^汉献帝：善，如此寡人便降一诏，国舅代为宣读罢。%^RESET%^\n",
			"%^H_CYAN%^片刻后。。。%^RESET%^\n\n",
			"%^H_RED%^国舅%^H_CYAN%^董承：奉天承运，皇帝诏曰。寡人顺应天命，择良臣而为肱股，众卿\n"+"                      听封：%^RESET%^\n\n", });
    if ( !turn||!intp(turn) ) turn = 0;
    if ( turn>=sizeof(msg) ) {
          foreach ( string s in ss ) {
              str +=    HIC+"                      赐  "+HIG+
			COUNTRY_D->get_country(CHAR_D->get_char(s, "nation"), "name")+
			AREA_D->get_area(CHAR_D->get_char(s, "area"),"name")+
			OFFICER_D->get_officer(CHAR_D->get_char(s, "ranklocal"),"name")+"，"+ 
			CHENGHU_D->query_char_jun(s)+"，"+NOR+
			CHAR_D->get_char(s, "name")+HIC+"君  "+HIY+
			title[CHAR_D->get_char(s,"rankroyal")]+HIC+"一职；"+NOR+"\n";
          }
	tell( users(), str+"%^RESET%^\n");
    } else {
    	tell( users(), "%^H_YELLOW%^【东汉宫廷】"+msg[turn] );
	turn ++;
	remove_call_out("announce_elect_result");
        call_out("announce_elect_result", 2, ss, turn);
    }
    return;
}
void call_for_meeting(string *ss)
{
    int i;
    string str  = "%^H_YELLOW%^【东汉宫廷】%^H_RED%^国舅%^H_CYAN%^董承：奉天承运，皇帝诏曰: 责\n                      ";
    foreach ( string s in ss ) {
	str += HIW+title[CHAR_D->get_char(s,"rankroyal")]+NOR+CHAR_D->get_char(s,"name")+"，";
        i++;
        if ( i == 3 ) {
     	    i = 0;
	    str += "\n                      ";
	}
    }
    tell(users(), str[0..sizeof(str)-2]+"速来晋见！" );
}
