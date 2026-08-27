//  -*- LPC -*- 
// monster.c  Tim, 10/95:   A very generic (and sloppy) monster
//
// Copyright (C) 1996 Tim McIntosh (tmcintos@dm.imaginary.com)
//
// This program is part of the OpenLib Mudlib distribution; it
// is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published
// by the Free Software Foundation; either version 2 of the License,
// or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// If you acquired this program as part of the OpenLib Mudlib
// distribution, you should have received a copy of the GNU
// General Public License in the file /doc/GPL; if not,
// write to the Free Software Foundation, Inc., 675 Mass Ave,
// Cambridge, MA 02139, USA.
//

#include <mudlib.h>

inherit LIVING;

private boolean move_around = FALSE;     // do we move around or not?
private boolean talking_monster = FALSE; // do we go around talking??
private int chance_talk = 100;           // 100 - %chance to talk
private int chance_act = 100;            // 100 - %chance to move
private string *vocabulary = ({});       // lines that we speak
private int undead;                      // 1 if undead

// Function Prototypes
void heart_beat();
void set_move_around(int chance);
void set_talk(int chance, string *lines);
void set_undead();
int query_undead();

private void random_action();
private void do_talk();

// Called by the driver every 2 seconds or so...

void
heart_beat()
{
  if(move_around && !random(chance_act))
    random_action();
  if(talking_monster && !random(chance_talk))
    do_talk();
}

// Call this to make the monster randomly move around and do things

void
set_move_around(int chance)
{
  chance_act = 100 - chance;
  move_around = TRUE;
}

// Take a random action...pick from all available actions to make it
// look real :)

void
random_action()
{
  mixed *actions = commands();
  int action = random(sizeof(actions));

  command(actions[action][0]);
}

// Call this to make the monster talk

void
set_talk(int chance, string *lines)
{
  chance_talk = 100 - chance;
  vocabulary = lines;
  talking_monster = TRUE;
}

// speak and be heard!!

void
do_talk()
{
  int num = random(sizeof(vocabulary));

  say(query_cap_name() + " says: " + vocabulary[num] +"\n");
}

void
set_undead()
{
  undead = 1;
}

int
query_undead()
{
  return undead;
}

void
die()
{
  if(undead) {
    tell_room(environment(this_object()),
	      sprintf("%s turns to dust before your eyes.\n"));

    foreach(object ob in all_inventory(this_object())) {
      if(ob->drop())
	ob->move(environment(this_object()));
    }
    destruct(this_object());
  } else {
    ::die();
  }
}
