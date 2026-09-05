// File		: colord.c
// Created By	: iszt@pkuxkx, 2007-03-24
// Modified By : whuan@pkuxkx, 2008-08-21
// Modified By : Vast@pkuxkx, 2009-05-17 add function uncolor()

#include <ansi.h>
void create()
{
        seteuid(getuid());
}
string clean_color(string str)
{
    string prefix, suffix;
        int i;
        string  *color  =    ({ BLK,
                                RED,
                                GRN,
                                YEL,
                                BLU,
                                MAG,
                                CYN,
                                WHT,
                                HIR,
                                HIG,
                                HIY,
                                HIB,
                                HIM,
                                HIC,
                                HIW,
                                HBRED,
                                HBGRN,
                                HBYEL,
                                HBBLU,
                                HBMAG,
                                HBCYN,
                                HBWHT,
                                BBLK,
                                BRED,
                                BYEL,
                                BBLU,
                                BMAG,
                                BCYN,
                                NOR,
                                BNK });
    if (!stringp(str))
    return str;
    while (sscanf(str, "%s*sm%s", prefix, suffix) == 3)
    str = prefix + suffix;
    return str;
}

string uncolor(string msg)
{
	int n, i;
  string  *color  =    ({ BLK,
                          RED,
                          GRN,
                          YEL,
                          BLU,
                          MAG,
                          CYN,
                          WHT,
                          
                          HIK,
                          HIR,
                          HIG,
                          HIY,
                          HIB,
                          HIM,
                          HIC,
                          HIW,
                          
                          HBRED,
                          HBGRN,
                          HBYEL,
                          HBBLU,
                          HBMAG,
                          HBCYN,
                          HBWHT,
                          
                          BBLK,
                          BRED,
                          BGRN,
                          BYEL,
                          BBLU,
                          BMAG,
                          BCYN,
                          
                          NOR,
                          BNK });	 
	if( !msg ) return 0;
		
	n = sizeof(color);
	for(i = 0; i < n; i++)
	msg = replace_string(msg, color[i], "");
	
	return msg;
}

varargs string replace_color(string msg,int flag)
{
        msg = replace_string(msg, "$BLK$", flag?BLK:"");
        msg = replace_string(msg, "$RED$", flag?RED:"");
        msg = replace_string(msg, "$GRN$", flag?GRN:"");
        msg = replace_string(msg, "$YEL$", flag?YEL:"");
        msg = replace_string(msg, "$BLU$", flag?BLU:"");
        msg = replace_string(msg, "$MAG$", flag?MAG:"");
        msg = replace_string(msg, "$CYN$", flag?CYN:"");
        msg = replace_string(msg, "$WHT$", flag?WHT:"");
        msg = replace_string(msg, "$HIR$", flag?HIR:"");
        msg = replace_string(msg, "$HIG$", flag?HIG:"");
        msg = replace_string(msg, "$HIY$", flag?HIY:"");
        msg = replace_string(msg, "$HIB$", flag?HIB:"");
        msg = replace_string(msg, "$HIM$", flag?HIM:"");
        msg = replace_string(msg, "$HIC$", flag?HIC:"");
        msg = replace_string(msg, "$HIW$", flag?HIW:"");
        msg = replace_string(msg, "$NOR$", flag?NOR:"");
        msg = replace_string(msg, "$BNK$", flag?BNK:"");

        // Background color
        msg = replace_string(msg, "$BBLK$", BBLK);
        msg = replace_string(msg, "$BRED$", BRED);
        msg = replace_string(msg, "$BGRN$", BGRN);
        msg = replace_string(msg, "$BYEL$", BYEL);
        msg = replace_string(msg, "$BBLU$", BBLU);
        msg = replace_string(msg, "$BMAG$", BMAG);
        msg = replace_string(msg, "$BCYN$", BCYN);
// 77          msg = replace_string(msg, "$BWHT$", BWHT);
        msg = replace_string(msg, "$HBRED$", HBRED);
        msg = replace_string(msg, "$HBGRN$", HBGRN);
        msg = replace_string(msg, "$HBYEL$", HBYEL);
        msg = replace_string(msg, "$HBBLU$", HBBLU);
        msg = replace_string(msg, "$HBMAG$", HBMAG);
        msg = replace_string(msg, "$HBWHT$", HBWHT);
        msg = replace_string(msg, "$HBCYN$", HBCYN);
        if(flag) msg+=NOR;
        return msg;
}
// trans_color
// raw = 0, only forecolor
// raw = 1, include backround color
// raw = 2, include blink & others
string trans_color(string arg, int raw)
{
    // forecolor
    arg = replace_string(arg, "$BLK$", BLK);
    arg = replace_string(arg, "$RED$", RED);
    arg = replace_string(arg, "$GRN$", GRN);
    arg = replace_string(arg, "$YEL$", YEL);
    arg = replace_string(arg, "$BLU$", BLU);
    arg = replace_string(arg, "$MAG$", MAG);
    arg = replace_string(arg, "$CYN$", CYN);
    arg = replace_string(arg, "$WHT$", WHT);
    arg = replace_string(arg, "$HIR$", HIR);
    arg = replace_string(arg, "$HIG$", HIG);
    arg = replace_string(arg, "$HIY$", HIY);
    arg = replace_string(arg, "$HIB$", HIB);
    arg = replace_string(arg, "$HIM$", HIM);
    arg = replace_string(arg, "$HIC$", HIC);
    arg = replace_string(arg, "$HIW$", HIW);
    arg = replace_string(arg, "$NOR$", NOR);

    if (raw)
    {
        // Background color
        arg = replace_string(arg, "$BBLK$", BBLK);
        arg = replace_string(arg, "$BRED$", BRED);
        arg = replace_string(arg, "$BGRN$", BGRN);
        arg = replace_string(arg, "$BYEL$", BYEL);
        arg = replace_string(arg, "$BBLU$", BBLU);
        arg = replace_string(arg, "$BMAG$", BMAG);
        arg = replace_string(arg, "$BCYN$", BCYN);
        arg = replace_string(arg, "$HBRED$", HBRED);
        arg = replace_string(arg, "$HBGRN$", HBGRN);
        arg = replace_string(arg, "$HBYEL$", HBYEL);
        arg = replace_string(arg, "$HBBLU$", HBBLU);
        arg = replace_string(arg, "$HBMAG$", HBMAG);
        arg = replace_string(arg, "$HBCYN$", HBCYN);
    }

    if (raw == 2)
    {
        // special effect
        arg = replace_string(arg, "$U$", U);
        arg = replace_string(arg, "$BNK$", BNK);
        arg = replace_string(arg, "$REV$", REV);
        arg = replace_string(arg, "$HIREV$", HIREV);
        arg = replace_string(arg, "$BOLD$", BOLD);
    }

    arg += NOR;
    return arg;
}

/*
type: 1 : 随即底色
      2 : 随即底色加前景色
      3 : 随即暗色
      4 ：随即亮色
blink: 1 : 闪烁
*/
varargs string random_color(int type,int blink)
{
    string  *color_a  = ({  RED,
        GRN,
        YEL,
        BLU,
        MAG,
        CYN,
        HIR,
        HIG,
        HIY,
        HIB,
        HIM,
        HIC,
        HIW,
        WHT
        });

    string *color_b =   ({  BRED,
        BGRN,
        BYEL,
        BBLU,
        BMAG,
        BCYN,
        HBRED,
        HBGRN,
        HBYEL,
        HBBLU,
        HBMAG,
        HBCYN,
        HBWHT,
        });
    string co="";
    int co1,co2;
    if( blink ) co+=BNK;

    if( type==1 ) co+=color_b[random(sizeof(color_b))];
    else
    if( type==2 ) {
    co1=random(sizeof(color_b));
    co2=random(sizeof(color_a));
    while ( co1==co2 )
    {
    co1=random(sizeof(color_b));
    co2=random(sizeof(color_a));
    }
    co+=color_b[co1]+color_a[co2];
    }
    else
    if( type == 3 ) {
    if( random(6) )
    co1=random(6);
    else co1=13;
    co+=color_a[co1];
    }
    else
    if ( type == 4 ) {
    co1=6+random(7);
    co+=color_a[co1];
    }
    else    co+=color_a[random(sizeof(color_a))];

    return co;
}

string get_color(string arg)
{
    if( strsrch(arg,BLK)!=-1 ) return BLK;
    if( strsrch(arg,RED)!=-1 ) return RED;
    if( strsrch(arg,GRN)!=-1 ) return GRN;
    if( strsrch(arg,YEL)!=-1 ) return YEL;
    if( strsrch(arg,BLU)!=-1 ) return BLU;
    if( strsrch(arg,MAG)!=-1 ) return MAG;
    if( strsrch(arg,CYN)!=-1 ) return CYN;
    if( strsrch(arg,WHT)!=-1 ) return WHT;
    if( strsrch(arg,HIR)!=-1 ) return HIR;
    if( strsrch(arg,HIG)!=-1 ) return HIG;
    if( strsrch(arg,HIY)!=-1 ) return HIY;
    if( strsrch(arg,HIB)!=-1 ) return HIB;
    if( strsrch(arg,HIM)!=-1 ) return HIM;
    if( strsrch(arg,HIC)!=-1 ) return HIC;
    if( strsrch(arg,HIW)!=-1 ) return HIW;
    if( strsrch(arg,BNK)!=-1 ) return BNK;
    return "";
}

string transfer_color(string arg)
{
       if( arg=="BLK" ) return BLK;
       if( arg=="RED" ) return RED;
       if( arg=="GRN" ) return GRN;
       if( arg=="YEL" ) return YEL;
       if( arg=="BLU" ) return BLU;
       if( arg=="MAG" ) return MAG;
       if( arg=="CYN" ) return CYN;
       if( arg=="WHT" ) return WHT;
       if( arg=="HIR" ) return HIR;
       if( arg=="HIG" ) return HIG;
       if( arg=="HIY" ) return HIY;
       if( arg=="HIB" ) return HIB;
       if( arg=="HIM" ) return HIM;
       if( arg=="HIC" ) return HIC;
       if( arg=="HIW" ) return HIW;
       if( arg=="HBRED" ) return HBRED;
       if( arg=="HBGRN" ) return HBGRN;
       if( arg=="HBYEL" ) return HBYEL;
       if( arg=="HBBLU" ) return HBBLU;
       if( arg=="HBMAG" ) return HBMAG;
       if( arg=="HBCYN" ) return HBCYN;
       if( arg=="HBWHT" ) return HBWHT;
       if( arg=="BBLK" ) return BBLK;
       if( arg=="BRED" ) return BRED;
       if( arg=="BYEL" ) return BYEL;
       if( arg=="BBLU" ) return BBLU;
       if( arg=="BMAG" ) return BMAG;
       if( arg=="BCYN" ) return BCYN;
       if( arg=="NOR" ) return NOR;
       if( arg=="BNK" ) return BNK;
       return "";
}

string random_jjww()
{
string *jjww=({
"若有睡梦见莲华，及以梦见于繖盖",
"或复梦里见月轮，应当获得大利益",
"若有梦见佛形像，诸相具足庄严身",
"众生见者应欢喜，念当必作调御人",
"若此佛刹诸众生，令住信心及持戒",
"若此佛刹诸众生，令住信心于法行",
"若诸佛刹恒河沙，皆悉造寺求福故",
"若有佛刹如恒沙，皆悉遍施诸七宝",
"如铁围山高广大，造塔无量为诸佛",
"若诸众生具满劫，若头若髆常担戴",
"如是人等得胜法，若求菩提利众生",
"彼等众生最胜者，此无比类况有上",
"是故得闻此诸法，智者常生乐法心",
"当得无边大福聚，速得证于无上道"
});
    return WHT"佛云：“"+random_color(2)+jjww[random(sizeof(jjww))]+NOR+WHT+"”，";
}

string convert_color( string str )      
{
        string result_str;

        result_str = str;

        result_str = replace_string(result_str, "$BLK$", BLK);
        result_str = replace_string(result_str, "$RED$", RED);
        result_str = replace_string(result_str, "$GRN$", GRN);
        result_str = replace_string(result_str, "$YEL$", YEL);
        result_str = replace_string(result_str, "$BLU$", BLU);
        result_str = replace_string(result_str, "$MAG$", MAG);
        result_str = replace_string(result_str, "$CYN$", CYN);
        result_str = replace_string(result_str, "$WHT$", WHT);
        result_str = replace_string(result_str, "$HIR$", HIR);
        result_str = replace_string(result_str, "$HIG$", HIG);
        result_str = replace_string(result_str, "$HIY$", HIY);
        result_str = replace_string(result_str, "$HIB$", HIB);
        result_str = replace_string(result_str, "$HIM$", HIM);
        result_str = replace_string(result_str, "$HIC$", HIC);
        result_str = replace_string(result_str, "$HIW$", HIW);
        result_str = replace_string(result_str, "$NOR$", NOR);

        result_str = replace_string(result_str, "$BBLK$", BBLK);
        result_str = replace_string(result_str, "$BRED$", BRED);
        result_str = replace_string(result_str, "$BGRN$", BGRN);
        result_str = replace_string(result_str, "$BYEL$", BYEL);
        result_str = replace_string(result_str, "$BBLU$", BBLU);
        result_str = replace_string(result_str, "$BMAG$", BMAG);
        result_str = replace_string(result_str, "$BCYN$", BCYN);
//323          result_str = replace_string(result_str, "$BWHT$", BWHT);
        result_str = replace_string(result_str, "$BNK$", BNK);
        result_str = replace_string(result_str, "__$__", "$");

        return result_str;
}



//解决字符串有颜色后printf 对不齐的问题

string format_string( string str, int n )
{
        string sstr;
        int len;    
//        sstr = uncolor(str);   
        sstr = str;
        len=n-strwidth(uncolor(sstr));
        if( !stringp(sstr) || sizeof(sstr) < 1 ) return "";
        if( len<=0 ) return str;    
        
        //加n-sizeof(sstr) 个空格，补满 
        for( int i=0;i<len;i++) str += " ";
        
        return str;
}

int color_len(string str)
{
	int len;
	if(!str)
		return 0;
	len = strwidth(str);
	str = replace_string(str, BLK, "");
	str = replace_string(str, RED, "");
	str = replace_string(str, GRN, "");
	str = replace_string(str, YEL, "");
	str = replace_string(str, BLU, "");
	str = replace_string(str, MAG, "");
	str = replace_string(str, CYN, "");
	str = replace_string(str, WHT, "");

	str = replace_string(str, HIR, "");
	str = replace_string(str, HIG, "");
	str = replace_string(str, HIY, "");
	str = replace_string(str, HIB, "");
	str = replace_string(str, HIM, "");
	str = replace_string(str, HIC, "");
	str = replace_string(str, HIW, "");

	str = replace_string(str, BNK, "");
	str = replace_string(str, NOR, "");

	str = replace_string(str, BRED, "");
	str = replace_string(str, BGRN, "");
	str = replace_string(str, BYEL, "");
	str = replace_string(str, BBLU, "");
	str = replace_string(str, BMAG, "");
	str = replace_string(str, BCYN, "");
	str = replace_string(str, BBLK, "");
	str = replace_string(str, HBRED, "");
	str = replace_string(str, HBGRN, "");
	str = replace_string(str, HBYEL, "");
	str = replace_string(str, HBBLU, "");
	str = replace_string(str, HBMAG, "");
	str = replace_string(str, HBCYN, "");
	str = replace_string(str, HBWHT, "");

	str = replace_string(str, BOLD, "");

	return len - strwidth(str);
}
