/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : nature.h
 * Author : Clode@RevivalWorld
 * Date   : 
 * Note   : INCLUDE file
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */

#define EVENT			1	// 事件
#define CURRENT_WEATHER		2	// 目前天氣
#define CURRENT_DISASTER	3	// 目前災難
#define WEATHER_QUEUE		4	// 天氣排序
#define DISASTER_QUEUE		5	// 災難排序
#define TEMPERATURE		6	// 溫度
#define HUMIDITY		7	// 溼度
#define WIND			8	// 風速
#define NEXTTIME_ARRANGE	9	// 排序

// 季節定義, 將溫差拉大形成較鮮明的溫度變化
#define SEASON_ELEMENT			0
#define SEASON_TEMPERATURE_LOW		1
#define SEASON_TEMPERATURE_HIGH		2
#define SEASON_SUNRISE_HOUR		3
#define SEASON_SUNSET_HOUR		4

#define SEASON_DATA				\
([						\
	SPRING	:	({ WE_SPRING, 14, 28, 6, 18 }),	\
	SUMMER	:	({ WE_SUMMER, 22, 38, 5, 19 }),	\
	AUTUMN	:	({ WE_AUTUMN,  8, 24, 6, 18 }),	\
	WINTER	:	({ WE_WINTER, -2 ,16, 7, 17 }),	\
])

// 天氣四元素
#define WE_SPRING		(1<<0)  // 季節
#define WE_SUMMER		(1<<1)
#define WE_AUTUMN		(1<<2)
#define WE_WINTER		(1<<3)
#define WE_HUMIDITY_0		(1<<4)	// 溼度
#define WE_HUMIDITY_1		(1<<5)
#define WE_HUMIDITY_2		(1<<6)
#define WE_HUMIDITY_3		(1<<7)
#define WE_WIND_0		(1<<8)	// 風速
#define WE_WIND_1		(1<<9)
#define WE_WIND_2		(1<<10)
#define WE_WIND_3		(1<<11)
#define WE_TEMPERATURE_0	(1<<12)	// 溫度
#define WE_TEMPERATURE_1	(1<<13)
#define WE_TEMPERATURE_2	(1<<14)
#define WE_TEMPERATURE_3	(1<<15)
#define WE_ALL_SEASON		(WE_SPRING | WE_SUMMER | WE_AUTUMN | WE_WINTER)
#define WE_ALL_HUMIDITY		(WE_HUMIDITY_0 | WE_HUMIDITY_1 | WE_HUMIDITY_2 | WE_HUMIDITY_3)
#define WE_ALL_WIND		(WE_WIND_0 | WE_WIND_1 | WE_WIND_2 | WE_WIND_3)
#define WE_ALL_TEMPERATURE	(WE_TEMPERATURE_0 | WE_TEMPERATURE_1 | WE_TEMPERATURE_2 | WE_TEMPERATURE_3)

// 溫度層級
#define TEMPERATURE_LV_0	-2..6
#define TEMPERATURE_LV_1	7..16
#define TEMPERATURE_LV_2	17..26
#define TEMPERATURE_LV_3	27..38


// 災害狀態定義
#define DISASTER_CHINESE	0
#define DISASTER_ID		1
#define DISASTER_OCCUR_TERM	2
#define DISASTER_OCCUR_PROB	3

// 各種災難
#define DISASTER_ARIDITY	({ "乾旱", ARIDITY, WE_HUMIDITY_0 | WE_HUMIDITY_1 | WE_TEMPERATURE_3 | WE_ALL_WIND, 50 })
#define DISASTER_FLOOD		({ "洪水", FLOOD, WE_HUMIDITY_3 | WE_ALL_TEMPERATURE | WE_ALL_WIND, 50 })
#define DISASTER_COLD		({ "寒流", COLD, WE_HUMIDITY_0 | WE_HUMIDITY_1 | WE_TEMPERATURE_0 | WE_ALL_WIND, 100 })
#define DISASTER_THUNDER	({ "落雷", THUNDER, WE_HUMIDITY_2 | WE_HUMIDITY_3 | WE_TEMPERATURE_2 | WE_TEMPERATURE_3 | WE_ALL_WIND, 100 })
#define DISASTER_TORNADO	({ "颶風", TORNADO, WE_HUMIDITY_2 | WE_HUMIDITY_3 | WE_ALL_TEMPERATURE | WE_WIND_3, 50 })
#define DISASTER_FIRE		({ "火災", FIRE, WE_HUMIDITY_0 | WE_ALL_TEMPERATURE | WE_ALL_WIND, 50 })
#define DISASTER_HAILSTONE	({ "冰雹", HAILSTONE, WE_HUMIDITY_3 | WE_TEMPERATURE_0 | WE_TEMPERATURE_1 | WE_ALL_WIND, 10 })
#define DISASTER_EARTHQUAKE	({ "地震", EARTHQUAKE, WE_ALL_HUMIDITY | WE_ALL_TEMPERATURE | WE_ALL_WIND, 2})
#define DISASTER_ERUPTION	({ "火山爆發", ERUPTION, WE_ALL_HUMIDITY | WE_ALL_TEMPERATURE | WE_ALL_WIND, 1})
#define DISASTER_METEORITE	({ "隕石襲擊", METEORITE, WE_ALL_HUMIDITY | WE_ALL_TEMPERATURE | WE_ALL_WIND, 1})

// 天氣狀態定義
#define WEATHER_CHINESE			0
#define WEATHER_ID			1
#define WEATHER_PROBABILITY		2
#define WEATHER_OCCUR_TERM		3
#define WEATHER_HOLDTIME_TERM		4
#define WEATHER_RELATED_DISASTER	5

// 各種天氣

#define WEATHER_SUNNY		({								\
	"晴朗", SUNNY,	10,									\
	WE_ALL_SEASON | WE_HUMIDITY_0 | WE_HUMIDITY_1 | WE_ALL_WIND | WE_ALL_TEMPERATURE,	\
	([ 3:5, 4:5, 6:5, 12:3, 24:3 ]),							\
	({ DISASTER_ARIDITY }), 								\
				})

#define WEATHER_CLOUDY		({								\
	"陰天",	CLOUDY,	10,									\
	WE_ALL_SEASON | WE_HUMIDITY_1 | WE_HUMIDITY_2 | WE_ALL_WIND | WE_ALL_TEMPERATURE,	\
	([ 3:6, 4:6, 6:4, 12:3, ]),								\
	({ }),											\
				})

#define WEATHER_RAINY		({								\
	"雨天",	RAINY,	10,									\
	WE_ALL_SEASON | WE_HUMIDITY_1 | WE_HUMIDITY_2 | WE_ALL_WIND | WE_ALL_TEMPERATURE,	\
	([ 3:3, 4:3, 6:2, 12:1 ]),								\
	({ DISASTER_FLOOD }),									\
				})

#define WEATHER_WINDY		({								\
	"強風",	WINDY, 10,									\
	WE_SUMMER | WE_HUMIDITY_0 | WE_WIND_2 | WE_WIND_3 | WE_TEMPERATURE_3,			\
	([ 3:3, 4:2, 6:1 ]),									\
	({ DISASTER_FIRE }),									\
				})
					
#define WEATHER_SNOWY		({								\
	"下雪",	SNOWY,	6,									\
	WE_SPRING | WE_WINTER | WE_HUMIDITY_2 | WE_HUMIDITY_3 | WE_ALL_WIND | WE_TEMPERATURE_0,		\
	([ 3:7, 4:6, 6:5, 12:3, 24:1 ]),							\
	({ DISASTER_COLD }),									\
				})

#define WEATHER_SHOWER		({								\
	"陣雨",	SHOWER,	6,									\
	WE_ALL_SEASON | WE_HUMIDITY_2 | WE_HUMIDITY_3 | WE_ALL_WIND | WE_TEMPERATURE_2 | WE_TEMPERATURE_3,	\
	([ 1:4, 2:3, 3:2, 4:1, ]),								\
	({ DISASTER_FLOOD, DISASTER_HAILSTONE, DISASTER_THUNDER }),				\
				})

#define WEATHER_TYPHOON		({								\
	"颱風",	TYPHOON, 3,									\
	WE_SUMMER | WE_AUTUMN | WE_HUMIDITY_2 | WE_HUMIDITY_3 | WE_WIND_3 | WE_TEMPERATURE_2 | WE_TEMPERATURE_3,\
	([ 6:3, 12:4, 24:3 ]),									\
	({ DISASTER_FLOOD, DISASTER_THUNDER, DISASTER_TORNADO }),				\
				})

#define WEATHER_FOEHN		({								\
	"焚風",	FOEHN, 3,									\
	WE_SUMMER | WE_HUMIDITY_0 | WE_WIND_2 | WE_WIND_3 | WE_TEMPERATURE_3,			\
	([ 3:3, 4:2, 6:1 ]),									\
	({ DISASTER_FIRE }),									\
				})

				
#define ALL_WEATHER 	({ WEATHER_SUNNY, WEATHER_CLOUDY, WEATHER_RAINY, WEATHER_SNOWY, WEATHER_SHOWER, WEATHER_TYPHOON, WEATHER_FOEHN, WEATHER_WINDY })


// 濕度機率
#define HUMIDITY_PROBABILITY	\
([\
	SPRING	:	([ WE_HUMIDITY_0 : 1, WE_HUMIDITY_1 : 1, WE_HUMIDITY_2 : 1, WE_HUMIDITY_3 : 1, ]),\
	SUMMER	:	([ WE_HUMIDITY_0 : 4, WE_HUMIDITY_1 : 1, WE_HUMIDITY_2 : 1, WE_HUMIDITY_3 : 4, ]),\
	AUTUMN	:	([ WE_HUMIDITY_0 : 2, WE_HUMIDITY_1 : 3, WE_HUMIDITY_2 : 4, WE_HUMIDITY_3 : 1, ]),\
	WINTER	:	([ WE_HUMIDITY_0 : 3, WE_HUMIDITY_1 : 2, WE_HUMIDITY_2 : 2, WE_HUMIDITY_3 : 3, ]),\
])

// 風速機率
#define WIND_PROBABILITY	\
([\
	SPRING	:	([ WE_WIND_0 : 2, WE_WIND_1 : 4, WE_WIND_2 : 3, WE_WIND_3 : 1 ]),\
	SUMMER	:	([ WE_WIND_0 : 3, WE_WIND_1 : 2, WE_WIND_2 : 2, WE_WIND_3 : 3 ]),\
	AUTUMN	:	([ WE_WIND_0 : 3, WE_WIND_1 : 4, WE_WIND_2 : 2, WE_WIND_3 : 1 ]),\
	WINTER	:	([ WE_WIND_0 : 3, WE_WIND_1 : 3, WE_WIND_2 : 2, WE_WIND_3 : 1 ]),\
])
