// hgweishi.c
 
inherit NPC;
 
void create()
{
        int rd;
 
        rd=random(4);
        set_name("护宫卫士", ({ "wei shi", "shi"}) );
        set("title", "天宫");
        set("gender", "男性" );
        set("long", 
                "一个威武的护宫卫士，膀阔腰圆，力大无穷。\n"
                "他手持兵刃，身穿宝甲，目光扫视着每个路过的人。\n"
        );
        set("age", 19+random(15));
	set_level(120);
   	set("daoxing",1500000);
	set("force_factor", 55);
	set("mana_factor", 40);
        set_skill("unarmed",1090);
        set_skill("dodge",1090);
        set_skill("parry",1090);
        set_skill("spells",1090);
        set_skill("force",1090);
        switch(rd) 
        {
        	case 0:
                	set_skill("stick",99);
                	break;
        	case 1:
                        set_skill("sword",99);
                        break;
        	case 2:
                        set_skill("fork",99);
                        break;
        	default :
                        set_skill("axe",99);
                        break;
        }
	set("env/test","HIY");
   	set_temp("armor_level",90);
   	set_temp("weapon_level",90);
	setup();
        carry_object(0,"armor",1)->wear();
        switch(rd) 
        {
        	case 0: carry_object(0,"stick",1)->wield();break;
        	case 1: carry_object(0,"sword",1)->wield();break;
        	case 2: carry_object(0,"fork",1)->wield();break;
		default : carry_object(0,"axe",1)->wield();break;
        }
}
 
