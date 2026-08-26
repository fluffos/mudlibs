/*
** File: _hp.c
** Purpose:  The new hp command, written by Cyanide to replace the
**      code originally written by Mobydick@TMI-2 on 9-23-92.
** Credits:
**    22 Jul 97  Cyanide wrote the file.
** (04-06-98) Chronos adds a help() function.
*/

#include <mudlib.h>

int cmd_hp() {
  int hp, max_hp, sp, max_sp, tp, max_tp;

  hp = (int)TP->query("hit_points");
  max_hp = (int)TP->query("max_hp");
  sp = (int)TP->query("spell_points");
  max_sp = (int)TP->query("max_sp");
 tp = (int)TP->query("theurgy_points");
  max_tp = (int)TP->query("max_tp");
  
  if (!max_tp){
  if (!max_sp) {
    write( sprintf(" [ HP: %d / %d (%d%%) ]\n",
      hp, max_hp, (hp*100)/max_hp) ); 
    return 1;
  }
  write( sprintf(" [ HP: %d / %d (%d%%)\tSP: %d / %d (%d%%) ]\n",
    hp, max_hp, (hp*100)/max_hp,
    sp, max_sp, (sp*100)/max_sp) );

  return 1;
}else{
 if (!max_sp) {
    write( sprintf(" [ HP: %d / %d (%d%%)\tTP: %d / %d (%d%%) ]\n",
    hp, max_hp, (hp*100)/max_hp,
    tp, max_tp, (tp*100)/max_tp) );
    return 1;
  }
  write( sprintf(" [ HP: %d / %d \tSP: %d / %d \tTP: %d / %d  ]\n",
    hp, max_hp, sp, max_sp, 
    tp, max_tp ));
	return 1;
	}
	}

string help() {
  return @ENDHELP
Usage: hp

This command shows you your current hp and sp situation.

See also: score, kills, ds, monitor
ENDHELP
  ;
  }

