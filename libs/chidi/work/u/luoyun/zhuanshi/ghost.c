inherit BHNPC;
string *first_name =
({"³à","ºì","»Æ","ÂÌ","Çà","À¶","×Ï","ÎÚ","ºÚ","Òø","°×","½ð","»Ò","½ð","Ä¾","Ë®","»ð","ÍÁ"});
string *name_words =({"ÍÃ","ºü","Áú","òÔ","»¢", "±ª","Âí", 
"Â¹","Ñò","Éß","â¯","¼¦","¹·","ÀÇ","Ô³","ºï","Êó","Å£", "â³","Ñà","Öí","òð"});

string *last_words=({"¹í"}); 
void create()
{
         string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
   name += last_words[random(sizeof(last_words))];
        set_name(name, ({ "ghost"}) );
        set("gender", "ÄÐÐÔ" );
        set("age",40);
        set("str", 30);
        set("int", 20);
        set("per", 15);
        set("attitude", "heroism");
        set("combat_exp", 6400000000+random(600000000));
        set("max_qi", 10000000);
        set("max_jing", 1000000);
        set("neili",8000000);
        set("max_neili",8000000);
        set("jingli", 8000000);
        set("max_jingli", 8000000);
        set_skill("club",4000);
        set_skill("dagou-bang",4000);
        set_skill("dodge",4000);
        set_skill("force",4000);
        set_skill("huntian-qigong",4000);
        set_skill("parry",4000);
        set_skill("unarmed",4000);
        set_skill("xianglong-zhang",4000);
        set_skill("xiaoyaoyou",4000);
    map_skill("dodge", "xiaoyaoyou");
    map_skill("unarmed", "xianglong-zhang");
    map_skill("force", "huntian-qigong");
    map_skill("parry", "dagou-bang");
    map_skill("club", "dagou-bang");
   set("HellZhen", 0);
        setup();
        carry_object("/clone/misc/cloth")->wear();
   carry_object("/d/city/obj/zhubang")->wield();
}

void invocation(object who)
{
   object me=this_object();
   COMBAT_D->do_attack(me, who, query_temp("weapon"));
   destruct(me);
}