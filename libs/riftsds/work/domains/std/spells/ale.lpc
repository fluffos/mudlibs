inherit SPELL;

void setup()
{
   set_spell_name("conjure ale");
}

void cast_spell(object ob, object reagent)
{
   object ale;
   this_body()->simple_action("A streak of ale appears at the wave of $p hand.");
   ale = new ("domains/std/ale");
   ale->move(environment(this_body()));
}
