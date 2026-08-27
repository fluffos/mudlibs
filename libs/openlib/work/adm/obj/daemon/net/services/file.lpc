//  -*- LPC -*-
// file.c:  I3 'file' service implementation
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
// Created by Tim@Dysfunctional Mud 3.23.96
//

#include <daemons.h>
#include <net/daemons.h>

#define SERVICE_FILE

private mapping file_ids = ([]);

private int
new_file_id()
{
  int* ids = keys(file_ids);

  if( sizeof(ids) )
    return ids[<1]++;
  else
    return 0;
}

private string
PseudoRootPath(string rel)
{
  while( rel[0] == '/' ) rel = rel[1..]; // strip leading slashes
  rel = absolute_path(FTP_DIR, rel);
  if( !strsrch(rel, FTP_DIR) )
    return rel;                     // FTP_DIR is a prefix of rel
  else
    return FTP_DIR;                 // tried to go beyond the root
}

void
eventReceiveFileListRequest(mixed* packet)
{
  string* files;
  string dir;

  if( file_name(previous_object()) != OOB_D ) return;

  switch( file_size(dir = PseudoRootPath(packet[3])) ) {
  case -1:
    files = 0;
    break;
  case -2:
    files = get_dir(dir + "/*", -1);
    break;
  default:
    files = ({ get_dir(dir, -1) });
  }
  OOB_D->OOBSendPacket(packet[1], ({ "file-list-reply",
				     packet[2],
				     files }));
}

void
eventReceiveFileListReply(string mudname, mixed* packet)
{
  object ob;

  if( file_name(previous_object()) != OOB_D ) return;
  if( !packet[1] || !(ob = find_player(packet[1])) ) return;
  message("system", sprintf("\nRemote file list from %s:\n", mudname), ob);
  if( !packet[2] ) {
    message("system", "\nrls: no such file or directory.\n", ob);
  } else {
    string* list = ({});

    foreach(mixed* file in packet[2]) {
      string tmp = ( (file[1] == -2) ? "<DIR>" : "" + file[1] );
      list += ({ sprintf("   %18-s   %6-s   %30-s",
			 file[0], tmp, ctime(file[2]) ) });
    }
    message("system", implode(list, "\n") + "\n", ob);
  }
}

void
eventReceiveFileGetRequest(mixed* packet)
{
  string file;
  int success;

  if( file_name(previous_object()) != OOB_D ) return;
  switch( file_size(file = PseudoRootPath(packet[4])) ) {
  case -1:
    success = -1; 
    file = 0;
    break;
  case -2:
    success = -1;
    file = 0;
    break;
  default:
    file = read_file(file);
    if( file )
      success = 1;
    else
      success = -1;
  }  
  OOB_D->OOBSendPacket(packet[2], ({ "file-get-reply",
				     packet[1],
				     success,
				     file }));
}

void
eventReceiveFileGetReply(mixed* packet)
{
  string err;

  if( file_name(previous_object()) != OOB_D ) return;
  if( !file_ids[packet[1]] ) return;

  switch( packet[2] ) {
  case -2:
    err = "FILE GET request failed (read permission)";
    break;
  case -1:
    err = "FILE GET request failed (fpath error)";
    break;
  case 0:
    err = "FILE GET request failed (unknown error)";
    break;
  case 1:
    {
    string fn = FTP_DIR "/incoming/"+ explode(file_ids[packet[1]][0], "/")[<1];

    err = sprintf("FILE GET request successful.\nlocal: %s\nremote: %s",
		  fn, file_ids[packet[1]][0]);
    write_file(fn, packet[3]);
    }
    break;
  }
  message("system", err + "\n", find_player(file_ids[packet[1]][1]));
  map_delete(file_ids, packet[1]);
}

void
eventReceiveFilePut(mixed* packet)
{
  string file = PseudoRootPath(packet[4]);
  int success;

  if( strsrch(file, FTP_DIR "/incoming/") || file_exists(file) )
    success = -3;  // can only write new files into the incoming dir
  else if( !directory_exists("/" + implode(explode(file, "/")[0..<2], "/")) )
    success = -1;  // directory doesn't exist
  else
    success = write_file(file, packet[5]);

  OOB_D->OOBSendPacket(packet[2], ({ "file-put-ack",
				     packet[1],
				     success }));
}

void
eventReceiveFilePutAck(mixed* packet)
{
  string err;

  if( file_name(previous_object()) != OOB_D ) return;
  if( !file_ids[packet[1]] ) return;

  switch( packet[2] ) {
  case -3:
    err = "FILE PUT request failed (write permission)";
    break;
  case -1:
    err = "FILE PUT request failed (fpath error)";
    break;
  case 0:
    err = "FILE PUT request failed (unknown error)";
    break;
  case 1:
    err = sprintf("FILE PUT request succeeded\nremote: %s",
		  file_ids[packet[1]][0]);
    break;
  }
  message("system", err + "\n", find_player(file_ids[packet[1]][1]));
  map_delete(file_ids, packet[1]);
}

// --- Send functions

void
eventSendFileListRequest(string target_mudname, string dir)
{
  OOB_D->OOBQueuePacket(target_mudname, ({ "file-list-req",
					   mud_name(),
					   this_player(1)->query_name(),
					   dir }));
}

void
eventSendFileGetRequest(string target_mudname, string file)
{
  int id = new_file_id();
  string uname = this_player(1)->query_name();

  file_ids[id] = ({ file, uname });
  OOB_D->OOBQueuePacket(target_mudname, ({ "file-get-req",
					   id,
					   mud_name(),
					   uname,
					   file }));
}

void
eventSendFilePut(string target_mudname, string remote_file, string contents)
{
  int id = new_file_id();
  string uname = this_player(1)->query_name();

  file_ids[id] = ({ remote_file, uname });
  OOB_D->OOBQueuePacket(target_mudname, ({ "file-put",
					   id,
					   mud_name(),
					   uname,
					   remote_file,
					   contents }));
}
