//  -*- LPC -*-
// queue.h: Queue Object
//
// A FILO (First In Last Out) data structure.
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

//
// Make sure all conditions are satisfied before calling these functions!
//

/*
 * POST: is_empty() == "TRUE"
 */
void create();

/*
 * PRE: 'filename' is a fully qualified path (less .o extension)
 * POST: returns true if save succeeded
 */
int save(string filename);

/*
 * PRE:  'filename' is a fully qualified path to an existing 
 *       file (less .o extension)
 * POST: returns true if restore succeeded
 */
int restore(string filename);

/*
 * POST: returns "TRUE" if queue is empty
 */
boolean is_empty();

/*
 * MODIFIES: the queue
 * POST: 'item' is now the last item in the queue
 */
void queue(mixed item);

/*
 * POST: returns "TRUE" if 'item' is in the queue
 */
boolean queued(mixed item);

/*
 * PRE: queued(item) == "TRUE"
 * MODIFIES: the queue
 * POST: 'item' is removed from the queue.  
 */
void dequeue(mixed item);

/*
 * PRE: is_empty() == "FALSE"
 * MODIFIES: the queue
 * POST: first item is pulled from the queue and returned
 */
mixed pull();
