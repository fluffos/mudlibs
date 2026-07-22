//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit SUPER_NPC;

string *names = ({
	"道","清","常","守","宁","阳",
});		

void create()
{
	mapping his_name;
	string name,*ids;
	int g,i,k;
	g = 3+random(3);
	i = (5-g)*40+40;
	k = g-3;
	if( k>5 )
		k = 5;
	name = names[k];
	his_name = NAME_D->random_name2(0, -1, name, 0, 0);
	ids = his_name["id"];
	ids+= ({"guard"});
	set_name(his_name["name"],ids);
        set("gender", "男性");
        set("age", 14 + random(5));
        set("attitude", "peaceful");
        set("class","taoist");
	set_level(i);
        create_family("蜀山派",g,chinese_number(g)+"代守山剑童");
	set("long","蜀山剑派"+chinese_number(g)+"代守山剑童，自幼便修习秘法，以牺牲寿元的代价永葆童身，同时修行快速。\n");        	
        set_skill("force",i*10);
        set_skill("xianfeng-yunti",i*10);
        set_skill("dodge",i*10);
        set_skill("parry",i*10);
        set_skill("sword",i*10);
        set_skill("unarmed",i*10);
        set_skill("spells",i*10);
        set_skill("chuanyun-zhang",i*10);
        set_skill("yujianshu",i*10);
        set_skill("zuixian-wangyue",i*10);    
        set_skill("tianshi-fufa",i*10);

        map_skill("dodge", "zuixian-wangyue");
        map_skill("spells", "tianshi-fufa");
        map_skill("force", "xianfeng-yunti");
        map_skill("parry", "yujianshu");
        map_skill("sword", "yujianshu");
        map_skill("unarmed", "chuanyun-zhang");

        setup();
        carry_object(0,"cloth",random(2))->wear();
        carry_object(0,"pifeng",random(2))->wear();
        carry_object(0,"shoes",random(2))->wear();
        carry_object(0,"kui",random(2))->wear();
        carry_object(0,"sword",random(3))->wield();
        carry_object(0,"armor",random(2))->wear();
        carry_object(0,"shield",random(2))->wear();
}

