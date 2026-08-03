// domain_cost.h	各可建房区域的地皮费。
// by Find.

nosave mapping domain_cost = ([
	"city"	: ([ "cost" : 9000000,	 // 2000 gold.
			     "max"  : 10,      //此区域最多可建 10 套房子。
			     		      //-1 代表不限制数量,此区域内
			     		      //只要符合建房条件的地方就可以建.
			     "min_level" : 3, //在此区域建房要求的最低房屋等级.
			     ]),              //1 就代表不限制最低房屋等级了.

	"kaifeng"	: ([ "cost" :  6000000,	// 1800 gold.
			     "max"  :  6,
			     "min_level" : 2,
			     ]),

/*
	"fengtian"	: ([ "cost" :  6000000,	// 1800 gold.
			     "max"  :  6,
			     "min_level" : 2,
			     ]),


	"hangzhou"	: ([ "cost" :  5000000,	// 1500 gold.
			     "max"  :  6,
			     "min_level" : 2,
			     ]),

	"datong"	: ([ "cost" :  4000000,	// 900 gold.
			     "max"  :  3,
			     "min_level" : 2,
			     ]),

	"path1"		: ([ "cost" :  3000000,	// 900 gold.
			     "max"  :  20,
			     "max_level" : 2, //在此区域建房的最高房屋等级.
			     ]),	      //4 就代表不限制最高房屋等级了.

	"lumaji"	: ([ "cost" :  3000000,
			     "max"  :  4,
			     "max_level" : 2,
			     ]),

	"zuojiacun"	: ([ "cost" :  3000000,
			     "max"  :  5,
			     "max_level" : 2,
			     ]),

	"tianshui"	: ([ "cost" :  3000000,
			     "max"  :  3,
			     "max_level" : 3,
			     ]),

	"path2"		: ([ "cost" :  3000000,	// 900 gold.
			     "max"  :  20,
			     "max_level" : 2,
			     ]),
*/
]);
