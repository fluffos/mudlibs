// 门派绝招列表 (by xbd)

mapping *pfm = ({
	([	"party": "wudang",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: exert_function, "taiji" :),
			(: perform_action, "zong" :),}),
		"perform": ({
			(: perform_action, "unarmed.ji" :),
			(: perform_action, "unarmed.zhen" :),
			(: perform_action, "unarmed.zhenup" :),
			(: perform_action, "unarmed.zhan" :),
			(: perform_action, "sword.chan" :),
			(: perform_action, "sword.chanup" :),
			(: perform_action, "sword.lian" :),
			(: perform_action, "sword.sui" :),}),
		"perform1": ({
			(: perform_action, "unarmed.zhenup" :),
			(: perform_action, "sword.lian" :),}),
		"perform2": ({
			(: perform_action, "unarmed.zhan" :),
			(: perform_action, "sword.chanup" :),
			(: perform_action, "sword.chan" :),}),
	]),
	
	([	"party": "huashan",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: perform_action, "unarmed.leidong" :),
			(: perform_action, "sword.wudui" :),}),
		"perform": ({
			(: perform_action, "dodge.huiyanfeiwu" :),
			(: perform_action, "strike.wuji" :),
			(: perform_action, "sword.jiushi" :),
			(: perform_action, "sword.zongjue" :),
			(: perform_action, "sword.pozhao" :),
			(: perform_action, "sword.poqi" :),
			(: perform_action, "sword.pojian" :),
			(: perform_action, "sword.pozhang" :),
			(: perform_action, "sword.feilong" :),
			(: perform_action, "sword.jianzhang" :),
			(: perform_action, "sword.jm" :),}),
		"perform1": ({
			(: perform_action, "sword.jiushi" :),
			(: perform_action, "sword.zongjue" :),
			(: perform_action, "sword.poqi" :),
			(: perform_action, "sword.feilong" :),}),
		"perform2": ({
			(: perform_action, "sword.zongjue" :),
			(: perform_action, "sword.pozhao" :),}),
	]),
	
	([	"party": "lingjiu",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: exert_function, "duzun" :),
			(: exert_function, "shield" :),}),
		"perform": ({
			(: perform_action, "dodge.lingbo" :),
			(: perform_action, "unarmed.duo" :),
			(: perform_action, "unarmed.zhemei" :),
			(: perform_action, "strike.zhong" :),
			(: perform_action, "strike.lianzhong" :),
			(: perform_action, "sword.kuangwu" :),
			(: perform_action, "sword.san" :),
			(: perform_action, "sword.yushijufen" :),
			(: perform_action, "blade.ruyi" :),
			(: perform_action, "blade.shishiruyi" :),}),
		"perform1": ({
			(: perform_action, "sword.kuangwu" :),
			(: perform_action, "sword.yushijufen" :),
			(: perform_action, "blade.ruyi" :),
			(: perform_action, "blade.shishiruyi" :),}),
		"perform2": ({
			(: perform_action, "unarmed.duo" :),
			(: perform_action, "dodge.lingbo" :),}),
	]),
	
	([	"party": "taohua",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: exert_function, "wuzhuan" :),}),
		"perform": ({
			(: perform_action, "hand.fuxue" :),
			(: perform_action, "finger.jinglei" :),
			(: perform_action, "finger.lingxi" :),
			(: perform_action, "strike.shenjian" :),
			(: perform_action, "strike.xuan" :),
			(: perform_action, "unarmed.kuangfeng" :),
			(: perform_action, "sword.taohuajian" :),
			(: perform_action, "sword.tianwai" :),
			(: perform_action, "sword.yuxiao" :),
			(: perform_action, "sword.tianwu" :),}),
		"perform1": ({
			(: perform_action, "unarmed.kuangfeng" :),
			(: perform_action, "sword.taohuajian" :),
			(: perform_action, "sword.tianwu" :),}),
		"perform2": ({
			(: perform_action, "hand.fuxue" :),
			(: perform_action, "finger.jinglei" :),}),
	]),
	
	([	"party": "tiandihui",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: exert_function, "qingshen" :),}),
		"perform": ({
			(: perform_action, "unarmed.pofuchenzhou" :),
			(: perform_action, "unarmed.zhen" :),
			(: perform_action, "claw.ningxue" :),
			(: perform_action, "hand.fuxue" :),
			(: perform_action, "sword.duoming" :),
			(: perform_action, "sword.xian" :),
			(: perform_action, "sword.xunlei" :),
			(: perform_action, "whip.chan" :),}),
		"perform1": ({
			(: perform_action, "unarmed.pofuchenzhou" :),
			(: perform_action, "claw.ningxue" :),
			(: perform_action, "sword.xunlei" :),
			(: perform_action, "sword.xian" :),
			(: perform_action, "sword.duoming" :),}),
		"perform2": ({
			(: perform_action, "hand.fuxue" :),}),
	]),
	
	([	"party": "mingjiao",
		"powerup": ({
			(: exert_function, "powerup" :),}),
		"perform": ({
			(: command, "nuoyi" :),
			(: perform_action, "dodge.ruyingruhuan" :),
			(: perform_action, "unarmed.hunpofeiyang" :),
			(: perform_action, "unarmed.youyouhunduan" :),
			(: perform_action, "strike.xixueqingfu" :),
			(: perform_action, "claw.muyeyingyang" :),
			(: perform_action, "sword.duo" :),
			(: perform_action, "sword.tougu" :),
			(: perform_action, "sword.xiyanling" :),
			(: perform_action, "sword.yinfeng" :),}),
		"perform1": ({
			(: command, "nuoyi" :),
			(: perform_action, "unarmed.youyouhunduan" :),
			(: perform_action, "sword.tougu" :),
			(: perform_action, "sword.yinfeng" :),}),
		"perform2": ({
			(: perform_action, "dodge.ruyingruhuan" :),
			(: perform_action, "sword.xiyanling" :),
			(: perform_action, "sword.duo" :),}),
	]),
	
	([	"party": "gumu",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: perform_action, "unarmed.anran" :),}),
		"perform": ({
			(: perform_action, "unarmed.xiaohun" :),
			(: perform_action, "cuff.youju" :),
			(: perform_action, "cuff.wuqing" :),
			(: perform_action, "strike.luowang" :),
			(: perform_action, "sword.feihongrudian" :),
			(: perform_action, "sword.he" :),
			(: perform_action, "sword.hubo" :),
			(: perform_action, "sword.suxin" :),}),
		"perform1": ({
			(: perform_action, "unarmed.xiaohun" :),
			(: perform_action, "cuff.wuqing" :),
			(: perform_action, "sword.feihongrudian" :),
			(: perform_action, "sword.hubo" :),}),
		"perform2": ({
			(: perform_action, "strike.luowang" :),}),
	]),
	
	([	"party": "gaibang",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: exert_function, "shengang" :),
			(: perform_action, "unarmed.xianglong" :),}),
		"perform": ({
			(: perform_action, "dodge.canghaiyixiao" :),
			(: perform_action, "unarmed.leiting" :),
			(: perform_action, "unarmed.kanglongwuhui" :),
			(: perform_action, "staff.ban" :),
			(: perform_action, "staff.chan" :),
			(: perform_action, "staff.duo" :),
			(: perform_action, "staff.feng" :),
			(: perform_action, "staff.luanda" :),
			(: perform_action, "sword.zhuan" :),}),
		"perform1": ({
			(: perform_action, "unarmed.leiting" :),
			(: perform_action, "unarmed.kanglongwuhui" :),
			(: perform_action, "staff.luanda" :),}),
		"perform2": ({
			(: perform_action, "dodge.canghaiyixiao" :),
			(: perform_action, "staff.chan" :),}),
	]),
	
	([	"party": "quanzhen",
		"powerup": ({
			(: exert_function, "xiantiandafa" :),
			(: exert_function, "powerup" :),}),
		"perform": ({
			(: perform_action, "strike.ju" :),
			(: perform_action, "strike.lianhuan" :),
			(: perform_action, "sword.ding" :),
			(: perform_action, "sword.qixing" :),
			(: perform_action, "sword.sanqing" :),
			(: perform_action, "sword.tonggui" :),}),
		"perform1": ({
			(: perform_action, "sword.sanqing" :),
			(: perform_action, "sword.tonggui" :),}),
		"perform2": ({
			(: perform_action, "strike.ju" :),
			(: perform_action, "sword.ding" :),}),
	]),
	
	([	"party": "dali",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: exert_function, "rong" :),}),
		"perform": ({
			(: perform_action, "unarmed.liumaijingshen" :),
			(: perform_action, "finger.qiankun" :),
			(: perform_action, "unarmed.sandie" :),
			(: perform_action, "sword.ailao" :),
			(: perform_action, "sword.fenglei" :),
			(: perform_action, "sword.jingtian" :),}),
		"perform1": ({
			(: perform_action, "unarmed.liumaijingshen" :),
			(: perform_action, "sword.ailao" :),}),
		"perform2": ({
			(: perform_action, "finger.qiankun" :),
			(: perform_action, "unarmed.sandie" :),}),
	]),
	
	([	"party": "tiezhang",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: perform_action, "dodge.wu" :),
			(: perform_action, "unarmed.zhangdao" :),}),
		"perform": ({
			(: perform_action, "dodge.piaowu" :),
			(: perform_action, "unarmed.tiezhangxianglong" :),
			(: perform_action, "unarmed.tianlei" :),
			(: perform_action, "axe.duan" :),
			(: perform_action, "axe.hongtianza" :),
			(: perform_action, "axe.tiaoyan" :),}),
		"perform1": ({
			(: perform_action, "unarmed.tiezhangxianglong" :),
			(: perform_action, "unarmed.tianlei" :),}),
		"perform2": ({
			(: perform_action, "dodge.piaowu" :),
			(: perform_action, "axe.tiaoyan" :),
			(: perform_action, "axe.hongtianza" :),}),
	]),
	
	([	"party": "murong",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: perform_action, "dodge.yanling" :),}),
		"perform": ({
			(: perform_action, "parry.xingyi" :),
			(: perform_action, "parry.yihuajiemu" :),
			(: perform_action, "finger.dianxue" :),
			(: perform_action, "sword.kuangjian" :),
			(: perform_action, "sword.lianhuan" :),
			(: perform_action, "sword.qixing" :),
			(: perform_action, "blade.yingzhang" :),}),
		"perform1": ({
			(: perform_action, "parry.yihuajiemu" :),
			(: perform_action, "sword.kuangjian" :),
			(: perform_action, "sword.qixing" :),}),
		"perform2": ({
			(: perform_action, "finger.dianxue" :),}),
	]),
	
	([	"party": "kunlun",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: perform_action, "strike.liuyun" :),}),
		"perform": ({
			(: perform_action, "art.shimianmaifu" :),
			(: perform_action, "strike.yixing" :),
			(: perform_action, "strike.diezhang" :),
			(: perform_action, "unarmed.shuangjue" :),
			(: perform_action, "sword.feixue" :),
			(: perform_action, "sword.jianqin" :),
			(: perform_action, "sword.juedi" :),
			(: perform_action, "sword.ren" :),}),
		"perform1": ({
			(: perform_action, "strike.yixing" :),
			(: perform_action, "unarmed.shuangjue" :),
			(: perform_action, "sword.feixue" :),
			(: perform_action, "sword.jianqin" :),}),
		"perform2": ({
			(: perform_action, "art.shimianmaifu" :),}),
	]),
	
	([	"party": "lingxiao",
		"powerup": ({
			(: exert_function, "powerup" :),}),
		"perform": ({
			(: perform_action, "dodge.snowfly" :),
			(: perform_action, "unarmed.yanxue" :),
			(: perform_action, "sword.fengxue" :),
			(: perform_action, "sword.wanmei" :),
			(: perform_action, "sword.xuehua" :),
			(: perform_action, "blade.jinwu" :),}),
		"perform1": ({
			(: perform_action, "sword.wanmei" :),
			(: perform_action, "sword.xuehua" :),
			(: perform_action, "blade.jinwu" :),}),
		"perform2": ({
			(: perform_action, "dodge.snowfly" :),
			(: perform_action, "sword.fengxue" :),}),
	]),
	
	([	"party": "wdjiao",
		"powerup": ({
			(: exert_function, "powerup" :),}),
		"perform": ({
			(: perform_action, "dodge.snake" :),
			(: perform_action, "unarmed.qzwd" :),
			(: perform_action, "sword.suo" :),
			(: perform_action, "whip.judu" :),}),
		"perform1": ({
			(: perform_action, "unarmed.qzwd" :),
			(: perform_action, "sword.suo" :),}),
		"perform2": ({
			(: perform_action, "dodge.snake" :),}),
	]),
	
	([	"party": "xingxiu",
		"powerup": ({
			(: exert_function, "powerup" :),}),
		"perform": ({
			(: perform_action, "strike.biyan" :),
			(: perform_action, "strike.duixian" :),
			(: perform_action, "strike.fushidu" :),
			(: perform_action, "strike.huoqiang" :),
			(: perform_action, "strike.huoqiu" :),
			(: perform_action, "strike.sandu" :),
			(: perform_action, "strike.throw" :),
			(: perform_action, "strike.yinhuo" :),
			(: perform_action, "staff.hushen" :),
			(: perform_action, "staff.jinxian" :),
			(: perform_action, "staff.tianshan" :),
			(: perform_action, "claw.zhua" :),
			(: perform_action, "whip.duo" :),
			(: perform_action, "whip.huixuan" :),
			(: perform_action, "whip.suo" :),}),
	]),
	
        ([	"party": "xiaoyao",
		"powerup": ({
			(: exert_function, "shield" :),}),
		"perform": ({
			(: perform_action, "strike.jie" :),
			(: perform_action, "strike.lianzhong" :),
			(: perform_action, "strike.zhong" :),
			(: perform_action, "hand.duo" :),
			(: perform_action, "hand.tanmei" :),
			(: perform_action, "hand.zhemei" :),
			(: perform_action, "dodge.lingbo" :),
			(: perform_action, "blade.ruyi" :),
			(: perform_action, "blade.shishiruyi" :),
			(: perform_action, "blade.xiaoyao" :),}),
	]),
	
        ([	"party": "mizong",
		"powerup": ({
			(: exert_function, "shield" :),
			(: exert_function, "powerup" :),}),
		"perform": ({
			(: perform_action, "strike.fen" :),
			(: perform_action, "strike.honglian" :),
			(: perform_action, "strike.xiuluo" :),
			(: perform_action, "dodge.tianmaxingkong" :),}),
	]),
	
	([	"party": "riyue",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: perform_action, "kuihuawudi" :),}),
		"perform": ({
			(: perform_action, "sword.gui" :),
			(: perform_action, "sword.pi" :),
			(: perform_action, "sword.tonggui" :),
			(: perform_action, "sword.yinrou" :),
			(: perform_action, "sword.cimu" :),
			(: perform_action, "dodge.huanying" :),
			(: perform_action, "dodge.feiying" :),
			(: perform_action, "dodge.kuihuashenzhang" :),
			(: perform_action, "dodge.jue" :),
			(: perform_action, "unarmed.yuhuan" :),}),
	]),
	
	([	"party": "tangmen",
		"powerup": ({
			(: exert_function, "powerup" :),}),
		"perform": ({
			(: perform_action, "strike.huimeng" :),
			(: perform_action, "strike.meng" :),
			(: perform_action, "strike.wandu" :),
			(: perform_action, "throwing.dinhun" :),
			(: perform_action, "throwing.dusha" :),
			(: perform_action, "throwing.poqizhen" :),
			(: perform_action, "throwing.qizigangbiao" :),
			(: perform_action, "throwing.tanghua" :),
			(: perform_action, "dodge.wu" :),
			(: perform_action, "dodge.rain" :),}),
	]),
	
	([	"party": "baituo",
		"powerup": ({
			(: exert_function, "powerup" :),}),
		"perform": ({
			(: perform_action, "strike.hama" :),
			(: perform_action, "unarmed.hama" :),
			(: perform_action, "staff.hama" :),
			(: perform_action, "staff.huan" :),
			(: perform_action, "staff.qianshe" :),
			(: perform_action, "staff.saoluoye" :),
			(: perform_action, "staff.shoot" :),
			(: perform_action, "staff.wuji" :),
			(: perform_action, "dodge.chanfei" :),
			(: perform_action, "hand.chanshen" :),
			(: perform_action, "hand.diaoshou" :),
			(: perform_action, "hand.huixuan" :),}),
	]),
	
	([	"party": "feitian",
		"powerup": ({
			(: exert_function, "powerup" :),
			(: exert_function, "shayi" :),}),
		"perform": ({
			(: perform_action, "dodge.break" :),
			(: perform_action, "blade.jiu" :),
			(: perform_action, "blade.longlianda" :),
			(: perform_action, "blade.longshan" :),
			(: perform_action, "blade.suodi" :),
			(: perform_action, "blade.tianxiang" :),
			(: perform_action, "unarmed.niu" :),
			(: perform_action, "unarmed.qin" :),}),
	]),
	
	([	"party": "emei",
		"powerup": ({
			(: exert_function, "powerup" :),}),
		"perform": ({
			(: perform_action, "strike.bashi" :),
			(: perform_action, "strike.puzhao" :),
			(: perform_action, "finger.lingkong" :),
			(: perform_action, "sword.jue" :),
			(: perform_action, "sword.juemie" :),
			(: perform_action, "sword.liaoyuan" :),
			(: perform_action, "sword.mie" :),
			(: perform_action, "sword.sanqing" :),
			(: perform_action, "blade.huanying" :),}),
	]),
	
	([	"party": "shenlong",
		"powerup": ({
			(: exert_function, "powerup" :),}),
		"perform": ({
			(: perform_action, "strike.bujue" :),
			(: perform_action, "strike.hua" :),
			(: perform_action, "strike.lianhuan" :),
			(: perform_action, "hand.bada" :),
			(: perform_action, "hand.flower" :),
			(: perform_action, "hand.meinu" :),
			(: perform_action, "shenlongtuwu" :),
			(: perform_action, "shewu" :),
			(: perform_action, "hand.yingxiong" :),
			(: perform_action, "dodge.shewu" :),
			(: perform_action, "leg.zhuiming" :),
			(: perform_action, "claw.bao" :),
			(: perform_action, "claw.ju" :),
			(: perform_action, "staff.chang" :),
			(: perform_action, "staff.chang2" :),
			(: perform_action, "staff.chang3" :),
			(: perform_action, "staff.cui" :),
			(: perform_action, "staff.fei" :),
			(: perform_action, "staff.wanshe" :),
			(: perform_action, "staff.xian" :),
			(: perform_action, "sword.chang" :),
			(: perform_action, "sword.chang2" :),
			(: perform_action, "sword.chang3" :),
			(: perform_action, "sword.cui" :),
			(: perform_action, "sword.fei" :),
			(: perform_action, "sword.wanshe" :),
			(: perform_action, "sword.xian" :),}),
	]),
	

	
	([	"party": "shaolin",
		"powerup": ({
			(: exert_function, "jingang" :),
			(: exert_function, "powerup" :),}),
		"perform": ({
			(: perform_action, "strike.sanhua" :),
			(: perform_action, "dodge.yiweidujiang" :),
			(: perform_action, "finger.fuxue" :),
			(: perform_action, "hand.foguang" :),
			(: perform_action, "cuff.luohan" :),
			(: perform_action, "claw.lianhuan" :),
			(: perform_action, "claw.sanzhua" :),
			(: perform_action, "whip.chan" :),
			(: perform_action, "whip.chanrao" :),
			(: perform_action, "whip.fumoquan" :),
			(: perform_action, "whip.riyue" :),
			(: perform_action, "club.leidong" :),
			(: perform_action, "staff.wuchang" :),
			(: perform_action, "sword.foxin" :),
			(: perform_action, "sword.lidichenfo" :),
			(: perform_action, "sword.ruying" :),
			(: perform_action, "sword.wuying" :),}),
	]),	
	


	
});
