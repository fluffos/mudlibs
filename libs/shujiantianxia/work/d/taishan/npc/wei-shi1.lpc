// wu-shi1.c 盟主卫士

#include <ansi.h>
inherit NPC;

string *sword_skill = ({ 
"taiji-jian","damo-jian","fumo-jian","jinshe-jianfa","qingmang-jian","yuxiao-jian",
"yunu-jianfa","songshan-jian","murong-jianfa","huashan-jianfa", "duanjia-jianfa",
"huifeng-jian","liangyi-jian","quanzhen-jianfa" }); 

string *blade_skill = ({ 
"cibei-dao","fanliangyi-dao","liuhe-daofa","murong-daofa","qingmang-jian","wenjia-daofa", 
"shandian-daofa","xiuluo-dao","xuanxu-daofa", "yanxing-daofa",}); 

string *staff_skill = ({ 
"wuchang-zhang","fengmo-zhang","tianshan-zhang","xinyuegong" }); 

string *club_skill = ({ 
"weituo-chu","zui-gun","weituo-gun","xinyuegong" }); 

string *whip_skill = ({ 
"piaomiao-bianfa","qingxu-bian" }); 

string *dodge_skill = ({ 
"shuishangpiao","suibo-zhuliu","yanling-shenfa","yufeng-xiang","tianlong-xiang",
"yunu-shenfa","zhaixingshu","xiaoyaoyou","zhongyuefeng","huashan-shenfa","tiyunzong" }); 

string *weapon_list = ({ "chui","sword","blade","whip","gun","sword","gangzhang","blade" }); 

void create()
{
        string s_sword,s_blade,s_club,s_whip,
               s_staff,s_dodge, weapon;
        s_sword = sword_skill[random(sizeof(sword_skill))];
        s_blade = blade_skill[random(sizeof(blade_skill))];
        s_club  = club_skill[random(sizeof(club_skill))];
        s_whip  = whip_skill[random(sizeof(whip_skill))];
        s_staff = staff_skill[random(sizeof(staff_skill))];
        s_dodge = dodge_skill[random(sizeof(dodge_skill))];
        weapon = weapon_list[random(sizeof(weapon_list))];

	set_name(HIW "白衣武士" NOR, ({ "wei shi", "shi", "guard" }) );
	set("gender", "男性");
	set("age", 35);
	set("long",
		"这是位白衣武士，身披钢甲，手执长剑，双目精光炯炯，警惕地巡视着四周的情形。\n");
        set("combat_exp", 450000);
        set("attitude", "peaceful");
        set("str", 40);
        set("int", 22);
        set("con", 30);
        set("dex", 28);
        set("max_qi", 1500);
        set("max_jing", 1400);
        set("eff_jingli", 1300);
        set("jiali", 30);
        set("no_quest", 1);
        set_skill("taizuquan", 120);
        set_skill("xinyuegong", 120);
        set_skill("cuff", 120);
        set_skill("force", 120);
        set_skill("yinyun-ziqi", 120);
        set_skill("sword", 120);
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("blade", 120);
        set_skill("hammer", 120);
        set_skill("club", 120);
        set_skill("staff", 120);
        set_skill("whip", 120);
        set_skill(s_sword, 120);
        set_skill(s_blade, 120);
        set_skill(s_club, 120);
        set_skill(s_whip, 120);
        set_skill(s_staff, 120);
        set_skill(s_dodge, 120);
        map_skill("force", "yinyun-ziqi");
        map_skill("sword", s_sword);
        map_skill("dodge", s_dodge);
        map_skill("parry", "taizuquan");
        map_skill("hammer", "xinyuegong");
        map_skill("blade", s_blade);
        map_skill("club", s_club);
        map_skill("whip", s_whip);
        map_skill("staff", s_staff);
        map_skill("cuff", "taizuquan");
        prepare_skill("cuff", "taizuquan");         
        setup();
        carry_object(BINGQI_D(weapon))->wield();
        carry_object(ARMOR_D("yexing-yi"))->wear();
}			

void init()
{
	object ob;
	string mengzhu;

	ob = load_object("/clone/npc/zhong-shentong");
	mengzhu = ob->query("winner");

	if( this_player()->query("id") == mengzhu ) {
		message_vision(HIY "白衣武士举起长剑，向$N齐声大喊：万岁，万岁，万万岁！\n" NOR, 
		this_player());
		return;
	}		
	::init();
}
