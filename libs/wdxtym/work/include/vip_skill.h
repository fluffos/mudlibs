
string *sk_list = ({
		"qishang-quan",
		"zhuihun-jian",
		"zhuihun-jian",
		"zhuihun-jian",
		"baihua-quan",
		"baihua-quan",
		"hanbing-mianzhang",
		"hanbing-mianzhang",
		"hanbing-mianzhang",
		"sougu",
		"sougu",
		"yunlong-bian",
		"yunlong-bian",
		"yunlong-bian",
		"yunlong-shenfa",
		"yunlong-shenfa",
		"hanxing-bada",
		"hanxing-bada",
		"xuanming-zhang",
		"xuanming-zhang",
		"shenzhaojing",
});
string *sk_list2 = ({
		"qishang-quan",
		"zhuihun-jian",
		"baihua-quan",
		"hanbing-mianzhang",
		"sougu",
		"yunlong-bian",
		"yunlong-shenfa",
		"hanxing-bada",
		"xuanming-zhang",
		"shenzhaojing",
		"jiuyang-shengong",
});
//检查VIP对应等级，达到条件可拥有
int check_vip_skill(string skills, object me)
{
	int vip_lvl;
	
	if (skills && me) {
		if (SKILL_D(skills)->valid_learn(me))
			return 1;
		vip_lvl = me->query("zjvip/level");
		//VIP3级后可以无条件拥有的技能
		if (vip_lvl >= 3 && member_array(skills, sk_list) != -1)
			return 1;
		//VIP4级后可以无条件拥有的技能
		if (vip_lvl >= 4 && member_array(skills, sk_list2) != -1)
			return 1;
	}
	return 0;
}