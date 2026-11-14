// This file is part of Avalon Mudlib
// ----------------------------------------------------------------
// File:        /i/wizard_shell/vplayer.inc
// Author:      Avatar (10/96)
// Description: Hier befinden sich die wichtigsten Funktionen, die noetig
//              sind, um den Wiz-Tools einen Player vorzutaeuschen
//
// $Log: vplayer.inc,v $
// Revision 1.10  2015/10/15 18:37:53  gnomi
// query_client_width() fuer more() implementiert.
//
// Revision 1.9  2009-08-19 17:26:40  gnomi
// VT100-Suspend bei ed() eingebaut.
//
// Revision 1.8  2009-03-20 08:03:37  gnomi
// notify_message und query_real_cap_name eingebaut.
//
// Revision 1.7  2003/02/14 03:50:42  gnomi
// Funktion fuer die xed-Optionen geaendert.
//
// Revision 1.6  2002/04/30 07:06:03  gnomi
// query_eye_option implementiert.
//
// Revision 1.5  2002/01/21 02:03:45  gnomi
// query_new_wiz_errors: Falls Player nicht mehr eingeloggt, trotzdem einen
// gueltigen Wert liefern.
//
// Revision 1.4  2001/10/05 20:55:38  freaky
// Sichtbarkeit von Redefinitionen korrigiert.
//
// Revision 1.3  2001/07/18 20:26:18  gnomi
// query/set_new_wiz_errors von wizard_shell.c nach vplayer.inc verschoben und
// Sicherheitstest auf vorhandenen Master eingebaut.
//
// Revision 1.2  2001/01/30 23:59:01  sissi
// Bergeweise CVS Log Eintraege eingetragen.
// Hoffentlich nirgends doppelt und nirgends zu wenig.
//
//

#include <telnet.h>

private object update_master()
{
   object ob;

   if( !master_name )
      return 0;
   return master || (master=find_player(master_name));
}

nomask string query_real_name()       { return master_name; }
nomask string query_real_cap_name()   { return capitalize(master_name); }

nomask int query_level()
{
   if( update_master() )
      return master->query_level();
}
nomask int query_wiz_level()
{
   int level;
   
   return (level=query_level()) >= LVL_LEARNER ? level : 0;
}

// Fuer /i/player/tippse.c
int query_f_casting()      { return 0; }

// Fuer den Standard-Editor
int query_ed_setup()
{
   if( update_master() ) 
      return master->query_ed_setup(); 
}
void set_ed_setup(int i)
{
   if( update_master() )
      master->set_ed_setup(i);
}

int query_player_flag(int bit)
{
   if( update_master() )
      return master->query_player_flag(bit);
}
 
int query_input_without_cr()
{
   if( without_cr )
      return 1;
   if( update_master() )
      return master->query_input_without_cr();
}
 
void net_dead()  
{
   // Editor-Inhalt sichern
   xeditor::editor_save_current_file();
   destruct(this_object());
}

mixed query_read_artikel()
{
   if( update_master() )
      return master->query_read_artikel();
}

void set_read_artikel(mixed struc)
{
   if( update_master() )
      master->set_read_artikel(struc);
}

static string query_prompt_msg()
{
   if( shell_command_mode ) 
   {
      init_command_shell();
      input_to("get_command",3);
   }
   return files::query_current_path();
}

void set_new_wiz_errors(mixed *errs)
{
    if( update_master() )
        master->set_new_wiz_errors(errs);
}

mixed *query_new_wiz_errors()
{
    if( update_master() )
        return master->query_new_wiz_errors();
    else
	return ({ MAX_INT, ({ }) });
}

varargs mixed query_eye_option(string option)
{
    if (update_master())
	return master->query_eye_option(option);
    else if(option)
	return 0;
    else
	return ([]);
}

// Fuer /i/tools/xeditor.c
mapping query_editor_options()
{
    if (geteuid(previous_object()) == geteuid() && update_master())
    {
	mapping opts = master->query_editor_options();
	if(opts)
	    return opts-(["split_y"]);
    }
    return 0;
}
void set_editor_options(mapping opts)
{
    if (geteuid(previous_object()) == geteuid() && update_master())
	master->set_editor_options(opts);
}

// Fuer /i/player/wiz_soul.c
varargs void notify_message(string msg, int type)
{
    if(this_object())
        this_object()->receive_message(MT_NOTIFY,type,this_object(),msg);
}

// Wird vom Zauberstab aufgerufen.
void notify_ed_exit(int suspend_client)
{
    if(suspend_client)
	this_object()->restart_mudclient();
}

void notify_ed_enter(int suspend_client)
{
    if(suspend_client)
	this_object()->suspend_mudclient();
}

// Wird von more verwendet.
#define MIN_WIDTH 79
int query_client_width()
{
    mixed sb;
    int width;

    if(update_master())
        width = master->query_set_client_width();

    if(width)
        return width;

    if(this_object()->query_telnet(TELOPT_NAWS,&sb) && sizeof(sb) > 1 && sb[0] > MIN_WIDTH)
        return sb[0];

    return MIN_WIDTH;
}
