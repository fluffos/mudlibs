// Modified by  : kiden@pkuxkx
// 装备武器

varargs void wield_weapon(string weapon);
varargs void wield_weapon(string weapon)
{
        if(!weapon && this_object()->query("use_weapon1"))
                wield_weapon(this_object()->query("use_weapon1"));
        if(!weapon && this_object()->query("use_weapon2"))
                wield_weapon(this_object()->query("use_weapon2"));
        if(!weapon)
                return;
        switch(weapon)
        {
        case "sword":
                this_object()->carry_object("/clone/weapon/changjian")->wield();
                break;
        case "blade":
                this_object()->carry_object("/clone/weapon/gangdao")->wield();
                break;
        case "staff":
                this_object()->carry_object("/clone/weapon/gangzhang")->wield();
                break;
        case "whip":
                this_object()->carry_object("/clone/weapon/changbian")->wield();
                break;
        case "xiao":
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");
                this_object()->carry_object("/d/taohuadao/obj/shizi");                
                this_object()->carry_object("/d/taohuadao/npc/obj/yuxiao")->wield();
         break;
         case "ling":
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");
                this_object()->carry_object("/d/mingjiao/npc/obj/jinhua");                
                this_object()->carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
         break;
        case "zhen":
                this_object()->set("gender", "无性");
                this_object()->carry_object("/d/city/obj/flower_shoe");
                this_object()->carry_object("/d/city/obj/pink_cloth");
                this_object()->carry_object("/d/city/obj/goldring");
                this_object()->carry_object("/d/city/obj/necklace");
                this_object()->carry_object("/d/quanzhou/obj/xiuhua")->wield();
                this_object()->carry_object("/d/riyuejiao/obj/xiuhuajia");
                break;
        case "dagger":
                this_object()->carry_object("/clone/weapon/bishou")->wield();
                break;
        case "hammer":
                this_object()->carry_object("/d/dalunsi/npc/obj/iron-falun")->wield();
                break;
        default:
                break;
        }
        return;
}
