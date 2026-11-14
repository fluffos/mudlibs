// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/secure/simul_efun/input_to.inc
// Description: Um Umlaute bei input_to zu konvertieren
// Author:	Gnomi (17.02.2000)
// Modified by:	Freaky (24.02.2000) verbessert und einen Bug raus, der
//			entstand, wenn man die simul-efun zerstoerte
//
// $Log: input_to.inc,v $
// Revision 1.12  2015/08/26 21:40:30  gnomi
// Anpassungen an LDMud 3.5.0
//
// Revision 1.11  2012/12/11 22:08:41  gnomi
// efun::-Praefix verwenden, um Missverstaendnisse zu vermeiden.
//
// Revision 1.10  2008-04-10 08:47:37  gnomi
// Prompt ggf. erstmal via funcall auswerten.
//
// Revision 1.9  2008-04-02 08:40:56  gnomi
// Den aktuellen Prompt bei INPUT_APPEND-input_tos nicht veraendern.
//
// Revision 1.8  2007/09/02 00:27:35  gnomi
// Dem VT100-Client auch die input_to-Flags mitgeben, zur Info.
//
// Revision 1.7  2007/09/01 23:30:33  gnomi
// Workaround fuer die Prompt-Anzeige bei input_tos, die nicht waehrend
// der Befehlsabarbeitung auftreten.
//
// Revision 1.6  2007/08/20 18:22:39  gnomi
// query_input_pending bei getrennter Eingabezeile simulieren.
//
// Revision 1.5  2007/08/13 21:53:00  gnomi
// Input_tos auch von der VT100-Eingabezeile behandeln lassen.
//
// Revision 1.4  2007/08/13 21:09:34  gnomi
// Den Text zur Ausgabe an die VT100-Eingabezeile schicken.
//
// Revision 1.3  2001/11/26 00:40:26  gnomi
// fuer INPUT_PROMPT angepasst.
//
// Revision 1.2  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//

#include "/sys/input_to.h"

varargs void input_to(mixed fun, int flag, varargs mixed *args)
{
    closure cl;

    set_this_object(previous_object());
    if (stringp(fun))
    {
	if (!(cl = symbol_function(fun,this_object())))
	    raise_error("Function '" + fun +
		    "' for input_to() does not exist\n");
    }
    else if (closurep(fun))
	cl = fun;
    else
	raise_error("Bad argument 1 to input_to()\n");

    if(flag & INPUT_PROMPT)
    {
	if(!sizeof(args))
	    raise_error("Missing prompt argument to input_to().\n");
	
	if((flag & (INPUT_CHARMODE|INPUT_NOECHO)) ||
	    !this_player()->start_input_to(
		lambda(({'str}), ({#'apply, cl, 'str, quote(args[1..<1]) })),
		args[0], flag))
	{
	    // Workaround fuer fehlende Driver-Prompt-Anzeige,
	    // wenn noch ein Prompt aktiv ist:
	    if(efun::this_interactive()!=this_player() &&
		(!(flag&INPUT_APPEND) || 
#if __EFUN_DEFINED__(query_input_pending)
		 !efun::query_input_pending(this_player())
#else
		 !(interactive(this_player()) && efun::interactive_info(this_player(), II_INPUT_PENDING))
#endif
		))
	    {
		mixed res;
		mixed curprompt = funcall(args[0]);
		if(!call_resolved(&res, this_player(), "print_prompt", curprompt))
		    this_player()->receive_message_low(curprompt);
	    }
	    
	    efun::input_to(lambda(({'str}),
		({#'apply,cl,
		    flag & INPUT_CHARMODE ? 'str :
			({symbol_function("convert_umlaute"),'str}),
		    quote(args[1..<1]) })),
		flag, args[0]);
	}
    }
    else
    {
	if((flag & (INPUT_CHARMODE|INPUT_NOECHO)) ||
	    !this_player()->start_input_to(
		lambda(({'str}), ({#'apply, cl, 'str, quote(args) })),
		"", flag))
	    efun::input_to(lambda(({'str}),
		({#'apply,cl,
		    flag & INPUT_CHARMODE ? 'str :
			({symbol_function("convert_umlaute"),'str}),
		    quote(args) })),
		flag);
    }
}

object query_input_pending(object ob)
{
    int pp = playerp(ob);

    set_this_object(previous_object());

    return (pp && ob->query_pending_input_to()) ||
#if __EFUN_DEFINED__(query_input_pending)
	efun::query_input_pending(ob);
#else
	(efun::interactive(ob) && efun::interactive_info(ob, II_INPUT_PENDING));
#endif
}
