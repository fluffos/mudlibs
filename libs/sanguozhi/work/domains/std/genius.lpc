// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;

int starts_with(string str, string pref) {
    return str[0..strlen(pref)-1] == pref;
}

int ends_with(string str, string suff) {
    return str[<strlen(suff)..] == suff;
}

void setup() {
    int *handle;
    
    set_name("Logical Genius", "逻辑天才");
    set_gender(1);
    set_proper_name("逻辑天才");
    set_in_room_desc("逻辑天才以怀疑的眼光上下打量着你。");
    add_id("dude");
    add_id("genius");
    set_long("逻辑天才看了你一眼...\n逻辑天才说：来，给我讲讲你的名字好吗？");

    add_pattern("%s说道：%s。", function(string name, mixed sub) {
        if (functionp(sub)) {
	    if (evaluate(sub, lower_case(name)))
		return "say 正确．";
	    else
		return "say 你说谎。";
	}
	if (sub && intp(sub))
	    return "say 我不懂你说的是什么意思。";
	if (random(5))
	    return 0;
	return "say 别瞎扯，我只对你的名字感兴趣。";
    }, 0, "say_rule");
    
    add_sub_pattern("say_rule", "%s name %s", (: $2 :), 0, "predicate");
     
    add_sub_pattern("predicate", "%s or %s", function(function f1, function f2) {
	return (: evaluate($(f1), $1) || evaluate($(f2), $1) :);
    }, "and_pred", "predicate");
    add_sub_pattern("predicate", "%s", (: $1 :), "and_pred");

    add_sub_pattern("and_pred", "%s and %s", function(function f1, function f2) {
	return (: evaluate($(f1), $1) && evaluate($(f2), $1) :);
    }, "simple_pred", "and_pred");
    add_sub_pattern("and_pred", "%s", (: $1 :), "simple_pred");
    
    add_sub_pattern("simple_pred", "is not %s", function(string name) {
	return (: $1 != $(name) :);
    } );
    add_sub_pattern("simple_pred", "is %s", function(string name) {
	return (: $1 == $(name) :);
    } );
    add_sub_pattern("simple_pred", "starts with %s", function(string prefix) {
	return (: starts_with($1, $(prefix)) :);
    } );
    add_sub_pattern("simple_pred", "ends with %s", function(string suffix) {
	return (: ends_with($1, $(suffix)) :);
    } );
    add_sub_pattern("simple_pred", 0, 1);
}
