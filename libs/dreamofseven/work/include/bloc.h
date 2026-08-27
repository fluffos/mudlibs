#ifndef __BLOC_H__
#define __BLOC_H__

//
// 聯盟職務
//
string *__E_Bloc_Rank_Table__ = ({"none","first","second","presbyter",
				"third","fourth","fifth",
				"sixth","seventh","eighth",
				"ninth"});
// 原始聯盟職位表
string *CBlocRankTable = ({"沒有","總裁","副總裁","長老","大臣",
			"部長","副部長","組長","副組長",
			"組員","實習生" });

#define __BlocFileLocate__	"/data/bloc/"
#define __BlocInfoFile__	__BlocFileLocate__ + "bloc"
#define BlocData(x)		( __BlocFileLocate__ + x +".info" )

//string *__E_Bloc_Rank_Table__ = ({"director","deputy_director","presbyter",
//				"official","minister","vice_minister",
//				"chief","vice_chief","member",
//				"trainee"});

#define FIRST		1
#define SECOND		2
#define PRESBYTER	3
#define THIRD		4
#define FOURTH		5
#define FIFTH		6
#define SIXTH		7
#define SEVENTH		8
#define EIGHTH		9
#define NINTH		10

//
// 聯盟指令權限
//

string *__BLOC_CMDS_TABLE__ = ({"Void","creat","ruin","setrank","setcmds","setmark","creatroom","addmember","kickmember","show"});

#define BLOC_CMDS_Void		0	// 空無指令
#define BLOC_CMDS_CREAT		1	// 建立聯盟
#define BLOC_CMDS_RUIN		2	// 毀滅聯盟
#define BLOC_CMDS_SETRANK	3	// 設定聯盟各職務的名稱
#define BLOC_CMDS_SETCMDS	4	// 設定聯盟各職務的自訂指令
#define BLOC_CMDS_SETMARK	5	// 建立聯盟的標誌
#define BLOC_CMDS_CREATROOM	6	// 建立聯盟房間
#define BLOC_CMDS_ADDMEMBER	7	// 增加成員
#define BLOC_CMDS_KICKMEMBER	8	// 刪除成員
#define BLOC_CMDS_SHOW		9	// 顯示聯盟資訊

#endif
