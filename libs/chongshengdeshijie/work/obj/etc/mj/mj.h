/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : mj.h
 * Author : Clode@RevivalWorld
 * Date   : 
 * Note   : INCLUDE file
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */

#define DATA_PATH	"/data/object/mj112.o"
#define MJAI_FILE 	"/obj/etc/mj/mjai.lpc"

#define VERSION 	"1.13"

// 一底
#define BASEMONEY	10000
// 一台
#define BONUSMONEY	4000

// Score Index
#define SCORE		0
#define ROUNDS		1
#define WINTIMES	2
#define GUNTIMES	3
#define BONUSES 	4
#define HUMYSELVES	5
#define LOSEBONUSES	6
#define LOSETIMES	7

// MJtile Index
#define CHINESE 	0
#define AMOUNT		1
#define COLOR1		2
#define COLOR2		3

// MJdata Index
#define PLAYING 	0	//遊戲中
#define TURN		1	//輪到位
#define DUMPED		2	//海底牌
#define DUMPING 	3	//打牌
#define MO		4	//摸牌
#define CHEAT		5	//詐胡
#define TILELIMIT	6	//流局張數
#define ROUND		7	//總圈數計算
#define MROUND		8	//莊圈數計算
#define WINNER		9	//上圈贏家
#define HUMYSELF	10	//自摸
#define HUFIRST 	11	//天胡
#define NINEYOUNGS	12	//九么九和
#define LOSER		13	//放槍
#define CMASTER 	14	//連莊次數
#define ROUNDWIND	15	//圈風
#define OPENDOOR	16	//開門
#define FINISH		17	//完成一圈
#define CFINISH 	18	//完全結束
#define KEYTILE 	19	//關鍵牌
#define LISTENING	20	//聽牌中
#define ONLOOKER	21	//旁觀者

// Pdata Index
#define PLAYER		0	//物件
#define ID		1	//純ID
#define IDNAME		2	//名稱
#define TILE		3	//主牌
#define OTILE		4	//門牌
#define FLOWER		5	//花牌
#define AUTOPON 	6	//自動碰
#define AUTOGON 	7	//自動槓
#define AUTOHU		8	//自動胡
#define LISTEN		9	//聽牌
#define TAILTILE	10	//摸尾
#define LOOKSEA 	11	//看海底
#define SECRETGON	12	//暗槓
#define MONEY		13	//籌碼
#define PLISTEN 	14	//自動聽牌
#define LISTENTYPE	15	//聽牌型態
#define AUTOOFF 	16	//自動關閉
#define FLOWERNUM	17	//花牌位
#define LOOKALL 	18	//看全部
#define AI		19	//AI玩家
#define PDUMPED		20	//個人打過的牌

// Psort Index
#define MASTER		0	//莊家位

#define TITLE_SCREEN_LENGTH	14
#define Dsort	({ "東","南","西","北" })
#define Tsort	({ "1w","2w","3w","4w","5w","6w","7w","8w","9w","1s","2s","3s","4s","5s","6s","7s","8s","9s","1t","2t","3t","4t","5t","6t","7t","8t","9t","ea","so","we","no","ba","jo","fa","f1","f2","f3","f4","f5","f6","f7","f8", })
