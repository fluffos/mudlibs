// File:    Stereo.c
// Purpose: Plays music for effect.
// Credits:
//      03 Jun 99   Cyanide created the file.

#define SONG_DIR "/u/c/cyanide/songlists/"
#define SONG_WILD "list_*.st"

inherit DAEMON;

string *genres, active_genre;
mapping active_list, current_song;

void init_songs(string songfile) {
    // Sets up the list of songs within a selected genre
    string *s_list;
    int x, listsize;

    if (!sizeof( genres )) {
	s_list = ({ });
	return;
    } 

    if (member_array(songfile, genres)!=-1) {
	string *tmpstr;

	active_genre = songfile;

	s_list = explode( read_file(SONG_DIR + 
	    songfile), "###\n");

	listsize = sizeof ( s_list );
	active_list = ([]);
	for (x=0; x < listsize; x++) {
	    tmpstr = explode(s_list[x], "::");
	    active_list += ([ tmpstr[0] : tmpstr [1] ]);
    }
}

return;        
}

mapping set_song_by_number(int x) {
    string *songs, *artists;

    songs = keys(active_list);
    artists = values(active_list);
    current_song = ([ songs[x] : artists[x] ]);

return current_song;
}

mapping randomize_song () {
    int x, list_size;
    x = random(sizeof( keys(active_list) ));

    return set_song_by_number(x);
}

int query_active_song() { return (keys(current_song))[0]; }

int query_active_artist() { return (values(current_song))[0]; }

string query_active_genre() { return active_genre; }

// This func returns the song number of the song within the genre list.
// If it returns zero, the current song is somehow not in thw list.
int query_song_number() {
    int val;
    string *strs = keys(active_list);

    val = member_array(query_active_song(), strs);

    return ++val;
}

void create() {
    /*
	genres = get_dir( SONG_DIR + SONG_WILD );
	init_songs(genres[random(sizeof(genres))]);
    */

    init_songs(SONG_DIR + SONG_WILD );
}

/* EOF */
