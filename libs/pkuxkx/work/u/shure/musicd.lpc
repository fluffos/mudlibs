// /adm/daemons/musicd.c
// base on the work of jjgod
// by shure@mudbuilder.net 2001-10-06

#include <ansi.h>

inherit F_SAVE;
#define MUSIC_DATA "/data/music.o"
mapping songs = ([]);
mapping playersongs = ([]);

void create()
{
        seteuid(getuid());

        if (file_size(MUSIC_DATA) <= 0)
                save();
        restore();
}

string query_save_file()
{
        return MUSIC_DATA;
}

// player add

mapping query_PlayerSongs()
{
        return playersongs;
}

mapping query_PlayerSong(string id)
{
        return playersongs[id];
}

void add_PlayerSongs(string id, mapping song)
{
        playersongs[id] = song;
        save();
}

mapping delete_PlayerSongs(string id)
{
        map_delete(playersongs, id);
        save();
}

mapping delete_all_PlayerSongs()
{
	playersongs = ([]);
        save();
}

// wiz add

mapping query_songs()
{
        return songs;
}

mapping query_song(string id)
{
        return songs[id];
}

void add_songs(string id, mapping song)
{
        songs[id] = song;
        save();
}

void delete_songs(string id)
{
        map_delete(songs,id);
        save();
}