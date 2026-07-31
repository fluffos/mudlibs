 // book.c
inherit ITEM; 
void create()
{
    int i; 
   string *names = ({
        "「回风落雁剑」", "「泰山十八盘」", "「嵩山剑法」","「青城刀法」",
        "「恒山剑法」"
    }); 
    string *skills = ({
        "luoyan-jian", "shiba-pan", "songshan-jian", "liuhe-dao","hengshan-jian"
    });
        i = random(5);
    set_name( names[i], ({ "book" }));
    set_weight(100);
    set("unit", "本");
    set("long", "这是一本修练五岳武功的书籍。\n");
    set("skill", ([
        "name":                 skills[i],
        "exp_required": 0,                
        "jing_cost":             50,     
        "difficulty":   50,            
        "max_skill":    215           
                                            
        ]) );
        setup();
}    
