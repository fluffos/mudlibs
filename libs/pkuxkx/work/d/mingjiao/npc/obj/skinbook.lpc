inherit ITEM;
void create()
{
        set_name("乾坤大挪移心法", ({ "xin fa", "book" }));
        set_weight(600); 
	 set("no_drop",1);
	set("no_get",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "一张羊皮纸，一面有毛，一面光滑，上面写着“明教圣火心法 乾坤大挪移”。\n");
                set("value", 1000);
                set("material", "cloth");
                set("skill", ([
                        "name": "qiankun-danuoyi",
                    	"exp_required": 100000,
                        "jing_cost":    30,
                        "difficulty":   30,
                "max_skill":   200
                ]) );
        }
  }
void init()
{
      add_action("do_study","study");
}
int do_study(string arg)
{
      string target;
      int num;
      if (!arg 
|| sscanf(arg,"%s %d",target,num)!=2)
      {
            return 0;
      }
      if (!id(target))
            return 0;
        if (base_name(environment(this_player())) != "/d/mingjiao/mishi")
      {
            write("你不在明教的秘室中，不能学习乾坤大挪移心法。
\n");
            return 1;
      }
      return 0;
}
