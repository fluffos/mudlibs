#ifndef MAP_ENVIRONMENT_DEFS_H
#define MAP_ENVIRONMENT_DEFS_H

#define MAP_ENVIRONMENT_ARCTIC				1
#define MAP_ENVIRONMENT_BADLANDS			2
#define MAP_ENVIRONMENT_BAYOU				3
#define MAP_ENVIRONMENT_BEACH				4
#define MAP_ENVIRONMENT_BLIGHT				5
#define MAP_ENVIRONMENT_BOG				6
#define MAP_ENVIRONMENT_BRIDGE				7
#define MAP_ENVIRONMENT_CANYON				8
#define MAP_ENVIRONMENT_CASTLE				9
#define MAP_ENVIRONMENT_CAVE				10
#define MAP_ENVIRONMENT_CATACOMB			11
#define MAP_ENVIRONMENT_CITY				12
#define MAP_ENVIRONMENT_CLIFF				13
#define MAP_ENVIRONMENT_COAST				14
#define MAP_ENVIRONMENT_CRATER				15
#define MAP_ENVIRONMENT_DELTA				16
#define MAP_ENVIRONMENT_DESERT				17
#define MAP_ENVIRONMENT_DOCK				18
//#define MAP_ENVIRONMENT_DWARVEN			19
//#define MAP_ENVIRONMENT_ELVEN				20
#define MAP_ENVIRONMENT_GARDEN				21
#define MAP_ENVIRONMENT_GEYSER				22
#define MAP_ENVIRONMENT_GLACIER				23
//#define MAP_ENVIRONMENT_GOBLINOID			24
#define MAP_ENVIRONMENT_FARM				25
#define MAP_ENVIRONMENT_FOREST				26
#define MAP_ENVIRONMENT_HILLS				27
#define MAP_ENVIRONMENT_ISLAND				28
#define MAP_ENVIRONMENT_LAGOON				29
#define MAP_ENVIRONMENT_LAKE				30
#define MAP_ENVIRONMENT_LAVA				31
#define MAP_ENVIRONMENT_LIGHT_FOREST			32
#define MAP_ENVIRONMENT_MESA				33
#define MAP_ENVIRONMENT_MINE				34
#define MAP_ENVIRONMENT_MOUNTAIN			35
#define MAP_ENVIRONMENT_OASIS				36
#define MAP_ENVIRONMENT_OCEAN				37
#define MAP_ENVIRONMENT_PASS				38
#define MAP_ENVIRONMENT_PATH				39
#define MAP_ENVIRONMENT_PLAIN				40
#define MAP_ENVIRONMENT_PLATEAU				41
#define MAP_ENVIRONMENT_POLAR				42
#define MAP_ENVIRONMENT_POND				43
#define MAP_ENVIRONMENT_POOL				44
#define MAP_ENVIRONMENT_PRAIRIE				45
#define MAP_ENVIRONMENT_QUARRY				46
#define MAP_ENVIRONMENT_RAPID				47
#define MAP_ENVIRONMENT_RIDGE				48
#define MAP_ENVIRONMENT_RIVER				49
#define MAP_ENVIRONMENT_ROAD				50
#define MAP_ENVIRONMENT_RUINS				51
#define MAP_ENVIRONMENT_SHIRE				52
#define MAP_ENVIRONMENT_SINKHOLE			53
#define MAP_ENVIRONMENT_SHOP				54
#define MAP_ENVIRONMENT_SEWER				55
#define MAP_ENVIRONMENT_SPRING				56
#define MAP_ENVIRONMENT_STACK				57
#define MAP_ENVIRONMENT_STREAM				58
#define MAP_ENVIRONMENT_SWAMP				59
#define MAP_ENVIRONMENT_TAVERN				60
#define MAP_ENVIRONMENT_TOWN				61
#define MAP_ENVIRONMENT_TUNDRA				62
#define MAP_ENVIRONMENT_TUNNEL				63
#define MAP_ENVIRONMENT_UNDERGROUND			64
#define MAP_ENVIRONMENT_UNDERGROUND_LAKE		65
#define MAP_ENVIRONMENT_VALLEY				66
#define MAP_ENVIRONMENT_VILLAGE				67
#define MAP_ENVIRONMENT_VOLCANO				68
#define MAP_ENVIRONMENT_WATERFALL			69
#define MAP_ENVIRONMENT_WETLAND				70

#define MAP_COLORS ([\
	"maroon":	({1, "800000"}),\
	"green":	({2, "008000"}),\
	"olive":	({3, "808000"}),\
	"navy":		({4, "000080"}),\
	"purple":	({5, "800080"}),\
	"teal":		({6, "008080"}),\
	"silver":	({7, "C0C0C0"}),\
	"gray":		({8, "808080"}),\
	"red":		({9, "FF0000"}),\
	"lime":		({10, "00FF00"}),\
	"yellow":	({11, "FFFF00"}),\
	"blue":		({12, "0000FF"}),\
	"aqua":		({13, "00FFFF"}),\
	"fuchsia":	({14, "FF00FF"}),\
	"white":	({15, "FFFFFF"}),\
])

#define MAP_ENVIRONMENTS ([\
	MAP_ENVIRONMENT_ARCTIC:(["name":"Arctic","color":"white"]),\
	MAP_ENVIRONMENT_BADLANDS:(["name":"Badlands","color":"maroon"]),\
	MAP_ENVIRONMENT_BAYOU:(["name":"Bayou","color":"aqua"]),\
	MAP_ENVIRONMENT_BEACH:(["name":"Beach","color":"navy"]),\
	MAP_ENVIRONMENT_BLIGHT:(["name":"Blight","color":"maroon"]),\
	MAP_ENVIRONMENT_BOG:(["name":"Bog","color":"purple"]),\
	MAP_ENVIRONMENT_BRIDGE:(["name":"Bridge","color":"yellow"]),\
	MAP_ENVIRONMENT_CANYON:(["name":"Canyon","color":"olive"]),\
	MAP_ENVIRONMENT_CASTLE:(["name":"Castle","color":"fuchsia"]),\
	MAP_ENVIRONMENT_CAVE:(["name":"Cave","color":"maroon"]),\
	MAP_ENVIRONMENT_CATACOMB:(["name":"Catacomb","color":"red"]),\
	MAP_ENVIRONMENT_CITY:(["name":"City","color":"white"]),\
	MAP_ENVIRONMENT_CLIFF:(["name":"Cliff","color":"teal"]),\
	MAP_ENVIRONMENT_COAST:(["name":"Coast","color":"navy"]),\
	MAP_ENVIRONMENT_CRATER:(["name":"Crater","color":"purple"]),\
	MAP_ENVIRONMENT_DELTA:(["name":"Delta","color":"navy"]),\
	MAP_ENVIRONMENT_DESERT:(["name":"Desert","color":"yellow"]),\
	MAP_ENVIRONMENT_DOCK:(["name":"Dock","color":"teal"]),\
	MAP_ENVIRONMENT_GARDEN:(["name":"Garden","color":"green"]),\
	MAP_ENVIRONMENT_GEYSER:(["name":"Geyser","color":"fuchsia"]),\
	MAP_ENVIRONMENT_GLACIER:(["name":"Glacier","color":"fuchsia"]),\
	MAP_ENVIRONMENT_FARM:(["name":"Farm","color":"olive"]),\
	MAP_ENVIRONMENT_FOREST:(["name":"Forest","color":"green"]),\
	MAP_ENVIRONMENT_HILLS:(["name":"Hills","color":"olive"]),\
	MAP_ENVIRONMENT_ISLAND:(["name":"Island","color":"teal"]),\
	MAP_ENVIRONMENT_LAGOON:(["name":"Lagoon","color":"aqua"]),\
	MAP_ENVIRONMENT_LAKE:(["name":"Lake","color":"blue"]),\
	MAP_ENVIRONMENT_LAVA:(["name":"Lava","color":"yellow"]),\
	MAP_ENVIRONMENT_LIGHT_FOREST:(["name":"Light Forest","color":"olive"]),\
	MAP_ENVIRONMENT_MESA:(["name":"Mesa","color":"maroon"]),\
	MAP_ENVIRONMENT_MINE:(["name":"Mine","color":"silver"]),\
	MAP_ENVIRONMENT_MOUNTAIN:(["name":"Mountain","color":"white"]),\
	MAP_ENVIRONMENT_OASIS:(["name":"Oasis","color":"white"]),\
	MAP_ENVIRONMENT_OCEAN:(["name":"Ocean","color":"blue"]),\
	MAP_ENVIRONMENT_PASS:(["name":"Pass","color":"teal"]),\
	MAP_ENVIRONMENT_PATH:(["name":"Path","color":"lime"]),\
	MAP_ENVIRONMENT_PLAIN:(["name":"Plain","color":"olive"]),\
	MAP_ENVIRONMENT_PLATEAU:(["name":"Plateau","color":"silver"]),\
	MAP_ENVIRONMENT_POLAR:(["name":"Polar","color":"aqua"]),\
	MAP_ENVIRONMENT_POND:(["name":"Pond","color":"blue"]),\
	MAP_ENVIRONMENT_POOL:(["name":"Pool","color":"navy"]),\
	MAP_ENVIRONMENT_PRAIRIE:(["name":"Prairie","color":"green"]),\
	MAP_ENVIRONMENT_QUARRY:(["name":"Quarry","color":"gray"]),\
	MAP_ENVIRONMENT_RAPID:(["name":"Rapid","color":"red"]),\
	MAP_ENVIRONMENT_RIDGE:(["name":"Ridge","color":"maroon"]),\
	MAP_ENVIRONMENT_RIVER:(["name":"River","color":"blue"]),\
	MAP_ENVIRONMENT_ROAD:(["name":"Road","color":"teal"]),\
	MAP_ENVIRONMENT_RUINS:(["name":"Ruins","color":"navy"]),\
	MAP_ENVIRONMENT_SHIRE:(["name":"Shire","color":"green"]),\
	MAP_ENVIRONMENT_SINKHOLE:(["name":"Sinkhole","color":"purple"]),\
	MAP_ENVIRONMENT_SHOP:(["name":"Shop","color":"fuchsia"]),\
	MAP_ENVIRONMENT_SEWER:(["name":"Sewer","color":"olive"]),\
	MAP_ENVIRONMENT_SPRING:(["name":"Spring","color":"yellow"]),\
	MAP_ENVIRONMENT_STACK:(["name":"Stack","color":"olive"]),\
	MAP_ENVIRONMENT_STREAM:(["name":"Stream","color":"blue"]),\
	MAP_ENVIRONMENT_SWAMP:(["name":"Swamp","color":"aqua"]),\
	MAP_ENVIRONMENT_TAVERN:(["name":"Tavern","color":"navy"]),\
	MAP_ENVIRONMENT_TOWN:(["name":"Town","color":"silver"]),\
	MAP_ENVIRONMENT_TUNDRA:(["name":"Tundra","color":"white"]),\
	MAP_ENVIRONMENT_TUNNEL:(["name":"Tunnel","color":"silver"]),\
	MAP_ENVIRONMENT_UNDERGROUND:(["name":"Underground","color":"teal"]),\
	MAP_ENVIRONMENT_UNDERGROUND_LAKE:(["name":"Underground Lake","color":"navy"]),\
	MAP_ENVIRONMENT_VALLEY:(["name":"Valley","color":"teal"]),\
	MAP_ENVIRONMENT_VILLAGE:(["name":"Village","color":"maroon"]),\
	MAP_ENVIRONMENT_VOLCANO:(["name":"Volcano","color":"red"]),\
	MAP_ENVIRONMENT_WATERFALL:(["name":"Waterfall","color":"aqua"]),\
	MAP_ENVIRONMENT_WETLAND:(["name":"Wetland","color":"aqua"]),\
])

#endif /* MAP_ENVIRONMENT_DEFS_H */
