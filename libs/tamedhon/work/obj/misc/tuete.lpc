//Asrahel

inherit "std/thing" ;

#include <properties.h>
#include <moving.h>
#include <defines.h>
#include <language.h>

void create()
{
  if (!clonep(this_object())) return;
  ::create() ;

  SetProp( P_SHORT, "Eine Tüte Bonbons" ) ;
  SetProp( P_LONG, "Eine magische Bonbontüte. So oft Du auch hineingreifst, sie wird niemals leer\n"
		+  "und enthält immer eine bunte Mischung.\n");

  SetProp( P_WEIGHT, 0 ) ;
  SetProp( P_NOBUY, 1) ;
  SetProp( P_NODROP, "Nein, Du willst doch nicht dieses Geschenk weggeben !?\n");
  SetProp( P_NEVERDROP, 1) ;
  SetProp( P_NAME, "Tüte") ;
  SetProp( P_GENDER, FEMALE ) ;
  AddId( ({ "bonbontuete","tuete", "bonbons","bonbontüte","tüte" }) ) ;
  SetProp(P_AUTOLOADOBJ, 1);

}

void init()
{
	::init();
	add_action("naschen","greife");
	add_action("naschen","greif");
}

int naschen (string str)
{
  notify_fail("Wohinein möchtest Du greifen ?\n");
	if ( str != "tuete" && str != "in tuete" && str != "bonbons" && str != "in bonbontuete" && str != "tüte" && str != "in tüte" && str != "in bonbontüte")
		 return 0;
	write("Du greifst in Deine Tüte und holst ein Bonbon heraus.\n");
	say( PL->name(WER,2) + " holt ein Bonbon aus einer Tuete.\n");
	clone_object("obj/misc/bonbon")->move(PL);
	return 1;
}

