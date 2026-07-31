#include "seed.h"

mapping seed_info = ([
	"name" : "油菜种子",		//种子名字
	"id" : "baicai",			//种子ID，后会自动加" seed"
	"value" : 1000,			//种子价值
	"mature_name" : "油菜", //成熟名称
	"time_need" : 1800,		//成熟时间
]);

void create()
{
	create_seed(seed_info);
}