#define BASEPPLNUM 200
#define MAXPPLNUMRATE 0.2
#define FROOMA( x , y , z) "/sgdomain/base/base_server/"+ x +"/"+ y +"/"+ z

#define S_NORMAL	0
#define S_NOLEADER	-1	// no lead
#define S_NOHEAD	-2	// no head
#define S_NOPPL		-3	// no ppl
#define S_NOSOURCESTUFF		-4	// 缺乏原料

#define P_NORMAL	0
#define P_ASKWINE	-1	// ppl want some wine
#define P_ASKMEAT	-2	// ppl want some meat
#define P_ASKRAISE	-3	// head want more salary
