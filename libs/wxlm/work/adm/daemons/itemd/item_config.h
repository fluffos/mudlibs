// 可以用来浸透的物品列表：必须是物品的base_name
mapping imbue_list = ([
	"feicui lan":"翡翠兰",
	"puti zi":"菩提子",
	"ling zhi":"千年灵芝",
	"xian dan":"醍醐仙丹",
	"xisui dan":"洗髓丹",
	"shenli wan":"神力丸",
	"huohong xiandan":"火红仙丹",
	"jiuzhuan jindan":"九转金丹",
	"magic water":"天香玉露",
	"fushou gao":"福寿膏",
]);

// 浸入的次数的随机界限：如果每次IMBUE以后取0-IMBUE次数的随机
// 数大于这个数值，则IMBUE最终成功。
#define RANDOM_IMBUE_OK	 80

// 每次浸入需要圣化的次数
#define SAN_PER_IMBUE	   5