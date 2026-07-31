#ifndef LIEBIAO_H
#define LIEBIAO_H

#define TMA "\x19"  //ASCII码25
#define TMB "\x1A"  //ASCII码26
#define TMI(x) (TMA+x+TMB)
#define ALERT(x) TMI("alert "+x)
#define L_NAME(x) RANK_D->new_name(x)
#define L_ITEM(x) RANK_D->new_short(x)
#define L_ICONS(x) TMI("licon "+RANK_D->new_short(x))
#define L_ICON(x) TMI("licon "+x)
#define CLEAN0  TMI("lbclear0")
#define ADD0(x) TMI("lbadd0 "+L_ITEM(x)+";")
#define REM0(x) TMI("lbrem0 "+L_ITEM(x)+";")
#define CLEAN1  TMI("lbclear1")
#define ADD1(x) TMI("lbadd1 "+L_ITEM(x)+";")
#define REM1(x) TMI("lbrem1 "+L_ITEM(x)+";")
#define CLEAN2  TMI("lbclear2")
#define ADD2(x) TMI("lbadd2 "+L_NAME(x)+";")            	
#define REM2(x) TMI("lbrem2 "+L_NAME(x)+";")
#define ADDWAY(x) TMI("bnway "+x+";")
#define PTEXT(x) TMI("ptext "+x+";")
#define MAP(x) TMI("map_t "+x)
#define LOOK(x) TMI("lookt "+x)
#define SHOWIETM(x) TMI("obmsg "+x)
#define SET(x) TMI("myset "+x)
#define HP(x) TMI("my_hp "+x)
#define CHECK(x) TMI("check "+x)
#define ROOMNAME(x) TMI("rname "+x)

#endif
