//Nanf 2011-03

string detail_desc = "
　　　　　　　　　  "RED"north_name"NOR"
　　　　　　　　　  "RED"north_id"NOR"
　　　　　　　　　　　　　　　　"BLK"north_left"NOR"
　　　　　　　　　　"RED"north_prepare"NOR"　"WHT"north_lord"NOR"
　　　　　　 　　"YEL"┏━━━━━━━┓"NOR"
　　　　　 "WHT"west_lord"NOR"　"YEL"┃"NOR"　　　"RED"北"NOR"　"BLINK+WHT"north_speak"NOR"　"YEL"┃"NOR"
　　　　　　　　 "YEL"┃"NOR""BLINK+WHT"west_speak"NOR"　　　　　　"YEL"┃"NOR"
　 "GRN"west_name"NOR"　"YEL"┃"NOR"　　　　　　　"YEL"┃"NOR"　"CYN"east_name"NOR"
　 "GRN"west_id"NOR"　"YEL"┃"NOR""GRN"西"NOR"　"BLK"is_playing"NOR"　"CYN"东"NOR""YEL"┃"NOR"　"CYN"east_id"NOR"
　　　　　 "GRN"west_prepare"NOR"　"YEL"┃"NOR"　　　　　　　"YEL"┃"NOR"　"CYN"east_prepare"NOR"　　"BLK"east_left"NOR"
　　　　　　 "BLK"west_left"NOR"　"YEL"┃"NOR"　　　　　　"BLINK+WHT"east_speak"NOR""YEL"┃"NOR"　"WHT"east_lord"NOR"
　　　　　　　　 "YEL"┃"NOR"　"BLINK+WHT"south_speak"NOR"　"BLU"南"NOR"　　　"YEL"┃"NOR"
　　　　　　　　 "YEL"┗━━━━━━━┛"NOR"
　　　　　　　　　 "WHT"south_lord"NOR"  "BLU"south_prepare"NOR"
　　　　　　　　　　　　　 "BLK"south_left"NOR"
　　　　　　　　　  "BLU"south_name"NOR"
　　　　　　　　　  "BLU"south_id"NOR"\n";

mapping table_seats = (["north":HIR"北面"NOR, "west":HIG"西面"NOR,"south":HIB"南面"NOR,"east":HIC"东面"NOR ]);
string* player_seats = ({"north","west","south","east"});

string* show_modes = ({"默认模式","花色模式","简单模式"});

#define JOKERA RED
#define JOKERB BLK
#define SPADE BLK
#define HEART RED
#define DIAMOND MAG
#define CLUB BLU

mapping *cards=({
	// 王
	([ 
		"name": HIY+BLINK " 大 王" NOR,
		"brief": RED"G "NOR,
		"desc": ({RED"J "NOR,RED"O "NOR,RED"K "NOR,RED"E "NOR,RED"R "NOR}),
		"group": "jokera",
		"rank": 17,
	]),
	([ 
		"name": HIW+BLINK " 小 王" NOR,
		"brief": BLK"H "NOR,
		"desc": ({BLK"J "NOR,BLK"O "NOR,BLK"K "NOR,BLK"E "NOR,BLK"R "NOR}),
		"group": "jokerb",
		"rank": 16,
	]),
	// 2
	([ 
		"name": SPADE" 黑桃2"NOR,
		"desc": ({CYN"2 "NOR,SPADE"  "NOR,SPADE"黑"NOR,SPADE"  "NOR,SPADE"桃"NOR}),
		"brief": "2 ",
		"group": "spade",
		"rank": 15,
	]),
	([ "name": HEART" 红桃2"NOR,
		"desc": ({CYN"2 "NOR,HEART"  "NOR,HEART"红"NOR,HEART"  "NOR,HEART"桃"NOR}),
		"brief": "2 ",
		"group": "heart",
		"rank": 15,
	]),
	([ 
		"name": CLUB" 梅花2"NOR,
		"desc": ({CYN"2 "NOR,CLUB"  "NOR,CLUB"梅"NOR,CLUB"  "NOR,CLUB"花"NOR}),
		"brief": "2 ",
		"group": "club",
		"rank": 15,
	]),
	([ 
		"name": DIAMOND" 方块2"NOR,
		"desc": ({CYN"2 "NOR,DIAMOND"  "NOR,DIAMOND"方"NOR,DIAMOND"  "NOR,DIAMOND"块"NOR}),
		"brief": "2 ",
		"group": "diamond",
		"rank": 15,
	]),
	// A
	([ 
		"name": SPADE" 黑桃A"NOR,
		"desc": ({CYN"A "NOR,SPADE"  "NOR,SPADE"黑"NOR,SPADE"  "NOR,SPADE"桃"NOR}),
		"brief": "A ",
		"group": "spade",
		"rank": 14,
	]),
	([ "name": HEART" 红桃A"NOR,
		"desc": ({CYN"A "NOR,HEART"  "NOR,HEART"红"NOR,HEART"  "NOR,HEART"桃"NOR}),
		"brief": "A ",
		"group": "heart",
		"rank": 14,
	]),
	([ 
		"name": CLUB" 梅花A"NOR,
		"desc": ({CYN"A "NOR,CLUB"  "NOR,CLUB"梅"NOR,CLUB"  "NOR,CLUB"花"NOR}),
		"brief": "A ",
		"group": "club",
		"rank": 14,
	]),
	([ 
		"name": DIAMOND" 方块A"NOR,
		"desc": ({CYN"A "NOR,DIAMOND"  "NOR,DIAMOND"方"NOR,DIAMOND"  "NOR,DIAMOND"块"NOR}),
		"brief": "A ",
		"group": "diamond",
		"rank": 14,
	]),
	// K
	([ 
		"name": SPADE" 黑桃K"NOR,
		"desc": ({CYN"K "NOR,SPADE"  "NOR,SPADE"黑"NOR,SPADE"  "NOR,SPADE"桃"NOR}),
		"brief": "K ",
		"group": "spade",
		"rank": 13,
	]),
	([ "name": HEART" 红桃K"NOR,
		"desc": ({CYN"K "NOR,HEART"  "NOR,HEART"红"NOR,HEART"  "NOR,HEART"桃"NOR}),
		"brief": "K ",
		"group": "heart",
		"rank": 13,
	]),
	([ 
		"name": CLUB" 梅花K"NOR,
		"desc": ({CYN"K "NOR,CLUB"  "NOR,CLUB"梅"NOR,CLUB"  "NOR,CLUB"花"NOR}),
		"brief": "K ",
		"group": "club",
		"rank": 13,
	]),
	([ 
		"name": DIAMOND" 方块K"NOR,
		"desc": ({CYN"K "NOR,DIAMOND"  "NOR,DIAMOND"方"NOR,DIAMOND"  "NOR,DIAMOND"块"NOR}),
		"brief": "K ",
		"group": "diamond",
		"rank": 13,
	]),
	// Q
	([ 
		"name": SPADE" 黑桃Q"NOR,
		"desc": ({CYN"Q "NOR,SPADE"  "NOR,SPADE"黑"NOR,SPADE"  "NOR,SPADE"桃"NOR}),
		"brief": "Q ",
		"group": "spade",
		"rank": 12,
	]),
	([ "name": HEART" 红桃Q"NOR,
		"desc": ({CYN"Q "NOR,HEART"  "NOR,HEART"红"NOR,HEART"  "NOR,HEART"桃"NOR}),
		"brief": "Q ",
		"group": "heart",
		"rank": 12,
	]),
	([ 
		"name": CLUB" 梅花Q"NOR,
		"desc": ({CYN"Q "NOR,CLUB"  "NOR,CLUB"梅"NOR,CLUB"  "NOR,CLUB"花"NOR}),
		"brief": "Q ",
		"group": "club",
		"rank": 12,
	]),
	([ 
		"name": DIAMOND" 方块Q"NOR,
		"desc": ({CYN"Q "NOR,DIAMOND"  "NOR,DIAMOND"方"NOR,DIAMOND"  "NOR,DIAMOND"块"NOR}),
		"brief": "Q ",
		"group": "diamond",
		"rank": 12,
	]),
	// J
	([ 
		"name": SPADE" 黑桃J"NOR,
		"desc": ({CYN"J "NOR,SPADE"  "NOR,SPADE"黑"NOR,SPADE"  "NOR,SPADE"桃"NOR}),
		"brief": "J ",
		"group": "spade",
		"rank": 11,
	]),
	([ "name": HEART" 红桃J"NOR,
		"desc": ({CYN"J "NOR,HEART"  "NOR,HEART"红"NOR,HEART"  "NOR,HEART"桃"NOR}),
		"brief": "J ",
		"group": "heart",
		"rank": 11,
	]),
	([ 
		"name": CLUB" 梅花J"NOR,
		"desc": ({CYN"J "NOR,CLUB"  "NOR,CLUB"梅"NOR,CLUB"  "NOR,CLUB"花"NOR}),
		"brief": "J ",
		"group": "club",
		"rank": 11,
	]),
	([ 
		"name": DIAMOND" 方块J"NOR,
		"desc": ({CYN"J "NOR,DIAMOND"  "NOR,DIAMOND"方"NOR,DIAMOND"  "NOR,DIAMOND"块"NOR}),
		"brief": "J ",
		"group": "diamond",
		"rank": 11,
	]),
	// 10
	([ 
		"name": SPADE" 黑桃10"NOR,
		"desc": ({CYN"10"NOR,SPADE"  "NOR,SPADE"黑"NOR,SPADE"  "NOR,SPADE"桃"NOR}),
		"brief": "10 ",
		"group": "spade",
		"rank": 10,
	]),
	([ "name": HEART" 红桃10"NOR,
		"desc": ({CYN"10"NOR,HEART"  "NOR,HEART"红"NOR,HEART"  "NOR,HEART"桃"NOR}),
		"brief": "10 ",
		"group": "heart",
		"rank": 10,
	]),
	([ 
		"name": CLUB" 梅花10"NOR,
		"desc": ({CYN"10"NOR,CLUB"  "NOR,CLUB"梅"NOR,CLUB"  "NOR,CLUB"花"NOR}),
		"brief": "10 ",
		"group": "club",
		"rank": 10,
	]),
	([ 
		"name": DIAMOND" 方块10"NOR,
		"desc": ({CYN"10"NOR,DIAMOND"  "NOR,DIAMOND"方"NOR,DIAMOND"  "NOR,DIAMOND"块"NOR}),
		"brief": "10 ",
		"group": "diamond",
		"rank": 10,
	]),
	// 9
	([ 
		"name": SPADE" 黑桃9"NOR,
		"desc": ({CYN"9 "NOR,SPADE"  "NOR,SPADE"黑"NOR,SPADE"  "NOR,SPADE"桃"NOR}),
		"brief": "9 ",
		"group": "spade",
		"rank": 9,
	]),
	([ "name": HEART" 红桃9"NOR,
		"desc": ({CYN"9 "NOR,HEART"  "NOR,HEART"红"NOR,HEART"  "NOR,HEART"桃"NOR}),
		"brief": "9 ",
		"group": "heart",
		"rank": 9,
	]),
	([ 
		"name": CLUB" 梅花9"NOR,
		"desc": ({CYN"9 "NOR,CLUB"  "NOR,CLUB"梅"NOR,CLUB"  "NOR,CLUB"花"NOR}),
		"brief": "9 ",
		"group": "club",
		"rank": 9,
	]),
	([ 
		"name": DIAMOND" 方块9"NOR,
		"desc": ({CYN"9 "NOR,DIAMOND"  "NOR,DIAMOND"方"NOR,DIAMOND"  "NOR,DIAMOND"块"NOR}),
		"brief": "9 ",
		"group": "diamond",
		"rank": 9,
	]),
	// 8
	([ 
		"name": SPADE" 黑桃8"NOR,
		"desc": ({CYN"8 "NOR,SPADE"  "NOR,SPADE"黑"NOR,SPADE"  "NOR,SPADE"桃"NOR}),
		"brief": "8 ",
		"group": "spade",
		"rank": 8,
	]),
	([ "name": HEART" 红桃8"NOR,
		"desc": ({CYN"8 "NOR,HEART"  "NOR,HEART"红"NOR,HEART"  "NOR,HEART"桃"NOR}),
		"brief": "8 ",
		"group": "heart",
		"rank": 8,
	]),
	([ 
		"name": CLUB" 梅花8"NOR,
		"desc": ({CYN"8 "NOR,CLUB"  "NOR,CLUB"梅"NOR,CLUB"  "NOR,CLUB"花"NOR}),
		"brief": "8 ",
		"group": "club",
		"rank": 8,
	]),
	([ 
		"name": DIAMOND" 方块8"NOR,
		"desc": ({CYN"8 "NOR,DIAMOND"  "NOR,DIAMOND"方"NOR,DIAMOND"  "NOR,DIAMOND"块"NOR}),
		"brief": "8 ",
		"group": "diamond",
		"rank": 8,
	]),
	// 7
	([ 
		"name": SPADE" 黑桃7"NOR,
		"desc": ({CYN"7 "NOR,SPADE"  "NOR,SPADE"黑"NOR,SPADE"  "NOR,SPADE"桃"NOR}),
		"brief": "7 ",
		"group": "spade",
		"rank": 7,
	]),
	([ "name": HEART" 红桃7"NOR,
		"desc": ({CYN"7 "NOR,HEART"  "NOR,HEART"红"NOR,HEART"  "NOR,HEART"桃"NOR}),
		"brief": "7 ",
		"group": "heart",
		"rank": 7,
	]),
	([ 
		"name": CLUB" 梅花7"NOR,
		"desc": ({CYN"7 "NOR,CLUB"  "NOR,CLUB"梅"NOR,CLUB"  "NOR,CLUB"花"NOR}),
		"brief": "7 ",
		"group": "club",
		"rank": 7,
	]),
	([ 
		"name": DIAMOND" 方块7"NOR,
		"desc": ({CYN"7 "NOR,DIAMOND"  "NOR,DIAMOND"方"NOR,DIAMOND"  "NOR,DIAMOND"块"NOR}),
		"brief": "7 ",
		"group": "diamond",
		"rank": 7,
	]),
	// 6
	([ 
		"name": SPADE" 黑桃6"NOR,
		"desc": ({CYN"6 "NOR,SPADE"  "NOR,SPADE"黑"NOR,SPADE"  "NOR,SPADE"桃"NOR}),
		"brief": "6 ",
		"group": "spade",
		"rank": 6,
	]),
	([ "name": HEART" 红桃6"NOR,
		"desc": ({CYN"6 "NOR,HEART"  "NOR,HEART"红"NOR,HEART"  "NOR,HEART"桃"NOR}),
		"brief": "6 ",
		"group": "heart",
		"rank": 6,
	]),
	([ 
		"name": CLUB" 梅花6"NOR,
		"desc": ({CYN"6 "NOR,CLUB"  "NOR,CLUB"梅"NOR,CLUB"  "NOR,CLUB"花"NOR}),
		"brief": "6 ",
		"group": "club",
		"rank": 6,
	]),
	([ 
		"name": DIAMOND" 方块6"NOR,
		"desc": ({CYN"6 "NOR,DIAMOND"  "NOR,DIAMOND"方"NOR,DIAMOND"  "NOR,DIAMOND"块"NOR}),
		"brief": "6 ",
		"group": "diamond",
		"rank": 6,
	]),
	// 5
	([ 
		"name": SPADE" 黑桃5"NOR,
		"desc": ({CYN"5 "NOR,SPADE"  "NOR,SPADE"黑"NOR,SPADE"  "NOR,SPADE"桃"NOR}),
		"brief": "5 ",
		"group": "spade",
		"rank": 5,
	]),
	([ "name": HEART" 红桃5"NOR,
		"desc": ({CYN"5 "NOR,HEART"  "NOR,HEART"红"NOR,HEART"  "NOR,HEART"桃"NOR}),
		"brief": "5 ",
		"group": "heart",
		"rank": 5,
	]),
	([ 
		"name": CLUB" 梅花5"NOR,
		"desc": ({CYN"5 "NOR,CLUB"  "NOR,CLUB"梅"NOR,CLUB"  "NOR,CLUB"花"NOR}),
		"brief": "5 ",
		"group": "club",
		"rank": 5,
	]),
	([ 
		"name": DIAMOND" 方块5"NOR,
		"desc": ({CYN"5 "NOR,DIAMOND"  "NOR,DIAMOND"方"NOR,DIAMOND"  "NOR,DIAMOND"块"NOR}),
		"brief": "5 ",
		"group": "diamond",
		"rank": 5,
	]),
	// 4
	([ 
		"name": SPADE" 黑桃4"NOR,
		"desc": ({CYN"4 "NOR,SPADE"  "NOR,SPADE"黑"NOR,SPADE"  "NOR,SPADE"桃"NOR}),
		"brief": "4 ",
		"group": "spade",
		"rank": 4,
	]),
	([ "name": HEART" 红桃4"NOR,
		"desc": ({CYN"4 "NOR,HEART"  "NOR,HEART"红"NOR,HEART"  "NOR,HEART"桃"NOR}),
		"brief": "4 ",
		"group": "heart",
		"rank": 4,
	]),
	([ 
		"name": CLUB" 梅花4"NOR,
		"desc": ({CYN"4 "NOR,CLUB"  "NOR,CLUB"梅"NOR,CLUB"  "NOR,CLUB"花"NOR}),
		"brief": "4 ",
		"group": "club",
		"rank": 4,
	]),
	([ 
		"name": DIAMOND" 方块4"NOR,
		"desc": ({CYN"4 "NOR,DIAMOND"  "NOR,DIAMOND"方"NOR,DIAMOND"  "NOR,DIAMOND"块"NOR}),
		"brief": "4 ",
		"group": "diamond",
		"rank": 4,
	]),
	// 3
	([ 
		"name": SPADE" 黑桃3"NOR,
		"desc": ({CYN"3 "NOR,SPADE"  "NOR,SPADE"黑"NOR,SPADE"  "NOR,SPADE"桃"NOR}),
		"brief": "3 ",
		"group": "spade",
		"rank": 3,
	]),
	([ "name": HEART" 红桃3"NOR,
		"desc": ({CYN"3 "NOR,HEART"  "NOR,HEART"红"NOR,HEART"  "NOR,HEART"桃"NOR}),
		"brief": "3 ",
		"group": "heart",
		"rank": 3,
	]),
	([ 
		"name": CLUB" 梅花3"NOR,
		"desc": ({CYN"3 "NOR,CLUB"  "NOR,CLUB"梅"NOR,CLUB"  "NOR,CLUB"花"NOR}),
		"brief": "3 ",
		"group": "club",
		"rank": 3,
	]),
	([ 
		"name": DIAMOND" 方块3"NOR,
		"desc": ({CYN"3 "NOR,DIAMOND"  "NOR,DIAMOND"方"NOR,DIAMOND"  "NOR,DIAMOND"块"NOR}),
		"brief": "3 ",
		"group": "diamond",
		"rank": 3,
	]),
	
});

mapping ranks = 
([
	"G":17,
	"g":17,
	"JOKER":17,
	"H":16,
	"h":16,
	"joker":16,
	"2":15,
	"A":14,
	"a":14,
	"1":14,
	"K":13,
	"k":13,
	"Q":12,
	"q":12,
	"J":11,
	"j":11,
	"0":10,
	"10":10,
	"9":9,
	"8":8,
	"7":7,
	"6":6,
	"5":5,
	"4":4,
	"3":3,
]);