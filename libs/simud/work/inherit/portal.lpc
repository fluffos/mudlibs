/**
 * This file contains all methods required to interact with a Portal
 * compatible mud client, and ideally, it will also include our own expansions
 * for our custom graphical client.
 **/

void portal_msg_object(object who, string txt) {
	if (!who || !who->query_client_code())
		return;
	// just in case of evil, yank newlines and trim white space
	txt = trim(txt,TRIM_BOTH," \t\n");
	tell_object(who, "#K%" + sprintf("%05d%03d", who->query_client_code(), strlen(txt)) + txt);
}

void portal_msg(string txt) {
	portal_msg_object(this_player(),txt);
}

void portal_msg_all(string txt) {
	object who;
	foreach (who : users())
		portal_msg_object(who,txt);
}

void portal_msg_room(object room, string txt) {
	object who;
	foreach (who : all_inventory(room))
		portal_msg_object(who,txt);
}

#define CL_DELIM			"~"
#define	CL_SEND_SOUND		"AAA"
#define CL_SEND_IMAGE		"AAB"
#define CL_SEND_REBOOT		"AAC"	// unused, we don't have scheduled boots
#define CL_SEND_MUSIC		"AAD"
// unused???				"AAE"
#define CL_SEND_UPTIME		"AAF"	// used, see func for concerns...
#define CL_SEND_AVI			"AAG"
#define CL_DOWNLOAD_MEDIA	"AAH"
#define CL_SEND_SPECIAL		"BAA"	// unused, it's pointless
#define CL_SEND_TELL		"BAB"
#define CL_SEND_SPECIAL2	"BAC"	// unused, it's even more pointless ;)

/** Plays a sound (wav file)
 * \param filename A file stored under <portal>/media/sounds/ on client
 */
string cl_send_sound( string filename ) {
	return CL_SEND_SOUND+filename;
}

/** Displays an image (bmp or gif only, stupid Tensor...)
 * \param filename A file stored under <portal>/media/images/ on client
 * \param imagelabel Label to attach to image as it is displayed
 */
string cl_send_image( string filename, string imagelabel ) {
	return CL_SEND_IMAGE+filename+CL_DELIM+imagelabel;
}

/** Begins playing a music file (midi or mp3, why no ogg? :P)
 * \param filename A file stored under <portal>/media/sounds/ on client
 * \param iterations Number of times to play track
 */
string cl_send_music( string filename, string iterations ) {
	return CL_SEND_MUSIC+filename+CL_DELIM+iterations;
}
/// Stop any music file currently playing
string cl_stop_music() {
	return CL_SEND_MUSIC;
}

/** Sends amount of time since the mud has booted. This one is gonna be sent
 * automagically every time nolife polls for idlers, as well as when people
 * manually type 'uptime'.
 *
 * NOTE: I don't know if this will work well with Tensor's Portal, as we have
 * uptimes well in excess of 99 hours, I am going to send time as 'dd:hh:mm',
 * which might break lesser clients' attemts to read the packet.
 */
string cl_send_uptime() {
	int uptime = time() - "/daemon/time"->query_boot_time();
	int days, hours, minutes;

	// i think this math is right, but don't want to check right now ;)
	uptime /= 60;
	days = floor( uptime / 1440 );
	uptime -= 1440 * days;
	hours = floor( uptime / 24 );
	minutes = uptime - (60 * hours);
	
	return CL_SEND_UPTIME+sprintf("%02d:%02d:%02d", days, hours, minutes);
}

/** Plays an avi file in the client's image window.
 * \param filename A file stored under <portal>/media/images/ on client
 * \param imagelabel Label to attach to video as it is played
 * \param width Width of video in pixels
 * \param height Height of video in pixels
 * \param repeat 1 to loop video, 0 to play only once
 */
string cl_send_avi( string filename, string imagelabel, int width, int height, int repeat) {
	// you will note that it is sent to client height, width since Tensor
	// says so...
	if (repeat)
		return CL_SEND_AVI+filename+CL_DELIM+imagelabel+CL_DELIM+height+CL_DELIM+width+CL_DELIM+"1";
	else
		return CL_SEND_AVI+filename+CL_DELIM+imagelabel+CL_DELIM+height+CL_DELIM+width;
}

/** Download a media file into the appropriate location on the client's
 * computer. If file already exists, download will not occur ;)
 * \param filename Name to save the file as
 * \param url Where to download from
 */
string cl_download_media( string filename, string url ) {
	return CL_DOWNLOAD_MEDIA+filename+C_DELIM+url;
}

/** Sends a tell to Portal such that it will be able to capture it and put
 * it into little chat windows.
 * \param who Object receiving the tell
 * \param text Contents of the tell
 */
string cl_send_tell( object who, string text ) {
	return CL_SEND_TELL+"x"+CL_DELIM+who->query_cap_name()+CL_DELIM+text;
}

/** Just as cl_send_tell, only for receiving tells.
 * \param who Object sending the tell
 * \param text Contents of the tell
 */
string cl_receive_tell( object who, string text ) {
	return CL_SEND_TELL+CL_DELIM+who->query_cap_name()+CL_DELIM+text;
}
