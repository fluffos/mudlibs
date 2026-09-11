#include <mudlib.h>

inherit M_CHAR;
inherit LIVING;

string *first = ({ "赵","钱","孙","李","周","吴","郑","王","张","陈",
	"刘","林" });
string *words = ({ "顺","昌","振","发","财","俊","彦","良","志","忠",
    	"孝","雄","益","添","金","辉","长","盛","胜","进","安","福","同","满",
    	"富","万","龙","隆","祥","栋","国","亿","寿" });

string *rnd_id = ({"ra","ma","ta","pu","gu","du","so","po","lo","phi","tri"});
string *rnd_id_tail = ({"ng","gh","ss","h","le","d","ck","m","tte"});

mapping msg = (["砍树":({"$N躺在树下睡着了。\n",
			"$N不紧不慢的砍着树。\n",
			"$N一本正经的砍着树。\n",
			"$N努力的砍树，流了一身的汗。\n",
			"$N拼了命似的砍树，大树唰唰的倒在地上。\n"}),
		"整地":({"$N倒在地睡着了。\n",
			"$N不紧不慢的整着地。\n",
			"$N一本正经的整着地　n",
			"$N努力的整地，流了一身的汗。\n",
			"$N拼了命似的整地。\n",}),
		"灌溉":({"$N倒在地睡着了。\n",
                        "$N不紧不慢的灌溉着。\n",
                        "$N一本正经的灌溉着。\n",
                        "$N努力的灌溉，流了一身的汗。\n",
                        "$N拼了命似的灌溉。\n",}),
	]);
mapping work = (["砍树":"str", "整地":"exp", "灌溉":"int", ]);

void setup()
{
	string name, id;
	
	name = first[random(sizeof(first))];
    	name += words[random(sizeof(words))];
    	if( random(10) > 2 ) name += words[random(sizeof(words))];

    	id = rnd_id[random(sizeof(rnd_id))];
    	if( random(10) > 4 ) id += rnd_id[random(sizeof(rnd_id))];
    	id += rnd_id_tail[random(sizeof(rnd_id_tail))];

	set_name(id, name);
	add_id("worker");
	set_in_room_desc(name+"("+id+")");
	set_long(name+"("+id+")");
	set_gender(1);
	set_age(20+random(20));

	set("str", random(5)+5);
	set("int", random(5)+5);
	set("exp", random(5)+5);
	set("eff", random(5)+5);
	set("wrk", 0 );
	set("job", "none");

	call_out("do_work", 10);
}
void do_work()
{
	int eff;

	eff = query("eff") - 5;
	eff = random(2) + eff;
	if( eff < 0 )eff = 0;
	if( eff > 4 )eff = 4;

	if( !this_object()->query("job") || this_object()->query("job") == "none" ){
		this_object()->simple_action("$N无所四事的发呆。\n");
	} else {
		this_object()->simple_action(msg[query("job")][eff]);
		set("wrk", query("wrk")+query("eff")*query(work[query("job")]));
	};
	call_out("do_work", 10 + random(5) );
	return;
}
