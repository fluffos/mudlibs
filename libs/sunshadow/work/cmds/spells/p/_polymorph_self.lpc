inherit "/cmds/spells/s/_shapechange";

string *valid_forms()
{
    return ({"spider","pixie","troll"});
}

void create()
{
    ::create();
    set_spell_name("polymorph self");
    set_spell_level(([ "ranger" : 4, "assassin":4, "oracle":4, "warlock" : 2, "cleric" : 4, "druid" : 4 ]));
    set_domains("animal");
    set_mystery("nature");
    set_spell_sphere("alteration");
    set_syntax("cast CLASS polymorph self on spider|pixie|troll");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
    set_feats_required(([ "warlock" : "tome of ancient secrets"]));
}

int preSpell()
{
    object shape;
    string *forms;
    if(objectp(shape = caster->query_property("shapeshifted")) ||
       objectp(shape = caster->query_property("transformed")) ||
       objectp(shape = caster->query_property("dance-of-cuts")) ||
       objectp(shape = caster->query_property("altered")))
    {
        tell_object(caster,"You are already in an alternative form!");
        return 0;
    }
    
    forms = valid_forms();
      
    if(member_array(arg,forms)==-1)
    {
        tell_object(caster,"Invalid form, valid forms are: "+implode(valid_forms(),", "));
        return 0;
    }

    return 1;
}
